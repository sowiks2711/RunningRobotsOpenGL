#pragma once
#include "..\POCOs\ArmRotators.h"
#include "..\POCOs\LegRotators.h"

class RobotAnimation
{
protected:
	ArmRotators* _leftArmRotators;
	ArmRotators* _rightArmRotators;
	LegRotators* _leftLegRotators;
	LegRotators* _rightLegRotators;
	glm::mat4* _rootTransformation;
	void applyTransformation(glm::mat4* toMatrix, glm::mat4& byMatrix);
public:
	RobotAnimation();
	RobotAnimation(
		ArmRotators& leftArmRotators,
		ArmRotators& rightArmRotators,
		LegRotators& leftLegRotators,
		LegRotators& rightLegRotators,
		glm::mat4* rootTransformation
	);
	virtual bool nextStep() = 0;
	~RobotAnimation();
};

