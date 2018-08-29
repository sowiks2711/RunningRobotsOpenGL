#pragma once
#include "ModelBuilder.h"
#include "CubeRenderer.h"
#include "Cube.h"

class CubeModelBuilder :
	public ModelBuilder
{
	CubeRenderer* _renderer;
	Cube* _geometry;
protected:
	ModelRenderer* getModelRenderer();
public:
	CubeModelBuilder();
	~CubeModelBuilder();
};
