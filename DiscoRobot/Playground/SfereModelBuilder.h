#pragma once
#include "ModelBuilder.h"
#include "SfereRenderer.h"
#include "Sfere.h"

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

