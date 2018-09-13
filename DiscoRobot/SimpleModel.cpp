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

void SimpleModel::render(const TransformationMatricesHandles& matricesHandles, const glm::mat4& M, const glm::mat4& V, const glm::mat4& P)
{
	this->_renderer->render(matricesHandles, M*_modelCoordinates, V, P);
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
