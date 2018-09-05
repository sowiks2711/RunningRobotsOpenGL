#include "SimpleModel.h"



SimpleModel::SimpleModel()
{
}

SimpleModel::SimpleModel(ModelRenderer * renderer, glm::mat4 & modelMatrix, LightInteractionProperties & materialProperties)
{
	this->_renderer = renderer;
	this->_modelCoordinates = modelMatrix;
	this->_materialProperties = materialProperties;
}

void SimpleModel::render(const GLuint mvId, const glm::mat4 & view, const GLuint pId, const glm::mat4 & P)
{
	glm::mat4 MV = view * _modelCoordinates;
	this->_renderer->render(mvId, MV, pId, P);
}

void SimpleModel::bindMaterialProperties(LightInteractionPropertiesHandles & handles)
{
	_renderer->bindColourProperties(_materialProperties, handles);
}

glm::mat4 & SimpleModel::getCurrentTransformation()
{
	return _modelCoordinates;
}

const LightInteractionProperties & SimpleModel::getMaterialProperties()
{
	return _materialProperties;
}


SimpleModel::~SimpleModel()
{
}
