#include "SimpleModel.h"



SimpleModel::SimpleModel()
{
}

SimpleModel::SimpleModel(ModelRenderer * renderer, glm::mat4 & modelMatrix, LightInteractionProperties & materialProperties)
	:AbstractModel(renderer, modelMatrix, materialProperties)
{
}

void SimpleModel::render(const GLuint mvId, const glm::mat4 & MV, const GLuint pId, const glm::mat4 & P)
{
	this->_renderer->render(mvId, MV, pId, P);
}

void SimpleModel::bindMaterialProperties(LightInteractionPropertiesHandles & handles)
{
	_renderer->bindColourProperties(_materialProperties, handles);
}


SimpleModel::~SimpleModel()
{
}
