#include "CubeModelBuilder.h"

ModelRenderer* CubeModelBuilder::getModelRenderer()
{
	return _renderer;
}

CubeModelBuilder::CubeModelBuilder():ModelBuilder()
{
	_geometry = new Cube();
	_renderer = new CubeRenderer(*_geometry);
}

CubeModelBuilder::~CubeModelBuilder()
{
	delete _geometry;
	delete _renderer;
}
