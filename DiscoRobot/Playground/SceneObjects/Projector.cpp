#include "Projector.h"



Projector::Projector()
{
}

Projector::Projector(glm::mat4& projection, Screen& screen)
{
	_projection = projection;
	_screen = screen;
}

void Projector::clearScreen()
{
	_screen.clear();
}

glm::mat4 & Projector::getProjection()
{
	return _projection;
}


Projector::~Projector()
{
}
