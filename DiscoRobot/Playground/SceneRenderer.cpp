#include "SceneRenderer.h"
#include "..\ShaderLoader\Shader.hpp"



SceneRenderer::SceneRenderer()
{
	programId = LoadShaders("SimpleVertexShader.vert", "SimpleFragmentShader.frag");
	matricesIds.modelViewId = glGetUniformLocation(programId, "MV");
	matricesIds.projectionId = glGetUniformLocation(programId, "P");
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
	glm::mat4 mv = view * model.getModelCoordinates();
	model.render(matricesIds.modelViewId, mv, matricesIds.projectionId, projection);
}

void SceneRenderer::bindColourProperties(const LightInteractionProperties& properties)
{
	glUniform1f(materialPropertiesIds.shininessId, properties.shininess);
	glUniform4fv(materialPropertiesIds.emissionId, 1, &properties.emission.x);
	glUniform4fv(materialPropertiesIds.diffuseId, 1, &properties.diffuse.x);
	glUniform4fv(materialPropertiesIds.specularId, 1, &properties.specular.x);
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