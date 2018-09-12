#include "RobotPartsFactory.h"



ModelBuilder*  RobotPartsFactory::prepareGreenCubicPart()
{
	return &cubeBuilder->setDiffuse(0x17 / 255., 0x7D / 255., 0x07 / 255.)
		.setEmission(0.1 * 0x17 / 255, 0.1 * 0x7D / 255, 0.1 * 0x07 / 255)
		.setShininess(400)
		.setSpecular(1, 1, 1);
}

ModelBuilder * RobotPartsFactory::prepareRedBearingPart()
{
	return &sfereBuilder->setEmission(0x93 / 255., 0x08 / 255., 0x12 / 255.)
		.setDiffuse(0x93 / 255., 0x08 / 255., 0x12 / 255.)
		.setShininess(400)
		.setSpecular(1, 1, 1);
}

RobotPartsFactory::RobotPartsFactory()
{
	transformationBuilder = TransformationBuilder();
	cubeBuilder = new CubeModelBuilder();
	sfereBuilder = new SfereModelBuilder();

}

SimpleModel*  RobotPartsFactory::createChest()
{
	return &prepareGreenCubicPart()
		->setTransformation(
			transformationBuilder.scale(4,5,1).build()
		)
		.build();
}

SimpleModel * RobotPartsFactory::createHead()
{
	
	glm::mat4 headScaling = transformationBuilder
		.scale(0.10f, 0.08f, 0.08f)
		.build();

	return &sfereBuilder
		->setEmission(0x97/255., 0x8A/255., 0x08/255)
		.setDiffuse(0x97/255., 0x8A/255., 0x08/255)
		.setShininess(400)
		.setSpecular(1, 1, 1)
		.setTransformation(headScaling)
		.build();
}

SimpleModel * RobotPartsFactory::createBearing()
{
	return &prepareRedBearingPart()
		->setTransformation(
			transformationBuilder.scale(0.04).build()
		)
		.build();
}

SimpleModel * RobotPartsFactory::createLongLink()
{
	return &prepareGreenCubicPart()
		->setTransformation(
			transformationBuilder.scale(1,3,1).build()
		)
		.build();
}

SimpleModel * RobotPartsFactory::createShortLink()
{
	return &prepareGreenCubicPart()
		->setTransformation(
			transformationBuilder.scale(1,2,1).build()
		)
		.build();
}

SimpleModel * RobotPartsFactory::createFinger()
{
	return &prepareGreenCubicPart()
		->setTransformation(
			transformationBuilder.scale(0.3,1.0,0.3).build()
		)
		.build();
}

SimpleModel * RobotPartsFactory::createFeet()
{
	return &prepareGreenCubicPart()
		->setTransformation(
			transformationBuilder.scale(1,1,-2).build()
		)
		.build();
}

SimpleModel * RobotPartsFactory::createEye()
{
	return &prepareRedBearingPart()
		->setTransformation(
			transformationBuilder.scale(0.02).build()
		)
		.build();
}

SimpleModel * RobotPartsFactory::createMouth()
{
	return &prepareGreenCubicPart()
		->setTransformation(
			transformationBuilder.scale(0.8,0.3,0.5).build()
		)
		.build();
}

SimpleModel * RobotPartsFactory::createFloorPart()
{
	return &cubeBuilder
		->setDiffuse(0x97/255., 0x8A/255., 0x08/255)
		.setEmission(0.1, 0, 0)
		.setShininess(100)
		.setSpecular(1, 1, 1)
		.setTransformation(
			transformationBuilder.scale(20,1,20).build()
		)
		.build();
}


RobotPartsFactory::~RobotPartsFactory()
{
	delete cubeBuilder;
	delete sfereBuilder;
}
