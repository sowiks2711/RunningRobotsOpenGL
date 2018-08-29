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

void AbstractModel::render(const GLuint mvId, const glm::mat4 &MV, const GLuint pId, const glm::mat4 &P) 
{
	this->_renderer->render(mvId, MV, pId, P);
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
