#pragma once
#include "Transform.h"
#include <glm\glm.hpp>

#define _USE_MATH_DEFINES
#include <math.h>

class TransformationBuilder
{
protected:
	glm::mat4 _transformation;
public:
	TransformationBuilder();
	glm::mat4 build();
	void reset();
	TransformationBuilder& rotate(float degrees, const glm::vec3 rotationAxis);
	TransformationBuilder& perspective(float FoV, float aspect, float zNear, float zFar);
	TransformationBuilder& translate(float x, float y, float z);
	TransformationBuilder& scale(float sx, float sy, float sz);
	TransformationBuilder& scale(float s);
	~TransformationBuilder();
};

