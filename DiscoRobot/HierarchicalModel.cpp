#include "HierarchicalModel.h"



HierarchicalModel::HierarchicalModel()
{
}

void HierarchicalModel::render(const GLuint mvId, const glm::mat4 &view, const GLuint pId, const glm::mat4 & P)
{
	_model->bindMaterialProperties(*_handles);
	//_transformation = animator * parentToMeTranslation * parent->_transformation
	_transformation = *_animationMatrix * _parentToMeTransformation;
	glm::mat4 parentTransformation = _parent == nullptr ? glm::mat4(1) : _parent->getCurrentTransformation();
	_transformation = _transformation * parentTransformation;

	_model->render(mvId, view * _transformation, pId, P);

	for(HierarchicalModel* child : _children)
	{
		child->bindMaterialProperties(*_handles);
		child->render(mvId, view, pId, P);
	}
}

void HierarchicalModel::bindMaterialProperties(LightInteractionPropertiesHandles & handles)
{
	this->_handles = &handles;
}

glm::mat4 HierarchicalModel::getCurrentTransformation()
{
	return _transformation;
}


HierarchicalModel::~HierarchicalModel()
{
}
