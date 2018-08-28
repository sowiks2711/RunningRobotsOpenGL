#pragma once
#include "Screen.h"
#include <glm/glm.hpp>

class Projector
{
	Screen _screen;
	glm::mat4 _projection;
public:
	Projector();
	Projector(glm::mat4 &projection, Screen &screen);
	void clearScreen();
	glm::mat4 &getProjection();
	~Projector();
};

