#pragma once 
#include "..\SceneObjects\AbstractModel.h"
#include "..\SceneObjects\View.h"
#include "..\SceneObjects\Projector.h"
#include "..\POCOs\LightProperties.h"
#include "..\POCOs\TransformationMatricesHandles.h"
#include "..\POCOs\LightInteractionPropertiesHandles.h"
#include "..\POCOs\LightPropertiesHandles.h"
#include "..\..\ShaderLoader\Shader.hpp"

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
	LightInteractionPropertiesHandles& getMaterialPropertiesHandles();
	void bindLigths(glm::mat4& view, std::vector<glm::vec4>& lightPositions, std::vector<glm::vec4>& lightColors);
	void renderModel(AbstractModel& model, glm::mat4& view, glm::mat4& projection);
	void useDefaultShader();
	void bindSpotLightRotation(glm::mat4& spotlightRotation);
	SceneRenderer& operator=(SceneRenderer& other);
	~SceneRenderer();
};

