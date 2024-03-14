import QtQuick 1.1
import com.nokia.meego 1.0
import IarChep.MeeShop 1.0


Page {
    id: mainPage
    tools: commonTools

    Repository {
        id: mainRepo
    }

    property string title : "<b>Meeshop:<b> Home"

    //tools: commonTools
    orientationLock: PageOrientation.LockPortrait
    Image {
        id: pageHeader
        anchors {
            top: mainPage.top
            left: mainPage.left
            right: mainPage.right
        }

        height: parent.width < parent.height ? 72 : 46
        width: parent.width
        source: "image://theme/meegotouch-view-header-fixed" + (theme.inverted ? "-inverted" : "")
        z: 1

        Label {
            id: header
            anchors {
                verticalCenter: parent.verticalCenter
                left: parent.left
                leftMargin: 16
            }
            platformStyle: LabelStyle {
                fontFamily: "Nokia Pure Text Light"
                fontPixelSize: 32
            }
            text: mainPage.title
        }
    }
    ListView {
        id: mainList
        width: parent.width
        height: parent.height- pageHeader.height
        anchors.top: pageHeader.bottom
        delegate: Rectangle {
            id: appelem
            width: 480
            height: 90
            color: mouseArea.pressed === true ? "#bbbcbe" : "#e0e1e2"
            Row {
                x: 15
                anchors.verticalCenter: parent.verticalCenter
                spacing: 15
                Image {
                    id: icon
                    source: "http://wunderwungiel.pl/MeeGo/openrepos/icons/" + app_icon
                }

                Column {
                    Text {
                        text: app_name
                        color: "black"
                        font.pixelSize: 25
                    }
                    Text {
                        text: "Size: " + app_size
                        color: "black"
                        font.pixelSize: 20
                    }
                }
            }
            MouseArea {
                id: mouseArea
                anchors.fill: appelem
            }
        }

        section.property: "letter"
        section.criteria: ViewSection.FullString
        section.delegate: Item {
            // "GroupHeader" component?
            width: parent.width
            height: 40
            Text {
                id: headerLabel
                anchors.right: parent.right
                anchors.rightMargin: UiConstants.DefaultMargin
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 2
                text: section
                font.bold: true
                font.pointSize: 18
                color: theme.inverted ? "#4D4D4D" : "#3C3C3C";
            }
            Image {
                anchors.right: headerLabel.left
                anchors.left: parent.left
                anchors.verticalCenter: headerLabel.verticalCenter
                anchors.rightMargin: 24
                source: "image://theme/meegotouch-groupheader" + (theme.inverted ? "-inverted" : "") + "-background"
            }
        }
    }

    Connections {
        target: mainRepo

        onInformation_loading_finished: {
            mainRepo.model.slice(0,13)
            mainList.model = mainRepo.model
        }
    }


    Component.onCompleted: mainRepo.load_applications("catalog_new.xml")
}
