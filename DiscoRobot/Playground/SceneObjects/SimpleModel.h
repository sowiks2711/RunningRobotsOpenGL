#pragma once
#include "AbstractModel.h"
#include "..\POCOs\TransformationMatricesHandles.h"

class SimpleModel :
	public AbstractModel
{
	glm::mat4 _modelCoordinates;
	ModelRenderer* _renderer;
	LightInteractionProperties _materialProperties;
public:
	SimpleModel();
	SimpleModel(ModelRenderer* renderer, glm::mat4& modelMatrix, LightInteractionProperties& materialProperties);
	void render(const TransformationMatricesHandles& matricesHandles, const glm::mat4 &M, const glm::mat4 &V, const glm::mat4 &P);
	void bindMaterialProperties(LightInteractionPropertiesHandles& handles);
	glm::mat4& getCurrentTransformation();
	const LightInteractionProperties& getMaterialProperties();
	~SimpleModel();
};

