#pragma once
#include "GL\glew.h"
#include "Playground\TransformationBuilder.h"
#include "SimpleModel.h"
#include "Playground\CubeModelBuilder.h"
#include "Playground\SfereModelBuilder.h"

class RobotPartsFactory
{
	TransformationBuilder transformationBuilder;
	CubeModelBuilder* cubeBuilder;
	SfereModelBuilder* sfereBuilder;
public:
	RobotPartsFactory();
	SimpleModel* createChest();
	SimpleModel* createHead();
	SimpleModel* createBearing();
	SimpleModel* createLongLink();
	SimpleModel* createShortLink();
	SimpleModel* createFinger();
	SimpleModel* createFeet();
	SimpleModel* createEye();
	SimpleModel* createMouth();
	~RobotPartsFactory();
};

