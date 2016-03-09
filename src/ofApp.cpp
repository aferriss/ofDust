#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    img.load("images/natural4.png");
    
    w = img.getWidth();
    h = img.getHeight();
    ofSetWindowShape(w, h);
    
    fbo.allocate(w, h, GL_RGB);
    screen.allocate(w, h, GL_RGB);
    ofSetFrameRate(30);
    shader.load("shaders/repos");
    
    save = false;
    
    pix = img.getPixels();
    
//    pickRandSpots(1000);
    yPos = 0;
    
    ofSetBackgroundAuto(false);
    
    fbo.begin();
        ofClear(0);
    fbo.end();
    
    inc = 1;
    
    recorder.setVideoBitrate("50000k");
    recorder.setVideoCodec("mpeg4");
    
    xPos = (int)ofRandom(w);
    yPos = (int)ofRandom(h);
    linePos = h/2;
    xInc = 1;
    yInc = 1;
    folder = ofGetTimestampString();
}
//--------------------------------------------------------------
void ofApp::update(){
    
//    for(int i = 0; i<spots.size(); i++){
//        pix[ spots[i]*3 ] = (pix[ spots[i] ] + 1) % 255;
//        pix[ spots[i]*3+1 ] = (pix[ spots[i]*3+1 ] + 1) % 255;
//        pix[ spots[i]*3+2 ] = (pix[ spots[i]*3+2 ] + 1) % 255;
//    }
//    
//    img.setFromPixels(pix);
    
    if(save){
        ofPixels savePix;
        screen.readToPixels(savePix);
        ofSaveImage(savePix, "saved/"+folder+"/"+ofToString(ofGetFrameNum())+".jpg");
//        recorder.addFrame(savePix);
        
//        save = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(ofGetFrameNum() <10){
        img.draw(0,0);
    }
    
    fbo.begin();
    
    ofSetColor(0,0,0,15);
    ofDrawRectangle(0, 0, w, h);
    
    ofSetColor(200,0,20);
    ofDrawRectangle(0, linePos, w, 1);
//    ofDrawCircle(xPos, yPos, 50);
    ofSetColor(255);

    fbo.end();
    
    xPos = (sin(ofGetFrameNum()*0.009)*0.5+0.5)*w;
    yPos = (cos(ofGetFrameNum()*0.005)*0.5+0.5)*h;
    
    linePos += yInc;
    
//    yPos = (yPos +1) % (int)img.getHeight();
//    if(yPos > img.getHeight()-10 || yPos< 0){
//        yInc *= -1;
//    }
//    
//    if(xPos > img.getWidth()-10 || xPos< 0){
//        xInc *= -1;
//    }
    
    if(linePos > img.getHeight()-10 || linePos < 10){
        yInc *= -1;
    }
    
    
    
    screen.begin();
        shader.begin();
            shader.setUniformTexture("tex0", fbo.getTexture(), 0);
            shader.setUniformTexture("tex1", img.getTexture(), 1);
        
            fbo.draw(0,0);
        
        shader.end();
    screen.end();
    
    screen.draw(0,0);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){
//        pickRandSpots( (int)ofRandom(5000));
        
//        recorder.setup("saved/"+ofGetTimestampString()+".mov", w, h, 30);
//        recorder.start();
        save = true;
    }
    
    if(key == 'i'){
        inc *= -1;
    }
}
//--------------------------------------------------------------
void ofApp::pickRandSpots(int spotCount){
    numSpots = (int)ofRandom(spotCount);
    spots.clear();
    
    for(int i = 0; i<numSpots; i++){
        int num = (int)ofRandom(img.getWidth() * img.getHeight());
        spots.push_back(num);
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::exit(){
//    recorder.close();
}
