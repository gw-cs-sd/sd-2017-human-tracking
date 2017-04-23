# Senior-Design

Automated Transport Vehicle

ATV will be able to follow a user through various terrain, over obstacles like curbs and stairs, and keep its cargo area safe and flat. An onboard computer will identify and follow a designated target within the field of view of the attached Intel Realsense R200 camera.

## What's in this repository?

The code that operates the RealSense R200 and the Arduino Mega are in this repository. All Realsense code is located int `Realsense\` while Arduino code is located in `Motors\`. The final RealSense project does have some Arduino code mixed in to enable it to communicate over the Serial connection.

## Current Progress

A lot of time went in to getting the PersonTracking module into working condition. We inherited a mostly functional code-base from Intel, but very little correct documentation regarding the internals. Through a large amount of trial and error, we got this module into working condition and have iteratively added features. 

So far we have accomplished:
* Gathering, processing and outputting joint information
* Gathering, processing, storing location data into location buffer
* Finished initialization phase where ATV learns about target user features and joints
* Fixed unreliable world measurements reported from the RealSense SDK
* Implemented Socket-based networking to debug the robot during operation
* Utilized 3 data inputs to figure out which person in FOV is the target user:
	* Joint data
	* Previous Locations
	* userID
* Finished data packaging and serial transmission to Arduino
* When target user leaves FOV, the image is divided into regions. ATV only attempts to find TU in the last-known region


## Joint Data

In case anyone would like to continue development using the RealSense person tracking module, check out our code. Despite what the SDK documentation says, only a few joints were confirmed working. We only use the head, shoulders, spine and center of mass in calculations. 

Realsense Joint |  Our Code
----------------|----------
JOINT_HEAD | JOINT_HEAD
JOINT_LEFT_SHOULDER | JOINT_SHOULDER_LEFT
JOINT_RIGHT_SHOULDER | JOINT_SHOULDER_RIGHT
JOINT_SPINE_MID | JOINT_SPINE_MID
from personModule | JOINT_CENTER_MASS


## Combining Visual C++, Arduino and DC motors

`RealSense/Projects/userIDMotorsSimple`
`Motors/readSerialMotorTest/`

Sample code for controlling motors based on what the RealSense R200 sees. 

Arduino is serially connected to the Windows computer, and instructions are sent in 1-byte increments. Requires an Arduino sketch to parse the bytes, also availble in this repo.

## To run the code

1. Ensure the RealSense is plugged into the Windows computer. 
2. Ensure the Arduino is also plugged into the Windows computer. 
3. Compile and run sketch on the Arduino. 
4. Compile and run the code on the Windows computer. 
5. Wait for initialization to finish.
6. ???
7. Profit



