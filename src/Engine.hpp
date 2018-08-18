//
// Created by msmith on 2/22/16.
//

#ifndef TCODRL_ENGINE_H
#define TCODRL_ENGINE_H

class Engine {
public:
    enum GameStatus {
        STARTUP,
        IDLE,
        NEW_TURN,
        VICTORY,
        DEFEAT
    } gameStatus;

    TCODList<Actor *> actors;
    Actor *player;
    Map *map;
    int fovRadius;
    int screenWidth;
    int screenHeight;
    TCOD_key_t lastKey;

    Engine(int screenWidth, int screenHeight);
    ~Engine();
    void update();
    void render();
    void sendToBack(Actor *actor);
};

extern Engine engine;

#endif //TCODRL_ENGINE_H
