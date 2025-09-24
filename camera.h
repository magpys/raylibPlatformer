//
// Created by Daniel Griffiths on 24/09/2025.
//

#ifndef PLATFORMER_CAMERA_H
#define PLATFORMER_CAMERA_H
#include <raylib.h>

#include "entities.h"

void UpdateCameraCenterInsideMap(Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height);

#endif //PLATFORMER_CAMERA_H