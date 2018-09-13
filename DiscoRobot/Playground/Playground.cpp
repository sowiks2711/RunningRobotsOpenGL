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
#include "..\HierarchicalModel.h"
#include "..\RobotPartsFactory.h"
#include "..\RobotFactory.h"
#include "..\ViewAnimator.h"

using namespace glm;

int main( void )
{
	ScreenRenderer screenRenderer = ScreenRenderer(1024, 868);
	Screen screen = Screen(screenRenderer);
	TransformationBuilder transformationBuilder = TransformationBuilder();
	RobotPartsFactory partsFactory = RobotPartsFactory();
	RobotFactory robotFactory = RobotFactory(partsFactory);

	glm::mat4 viewMatrix, projection, spotlightRotation;
	glm::vec3 eye = vec3(0, 10, -45);
	glm::vec3 up = vec3(0, 1, 0);
	spotlightRotation = transformationBuilder.rotateOverY(5).build();

	viewMatrix = Transform::lookAt(
		eye,
		vec3(0, 0, 0),
		up
	);
	projection = transformationBuilder
		.perspective(
			90,
			screen.getAspectRatio(),
			0.1f,
			1000.0f
		).build();

	Projector projector = Projector(projection, screen);
	SceneRenderer sceneRenderer = SceneRenderer();

	LightProperties l1 = { glm::vec4(1,1,-11,1), glm::vec4(1,0,0,1) };
	LightProperties l2 = { glm::vec4(-1,1,-1,1), glm::vec4(0,0.1,0,1) };
	LightProperties l3 = { glm::vec4(1,-1,1,1), glm::vec4(0,0,1,1) };
	LightProperties l4 = { glm::vec4(-1,-1,1,1), glm::vec4(1,1,0,1) };

	glm::mat4 secondaryActorTransformation = transformationBuilder.translate(100, 0, 45).build();
	RobotModel* robot1 = robotFactory.createRobot(secondaryActorTransformation);
	glm::mat4 mainActorTransformation = transformationBuilder.translate(95, 0, 45).build();
	RobotModel* robot2 = robotFactory.createRobot(mainActorTransformation );
	HierarchicalModel* floor = robotFactory.createFloor();

	ViewAnimator viewAnimator = ViewAnimator(viewMatrix, eye, up, secondaryActorTransformation);
	View view = View(viewMatrix);

	Scene scene = Scene(view, projector, sceneRenderer);
	scene.adddSpotlightRotation(spotlightRotation);
	scene.addLight(l1);
	scene.addLight(l2);
	scene.addLight(l3);
	scene.addLight(l4);
	
	scene.addModel(robot1);
	scene.addModel(robot2);
	scene.addModel(floor);

	do {

		scene.clearScene();
		scene.render();
		screen.swapBuffers();
		viewAnimator.makeNextStep();
		spotlightRotation = spotlightRotation * transformationBuilder.rotateOverY(0.5).build();

	} // Check if the ESC key was pressed or the window was closed
	while( screen.escapeHasNotBeenPressed());
	glfwTerminate();
	return 0;
}

