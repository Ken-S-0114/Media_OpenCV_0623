#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  inputImg.allocate(camWidth, camHeight);
  outputImg.allocate(camWidth, camHeight);
  inputOfImg.load("kanna.jpeg");
  src_img = ofxCv::toCv(inputOfImg);
  
  Mat grey_image;
  
  cvtColor(src_img, grey_image, CV_BGR2GRAY, 0);
  
  
  equalizeHist(grey_image, grey_image);
  
  string cascadeName = ofToDataPath("haarcascade_frontalface_default.xml");
  CascadeClassifier cascade;
  if((cascade.load(cascadeName))==NULL ){
    
    printf( "Cannot load classifier cascade\n" );
    return -1;
  }
  
  
  vector<cv::Rect> faces;
  cascade.detectMultiScale(
                           src_img, faces,
                           1.1,             // scale factor
                           3,               // minimum neighbors
                           0,               // flags
                           cv::Size(20, 20) // minimum size
                           );
  
  
  vector<cv::Rect>::const_iterator r;
  for(r = faces.begin(); r != faces.end(); r++ ){
    cv::Point center;
    int radius;
    center.x = saturate_cast<int>(r->x + r->width  *0.5);
    center.y = saturate_cast<int>(r->y + r->height *0.5);
    radius   = saturate_cast<int>((r->y + r->height) *0.5); // 半径
    circle(src_img, center, radius, cv::Scalar(80, 80, 255), 5, 8, 0);
  }
  
//  namedWindow("Result", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
//  imshow("Result", src_img);
//  waitKey(0);

//  ofxCv::toOf(grey_image, outputOfImg);
//  inputOfImg.update();

  ofxCv::toOf(src_img, outputOfImg);
  outputOfImg.update();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  inputOfImg.draw(0,10,camWidth/2, camHeight/2);
  outputOfImg.draw(camWidth/2, 10, camWidth/2, camHeight/2);
  
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
