#include <Windows.h>
#include <WinUser.h>
#include "pxccapturemanager.h"
#include "pxcsensemanager.h"
#include "pxcmetadata.h"
#include "util_cmdline.h"
#include "util_render.h"
#include <conio.h> //for _getch
#include "pxcpersontrackingmodule.h"
#include "pxcpersontrackingdata.h"
#include "pxcvideomodule.h"
#include "pxcpersontrackingconfiguration.h"
#include "pxcmetadata.h"
#include "service/pxcsessionservice.h"
#include <assert.h>
#include "myPerson.h"
#include "myLogging.h"

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f
/* Required for ouputting data to file */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <sstream>

using namespace std;

<<<<<<< HEAD


=======
#define COUNT_WIDTH 15
#define COLUMN_WIDTH 35
<<<<<<< HEAD
#define VECTOR_WIDTH 6



=======



=======
>>>>>>> 89200231d664bd486c70963a59ef341cecbb976e
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f
PXCSession *session = NULL;

/* Variables needed to compile */
pxcCHAR fileName[1024] = { 0 };
HANDLE ghMutex;
volatile bool isStopped = false;

/* Global variables used in target identification */
myPerson targetUser;
bool isInitialized = false;
//vector<int> personList;
int numPeopleFound = -1;

/* Global variables for logging joint data */
//char separator = ' ';
<<<<<<< HEAD
=======
int timeCounter = 0;
ofstream jointLog;
ofstream torsoLog;
ofstream leftArmLog;
ofstream rightArmLog;


=======
<<<<<<< HEAD
/* Global variables for logging joint data */
char separator = ' ';
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f
int timeCounter = 0;
ofstream jointLog;
ofstream torsoLog;
ofstream leftArmLog;
ofstream rightArmLog;


<<<<<<< HEAD
=======
=======
>>>>>>> 89200231d664bd486c70963a59ef341cecbb976e
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f
/* Method declarations */
void initializeTargetUser(PXCPersonTrackingModule* personModule);
void comparePeopleInFOV(PXCPersonTrackingModule* personModule, int numPeople);
myPerson convertPXCPersonToMyPerson(PXCPersonTrackingData::Person* person);
void updateTargetUser(PXCPersonTrackingModule* personModule);
<<<<<<< HEAD
boolean isNewUser(PXCPersonTrackingModule *personModule);
=======
=======
<<<<<<< HEAD
myPerson convertPXCPersonToMyPerson(PXCPersonTrackingData::Person* person);

void createLogFile(string fileName);
string pointToString(myPoint point);
void printToLog(myPerson person);
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f


int main(int argc, WCHAR* argv[]) {
	/* Setting up log file */
	//createJointLogFile("pointLogs/pointLog14.txt");
	//createVectorLogFile("torsoLogs/torsoLog14.txt", "torso",torsoLog);
	//createVectorLogFile("leftArmLogs/leftArmLog14.txt", "leftArm",leftArmLog);
	//createVectorLogFile("rightArmLogs/rightArmLog14.txt", "rightArm",rightArmLog);
	//createVectorLogFile("zAxisLogs/zAxisLog3.txt", "zAxis", zAxisLog);
	
<<<<<<< HEAD
=======
=======
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685

void createJointLogFile(string fileName);
void createVectorLogFile(string fileName, string feature, ofstream& measurement);
string pointToString(myPoint point);
void printToJointLog(myPerson person);
void printToVectorLog(vector<double> vect,ofstream& measurement);


int main(int argc, WCHAR* argv[]) {
<<<<<<< HEAD
	/* Setting up log file */
	createJointLogFile("pointLogs/pointLog14.txt");
	createVectorLogFile("torsoLogs/torsoLog14.txt", "torso",torsoLog);
	createVectorLogFile("leftArmLogs/leftArmLog14.txt", "leftArm",leftArmLog);
	createVectorLogFile("rightArmLogs/rightArmLog14.txt", "rightArm",rightArmLog);
	//createVectorLogFile("zAxisLogs/zAxisLog3.txt", "zAxis", zAxisLog);
	
=======
>>>>>>> 89200231d664bd486c70963a59ef341cecbb976e
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f
	/* Creates an instance of the PXCSenseManager */
	PXCSenseManager *pp = PXCSenseManager::CreateInstance();

	if (!pp) {
		wprintf_s(L"Unable to create the SenseManager\n");
		return 3;
	}

	/* Initiates session */
=======
<<<<<<< HEAD
	/* Initiates session */
	session = pp->QuerySession();
	
	/* Configures coordinate sytem to work with OpenCV */
	session->SetCoordinateSystem(PXCSession::COORDINATE_SYSTEM_REAR_OPENCV);
	
	/* Enables person tracking module */
	pp->EnablePersonTracking();
	
	/* Checks if coodinate system successfull switched to OpenCV mode */
	PXCSession::CoordinateSystem cs = session->QueryCoordinateSystem();
	if (cs & PXCSession::COORDINATE_SYSTEM_REAR_OPENCV) {
		printf("OpenCV coordinate mode enabled...\n");
	}
	else {
		printf("OpenCV mode unsuccessful...\n");
	}

<<<<<<< HEAD
=======
=======
	/* Enables person tracking module */
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
	session = pp->QuerySession();
	
	/* Configures coordinate sytem to work with OpenCV */
	session->SetCoordinateSystem(PXCSession::COORDINATE_SYSTEM_REAR_OPENCV);
	
	/* Enables person tracking module */
	pp->EnablePersonTracking();
<<<<<<< HEAD
	
	/* Checks if coodinate system successfull switched to OpenCV mode */
	PXCSession::CoordinateSystem cs = session->QueryCoordinateSystem();
	if (cs & PXCSession::COORDINATE_SYSTEM_REAR_OPENCV) {
		printf("OpenCV coordinate mode enabled...\n");
	}
	else {
		printf("OpenCV mode unsuccessful...\n");
	}

=======
>>>>>>> 89200231d664bd486c70963a59ef341cecbb976e
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f

	/* Creates stream renders */
	UtilRender renderc(L"Color"), renderd(L"Depth");
	pxcStatus sts;

	/* Creates render windows */
	HWND colorWindow = renderc.m_hWnd;
	HWND depthWindow = renderc.m_hWnd;

	do {
		PXCVideoModule::DataDesc desc = {};
		desc.deviceInfo.streams = PXCCapture::STREAM_TYPE_COLOR | PXCCapture::STREAM_TYPE_DEPTH;
		pp->EnableStreams(&desc);

		/* Initializes the pipeline */
		sts = pp->Init();
		if (sts < PXC_STATUS_NO_ERROR) {
			/* Enable a single stream */
			pp->Close();
			pp->EnableStream(PXCCapture::STREAM_TYPE_DEPTH);
			sts = pp->Init();
			if (sts < PXC_STATUS_NO_ERROR) {
				pp->Close();
				pp->EnableStream(PXCCapture::STREAM_TYPE_COLOR);
				sts = pp->Init();
			}

			if (sts < PXC_STATUS_NO_ERROR) {
				wprintf_s(L"Failed to locate any video stream(s)\n");
				pp->Release();
				return sts;
			}
		}

		/* Enabling skeleton joint tracking */
		PXCPersonTrackingModule* personModule = pp->QueryPersonTracking();
		PXCPersonTrackingConfiguration* personTrackingConfig = personModule->QueryConfiguration();
		personTrackingConfig->QueryTracking()->SetTrackingMode(PXCPersonTrackingConfiguration::TrackingConfiguration::TRACKING_MODE_INTERACTIVE);

		PXCPersonTrackingConfiguration::SkeletonJointsConfiguration* skeletonJoints = personTrackingConfig->QuerySkeletonJoints();
		skeletonJoints->Enable();
		//printf("is jointTracking Enabled?: %d\n", skeletonJoints->IsEnabled());


		printf("Initializing stream...\n");
		/* Stream Data */
		while (true) {
			/* Waits until new frame is available and locks it for application processing */
			sts = pp->AcquireFrame(false);

			/* Render streams */
			PXCCapture::Sample *sample = pp->QuerySample();

			if (sample) {
				//printf("running");
				PXCPersonTrackingModule* personModule = pp->QueryPersonTracking();

				/* If no persons are visible, renders and releases current frame */
				if (personModule == NULL) {
					if (sample->depth && !renderd.RenderFrame(sample->depth)) break;
					if (sample->color && !renderc.RenderFrame(sample->color)) break;
					pp->ReleaseFrame();
					continue;
				}

				int numPeople = personModule->QueryOutput()->QueryNumberOfPeople();

				/* Found a person */
				if (numPeople != 0) {

					/* Initializing target user */
					if (isInitialized == false) {
						initializeTargetUser(personModule);
						//printf("Still initializing user...\n");
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
						//printf("Still initializing user...\n");
=======
>>>>>>> 89200231d664bd486c70963a59ef341cecbb976e
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f

					}
					/* Once target user initialized, update the torso height */
					else {
<<<<<<< HEAD
						updateTargetUser(personModule);
						if (isNewUser(personModule)) {
							/* Comparing people in FOV against target user */
							comparePeopleInFOV(personModule, numPeople);
=======
<<<<<<< HEAD
						updateTargetUser(personModule);
						printToVectorLog(targetUser.getTorsoVector(),torsoLog);
						printToVectorLog(targetUser.getLeftArmVector(),leftArmLog);
						printToVectorLog(targetUser.getRightArmVector(),rightArmLog);
						PXCPersonTrackingData::Person* personData = personModule->QueryOutput()->QueryPersonData(PXCPersonTrackingData::ACCESS_ORDER_BY_ID, 0);
						printToJointLog(convertPXCPersonToMyPerson(personData));


					}
					/* Comparing people in FOV against target user */
					/*else {
						//comparePeopleInFOV(personModule, numPeople);
						/* Person initialized, time to gather data 
						if (timeCounter < 500) {
							printf("timeCounter = %d", timeCounter);
							PXCPersonTrackingData::Person* personData = personModule->QueryOutput()->QueryPersonData(PXCPersonTrackingData::ACCESS_ORDER_BY_ID, 0);
							printToLog(convertPXCPersonToMyPerson(personData));
							//timeCounter++; it increases inside a convertPXCPersonToMyPerson
						}
					}*/
=======
<<<<<<< HEAD
						//comparePeopleInFOV(personModule, numPeople);
						/* Person initialized, time to gather data */
						if (timeCounter < 500) {
							printf("timeCounter = %d", timeCounter);
							PXCPersonTrackingData::Person* personData = personModule->QueryOutput()->QueryPersonData(PXCPersonTrackingData::ACCESS_ORDER_BY_ID, 0);
							printToLog(convertPXCPersonToMyPerson(personData));
							//timeCounter++; it increases inside a convertPXCPersonToMyPerson
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f
						}

<<<<<<< HEAD
						
						/* printing information to log files */
						//printToVectorLog(targetUser.getTorsoVector(),torsoLog);
						//printToVectorLog(targetUser.getLeftArmVector(),leftArmLog);
						//printToVectorLog(targetUser.getRightArmVector(),rightArmLog);
						PXCPersonTrackingData::Person* personData = personModule->QueryOutput()->QueryPersonData(PXCPersonTrackingData::ACCESS_ORDER_BY_ID, 0);
						//printToJointLog(convertPXCPersonToMyPerson(personData));


					}
=======
>>>>>>> 89200231d664bd486c70963a59ef341cecbb976e
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f
				}
			}


			/* Releases lock so pipeline can process next frame */
			pp->ReleaseFrame();

			if (_kbhit()) { // Break loop
				int c = _getch() & 255;
				if (c == 27 || c == 'q' || c == 'Q') break; // ESC|q|Q for Exit
			}

		}

	} while (sts == PXC_STATUS_STREAM_CONFIG_CHANGED);

	wprintf_s(L"Exiting\n");

	// Clean Up
	pp->Release();
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f
	jointLog.close();
	torsoLog.close();
	leftArmLog.close();
	rightArmLog.close();
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
	outputFile.close();
=======
>>>>>>> 89200231d664bd486c70963a59ef341cecbb976e
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f
	return 0;
}







/* We should average our tracked joints over 5 seconds or something, removing outliers (median calculated values),
initializing shouldn't occur in one frame*/
void initializeTargetUser(PXCPersonTrackingModule* personModule) {
	/* Accesses the only person in camera's FOV, our target user */
	PXCPersonTrackingData::Person* personData = personModule->QueryOutput()->QueryPersonData(PXCPersonTrackingData::ACCESS_ORDER_BY_ID, 0);
	assert(personData != NULL);

	/* Queries for skeleton joint data */
	PXCPersonTrackingData::PersonJoints* personJoints = personData->QuerySkeletonJoints();

	PXCPersonTrackingData::PersonJoints::SkeletonPoint* joints = new PXCPersonTrackingData::PersonJoints::SkeletonPoint[personJoints->QueryNumJoints()];
	personJoints->QueryJoints(joints);

	if (isJointInfoValid(joints) == false) {
		//printf("Invalid jointType data...\n");
	}
	/* Joint info is valid, initialize target user */
	else {
		printf("Initializing target user...\n");
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f
		myPoint leftHand      (joints[0].world.x, joints[0].world.y, joints[0].world.z, joints[0].image.x, joints[0].image.y);
		myPoint rightHand     (joints[1].world.x, joints[1].world.y, joints[1].world.z, joints[1].image.x, joints[1].image.y);
		myPoint head          (joints[2].world.x, joints[2].world.y, joints[2].world.z, joints[2].image.x, joints[2].image.y);
		myPoint shoulderLeft  (joints[4].world.x, joints[4].world.y, joints[4].world.z, joints[4].image.x, joints[4].image.y);
		myPoint shoulderRight (joints[5].world.x, joints[5].world.y, joints[5].world.z, joints[5].image.x, joints[5].image.y);
		myPoint spineMid      (joints[3].world.x, joints[3].world.y, joints[3].world.z, joints[3].image.x, joints[3].image.y);
		
		PXCPersonTrackingData::PersonTracking::PointCombined centerMass = personData->QueryTracking()->QueryCenterMass();
		myPoint myCenterMass(centerMass.world.point.x, centerMass.world.point.y, centerMass.world.point.z, centerMass.image.point.x, centerMass.image.point.y);
		
		targetUser.changeJoints(head, shoulderLeft, shoulderRight, leftHand, rightHand, spineMid, myCenterMass);
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
=======
		myPoint leftHand(joints[0].world.x, joints[0].world.y, joints[0].world.z, joints[0].image.x, joints[0].image.y);
		myPoint rightHand(joints[1].world.x, joints[1].world.y, joints[1].world.z, joints[1].image.x, joints[1].image.y);
		myPoint head(joints[2].world.x, joints[2].world.y, joints[2].world.z, joints[2].image.x, joints[2].image.y);
		myPoint shoulderLeft(joints[3].world.x, joints[3].world.y, joints[3].world.z, joints[3].image.x, joints[3].image.y);
		myPoint shoulderRight(joints[4].world.x, joints[4].world.y, joints[4].world.z, joints[4].image.x, joints[4].image.y);
		myPoint spineMid(joints[5].world.x, joints[5].world.y, joints[5].world.z, joints[5].image.x, joints[5].image.y);
		targetUser.updateJoints(head, shoulderLeft, shoulderRight, leftHand, rightHand, spineMid);
>>>>>>> 89200231d664bd486c70963a59ef341cecbb976e
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f
		targetUser.printPerson();
		isInitialized = true;
	}

	/* Frees up space allocated for joints array, it is not needed anymore */
	delete[] joints;
}


<<<<<<< HEAD
=======
	/* All tested issues passed, joint info is valid */
	return true;
}
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f

/* Iterates across all people in FOV, compares against target user */
void comparePeopleInFOV(PXCPersonTrackingModule* personModule, int numPeople) {

	/* Iterates across all people in FOV */
	for (int perIter = 0; perIter < numPeople; perIter++) {

		PXCPersonTrackingData::Person* personData = personModule->QueryOutput()->QueryPersonData(PXCPersonTrackingData::ACCESS_ORDER_BY_ID, perIter);
		assert(personData != NULL);
		PXCPersonTrackingData::PersonJoints* personJoints = personData->QuerySkeletonJoints();

		PXCPersonTrackingData::PersonJoints::SkeletonPoint* joints = new PXCPersonTrackingData::PersonJoints::SkeletonPoint[personJoints->QueryNumJoints()];
		personJoints->QueryJoints(joints);

		PXCPersonTrackingData::PersonTracking::PointCombined centerMass = personData->QueryTracking()->QueryCenterMass();
		myPoint myCenterMass(centerMass.world.point.x, centerMass.world.point.y, centerMass.world.point.z, centerMass.image.point.x, centerMass.image.point.y);

<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
		PXCPersonTrackingData::PersonTracking::PointCombined centerMass = personData->QueryTracking()->QueryCenterMass();
		myPoint myCenterMass(centerMass.world.point.x, centerMass.world.point.y, centerMass.world.point.z, centerMass.image.point.x, centerMass.image.point.y);

=======
>>>>>>> 89200231d664bd486c70963a59ef341cecbb976e
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f

		if (isJointInfoValid(joints) == false) {
			printf("Invalid joint data...no comparison\n");
		}
		else {
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f
			myPoint leftHand        (joints[0].world.x, joints[0].world.y, joints[0].world.z, joints[0].image.x, joints[0].image.y);
			myPoint rightHand       (joints[1].world.x, joints[1].world.y, joints[1].world.z, joints[1].image.x, joints[1].image.y);
			myPoint head            (joints[2].world.x, joints[2].world.y, joints[2].world.z, joints[2].image.x, joints[2].image.y);
			myPoint shoulderLeft    (joints[4].world.x, joints[4].world.y, joints[4].world.z, joints[4].image.x, joints[4].image.y);
			myPoint shoulderRight   (joints[5].world.x, joints[5].world.y, joints[5].world.z, joints[5].image.x, joints[5].image.y);
			myPoint spineMid        (joints[3].world.x, joints[3].world.y, joints[3].world.z, joints[3].image.x, joints[3].image.y);


			myPerson curr = myPerson(head, shoulderLeft, shoulderRight, leftHand, rightHand, spineMid, myCenterMass);
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
=======
			myPoint leftHand     (joints[0].world.x, joints[0].world.y, joints[0].world.z, joints[0].image.x, joints[0].image.y);
			myPoint rightHand    (joints[1].world.x, joints[1].world.y, joints[1].world.z, joints[1].image.x, joints[1].image.y);
			myPoint head         (joints[2].world.x, joints[2].world.y, joints[2].world.z, joints[2].image.x, joints[2].image.y);
			myPoint leftShoulder (joints[3].world.x, joints[3].world.y, joints[3].world.z, joints[3].image.x, joints[3].image.y);
			myPoint rightShoulder(joints[4].world.x, joints[4].world.y, joints[4].world.z, joints[4].image.x, joints[4].image.y);
			myPoint spineMid     (joints[5].world.x, joints[5].world.y, joints[5].world.z, joints[5].image.x, joints[5].image.y);
			myPerson curr = myPerson(head, leftShoulder, rightShoulder, leftHand, rightHand, spineMid);
>>>>>>> 89200231d664bd486c70963a59ef341cecbb976e
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f
			//curr.printPerson(); //can implement while testing
			double currConf = compareTorsoRatio(curr, targetUser); //confidence that current person is user
			printf("%d. Similarity = %.2f\n", perIter, currConf);

		}
	}
<<<<<<< HEAD
}

=======
<<<<<<< HEAD
}

void createJointLogFile(string string) {
	jointLog.open(string);

	jointLog << "\n";
	jointLog << "Beginning joint data output...";
	jointLog << "\n\n\n";

	jointLog << left << setw(COUNT_WIDTH) << setfill(separator) << "Time";
	jointLog << left << setw(COLUMN_WIDTH) << setfill(separator) << "JOINT_HEAD";
	jointLog << left << setw(COLUMN_WIDTH) << setfill(separator) << "JOINT_SHOULDER_LEFT";
	jointLog << left << setw(COLUMN_WIDTH) << setfill(separator) << "JOINT_SHOULDER_RIGHT";
	jointLog << left << setw(COLUMN_WIDTH) << setfill(separator) << "JOINT_HAND_LEFT";
	jointLog << left << setw(COLUMN_WIDTH) << setfill(separator) << "JOINT_HAND_RIGHT";
	jointLog << left << setw(COLUMN_WIDTH) << setfill(separator) << "JOINT_SPINE_MID";
	jointLog << left << setw(COLUMN_WIDTH) << setfill(separator) << "JOINT_CENTER_MASS";

	jointLog << "\n";
}

/* Creates the file to store our vector data */
void createVectorLogFile(string fileName, string featureType,ofstream& measurement) {
	measurement.open(fileName);
	measurement    << "\n";
	measurement    << "Beginning " << featureType << " data output...";
	measurement    << "\n\n\n";
}

/* Takes a myPerson as input, prints it to the joint log file */
void printToJointLog(myPerson newPerson) {
	jointLog << left << setw(COUNT_WIDTH) << setfill(separator) << timeCounter;
	jointLog << left << setw(COLUMN_WIDTH) << setfill(separator) << pointToString(newPerson.getHead());
	jointLog << left << setw(COLUMN_WIDTH) << setfill(separator) << pointToString(newPerson.getLeftShoulder());
	jointLog << left << setw(COLUMN_WIDTH) << setfill(separator) << pointToString(newPerson.getRightShoulder());
	jointLog << left << setw(COLUMN_WIDTH) << setfill(separator) << pointToString(newPerson.getLeftHand());
	jointLog << left << setw(COLUMN_WIDTH) << setfill(separator) << pointToString(newPerson.getRightHand());
	jointLog << left << setw(COLUMN_WIDTH) << setfill(separator) << pointToString(newPerson.getSpineMid());
	jointLog << left << setw(COLUMN_WIDTH) << setfill(separator) << pointToString(newPerson.getCenterMass());
	jointLog << "\n";
}

/* Prints the entire vector onto one line in the vector log file */
void printToVectorLog(vector<double> vect,ofstream& measurement) {
	
	measurement << "Unsorted: ";
	for (vector<double>::iterator it = vect.begin(); it != vect.end(); it++) {
		measurement << left << setprecision(4) << setw(VECTOR_WIDTH) << setfill(separator) << *it;
	}
	measurement << "\n";
	measurement << "Sorted:   ";
	sort(vect.begin(), vect.end());
	for (vector<double>::iterator it = vect.begin(); it != vect.end(); it++) {
		measurement << left << setprecision(4) << setw(VECTOR_WIDTH) << setfill(separator) << *it;
	}
	measurement << "\n median: ";
	measurement << findMedian(vect);
	measurement << "\n";


}



=======
<<<<<<< HEAD
}

void createLogFile(string string) {
	outputFile.open(string);

	outputFile << "\n";
	outputFile << "Beginning data output...";
	outputFile << "\n\n\n";

	outputFile << left << setw(COUNT_WIDTH) << setfill(separator) << "Time";
	outputFile << left << setw(COLUMN_WIDTH) << setfill(separator) << "JOINT_HEAD";
	outputFile << left << setw(COLUMN_WIDTH) << setfill(separator) << "JOINT_SHOULDER_LEFT";
	outputFile << left << setw(COLUMN_WIDTH) << setfill(separator) << "JOINT_SHOULDER_RIGHT";
	outputFile << left << setw(COLUMN_WIDTH) << setfill(separator) << "JOINT_HAND_LEFT";
	outputFile << left << setw(COLUMN_WIDTH) << setfill(separator) << "JOINT_HAND_RIGHT";
	outputFile << left << setw(COLUMN_WIDTH) << setfill(separator) << "JOINT_SPINE_MID";
	outputFile << left << setw(COLUMN_WIDTH) << setfill(separator) << "JOINT_CENTER_MASS";

	outputFile << "\n";
}

void printToLog(myPerson newPerson) {
	outputFile << left << setw(COUNT_WIDTH) << setfill(separator) << timeCounter;
	outputFile << left << setw(COLUMN_WIDTH) << setfill(separator) << pointToString(newPerson.getHead());
	outputFile << left << setw(COLUMN_WIDTH) << setfill(separator) << pointToString(newPerson.getLeftShoulder());
	outputFile << left << setw(COLUMN_WIDTH) << setfill(separator) << pointToString(newPerson.getRightShoulder());
	outputFile << left << setw(COLUMN_WIDTH) << setfill(separator) << pointToString(newPerson.getLeftHand());
	outputFile << left << setw(COLUMN_WIDTH) << setfill(separator) << pointToString(newPerson.getRightHand());
	outputFile << left << setw(COLUMN_WIDTH) << setfill(separator) << pointToString(newPerson.getSpineMid());
	outputFile << left << setw(COLUMN_WIDTH) << setfill(separator) << pointToString(newPerson.getCenterMass());
	outputFile << "\n";
}

>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
/* Returns x and y coordinates of images, z coordinate from world */
string pointToString(myPoint point) {
	point.printPoint();
	stringstream ss;

	ss << left << setprecision(5) << setw(5) << point.getImageX();
	ss << left << ", ";
	ss << left << setprecision(5) << setw(5) << point.getImageY();
	ss << left << ", ";
	ss << left << setprecision(5) << setw(5) << point.getWorldZ();
	return ss.str(); //converts stringStream to a string
}
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f

void updateTargetUser(PXCPersonTrackingModule* personModule) {
	//printf("Updating the target user...\n");
	/* Accesses the only person in camera's FOV, our target user */
	PXCPersonTrackingData::Person* personData = personModule->QueryOutput()->QueryPersonData(PXCPersonTrackingData::ACCESS_ORDER_BY_ID, 0);
	assert(personData != NULL);

	/* Queries for skeleton joint data */
	PXCPersonTrackingData::PersonJoints* personJoints = personData->QuerySkeletonJoints();

	PXCPersonTrackingData::PersonJoints::SkeletonPoint* joints = new PXCPersonTrackingData::PersonJoints::SkeletonPoint[personJoints->QueryNumJoints()];
	personJoints->QueryJoints(joints);
<<<<<<< HEAD
=======

	PXCPersonTrackingData::PersonTracking::PointCombined centerMass = personData->QueryTracking()->QueryCenterMass();
<<<<<<< HEAD
	myPoint myCenterMass(centerMass.world.point.x, centerMass.world.point.y, centerMass.world.point.z, centerMass.image.point.x, centerMass.image.point.y * 1000);
=======
	myPoint myCenterMass(centerMass.world.point.x, centerMass.world.point.y, centerMass.world.point.z, centerMass.image.point.x, centerMass.image.point.y);
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f
	
	if (isJointInfoValid(joints) == false) {
		//printf("Invalid jointType data...\n");
	}
	/* Joint info is valid, initialize target user */
	else {
		myPoint leftHand       (joints[0].world.x, joints[0].world.y, joints[0].world.z, joints[0].image.x, joints[0].image.y);
		myPoint rightHand      (joints[1].world.x, joints[1].world.y, joints[1].world.z, joints[1].image.x, joints[1].image.y);
		myPoint head           (joints[2].world.x, joints[2].world.y, joints[2].world.z, joints[2].image.x, joints[2].image.y);
		myPoint shoulderLeft   (joints[4].world.x, joints[4].world.y, joints[4].world.z, joints[4].image.x, joints[4].image.y);
		myPoint shoulderRight  (joints[5].world.x, joints[5].world.y, joints[5].world.z, joints[5].image.x, joints[5].image.y);
		myPoint spineMid       (joints[3].world.x, joints[3].world.y, joints[3].world.z, joints[3].image.x, joints[3].image.y);

		PXCPersonTrackingData::PersonTracking::PointCombined centerMass = personData->QueryTracking()->QueryCenterMass();
		myPoint myCenterMass(centerMass.world.point.x, centerMass.world.point.y, centerMass.world.point.z, centerMass.image.point.x, centerMass.image.point.y);

		targetUser.updatePerson(head, shoulderLeft, shoulderRight, leftHand, rightHand, spineMid, myCenterMass);
		//printf("median torsoHeight: %f\n", targetUser.getMedianTorsoHeight());
		//printf("median leftArmLength: %f\n", targetUser.getMedianLeftArmLength());
		//printf("median rightArmLength: %f\n", targetUser.getMedianRightArmLength());
	}


}
<<<<<<< HEAD


/* Determines if persons seen in the camera have been seen before */
boolean isNewUser(PXCPersonTrackingModule *personModule) {

	//PXCPersonTrackingData::Person* personData = personModule->QueryOutput()->QueryPersonData(PXCPersonTrackingData::ACCESS_ORDER_BY_ID, 0);

	int numPersons = personModule->QueryOutput()->QueryNumberOfPeople();
	//int numPersons = personModulepersonData->QueryNumberOfPeople(); //returns number of people

	for (int i = 0; i < numPersons; i++) {
		PXCPersonTrackingData::Person* personData = personModule->QueryOutput()->QueryPersonData(PXCPersonTrackingData::ACCESS_ORDER_BY_ID, i);

		/* Finds the unique ID of each user */
		int uniqueID = personData->QueryTracking()->QueryId();
		//printf("uniqueID = %d numPeople=%d", uniqueID, numPeopleFound);
		/* If assigned ID greater than numPeopleFound, person hasn't been seen before */
		if (uniqueID > numPeopleFound) {
			printf("New user found ID = %d\n", uniqueID);
			numPeopleFound++;
			return true;
		}
	}
	return false;
}
	
=======
<<<<<<< HEAD

void updateTargetUser(PXCPersonTrackingModule* personModule) {
	printf("Updating the target user...\n");
	/* Accesses the only person in camera's FOV, our target user */
	PXCPersonTrackingData::Person* personData = personModule->QueryOutput()->QueryPersonData(PXCPersonTrackingData::ACCESS_ORDER_BY_ID, 0);
	assert(personData != NULL);

	/* Queries for skeleton joint data */
	PXCPersonTrackingData::PersonJoints* personJoints = personData->QuerySkeletonJoints();

	PXCPersonTrackingData::PersonJoints::SkeletonPoint* joints = new PXCPersonTrackingData::PersonJoints::SkeletonPoint[personJoints->QueryNumJoints()];
	personJoints->QueryJoints(joints);
	
	if (isJointInfoValid(joints) == false) {
		//printf("Invalid jointType data...\n");
	}
	/* Joint info is valid, initialize target user */
	else {
		myPoint leftHand       (joints[0].world.x, joints[0].world.y, joints[0].world.z, joints[0].image.x, joints[0].image.y);
		myPoint rightHand      (joints[1].world.x, joints[1].world.y, joints[1].world.z, joints[1].image.x, joints[1].image.y);
		myPoint head           (joints[2].world.x, joints[2].world.y, joints[2].world.z, joints[2].image.x, joints[2].image.y);
		myPoint shoulderLeft   (joints[4].world.x, joints[4].world.y, joints[4].world.z, joints[4].image.x, joints[4].image.y);
		myPoint shoulderRight  (joints[5].world.x, joints[5].world.y, joints[5].world.z, joints[5].image.x, joints[5].image.y);
		myPoint spineMid       (joints[3].world.x, joints[3].world.y, joints[3].world.z, joints[3].image.x, joints[3].image.y);

		PXCPersonTrackingData::PersonTracking::PointCombined centerMass = personData->QueryTracking()->QueryCenterMass();
		myPoint myCenterMass(centerMass.world.point.x, centerMass.world.point.y, centerMass.world.point.z, centerMass.image.point.x, centerMass.image.point.y);

		targetUser.updatePerson(head, shoulderLeft, shoulderRight, leftHand, rightHand, spineMid, myCenterMass);
		//printf("median torsoHeight: %f\n", targetUser.getMedianTorsoHeight());
		//printf("median leftArmLength: %f\n", targetUser.getMedianLeftArmLength());
		//printf("median rightArmLength: %f\n", targetUser.getMedianRightArmLength());
	}


}
=======
=======
}
>>>>>>> 89200231d664bd486c70963a59ef341cecbb976e
>>>>>>> c61d20a7a317b00e9ed3321e57ad78b80249b685
>>>>>>> 6290029ecbffa7d05b69862bffc0e37afe94df8f
