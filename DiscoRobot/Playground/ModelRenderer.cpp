#include "ModelRenderer.h"



ModelRenderer::ModelRenderer()
{
}

void ModelRenderer::init(AbstractGeometry* geometry)
{
	glGenVertexArrays(1, &_vertexArrayId);
	glBindVertexArray(_vertexArrayId);
	initOpenGlBuffer(_verticesBufferId, geometry->getVerticesSize(), geometry->getVerticesArrayStart());
	initOpenGlBuffer(_normalsBufferId, geometry->getNormalsSize(), geometry->getNormalsArrayStart());
	this->_triangles = geometry->getTrianglesCount();
}

void ModelRenderer::draw()
{
	glDrawArrays(GL_TRIANGLES, 0, _triangles);
}

void ModelRenderer::initOpenGlBuffer(GLuint& bufferId, size_t verticesSize,const void* arrayStart)
{
	glGenBuffers(1, &bufferId);
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glBufferData(GL_ARRAY_BUFFER, verticesSize, arrayStart, GL_STATIC_DRAW);
}

void ModelRenderer::render( const GLuint mvId, const glm::mat4 &MV, const GLuint pId, const glm::mat4 &P)
{
	glUniformMatrix4fv(mvId, 1, GL_FALSE, &MV[0][0]);
	glUniformMatrix4fv(pId, 1, GL_FALSE, &P[0][0]);
	glBindVertexArray(_vertexArrayId);
	bindArrayToAtrribute(0, _verticesBufferId, 3);
	bindArrayToAtrribute(1, _normalsBufferId, 3);
	draw();
	glDisableVertexAttribArray(0);
}


void ModelRenderer::bindArrayToAtrribute(GLuint attributeId, GLuint bufferId, int vecDimentions)
{
	glEnableVertexAttribArray(attributeId);
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glVertexAttribPointer(
		attributeId,
		vecDimentions,
		GL_FLOAT,
		GL_FALSE,
		3 * sizeof(GLfloat),
		(void*)0
	);
}

void ModelRenderer::bindColourProperties(const LightInteractionProperties & _properties, const LightInteractionPropertiesHandles & handles)
{
	glUniform1f(handles.shininessId, _properties.shininess);
	glUniform4fv(handles.emissionId, 1, &_properties.emission.x);
	glUniform4fv(handles.diffuseId, 1, &_properties.diffuse.x);
	glUniform4fv(handles.specularId, 1, &_properties.specular.x);
}


ModelRenderer::~ModelRenderer()
{
	glDeleteVertexArrays(1, &_vertexArrayId);
	glDeleteBuffers(1, &_verticesBufferId);
	glDeleteBuffers(1, &_normalsBufferId);
}
