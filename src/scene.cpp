#include "scene.hpp"

Scene::Scene(TileMap tm) : scene_map(tm) {

    camera = {0};
    camera.target = {0, 0};
    camera.offset = {GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    camera_lerp = 0.3f;
};

void Scene::add_gameobj(GameObject *new_obj) {
    scene_gameobjs.push_back(new_obj);
}

Camera2D *Scene::get_camera() {
    return &camera;
}

TileMap *Scene::get_tilemap() {
    return &scene_map;
}

void Scene::draw_scene() const {

    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode2D(camera);

    scene_map.draw();

    for (size_t i = 0; i < scene_gameobjs.size(); ++i) {
        scene_gameobjs[i]->draw();
    }
}

void Scene::update_scene() {

    float dt = GetFrameTime();

    for (size_t i = 0; i < scene_gameobjs.size(); ++i) {
        scene_gameobjs[i]->update(dt);
    }

    EndMode2D();
    EndDrawing();
}

void SceneManager::add_scene(Scene *new_scene) {

    scenes.push_back(new_scene);
}
