#pragma once
#include "AbstractModel.h"
#include <glm\glm.hpp>

class ModelBuilder
{
	LightInteractionProperties _properties;
	glm::mat4 _transformation;
	std::vector<AbstractModel*> _modelTrackingList;
protected:
	virtual ModelRenderer* getModelRenderer() = 0;
public:
	ModelBuilder();
	ModelBuilder& setShininess(GLfloat shininess);
	ModelBuilder& setDiffuse(GLfloat r, GLfloat g, GLfloat b);
	ModelBuilder& setEmission(GLfloat r, GLfloat g, GLfloat b);
	ModelBuilder& setSpecular(GLfloat r, GLfloat g, GLfloat b);
	ModelBuilder& setTransformation(glm::mat4 transformation);
	AbstractModel& build();
	~ModelBuilder();
};

