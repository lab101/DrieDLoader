#pragma once
#include "ofMain.h"


class IModel {
	public:


		virtual void setup(std::string Path, float fboWidth, float fboHeight) = 0;
		virtual void update(float speed) = 0;
		virtual void drawInFbo() = 0;
		virtual void drawFbo(float x, float y) = 0;

};
