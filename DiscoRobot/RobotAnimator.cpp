#include "RobotAnimator.h"



RobotAnimator::RobotAnimator()
{
	glm::mat4* leftHoopTransformation = new glm::mat4(1);
	glm::mat4* rightHoopTransformation = new glm::mat4(1);
	glm::mat4* leftElbowTransformation = new glm::mat4(1);
	glm::mat4* rightElbowTransformation = new glm::mat4(1);
	glm::mat4* leftPanTransformation = new glm::mat4(1);
	glm::mat4* rightPanTransformation = new glm::mat4(1);
	glm::mat4* leftKneeTransformation = new glm::mat4(1);
	glm::mat4* rightKneeTransformation = new glm::mat4(1);
}


RobotAnimator::~RobotAnimator()
{
	delete leftHoopTransformation;
	delete rightHoopTransformation;
	delete leftElbowTransformation;
	delete rightElbowTransformation;
	delete leftPanTransformation;
	delete rightPanTransformation;
	delete leftKneeTransformation;
	delete rightKneeTransformation;
}
