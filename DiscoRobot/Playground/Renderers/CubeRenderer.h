#pragma once
#include "ModelRenderer.h"
#include "..\Geometry\Cube.h"

class CubeRenderer :
	public ModelRenderer
{
	GLuint _indexBufferId;
	size_t _indicesSize;
	int _indicesCount;
	void initIndexes(Cube& cube);
	void draw();
public:
	CubeRenderer();
	CubeRenderer(Cube& cube);
	~CubeRenderer();
};

