#ifndef SYNCH_HTTPCLIENT_H
#define SYNCH_HTTPCLIENT_H

#include "httpclient.h" // for: HTTPClient
#include "synch_httpclient_imp.h"   // for: SynchHTTPClientImp

// ----------
// Interfaces
// ----------
class SynchHTTPClient : public HTTPClient
{
public:
    SynchHTTPClient(boost::asio::io_service& _io_service)
        : ptrClientImp_(new SynchHTTPClientImp(_io_service)) {}

    void get(const std::string &_server, const std::string &_path) override;
    void post(const std::string &_server, const std::string &_path, const std::string &_xwwwformcoded) override;

    const std::string & get_response() const override { ptrClientImp_->get_response(); }

private:
    SynchHTTPClientImp * ptrClientImp_;
};


#endif // SYNCH_HTTPCLIENT_H