#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "IModel.h"

class ModelBjarni : public IModel {

	ofxAssimpModelLoader modelLoader;
	ofMesh faceMesh;
    
    // original loaded mesh in a vbo
    ofVboMesh vboMesh;
    
	ofCamera camera;
	ofLight light1;

	ofFbo fbo;


public:
	void setup(string Path, float fboWidth, float fboHeight);
	void update(float speed);
	void draw();
	void drawInFbo();
	void drawFbo(float x, float y);



};
