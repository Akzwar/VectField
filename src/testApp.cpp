#include "testApp.h"
#include <glut.h>
//--------------------------------------------------------------
void testApp::setup(){
    data=new float[BUFFER_SIZE];
    soundStream=new ofSoundStream();
    v_count=0;
    soundStream->listDevices();
    soundStream->setDeviceID(0);
    soundStream->setup(this,0,1,48000,BUFFER_SIZE,4);
    audio_capturing=false;
    one.loadImage("0.png");
    pictavail=false;
    isdots=false;
    isdrawim=false;
}

//--------------------------------------------------------------
void testApp::update(){
	myfft.powerSpectrum(0,(int)BUFFER_SIZE/2, data,BUFFER_SIZE,&magnitude[0],&phase[0],&power[0],&power_a[0]);
    p.recalc();
    p.nextstep();
    for(int i=0;i<v_count;i++)
        {p.V[v_count-1].Vect.x=magnitude[7];//7
        p.V[v_count-1].Vect.y=magnitude[13];}//20
        if(isdrawim&&pictavail)
        {
            one.reloadTexture();

            mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);

            mesh.addVertex(ofVec2f(0, 0));
            mesh.addVertex(ofVec2f(0, 1050));
            mesh.addVertex(ofVec2f(1680, 1050));
            mesh.addVertex(ofVec2f(1680, 0));
            mesh.addVertex(ofVec2f(0, 0));

            mesh.addTexCoord(ofVec2f(0, 0));
            mesh.addTexCoord(ofVec2f(0, 1050));
            mesh.addTexCoord(ofVec2f(1680, 1050));
            mesh.addTexCoord(ofVec2f(1680, 0));
            mesh.addTexCoord(ofVec2f(0, 0));
        }
    /**/
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0, 0, 20);
	if(isdrawim&&pictavail)
	{
        glColor3f(1.0,1.0,1.0);
        one.reloadTexture();
        one.bind();
        mesh.draw();
        one.unbind();
	}

    if(!isdots)
    glBegin(GL_QUADS);
    else
    glBegin(GL_POINTS);
       // glColor3f(magnitude[5], magnitude[100], magnitude[50]);
        for(int i=0;i<COUNT;i++)
        {
            if(pictavail)
                if((p.parts[i].x>0)&&
                    (p.parts[i].x<one.getWidth())&&
                    (p.parts[i].y>0)&&
                    (p.parts[i].y<one.getHeight())
                  )
                  {
                    tmpcolor=one.getColor(p.parts[i].x,p.parts[i].y);
                    ofSetColor(tmpcolor);
                  }
            if(!pictavail)
            {
                if(dist(p.parts[i].x-p.V[0].x,p.parts[i].y-p.V[0].y)>512)
                    glColor3f(0.0,0.0,0.1);
                else
                    glColor3f(magnitude[10]-dist(p.parts[i].x-p.V[0].x,p.parts[i].y-p.V[0].y)/512, magnitude[100]-dist(p.parts[i].x-p.V[0].x,p.parts[i].y-p.V[0].y)/512, magnitude[50]-dist(p.parts[i].x-p.V[0].x,p.parts[i].y-p.V[0].y)/512);
            }
            if(!isdots)
            {
                glVertex2f(p.parts[i].x-2, p.parts[i].y-2);
                glVertex2f(p.parts[i].x+2, p.parts[i].y-2);
                glVertex2f(p.parts[i].x+2, p.parts[i].y+2);
                glVertex2f(p.parts[i].x-2, p.parts[i].y+2);
            }
            else
            glVertex2f(p.parts[i].x, p.parts[i].y);

        }

    glEnd();
    glColor3f(200.0, 0.0, 0);
    outstring="";
    outstring+="FPS:"+ofToString(ofGetFrameRate(), 2)+"\n";
    outstring+="m[7]:"+ofToString(magnitude[7])+"\n";
    //for(int i=0;i<BUFFER_SIZE;i+=10)
    //outstring+="m["+ofToString(i)+"]:"+ofToString(magnitude[i])+"\n";
    ofDrawBitmapString(outstring,10,10);
    //if(audio_capturing)
    //for(int i=0;i<=255;i+=5)
    //outstring+="\nmagnitude["+ofToString(i,2)+"]="+ofToString(magnitude[i], 2);
       /* glBegin(GL_QUADS);
        for(int i=5;i<BUFFER_SIZE;i+=5)
        {
                glVertex2f(200+i*2, 900-magnitude[i]*100);
                glVertex2f(200+i*2+5, 900-magnitude[i]*100);
                glVertex2f(200+i*2+5, 900);
                glVertex2f(200+i*2,  900);
        }
        glEnd();*/
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key==OF_KEY_UP)
        pictavail=true;
    if(key==OF_KEY_DOWN)
        pictavail=false;
    if(key==OF_KEY_LEFT)
        isdots=true;
    if(key==OF_KEY_RIGHT)
        isdots=false;
    if(key==OF_KEY_F1)
        if(isdrawim)
        isdrawim=false;
        else
        isdrawim=true;

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
        p.V[v_count-1].Vect.x=magnitude[50]*100-200;
        p.V[v_count-1].Vect.y=magnitude[10]*100-200;
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
		data[i] = input[i];
	}
	//printf("%d",bufferSize);
	bufferCounter++;
    audio_capturing=true;
}
//--------------------------------------------------------------
void testApp::audioOut(float * input, int bufferSize, int nChannels){

}
