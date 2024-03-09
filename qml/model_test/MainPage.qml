import QtQuick 1.1
import com.nokia.meego 1.0
import IarChep.MeeShop 1.0


Page {
    tools: commonTools
    InfoManager {
        id: info
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
            model: info.model
            delegate: Text { text: model.app_name }

            section.criteria: ViewSection.FullString
            section.delegate: sectionHeading
        }
    }
    Component.onCompleted: info.load_applications("catalog_new.xml")

    Connections {
        target: info

        onInformation_loading_finished: mainList.model = info.model
    }
}
