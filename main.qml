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

import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import io.qt.examples.backend 1.0
import QtQuick.Layouts 1.11
import QtQuick.Window 2.2
import QtQuick.Scene3D 2.0
import QtQuick.Controls 2.0
import QtQuick 2.6
Item{
    width: 1270
    height: 768

      Scene3D {
            id: scene
            anchors.fill: parent
            aspects: ["input", "logic","render"]
            cameraAspectRatioMode: Scene3D.AutomaticAspectRatio
            focus: true

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

                    components: [
                        RenderSettings {
                            activeFrameGraph: ForwardRenderer {
                                camera: camera
                                clearColor: Qt.rgba(0, 0.5, 1, 1)
                            }
                        }
                        // Event Source will be set by the Qt3DQuickWindow
                    ]

                    OrbitCameraController {
                        camera: camera
                    }
                    // Event Source will be set by the Qt3DQuickWindow


                    InputSettings { }

                    BackEnd {
                        id:backend
                    }

                    NodeInstantiator {
                        id: grid

                        model: 1

                            Entity {
                                id:nodes

                                Transform {
                                    id: sphereTransformer
                                    translation: backend.location
                                }

                                PhongMaterial {
                                    id: material
                                }

                                SphereMesh {
                                    id: sphereMes
                                    slices: 60
                                    rings: 60
                                    radius: 0.65
                                }

                                components: [ sphereTransformer, sphereMes, material ]

                            }


                        }

                        NodeInstantiator {
                            id: edges

                            model: 1

                            Entity {
                                id:edge

                                ObjectPicker {
                                    id: picker2
                                    signal pressed(PickEvent pick)
                                    onPressed: {
                                        console.log(pick.localIntersection, pick.worldIntersection)
                                    }

                                }


                                Transform {
                                    id: edgeTransformer
                                    translation: backend.location //Qt.vector3d(0,0,0)
                                    rotation: 90
                                    rotationX: 45
                                }

                                PhongMaterial {
                                    id: material2
                                }

                                CylinderMesh {
                                    id: cylMesh
                                    slices: 20
                                    rings: 20
                                    radius: 0.25
                                }

                                components: [ edgeTransformer, cylMesh, material2 ]
                            }

                        }


                }




        }


    Row {
        anchors.top: parent.top
        anchors.topMargin: 10
        focus: false


            Button {
                id: start
                text: "Start"
                z: 2
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 10



            }

            Button {
                id: stop
                text: "Stop"
                z: 2
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 125

            }
     }



        Text {
            id: locationText
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.rightMargin: 15
            text: "{ 0,0,0 }"
            color: "white"
            font.family: "Helvetica"
            font.pointSize: 15


           function changeText(x, y, z){
                 text: "{" + x + ", " + y + ", " + z + "}"
           }


        }



        Slider {
            id: durationSlider

            focus: false
            value: 50
            orientation: Qt.Vertical
            stepSize: 0.1
            from: 0
            to: 100

            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.rightMargin: 25
            anchors.bottomMargin: 10
            anchors.topMargin: 10
            topPadding: 5
            wheelEnabled: false

            signal roundDurationChanged(int value)
            property bool setterDisabled: false;
            property bool callbackDisabled: false;

            onValueChanged: {
                if(!callbackDisabled){
                            roundDurationChanged(transferFunc(value))
                            roundDurationText.text = transferFunc(value) + " ms"
                }
            }

                    onPressedChanged: {
                        /**When changing the value via slider disable the "setRoundDuration" function
                        because it is always called when "value" changes. This is because
                        "onValueChanged" calls "roundDurationChanged" which results in a "setRoundDuration"
                        call. Therefore we break the cycle by disabling the latter.
                        **/
                        setterDisabled = !setterDisabled
                    }

                    function setRoundDuration(ms){
                        if(!setterDisabled){
                            /**When setting the ms value via console this setter is called. This setter
                              changes the value of the slider which results in a call of "onValueChanged".
                              As explained above, that function results in a call of this setter again.
                              Therefore we break the cycle by disabling the callback "onValueChanged" for
                              this value change.
                            **/
                            callbackDisabled = true
                            value = invTransferFunc(ms)
                            callbackDisabled = false
                            roundDurationText.text = ms + " ms"
                        }
                    }


                    function transferFunc(val){

                        var ms;
                        var b = Math.pow(0.2, 1/49)
                        var a = 100 * Math.pow(5, 1/49)
                        if( val >= 50){
                            ms = -0.4*val + 40
                        } else {
                            ms = a*Math.pow(b, val)
                        }
                        return Math.round(ms)
                    }

                    function invTransferFunc(ms){
                        var val;
                        var a = 100 * Math.pow(5, 1/49)
                        if( ms <= 20 ){
                            val = -2.5*ms + 100
                        } else {
                            val = (49/Math.log(5))*Math.log(a/ms)
                        }

                        return val
                    }
            Text {
                 id: roundDurationText
                 text: durationSlider.transferFunc(50) + " ms"
                 anchors.bottom: durationSlider.top
                 anchors.bottomMargin: 10
                 color: "white"
            }

        }




}
