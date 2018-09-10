#pragma once
#include <glm\glm.hpp>
#include "Playground\TransformationBuilder.h"
class AnimationStepMaker
{
	glm::mat4 stepForward;
	glm::mat4 stepBackward;
	glm::mat4 startingPoint;
	int currentStepNr;
	int directionSwitchingInterval;
	bool isForward;
	
public:
	AnimationStepMaker();
	glm::mat4& getNextStep();
	void changeAnimationDirection();
	bool isTimeForDirectionChange();
	~AnimationStepMaker();
};

