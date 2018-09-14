#include "RobotAnimation.h"



void RobotAnimation::applyTransformation(glm::mat4 * toMatrix, glm::mat4 & byMatrix)
{
	*toMatrix = *toMatrix * byMatrix;
}

RobotAnimation::RobotAnimation()
{
}


RobotAnimation::RobotAnimation(ArmRotators & leftArmRotators, ArmRotators & rightArmRotators, LegRotators & leftLegRotators, LegRotators & rightLegRotators, glm::mat4* rootTransformation)
{
	_leftArmRotators = &leftArmRotators;
	_rightArmRotators = &rightArmRotators;
	_leftLegRotators = &leftLegRotators;
	_rightLegRotators = &rightLegRotators;
	_rootTransformation = rootTransformation;


}

RobotAnimation::~RobotAnimation()
{
}
