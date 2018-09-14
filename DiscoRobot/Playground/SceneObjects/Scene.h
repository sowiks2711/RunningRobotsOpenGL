#pragma once 
#include "AbstractModel.h"
#include "View.h"
#include "Projector.h"
#include "..\POCOs\LightProperties.h"
#include "..\Renderers\SceneRenderer.h"

class Scene
{
	View _view;
	Projector _projector;
	SceneRenderer _renderer;
	std::vector<glm::vec4> _lightPositions;
	std::vector<glm::vec4> _lightColors;
	glm::mat4* _spotlightRotation;
	glm::mat4 _identity = glm::mat4(1);
	std::vector<AbstractModel*> _models;
public:
	Scene();
	Scene(View& view, Projector& projector, SceneRenderer& renderer);
	void addModel(AbstractModel* model);
	void addLight(LightProperties light);
	void adddSpotlightRotation(glm::mat4& spotlightRotation);
	void render();
	void clearScene();
	~Scene();
};

