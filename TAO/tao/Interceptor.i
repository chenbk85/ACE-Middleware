/* -*- C++ -*- $Id$ */

#if defined (TAO_HAS_INTERCEPTORS)
ACE_INLINE
TAO_ClientRequestInterceptor_Adapter::TAO_ClientRequestInterceptor_Adapter
  (PortableInterceptor::ClientRequestInterceptor_ptr interceptor)
    : interceptor_ (interceptor)
{
}

ACE_INLINE
TAO_ClientRequestInterceptor_Adapter::~TAO_ClientRequestInterceptor_Adapter
  (void)
{
}

ACE_INLINE void
TAO_ClientRequestInterceptor_Adapter::
preinvoke (CORBA::ULong request_id,
           CORBA::Boolean two_way,
           CORBA::Object_ptr objref,
           const char *operation,
           IOP::ServiceContextList &sc,
           CORBA::NVList_ptr &args,
           PortableInterceptor::Cookies &cookies,
           CORBA::Environment &ACE_TRY_ENV)
{
  if (! CORBA::is_nil (this->interceptor_.in ()))
    this->interceptor_->preinvoke (request_id,
                                   two_way,
                                   objref,
                                   operation,
                                   sc,
                                   args,
                                   cookies,
                                   ACE_TRY_ENV);
}

ACE_INLINE void
TAO_ClientRequestInterceptor_Adapter::
postinvoke (CORBA::ULong request_id,
            CORBA::Boolean two_way,
            CORBA::Object_ptr objref,
            const char *operation,
            IOP::ServiceContextList &sc,
            CORBA::NVList_ptr &args,
            PortableInterceptor::Cookies &cookies,
            CORBA::Environment &ACE_TRY_ENV)
{
  if (! CORBA::is_nil (this->interceptor_.in ()))
    this->interceptor_->postinvoke (request_id,
                                    two_way,
                                    objref,
                                    operation,
                                    sc,
                                    args,
                                    cookies,
                                    ACE_TRY_ENV);
}

ACE_INLINE void
TAO_ClientRequestInterceptor_Adapter::
exception_occurred (CORBA::ULong request_id,
                    CORBA::Boolean two_way,
                    CORBA::Object_ptr objref,
                    const char *operation,
                    //IOP::ServiceContextList &,
                    //CORBA::Exception_ptr &,
                    PortableInterceptor::Cookies &cookies,
                    CORBA::Environment &ACE_TRY_ENV)
{
  if (! CORBA::is_nil (this->interceptor_.in ()))
    this->interceptor_->exception_occurred (request_id,
                                            two_way,
                                            objref,
                                            operation,
                                            cookies,
                                            ACE_TRY_ENV);
}

ACE_INLINE
TAO_ServerRequestInterceptor_Adapter::TAO_ServerRequestInterceptor_Adapter
  (PortableInterceptor::ServerRequestInterceptor_ptr interceptor)
    : interceptor_ (interceptor)
{
}

ACE_INLINE
TAO_ServerRequestInterceptor_Adapter::~TAO_ServerRequestInterceptor_Adapter
  (void)
{
}

ACE_INLINE void
TAO_ServerRequestInterceptor_Adapter::
preinvoke (CORBA::ULong request_id,
           CORBA::Boolean two_way,
           CORBA::Object_ptr objref,
           const char *operation,
           IOP::ServiceContextList &sc,
           CORBA::NVList_ptr &args,
           PortableInterceptor::Cookies &cookies,
           CORBA::Environment &ACE_TRY_ENV)
{
  if (! CORBA::is_nil (this->interceptor_.in ()))
    this->interceptor_->preinvoke (request_id,
                                   two_way,
                                   objref,
                                   operation,
                                   sc,
                                   args,
                                   cookies,
                                   ACE_TRY_ENV);
}

ACE_INLINE void
TAO_ServerRequestInterceptor_Adapter::
postinvoke (CORBA::ULong request_id,
            CORBA::Boolean two_way,
            CORBA::Object_ptr objref,
            const char *operation,
            IOP::ServiceContextList &sc,
            CORBA::NVList_ptr &args,
            PortableInterceptor::Cookies &cookies,
            CORBA::Environment &ACE_TRY_ENV)
{
  if (! CORBA::is_nil (this->interceptor_.in ()))
    this->interceptor_->postinvoke (request_id,
                                    two_way,
                                    objref,
                                    operation,
                                    sc,
                                    args,
                                    cookies,
                                    ACE_TRY_ENV);
}

ACE_INLINE void
TAO_ServerRequestInterceptor_Adapter::
exception_occurred (CORBA::ULong request_id,
                    CORBA::Boolean two_way,
                    CORBA::Object_ptr objref,
                    const char *operation,
                    //IOP::ServiceContextList &,
                    //CORBA::Exception_ptr &,
                    PortableInterceptor::Cookies &cookies,
                    CORBA::Environment &ACE_TRY_ENV)
{
  if (! CORBA::is_nil (this->interceptor_.in ()))
    this->interceptor_->exception_occurred (request_id,
                                            two_way,
                                            objref,
                                            operation,
                                            cookies,
                                            ACE_TRY_ENV);
}
#endif /* TAO_HAS_INTERCEPTORS */
