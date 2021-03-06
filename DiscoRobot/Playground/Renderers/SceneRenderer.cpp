#include "SceneRenderer.h"



SceneRenderer::SceneRenderer()
{
	programId = LoadShaders("SimpleVertexShader.vert", "SimpleFragmentShader.frag");
	matricesIds.modelId = glGetUniformLocation(programId, "M");
	matricesIds.viewId = glGetUniformLocation(programId, "V");
	matricesIds.projectionId = glGetUniformLocation(programId, "P");
	matricesIds.spotlightRotationId = glGetUniformLocation(programId, "SPOT_LIGHT_ROTATION");
	materialPropertiesIds.emissionId = glGetUniformLocation(programId, "_emission");
	materialPropertiesIds.diffuseId = glGetUniformLocation(programId, "_diffuse");
	materialPropertiesIds.specularId = glGetUniformLocation(programId, "_specular");
	materialPropertiesIds.shininessId = glGetUniformLocation(programId, "_shininess");
	lightsPropertiesIds.positionsId = glGetUniformLocation(programId, "_lightsPositions");
	lightsPropertiesIds.colorsId = glGetUniformLocation(programId, "_lightsColors");
	lightsPropertiesIds.lightsUsedId = glGetUniformLocation(programId, "_lightsUsed");
}

void SceneRenderer::renderModel(AbstractModel& model, glm::mat4& view, glm::mat4& projection)
{
	model.bindMaterialProperties(getMaterialPropertiesHandles());
	model.render(matricesIds, model.getCurrentTransformation(), view, projection);
}

LightInteractionPropertiesHandles& SceneRenderer::getMaterialPropertiesHandles()
{
	return materialPropertiesIds;
}
void SceneRenderer::bindLigths(glm::mat4& view, std::vector<glm::vec4>& lightPositions, std::vector<glm::vec4>& lightColors)
{
	lightPositionsTransformed.clear();
	for (glm::vec4 lightPosition : lightPositions)
	{
		lightPositionsTransformed.push_back(view * lightPosition);
	}
	glUniform4fv(lightsPropertiesIds.positionsId, lightPositionsTransformed.size(), &lightPositionsTransformed[0].x);
	glUniform4fv(lightsPropertiesIds.colorsId, lightColors.size(), &lightColors[0].x);
	glUniform1i(lightsPropertiesIds.lightsUsedId, lightPositionsTransformed.size());
	
}
void SceneRenderer::useDefaultShader()
{
	glUseProgram(programId);
}

void SceneRenderer::bindSpotLightRotation(glm::mat4 & spotlightRotation)
{
	glUniformMatrix4fv(matricesIds.spotlightRotationId, 1, GL_FALSE, &spotlightRotation[0][0]);
}



SceneRenderer & SceneRenderer::operator=(SceneRenderer & other)
{
	this->matricesIds = other.matricesIds;
	this->materialPropertiesIds = other.materialPropertiesIds;
	this->lightsPropertiesIds = other.lightsPropertiesIds;
	this->programId = other.programId;
	this->lightPositionsTransformed = other.lightPositionsTransformed;
	return *this;
}


SceneRenderer::~SceneRenderer()
{
	glDeleteProgram(programId);
}
