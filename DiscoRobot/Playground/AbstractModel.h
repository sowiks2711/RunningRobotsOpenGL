#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <glm/glm.hpp>
#include "AbstractGeometry.h"
#include "ModelRenderer.h"
#include "LightInteractionProperties.h"
class AbstractModel
{
protected:
	glm::mat4 _modelCoordinates;
	ModelRenderer* _renderer;
	LightInteractionProperties _materialProperties;


public:
	AbstractModel();
	AbstractModel(ModelRenderer* renderer, glm::mat4& modelMatrix, LightInteractionProperties& materialProperties);
	virtual void render(const GLuint mvId, const glm::mat4& view, const GLuint pId, const glm::mat4 &P) = 0;
	virtual void bindMaterialProperties(LightInteractionPropertiesHandles& handles) = 0;
	glm::mat4 &getModelCoordinates();
	const LightInteractionProperties& getMaterialProperties();
	~AbstractModel();
};

