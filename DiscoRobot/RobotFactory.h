#pragma once
#include "RobotPartsFactory.h"
#include "HierarchicalModel.h"
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
	RobotPartsFactory* _partsFactory;
	TransformationBuilder transformationBuilder;
	std::vector<HierarchicalModel*> wrappersTrackerList;
public:
	RobotFactory();
	RobotFactory(RobotPartsFactory& partsFactory);
	HierarchicalModel* createRobot();
	~RobotFactory();
};

