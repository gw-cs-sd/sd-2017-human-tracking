#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
<<<<<<< HEAD
#include <sstream>
#include "myPerson.h"

using namespace std;

/* Function declaration */
myPerson createRandomPerson();
string pointToString(myPoint);



int main() {

	/* Initialize random seed. Needs to happen in a method */
=======

using namespace std;


int main() {

	/* Iinitialize random seed. Needs to happen in a method */
>>>>>>> 89200231d664bd486c70963a59ef341cecbb976e
	srand(0);


	char separator = ' ';
	int countWidth = 15;
<<<<<<< HEAD
	int headWidth = 35;
	int shoulderWidth = 35;
	int handWidth = 35;
	int spineWidth = 35;
=======
	int headWidth = 25;
	int shoulderWidth = 25;
	int handWidth = 25;
	int spineWidth = 25;
>>>>>>> 89200231d664bd486c70963a59ef341cecbb976e



	ofstream outputFile;
<<<<<<< HEAD
	outputFile.open("example.txt"); //tells the stream to put things in exaample.txt
	
	outputFile << "\n";

	outputFile << "Beginning data output...";

	outputFile << "\n\n\n";
=======
	outputFile.open("example.txt");
	outputFile << "Hello world!!!\n";

	for (int i = 0; i < 10; i++) {
		outputFile << i << ", ";
	}
>>>>>>> 89200231d664bd486c70963a59ef341cecbb976e

	outputFile << "\n";

	int timeCounter = 0;

	outputFile << left << setw(countWidth) << setfill(separator) << "Time";
	outputFile << left << setw(headWidth) << setfill(separator) << "JOINT_HEAD";
	outputFile << left << setw(shoulderWidth) << setfill(separator) << "JOINT_SHOULDER_LEFT";
	outputFile << left << setw(shoulderWidth) << setfill(separator) << "JOINT_SHOULDER_RIGHT";
	outputFile << left << setw(handWidth) << setfill(separator) << "JOINT_HAND_LEFT";
	outputFile << left << setw(handWidth) << setfill(separator) << "JOINT_HAND_RIGHT";
	outputFile << left << setw(spineWidth) << setfill(separator) << "JOINT_SPINE_MID";
	outputFile << "\n";

	while (timeCounter < 100) {
<<<<<<< HEAD
		myPerson newPerson = createRandomPerson();

		outputFile << left << setw(countWidth) << setfill(separator) << timeCounter++;
		outputFile << left << setw(headWidth) << setfill(separator) << pointToString(newPerson.getHead());
		outputFile << left << setw(shoulderWidth) << setfill(separator) << pointToString(newPerson.getLeftShoulder());
		outputFile << left << setw(shoulderWidth) << setfill(separator) << pointToString(newPerson.getRightShoulder());
		outputFile << left << setw(handWidth) << setfill(separator) << pointToString(newPerson.getLeftHand());
		outputFile << left << setw(handWidth) << setfill(separator) << pointToString(newPerson.getRightHand());
		outputFile << left << setw(spineWidth) << setfill(separator) << pointToString(newPerson.getSpineMid());
=======
		outputFile << left << setw(countWidth) << setfill(separator) << timeCounter++;
		outputFile << left << setw(headWidth) << setfill(separator) << rand() % 100;;
		outputFile << left << setw(shoulderWidth) << setfill(separator) << rand() % 100;
		outputFile << left << setw(shoulderWidth) << setfill(separator) << rand() % 100;
		outputFile << left << setw(handWidth) << setfill(separator) << rand() % 100;
		outputFile << left << setw(handWidth) << setfill(separator) << rand() % 100;
		outputFile << left << setw(spineWidth) << setfill(separator) << rand() % 100;
>>>>>>> 89200231d664bd486c70963a59ef341cecbb976e
		outputFile << "\n";

	}

	/*outputFile << left << setw(nameWidth) << setfill(separator) << "Michael";
	outputFile << left << setw(nameWidth) << setfill(separator) << "Esposito";
	outputFile << "\n";
	outputFile << left << setw(nameWidth) << setfill(separator) << "Sean";
	outputFile << left << setw(nameWidth) << setfill(separator) << "Bird";*/


<<<<<<< HEAD
	outputFile.close();


}

myPerson createRandomPerson() {
	myPoint head      (rand() % 100, rand() % 100, rand() % 100);
	myPoint lShoulder (rand() % 100, rand() % 100, rand() % 100);
	myPoint rShoulder (rand() % 100, rand() % 100, rand() % 100);
	myPoint lHand     (rand() % 100, rand() % 100, rand() % 100);
	myPoint rHand     (rand() % 100, rand() % 100, rand() % 100);
	myPoint spineMid  (rand() % 100, rand() % 100, rand() % 100);
	myPerson newPerson(head, lShoulder, rShoulder, lHand, rHand, spineMid);
	return newPerson;

}

string pointToString(myPoint point) {
	stringstream ss;
	//ss << left << setprecision(2) << "(" << point.getWorldX() << ", " << point.getWorldY() << ", " << point.getWorldZ() << ")";
	ss << left << "(";
	ss << left << setprecision(2) << setw(5) << point.getWorldX();
	ss << left << ", ";
	ss << left << setprecision(2) << setw(5) << point.getWorldY();
	ss << left << ", ";
	ss << left << setprecision(2) << setw(5) << point.getWorldZ();
	ss << left << ")";

	return ss.str(); //converts stringStream to a string

} 
=======




	outputFile.close();


}
>>>>>>> 89200231d664bd486c70963a59ef341cecbb976e
