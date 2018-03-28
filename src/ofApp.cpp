#include "ofApp.h"

#include "Model.h"


#include "ModelDmitriy.h"
#include "ModelLennert.h"
#include "ModelJalle.h"
#include "ModelSandie.h"
#include "ModelMarkian.h"
#include "ModelBjarni.h"


//#include "Model3.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
  
    fboSize = 250;

    models.push_back(new ModelLennert());
    models.back()->setup("model-lennert.obj", fboSize, fboSize);
    models.push_back(new ModelJalle());
    models.back()->setup("model-jalle.obj", fboSize, fboSize);
    models.push_back(new ModelDmitriy());
    models.back()->setup("model-dmitriy.obj", fboSize, fboSize);
    models.push_back(new ModelBjarni());
    models.back()->setup("model-bjarni.obj", fboSize, fboSize);
	models.push_back(new ModelSandie());
	models.back()->setup("model-sandie.obj", fboSize, fboSize);
	models.push_back(new ModelMarkian());
	models.back()->setup("model-Markian.obj", fboSize, fboSize);


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
