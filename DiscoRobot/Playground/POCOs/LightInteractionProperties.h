#pragma once
#include <GL/glew.h>
#include <glm\glm.hpp>
struct LightInteractionProperties
{
public:
	glm::vec4 diffuse;
	glm::vec4 emission;
	glm::vec4 specular;
	GLfloat shininess;
};

