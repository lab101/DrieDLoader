#include "ofApp.h"

#include "Model.h"


#include "ModelDmitriy.h"


//#include "Model3.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    fboSize = 550;

<<<<<<< HEAD
    models.push_back(new ModelDmitriy());
    models.back()->setup("model-dmitriy.obj", fboSize, fboSize);
=======
    models.push_back(new ModelKris());
    models.back()->setup("model-dimitri.obj", fboSize, fboSize);
>>>>>>> 6b3c85f99fb3ba1748817e267e9431eaa91a7176

}

//--------------------------------------------------------------
void ofApp::update(){
    for(IModel* m : models){
        m->update(0.1);
        m->drawInFbo();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(IModel* m : models){
        m->drawFbo(0, 0);
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
