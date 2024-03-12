import QtQuick 1.1
import com.nokia.meego 1.0
import IarChep.MeeShop 1.0


Page {
    tools: commonTools
    Test {
        id: test
    }

    AnimalModel {
        id: model
    }

    Component.onCompleted: test.initialize()

    Connections {
        target: test

        onInit_finished : {
            mainList.model = test.model
        }
    }
}
