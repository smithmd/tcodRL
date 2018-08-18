//
// Created by msmith on 8/17/18.
//

#ifndef TCODRL_ATTACKER_HPP
#define TCODRL_ATTACKER_HPP

class Attacker {
public:
    float power; // hit points given

    Attacker(float power);
    void attack(Actor *owner, Actor *target);
};


#endif //TCODRL_ATTACKER_HPP
