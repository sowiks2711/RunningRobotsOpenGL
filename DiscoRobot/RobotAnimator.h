#pragma once
#include <glm\glm.hpp>
#include "Playground\TransformationBuilder.h"
#include "AnimationStepMaker.h"
#include "ArmRotators.h"
#include "LegRotators.h"

class RobotAnimator
{
	TransformationBuilder* _transformationBuilder;
	AnimationStepMaker* _hoopStepMaker;
	AnimationStepMaker* _elbowStepMaker;

	ArmRotators leftArmRotators;
	ArmRotators rightArmRotators;
	LegRotators leftLegRotators;
	LegRotators rightLegRotators;
public:
	ArmRotators& getLeftArmRotators();
	ArmRotators& getRightArmRotators();
	LegRotators& getLeftLegRotators();
	LegRotators& getRightLegRotators();
	RobotAnimator();
	void makeAnimationStep();
	~RobotAnimator();
};

