#pragma once 
#include "AbstractModel.h"
#include "View.h"
#include "Projector.h"
#include "LightProperties.h"
#include "SceneRenderer.h"

class Scene
{
	View _view;
	Projector _projector;
	SceneRenderer _renderer;
	std::vector<glm::vec4> _lightPositions;
	std::vector<glm::vec4> _lightColors;
	std::vector<AbstractModel> _models;
public:
	Scene();
	Scene(View& view, Projector& projector, SceneRenderer& renderer);
	void addModel(const AbstractModel& model);
	void addLight(LightProperties light);
	void render();
	void clearScene();
	~Scene();
};

