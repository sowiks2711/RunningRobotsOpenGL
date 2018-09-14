#pragma once
#include "ModelBuilder.h"
#include "..\Renderers\CubeRenderer.h"
#include "..\Geometry\Cube.h"

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
