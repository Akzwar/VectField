#include "testApp.h"
#include <glut.h>
//--------------------------------------------------------------
void testApp::setup(){
    v_count=0;
    soundStream.listDevices();
    soundStream.setDeviceID(4);
    soundStream.setup(this,0,2,44100,255,4);
    audio_capturing=false;
    data=new float[255];
}

//--------------------------------------------------------------
void testApp::update(){
	myfft.powerSpectrum(0,(int)BUFFER_SIZE/2, data,BUFFER_SIZE,&magnitude[0],&phase[0],&power[0],&power_a[0]);
    p.recalc();
    p.nextstep();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0, 0, 20);
    glBegin(GL_POINTS);
        glColor3f(magnitude[5], magnitude[100], magnitude[50]);
        for(int i=0;i<COUNT;i++)
            glVertex2f(p.parts[i].x, p.parts[i].y);
    glEnd();
    glColor3f(200.0, 0.0, 0);
    string outstring="Number of Vects:"+ofToString(v_count,2);
    if(audio_capturing)
    outstring+="\nAudio is capturing...";
    for(int i=0;i<=255;i+=5)
    outstring+="\nmagnitude["+ofToString(i,2)+"]="+ofToString(magnitude[i], 2);
    ofDrawBitmapString(outstring, 10,10);
    for(int i=10;i<=128;i+=5)
    {
        glBegin(GL_QUADS);
            glVertex2f(10+i*2, 1000-magnitude[i]*100);
            glVertex2f(10+i*2+5, 1000-magnitude[i]*100);
            glVertex2f(10+i*2+5, 1000);
            glVertex2f(10+i*2, 1000);
        glEnd();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){//1=49
    //soundStream.setDeviceID(key-48);

    //soundStream.setup(this,0,2,44100,255,4);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
if(button==0)
{
    if(v_count<V_COUNT)
    {
        v_count++;
        p.V[v_count-1].x=x;
        p.V[v_count-1].y=y;
        p.V[v_count-1].r=200;
        p.V[v_count-1].Vect.x=-200;
        p.V[v_count-1].Vect.y=100;
    }
}
if(button==2)
{
    if(v_count>0)
    {
        p.V[v_count-1].x=x;
        p.V[v_count-1].y=y;
        p.V[v_count-1].r=200;
        p.V[v_count-1].Vect.x=0;
        p.V[v_count-1].Vect.y=0;
        v_count--;
    }
}
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}

//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){
for (int i = 0; i < bufferSize; i++){
		data[i] = input[i*2];
	}
	bufferCounter++;
    audio_capturing=true;
}
//--------------------------------------------------------------
void testApp::audioOut(float * input, int bufferSize, int nChannels){

}
