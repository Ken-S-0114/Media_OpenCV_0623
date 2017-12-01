#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"

using namespace cv;

#define camWidth  380
#define camHeight 380

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
  
  ofImage inputOfImg, outputOfImg, outputOfImg2, outputOfImg3;
  
  ofxCvColorImage inputImg,
  outputImg,
  outputImg2,
  outputImg3,
  grayImage;
  
  cv::Mat src_img, dst_img, input_img, output_img;
		
};
