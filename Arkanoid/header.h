#pragma once
#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>

#define HEIGHT 960
#define WIDTH 840
#define NAME_GAME "Arkanoid"

typedef struct {
	float x, y;
	float speedX, speedY;
	int radius;

}BALL;
typedef struct {
	float x, y;
	float speed;
	float width, height;
}PLATE;

int GameArkanoid(void);
int GameMechanics(void);
int GameLose(void);
int GameWin(void);
int Settings(void);