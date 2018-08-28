#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include "ScreenRenderer.h"
#include <exception>
#define GLEW_INIT_FAILED -2
#define OPENNING_WINDOW_FAILED -3
#define GLFW_INIT_FAILED -4

ScreenRenderer::ScreenRenderer()
{
}



ScreenRenderer::ScreenRenderer(int w, int h)
{
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
		throw GLFW_INIT_FAILED;
	}
	_w = w;
	_h = h;
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	windowId = glfwCreateWindow( w, h, "Playground", NULL, NULL);
	glfwMakeContextCurrent(windowId);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		throw GLEW_INIT_FAILED;
	}
	if( windowId == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		getchar();
		glfwTerminate();
		throw OPENNING_WINDOW_FAILED;
	}
	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(windowId, GLFW_STICKY_KEYS, GL_TRUE);
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);
	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
}

ScreenRenderer & ScreenRenderer::operator=(const ScreenRenderer & other)
{
	_h = other._h;
	_w = other._w;
	windowId = other.windowId;
	return *this;
}

ScreenRenderer::ScreenRenderer(const ScreenRenderer & other)
{
	_w = other._w;
	_h = other._h;
	windowId = other.windowId;
}

GLfloat ScreenRenderer::getAspectRatio()
{
	return _w/(GLfloat)_h;
}

void ScreenRenderer::clearScreen()
{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void ScreenRenderer::swapBuffers()
{
	glfwSwapBuffers(windowId);
	glfwPollEvents();
}

GLFWwindow * ScreenRenderer::getWindowId()
{
	return windowId;
}

ScreenRenderer::~ScreenRenderer()
{
}
