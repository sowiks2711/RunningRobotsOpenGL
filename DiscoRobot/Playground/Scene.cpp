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

void Scene::addModel(AbstractModel& model)
{
	_models.push_back(&model);
}

void Scene::addLight(LightProperties light)
{
	_lightPositions.push_back(light.position);
	_lightColors.push_back(light.color);
}

void Scene::render()
{
	_renderer.useDefaultShader();
	_renderer.bindLigths(_view.getView(), _lightPositions, _lightColors);

	for (AbstractModel* model : _models)
	{
		_renderer.bindColourProperties(model->getMaterialProperties());
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
