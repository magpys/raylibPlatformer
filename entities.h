#ifndef PLATFORMER_ENTITIES_H
#define PLATFORMER_ENTITIES_H
#include <raylib.h>

typedef struct Player {
    Vector2 position;
    float speed;
    bool canJump;
    bool isJumping;
    float startingJumpHeight;
} Player;

typedef struct EnvItem {
    Rectangle rect;
    int blocking;
    Color color;
} EnvItem;

void UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta);

#endif //PLATFORMER_ENTITIES_H