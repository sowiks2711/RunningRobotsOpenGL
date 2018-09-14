#include "RobotModel.h"



RobotModel::RobotModel()
{
}

RobotModel::RobotModel(HierarchicalModel* modelRoot, RobotAnimator* animator)
{
	_modelRoot = modelRoot;
	_animator = animator;
}

void RobotModel::setStartingTranslation(glm::mat4& translation)
{
	_modelRoot->setAnimationMatrix(translation);
}

void RobotModel::render(const TransformationMatricesHandles& matricesHandles, const glm::mat4& M, const glm::mat4& V, const glm::mat4 &P)
{
	_modelRoot->render(matricesHandles, M, V, P);
	_animator->makeAnimationStep();
}

void RobotModel::bindMaterialProperties(LightInteractionPropertiesHandles & handles)
{
	_modelRoot->bindMaterialProperties(handles);
}

glm::mat4 & RobotModel::getCurrentTransformation()
{
	return _modelRoot->getCurrentTransformation();
}

const LightInteractionProperties & RobotModel::getMaterialProperties()
{
	return _modelRoot->getMaterialProperties();
}


RobotModel::~RobotModel()
{
}
