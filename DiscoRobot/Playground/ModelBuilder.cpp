#include "ModelBuilder.h"



ModelBuilder::ModelBuilder()
{
	_properties.shininess = 50;
	_properties.diffuse = glm::vec4(0.5, 0.7, 0.6, 1);
	_properties.emission = glm::vec4(0.2, 0.2, 0.1, 1);
	_properties.specular = glm::vec4(1, 1, 1, 1);
	_transformation = glm::mat4(1);
	_modelTrackingList.clear();
}

ModelBuilder & ModelBuilder::setShininess(GLfloat shininess)
{
	_properties.shininess = shininess;
	return *this;
}

ModelBuilder & ModelBuilder::setDiffuse(GLfloat r, GLfloat g, GLfloat b)
{
	_properties.diffuse = glm::vec4(r, g, b, 1);
	return *this;
}

ModelBuilder & ModelBuilder::setEmission(GLfloat r, GLfloat g, GLfloat b)
{
	_properties.emission = glm::vec4(r, g, b, 1);
	return *this;
}

ModelBuilder & ModelBuilder::setSpecular(GLfloat r, GLfloat g, GLfloat b)
{
	_properties.specular = glm::vec4(r, g, b, 1);
	return *this;
}

ModelBuilder & ModelBuilder::setTransformation(glm::mat4 transformation)
{
	_transformation = transformation;
	return *this;
}

AbstractModel& ModelBuilder::build()
{
	AbstractModel* model = new AbstractModel(getModelRenderer(), _transformation, _properties);
	_modelTrackingList.push_back(model);
	return *model;
}


ModelBuilder::~ModelBuilder()
{
	for (AbstractModel* modelPointer : _modelTrackingList)
		delete modelPointer;
}
