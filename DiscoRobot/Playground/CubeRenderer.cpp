#include "CubeRenderer.h"



void CubeRenderer::initIndexes(Cube& cube)
{
	glGenBuffers(1, &_indexBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, cube.getIndicesSize(), cube.getIndicesArrayStart(), GL_STATIC_DRAW);
}

void CubeRenderer::draw()
{
	// Index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBufferId);

	// Draw the triangles !
	glDrawElements(
		GL_TRIANGLES,      // mode
		_indicesCount,    // count
		GL_UNSIGNED_INT,   // type
		(void*)0           // element array buffer offset
	);
}

CubeRenderer::CubeRenderer()
{
}

CubeRenderer::CubeRenderer(Cube & cube)
{
	_indicesSize = cube.getIndicesSize();
	_indicesCount = cube.getIndicesCount();
	init(cube);
	initIndexes(cube);

}


CubeRenderer::~CubeRenderer()
{
	glDeleteBuffers(1, &_indexBufferId);
}
