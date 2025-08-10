#include "scene.hpp"
#include <ctype.h>

Scene::Scene(TileMap tm) : scene_map(tm) {};

void Scene::add_gameobj(GameObject *new_obj) {
    scene_gameobjs.push_back(*new_obj);
}

void Scene::update_scene(){

    float dt = GetFrameTime();

    for(size_t i = 0; i < scene_gameobjs.size(); ++i){
	scene_gameobjs[i].update(dt);
    }

}

void Scene::draw_scene() const {

    for(size_t i = 0; i < scene_gameobjs.size(); ++i){
	scene_gameobjs[i].draw();
    }

}

void SceneManager::add_scene(Scene *new_scene){

    scenes.push_back(new_scene);

}
