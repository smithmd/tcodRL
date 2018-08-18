//
// Created by msmith on 8/17/18.
//

#include "main.hpp"

#include <stdio.h>
#include <math.h>

void PlayerAi::update(Actor *owner) {
    if (owner->destructible && owner->destructible->isDead()) {
        return;
    }

    int dx = 0, dy = 0;
    switch (engine.lastKey.vk) {
        case TCODK_UP:
            dy = -1;
            break;
        case TCODK_DOWN:
            dy = 1;
            break;
        case TCODK_LEFT:
            dx = -1;
            break;
        case TCODK_RIGHT:
            dx = 1;
            break;
        default:
            break;
    }

    if (dx != 0 || dy != 0) {
        engine.gameStatus = Engine::NEW_TURN;
        if (moveOrAttack(owner, owner->x + dx, owner->y + dy)) {
            engine.map->computeFov();
        }
    }
}

bool PlayerAi::moveOrAttack(Actor *owner, int target_x, int target_y) {
    if (engine.map->isWall(target_x, target_y)) {
        return false;
    }
    // look for living actors to attack
    for (auto actor : engine.actors) {
        if (actor->destructible && !actor->destructible->isDead() && actor->x == target_x && actor->y == target_y) {
            owner->attacker->attack(owner, actor);
            return false;
        }
    }

    // look for corpses
    for (auto actor : engine.actors) {
        if (actor->destructible && actor->destructible->isDead() && actor->x == target_x && actor->y == target_y) {
            printf("There's a %s here\n", actor->name);
        }
    }

    owner->x = target_x;
    owner->y = target_y;
    return true;
}

void MonsterAi::update(Actor *owner) {
    if (owner->destructible && owner->destructible->isDead()) {
        return;
    }

    if (engine.map->isInFov(owner->x, owner->y)) {
        // we can see the player. move towards him
        moveCount = TRACKING_TURNS;
    } else {
        moveCount--;
    }

    if (moveCount > 0) {
        moveOrAttack(owner, engine.player->x, engine.player->y);
    }
}

void MonsterAi::moveOrAttack(Actor *owner, int target_x, int target_y) {
    int dx = target_x - owner->x;
    int dy = target_y - owner->y;
    int step_dx = dx > 0 ? 1 : -1;
    int step_dy = dy > 0 ? 1 : -1;
    float distance = sqrtf(dx * dx + dy * dy);

    if (distance >= 2) {
        dx = (int) (round(dx / distance));
        dy = (int) (round(dy / distance));

        if (engine.map->canWalk(owner->x + dx, owner->y + dy)) {
            owner->x += dx;
            owner->y += dy;
        } else if (engine.map->canWalk(owner->x + step_dx, owner->y)) {
            owner->x += step_dx;
        } else if (engine.map->canWalk(owner->x, owner->y + step_dy)) {
            owner->y += step_dy;
        }
    } else if (owner->attacker) {
        owner->attacker->attack(owner, engine.player);
    }
}
