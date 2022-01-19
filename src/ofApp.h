#pragma once

#include "ofMain.h"
#include <vector>
#include <string>
#include <fstream>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void loadData();

		ofTrueTypeFont font, font2, font3;
		ofRectangle btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9, btn10;
		string ofApp::wrapString(string text, int width);
		string text, date, ignore, countText;

		vector <string> tweet, day, holder1, holder2;
		ifstream data;
		int count = 0;

		void mousePressed(int x, int y, int button);
		
};

