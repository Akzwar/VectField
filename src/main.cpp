#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"
#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768

//========================================================================
int main( ){

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, SCREEN_WIDTH,SCREEN_HEIGHT, OF_FULLSCREEN);
	testApp* myapp = new testApp(SCREEN_WIDTH,SCREEN_HEIGHT);
	ofRunApp(myapp);
	delete myapp;
	return 0;
}
