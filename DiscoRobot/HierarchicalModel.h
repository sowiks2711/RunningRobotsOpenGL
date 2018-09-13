#pragma once
#include "Playground\AbstractModel.h"
#include "SimpleModel.h"
#include "Playground\TransformationMatricesHandles.h"

class HierarchicalModel :
	public AbstractModel
{
	glm::mat4 identity = glm::mat4(1);
	HierarchicalModel* _parent;
	glm::mat4 _transformation;
	SimpleModel* _model;
	glm::mat4* _animationMatrix;
	glm::mat4 _parentToMeTransformation;
	std::vector<HierarchicalModel*> _children;
	LightInteractionPropertiesHandles* _handles;
public:
	HierarchicalModel();
	HierarchicalModel(SimpleModel* model);
	virtual void render(const TransformationMatricesHandles& matricesHandles, const glm::mat4 &M, const glm::mat4 &V, const glm::mat4 &P);
	virtual void bindMaterialProperties(LightInteractionPropertiesHandles& handles);
	virtual glm::mat4& getCurrentTransformation();
	virtual const LightInteractionProperties& getMaterialProperties();
	void addChild(HierarchicalModel& child, glm::mat4& relativeTransformation);
	void setParent(HierarchicalModel* parent);
	void setRelativeTransformation(glm::mat4& relativeTransformation);
	void setAnimationMatrix(glm::mat4& animationTransformation);
	~HierarchicalModel();
};

