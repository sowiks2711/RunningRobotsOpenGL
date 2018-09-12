#include "View.h"



View::View()
{
}

View::View(glm::mat4 & view)
{
	this->_view = &view;
}

glm::mat4 &View::getView()
{
	return *_view;
}


View::~View()
{
}
