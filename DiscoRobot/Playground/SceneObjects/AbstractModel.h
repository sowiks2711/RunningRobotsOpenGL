#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <glm/glm.hpp>
#include "..\Geometry\AbstractGeometry.h"
#include "..\Renderers\ModelRenderer.h"
#include "..\POCOs\LightInteractionProperties.h"
#include "..\POCOs\TransformationMatricesHandles.h"

class AbstractModel
{

public:
	AbstractModel();
	virtual void render(const TransformationMatricesHandles& matricesHandles, const glm::mat4 &M, const glm::mat4 &V, const glm::mat4& P) = 0;
	virtual void bindMaterialProperties(LightInteractionPropertiesHandles& handles) = 0;
	virtual glm::mat4& getCurrentTransformation() = 0;
	virtual const LightInteractionProperties& getMaterialProperties() = 0;
	~AbstractModel();
};

