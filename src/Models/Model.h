#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "IModel.h"


class Particle{
    
public:
    ofVec3f startPosition;
    ofVec3f orginalPosition;
    ofVec3f currentPostion;
    float speed;
};


class Model : public IModel {

	ofxAssimpModelLoader modelLoader;
	ofMesh faceMesh;
    
    
    float resetAnimationTimer;
    
    // original loaded mesh in a vbo
    ofVboMesh vboMesh;
    
	ofCamera camera;
	ofLight light1;

	ofFbo fbo;
    
    vector<Particle> particles;


public:
	void setup(string Path, float fboWidth, float fboHeight);
	void update(float speed);
	void draw();
	void drawInFbo();
	void drawFbo(float x, float y);



};
