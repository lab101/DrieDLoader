#include  "ModelDmitriy.h"




void ModelDmitriy::setup(string path, float fboWidth, float fboHeight) {

	modelLoader.loadModel(path, false);

    ofSetSmoothLighting(true);
    vboMesh = modelLoader.getMesh(0);
    
	vector<ofVec3f>& vertices = vboMesh.getVertices();
	vector<ofIndexType>& indices = vboMesh.getIndices();
	vector<ofVec3f> normals = vboMesh.getNormals();

    
    // recreating the mesh.
	for (ofVec3f& v : vertices) {
		faceMesh.addVertex(v * 10);
	}

	for (size_t index : indices) {
		faceMesh.addIndex(index);
	}

	for (ofVec3f normal : normals) {
		faceMesh.addNormal(normal);
	}
    
    
    // setup the camera
	camera.setPosition(0, 9, 9);
	camera.lookAt(ofVec3f(0, 3, 0));

	light1.setPosition(0, 5, 5);
    
    fbo.allocate(fboWidth, fboHeight);
    
}


void ModelDmitriy::update(float speed) {


    faceMesh.clearColors();
    
    // adjust the colors
    float hueStart = fmod(ofGetElapsedTimef() * 10, 255);
    //for(ofVec3f& v : vboMesh.getVertices()){
    //    float h = ofMap(v.x, -0.1, 0.1, hueStart, hueStart +10, true);
    //    float s = ofMap(v.y, -0.1, 0.1, 255, 100, true);

    //    faceMesh.addColor(ofColor::fromHsb(h, s, 255));
    //}
    //
    //// clearint the vertices and adding new ones with some noise
    //faceMesh.clearVertices();
    //for (ofVec3f& v : vboMesh.getVertices()) {
   
    //}
    
    light1.setAmbientColor(ofColor::fromHsb(hueStart + 10, 255, 255));



}


void ModelDmitriy::draw() {

    float hueStart = fmod(ofGetElapsedTimef() * 10, 255);    
    ofClear(ofColor::fromHsb(hueStart, 100, 0));


	camera.begin();
    
    ofEnableLighting();
    ofEnableDepthTest();

	ofPushMatrix();


        ofRotateY(ofGetElapsedTimef() * 10);
        ofRotateX(-90);
        ofScale(1.5, 1.5, 1.5);

        // draw mesh with lighting
        light1.enable();
		light2.enable();
        //faceMesh.drawFaces();
		for (ofVec3f& v : vboMesh.getVertices()) {
			ofDrawBox(v*12, ofSignedNoise(v.y, v.x, v.z, ofGetElapsedTimef()* .3));
		}



		light1.disable();
        light2.disable();



        ofDisableLighting();
        // for vertices and wireframe draw without lighting
//        faceMesh.drawVertices();
       // faceMesh.drawWireframe();
    
	ofPopMatrix();
	camera.end();
}


void ModelDmitriy::drawInFbo() {
	fbo.begin();
	draw();
	fbo.end();
}

void ModelDmitriy::drawFbo(float x, float y) {
	fbo.draw(x, y);
}
