#include "AnimationStepMaker.h"




AnimationStepMaker::AnimationStepMaker()
{
	TransformationBuilder tb = TransformationBuilder();
	stepForward = tb.rotate(-0.1, glm::vec3(1,0,0)).build();
	stepBackward = tb.rotate(0.1, glm::vec3(1,0,0)).build();
	startingPoint = glm::mat4(1.0);
	currentStepNr = 500;
	directionSwitchingInterval = 1000;
	isForward = true;
}

glm::mat4& AnimationStepMaker::getNextStep()
{

	glm::mat4* result = isForward ? &stepForward : &stepBackward;

	if (isTimeForDirectionChange())
		changeAnimationDirection();
	
	currentStepNr++;
	return *result;
}

void AnimationStepMaker::changeAnimationDirection()
{
	isForward = !isForward;
}

bool AnimationStepMaker::isTimeForDirectionChange()
{
	return currentStepNr % directionSwitchingInterval == 0;
}


AnimationStepMaker::~AnimationStepMaker()
{
}
