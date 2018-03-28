#include "ofApp.h"

#include "Model.h"

#include "ModelDmitriy.h"
#include "ModelLennert.h"
#include "ModelJalle.h"
<<<<<<< HEAD
#include "ModelSandy.hpp"
=======
#include "ModelSandie.h"
>>>>>>> 7c90f3674f87248185c3ebea953f7425a44ee192


//#include "Model3.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    fboSize = 250;

    models.push_back(new ModelJalle());
    models.back()->setup("model-jalle.obj", fboSize, fboSize);
    models.push_back(new ModelDmitriy());
    models.back()->setup("model-dmitriy.obj", fboSize, fboSize);
    models.push_back(new Model());
    models.back()->setup("model-bjarni.obj", fboSize, fboSize);
    models.push_back(new Model());
    models.back()->setup("model-lennert.obj", fboSize, fboSize);
<<<<<<< HEAD
    models.push_back(new ModelSandy());
    models.back()->setup("model-sandy.obj", fboSize, fboSize);
=======
	models.push_back(new ModelSandie());
	models.back()->setup("model-sandie.obj", fboSize, fboSize);

>>>>>>> 7c90f3674f87248185c3ebea953f7425a44ee192

}

//--------------------------------------------------------------
void ofApp::update(){
    for(IModel* m : models){
        m->update(0.5);
        m->drawInFbo();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofVec2f offset;
    for(IModel* m : models){
        m->drawFbo(offset.x,offset.y);
        
        offset.x += fboSize +2;
        if(offset.x > ofGetWidth() - fboSize){
            offset.y += fboSize + 2;
            offset.x = 0;
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
