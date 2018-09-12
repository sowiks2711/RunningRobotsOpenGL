#include "ViewAnimator.h" 
#include <glm/gtc/matrix_transform.hpp>

void ViewAnimator::rotateCameraUpOverCenterByStep()
{
	//Transform::rotateCameraNormalsOverCenterUp(0.0001, *_eye, *_up);
	Transform::rotateCameraNormalsOverCenterLeft(10.0/cycleDuration, *_eye, *_up);
	*_viewMatrix = Transform::lookAt(*_eye, glm::vec3(0, 0, 0), *_up);
}

void ViewAnimator::followMainActorWithCamera()
{
	glm::vec4 transformedCenter = (*_mainActorTransformation)* glm::vec4(0., 0., 0., 1.);
	glm::vec3 center = glm::vec3(transformedCenter.x,
		transformedCenter.y,
		transformedCenter.z
	);
	//glm::vec4 transformedCenter = glm::vec4(0., 0., 0., 1.);
	glm::vec3 transformedEye = (*_mainActorTransformation)* (glm::vec4(0., 20, 40, 1));
	//glm::vec3 transformedEye = (*_mainActorTransformation)* (transformedCenter +glm::vec4(0., 20, 40,1));
	//glm::vec3 transformedUp = (*_mainActorTransformation)*glm::vec4(*_up, 1);
	*_viewMatrix = Transform::lookAt(transformedEye, center, *_up);
}

ViewAnimator::ViewAnimator()
{
}

ViewAnimator::ViewAnimator(glm::mat4 & viewMatrix, glm::vec3& eye, glm::vec3& up, glm::mat4& mainActorTransformation)
{
	currentStep = 0;
	waitDuration = 500;
	cycleDuration = 3600;
	_viewMatrix = &viewMatrix;
	_eye = &eye;
	_up = &up;
	_mainActorTransformation = &mainActorTransformation;
}

void ViewAnimator::makeNextStep()
{
	if (currentStep < waitDuration);
	else if (currentStep < cycleDuration/3)	rotateCameraUpOverCenterByStep();
	else if (currentStep < cycleDuration/3 + waitDuration);
	else followMainActorWithCamera();
	currentStep = (currentStep + 1) % cycleDuration;
}



ViewAnimator::~ViewAnimator()
{
	delete _builder;
}
