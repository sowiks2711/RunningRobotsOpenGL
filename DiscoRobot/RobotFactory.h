#pragma once
#include "RobotPartsFactory.h"
#include "RobotAnimator.h"
#include "HierarchicalModel.h"
#include "RobotModel.h"

class RobotFactory
{
	glm::mat4 elbowToForearm;
	glm::mat4 armToElbow;
	glm::mat4 hoopToArm;
	glm::mat4 chestToLeftHoop;
	glm::mat4 chestToRightHoop;
	glm::mat4 rootToHead;
	glm::mat4 rootToLeftPan;
	glm::mat4 rootToRightPan;
	glm::mat4 headToLeftEye;
	glm::mat4 headToRightEye;
	glm::mat4 headToMouth;
	glm::mat4 forearmToLeftFingerBase;
	glm::mat4 forearmToRightFingerBase;
	glm::mat4 leftFingerBaseToLeftFingerEnd;
	glm::mat4 rightFingerBaseToRightFingerEnd;
	RobotPartsFactory* _partsFactory;
	TransformationBuilder transformationBuilder;
	std::vector<HierarchicalModel*> wrappersTrackerList;
	std::vector<RobotModel*> robotTrackerList;
	std::vector<RobotAnimator*> animatorsTrackerList;
public:
	RobotFactory();
	RobotFactory(RobotPartsFactory& partsFactory);
	RobotModel* createRobot();
	HierarchicalModel* createHead();
	HierarchicalModel* createArm(ArmRotators& armRotators);
	HierarchicalModel* createLeg(LegRotators& legRotators);
	~RobotFactory();
};

