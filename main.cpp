#include "jswidget.h"
#include "jsserver.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>

#include <Tufao/HttpServerResponse>
#include <Tufao/HttpServer>
#include <Tufao/HttpFileServer>
#include <Tufao/HttpServerRequestRouter>
#include <Tufao/NotFoundHandler>
#include <QDebug>
using namespace Tufao;

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QApplication a(argc, argv);

    JsServer server;
    server.serv();

    JsWidget w;
    w.show();
    return a.exec();
}
