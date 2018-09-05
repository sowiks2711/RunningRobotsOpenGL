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

using namespace glm;

int main( void )
{
	ScreenRenderer screenRenderer = ScreenRenderer(1024, 868);
	Screen screen = Screen(screenRenderer);
	TransformationBuilder transformationBuilder = TransformationBuilder();
	RobotPartsFactory partsFactory = RobotPartsFactory();
	RobotFactory robotFactory = RobotFactory(partsFactory);

	glm::mat4 viewMatrix, projection;
	
	viewMatrix = Transform::lookAt(
		vec3(0, 0, -15),
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
	RobotModel* robot = robotFactory.createRobot();
	scene.addModel(robot);
	//rootanimation = transformationBuilder.scale(2).build();

	int i = 1;
	int step = 1;
	do {

		scene.clearScene();
		scene.render();
		screen.swapBuffers();
		//animation = animation * transformationBuilder.rotate(0.5, glm::vec3(1, 1, 1)).build();
		//rootanimation = rootanimation * transformationBuilder.translate(0, 0.001 * i,0).build();
		if ((i+80) % 160 == 0) step = -step;
		i += step;

	} // Check if the ESC key was pressed or the window was closed
	while( screen.escapeHasNotBeenPressed());
	glfwTerminate();
	return 0;
}

