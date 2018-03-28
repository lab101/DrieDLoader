#include  "ModelLennert.h"




void ModelLennert::setup(string path, float fboWidth, float fboHeight) {
    
    ofSetFullscreen(true);
    modelLoader.loadModel(path, false);
    
    ofSetSmoothLighting(true);
    vboMesh = modelLoader.getMesh(0);
    
    vector<ofVec3f>& vertices = vboMesh.getVertices();
    vector<ofIndexType>& indices = vboMesh.getIndices();
    vector<ofVec3f> normals = vboMesh.getNormals();
    
    
    // recreating the mesh.
    for (ofVec3f& v : vertices) {
        faceMesh.addVertex(v * 30);}
    
    for (size_t index : indices) {
        faceMesh.addIndex(index);
        
    }
    
    for (ofVec3f normal : normals) {
        faceMesh.addNormal(normal);
        
    }
    
    
    // setup the camera
    camera.setPosition(0, 9, 9);
    camera.lookAt(ofVec3f(0, 1, 0));
    
    light1.setPosition(0, 5, 5);
    
    fbo.allocate(fboWidth, fboHeight);
    
}


void ModelLennert::update(float speed) {
    vector<ofVec3f>& vertices = vboMesh.getVertices();
    vector<ofIndexType>& indices = vboMesh.getIndices();
    vector<ofVec3f> normals = vboMesh.getNormals();
    
    
    faceMesh.clearColors();
    faceMesh.clear();
    for (ofVec3f& v : vertices) {
        if(v.z >0.09){
            v.x +=sin((ofGetElapsedTimef())/0.3)/3000;
            v.y += sin((ofGetElapsedTimef())/0.3)/3000;
        }else if(v.z >0.05){
            v.x +=sin((ofGetElapsedTimef())/0.3)/3100;
            v.y += sin((ofGetElapsedTimef())/0.3)/3100;
        }else if(v.z >0.01){
            v.x +=sin((ofGetElapsedTimef())/0.3)/3200;
            v.y +=sin((ofGetElapsedTimef())/0.3)/3200;
            
        }else if(v.z > -0.01 && v.y>2){
            v.x +=sin((ofGetElapsedTimef())/0.3)/3300;
            v.y +=sin((ofGetElapsedTimef())/0.3)/3300;
            
        }else if(v.z > -0.06){
            v.x +=sin((ofGetElapsedTimef())/0.3)/3400;
            v.y +=sin((ofGetElapsedTimef())/0.3)/3400;
            
        }else if(v.z > -0.1){
            v.x +=sin((ofGetElapsedTimef())/0.3)/3500;
            v.y +=sin((ofGetElapsedTimef())/0.3)/3500;
        }else{
            v.x +=sin((ofGetElapsedTimef())/0.3)/3600;
            v.y +=sin((ofGetElapsedTimef())/0.3)/3600;
        }
        
        
        faceMesh.addVertex(v * 30);}
    
    for (size_t index : indices) {
        faceMesh.addIndex(index);
        
    }
    
    for (ofVec3f normal : normals) {
        faceMesh.addNormal(normal);
        
    }
    
    
    float hueStart = fmod(ofGetElapsedTimef() * 10, 255);
    for(ofVec3f& v : vboMesh.getVertices()){
        float h = ofMap(v.x, -0.1, 0.1, hueStart, hueStart +10, true);
        float s = ofMap(v.y, -0.1, 0.1, 255, 100, true);
        
        faceMesh.addColor(ofColor::fromHsb(h, s, 255));
    }
    
    // clearint the vertices and adding new ones with some noise
    //    faceMesh.clearVertices();
    //    for (ofVec3f& v : vboMesh.getVertices()) {
    //
    //    }
    
    light1.setAmbientColor(ofColor::fromHsb(hueStart + 10, 255, 255));
    
    
    
}


void ModelLennert::draw() {
    float hueStart = fmod(ofGetElapsedTimef() * 10, 255);
    ofClear(ofColor::fromHsb(360, 220, 220));
    

    camera.begin();
    
    ofEnableLighting();
    ofEnableDepthTest();
    
    ofPushMatrix();
    
    
    ofRotateY(ofGetElapsedTimef() * 15);
    ofRotateX(-120);
    
    // draw mesh with lighting
    light1.enable();
    light2.enable();
    //faceMesh.drawFaces();
    for(ofVec3f& v : vboMesh.getVertices()){
        float h = ofMap(v.x, -0.1, 0.1, hueStart, hueStart +20, true);
        float s = ofMap(v.y, -0.1, 0.1, 255, 100, true);
        ofSetColor(ofColor::fromHsb(h, s, 255));
    }
    
    for (ofVec3f& v : vboMesh.getVertices()) {
        
        
        float x = sin((ofGetElapsedTimef())/0.5)+v.x;
        float radius = ofMap(x, -1, 1, 0.02, 0.2);
        radius += ofRandom(0.03);
        ofDrawSphere ((v*30)+ofNoise(v.x),radius);
        
    }
    
    
    
    light1.disable();
    light2.disable();
    
    
    
    ofDisableLighting();
    // for vertices and wireframe draw without lighting
    //faceMesh.drawVertices();
    //faceMesh.drawWireframe();
    
    ofPopMatrix();
    camera.end();
}


void ModelLennert::drawInFbo() {
    fbo.begin();
    draw();
    fbo.end();
}

void ModelLennert::drawFbo(float x, float y) {
    fbo.draw(x, y);
}

