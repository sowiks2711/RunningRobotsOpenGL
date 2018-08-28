#pragma once
#include "ModelRenderer.h"
class SfereRenderer :
	public ModelRenderer
{
public:
	SfereRenderer();
	SfereRenderer(AbstractGeometry& sfere);
	~SfereRenderer();
};

