#pragma once
#include "Playground\AbstractModel.h"
class SimpleModel :
	public AbstractModel
{
	glm::mat4 _modelCoordinates;
	ModelRenderer* _renderer;
	LightInteractionProperties _materialProperties;
public:
	SimpleModel();
	SimpleModel(ModelRenderer* renderer, glm::mat4& modelMatrix, LightInteractionProperties& materialProperties);
	void render(const GLuint mvId, const glm::mat4 &view, const GLuint pId, const glm::mat4 &P);
	void bindMaterialProperties(LightInteractionPropertiesHandles& handles);
	glm::mat4& getCurrentTransformation();
	const LightInteractionProperties& getMaterialProperties();
	~SimpleModel();
};

