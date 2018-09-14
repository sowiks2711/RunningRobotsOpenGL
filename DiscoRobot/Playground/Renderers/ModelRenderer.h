#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include <GLFW/glfw3.h>
#include "..\Geometry\AbstractGeometry.h"
#include "..\POCOs\LightInteractionProperties.h"
#include "..\POCOs\LightInteractionPropertiesHandles.h"
#include "..\POCOs\TransformationMatricesHandles.h"

class ModelRenderer
{
	int _triangles;
	void initOpenGlBuffer(GLuint& bufferId, size_t verticesSize, const void* arrayStart);
protected:
	GLuint _vertexArrayId;
	GLuint _verticesBufferId;
	GLuint _normalsBufferId;
	virtual void init(AbstractGeometry* geometry);
	virtual void draw();
public:
	ModelRenderer();
	virtual void render(const TransformationMatricesHandles& matricesHandles, const glm::mat4 &M, const glm::mat4 &V, const glm::mat4& P);
	void bindArrayToAtrribute(GLuint attributeId, GLuint bufferId, int vecDimentions);
	void bindColourProperties(const LightInteractionProperties& _properties, const LightInteractionPropertiesHandles& handles);
	~ModelRenderer();
};

