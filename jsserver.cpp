#include "jsserver.h"
#include <QtDebug>

using namespace Tufao;

HttpServer* JsServer::_server;
NotFoundHandler* JsServer::_handler404;
HttpServerRequestRouter* JsServer::_router;
uint JsServer::_ref;

JsServer::JsServer()
{
    if(!_server){
        _server = new HttpServer();
    }
    if(!_handler404){
        _handler404 = new NotFoundHandler();
    }
    if(!_router){
        _router = new HttpServerRequestRouter();
    }
    _ref++;
}

void JsServer::init(){
    _router->map({
        {QRegularExpression{ "" }, HttpFileServer::handler ( "/opt/mp3/static" )},
        {QRegularExpression{ "" }, NotFoundHandler::handler ()}});
}

void JsServer::serv(){
    if(_server->isListening()) return;
    init();
    QObject::connect(_server, &HttpServer::requestReady ,
                     _router, & HttpServerRequestRouter::handleRequest );
    _server->listen(QHostAddress::LocalHost, 0);
}

uint16_t JsServer::serverPort(){
    qDebug() << _server->serverPort();
    return _server->isListening() ?  _server->serverPort() : 0;
}

void JsServer::deinit(){
    if(_server->isListening())
        _server->close();
    QObject::disconnect(_server, &HttpServer::requestReady ,
                        _router, & HttpServerRequestRouter::handleRequest );
}

JsServer::~JsServer()
{
    _ref--;
    if(_ref > 0) return;

    deinit();
    if(!_server){
        delete _server;
    }
    if(!_handler404){
        delete _handler404;
    }
    if(!_router){
        delete _router;
    }
}

