#pragma once 
#include "AbstractModel.h"
#include "View.h"
#include "Projector.h"
#include "LightProperties.h"
#include "TransformationMatricesHandles.h"
#include "LightInteractionPropertiesHandles.h"
#include "LightPropertiesHandles.h"

class SceneRenderer
{
	const GLuint MAXIMUM_LIGHTS_NR = 20;
	TransformationMatricesHandles matricesIds;
	LightInteractionPropertiesHandles materialPropertiesIds;
	LightPropertiesHandles lightsPropertiesIds;
	GLuint programId;
	std::vector<glm::vec4> lightPositionsTransformed;
public:
	SceneRenderer();
	void bindColourProperties(const LightInteractionProperties& properties);
	void bindLigths(glm::mat4& view, std::vector<glm::vec4>& lightPositions, std::vector<glm::vec4>& lightColors);
	void renderModel(AbstractModel& model, glm::mat4& view, glm::mat4& projection);
	void useDefaultShader();
	SceneRenderer& operator=(SceneRenderer& other);
	~SceneRenderer();
};

