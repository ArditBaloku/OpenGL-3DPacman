#pragma once
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "model.h"
#include "level.h"
#include "camera.h"
#include "ghost.h"

enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_PAUSED,
    GAME_WIN,
    GAME_LOSS
};

class Game {
  public:
    void init();
    void update(float dt);
    void processInput(float dt);
    void render(Shader& shader);
    Camera camera = Camera(glm::vec3(-1.0f, 0.0f, 13.0f));
    GameState state;
  private:
    std::vector<Model> characters;
    std::vector<Ghost> ghosts;
    Level level;
    
};

#endif