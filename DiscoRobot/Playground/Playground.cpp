#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../ShaderLoader/shader.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

#include "Cube.h"
#include "Sfere.h"
#include "CubeRenderer.h"
#include "SfereRenderer.h"
#include "AbstractModel.h"
#include "Screen.h"
#include "View.h"
#include "Projector.h"
#include "SceneRenderer.h"
#include "Scene.h"
#include "Transform.h"

using namespace glm;

int main( void )
{
	// Initialise GLFW
	ScreenRenderer screenRenderer = ScreenRenderer(1024, 868);
	Screen screen = Screen(screenRenderer);
	Cube cube = Cube();
	Sfere sfere = Sfere(20, 50, 50);
	CubeRenderer cubeRenderer = CubeRenderer(cube);
	SfereRenderer sfereRenderer = SfereRenderer(sfere);

	glm::mat4 cubetranslation, sfereTranslation, rotation, scaling, scaling2, viewMatrix, projection, cubemodel, sferemodel, trianglemodel;
	glm::vec3 rotationAxis(1,1,0);
	rotation = Transform::rotate(45.0f, rotationAxis);
	scaling = Transform::scale(0.15f, 0.15f, 0.15f);
	scaling2 = Transform::scale(0.5f, 0.5f, 0.5f);
	cubetranslation = Transform::translate(0, 0, 1)* Transform::translate(1, 0, 0);
	sfereTranslation = Transform::translate(0, 0, 5)* Transform::translate(-1.5, 0, 0);
	cubemodel = cubetranslation * rotation * scaling2;
	viewMatrix = Transform::lookAt(
		vec3(0, 0, -1),
		vec3(0, 0, 0),
		vec3(0, 1, 0)
	);
	View view = View(viewMatrix);
	float FoV = 100 * M_PI/180;
	projection = Transform::perspective(FoV,
		screen.getAspectRatio(),
		0.1f,
		100.0f
	);
	Projector projector = Projector(projection, screen);
	SceneRenderer sceneRenderer = SceneRenderer();
	LightInteractionProperties cubeProperties = LightInteractionProperties();
	cubeProperties.emission = glm::vec4(0.1, 0, 0, 1);
	cubeProperties.diffuse = glm::vec4(0, 0.61, 0, 1);
	cubeProperties.shininess = 400;
	cubeProperties.specular = glm::vec4(1, 1, 1, 1);

	AbstractModel cubeModel = AbstractModel(cubeRenderer, cubemodel, cubeProperties);
	sferemodel = sfereTranslation * rotation * scaling;
	//AbstractModel cubeModel2 = AbstractModel(cube, cubeRenderer, cubemodel2);
	LightInteractionProperties sfereProperties = LightInteractionProperties();
	sfereProperties.emission = glm::vec4(0.1, 0.1, 0.1, 1);
	sfereProperties.diffuse = glm::vec4(0.2, 0.41, 0.11, 1);
	sfereProperties.shininess = 400;
	sfereProperties.specular = glm::vec4(1, 1, 1, 1);
	AbstractModel sfereModel = AbstractModel(sfereRenderer, sferemodel, sfereProperties);
	LightProperties l1 = { glm::vec4(1,1,-11,1), glm::vec4(1,0,0,1) };
	LightProperties l2 = { glm::vec4(-1,1,-1,1), glm::vec4(0,1,0,1) };
	LightProperties l3 = { glm::vec4(1,-1,1,1), glm::vec4(0,0,1,1) };
	LightProperties l4 = { glm::vec4(-1,-1,1,1), glm::vec4(1,1,0,1) };
	Scene scene = Scene(view, projector, sceneRenderer);
	scene.addLight(l1);
	scene.addLight(l2);
	scene.addLight(l3);
	scene.addLight(l4);
	scene.addModel(sfereModel);
	scene.addModel(cubeModel);

	do {
		scene.clearScene();
		scene.render();
		screen.swapBuffers();
	} // Check if the ESC key was pressed or the window was closed
	while( screen.escapeHasNotBeenPressed());
	glfwTerminate();
	return 0;
}
