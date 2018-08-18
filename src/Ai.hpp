//
// Created by msmith on 8/17/18.
//

#ifndef TCODRL_AI_HPP
#define TCODRL_AI_HPP

class Ai {
public:
    virtual void update(Actor *owner) = 0;
};

class PlayerAi : public Ai {
public:
    void update(Actor *owner);

protected:
    bool moveOrAttack(Actor *owner, int target_x, int target_y);
};

class MonsterAi : public Ai {
    // how many turns the monster chases the player after losing his sight
    static const int TRACKING_TURNS = 3;

public:
    void update(Actor *owner);

protected:
    int moveCount;

    void moveOrAttack(Actor *owner, int target_x, int target_y);
};

#endif //TCODRL_AI_HPP
