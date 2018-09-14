#include "Transform.h"
#define _USE_MATH_DEFINES
#include <math.h>
using namespace glm;
Transform::Transform()
{
}

Transform::~Transform()
{
}

glm::mat4 Transform::lookAt(const glm::vec3 & eye, const glm::vec3 & center, const glm::vec3 & up)
{
	vec3 eyeCenterDiff = eye - center;

	vec3 w = normalize(eyeCenterDiff);
	vec3 u = normalize(cross(up, w));
	vec3 v = cross(w, u);

	mat3 rot = mat3(
		u.x, v.x, w.x, 
		u.y, v.y, w.y, 
		u.z, v.z, w.z
	);
	vec3 tr = rot * (-eye);

	return glm::mat4(
		rot[0][0], rot[0][1], rot[0][2], 0,
		rot[1][0], rot[1][1], rot[1][2], 0,
		rot[2][0], rot[2][1], rot[2][2], 0,
		tr.x, tr.y, tr.z, 1
	);
}

glm::mat4 Transform::perspective(float fovy, float aspect, float zNear, float zFar)
{

	float d = 1.0 / tan((double)(fovy/2));
	return glm::mat4(
			d/aspect, 0, 0, 0,
			0,        d, 0, 0,
			0,        0, (zNear + zFar)/(zNear - zFar), -1,
			0,        0, 2 * zNear * zFar / (zNear - zFar), 0
	);
}

glm::mat3 Transform::rotate3(const float angle , const glm::vec3 & axis)
{
	glm::vec3 normalizedAxis = normalize(axis);
	
	mat3 ux = mat3(0,       normalizedAxis.z, -normalizedAxis.y, 
	              -normalizedAxis.z,  0,       normalizedAxis.x,
		           normalizedAxis.y, -normalizedAxis.x,  0);
	mat3 uut = mat3(
		normalizedAxis.x * normalizedAxis.x, normalizedAxis.x * normalizedAxis.y, normalizedAxis.x * normalizedAxis.z,
		normalizedAxis.x * normalizedAxis.y, normalizedAxis.y * normalizedAxis.y, normalizedAxis.y * normalizedAxis.z,
		normalizedAxis.x * normalizedAxis.z, normalizedAxis.y * normalizedAxis.z, normalizedAxis.z * normalizedAxis.z
	);
	return cos(angle) * mat3(1.0) + sin(angle) * ux + (1 - cos(angle)) * uut;
}

glm::mat4 Transform::rotate(const float angle , const glm::vec3 & axis)
{
	mat3 rot = rotate3(angle, axis);
	return glm::mat4(
		rot[0][0], rot[0][1], rot[0][2], 0,
		rot[1][0], rot[1][1], rot[1][2], 0,
		rot[2][0], rot[2][1], rot[2][2], 0,
		0,		   0,		  0,		 1
	);
}

glm::mat4 Transform::scale(const float & sx, const float & sy, const float & sz)
{
	return glm::mat4(
		sx, 0,  0,  0,
		0,  sy, 0,  0,
		0,  0,  sz, 0,
		0,  0,  0,  1
	
	);
}

glm::mat4 Transform::translate(const float & tx, const float & ty, const float & tz)
{
	return glm::mat4(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		tx, ty, tz, 1
	);
}

void Transform::rotateCameraNormalsOverCenterLeft(float degrees, glm::vec3 & eye, glm::vec3 & up)
{
	mat3 rotM = rotate(degrees, normalize(up));
	eye = rotM * eye;
}

void Transform::rotateCameraNormalsOverCenterUp(float degrees, glm::vec3 & eye, glm::vec3 & up)
{
	vec3 axisUp = glm::cross(-eye, up);
	axisUp = normalize(axisUp);
	mat3 rotM = rotate(-degrees, axisUp);
	vec3 translation = -eye;
	vec3 rotTrans = rotM * translation;
	mat4 upM = mat4(rotM[0][0], rotM[0][1], rotM[0][2], 0,
		rotM[1][0], rotM[1][1], rotM[1][2], 0,
		rotM[2][0], rotM[2][1], rotM[2][2], 0,
		rotTrans.x, rotTrans.y, rotTrans.z, 1);
	vec4 homoUp = vec4(up, 1);
	homoUp = upM * homoUp;
	eye = rotM * eye;
	up = vec3(homoUp[0], homoUp[1], homoUp[2]) + eye;
	up = normalize(up);
}

