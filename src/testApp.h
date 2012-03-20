#pragma once

#include "ofMain.h"
#include "particles.h"
#include "fft.h"
#define BUFFER_SIZE 1024
class testApp : public ofBaseApp{

	public:
        ~testApp()
        {
            delete [] data;
            delete soundStream;
        }
        bool Exit;
        ofImage one;
        ofMesh mesh;
        ofColor tmpcolor;
        bool pictavail;
        bool isdots;
        bool isdrawim;
        string outstring;
        testApp(int w, int h){Exit=false;p=particles(w,h);}
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

        ofSoundStream* soundStream;

};
//10-290Hz
//15-430Hz
//20-570Hz
