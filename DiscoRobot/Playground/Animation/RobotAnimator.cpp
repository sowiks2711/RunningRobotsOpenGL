#include "RobotAnimator.h"



ArmRotators& RobotAnimator::getLeftArmRotators()
{
	return leftArmRotators;
}
ArmRotators& RobotAnimator::getRightArmRotators()
{
	return rightArmRotators;
}

LegRotators& RobotAnimator::getLeftLegRotators()
{
	return leftLegRotators;
}

LegRotators& RobotAnimator::getRightLegRotators()
{
	return rightLegRotators;
}

glm::mat4& RobotAnimator::getRootTransformation()
{
	return *rootTransformation;
}

void RobotAnimator::setInitialTransformation(glm::mat4& transformation)
{
	rootTransformation = &transformation;
}

void RobotAnimator::addWalkingAnimation()
{
	animations.push_back(
		new WalkingAnimation(leftArmRotators, rightArmRotators, leftLegRotators, rightLegRotators, rootTransformation)
	);
}

RobotAnimator::RobotAnimator()
{
	animations.clear();
	animationIndex = 0;
	leftArmRotators.hoopRotation = new glm::mat4(1);
	leftArmRotators.elbowRotation = new glm::mat4(1);
	leftArmRotators.forearmRotation = new glm::mat4(1);
	leftArmRotators.leftFingerRotator = new glm::mat4(1);
	leftArmRotators.rightFingerRotator = new glm::mat4(1);
	rightArmRotators.hoopRotation = new glm::mat4(1);
	rightArmRotators.elbowRotation = new glm::mat4(1);
	rightArmRotators.forearmRotation = new glm::mat4(1);
	rightArmRotators.leftFingerRotator = new glm::mat4(1);
	rightArmRotators.rightFingerRotator = new glm::mat4(1);
	leftLegRotators.panRotation = new glm::mat4(1);
	leftLegRotators.kneeRotation = new glm::mat4(1);
	rightLegRotators.panRotation = new glm::mat4(1);
	rightLegRotators.kneeRotation = new glm::mat4(1);

	_transformationBuilder = new TransformationBuilder();
}

void RobotAnimator::makeAnimationStep()
{
	if (animations[animationIndex]->nextStep())
		return;

}


RobotAnimator::~RobotAnimator()
{
	delete leftArmRotators.hoopRotation;
	delete leftArmRotators.elbowRotation;
	delete leftArmRotators.forearmRotation;
	delete leftArmRotators.leftFingerRotator;
	delete leftArmRotators.rightFingerRotator;
	delete rightArmRotators.hoopRotation;
	delete rightArmRotators.elbowRotation;
	delete rightArmRotators.forearmRotation;
	delete rightArmRotators.leftFingerRotator;
	delete rightArmRotators.rightFingerRotator;
	delete leftLegRotators.panRotation;
	delete leftLegRotators.kneeRotation;
	delete rightLegRotators.panRotation;
	delete rightLegRotators.kneeRotation;
	for (RobotAnimation* animation : animations)
		delete animation;
}
