import QtQuick 1.1
import com.nokia.meego 1.0

PageStackWindow {
    id: appWindow

    initialPage: mainPage

    MainPage {
        id: mainPage
    }

    ToolBarLayout {
        id: commonTools
        visible: true
        ToolIcon {
            platformIconId: "toolbar-view-menu"
            anchors.right: (parent === undefined) ? undefined : parent.right
            onClicked: (myMenu.status === DialogStatus.Closed) ? myMenu.open() : myMenu.close()
        }
    }

    Menu {
        id: myMenu
        visualParent: pageStack
        MenuLayout {
            MenuItem { text: qsTr("Sample menu item") }
        }
    }
    Rectangle {
        id: container
        anchors.fill: parent

        ListModel {
            id: animalsModel
            ListElement { name: "Parrot"; size: "Small" }
            ListElement { name: "Guinea pig"; size: "Small" }
            ListElement { name: "Dog"; size: "Medium" }
            ListElement { name: "Cat"; size: "Medium" }
            ListElement { name: "Elephant"; size: "Large" }
        }

        // The delegate for each section header
        Component {
            id: sectionHeading
            Rectangle {
                width: container.width
                height: childrenRect.height
                color: "lightsteelblue"

                Text {
                    text: section
                    font.bold: true
                }
            }
        }

        ListView {
            id: mainList
            anchors.fill: parent
            delegate: Text { id: pon ; text: type}

            section.property: "size"
            section.criteria: ViewSection.FullString
            section.delegate: sectionHeading
        }
    }
}
