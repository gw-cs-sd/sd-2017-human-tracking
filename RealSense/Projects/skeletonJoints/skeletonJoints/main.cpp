#include <Windows.h>
#include <WinUser.h>
#include "pxccapturemanager.h"
#include "pxcsensemanager.h"
#include "pxcmetadata.h"
#include "util_cmdline.h"
#include "util_render.h"
#include <conio.h>
#include "pxcpersontrackingmodule.h"
#include "pxcpersontrackingdata.h"
#include "pxcvideomodule.h"
#include "pxcpersontrackingconfiguration.h"
#include "pxcmetadata.h"
#include "service/pxcsessionservice.h"
#include <assert.h>
//#include "PersonTrackingFrameRateCalculator.h"
//#include "PersonTrackingRendererManager.h"
//#include "PersonTrackingRenderer2d.h"
//#include "PersonTrackingRenderer3d.h"
//#include "PersonTrackingProcessor.h"
//#include "PersonTrackingUtilities.h"
//#include "ProfileSetMap.h"
//#include "resource.h"

PXCSession *session = NULL;

//need this crap so it will compile...comes from extern variables in PersonTrackingProcessor.cpp
pxcCHAR fileName[1024] = { 0 };
HANDLE ghMutex;
volatile bool isStopped = false;

int main(int argc, WCHAR* argv[]) {
	/* Creates an instance of the PXCSenseManager */
	PXCSenseManager *pp = PXCSenseManager::CreateInstance();

	if (!pp) {
		wprintf_s(L"Unable to create the SenseManager\n");
		return 3;
	}

	/* Enables person tracking module */
	session = pp->QuerySession();
	pp->EnablePersonTracking();

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
		if (sts<PXC_STATUS_NO_ERROR) {
			/* Enable a single stream */
			pp->Close();
			pp->EnableStream(PXCCapture::STREAM_TYPE_DEPTH);
			sts = pp->Init();
			if (sts<PXC_STATUS_NO_ERROR) {
				pp->Close();
				pp->EnableStream(PXCCapture::STREAM_TYPE_COLOR);
				sts = pp->Init();
			}

			if (sts<PXC_STATUS_NO_ERROR) {
				wprintf_s(L"Failed to locate any video stream(s)\n");
				pp->Release();
				return sts;
			}
		}

		/* Enabling skeleton joint tracking */
		PXCPersonTrackingModule* personModule = pp->QueryPersonTracking();
		PXCPersonTrackingConfiguration* personTrackingConfig = personModule->QueryConfiguration();
	//	personTrackingConfig->SetTrackedAngles(PXCPersonTrackingConfiguration::TrackingAngles::TRACKING_ANGLES_ALL);
		personTrackingConfig->QueryTracking()->SetTrackingMode(PXCPersonTrackingConfiguration::TrackingConfiguration::TRACKING_MODE_INTERACTIVE);
		
		PXCPersonTrackingConfiguration::SkeletonJointsConfiguration* skeletonJoints = personTrackingConfig->QuerySkeletonJoints();
		skeletonJoints->Enable();
		printf("is jointTracking Enabled?: %d\n", skeletonJoints->IsEnabled());


		printf("Initializing stream...");
		/* Stream Data */
		while (true) {
			/* Waits until new frame is available and locks it for application processing */
			sts = pp->AcquireFrame(false);


			/* Render streams*/
		//	PXCCapture::Sample *sample = pp->QuerySample();
			PXCCapture::Sample *sample = pp->QueryPersonTrackingSample();

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
					printf("Number of people: %d\n", numPeople);
					PXCPersonTrackingData::Person* personData = personModule->QueryOutput()->QueryPersonData(PXCPersonTrackingData::ACCESS_ORDER_BY_ID, 0);
					assert(personData != NULL);
					PXCPersonTrackingData::PersonJoints* personJoints = personData->QuerySkeletonJoints();
					//numJoints = ptj->QueryNumJoints();
					pxcI32 numPoints = personJoints->QueryNumJoints();
					int n = numPoints;
					printf("numJoints: 0x%08x ", n);
					PXCPersonTrackingData::PersonJoints::SkeletonPoint* jointPoints = new PXCPersonTrackingData::PersonJoints::SkeletonPoint[6];
				//	printf("  Type: %d, confidenceImage:%d\n", jointPoints[0].jointType, jointPoints[0].confidenceImage);
					personJoints->QueryJoints(jointPoints);
					printf("  Type: %d, confidenceImage:%d x: %f y: %f\n", jointPoints[0].jointType, jointPoints[0].confidenceImage, jointPoints[0].image.x, jointPoints[0].image.y);
					delete[] jointPoints;
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
	return 0;
}