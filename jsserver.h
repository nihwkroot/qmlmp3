#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <Tufao/HttpServer>
#include <Tufao/HttpFileServer>
#include <Tufao/HttpServerRequestRouter>
#include <Tufao/NotFoundHandler>

class JsServer
{
private:
    static Tufao::HttpServer* _server;
    static Tufao::NotFoundHandler* _handler404;
    static Tufao::HttpServerRequestRouter* _router;
    static uint _ref;
    void init();
    void deinit();
public:
    JsServer();
    ~JsServer();

    static uint16_t serverPort();
    void serv();
};

#endif // HTTPSERVER_H
