#pragma once
#include <glm/glm.hpp>

class Transform
{
public:
	Transform();
	virtual ~Transform();
	static glm::mat4 lookAt(const glm::vec3& eye, const glm::vec3& center, const glm::vec3& up );
	static glm::mat4 perspective(float fovy, float aspect, float zNear, float zFar);
	static glm::mat3 rotate3(const float angle, const glm::vec3& axis);
	static glm::mat4 rotate(const float angle, const glm::vec3& axis);
	static glm::mat4 scale(const float& sx, const float& sy, const float& sz);
	static glm::mat4 translate(const float& tx, const float& ty, const float& tz);
	static void rotateCameraNormalsOverCenterLeft(float degrees, glm::vec3& eye, glm::vec3& up);
	static void rotateCameraNormalsOverCenterUp(float degrees, glm::vec3& eye, glm::vec3& up);
};

