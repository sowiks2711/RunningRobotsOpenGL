#pragma once
#include <glm\glm.hpp>

class RobotAnimator
{
public:
	glm::mat4* leftHoopTransformation;
	glm::mat4* rightHoopTransformation;
	glm::mat4* leftElbowTransformation;
	glm::mat4* rightElbowTransformation;
	glm::mat4* leftPanTransformation;
	glm::mat4* rightPanTransformation;
	glm::mat4* leftKneeTransformation;
	glm::mat4* rightKneeTransformation;
	RobotAnimator();
	~RobotAnimator();
};

