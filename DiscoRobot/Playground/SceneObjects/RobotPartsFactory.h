#pragma once
#include "GL\glew.h"
#include "..\Transformation\TransformationBuilder.h"
#include "SimpleModel.h"
#include "CubeModelBuilder.h"
#include "SfereModelBuilder.h"

class RobotPartsFactory
{
	TransformationBuilder transformationBuilder;
	CubeModelBuilder* cubeBuilder;
	SfereModelBuilder* sfereBuilder;
	ModelBuilder* prepareGreenCubicPart();
	ModelBuilder* prepareRedBearingPart();
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
	SimpleModel* createFloorPart();
	SimpleModel* createFillarPart();
	SimpleModel* createFillarBearingPart();
	SimpleModel* createBlobPart();
	~RobotPartsFactory();
};

