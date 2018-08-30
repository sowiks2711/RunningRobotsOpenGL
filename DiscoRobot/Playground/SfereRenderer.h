#pragma once
#include "ModelRenderer.h"
#include "Sfere.h"
class SfereRenderer :
	public ModelRenderer
{
public:
	SfereRenderer();
	SfereRenderer(Sfere& sfere);
	~SfereRenderer();
};

