#pragma once
#include <glm/glm.hpp>

struct ArmRotators
{
public:
	glm::mat4* hoopRotation;
	glm::mat4* elbowRotation;
	glm::mat4* forearmRotation;
	glm::mat4* leftFingerRotator;
	glm::mat4* rightFingerRotator;
};

