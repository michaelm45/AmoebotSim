/****************************************************************************
**
** Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
import QtQuick.Controls 1.4
import Qt3D.Core 2.0
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import io.qt.examples.backend 1.0
import QtQuick.Layouts 1.11
import QtQuick.Window 2.2
import QtQuick.Scene3D 2.0
import QtQuick 2.6 as QQ2
import QtQuick 2.6
import QtQuick.Controls 2.0
Item{
    id: mainWindow
    width: 1270
    height: 768
    visible: true


    Rectangle {
        id: scene1
        anchors.fill: parent
        anchors.margins: 50

        transform:Rotation {
            id:sceneRotation
            axis.x: 1
            axis.y: 0
            axis.z: 0
            origin.x: scene1.width /2
            origin.y: scene1.height /2
        }

        Scene3D {
            id: scene2
            anchors.fill: parent
            focus:true
            aspects: ["input", "logic"]
            cameraAspectRatioMode: Scene3D.AutomaticAspectRatio



                Entity {
                    id: sceneRoot

                    Camera {
                        id: camera
                        projectionType: CameraLens.PerspectiveProjection
                        fieldOfView: 45
                        aspectRatio: 16/9
                        nearPlane : 0.1
                        farPlane : 1000.0
                        position: Qt.vector3d( 0.0, 0.0, -40.0 )
                        upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
                        viewCenter: Qt.vector3d( 0.0, 0.0, 0.0 )
                    }

                    FirstPersonCameraController {
                        camera: camera
                    }
                    InputSettings { }
                    components: [
                        RenderSettings {
                            activeFrameGraph: ForwardRenderer {
                                camera: camera
                                clearColor: Qt.rgba(0, 0.5, 1, 1)
                            }
                        }
                        // Event Source will be set by the Qt3DQuickWindow

                    ]

                    PhongMaterial {
                        id: material
                    }

                    BackEnd {
                        id:backend
                    }

                    Entity {
                        id: spheres

                        SphereMesh {
                            id: sphereMes
                            slices: 60
                            rings: 60
                            radius: 0.65
                        }

                        NodeInstantiator {
                            id: grid

                            property int rows: 5
                            property int columns: 5
                            property int width: 5

                            model: rows * columns * width

                            Entity {

                                Transform {
                                    id: sphereTransformer
                                    translation: backend.location
                                }

                                components: [ sphereTransformer, sphereMes, material ]
                            }
                        }
                    }

                }



        }
    }



    Row {
        anchors.top: parent.top
        anchors.topMargin: 10

            Button {
                id: start
                text: "Start"
                z: 2
                anchors.left: parent.left
                anchors.top: parent.top
                //anchors.topMargin: 10
                anchors.leftMargin: 10

            }

            Button {
                id: stop
                text: "Stop"
                z: 2
                anchors.left: parent.left
                anchors.top: parent.top
                //anchors.topMargin: 10
                anchors.leftMargin: 125

            }




     }


        Slider {
            id: durationSlider
            value: .50
            orientation: Qt.Vertical
            stepSize: .1
            z: 2
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.rightMargin: 10
            anchors.bottomMargin: 10

        }

}








/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
