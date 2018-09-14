#include "Screen.h"

Screen::Screen()
{
}

Screen::Screen(ScreenRenderer& screenRenderer)
{
	_screenRenderer = screenRenderer;
}

Screen::Screen(const Screen& screen)
{
	_screenRenderer = screen._screenRenderer;
}

Screen& Screen::operator=(const Screen& screen)
{
	_screenRenderer = screen._screenRenderer;
	return *this;

}

GLfloat Screen::getAspectRatio()
{
	return _screenRenderer.getAspectRatio();
}

void Screen::swapBuffers()
{
	_screenRenderer.swapBuffers();
}

void Screen::clear()
{
	_screenRenderer.clearScreen();
}

bool Screen::escapeHasNotBeenPressed()
{
	return glfwGetKey(_screenRenderer.getWindowId(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(_screenRenderer.getWindowId()) == 0;
}


Screen::~Screen()
{
	
}
