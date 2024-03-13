import QtQuick 1.1
import com.nokia.meego 1.0
import IarChep.MeeShop 1.0


Page {
    id: mainPage
    tools: commonTools

    Repository {
        id: mainRepo
    }

    Component {
        id: sectionHeading
        Rectangle {
            width: mainPage.width
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
        model: mainRepo.model
        delegate: Text { id: pon ; text: app_name}

        section.property: "letter"
        section.criteria: ViewSection.FullString
        section.delegate: sectionHeading
    }


    Component.onCompleted: mainRepo.load_applications("catalog_new.xml")
}
