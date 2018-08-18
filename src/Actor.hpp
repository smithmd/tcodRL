//
// Created by msmith on 2/21/16.
//

#ifndef TCODRL_ACTOR_HPP
#define TCODRL_ACTOR_HPP

class Actor {
public:
    int x, y; // position on map
    int ch; // ascii code
    TCODColor col;
    const char *name; // actor's name
    bool blocks; // can we walk on this actor?
    Attacker *attacker; // something that deals damage
    Destructible *destructible; // something that can be damaged
    Ai *ai; // something self updating

    Actor(int x, int y, int ch, const char *name, const TCODColor &col);

    void render() const;

    void update();

    bool moveOrAttack(int x, int y);
};


#endif //TCODRL_ACTOR_H
