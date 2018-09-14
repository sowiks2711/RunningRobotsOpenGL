#pragma once
#include "AbstractModel.h"
#include "HierarchicalModel.h"
#include "..\Animation\RobotAnimator.h"
#include "..\POCOs\TransformationMatricesHandles.h"

class RobotModel :
	public AbstractModel
{
	HierarchicalModel* _modelRoot;
	RobotAnimator* _animator;
public:
	RobotModel();
	RobotModel(HierarchicalModel* modelRoot, RobotAnimator* animator);
	void setStartingTranslation(glm::mat4& translation);
	virtual void render(const TransformationMatricesHandles& matricesHandles, const glm::mat4& M, const glm::mat4& V, const glm::mat4 &P);
	virtual void bindMaterialProperties(LightInteractionPropertiesHandles& handles);
	virtual glm::mat4& getCurrentTransformation();
	virtual const LightInteractionProperties& getMaterialProperties();
	~RobotModel();
};

