#pragma once
#include ".\Playground\AbstractModel.h"
#include "HierarchicalModel.h"
#include "RobotAnimator.h"

class RobotModel :
	public AbstractModel
	//TODO: Extract concrete model class from AbstractModel 
{
	HierarchicalModel* _modelRoot;
	RobotAnimator* _animator;
public:
	RobotModel();
	RobotModel(HierarchicalModel* modelRoot, RobotAnimator* animator);
	virtual void render(const GLuint mvId, const glm::mat4& view, const GLuint pId, const glm::mat4 &P);
	virtual void bindMaterialProperties(LightInteractionPropertiesHandles& handles) = 0;
	~RobotModel();
};

