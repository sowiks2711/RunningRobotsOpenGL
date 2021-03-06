#include "HierarchicalModel.h"

HierarchicalModel::HierarchicalModel()
{
	_parentToMeTransformation = glm::mat4(1);
	_children = std::vector<HierarchicalModel*>();
}

HierarchicalModel::HierarchicalModel(SimpleModel* model): HierarchicalModel()
{
	_model = model;
	_transformation = model->getCurrentTransformation();
}

void HierarchicalModel::render(const TransformationMatricesHandles& matricesHandles, const glm::mat4 &M, const glm::mat4 &V, const glm::mat4 &P)
{
	_model->bindMaterialProperties(*_handles);
	//_transformation = parent->_transformation * parentToMeTranslation * animator * simpleMT

	glm::mat4 parentTransformation = _parent == nullptr ? glm::mat4(1) : _parent->getCurrentTransformation();
	_transformation = parentTransformation * _parentToMeTransformation ;
	_transformation = _transformation * (_animationMatrix == nullptr ? glm::mat4(1) : *_animationMatrix );

	_model->render(matricesHandles, _transformation , V,  P);

	for(HierarchicalModel* child : _children)
	{
		child->bindMaterialProperties(*_handles);
		child->render(matricesHandles, identity, V,  P);
	}
}

void HierarchicalModel::bindMaterialProperties(LightInteractionPropertiesHandles & handles)
{
	this->_handles = &handles;
}

glm::mat4& HierarchicalModel::getCurrentTransformation()
{
	return _transformation;
}

const LightInteractionProperties& HierarchicalModel::getMaterialProperties()
{
	return _model->getMaterialProperties();
}

void HierarchicalModel::addChild(HierarchicalModel& child, glm::mat4 & relativeTransformation)
{
	child.setRelativeTransformation(relativeTransformation);
	child.setParent(this);
	_children.push_back(&child);
}

void HierarchicalModel::setParent(HierarchicalModel * parent)
{
	this->_parent = parent;
}

void HierarchicalModel::setRelativeTransformation(glm::mat4 & relativeTransformation)
{
	_parentToMeTransformation = relativeTransformation;
}

void HierarchicalModel::setAnimationMatrix(glm::mat4 & animationTransformation)
{
	_animationMatrix = &animationTransformation;
}

HierarchicalModel::~HierarchicalModel()
{
}
