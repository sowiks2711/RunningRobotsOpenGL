#pragma once
#include <GL/glew.h>
#include <glm\glm.hpp>
struct TransformationMatricesHandles
{
public:
	GLuint viewId;
	GLuint modelId;
	GLuint projectionId;
	GLuint spotlightRotationId;
};

