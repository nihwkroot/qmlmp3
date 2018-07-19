#include "jswidget.h"
#include "jsserver.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QFile>
#include <QDir>
#include <QtDebug>
#include <QMouseEvent>

JsWidget::JsWidget(QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint), _size(550, 580)
{
    installEventFilter(this);
    _interactObj = new InteractObject(this);

    QWebChannel *channel = new QWebChannel(this);
    channel->registerObject(QStringLiteral("interactObj"), _interactObj);

    _webView = new QWebEngineView(this);
    _webView->page()->setWebChannel(channel);

    _webView->load(QUrl(QString("http://127.0.0.1:%1/index.html").arg(JsServer::serverPort())));
    _webView->setFixedSize(_size.width(), _size.height());
    _webView->show();


    this->setFixedSize(_size.width(), _size.height());
}

void JsWidget::appendContent(const QString &text)
{
    _edtContent->appendPlainText(text);
}

JsWidget::~JsWidget()
{

}

void JsWidget::onSendSlot()
{
    QString text = _edtInput->text().trimmed();
    if (text.isEmpty())
        return;

    _interactObj->sendStringToHtml(text);
    _edtInput->setText("");
}
