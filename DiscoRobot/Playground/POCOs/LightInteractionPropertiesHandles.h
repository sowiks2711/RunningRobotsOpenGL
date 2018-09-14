#pragma once
#include <GL/glew.h>
#include <glm\glm.hpp>
struct LightInteractionPropertiesHandles
{
public:
	GLuint diffuseId;
	GLuint emissionId;
	GLuint specularId;
	GLuint shininessId;
};

