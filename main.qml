import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import custom.clock 1.0

Window {

    width: 640
    height: 480
    visible: true
    title: qsTr("Clock");

    Clock {
        id: myClock
    }

    Row {

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 180

        Text {
            id: dateDisplay
            text: myClock.date
        }
    }


    Row {

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 200

        Text {
            id: timeDisplay
            font.bold: true
            font.pixelSize: 22
            font.pointSize: 22
            text: myClock.time
        }

    }

    Row {

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 3

        Button {
            id: btnStop
            text: "Stop"
            onClicked: {
                if (btnStop.text === "Start") {
                    btnStop.text = "Stop";
                } else {
                    btnStop.text = "Start";
                }
                myClock.btnHandler();
            }
        }

    }

}
