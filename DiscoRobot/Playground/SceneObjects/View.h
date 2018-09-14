#pragma once
#include <glm/glm.hpp>
class View
{
	glm::mat4* _view;
public:
	View();
	View(glm::mat4 &view);
	glm::mat4 &getView();
	~View();
};

