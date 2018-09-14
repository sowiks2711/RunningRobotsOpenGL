#pragma once
#include <glm\glm.hpp>
#include "..\Transformation\TransformationBuilder.h"
#include "..\POCOs\ArmRotators.h"
#include "..\POCOs\LegRotators.h"
#include "..\Animation\RobotAnimation.h"
#include "..\Animation\WalkingAnimation.h"
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
	void setInitialTransformation(glm::mat4& transformation);
	void addWalkingAnimation();
	RobotAnimator();
	void makeAnimationStep();
	~RobotAnimator();
};

