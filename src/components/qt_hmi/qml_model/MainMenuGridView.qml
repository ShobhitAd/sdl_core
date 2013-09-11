import QtQuick 2.0

GridView
{
    id: mainMenuGridview

    populate: Transition {
        id: populateTransition;
        SequentialAnimation {
            PropertyAction  {
                property: "opacity";
                value: 0
            }
            PauseAnimation {
                duration: populateTransition.ViewTransition.index * 100;
            }
            NumberAnimation {
                properties: "opacity"
                from: 0
                to: 1
                duration: 300
            }
        }
    }

    anchors.fill: parent
    cellWidth: width / 4
    cellHeight: height / 2
    highlightFollowsCurrentItem: false
    snapMode: GridView.SnapToRow
    flickableDirection: Flickable.AutoFlickDirection
    interactive: true

    model: Menu {}
    highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
    focus: true

    delegate: Item {
        width: mainMenuGridview.cellWidth
        height: mainMenuGridview.cellHeight
        MouseArea {
            cursorShape: Qt.PointingHandCursor
            anchors.fill: parent
            onClicked: {
                mainScreen.state = name
                menuContainer.source = qml
            }
        }

        Image { source: icon; anchors.horizontalCenter: parent.horizontalCenter; anchors.verticalCenter: parent.verticalCenter;}
    }
}
