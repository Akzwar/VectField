#pragma once

#include "ofMain.h"
#include "particles.h"
#include "fft.h"
#define BUFFER_SIZE 256
class testApp : public ofBaseApp{

	public:
        ~testApp(){delete [] data;}
        bool Exit;
		int x;
		int y;
        testApp(int w, int h){Exit=false;x=300;y=300;p=particles(w,h);}
		void setup();
		void update();
		void draw();
        void audioIn(float * input, int bufferSize, int nChannels );
        void audioOut(float * input, int bufferSize, int nChannels );
		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        particles p;
        int v_count;
		int bufferCounter;
        fft myfft;
        bool audio_capturing;
        float *data;
        float magnitude[BUFFER_SIZE];
        float power[BUFFER_SIZE];
        float power_a[BUFFER_SIZE];
        float phase[BUFFER_SIZE];

        ofSoundStream soundStream;

};
