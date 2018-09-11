#include "WalkingAnimation.h"



void WalkingAnimation::takeBendArmsByStep()
{
	applyTransformation(_leftArmRotators->elbowRotation, bendingRotationStep);
	applyTransformation(_rightArmRotators->elbowRotation, bendingRotationStep);
	applyTransformation(_leftArmRotators->forearmRotation, forwardForearmRotationStep);
	applyTransformation(_rightArmRotators->forearmRotation, backwardForearmRotationStep);
}

void WalkingAnimation::takeWalkCycleStep(int stepNr)
{
	Quarter quarter = getQuarter(stepNr);
	applyTransformation(_rootTransformation, rootTransformationStep);
	switch (quarter) 
	{
	case First:
		applyTransformation(_leftArmRotators->hoopRotation, forwardSwingingRotationStep);
		applyTransformation(_rightArmRotators->hoopRotation, backwardSwingingRotationStep);
		applyTransformation(_leftLegRotators->panRotation, forwardSwingingRotationStep);
		applyTransformation(_rightLegRotators->panRotation, backwardSwingingRotationStep);
		applyTransformation(_leftLegRotators->kneeRotation, backwardSwingingRotationStep);
		applyTransformation(_rightLegRotators->kneeRotation, backwardSwingingRotationStep);
		applyTransformation(_leftArmRotators->elbowRotation, backwardSwingingForearmRotationStep);
		applyTransformation(_rightArmRotators->elbowRotation, forwardSwingingForearmRotationStep);
		applyTransformation(_leftArmRotators->leftFingerRotator, forwardHookBendStep);
		applyTransformation(_leftArmRotators->rightFingerRotator, backwardHookBendStep);
		applyTransformation(_rightArmRotators->leftFingerRotator, forwardHookBendStep);
		applyTransformation(_rightArmRotators->rightFingerRotator, backwardHookBendStep);
		break;
	case Second:
		applyTransformation(_leftArmRotators->hoopRotation, backwardSwingingRotationStep);
		applyTransformation(_rightArmRotators->hoopRotation, forwardSwingingRotationStep);
		applyTransformation(_leftLegRotators->panRotation, backwardSwingingRotationStep);
		applyTransformation(_rightLegRotators->panRotation, forwardSwingingRotationStep);
		applyTransformation(_leftLegRotators->kneeRotation, forwardSwingingRotationStep);
		applyTransformation(_rightLegRotators->kneeRotation, forwardSwingingRotationStep);
		applyTransformation(_rightArmRotators->elbowRotation, backwardSwingingForearmRotationStep);
		applyTransformation(_leftArmRotators->elbowRotation, forwardSwingingForearmRotationStep);
		applyTransformation(_leftArmRotators->leftFingerRotator, forwardHookBendStep);
		applyTransformation(_leftArmRotators->rightFingerRotator, backwardHookBendStep);
		applyTransformation(_rightArmRotators->leftFingerRotator, forwardHookBendStep);
		applyTransformation(_rightArmRotators->rightFingerRotator, backwardHookBendStep);
		break;
	case Third:
		applyTransformation(_leftArmRotators->hoopRotation, backwardSwingingRotationStep);
		applyTransformation(_rightArmRotators->hoopRotation, forwardSwingingRotationStep);
		applyTransformation(_leftLegRotators->panRotation, backwardSwingingRotationStep);
		applyTransformation(_rightLegRotators->panRotation, forwardSwingingRotationStep);
		applyTransformation(_leftLegRotators->kneeRotation, backwardSwingingRotationStep);
		applyTransformation(_rightLegRotators->kneeRotation, backwardSwingingRotationStep);
		applyTransformation(_leftArmRotators->elbowRotation, backwardSwingingForearmRotationStep);
		applyTransformation(_rightArmRotators->elbowRotation, forwardSwingingForearmRotationStep);
		applyTransformation(_leftArmRotators->leftFingerRotator, backwardHookBendStep);
		applyTransformation(_leftArmRotators->rightFingerRotator, forwardHookBendStep);
		applyTransformation(_rightArmRotators->leftFingerRotator, backwardHookBendStep);
		applyTransformation(_rightArmRotators->rightFingerRotator, forwardHookBendStep);
		break;
	case Fourth:
		applyTransformation(_leftArmRotators->hoopRotation, forwardSwingingRotationStep);
		applyTransformation(_rightArmRotators->hoopRotation, backwardSwingingRotationStep);
		applyTransformation(_leftLegRotators->panRotation, forwardSwingingRotationStep);
		applyTransformation(_rightLegRotators->panRotation, backwardSwingingRotationStep);
		applyTransformation(_leftLegRotators->kneeRotation, forwardSwingingRotationStep);
		applyTransformation(_rightLegRotators->kneeRotation, forwardSwingingRotationStep);
		applyTransformation(_rightArmRotators->elbowRotation, backwardSwingingForearmRotationStep);
		applyTransformation(_leftArmRotators->elbowRotation, forwardSwingingForearmRotationStep);
		applyTransformation(_leftArmRotators->leftFingerRotator, backwardHookBendStep);
		applyTransformation(_leftArmRotators->rightFingerRotator, forwardHookBendStep);
		applyTransformation(_rightArmRotators->leftFingerRotator, backwardHookBendStep);
		applyTransformation(_rightArmRotators->rightFingerRotator, forwardHookBendStep);
		break;
	}

}

void WalkingAnimation::takeStraighteningArmsStep()
{
	applyTransformation(_leftArmRotators->elbowRotation, straitaningRotationStep);
	applyTransformation(_rightArmRotators->elbowRotation, straitaningRotationStep);
	applyTransformation(_leftArmRotators->forearmRotation, backwardForearmRotationStep);
	applyTransformation(_rightArmRotators->forearmRotation, forwardForearmRotationStep);
}


WalkingAnimation::Quarter WalkingAnimation::getQuarter(int stepNr)
{
	float mapped = stepNr / (float)_walkCycleSteps;
	return Quarter((int)(mapped*4));

}

WalkingAnimation::WalkingAnimation()
{
}

WalkingAnimation::WalkingAnimation(ArmRotators & leftArmRotators, ArmRotators & rightArmRotators, LegRotators & leftLegRotators, LegRotators & rightLegRotators, glm::mat4* rootTransformation)
: RobotAnimation(leftArmRotators, rightArmRotators, leftLegRotators, rightLegRotators, rootTransformation)
{
	_currentStep = 0;
	_armsAngle = 45;
	builder = new TransformationBuilder();
	bendingRotationStep = builder->rotate(bendAngle / _prepareArmsSteps, glm::vec3(1, 0, 0)).build();
	straitaningRotationStep = builder->rotate(-bendAngle / _prepareArmsSteps, glm::vec3(1, 0, 0)).build();
	forwardSwingingRotationStep = builder->rotate(4 * swingAngle / _walkCycleSteps, glm::vec3(1, 0, 0)).build();
	backwardSwingingRotationStep = builder->rotate(-4 * swingAngle / _walkCycleSteps, glm::vec3(1, 0, 0)).build();
	backwardSwingingForearmRotationStep = builder->rotate(- swingAngle / _walkCycleSteps, glm::vec3(1, 0, 0)).build(); 
	forwardSwingingForearmRotationStep = builder->rotate(swingAngle / _walkCycleSteps, glm::vec3(1, 0, 0)).build(); 
	forwardForearmRotationStep = builder->rotate(180.0 / _prepareArmsSteps, glm::vec3(0, 1, 0)).build();
	backwardForearmRotationStep = builder->rotate(180.0 / _prepareArmsSteps, glm::vec3(0, 1, 0)).build();
	forwardHookBendStep = builder->rotate(-40.0 / _walkCycleSteps, glm::vec3(0, 0, 1)).build();
	backwardHookBendStep = builder->rotate(40.0 / _walkCycleSteps, glm::vec3(0, 0, 1)).build();
	rootTransformationStep = builder->rotate(360.0 / _walkCycleSteps, glm::vec3(0, 1, 0)).translate(0, 0, -0.1).build();

}

bool WalkingAnimation::nextStep()
{
	if (_currentStep < _prepareArmsSteps)
		takeBendArmsByStep();
	else if (_currentStep < _prepareArmsSteps + _walkCycleSteps*nrOfWalkCycles)
		takeWalkCycleStep((_currentStep - _prepareArmsSteps) % _walkCycleSteps);
	else
		takeStraighteningArmsStep();

	_currentStep++;
	bool hasNextStep = _currentStep < _prepareArmsSteps *2 + _walkCycleSteps*nrOfWalkCycles;
	if (!hasNextStep) _currentStep = 0;
	return hasNextStep;
}


WalkingAnimation::~WalkingAnimation()
{
	delete builder;
}