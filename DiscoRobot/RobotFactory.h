#pragma once
#include "RobotPartsFactory.h"
#include "HierarchicalModel.h"
class RobotFactory
{
	RobotPartsFactory* _partsFactory;
	TransformationBuilder transformationBuilder;
	std::vector<HierarchicalModel*> wrappersTrackerList;
public:
	RobotFactory();
	RobotFactory(RobotPartsFactory& partsFactory);
	HierarchicalModel* createRobot();
	~RobotFactory();
};

