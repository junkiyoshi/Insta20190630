#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(1);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int size = 30;
	for (int len = 60; len <= 360; len += 60) {

		ofPushMatrix();
		ofRotateY(ofMap(ofNoise((len * 0.1 + ofGetFrameNum()) * 0.01), 0, 1, -180, 180));
		for (int x = -len * 0.5; x <= len * 0.5; x += size) {

			for (int y = -len * 0.5; y <= len * 0.5; y += size) {

				if (x == -len * 0.5 || x == len * 0.5 || y == -len * 0.5 || y == len * 0.5) {

					ofNoFill();
					ofSetColor(39);
					ofDrawBox(glm::vec3(x, y, 0), size * 0.9);

					ofFill();
					ofSetColor(239);
					ofDrawBox(glm::vec3(x, y, 0), size * 0.88);
				}
			}
		}
		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}