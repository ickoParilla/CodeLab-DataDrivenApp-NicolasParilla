#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundColor(151, 195, 229); // Sets background color
	font.load("Montserrat-ExtraBold.ttf", 32); // Loads Font in bin Folder
	font2.load("Montserrat-Regular.ttf", 20); // Loads Font in bin Folder
	font3.load("Montserrat-Regular.ttf", 10); // Loads Font in bin Folder

	btn1.set(20, 100, 200, 65); // Sets button location
	btn2.set(20, 165, 200, 65); // Sets button location
	btn3.set(20, 230, 200, 65); // Sets button location
	btn4.set(20, 295, 200, 65); // Sets button location
	btn5.set(20, 360, 200, 65); // Sets button location
	btn6.set(20, 425, 200, 65); // Sets button location
	btn7.set(20, 490, 200, 65); // Sets button location
	btn8.set(20, 555, 200, 65); // Sets button location
	btn9.set(20, 620, 200, 65); // Sets button location
	btn10.set(20, 685, 200, 65); // Sets button location

	loadData();

}

void ofApp::loadData() { // takes data from cvs and puts in vectors
	data.open(ofToDataPath("sampleTweets.csv"));

	if (data.is_open()) {
		while (!data.eof()) {
			getline(data, date, ',');
			getline(data, ignore, 'b');
			getline(data, text);
			holder1.push_back(date);
			holder2.push_back(text);
			tweet.push_back(text);
			day.push_back(date);

		}
		holder1.erase(holder1.begin());
		holder2.erase(holder2.begin());
		date.erase(date.begin());
		text.erase(text.begin());

		data.close();
	}
	else {
		cout << "Fail" << endl;
	}


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(0); // Sets color to black
	font.drawString("Twitter", 40, 50);
	font.drawString("Innit", 110, 80);
	ofDrawRectRounded(250, 25, 1650, 1050, 15);
	ofDrawRectRounded(20, 100, 200, 650, 15);
	ofDrawRectRounded(20, 800, 200, 200, 15);


	ofSetColor(255); // Sets color to white
	font.drawString("Twitter", 35, 45);
	font.drawString("Innit", 105, 75);
	ofDrawRectRounded(245, 20, 1650, 1050, 15);
	ofDrawRectRounded(15, 95, 200, 650, 15);
	ofDrawRectRounded(15, 795, 200, 200, 15);


	ofSetColor(0); // Sets color to black
	font2.drawString("Count Total", 35, 140);
	font2.drawString("Count Money", 30, 205);
	font2.drawString("Count Politics", 25, 270);
	font2.drawString("Paris", 80, 335);
	font2.drawString("DreamWorks", 30, 400);
	font2.drawString("Uber", 80, 465);
	font2.drawString("Shrek", 75, 530);
	font2.drawString("Juice", 80, 595);
	font2.drawString("Burger", 70, 660);
	font2.drawString("Cool", 85, 725);

	font2.drawString(countText, 40, 850);
	font2.drawString(ofToString(count), 50, 900);


	ofSetColor(0, 0, 0, 0); // Sets opacity to 0
	ofDrawRectangle(btn1); // Adds button
	ofDrawRectangle(btn2); // Adds button
	ofDrawRectangle(btn3); // Adds button
	ofDrawRectangle(btn4); // Adds button
	ofDrawRectangle(btn5); // Adds button
	ofDrawRectangle(btn6); // Adds button
	ofDrawRectangle(btn7); // Adds button
	ofDrawRectangle(btn8); // Adds button
	ofDrawRectangle(btn9); // Adds button
	ofDrawRectangle(btn10); // Adds button

	ofSetColor(0);
	int j = 40, k = 40;
	int counter1 = 0, counter2 = 0;

	for (string s : holder1) { // Prints date data in cvs from vector
		s = wrapString(s, 500);
		font3.drawString(s, 260, k);
		k += 50;
		if (counter1 == 100) {
			break;
		}
		counter1++;
	}

	for (string t : holder2) { // Prints tweet data in cvs from vector
		t = wrapString(t, 1800);
		font3.drawString(t, 370, j);
		j += 50;
		if (counter2 == 100) {
			break;
		}
		counter2++;
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
	if (btn1.inside(x, y)) {
		cout << "Button 1 Clicked" << endl;
		count = 0; // Sets count to 0
		countText = "Total"; // Sets countText to "Total"

		for (int i = 0; i < tweet.size(); i++) { // Counts Total lines in cvs
			string str1 = tweet[i];
			count++;

		}
	}

	if (btn2.inside(x, y)) {
		cout << "Button 2 Clicked" << endl;
		count = 0; // Sets count to 0
		countText = "Money Total"; // Sets countText to "Money Total"

		for (int i = 0; i < tweet.size(); i++) { // Counts how many time "Money" appears in cvs
			string str1 = tweet[i];

			if (str1.find("money") != string::npos) {
				count++;
			}

		}
	}

	if (btn3.inside(x, y)) {
		cout << "Button 3 Clicked" << endl;
		count = 0; // Sets count to 0
		countText = "Politics Total"; // Sets countText to "Politics Total"
		for (int i = 0; i < tweet.size(); i++) { // Counts how many time "Politics" appears in cvs
			string str1 = tweet[i];

			if (str1.find("politics") != string::npos) {
				count++;
			}
		}
	}

	if (btn4.inside(x, y)) {
		cout << "Button 4 Clicked" << endl;
		holder1.clear(); // Clears Data
		holder2.clear(); // Clears Data

		for (int i = 0; i < tweet.size(); i++) {
			string str1 = tweet[i];

			if (str1.find("Paris") != string::npos) { // If current string has "Paris" will push back both date and tweet
				holder1.push_back(day[i]);
				holder2.push_back(tweet[i]);
				count++;
			}

		}
	}

	if (btn5.inside(x, y)) {
		cout << "Button 5 Clicked" << endl;
		holder1.clear(); // Clears Data
		holder2.clear(); // Clears Data

		for (int i = 0; i < tweet.size(); i++) {
			string str1 = tweet[i];

			if (str1.find("DreamWorks") != string::npos) { // If current string has "DreamWorks" will push back both date and tweet
				holder1.push_back(day[i]);
				holder2.push_back(tweet[i]);
				count++;
			}

		}
	}

	if (btn6.inside(x, y)) {
		cout << "Button 6 Clicked" << endl;
		holder1.clear(); // Clears Data
		holder2.clear(); // Clears Data

		for (int i = 0; i < tweet.size(); i++) {
			string str1 = tweet[i];

			if (str1.find("Uber") != string::npos) { // If current string has "Uber" will push back both date and tweet
				holder1.push_back(day[i]);
				holder2.push_back(tweet[i]);
				count++;
			}

		}
	}

	if (btn7.inside(x, y)) {
		cout << "Button 7 Clicked" << endl;
		holder1.clear(); // Clears Data
		holder2.clear(); // Clears Data

		for (int i = 0; i < tweet.size(); i++) { // If current string has "Shrek" will push back both date and tweet
			string str1 = tweet[i];

			if (str1.find("Shrek") != string::npos) {
				holder1.push_back(day[i]);
				holder2.push_back(tweet[i]);
				count++;
			}

		}
	}

	if (btn8.inside(x, y)) {
		cout << "Button 8 Clicked" << endl;
		holder1.clear(); // Clears Data
		holder2.clear(); // Clears Data

		for (int i = 0; i < tweet.size(); i++) { // If current string has "Juice" will push back both date and tweet
			string str1 = tweet[i];

			if (str1.find("Juice") != string::npos) {
				holder1.push_back(day[i]);
				holder2.push_back(tweet[i]);
				count++;
			}

		}
	}

	if (btn9.inside(x, y)) {
		cout << "Button 9 Clicked" << endl;
		holder1.clear(); // Clears Data
		holder2.clear(); // Clears Data

		for (int i = 0; i < tweet.size(); i++) { // If current string has "Burger" will push back both date and tweet
			string str1 = tweet[i];

			if (str1.find("Burger") != string::npos) {
				holder1.push_back(day[i]);
				holder2.push_back(tweet[i]);
				count++;
			}

		}
	}

	if (btn10.inside(x, y)) {
		cout << "Button 10 Clicked" << endl;
		holder1.clear(); // Clears Data
		holder2.clear(); // Clears Data

		for (int i = 0; i < tweet.size(); i++) { // If current string has "Cool" will push back both date and tweet
			string str1 = tweet[i];

			if (str1.find("Cool") != string::npos) {
				holder1.push_back(day[i]);
				holder2.push_back(tweet[i]);
				count++;
			}

		}
	}
}

string ofApp::wrapString(string text, int width) {
	string typeWrapped = "";
	string tempString = "";
	vector <string> words = ofSplitString(text, " ");

	for (int i = 0; i < words.size(); i++) { 
		string wrd = words[i]; // Gets data for wrd

		if (i > 0) { // Adds a space after every word
			tempString += " ";
		}
		tempString += wrd; //Adds current word in wrd to temp string

		int stringwidth = font.stringWidth(tempString); // Sets string width to match length of sentence

		if (stringwidth >= width) {//check string with to add either space or new line before current word
			typeWrapped += "\n"; //if line is now longer than desired width add a new line
			tempString = wrd; // make sure we're including the extra word on the next line
		}
		else if (i > 0) {
			typeWrapped += " "; // Adds space
		}
		typeWrapped += wrd; // Adds current word to string to be returned with new lines for wrapping
	}

	return typeWrapped;

}