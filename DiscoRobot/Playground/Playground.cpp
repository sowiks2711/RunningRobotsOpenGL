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
#include "TransformationBuilder.h"
#include "CubeModelBuilder.h"
#include "SfereModelBuilder.h"

using namespace glm;

int main( void )
{
	ScreenRenderer screenRenderer = ScreenRenderer(1024, 868);
	Screen screen = Screen(screenRenderer);
	TransformationBuilder transformationBuilder = TransformationBuilder();
	SfereModelBuilder sfereBuilder = SfereModelBuilder();
	CubeModelBuilder cubeBuilder = CubeModelBuilder();


	glm::mat4 viewMatrix, projection, cubeTransformation, sfereTransformation;
	cubeTransformation = transformationBuilder
		.scale(0.8f, 1.2f, 0.8f)
		//.rotate(45.0f, glm::vec3(1, 1, 0))
		.translate(0, 0, 1)
		.translate(0, -0.2, 0)
		.build();

	AbstractModel* cubeModel = &cubeBuilder
		.setDiffuse(0, 0.61, 0)
		.setEmission(0.1, 0, 0)
		.setShininess(400)
		.setSpecular(1, 1, 1)
		.setTransformation(cubeTransformation)
		.build();

	AbstractModel* cubeModel2 = &cubeBuilder
		.setDiffuse(0, 0.61, 0)
		.setEmission(0.1, 0, 0)
		.setShininess(400)
		.setSpecular(1, 1, 1)
		.setTransformation(
			transformationBuilder.scale(0.3, 0.5, 0.3).translate(0.75,0.2,1).build()
		)
		.build();

	sfereTransformation = transformationBuilder
		.scale(0.03f, 0.02f, 0.02f)
		//.rotate(45.0f, glm::vec3(1, 1, 0))
		.translate(0, 0, 1)
		.translate(0, 1, 0)
		.build();

	AbstractModel* sfereModel = &sfereBuilder
		.setEmission(0.8, 0.1, 0.5)
		.setDiffuse(0.2, 0.41, 0.11)
		.setShininess(400)
		.setSpecular(1, 1, 1)
		.setTransformation(sfereTransformation)
		.build();

	AbstractModel* sfereModel2 = &sfereBuilder
		.setEmission(0.1, 0.1, 0.1)
		.setDiffuse(0.2, 0.41, 0.11)
		.setShininess(400)
		.setSpecular(1, 1, 1)
		.setTransformation(
			transformationBuilder.scale(0.10).translate(1,-1,12).build()
		)
		.build();
	
	viewMatrix = Transform::lookAt(
		vec3(0, 0, -1),
		vec3(0, 0, 0),
		vec3(0, 1, 0)
	);
	View view = View(viewMatrix);
	projection = transformationBuilder
		.perspective(
			90,
			screen.getAspectRatio(),
			0.1f,
			100.0f
		).build();

	Projector projector = Projector(projection, screen);
	SceneRenderer sceneRenderer = SceneRenderer();

	LightProperties l1 = { glm::vec4(1,1,-11,1), glm::vec4(1,0,0,1) };
	LightProperties l2 = { glm::vec4(-1,1,-1,1), glm::vec4(0,1,0,1) };
	LightProperties l3 = { glm::vec4(1,-1,1,1), glm::vec4(0,0,1,1) };
	LightProperties l4 = { glm::vec4(-1,-1,1,1), glm::vec4(1,1,0,1) };


	Scene scene = Scene(view, projector, sceneRenderer);
	scene.addLight(l1);
	scene.addLight(l2);
	scene.addLight(l3);
	scene.addLight(l4);
	scene.addModel(*sfereModel);
	scene.addModel(*cubeModel);
	//scene.addModel(*sfereModel2);
	scene.addModel(*cubeModel2);

	do {
		scene.clearScene();
		scene.render();
		screen.swapBuffers();
	} // Check if the ESC key was pressed or the window was closed
	while( screen.escapeHasNotBeenPressed());
	glfwTerminate();
	return 0;
}

