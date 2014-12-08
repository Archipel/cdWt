/*
 * Wapplication.h
 *
 *  Created on: 01-dec.-2014
 *      Author: Thomas Weyn
 */

#include <Wt/WApplication>
#include "CDWObject.h"

namespace Wt {
  class CDWApplication : public CDWObject{
  public:
    static CDWApplication* instance = nullptr;

    CDWApplication(WApplication* object = 0): CDWObject(object) {}

    WApplication* getObject() const {
      return static_cast<WApplication*>(wobject);
    }
  };

  /*! \brief Creates a new application instance.
   *
   * The \p environment provides information on the initial request,
   * user agent, and deployment-related information.
   */
  inline CDWApplication* constructWApplication(const WEnvironment& environment){
    return new CDWApplication(new WApplication(environment));
  }

  /*! \brief Returns the current application instance.
   *
   * \if cpp
   * This is the same as the global define #wApp. In a multi-threaded server,
   * this method uses thread-specific storage to fetch the current session.
   * \elseif java
   * This method uses thread-specific storage to fetch the current session.
   * \endif
   */
  static CDWApplication* getCDWApplicationInstance(){
    return CDWApplication::instance;
  }
}

