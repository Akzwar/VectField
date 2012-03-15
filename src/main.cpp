#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"
#define SCREEN_WIDTH 1680
#define SCREEN_HEIGHT 1050

//========================================================================
int main( ){

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, SCREEN_WIDTH,SCREEN_HEIGHT, OF_WINDOW);
	testApp* myapp = new testApp(SCREEN_WIDTH,SCREEN_HEIGHT);
	ofRunApp(myapp);
	delete myapp;
	return 0;
}
