#pragma once
#include "ModelBuilder.h"
#include "..\Renderers\SfereRenderer.h"
#include "..\Geometry\Sfere.h"

class SfereModelBuilder :
	public ModelBuilder
{
	SfereRenderer* _renderer;
	Sfere* _geometry;
protected:
	ModelRenderer* getModelRenderer();
public:
	SfereModelBuilder();
	~SfereModelBuilder();
};

