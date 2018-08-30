#include "SfereModelBuilder.h"



ModelRenderer* SfereModelBuilder::getModelRenderer()
{
	return _renderer;
}

SfereModelBuilder::SfereModelBuilder()
{
	_geometry = new Sfere(20, 50, 50);
	_renderer = new SfereRenderer(*_geometry);
}


SfereModelBuilder::~SfereModelBuilder()
{
	delete _geometry;
	delete _renderer;
}
