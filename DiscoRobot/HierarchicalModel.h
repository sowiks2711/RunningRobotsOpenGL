#pragma once
#include "Playground\AbstractModel.h"
#include "SimpleModel.h"
class HierarchicalModel :
	public AbstractModel
{
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
	virtual void render(const GLuint mvId, const glm::mat4 &MV, const GLuint pId, const glm::mat4 &P);
	virtual void bindMaterialProperties(LightInteractionPropertiesHandles& handles);
	glm::mat4 getCurrentTransformation();
	void addChild(HierarchicalModel& child, glm::mat4& relativeTransformation);
	void setParent(HierarchicalModel* parent);
	void setRelativeTransformation(glm::mat4& relativeTransformation);
	void setAnimationMatrix(glm::mat4& animationTransformation);
	~HierarchicalModel();
};

