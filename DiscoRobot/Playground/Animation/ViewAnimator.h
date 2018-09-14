#pragma once
#include "..\Transformation\Transform.h"
#include "..\Transformation\TransformationBuilder.h"

class ViewAnimator
{
	glm::mat4* _mainActorTransformation;
	glm::mat4* _viewMatrix;
	glm::mat4 _singleStepTransformation;
	glm::vec3* _eye;
	glm::vec3* _up;
	TransformationBuilder* _builder;
	int currentStep;
	int waitDuration;
	int cycleDuration;
	void rotateCameraUpOverCenterByStep();
	void followMainActorWithCamera();
public:
	ViewAnimator();
	ViewAnimator(glm::mat4& viewMatrix, glm::vec3& eye, glm::vec3& up, glm::mat4& mainActorTransformation);
	void makeNextStep();
	~ViewAnimator();
};

