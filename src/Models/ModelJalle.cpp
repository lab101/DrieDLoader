#include  "ModelJalle.h"




void ModelJalle::setup(string path, float fboWidth, float fboHeight) {

	modelLoader.loadModel(path, false);

    ofSetSmoothLighting(true);
    vboMesh = modelLoader.getMesh(0);
    
	vector<ofVec3f>& vertices = vboMesh.getVertices();
	vector<ofIndexType>& indices = vboMesh.getIndices();
	vector<ofVec3f> normals = vboMesh.getNormals();

    
    // recreating the mesh.
	/*
	for (ofVec3f& v : vertices) {
		faceMesh.addVertex(v * 10);
	}

	for (size_t index : indices) {
		faceMesh.addIndex(index);
	}

	for (ofVec3f normal : normals) {
		faceMesh.addNormal(normal);
	}
	*/
    
    
    // setup the camera
	camera.setPosition(0, 9, 9);
	camera.lookAt(ofVec3f(0, 3, -8));

	light1.setPosition(0, 5, 5);
    
    fbo.allocate(fboWidth, fboHeight);


    
}


void ModelJalle::update(float speed) {


    faceMesh.clearColors();
    // clearint the vertices and adding new ones with some noise
	/*

    faceMesh.clearVertices();
    for (ofVec3f& v : vboMesh.getVertices()) {
		//glPointSize(ofNoise(ofGetElapsedTimef() * 0.8, v.y) * 10);
		faceMesh.addVertex((v * 10) + ofVec3f(v.x , v.y , v.z ));
    }

	*/
	//ofVec3f(v.x * 20 * cos(ofGetElapsedTimef()), v.y * 20 * sin(ofGetElapsedTimef()), v.z)

	
	/*
	faceMesh.clearVertices();
	    for (ofVec3f& v : vboMesh.getVertices()) {
	        faceMesh.addVertex((v * 10) + ofVec3f(ofSignedNoise(v.x * 0.1, v.y * 0.4, ofGetElapsedTimef()* speed) * 2.2, ofSignedNoise(v.y, v.x, ofGetElapsedTimef()* .3) * 2.2, 0));
	    }
    */
  
	light1.setAmbientColor(ofColor::fromHex(0xa50000,1));



}


void ModelJalle::draw() {
	
   // float hueStart = fmod(ofGetElapsedTimef() * 10, 255);    
    ofClear(ofColor(0, 0, 0));


	camera.begin();
    
    ofEnableLighting();
    ofEnableDepthTest();

	ofPushMatrix();


        //ofRotateY((ofGetElapsedTimef() * 10));
		//ofRotateY(90);
		//ofRotateY(sin(ofGetElapsedTimef()));
		ofRotateY(90 + sin(ofGetElapsedTimef() * 5) * 18);
		ofRotateZ(sin(ofGetElapsedTimef() * 10) * 8);
        ofRotateX(-90);
        ofScale(1.5, 1.5, 1.5);

        // draw mesh with lighting
        light1.enable();


		for (ofVec3f& v : vboMesh.getVertices()) {
			//ofDrawCylinder(v * 12, ofNoise(ofGetElapsedTimef() * 0.4, v.z) * 0.5, ofNoise(ofGetElapsedTimef() * 0.3, v.y) * 0.8);
			ofDrawCylinder(v * 12, ofNoise(ofGetElapsedTimef() * 0.4, v.z) * 0.5, ofNoise(ofGetElapsedTimef() * 0.4, v.y) * 0.8);

		}
        //faceMesh.drawFaces();
        light1.disable();



		



        ofDisableLighting();
        // for vertices and wireframe draw without lighting
		
        //faceMesh.drawVertices();
        //faceMesh.drawWireframe();
    
	ofPopMatrix();
	camera.end();
}


void ModelJalle::drawInFbo() {
	fbo.begin();
	draw();
	fbo.end();
}

void ModelJalle::drawFbo(float x, float y) {
	fbo.draw(x, y);
}
