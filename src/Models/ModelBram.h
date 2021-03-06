#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "IModel.h"

class ModelBram : public IModel {

	ofxAssimpModelLoader modelLoader;
	ofMesh faceMesh;
	ofMesh faceMesh1;
	ofMesh faceMesh2;

	// original loaded mesh in a vbo
	ofVboMesh vboMesh;

	ofCamera camera;
	ofLight light1;
	ofLight light2;

	ofFbo fbo;


public:
	void setup(string Path, float fboWidth, float fboHeight);
	void update(float speed);
	void draw();
	void drawInFbo();
	void drawFbo(float x, float y);



};
#pragma once
