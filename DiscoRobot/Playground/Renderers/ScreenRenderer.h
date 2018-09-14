#pragma once
#include <GLFW/glfw3.h>

class ScreenRenderer
{
	int _h;
	int _w;
	GLFWwindow* windowId;

public:
	ScreenRenderer();
	ScreenRenderer(int w, int h);
	ScreenRenderer& operator=(const ScreenRenderer& other);
	ScreenRenderer(const ScreenRenderer& other);
	GLfloat getAspectRatio();
	void clearScreen();
	void swapBuffers();
	GLFWwindow* getWindowId();
	~ScreenRenderer();
};

