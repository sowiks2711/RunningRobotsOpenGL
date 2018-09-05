#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <glm/glm.hpp>
#include "AbstractGeometry.h"
#include "ModelRenderer.h"
#include "LightInteractionProperties.h"
class AbstractModel
{

public:
	AbstractModel();
	virtual void render(const GLuint mvId, const glm::mat4& view, const GLuint pId, const glm::mat4 &P) = 0;
	virtual void bindMaterialProperties(LightInteractionPropertiesHandles& handles) = 0;
	virtual glm::mat4 &getModelCoordinates() = 0;
	virtual const LightInteractionProperties& getMaterialProperties() = 0;
	~AbstractModel();
};

