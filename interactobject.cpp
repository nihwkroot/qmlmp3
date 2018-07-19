#include "interactobject.h"
#include "jswidget.h"

InteractObject::InteractObject(JsWidget *parent)
: QObject(parent)
, _jsWidget(parent)
{

}

void InteractObject::sendStringToHtml(const QString &text)
{
    emit sendStringSignal(text);
}

/*!
This slot is invoked from the HTML client side and the text displayed on the server side.
*/
void InteractObject::recvStringSlot(const QString &text)
{
    _jsWidget->appendContent("Received string: " + text);
}
