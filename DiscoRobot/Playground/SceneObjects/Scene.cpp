#include "Scene.h"


Scene::Scene()
{

}

Scene::Scene(View& view, Projector& projector, SceneRenderer& renderer)
{
	this->_view = view;
	this->_projector = projector;
	this->_renderer = renderer;
}

void Scene::addModel(AbstractModel* model)
{
	_models.push_back(model);
}

void Scene::addLight(LightProperties light)
{
	_lightPositions.push_back(light.position);
	_lightColors.push_back(light.color);
}

void Scene::adddSpotlightRotation(glm::mat4 & spotlightRotation)
{
	_spotlightRotation = &spotlightRotation;
}

void Scene::render()
{
	_renderer.useDefaultShader();
	_renderer.bindLigths(_view.getView(), _lightPositions, _lightColors);
	_renderer.bindSpotLightRotation(_spotlightRotation == nullptr ? _identity : *_spotlightRotation);
	for (AbstractModel* model : _models)
	{
		_renderer.renderModel(*model, _view.getView(), _projector.getProjection());
	}
}

void Scene::clearScene()
{
	_projector.clearScreen();
}


Scene::~Scene()
{
}
