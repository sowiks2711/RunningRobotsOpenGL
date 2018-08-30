#pragma once
#include "Playground\AbstractModel.h"
class SimpleModel :
	public AbstractModel
{
public:
	SimpleModel();
	SimpleModel(ModelRenderer* renderer, glm::mat4& modelMatrix, LightInteractionProperties& materialProperties);
	void render(const GLuint mvId, const glm::mat4 &MV, const GLuint pId, const glm::mat4 &P);
	void bindMaterialProperties(LightInteractionPropertiesHandles& handles);
	~SimpleModel();
};

