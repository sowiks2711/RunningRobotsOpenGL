#include "AbstractModel.h"

AbstractModel::AbstractModel()
{
}

AbstractModel::AbstractModel(ModelRenderer* renderer, glm::mat4& modelMatrix, LightInteractionProperties& materialProperties)
{
	this->_renderer = renderer;
	this->_modelCoordinates = modelMatrix;
	this->_materialProperties = materialProperties;
}

glm::mat4 & AbstractModel::getModelCoordinates()
{
	return _modelCoordinates;
}

const LightInteractionProperties & AbstractModel::getMaterialProperties()
{
	return _materialProperties;
}


AbstractModel::~AbstractModel()
{
}
