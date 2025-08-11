#ifndef SCENE_H
#define SCENE_H

#include "gameobj.hpp"
#include "tilemap.hpp"
#include <vector>

class Scene {

  public:
    TileMap scene_map;
    std::vector<GameObject *> scene_gameobjs;

    Scene(TileMap tm);

    void add_gameobj(GameObject *new_obj);

    void update_scene();
    void draw_scene() const;
};

class SceneManager {
  public:
    std::vector<Scene *> scenes;

    void add_scene(Scene *new_scene);
};

#endif // SCENE_H
