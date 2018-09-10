#include "RobotFactory.h"

RobotFactory::RobotFactory()
{
	wrappersTrackerList.clear();
	animatorsTrackerList.clear();
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

RobotModel* RobotFactory::createRobot()
{
	SimpleModel* chestPart = _partsFactory->createChest();
	RobotAnimator* animator = new RobotAnimator();

	animatorsTrackerList.push_back(animator);

	HierarchicalModel* chest = new HierarchicalModel(chestPart);
	HierarchicalModel* leftArm = createArm(animator->getLeftArmRotators());
	HierarchicalModel* rightArm = createArm(animator->getRightArmRotators());
	HierarchicalModel* head = createHead();
	HierarchicalModel* leftLeg = createLeg(animator->getLeftLegRotators());
	HierarchicalModel* rightLeg = createLeg(animator->getRightLegRotators());

	wrappersTrackerList.push_back(chest);

	chest->addChild(*leftArm, chestToLeftHoop);
	chest->addChild(*rightArm, chestToRightHoop);
	chest->addChild(*head, rootToHead);
	chest->addChild(*leftLeg, rootToLeftPan);
	chest->addChild(*rightLeg, rootToRightPan);

	RobotModel* robot = new RobotModel(chest, animator);
	robotTrackerList.push_back(robot);

	return robot;
}

HierarchicalModel * RobotFactory::createHead()
{
	SimpleModel* mouthPart = _partsFactory->createMouth();
	SimpleModel* headPart = _partsFactory->createHead();
	SimpleModel* leftEyePart = _partsFactory->createEye();
	SimpleModel* rightEyePart = _partsFactory->createEye();

	HierarchicalModel* head = new HierarchicalModel(headPart);
	HierarchicalModel* leftEye = new HierarchicalModel(leftEyePart);
	HierarchicalModel* rightEye = new HierarchicalModel(rightEyePart);
	HierarchicalModel* mouth = new HierarchicalModel(mouthPart);

	wrappersTrackerList.push_back(head);
	wrappersTrackerList.push_back(leftEye);
	wrappersTrackerList.push_back(rightEye);
	wrappersTrackerList.push_back(mouth);

	head->addChild(*leftEye, headToLeftEye);
	head->addChild(*rightEye, headToRightEye);
	head->addChild(*mouth, headToMouth);

	return head;
}

HierarchicalModel * RobotFactory::createArm(ArmRotators& armRotators)
{
	SimpleModel* armPart = _partsFactory->createLongLink();
	SimpleModel* hoopPart = _partsFactory->createBearing();
	SimpleModel* elbowPart = _partsFactory->createBearing();
	SimpleModel* forearmPart = _partsFactory->createShortLink();

	HierarchicalModel* forearm = new HierarchicalModel(forearmPart);
	HierarchicalModel* hoop = new HierarchicalModel(hoopPart);
	HierarchicalModel* arm = new HierarchicalModel(armPart);
	HierarchicalModel* elbow = new HierarchicalModel(elbowPart);

	wrappersTrackerList.push_back(forearm);
	wrappersTrackerList.push_back(hoop);
	wrappersTrackerList.push_back(arm);
	wrappersTrackerList.push_back(elbow);

	elbow->addChild(*forearm, elbowToForearm);
	arm->addChild(*elbow, armToElbow);
	hoop->addChild(*arm, hoopToArm);

	hoop->setAnimationMatrix(*armRotators.hoopRotation);
	elbow->setAnimationMatrix(*armRotators.elbowRotation);
	return hoop;
}

HierarchicalModel* RobotFactory::createLeg(LegRotators& legRotators)
{
	SimpleModel* feetPart = _partsFactory->createFeet();
	SimpleModel* panPart = _partsFactory->createBearing();
	SimpleModel* kneePart = _partsFactory->createBearing();
	SimpleModel* tightPart = _partsFactory->createLongLink();
	SimpleModel* calfPart = _partsFactory->createLongLink();

	HierarchicalModel* calf = new HierarchicalModel(calfPart);
	HierarchicalModel* knee = new HierarchicalModel(kneePart);
	HierarchicalModel* tight = new HierarchicalModel(tightPart);
	HierarchicalModel* pan = new HierarchicalModel(panPart);
	HierarchicalModel* feet = new HierarchicalModel(feetPart);

	wrappersTrackerList.push_back(calf);
	wrappersTrackerList.push_back(knee);
	wrappersTrackerList.push_back(tight);
	wrappersTrackerList.push_back(pan);
	wrappersTrackerList.push_back(feet);

	pan->addChild(*tight, hoopToArm);
	tight->addChild(*knee, armToElbow);
	knee->addChild(*calf, hoopToArm);
	calf->addChild(*feet, armToElbow);

	pan->setAnimationMatrix(*legRotators.panRotation);
	knee->setAnimationMatrix(*legRotators.kneeRotation);

	return pan;
}

RobotFactory::~RobotFactory()
{
	for (HierarchicalModel* model : wrappersTrackerList)
		delete model;
}
