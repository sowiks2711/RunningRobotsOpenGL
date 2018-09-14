#include "TransformationBuilder.h"


TransformationBuilder::TransformationBuilder()
{
	reset();
}

glm::mat4 TransformationBuilder::build()
{
	glm::mat4 result = _transformation;
	reset();
	return result;
}

void TransformationBuilder::reset()
{
	_transformation = glm::mat4(1.0);
}

TransformationBuilder& TransformationBuilder::rotate(float degrees, const glm::vec3 rotationAxis)
{
	float angle = degrees *  M_PI/180;
	_transformation = Transform::rotate(angle, rotationAxis) * _transformation;
	return *this;
}
TransformationBuilder & TransformationBuilder::rotateOverX(float degrees)
{
	return rotate(degrees, glm::vec3(1, 0, 0));
}
TransformationBuilder & TransformationBuilder::rotateOverY(float degrees)
{
	return rotate(degrees, glm::vec3(0, 1, 0));
}
TransformationBuilder & TransformationBuilder::rotateOverZ(float degrees)
{
	return rotate(degrees, glm::vec3(0, 0, 1));
}
TransformationBuilder& TransformationBuilder::perspective(float FoV, float aspect, float zNear, float zFar)
{
	float angle = FoV *  M_PI/180;

	_transformation = Transform::perspective(angle, aspect, zNear, zFar) * _transformation;
	return *this;
}

TransformationBuilder & TransformationBuilder::translate(float x, float y, float z)
{
	_transformation = Transform::translate(x, y, z) * _transformation;
	return *this;
}

TransformationBuilder & TransformationBuilder::scale(float sx, float sy, float sz)
{
	_transformation = Transform::scale(sx, sy, sz) * _transformation;
	return *this;
}

TransformationBuilder & TransformationBuilder::scale(float s)
{
	_transformation = Transform::scale(s, s, s) * _transformation;
	return *this;
}

TransformationBuilder::~TransformationBuilder()
{
}

