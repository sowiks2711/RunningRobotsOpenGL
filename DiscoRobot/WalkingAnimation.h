#pragma once
#include "RobotAnimation.h"
#include "Playground\TransformationBuilder.h"

class WalkingAnimation :
	public RobotAnimation
{
	enum Quarter {
		First,
		Second,
		Third,
		Fourth
	};
	const int _prepareArmsSteps = 300;
	const int _walkCycleSteps = 500;
	const int nrOfWalkCycles = 10;
	const float bendAngle = 90.0;
	const float swingAngle = 45.0;
	float _armsAngle;
	int _currentStep;
	void takeBendArmsByStep();
	void takeWalkCycleStep(int stepNr);
	void takeStraighteningArmsStep();
	TransformationBuilder* builder;
	WalkingAnimation::Quarter getQuarter(int stepNr);
	glm::mat4 bendingRotationStep;
	glm::mat4 straitaningRotationStep;
	glm::mat4 forwardSwingingRotationStep;
	glm::mat4 backwardSwingingRotationStep;
	glm::mat4 backwardSwingingForearmRotationStep;
	glm::mat4 forwardSwingingForearmRotationStep;
	glm::mat4 forwardForearmRotationStep;
	glm::mat4 backwardForearmRotationStep;
	glm::mat4 forwardHookBendStep;
	glm::mat4 backwardHookBendStep;
	glm::mat4 rootTransformationStep;

public:
	WalkingAnimation();
	WalkingAnimation(
		ArmRotators& leftArmRotators,
		ArmRotators& rightArmRotators,
		LegRotators& leftLegRotators,
		LegRotators& rightLegRotators,
		glm::mat4* rootTransformation
	) ;
	virtual bool nextStep();
	~WalkingAnimation();
};

