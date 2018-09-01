#include "RobotPartsFactory.h"



RobotPartsFactory::RobotPartsFactory()
{
	transformationBuilder = TransformationBuilder();
	cubeBuilder = new CubeModelBuilder();
	sfereBuilder = new SfereModelBuilder();

}

SimpleModel*  RobotPartsFactory::createChest()
{
	return &cubeBuilder->setDiffuse(0, 0.61, 0)
		.setEmission(0.1, 0, 0)
		.setShininess(400)
		.setSpecular(1, 1, 1)
		.setTransformation(
			transformationBuilder.scale(4,5,1).build()
		)
		.build();
}

SimpleModel * RobotPartsFactory::createHead()
{
	
	glm::mat4 headScaling = transformationBuilder
		.scale(0.10f, 0.08f, 0.08f)
		.build();

	return &sfereBuilder->setEmission(0.8, 0.1, 0.5)
		.setDiffuse(0.2, 0.41, 0.11)
		.setShininess(400)
		.setSpecular(1, 1, 1)
		.setTransformation(headScaling)
		.build();
}

SimpleModel * RobotPartsFactory::createBearing()
{
	return &sfereBuilder->setEmission(0, 0, 0.59)
		.setDiffuse(0, 0.01, 0.59)
		.setShininess(400)
		.setSpecular(1, 1, 1)
		.setTransformation(
			transformationBuilder.scale(0.04).build()
		)
		.build();
}

SimpleModel * RobotPartsFactory::createLongLink()
{
	return &cubeBuilder->setDiffuse(0, 0.61, 0)
		.setEmission(0.1, 0, 0)
		.setShininess(400)
		.setSpecular(1, 1, 1)
		.setTransformation(
			transformationBuilder.scale(1,3,1).build()
		)
		.build();
}

SimpleModel * RobotPartsFactory::createShortLink()
{
	return &cubeBuilder->setDiffuse(0, 0.61, 0)
		.setEmission(0.1, 0, 0)
		.setShininess(400)
		.setSpecular(1, 1, 1)
		.setTransformation(
			transformationBuilder.scale(1,2,1).build()
		)
		.build();
}

SimpleModel * RobotPartsFactory::createFeet()
{
	return &cubeBuilder->setDiffuse(0, 0.61, 0)
		.setEmission(0.1, 0, 0)
		.setShininess(400)
		.setSpecular(1, 1, 1)
		.setTransformation(
			transformationBuilder.scale(1,1,-2).build()
		)
		.build();
}

SimpleModel * RobotPartsFactory::createEye()
{
	return &sfereBuilder->setEmission(0.1, 0.1, 0.7)
		.setDiffuse(0.1, 0.11, 0.91)
		.setShininess(400)
		.setSpecular(0.1, 0.1, 1)
		.setTransformation(
			transformationBuilder.scale(0.02).build()
		)
		.build();
}

SimpleModel * RobotPartsFactory::createMouth()
{
	return &cubeBuilder->setDiffuse(1, 0.1, 0.1)
		.setEmission(0.1, 0, 0)
		.setShininess(400)
		.setSpecular(1, 1, 1)
		.setTransformation(
			transformationBuilder.scale(0.8,0.3,0.5).build()
		)
		.build();
}


RobotPartsFactory::~RobotPartsFactory()
{
	delete cubeBuilder;
	delete sfereBuilder;
}
