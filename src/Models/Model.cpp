#include  "Model.h"




void Model::setup(string path, float fboWidth, float fboHeight) {

	modelLoader.loadModel(path, false);

    vboMesh = modelLoader.getMesh(0);
	vector<ofVec3f>& vertices = vboMesh.getVertices();

    
    // recreating the mesh.
    
    for (int i=0; i < vertices.size(); i++) {
        Particle p;
        p.speed = ofRandom(1,10);
        p.orginalPosition = vertices[i] *10;
        p.startPosition.set(ofRandom(-100, 100), ofRandom(-100, 100),ofRandom(-100, 100));
        p.currentPostion = p.startPosition;
        particles.push_back(p);
	}
    
    
    resetAnimationTimer = ofGetElapsedTimef();

    
    // setup the camera
	camera.setPosition(0, 9, 9);
	camera.lookAt(ofVec3f(0, 3, 0));

    
    fbo.allocate(fboWidth, fboHeight);
    
}


void Model::update(float speed) {

    
    if(ofGetElapsedTimef() - resetAnimationTimer >  10){
        for(Particle& p : particles){
            p.speed = ofRandom(1,10);
            p.startPosition.set(ofRandom(-100, 100), ofRandom(-100, 100),ofRandom(-100, 100));
            p.currentPostion = p.startPosition;
        }
        
        resetAnimationTimer = ofGetElapsedTimef();
    }
    
    for(Particle& p : particles){
        
        
        ofVec3f  div = (p.orginalPosition - p.currentPostion);
        
        if(p.speed > 0.003){
            p.speed -= p.speed * 0.1;
        }else{
            p.speed = 0.003;
        }
        p.currentPostion += div.normalize() * p.speed;
        
        
    }


}


void Model::draw() {

    float hueStart = fmod(ofGetElapsedTimef() * 10, 255);    
    ofClear(ofColor(0));


	camera.begin();
    
    ofEnableDepthTest();

	ofPushMatrix();


        ofRotateY(ofGetElapsedTimef() * 14);
        ofRotateX(-90);
        ofScale(1.5, 1.5, 1.5);

        ofDisableLighting();
        for(Particle& p : particles){
            ofDrawBox(p.currentPostion, 0.04);
        }

    
  
    
    
	ofPopMatrix();
	camera.end();
}


void Model::drawInFbo() {
	fbo.begin();
	draw();
	fbo.end();
}

void Model::drawFbo(float x, float y) {
	fbo.draw(x, y);
}
