#include "RobotAnimator.h"



ArmRotators & RobotAnimator::getLeftArmRotators()
{
	return leftArmRotators;
}

ArmRotators & RobotAnimator::getRightArmRotators()
{
	return rightArmRotators;
}

LegRotators & RobotAnimator::getLeftLegRotators()
{
	return leftLegRotators;
}

LegRotators & RobotAnimator::getRightLegRotators()
{
	return rightLegRotators;
}

RobotAnimator::RobotAnimator()
{
	leftArmRotators.hoopRotation = new glm::mat4(1);
	leftArmRotators.elbowRotation = new glm::mat4(1);
	rightArmRotators.hoopRotation = new glm::mat4(1);
	rightArmRotators.elbowRotation = new glm::mat4(1);
	leftLegRotators.panRotation = new glm::mat4(1);
	leftLegRotators.kneeRotation = new glm::mat4(1);
	rightLegRotators.panRotation = new glm::mat4(1);
	rightLegRotators.kneeRotation = new glm::mat4(1);
	_transformationBuilder = new TransformationBuilder();
	_hoopStepMaker = new AnimationStepMaker();
	_hoopStepMaker->changeAnimationDirection();
	_elbowStepMaker = new AnimationStepMaker();
	_elbowStepMaker->changeAnimationDirection();
}

void RobotAnimator::makeAnimationStep()
{
	*(leftArmRotators.hoopRotation) = (*(leftArmRotators.hoopRotation))*_hoopStepMaker->getNextStep();
	*(leftArmRotators.elbowRotation) = (*(leftArmRotators.elbowRotation))*_elbowStepMaker->getNextStep();
}


RobotAnimator::~RobotAnimator()
{
	delete leftArmRotators.hoopRotation;
	delete leftArmRotators.elbowRotation;
	delete rightArmRotators.hoopRotation;
	delete rightArmRotators.elbowRotation;
	delete leftLegRotators.panRotation;
	delete leftLegRotators.kneeRotation;
	delete rightLegRotators.panRotation;
	delete rightLegRotators.kneeRotation;
	delete _hoopStepMaker;
	delete _elbowStepMaker;
}
