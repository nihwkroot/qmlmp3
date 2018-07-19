import QtQuick 2.0
import QtQuick.Window 2.0
import QtWebEngine 1.0

Window {
    width: 256
    height: 185
    visible: true
    WebEngineView {
        anchors.fill: parent
        url: "http://www.qt.io"
    }
}
