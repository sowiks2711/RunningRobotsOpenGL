#pragma once
#include "ScreenRenderer.h"
class Screen
{
	ScreenRenderer _screenRenderer;
public:
	Screen();
	Screen(ScreenRenderer& screenRenderer);
	Screen(const Screen& screen);
	Screen& operator=(const Screen& screen);
	GLfloat getAspectRatio();
	void swapBuffers();
	void clear();
	bool escapeHasNotBeenPressed();
	~Screen();
};

