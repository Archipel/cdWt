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

    /*! \brief Returns the environment information.
     *
     * This method returns the environment object that was used when
     * constructing the application. The environment provides
     * information on the initial request, user agent, and
     * deployment-related information.
     *
     * \sa url(), sessionId()
     */
    virtual const WEnvironment& environment() const{
      return getObject()->environment();
    }

    /*! \brief Returns the root container.
     *
     * This is the top-level widget container of the application, and
     * corresponds to entire browser window. The user interface of your
     * application is represented by the content of this container.
     *
     * \if cpp
     *
     * The %root() widget is only defined when the application manages
     * the entire window. When deployed as a \link Wt::WidgetSet
     * WidgetSet\endlink application, there is no %root() container, and
     * \c 0 is returned.  Instead, use bindWidget() to bind one or more
     * root widgets to existing HTML &lt;div&gt; (or other) elements on
     * the page.
     *
     * \elseif java
     *
     * The root() widget is only defined when the application manages
     * the entire window. When deployed as a \link Wt::WidgetSet
     * WidgetSet\endlink application, there is no %root() container, and
     * <code>null</code> is returned. Instead, use bindWidget() to bind
     * one or more root widgets to existing HTML &lt;div&gt; (or other)
     * elements on the page.
     *
     * \endif
     */
    virtual WContainerWidget *root() const {
      return getObject()->root();
    }

    /*! \brief Finds a widget by name.
     *
     * This finds a widget in the application's widget hierarchy. It
     * does not only consider widgets in the root(), but also widgets
     * that are placed outside this root, such as in dialogs, or other
     * "roots" such as all the bound widgets in a widgetset application.
     *
     * \sa WWidget::setObjectName(), WWidget::find()
     */
    virtual WWidget *findWidget(const char* name){
      return getObject()->findWidget(name);
    }

    /** @name Style sheets and CSS
     */
    //@{
    /*! \brief Returns a reference to the inline style sheet.
     *
     * Widgets may allow configuration of their look and feel through
     * style classes. These may be defined in this inline stylesheet, or
     * in external style sheets.
     *
     * It is usually preferable to use external stylesheets (and
     * consider more accessible). Still, the internal stylesheet has as
     * benefit that style rules may be dynamically updated, and it is
     * easier to manage logistically.
     *
     * \sa useStyleSheet()
     * \sa WWidget::setStyleClass()
     */
    virtual WCssStyleSheet& styleSheet() {
      return getObject()->styleSheet();
    }

    /*! \brief Adds an external style sheet.
     *
     * The \p link is a link to a stylesheet.
     *
     * The \p media indicates the CSS media to which this stylesheet
     * applies. This may be a comma separated list of media. The default
     * value is "all" indicating all media.
     *
     * This is an overloaded method for convenience, equivalent to:
     * \code
     * useStyleSheet(Wt::WCssStyleSheet(link, media))
     * \endcode
     */
    virtual void useStyleSheet(const WLink& link, const char* media = "all"){
      getObject()->useStyleSheet(link, media);
    }

    /*! \brief Conditionally adds an external style sheet.
     *
     * This is an overloaded method for convenience, equivalent to:
     * \code
     * useStyleSheet(Wt::WCssStyleSheet(link, media), condition)
     * \endcode
     */
    virtual void useStyleSheet(const WLink& link, const char* condition, const char* media){
      getObject()->useStyleSheet(link, condition, media);
    }

    /*! \brief Adds an external stylesheet.
     *
     * Widgets may allow configuration of their look and feel through
     * style classes. These may be defined in an inline stylesheet,
     * or in external style sheets.
     *
     * External stylesheets are inserted after the internal style sheet,
     * and can therefore override default styles set by widgets in the
     * internal style sheet.
     *
     * If not empty, \p condition is a string that is used to apply the
     * stylesheet to specific versions of IE. Only a limited subset of
     * the IE conditional comments syntax is supported (since these are
     * in fact interpreted server-side instead of client-side). Examples
     * are:
     *
     * - "IE gte 6": only for IE version 6 or later.
     * - "!IE gte 6": only for IE versions prior to IE6.
     * - "IE lte 7": only for IE versions prior to IE7.
     *
     * \sa styleSheet(), useStyleSheet(const char*, const char*)
     * \sa WWidget::setStyleClass()
     */
    virtual void useStyleSheet(const WCssStyleSheet& styleSheet, const char* condition = ""){
      getObject()->useStyleSheet(styleSheet, condition);
    }

    /*! \brief Sets the theme.
     *
     * The theme provides the look and feel of several built-in widgets,
     * using CSS style rules. Rules for each theme are defined in the
     * <tt>resources/themes/</tt><i>theme</i><tt>/</tt> folder.
     *
     * The default theme is "default" CSS theme.
     */
    virtual void setTheme(const WTheme *theme){
      getObject()->setTheme(theme);
    }

    /*! \brief Returns the theme.
     */
    virtual const WTheme *theme() const {
      return getObject()->theme();
    }

    /*! \brief Sets a CSS theme.
     *
     * This sets a WCssTheme as theme.
     *
     * The theme provides the look and feel of several built-in widgets,
     * using CSS style rules. Rules for each CSS theme are defined in
     * the <tt>resources/themes/</tt><i>name</i><tt>/</tt> folder.
     *
     * The default theme is "default". Setting an empty theme "" will
     * result in a stub CSS theme that does not load any stylesheets.
     */
    virtual void setCssTheme(const char* name){
      getObject()->setCssTheme(name);
    }

    /*! \brief Sets the layout direction.
     *
     * The default direction is LeftToRight.
     *
     * This sets the language text direction, which by itself sets the
     * default text alignment and reverse the column orders of &lt;table&gt;
     * elements.
     *
     * In addition, %Wt will take this setting into account in WTextEdit,
     * WTableView and WTreeView (so that columns are reverted), and swap
     * the behaviour of WWidget::setFloatSide() and
     * WWidget::setOffsets() for RightToLeft languages. Note that CSS
     * settings themselves are not affected by this setting, and thus
     * for example <tt>"float: right"</tt> will move a box to the right,
     * irrespective of the layout direction.
     *
     * The library sets <tt>"Wt-ltr"</tt> or <tt>"Wt-rtl"</tt> as style
     * classes for the document body. You may use this if to override
     * certain style rules for a Right-to-Left document.
     *
     * For example:
     * \code
     * body        .sidebar { float: right; }
     * body.Wt-rtl .sidebar { float: left; }
     * \endcode
     *
     * \note The layout direction can be set only at application startup
     * and does not have the effect of rerendering the entire UI.
     */
    virtual void setLayoutDirection(LayoutDirection direction){
      getObject()->setLayoutDirection(direction);
    }

    /*! \brief Returns the layout direction.
     *
     * \sa setLayoutDirection()
     */
    virtual LayoutDirection layoutDirection() const {
      return getObject()->layoutDirection();
    }

    /*! \brief Sets a style class to the entire page &lt;body&gt;.
     *
     * \sa setHtmlClass()
     */
    virtual void setBodyClass(const char* styleClass){
      return getObject()->setBodyClass(styleClass);
    }

    /*! \brief Returns the style class set for the entire page &lt;body&gt;.
     *
     * \sa setBodyClass()
     */
    virtual const char* bodyClass() const {
      return getObject()->bodyClass().c_str();
    }

    /*! \brief Sets a style class to the entire page &lt;html&gt;.
     *
     * \sa setBodyClass()
     */
    virtual void setHtmlClass(const char* styleClass){
      return getObject()->setHtmlClass(styleClass);
    }

    /*! \brief Returns the style class set for the entire page &lt;html&gt;.
     *
     * \sa setHtmlClass()
     */
    virtual const char* htmlClass() const {
      return getObject()->htmlClass();
    }
    //@}

    /*! \brief Sets the window title.
     *
     * Sets the browser window title to \p title.
     *
     * The default title is "".
     *
     * \sa title()
     */
    virtual void setTitle(const WString& title){
      getObject()->setTitle(title);
    }

    /*! \brief Returns the window title.
     *
     * \sa setTitle(const WString&)
     */
    virtual const WString& title() const {
      return getObject()->title();
    }

    /*! \brief Returns the close message.
     *
     * \sa setConfirmCloseMessage()
     */
    virtual const WString& closeMessage() const {
      return getObject()->closeMessage();
    }

    /*! \brief Returns the resource object that provides localized strings.
     *
     * \if cpp
     * The default value is a WMessageResourceBundle instance, which
     * uses XML files to resolve localized strings, but you can set a
     * custom class using setLocalizedStrings().
     * \elseif java
     * This returns the object previously set using setLocalizedStrings().
     * \endif
     *
     * WString::tr() is used to create localized strings, whose
     * localized translation is looked up through this object, using a
     * key.
     *
     * \if cpp
     * \sa WString::tr(), messageResourceBundle()
     * \elseif java
     * \sa WString::tr()
     * \endif
     */
    virtual WLocalizedStrings *localizedStrings(){
      return getObject()->localizedStrings();
    }

    /*! \brief Sets the resource object that provides localized strings.
     *
     * The \p translator resolves localized strings within the current
     * application locale.
     *
     * \if cpp
     * The previous resource is deleted, and ownership of the new resource
     * passes to the application.
     * \endif
     *
     * \sa localizedStrings(), WString::tr(const char *key)
     */
    virtual void setLocalizedStrings(WLocalizedStrings *stringResolver){
      getObject()->setLocalizedStrings(stringResolver);
    }

    /*! \brief Returns the message resource bundle.
     *
     * The message resource bundle defines the list of external XML
     * files that are used to lookup localized strings.
     *
     * The default localizedStrings() is a WMessageResourceBundle
     * object, and this method returns localizedStrings() downcasted to
     * this type.
     *
     * \sa WString::tr(const char *key)
     */
    virtual WMessageResourceBundle& messageResourceBundle(){
      return getObject()->messageResourceBundle();
    }

    /*! \brief Changes the locale.
     *
     * The locale is used by the localized strings resource to resolve
     * localized strings.
     *
     * By passing an empty \p locale, the default locale is
     * chosen.
     *
     * When the locale is changed, refresh() is called, which will
     * resolve the strings of the current user-interface in the new
     * locale.
     *
     * At construction, the locale is copied from the environment
     * (WEnvironment::locale()), and this is the locale that was
     * configured by the user in his browser preferences, and passed
     * using an HTTP request header.
     *
     * \sa localizedStrings(), WString::tr()
     */
    virtual void setLocale(const WLocale& locale){
      getObject()->setLocale(locale);
    }

    /*! \brief Returns the current locale.
     *
     * \sa setLocale(const WLocale&)
     */
    virtual const WLocale& locale() const {
      return getObject()->locale();
    }

    /*! \brief Refreshes the application.
     *
     * This lets the application to refresh its data, including strings
     * from message-resource bundles. This done by propagating
     * WWidget::refresh() through the widget hierarchy.
     *
     * This method is also called when the user hits the refresh (or
     * reload) button, if this can be caught within the current session.
     *
     * \if cpp
     *
     * The reload button may only be caught when %Wt is configured so that
     * reload should not spawn a new session. When URL rewriting is used for
     * session tracking, this will cause an ugly session ID to be added to the
     * URL. See \ref config_session for configuring the reload
     * behavior ("<reload-is-new-session>").
     *
     * \elseif java
     *
     * The reload button may only be caught when cookies for session
     * tracking are configured in the servlet container.
     *
     * \endif
     *
     * \sa WWidget::refresh()
     */
    virtual void refresh(){
      getObject()->refresh();
    }

    /*! \brief Binds a top-level widget for a WidgetSet deployment.
     *
     * This method binds a \p widget to an existing element with DOM id
     * \p domId on the page. The element type should correspond with
     * the widget type (e.g. it should be a &lt;div&gt; for a
     * WContainerWidget, or a &lt;table&gt; for a WTable).
     *
     * \sa root()
     * \sa Wt::WidgetSet
     */
    virtual void bindWidget(WWidget *widget, const char* domId){
      getObject()->bindWidget(widget, domId);
    }

    /** @name URLs and internal paths
     */
    //@{
    /*! \brief Returns a URL for the current session
     *
     * Returns the (relative) URL for this application session
     * (including the session ID if necessary). The URL includes the
     * full application path, and is expanded by the browser into a full
     * URL.
     *
     * For example, for an application deployed at \code
     * http://www.mydomain.com/stuff/app.wt \endcode this method might
     * return <tt>"/stuff/app.wt?wtd=AbCdEf"</tt>. Additional query
     * parameters can be appended in the form of
     * <tt>"&param1=value&param2=value"</tt>.
     *
     * To obtain a URL that is suitable for bookmarking the current
     * application state, to be used across sessions, use bookmarkUrl()
     * instead.
     *
     * \sa redirect(), WEnvironment::hostName(), WEnvironment::urlScheme()
     * \sa bookmarkUrl()
     */
    virtual const char* url(const char* internalPath = "") const{
      return getObject()->url(internalPath).c_str();
    }

    /*! \brief Makes an absolute URL.
     *
     * Returns an absolute URL for a given (relative url) by including
     * the schema, hostname, and deployment path.
     *
     * If \p url is "", then the absolute base URL is returned. This is
     * the absolute URL at which the application is deployed, up to the
     * last '/'.
     *
     * This is not used in the library, except when a public URL is
     * needed, e.g. for inclusion in an email.
     *
     * You may want to reimplement this method when the application is
     * hosted behind a reverse proxy or in general the public URL of the
     * application cannot be guessed correctly by the application.
     */
    virtual const char* makeAbsoluteUrl(const char* url) const{
      return getObject()->makeAbsoluteUrl(url).c_str();
    }

    /*! \brief "Resolves" a relative URL taking into account internal paths.
     *
     * Using HTML5 History API or in a plain HTML session (without ugly
     * internal paths), the internal path is present as a full part of
     * the URL. This has a consequence that relative URLs, if not dealt
     * with, would be resolved against the last 'folder' name of the
     * internal path, rather than against the application deployment
     * path (which is what you probably want).
     *
     * When using a widgetset mode deployment, or when configuring a
     * baseURL property in the configuration, this method will make an
     * absolute URL so that the property is fetched from the right
     * server.
     *
     * Otherwise, this method will fixup a relative URL so that it
     * resolves correctly against the base path of an application. This
     * does not necessarily mean that the URL is resolved into an
     * absolute URL. In fact, %Wt will simply prepend a sequence of "../"
     * path elements to correct for the internal path. When passed an
     * absolute URL (i.e. starting with '/'), the url is returned
     * unchanged.
     *
     * For URLs passed to the %Wt API (and of which the library knows it
     * is represents a URL) this method is called internally by the
     * library. But it may be useful for URLs which are set e.g. inside
     * a WTemplate.
     */
    virtual const char* resolveRelativeUrl(const char* url) const{
      return getObject()->resolveRelativeUrl(url).c_str();
    }

      /*! \brief Returns a bookmarkable URL for the current internal path.
       *
       * Is equivalent to <tt>bookmarkUrl(internalPath())</tt>, see
       * bookmarkUrl(const char*) const.
       *
       * To obtain a URL that is refers to the current session of the
       * application, use url() instead.
       *
       * \sa url(), bookmarkUrl(const char*) const
       */
      virtual const char* bookmarkUrl() const{
        return getObject()->bookmarkUrl().c_str();
      }

      /*! \brief Returns a bookmarkable URL for a given internal path.
       *
       * Returns the (relative) URL for this application that includes the
       * internal path \p internalPath, usable across sessions.
       *
       * The returned URL concatenates the internal path to the application
       * base URL, and when no JavaScript is available and URL rewriting is used
       * for session-tracking, a session Id is appended to reuse an existing
       * session if available.
       *
       * \if cpp
       * See also \ref config_session for configuring the session-tracking
       * method.
       *
       * For the built-in httpd, when the application is deployed at a folder
       * (ending with '/'), only an exact matching path is routed to
       * the application (this can be changed since Wt 3.1.9, see
       * \ref wthttpd ), making clean URLs impossible. Returned URLs then
       * include a <tt>"?_="</tt> encoding for the internal path.
       * \endif
       *
       * You can use bookmarkUrl() as the destination for a WAnchor, and
       * listen to a click event is attached to a slot that switches to
       * the internal path \p internalPath (see
       * WAnchor::setRefInternalPath()). In this way, an anchor can be
       * used to switch between internal paths within an application
       * regardless of the situation (browser with or without Ajax
       * support, or a web spider bot), but still generates suitable URLs
       * across sessions, which can be used for bookmarking, opening in a
       * new window/tab, or indexing.
       *
       * To obtain a URL that refers to the current session of the
       * application, use url() instead.
       *
       * \sa url(), bookmarkUrl()
       *
       * \if cpp
       * \note the \p internalPath should be UTF8 encoded (we may fix the API
       *       to use WString in the future).
       * \endif
       */
      virtual const char* bookmarkUrl(const char* internalPath) const{
        return getObject()->bookmarkUrl(internalPath).c_str();
      }

      /*! \brief Changes the internal path.
       *
       * A %Wt application may manage multiple virtual paths. The virtual
       * path is appended to the application URL. Depending on the
       * situation, the path is directly appended to the application URL
       * or it is appended using a name anchor (#).
       *
       * For example, for an application deployed at:
       * \code
       * http://www.mydomain.com/stuff/app.wt
       * \endcode
       * for which an \p internalPath <tt>"/project/z3cbc/details/"</tt> is
       * set, the two forms for the application URL are:
       * <ul>
       * <li> in an AJAX session (HTML5):
       * \code
       * http://www.mydomain.com/stuff/app.wt/project/z3cbc/details/
       * \endcode
       * </li><li> in an AJAX session (HTML4):
       * \code
       * http://www.mydomain.com/stuff/app.wt#/project/z3cbc/details/
       * \endcode
       * </li><li>
       * </li><li>
       * in a plain HTML session:
       * \code
       * http://www.mydomain.com/stuff/app.wt/project/z3cbc/details/
       * \endcode
       * </li></ul>
       *
       * Note, since %Wt 3.1.9, the actual form of the URL no longer
       * affects relative URL resolution, since now %Wt includes an HTML
       * <tt>meta base</tt> tag which points to the deployment path,
       * regardless of the current internal path. This does break
       * deployments behind a reverse proxy which changes paths.
       *
       * \if cpp
       * For the built-in httpd, when the application is deployed
       * at a folder (ending with '/'), only an exact matching path is
       * routed to the application (this can be changed since Wt 3.1.9,
       * see \ref wthttpd ), making clean URLs impossible. Returned
       * URLs then include a <tt>"?_="</tt> encoding for the internal
       * path:
       *
       * \code
       * http://www.mydomain.com/stuff/?_=/project/z3cbc/details/
       * \endcode
       * \endif
       *
       * When the internal path is changed, an entry is added to the
       * browser history. When the user navigates back and forward through
       * this history (using the browser back/forward buttons), an
       * internalPathChanged() event is emitted. You should listen to this
       * signal to switch the application to the corresponding state. When
       * \p emitChange is \c true, this signal is also emitted by setting
       * the path (but only if the path is actually changed).
       *
       * A url that includes the internal path may be obtained using
       * bookmarkUrl().
       *
       * The \p internalPath must start with a '/'. In this way, you
       * can still use normal anchors in your HTML. Internal path changes
       * initiated in the browser to paths that do not start with a '/'
       * are ignored.
       *
       * \sa bookmarkUrl(), internalPath(), internalPathChanged()
       *
       * \if cpp
       * \note the \p path should be UTF8 encoded (we may fix the API
       *       to use WString in the future).
       * \endif
       */
      virtual void setInternalPath(const char* path, bool emitChange = false){
        getObject()->setInternalPath(path, emitChange);
      }

      /*! \brief Sets whether an internal path is valid by default.
       *
       * This configures how you treat (invalid) internal paths. If an
       * internal path is treated valid by default then you need to call
       * setInternalPath(false) for an invalid path. If on the other hand
       * you treat an internal path as invalid by default, then you need
       * to call setInternalPath(true) for a valid path.
       *
       * A user which opens an invalid internal path will receive a HTTP
       * 404-Not Found response code (if sent an HTML response).
       *
       * The default value is \c true.
       */
      virtual void setInternalPathDefaultValid(bool valid){
        getObject()->setInternalPathDefaultValid(valid);
      }

      /*! \brief Returns whether an internal path is valid by default.
       *
       * \sa setInternalPathDefaultValid()
       */
      virtual bool internalPathDefaultValid() const{
        return getObject()->internalPathDefaultValid();
      }

      /*! \brief Sets whether the current internal path is valid.
       *
       * You can use this function in response to an internal path change
       * event (or at application startup) to indicate whether the new (or
       * initial) internal path is valid. This has only an effect on plain
       * HTML sessions, or on the first response in an application
       * deployed with progressive bootstrap settings, as this generates
       * then a 404 Not-Found response.
       *
       * \sa internalPathChanged(), setInternalPathDefaultValid()
       */
      virtual void setInternalPathValid(bool valid){
        getObject()->setInternalPathValid(valid);
      }

      /*! \brief Returns whether the current internal path is valid.
       *
       * \sa setInternalPathValid()
       */
      virtual bool internalPathValid() const{
        return getObject()->internalPathValid();
      }

      /*! \brief Returns the current internal path.
       *
       * When the application is just created, this is equal to
       * WEnvironment::internalPath().
       *
       * \sa setInternalPath(), internalPathNextPart(), internalPathMatches()
       *
       * \if cpp
       * \note the \p returned path is UTF8 (we may fix the API
       *       to use WString in the future).
       * \endif
       */
      virtual const char* internalPath() const{
        return getObject()->internalPath().c_str();
      }

      /*! \brief Returns a part of the current internal path.
       *
       * This is a convenience method which returns the next \p folder
       * in the internal path, after the given \p path.
       *
       * For example, when the current internal path is
       * <tt>"/project/z3cbc/details"</tt>, this method returns
       * <tt>"details"</tt> when called with <tt>"/project/z3cbc/"</tt> as
       * \p path argument.
       *
       * The \p path must start with a '/', and internalPathMatches()
       * should evaluate to \c true for the given \p path. If not,
       * an empty string is returned and an error message is logged.
       *
       * \sa internalPath(), internalPathChanged()
       *
       * \if cpp
       * \note the \p internal path is UTF8 encoded (we may fix the API
       *       to use WString in the future).
       * \endif
       */
      virtual const char* internalPathNextPart(const char* path) const{
        return getObject()->internalPathNextPart(path).c_str();
      }

      virtual const char* internalSubPath(const char* path) const{
        return getObject()->internalSubPath(path).c_str();
      }

      /*! \brief Checks if the internal path matches a given path.
       *
       * Returns whether the current internalPath() starts with
       * \p path (or is equal to \p path). You will typically use
       * this method within a slot conneted to the internalPathChanged()
       * signal, to check that an internal path change affects the
       * widget. It may also be useful before changing \p path using
       * setInternalPath() if you do not intend to remove sub paths when
       * the current internal path already matches \p path.
       *
       * The \p path must start with a '/'.
       *
       * \sa setInternalPath(), internalPath()
       *
       * \if cpp
       * \note the \p internal path is UTF8 encoded (we may fix the API
       *       to use WString in the future).
       * \endif
       */
      virtual bool internalPathMatches(const char* path) const{
        return getObject()->internalPathMatches(path);
      }

      /*! \brief %Signal which indicates that the user changes the internal path.
       *
       * This signal indicates a change to the internal path, which is
       * usually triggered by the user using the browser back/forward
       * buttons.
       *
       * The argument contains the new internal path.
       *
       * \sa setInternalPath()
       *
       * \if cpp
       * \note the \p internal path is UTF8 encoded (we may fix the API
       *       to use WString in the future).
       * \endif
       */
      //FIXME: implement
      //Signal<const char*>& internalPathChanged();

      //FIXME: implement
      //Signal<const char*>& internalPathInvalid() { return internalPathInvalid_; }

      /*! \brief Redirects the application to another location.
       *
       * The client will be redirected to a new location identified by \p
       * url. Use this in conjunction with quit() if you want to the
       * application to be terminated as well.
       *
       * Calling %redirect() does not imply %quit() since it may be useful
       * to switch between a non-secure and secure (SSL) transport
       * connection.
       */
      virtual void redirect(const char* url){
        getObject()->redirect(url);
      }
      //@}

      /*! \brief Returns the URL at which the resources are deployed.
       *
       * Returns resolveRelativeUrl(relativeResourcesUrl())
       */
      virtual const char* resourcesUrl(){
        return getObject()->resourcesUrl();
      }

      /*! \brief Returns the URL at which the resources are deployed.
       *
       * \if cpp
       * This returns the value of the 'resources' property set in the
       * configuration file, and may thus be a URL relative to the deployment
       * path.
       * \endif
       *
       * \sa resolveRelativeUrl()
       */
      virtual const char* relativeResourcesUrl(){
        return getObject()->relativeResourcesUrl();
      }

      /*! \brief Returns the appRoot special property
       *
       * This returns the "appRoot" property, with a trailing slash added
       * to the end if it was not yet present.
       *
       * The property "appRoot" was introduced as a generalization of the
       * working directory for the location of files that do not need to
       * be served over http to the client, but are required by the
       * program to run properly. Typically, these are message resource
       * bundles (xml), CSV files, database files (e.g. SQLite files for
       * Wt::Dbo), ...
       *
       * Some connectors do not allow you to control what the current
       * working directory (CWD) is set to (fcgi, isapi). Instead of
       * referring to files assuming a sensible CWD, it is therefore
       * better to refer to them relative to the application root.
       *
       * The appRoot property is special in the sense that it can be set
       * implicitly by the connector (see the connector documentation for
       * more info). If it was not set by the connector, it can be set as
       * a normal property in the configuration file (the default
       * wt_config.xml describes how to set properties). If the property
       * is not set at all, it is assumed that the appRoot is CWD and this
       * function will return an empty string.
       *
       * \if cpp
       * Usage example:
       * \code
       * messageResourceBundle().use(appRoot() + "text");
       * messageResourceBundle().use(appRoot() + "charts");
       *
       * Wt::Dbo::backend::Sqlite3 sqlite3_(appRoot() + "planner.db");
       * \endcode
       * \endif
       *
       * \sa WServer::appRoot(), docRoot()
       */
      virtual const char* appRoot(){
        return getObject()->appRoot();
      }

      /*! \brief Returns the server document root.
       *
       * This returns the filesystem path that corresponds to the document root
       * of the webserver.
       *
       * \note This does not work reliably for complex webserver configurations
       *       (e.g. using FastCGI with Apache and rewrite rules). See also the
       *       <a href="https://issues.apache.org/bugzilla/show_bug.cgi?id=26052">
       *       discussion here</a>.
       *
       * \sa appRoot()
       */
      virtual const char* docRoot(){
        return getObject()->docRoot();
      }

      /*! \brief Returns the unique identifier for the current session.
       *
       * The session id is a string that uniquely identifies the current session.
       * Note that the actual contents has no particular meaning and client
       * applications should in no way try to interpret its value.
       */
      virtual const char* sessionId(){
        return getObject()->sessionId();
      }

      /*! \brief Changes the session id.
       *
       * To mitigate session ID fixation attacks, you should use this
       * method to change the session ID to a new random value after a
       * user has authenticated himself.
       *
       * \sa sessionId()
       */
      virtual void changeSessionId(){
        getObject()->changeSessionId();
      }

      virtual WebSession* session() const{
        return getObject()->session();
      }

      /** @name Manipulation outside the main event loop
       */
      //@{
      /*! \brief Enables server-initiated updates.
       *
       * By default, updates to the user interface are possible only at
       * startup, during any event (in a slot), or at regular time points
       * using WTimer. This is the normal %Wt event loop.
       *
       * In some cases, one may want to modify the user interface from a
       * second thread, outside the event loop. While this may be worked
       * around by the WTimer, in some cases, there are bandwidth and
       * processing overheads associated which may be unnecessary, and
       * which create a trade-off with time resolution of the updates.
       *
       * When \p enabled is \c true, this enables "server push" (what is
       * called 'comet' in AJAX terminology). Widgets may then be
       * modified, created or deleted outside of the event loop (e.g. in
       * response to execution of another thread), and these changes are
       * propagated by calling triggerUpdate().
       *
       * \if cpp
       * There are two ways for safely manipulating a session's UI, with
       * respect to thread-safety and application life-time (the library
       * can decide to terminate an application if it lost connectivity
       * with the browser).
       *
       * <h3>WServer::post()</h3>
       *
       * The easiest and less error-prone solution is to post an event,
       * represented by a function/method call, to a session using
       * WServer::post().
       *
       * The method is non-blocking: it returns immediately, avoiding
       * dead-lock scenarios. The function is called from within a thread
       * of the server's thread pool, and not if the session has been or
       * is being terminated. The function is called in the context of the
       * targeted application session, and with exclusive access to the
       * session.
       *
       * <h3>WApplication::UpdateLock</h3>
       *
       * A more direct approach is to grab the application's update lock and
       * manipulate the application's state directly from another thread.
       *
       * At any time, the application may be deleted (e.g. because of a
       * time out or because the user closes the application window). You
       * should thus make sure you do no longer reference an application
       * after it has been deleted. When %Wt decides to delete an
       * application, it first runs WApplication::finalize() and then
       * invokes the destructor. While doing this, any other thread trying
       * to grab the update lock will unblock, but the lock will return \c
       * false. You should therefore always check whether the lock is
       * valid.
       *
       * \elseif java
       *
       * Note that you need to grab the application's update lock to avoid
       * concurrency problems, whenever you modify the application's state
       * from another thread.
       *
       * \endif
       *
       * An example of how to modify the widget tree outside the event loop
       * and propagate changes is:
       * \if cpp
       * \code
       * // You need to have a reference to the application whose state
       * // you are about to manipulate.
       * // You should prevent the application from being deleted somehow,
       * // before you could grab the application lock.
       * Wt::WApplication *app = ...;
       *
       * {
       *   // Grab the application lock. It is a scoped lock.
       *   Wt::WApplication::UpdateLock lock(app);
       *
       *   if (lock) {
       *     // We now have exclusive access to the application: we can safely modify the widget tree for example.
       *     app->root()->addWidget(new Wt::WText("Something happened!"));
       *
       *     // Push the changes to the browser
       *     app->triggerUpdate();
       *   }
       * }
       * \endcode
       * \elseif java
       * \code
       * // You need to have a reference to the application whose state
       * // you are about to manipulate.
       * WApplication app = ...;
       *
       * // Grab the application lock
       * WApplication.UpdateLock lock = app.getUpdateLock();
       *
       * try {
       *   // We now have exclusive access to the application:
       *   // we can safely modify the widget tree for example.
       *   app.getRoot().addWidget(new WText("Something happened!"));
       *
       *   // Push the changes to the browser
       *   app.triggerUpdate();
       * } finally {
       *   lock.release();
       * }
       * \endcode
       * \endif
       *
       * \if java
       * This works only if your servlet container supports the Servlet 3.0
       * API. If you try to invoke this function on a servlet container with
       * no such support, an exception will be thrown.
       * \endif
       *
       * \note This works only if JavaScript is available on the client.
       *
       * \sa triggerUpdate()
       */
      void enableUpdates(bool enabled = true);

      virtual void enableUpdates(bool enabled = true){
        getObject()->enableUpdates(enabled);
      }

      /*! \brief Returns whether server-initiated updates are enabled.
       *
       * \sa enableUpdates()
       */
      virtual bool updatesEnabled() const{
        return getObject()->updatesEnabled();
      }

      /*! \brief Propagates server-initiated updates.
       *
       * When the lock to the application is released, changes will
       * propagate to the user interface. This call only has an effect
       * after updates have been enabled from within the normal event loop
       * using enableUpdates().
       *
       * This is typically used only outside of the main event loop,
       * e.g. from another thread or from within a method posted to an
       * application using WServer::post(), since changes always propagate
       * within the event loop at the end of the event.
       *
       * The update is not immediate, and thus changes that happen after this
       * call will equally be pushed to the client.
       *
       * \sa enableUpdates()
       */
      virtual void triggerUpdate(){
        getObject()->triggerUpdate();
      }

      /** @name Invoking JavaScript or including scripts
       */
      //@{
      /*! \brief Executes some JavaScript code.
       *
       * This method may be used to call some custom \p javaScript code as
       * part of an event response.
       *
       * This function does not wait until the JavaScript is run, but
       * returns immediately. The JavaScript will be run after the normal
       * event handling, unless \p afterLoaded is set to \c false.
       *
       * In most situations, it's more robust to use
       * WWidget::doJavaScript() however.
       *
       * \sa WWidget::doJavaScript(), declareJavaScriptFunction()
       */
      virtual void doJavaScript(const char* javascript, bool afterLoaded = true){
        getObject()->doJavaScript(javascript, afterLoaded);
      }

      /*! \brief Adds JavaScript statements that should be run continuously.
       *
       * This is an internal method.
       *
       * It is used by for example layout managers to adjust the layout
       * whenever the DOM tree is manipulated.
       *
       * \sa doJavaScript()
       */
      virtual void addAutoJavaScript(const char* javascript){
        getObject()->addAutoJavaScript(javascript);
      }

      /*! \brief Declares an application-wide JavaScript function.
       *
       * The function is stored in WApplication::javaScriptClass().
       *
       * The next code snippet declares and invokes function foo:
       * \if cpp
       * \code
       * app->declareJavaScriptFunction("foo",
       *                                "function(id) { ... }");
       * ...
       * const char* id("myId");
       * app->doJavaScript(app->javaScriptClass() + ".foo('" + id + "');");
       * \endcode
       * \endif
       */
      virtual void declareJavaScriptFunction(const char* name, const char* function){
        getObject()->declareJavaScriptFunction(name, function);
      }

      /*! \brief Loads a JavaScript library.
      *
      * Loads a JavaScript library located at the URL \p url. %Wt keeps
      * track of libraries (with the same URL) that already have been
      * loaded, and will load a library only once. In addition, you may
      * provide a \p symbol which if already defined will also indicate
      * that the library was already loaded (possibly outside of %Wt when
      * in WidgetSet mode).
      *
      * This method returns \c true only when the library is loaded
      * for the first time.
      *
      * JavaScript libraries may be loaded at any point in time. Any
      * JavaScript code is deferred until the library is loaded, except
      * for JavaScript that was defined to load before, passing \c false
      * as second parameter to doJavaScript().
      *
      * Although %Wt includes an off-the-shelf JQuery version (which can
      * also be used by your own JavaScript code), you can override the
      * one used by %Wt and load another JQuery version instead, but this
      * needs to be done using requireJQuery().
      */
      virtual bool require(const char* url, const char* symbol = ""){
        return getObject()->require(url, symbol);
      }

      /*! \brief Loads a custom JQuery library.
      *
      * %Wt ships with a rather old version of JQuery (1.4.1) which is
      * sufficient for its needs and is many times smaller than more recent
      * JQuery releases (about 50% smaller).
      *
      * Using this function, you can replace Wt's JQuery version with another
      * version of JQuery.
      *
      * \code
      * requireJQuery("jquery/jquery-1.7.2.min.js");
      * \endcode
      */
      virtual bool requireJQuery(const char* url){
        return getObject()->requireJQuery(url);
      }

      virtual bool customJQuery() const {
        return getObject()->customJQuery();
      }

      /*! \brief Sets the name of the application JavaScript class.
      *
      * This should be called right after construction of the application, and
      * changing the JavaScript class is only supported for WidgetSet mode
      * applications. The \p className should be a valid JavaScript identifier, and
      * should also be unique in a single page.
      */
      virtual void setJavaScriptClass(const char* className){
        getObject()->setJavaScriptClass(className);
      }

      /*! \brief Returns the name of the application JavaScript class.
      *
      * This JavaScript class encapsulates all JavaScript methods
      * specific to this application instance. The method is foreseen to
      * allow multiple applications to run simultaneously on the same
      * page in Wt::WidgtSet mode, without interfering.
      */
      const char* javaScriptClass() {
        return getObject()->javaScriptClass().c_str();
      }
      //@}

      /*! \brief Processes UI events.
      *
      * You may call this method during a long operation to:
      *   - propagate widget changes to the client.
      *   - process UI events.
      *
      * This method starts a recursive event loop, blocking the current
      * thread, and resumes when all pending user interface events have been
      * processed.
      *
      * Because a thread is blocked, this may affect your application
      * scalability.
      */
      virtual void processEvents(){
        getObject()->processEvents();
      }

      /*! \brief Blocks the thread, waiting for an UI event.
      *
      * This function is used by functions like WDialog::exec() or
      * WPopupMenu::exec(), to block the current thread waiting for a new
      * event.
      *
      * This requires that at least one additional thread is available to
      * process incoming requests, and is not scalable when working with
      * a fixed size thread pools.
      */
      virtual void waitForEvent(){
        getObject()->waitForEvent();
      }

      /*! \brief Reads a configuration property.
      *
      * Tries to read a configured value for the property
      * \p name. The method returns whether a value is defined for
      * the property, and sets it to \p value.
      *
      * \sa WServer::readConfigurationProperty()
      */
      //FIXME: TODO
      //static bool readConfigurationProperty(const char* name, const char* value);

      /*! \brief Sets the Ajax communication method (<b>deprecated</b>).
      *
      * This method has no effect.
      *
      * Since %Wt 3.1.8, a communication method that works is detected at
      * run time. For widget set mode, cross-domain Ajax is chosen if
      * available.
      *
      * \deprecated this setting is no longer needed.
      */
      virtual void setAjaxMethod(WApplication::AjaxMethod method){
        getObject()->setAjaxMethod(method);
      }

      /*! \brief Returns the Ajax communication method (<b>deprecated</b>).
      *
      * \sa setAjaxMethod()
      */
      virtual WApplication::AjaxMethod ajaxMethod() const{
        return getObject()->ajaxMethod();
      }

      /*
      * The DOM root object. This contains not only the application root but
      * also other invisible objects (timers, dialog covers, ...).
      */
      virtual WContainerWidget* domRoot() const{
        return getObject()->domRoot();
      }

      /*
      * A phony DOM root object, used to logically contain all widgets bound
      * in widgetset mode.
      */
      virtual WContainerWidget* domRoot2() const{
        return getObject()->domRoot2();
      }

      /*
      * Encode an object to a string, to make it referencable from JavaScript.
      * Currently only used to encode the drag object in drag & drop.
      *
      * FIXME: provide a way to remove the encoding!
      *
      * \see decodeObject()
      */
      virtual const char* encodeObject(WObject *object) const{
        return getObject()->encodeObject(object).c_str();
      }

      /*
      * Decode an object.
      *
      * \see encodeObject()
      */
      virtual WObject* decodeObject(const char* objectId) const{
        return getObject()->decodeObject(objectId);
      }

      /*! \brief Initializes the application, post-construction.
       *
       * This method is invoked by the %Wt library after construction of a
       * new application. You may reimplement this method to do additional
       * initialization that is not possible from the constructor
       * (e.g. which uses virtual methods).
       */
      virtual void initialize(){
        getObject()->initialize();
      }

      /*! \brief Finalizes the application, pre-destruction.
       *
       * This method is invoked by the %Wt library before destruction of a
       * new application. You may reimplement this method to do additional
       * finalization that is not possible from the destructor (e.g. which
       * uses virtual methods).
       */
      virtual void finalize(){
        getObject()->finalize();
      }

      /*! \brief Changes the threshold for two-phase rendering.
       *
       * This changes the threshold for the \p size of a JavaScript
       * response (in bytes) to render invisible changes in one go. If the
       * bandwidth for rendering the invisible changes exceed the
       * threshold, they will be fetched in a second communication, after
       * the visible changes have been rendered.
       *
       * The value is a trade-off: setting it smaller will always use
       * two-phase rendering, increasing the total render time but
       * reducing the latency for the visible changes. Setting it too
       * large will increase the latency to render the visible changes,
       * since first also all invisible changes need to be computed and
       * received in the browser.
       *
       * \if cpp
       * The initial value is read from the configuration file, see \ref
       * config_general.
       * \endif
       */
      virtual void setTwoPhaseRenderingThreshold(int size){
        getObject()->setTwoPhaseRenderingThreshold(size);
      }

      /*! \brief Sets a new cookie.
       *
       * Use cookies to transfer information across different sessions
       * (e.g. a user name). In a subsequent session you will be able to
       * read this cookie using WEnvironment::getCookie(). You cannot use
       * a cookie to store information in the current session.
       *
       * The name must be a valid cookie name (of type 'token': no special
       * characters or separators, see RFC2616 page 16). The value may be
       * anything. Specify the maximum age (in seconds) after which the
       * client must discard the cookie. To delete a cookie, use a value of '0'.
       *
       * By default the cookie only applies to the application deployment
       * path (WEnvironment::deploymentPath()) in the current domain. To
       * set a proper value for domain, see also RFC2109.
       *
       * \if cpp
       * \note %Wt provides session tracking automatically, and may be configured
       *       to use a cookie for this. You only need to use cookies yourself
       *       if you want to remember some information (like a logged in identity)
       *       <i>across sessions</i>.
       * \endif
       *
       * \sa WEnvironment::supportsCookies(), WEnvironment::getCookie()
       */
      virtual void setCookie(const char* name, const char* value, int maxAge, const char* domain = "", const char* path = "", bool secure = false){
        getObject()->setCookie(name, value, maxAge, domain, path, secure);
      }

      virtual void setCookie(const char* name, const char* value, const WDateTime& expire, const char* domain = "", const char* path = "", bool secure = false){
        getObject()->setCookie(name, value, expire, domain, path, secure);
      }

      /*! \brief Removes a cookie.
       *
       * \sa setCookie()
       */
      virtual void removeCookie(const char* name, const char* domain = "", const char* path = ""){
        getObject()->removeCookie(name, domain, path);
      }

      /*! \brief Adds an HTML meta link.
       *
       * When a link was previously set for the same \p href, its contents
       * are replaced.
       * When an empty string is used for the arguments \p media, \p hreflang,
       * \p type or \p sizes, they will be ignored.
       *
       * \sa removeMetaLink()
       */
      virtual void addMetaLink(const char* href, const char* rel, const char* media, const char* hreflang, const char* type, const char* sizes,
          bool disabled){
        getObject()->addMetaLink(href, rel, media, hreflang, type, sizes, disabled);
      }

      /*! \brief Removes the HTML meta link.
       *
       * \sa addMetaLink()
       */
      virtual void removeMetaLink(const char* href){
        getObject()->removeMetaLink(href);
      }

      /*! \brief Adds an HTML meta header.
       *
       * \sa addMetaHeader(MetaHeaderType, const char*, const WString&, const char*)
       */
      virtual void addMetaHeader(const char* name, const WString& content, const char* lang = ""){
        getObject()->addMetaHeader(name, content, lang);
      }

      /*! \brief Adds an HTML meta header.
       *
       * This method sets either a "name" meta headers, which configures a
       * document property, or a "http-equiv" meta headers, which defines
       * a HTTP headers (but these latter headers are being deprecated).
       *
       * A meta header can however only be added in the following situations:
       *
       * - when a plain HTML session is used (including when the user agent is a
       *   bot), you can add meta headers at any time.
       * - or, when \ref progressive_bootstrap "progressive bootstrap" is
       *   used, you can set meta headers for any type of session, from
       *   within the application constructor (which corresponds to the
       *   initial request).
       * - but never for a Wt::WidgetSet mode application since then the
       *   application is hosted within a foreign HTML page.
       *
       * These situations coincide with WEnvironment::ajax() returning \c
       * false (see environment()). The reason that it other cases the
       * HTML page has already been rendered, and will not be rerendered
       * since all updates are done dynamically.
       *
       * As an alternative, you can use the &lt;meta-headers&gt;
       * configuration property in the configuration file, which will be
       * applied in all circumstances.
       *
       * \sa removeMetaHeader()
       */
      virtual void addMetaHeader(MetaHeaderType type, const char* name, const WString& content, const char* lang = ""){
        getObject()->addMetaHeader(type, name, content, lang);
      }

      /*! \brief Removes one or all meta headers.
       *
       * Removes the meta header with given type and name (if it is present).
       * If name is empty, all meta headers of the given type are removed.
       *
       * \sa addMetaHeader()
       */
      virtual void removeMetaHeader(MetaHeaderType type, const char* name = ""){
        getObject()->removeMetaHeader(type, name);
      }

      /*! \brief Adds an entry to the application log.
       *
       * Starts a new log entry of the given \p type in the %Wt
       * application log file. This method returns a stream-like object to
       * which the message may be streamed.
       *
       * \if cpp
       * A typical usage would be:
       * \code
       *  wApp->log("notice") << "User " << userName << " logged in successfully.";
       * \endcode
       *
       * This would create a log entry that looks like:
       * \verbatim
    [2008-Jul-13 14:01:17.817348] 16879 [/app.wt Z2gCmSxIGjLHD73L] [notice] "User bart logged in successfully."
       * \endverbatim
       * \endif
       *
       * \if cpp
       * \sa \ref config_general
       * \endif
       */
      virtual WLogEntry log(const char* type) const{
        return getObject()->log(type);
      }

      /*! \brief Sets the loading indicator.
       *
       * The loading indicator is shown to indicate that a response from
       * the server is pending or JavaScript is being evaluated.
       *
       * The default loading indicator is a WDefaultLoadingIndicator.
       *
       * When setting a new loading indicator, the previous one is
       * deleted.
       */
      void setLoadingIndicator(WLoadingIndicator* indicator){
        getObject()->setLoadingIndicator(indicator);
      }

      /*! \brief Returns the loading indicator.
       *
       * \sa setLoadingIndicator()
       */
      virtual WLoadingIndicator *loadingIndicator() const {
        return getObject()->loadingIndicator();
      }

      /*
       * A url to a resource that provides a one pixel gif. This is sometimes
       * useful for CSS hackery to make IE behave.
       */
      const char* onePixelGifUrl(){
        return getObject()->onePixelGifUrl().c_str();
      }

      /*
       * The doctype used to deliver the application.
       */
      const char* docType() const{
        return getObject()->docType().c_str();
      }

      /*! \brief Quits the application.
       *
       * This quits the application with a default restart message resolved
       * as WString::tr("Wt.QuittedMessage").
       *
       * \sa quit(const WString&)
       */
      virtual void quit(){
        getObject()->quit();
      }

      /*! \brief Quits the application.
       *
       * The method returns immediately, but has as effect that the
       * application will be terminated after the current event is
       * completed.
       *
       * The current widget tree (including any modifications still
       * pending and applied during the current event handling) will still
       * be rendered, after which the application is terminated.
       *
       * If the restart message is not empty, then the user will be
       * offered to restart the application (using the provided message)
       * when further interacting with the application.
       *
       * \sa redirect()
       */
      void quit(const WString& restartMessage){
        getObject()->quit(restartMessage);
      }

      /*! \brief Returns whether the application has quit.
       *
       * \sa quit()
       */
      bool hasQuit() const {
        return getObject()->hasQuit();
      }

      /*! \brief Returns the current maximum size of a request to the
       *         application.
       *
       * The returned value is the maximum request size in bytes.
       *
       * \if cpp
       * The maximum request size is configured in the configuration file,
       * see \ref config_general.
       * \endif
       *
       * \sa requestTooLarge()
       */
      virtual int64_t maximumRequestSize() const{
        return getObject()->maximumRequestSize();
      }

      /*! \brief %Signal which indicates that too a large request was received.
       *
       * The integer parameter is the request size that was received in bytes.
       */
      //FIXME
      //Signal< ::int64_t >& requestTooLarge() { return requestTooLarge_; }

      /*
       * For persistent sessions only: redirect to another session.
       */
      virtual void redirectToSession(const char* sessionId){
        getObject()->redirectToSession(sessionId);
      }

      /*
       * For persistent sessions only: return whether the persistent session
       * is connected to a browser.
       */
      virtual bool isConnected() const {
        return getObject()->isConnected();
      }

      /** @name Global keyboard and mouse events
       */
      //@{
      /*! \brief Event signal emitted when a keyboard key is pushed down.
       *
       * The application receives key events when no widget currently
       * has focus. Otherwise, key events are handled by the widget in focus,
       * and its ancestors.
       *
       * \sa See WInteractWidget::keyWentDown()
       */
      //FIXME
      //EventSignal<WKeyEvent>& globalKeyWentDown();

      /*! \brief Event signal emitted when a "character" was entered.
       *
       * The application receives key events when no widget currently
       * has focus. Otherwise, key events are handled by the widget in focus,
       * and its ancestors.
       *
       * \sa See WInteractWidget::keyPressed()
       */
      //FIXME
      //EventSignal<WKeyEvent>& globalKeyPressed();

      /*! \brief Event signal emitted when a keyboard key is released.
       *
       * The application receives key events when no widget currently
       * has focus. Otherwise, key events are handled by the widget in focus,
       * and its ancestors.
       *
       * \sa See WInteractWidget::keyWentUp()
       */
      //FIXME
      //EventSignal<WKeyEvent>& globalKeyWentUp();

      /*! \brief Event signal emitted when enter was pressed.
       *
       * The application receives key events when no widget currently
       * has focus. Otherwise, key events are handled by the widget in focus,
       * and its ancestors.
       *
       * \sa See WInteractWidget::enterPressed()
       */
      //FIXME
      //EventSignal<>& globalEnterPressed();
    
      /*! \brief Event signal emitted when escape was pressed.
       *
       * The application receives key events when no widget currently
       * has focus. Otherwise, key events are handled by the widget in focus,
       * and its ancestors.
       *
       * \sa See WInteractWidget::escapePressed()
       */
      //FIXME
      //EventSignal<>& globalEscapePressed();
      //@}

      /*
       * Returns whether debug was configured.
       * (should be public API ?)
       */
      virtual bool debug() const{
        return getObject()->debug();
      }

      /*
       * Methods for client-side focus
       */
      virtual void setFocus(const char* id, int selectionStart, int selectionEnd){
        getObject()->setFocus(id, selectionStart, selectionEnd);
      }

      virtual bool javaScriptLoaded(const char *jsFile) const{
        return getObject()->javaScriptLoaded(jsFile);
      }

      /*! \brief Sets the message for the user to confirm closing of the
       *         application window/tab.
       *
       * If the message is empty, then the user may navigate away from the page
       * without confirmation.
       *
       * Otherwise the user will be prompted with a browser-specific
       * dialog asking him to confirm leaving the page. This \p message is
       * added to the page.
       *
       * \sa unload()
       */
      virtual void setConfirmCloseMessage(const WString& message){
        getObject()->setConfirmCloseMessage(message);
      }

      /*! \brief Sets the message for the user when the application was .
       */
      virtual void enableInternalPaths(){
        getObject()->enableInternalPaths();
      }

      /*! \brief Utility function to check if one path falls under another path.
       *
       * This returns whether the \p query path matches the given \p path,
       * meaning that it is equal to that path or it specifies a more
       * specific sub path of that path.
       */
      //FIXME
      //static bool pathMatches(const char* path, const char* query);

      /*! \brief Defers rendering of the current event response.
       *
       * This method defers the rendering of the current event response
       * until resumeRendering() is called. This may be used if you do not
       * want to actively block the current thread while waiting for an
       * event which is needed to complete the current event
       * response. Note that this effectively freezes the user interface,
       * and thus you should only do this if you know that the event you
       * are waiting for will arrive shortly, or there is really nothing more
       * useful for the user to do than wait for the action to complete.
       *
       * A typical use case is in conjunction with the Http::Client, to
       * defer the rendering while waiting for the Http::Client to
       * complete.
       *
       * The function may be called multiple times and the number of deferral
       * requests is counted. The current response is deferred until as
       * many calls to resumeRendering() have been performed.
       *
       * \sa resumeRendering()
       */
      virtual void deferRendering(){
        getObject()->deferRendering();
      }

      /*! \brief Resumes rendering of a deferred event response.
       *
       * \sa deferRendering()
       */
      virtual void resumeRendering(){
        getObject()->resumeRendering();
      }

      /*! \brief Protects a function against deletion of the target object.
       *
       * When posting an event using WServer::post(), it is convenient to
       * bind an object method to be called. However, while
       * WServer::post() guarantees that the application to which an event
       * is posted is still alive, it may be that the targeted widget (or
       * WObject in general) has been deleted.
       *
       * This function wraps such an object method with a protection layer
       * which guarantees that the method is only called when the targeted
       * object is alive, in the same way as how a signal automatically
       * disconnects slots from objects that are being deleted.
       *
       * You typically will bind the function immediately within the event
       * loop where you register the "callback", and pass this bound
       * function to (typically an external thread) which calls post()
       * later on. What you cannot do is bind the function only later on,
       * since at that time the target object may already have been
       * destroyed.
       *
       * As with the signal/slot connection tracking mechanism, this
       * requires that the object is a WObject.
       */
      //FIXME
      //template <typename F> boost::function<void()> bind(const F& f);

      /*! \brief Encodes an untrusted URL to prevent referer leaks.
       *
       * This encodes an URL so that in case the session ID is present
       * in the current URL, this session ID does not leak to the refenced
       * URL.
       *
       * Wt will safely handle URLs in the API (in WImage and WAnchor) but
       * you may want to use this function to encode URLs which you use in
       * WTemplate texts.
       */
      virtual const char* encodeUntrustedUrl(const char* url) const{
        return getObject()->encodeUntrustedUrl(url).c_str();
      }

      /*! \brief Pushes a (modal) widget onto the expose stack.
       *
       * This defines a new context of widgets that are currently visible.
       */
      virtual void pushExposedConstraint(WWidget *w){
        getObject()->pushExposedConstraint(w);
      }

      virtual void popExposedConstraint(WWidget *w){
        getObject()->popExposedConstraint(w);
      }

      virtual void addGlobalWidget(WWidget *w){
        getObject()->addGlobalWidget(w);
      }

      virtual void removeGlobalWidget(WWidget *w){
        getObject()->removeGlobalWidget(w);
      }
  };

  /*! \brief Create a %WObject with a given parent object.
   *
   * If the optional parent is specified, the parent object will
   * destroy all child objects. Set parent to \c 0 to create an object
   * with no parent.
   *
   * \sa addChild()
   */
  inline CDWApplication* construct(WApplication* wobject = 0){
    return new CDWApplication(wobject);
  }

  inline CDWApplication* construct(const WEnvironment& environment){
    return new CDWApplication(new WApplication(environment));
  }

  inline CDWApplication* getApplication(){
    return CDWApplication::instance;
  }
}
