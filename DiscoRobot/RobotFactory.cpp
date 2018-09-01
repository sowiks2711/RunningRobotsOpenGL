#include "RobotFactory.h"



RobotFactory::RobotFactory()
{
	wrappersTrackerList.clear();
	elbowToForearm = transformationBuilder.translate(0, -1.8, 0).build();
	armToElbow = transformationBuilder.translate(0, -2.3, 0).build();
	hoopToArm = transformationBuilder.translate(0, -2.3, 0).build();
	chestToLeftHoop = transformationBuilder.translate(3, 2, 0).build();
	chestToRightHoop = transformationBuilder.translate(-3, 2, 0).build();
	rootToHead = transformationBuilder.translate(0, 4, 0).build();
	rootToLeftPan = transformationBuilder.translate(-1, -3.3, 0).build();
	rootToRightPan = transformationBuilder.translate(1, -3.3, 0).build();
	headToLeftEye = transformationBuilder.translate(-1, 0.5, -1.3).build();
	headToRightEye = transformationBuilder.translate(1, 0.5, -1.3).build();
	headToMouth = transformationBuilder.translate(0, -0.5, -1.3).build();
}

RobotFactory::RobotFactory(RobotPartsFactory & partsFactory):RobotFactory()
{
	_partsFactory = &partsFactory;
}

HierarchicalModel * RobotFactory::createRobot()
{
	SimpleModel* mouthPart = _partsFactory->createMouth();
	SimpleModel* leftFeetPart = _partsFactory->createFeet();
	SimpleModel* rightFeetPart = _partsFactory->createFeet();
	SimpleModel* leftEyePart = _partsFactory->createEye();
	SimpleModel* rightEyePart = _partsFactory->createEye();
	SimpleModel* chestPart = _partsFactory->createChest();
	SimpleModel* leftArmPart = _partsFactory->createLongLink();
	SimpleModel* rightArmPart = _partsFactory->createLongLink();
	SimpleModel* headPart = _partsFactory->createHead();
	SimpleModel* leftHoopPart = _partsFactory->createBearing();
	SimpleModel* rightHoopPart = _partsFactory->createBearing();
	SimpleModel* leftElbowPart = _partsFactory->createBearing();
	SimpleModel* rightElbowPart = _partsFactory->createBearing();
	SimpleModel* leftPanPart = _partsFactory->createBearing();
	SimpleModel* rightPanPart = _partsFactory->createBearing();
	SimpleModel* leftForearmPart = _partsFactory->createShortLink();
	SimpleModel* rightForearmPart = _partsFactory->createShortLink();
	SimpleModel* leftKneePart = _partsFactory->createBearing();
	SimpleModel* rightKneePart = _partsFactory->createBearing();
	SimpleModel* leftTightPart = _partsFactory->createLongLink();
	SimpleModel* rightTightPart = _partsFactory->createLongLink();
	SimpleModel* leftCalfPart = _partsFactory->createLongLink();
	SimpleModel* rightCalfPart = _partsFactory->createLongLink();

	HierarchicalModel* chest = new HierarchicalModel(chestPart);
	HierarchicalModel* leftCalf = new HierarchicalModel(leftCalfPart);
	HierarchicalModel* rightCalf = new HierarchicalModel(rightCalfPart);
	HierarchicalModel* leftKnee = new HierarchicalModel(leftKneePart);
	HierarchicalModel* rightKnee = new HierarchicalModel(rightKneePart);
	HierarchicalModel* leftTight = new HierarchicalModel(leftTightPart);
	HierarchicalModel* rightTight = new HierarchicalModel(rightTightPart);
	HierarchicalModel* leftPan = new HierarchicalModel(leftPanPart);
	HierarchicalModel* rightPan = new HierarchicalModel(rightPanPart);
	HierarchicalModel* leftForearm = new HierarchicalModel(leftForearmPart);
	HierarchicalModel* rightForearm = new HierarchicalModel(rightForearmPart);
	HierarchicalModel* leftHoop = new HierarchicalModel(leftHoopPart);
	HierarchicalModel* rightHoop = new HierarchicalModel(rightHoopPart);
	HierarchicalModel* leftArm = new HierarchicalModel(leftArmPart);
	HierarchicalModel* rightArm = new HierarchicalModel(rightArmPart);
	HierarchicalModel* leftElbow = new HierarchicalModel(leftElbowPart);
	HierarchicalModel* rightElbow = new HierarchicalModel(rightElbowPart);
	HierarchicalModel* head = new HierarchicalModel(headPart);
	HierarchicalModel* leftEye = new HierarchicalModel(leftEyePart);
	HierarchicalModel* rightEye = new HierarchicalModel(rightEyePart);
	HierarchicalModel* mouth = new HierarchicalModel(mouthPart);
	HierarchicalModel* leftFeet = new HierarchicalModel(leftFeetPart);
	HierarchicalModel* rightFeet = new HierarchicalModel(rightFeetPart);
	wrappersTrackerList.push_back(chest);
	wrappersTrackerList.push_back(leftCalf);
	wrappersTrackerList.push_back(rightCalf);
	wrappersTrackerList.push_back(leftKnee);
	wrappersTrackerList.push_back(rightKnee);
	wrappersTrackerList.push_back(leftTight);
	wrappersTrackerList.push_back(rightTight);
	wrappersTrackerList.push_back(leftPan);
	wrappersTrackerList.push_back(rightPan);
	wrappersTrackerList.push_back(leftForearm);
	wrappersTrackerList.push_back(rightForearm);
	wrappersTrackerList.push_back(leftHoop);
	wrappersTrackerList.push_back(rightHoop);
	wrappersTrackerList.push_back(leftArm);
	wrappersTrackerList.push_back(rightArm);
	wrappersTrackerList.push_back(leftElbow);
	wrappersTrackerList.push_back(rightElbow);
	wrappersTrackerList.push_back(head);
	wrappersTrackerList.push_back(leftEye);
	wrappersTrackerList.push_back(rightEye);
	wrappersTrackerList.push_back(mouth);
	wrappersTrackerList.push_back(leftFeet);
	wrappersTrackerList.push_back(rightFeet);

	leftElbow->addChild(*leftForearm, elbowToForearm);
	rightElbow->addChild(*rightForearm, elbowToForearm);
	leftArm->addChild(*leftElbow, armToElbow);
	rightArm->addChild(*rightElbow, armToElbow);
	leftHoop->addChild(*leftArm, hoopToArm);
	rightHoop->addChild(*rightArm, hoopToArm);
	chest->addChild(*leftHoop, chestToLeftHoop);
	chest->addChild(*rightHoop, chestToRightHoop);
	chest->addChild(*head, rootToHead);
	chest->addChild(*leftPan, rootToLeftPan);
	chest->addChild(*rightPan, rootToRightPan);
	leftPan->addChild(*leftTight, hoopToArm);
	rightPan->addChild(*rightTight, hoopToArm);
	leftTight->addChild(*leftKnee, armToElbow);
	rightTight->addChild(*rightKnee, armToElbow);
	leftKnee->addChild(*leftCalf, hoopToArm);
	rightKnee->addChild(*rightCalf, hoopToArm);
	leftCalf->addChild(*leftFeet, armToElbow);
	rightCalf->addChild(*rightFeet, armToElbow);
	head->addChild(*leftEye, headToLeftEye);
	head->addChild(*rightEye, headToRightEye);
	head->addChild(*mouth, headToMouth);

	return chest;
}

RobotFactory::~RobotFactory()
{
	for (HierarchicalModel* model : wrappersTrackerList)
		delete model;
}
