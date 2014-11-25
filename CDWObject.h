/*
 * WObject.cpp
 *
 *  Created on: 25-nov.-2014
 *      Author: thomas
 */

#include <Wt/WObject>

namespace Wt {

  class CDWObject{
  protected:
    WObject* wobject;
  public:

    CDWObject(WObject* wobject = 0): wobject(wobject) {}
    virtual ~CDWObject(){
      delete wobject;
    }

    /*
     * Unique id's
     */
    virtual unsigned rawUniqueId() const { return wobject->rawUniqueId(); }
    virtual const char* uniqueId() const { return wobject->uniqueId().c_str(); }

    /*! \brief Returns the (unique) identifier for this object
     *
     * For a %WWidget, this corresponds to the id of the DOM element
     * that represents the widget. This is not entirely unique, since a
     * \link WCompositeWidget composite widget\endlink shares the same
     * id as its implementation.
     *
     * By default, the id is auto-generated, unless a custom id is set
     * for a widget using WWidget::setId(). The auto-generated id is created
     * by concatenating objectName() with a unique number.
     *
     * \sa WWidget::jsRef()
     */
    virtual const char* id() const {
      return wobject->id().c_str();
    }

    /*! \brief Sets an object name.
     *
     * The object name can be used to easily identify a type of object
     * in the DOM, and does not need to be unique. It will usually
     * reflect the widget type or role. The object name is prepended to
     * the auto-generated object id().
     *
     * The default object name is empty.
     *
     * \note Only letters ([A-Za-z]), digits ([0-9]), hyphens ("-"),
     * underscores ("_"), colons (":"), and periods (".") are allowed in
     * the id.
     *
     * \sa id()
     */
    virtual void setObjectName(const char* name){
      wobject->setObjectName(name);
    }

    /*! \brief Returns the object name.
     *
     * \sa setObjectName()
     */
    virtual const char* objectName() const{
      return wobject->objectName().c_str();
    }

    /*! \brief Resets learned stateless slot implementations.
     *
     * Clears the stateless implementation for all slots declared to be
     * implemented with a stateless implementation.
     *
     * \sa resetLearnedSlot(), implementStateless()
     */
    virtual void resetLearnedSlots(){
      wobject->resetLearnedSlots();
    }

    /*! \brief Adds a child object.
     *
     * Take responsibility of deleting the child object, together with this
     * object.
     *
     * \sa removeChild()
     */
    virtual void addChild(WObject *child){
      wobject->addChild(child);
    }

    /*! \brief Removes a child object.
     *
     * The child must have been previously added.
     *
     * \sa addChild()
     */
    //virtual void removeChild(WObject *child) -> WObject implementation is OK

    /*! \brief Returns the children.
     */
    virtual WObject** children(size_t& nAmount) const{
      auto rv = wobject->children();
      nAmount = rv.size();
      return &rv[0];
    }

    /*! \brief Returns the parent object.
     */
    virtual WObject *parent() const {
      return wobject->parent();
    }

    //virtual bool hasParent() const;

    //NOTPORTED
    //static void seedId(unsigned id);
  };

  /*! \brief Create a %WObject with a given parent object.
   *
   * If the optional parent is specified, the parent object will
   * destroy all child objects. Set parent to \c 0 to create an object
   * with no parent.
   *
   * \sa addChild()
   */
  inline CDWObject* construct(WObject* wobject = 0){
    return new CDWObject(wobject);
  }

  /*! \brief Destructor.
   *
   * This automatically:
   * - deletes all child objects
   * - invalidates this object as sender or receiver in signals and slots
   */
  inline void destruct(CDWObject* obj){
    delete obj;
  }
};

