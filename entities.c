#include <raylib.h>

#include "entities.h"

#include <tgmath.h>

#include "constants.h"

void UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta)
{
    if (IsKeyDown(KEY_LEFT)) player->position.x -= PLAYER_HOR_SPD*delta;
    if (IsKeyDown(KEY_RIGHT)) player->position.x += PLAYER_HOR_SPD*delta;
    if (IsKeyDown(KEY_SPACE) && player->canJump)
    {
        player->speed = -PLAYER_JUMP_SPD;
        player->canJump = false;
        player->startingJumpHeight = player->position.y;
        player->isJumping = true;
    }
    if (IsKeyDown(KEY_SPACE) && player->isJumping) {
        player->speed = -PLAYER_JUMP_SPD;

        if (fabs(player->startingJumpHeight - player->position.y) > PLAYER_MAX_JUMP_HEIGHT) {
            player->isJumping = false;
        }
    }
    if (!IsKeyDown(KEY_SPACE) && player->isJumping) {
        player->isJumping = false;
    }

    bool hitObstacle = false;
    for (int i = 0; i < envItemsLength; i++)
    {
        EnvItem *ei = envItems + i;
        Vector2 *p = &(player->position);
        if (ei->blocking &&
            ei->rect.x <= p->x &&
            ei->rect.x + ei->rect.width >= p->x &&
            ei->rect.y >= p->y &&
            ei->rect.y <= p->y + player->speed*delta)
        {
            hitObstacle = true;
            player->speed = 0.0f;
            p->y = ei->rect.y;
            break;
        }
    }

    if (!hitObstacle)
    {
        player->position.y += player->speed*delta;
        player->speed = fmin(player->speed + G*delta, PLAYER_TERMINAL_VELOCITY);
        player->canJump = false;
    }
    else player->canJump = true;
}
