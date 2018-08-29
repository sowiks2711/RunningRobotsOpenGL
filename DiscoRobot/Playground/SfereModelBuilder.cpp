#include "SfereModelBuilder.h"



ModelRenderer* SfereModelBuilder::getModelRenderer()
{
	return &_renderer;
}

SfereModelBuilder::SfereModelBuilder()
{
	_geometry = Sfere(20, 20, 50);
	_renderer = SfereRenderer(_geometry);
}


SfereModelBuilder::~SfereModelBuilder()
{
}
