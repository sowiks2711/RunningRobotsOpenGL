#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include <GLFW/glfw3.h>
#include "AbstractGeometry.h"
#include "LightInteractionProperties.h"

class ModelRenderer
{
	int _triangles;
	void initOpenGlBuffer(GLuint& bufferId, size_t verticesSize, const void* arrayStart);
protected:
	GLuint _vertexArrayId;
	GLuint _verticesBufferId;
	GLuint _normalsBufferId;
	virtual void init(AbstractGeometry& geometry);
	virtual void draw();
public:
	ModelRenderer();
	virtual void render(const GLuint mvId, const glm::mat4 &MV, const GLuint pId, const glm::mat4& P);
	void BindArrayToAtrribute(GLuint attributeId, GLuint bufferId, int vecDimentions);
	~ModelRenderer();
};

