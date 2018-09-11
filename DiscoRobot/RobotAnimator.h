#pragma once
#include <glm\glm.hpp>
#include "Playground\TransformationBuilder.h"
#include "AnimationStepMaker.h"
#include "ArmRotators.h"
#include "LegRotators.h"
#include "RobotAnimation.h"
#include "WalkingAnimation.h"
#include <vector>

class RobotAnimator
{
	TransformationBuilder* _transformationBuilder;
	std::vector<RobotAnimation*> animations;
	int animationIndex;

	ArmRotators leftArmRotators;
	ArmRotators rightArmRotators;
	LegRotators leftLegRotators;
	LegRotators rightLegRotators;
	glm::mat4* rootTransformation;
public:
	ArmRotators& getLeftArmRotators();
	ArmRotators& getRightArmRotators();
	LegRotators& getLeftLegRotators();
	LegRotators& getRightLegRotators();
	glm::mat4& getRootTransformation();
	RobotAnimator();
	void makeAnimationStep();
	~RobotAnimator();
};

