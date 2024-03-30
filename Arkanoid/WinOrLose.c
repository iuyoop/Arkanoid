#include "header.h"

int GameWin(void)
{
    Texture2D menu, close, win;

    Music musicWin;
    musicWin = LoadMusicStream("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/WinMusic.mp3");

    menu = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Menu.png");
    close = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Close.png");
    win = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Win.png");

    while (!WindowShouldClose())
    {
        UpdateMusicStream(musicWin);
        PlayMusicStream(musicWin);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Rectangle MENU = {
                    530,
                    440 + close.height - 80,
                    menu.width,
                    menu.height
            };
            if (CheckCollisionPointRec(GetMousePosition(), MENU))
            {
                return 1;
                break;
            }

            Rectangle CLOSE = {
                    280,
                    440,
                    close.width,
                    close.height
            };
            if (CheckCollisionPointRec(GetMousePosition(), CLOSE))
            {
                return 0;
                break;
            }
        }


        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        BeginDrawing();
        ClearBackground(BLACK);

        DrawTexture(win, 200, 350 - close.height * 2 + 50, RAYWHITE);
        DrawTexture(close, 280, 440, RAYWHITE);
        DrawTexture(menu, 530, 440 + close.height - 80, RAYWHITE);

        EndDrawing();
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    }
}

int GameLose(void)
{
    Music musicLose;
    musicLose = LoadMusicStream("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/LoseMusic.mp3");

    Texture2D menu, close, lose;

    menu = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Menu.png");
    close = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Close.png");
    lose = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/YouLose.png");

    while (!WindowShouldClose())
    {
        UpdateMusicStream(musicLose);
        PlayMusicStream(musicLose);


        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Rectangle MENU = {
                    530,
                    440 + close.height - 80,
                    menu.width,
                    menu.height
            };
            if (CheckCollisionPointRec(GetMousePosition(), MENU))
            {
                return 1;
                break;
            }

            Rectangle CLOSE = {
                    280,
                    440,
                    close.width,
                    close.height
            };
            if (CheckCollisionPointRec(GetMousePosition(), CLOSE))
            {
                return 0;
                break;
            }
        }


        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        BeginDrawing();
        ClearBackground(BLACK);

        DrawTexture(lose, 150, 350 - close.height * 2 + 50, RAYWHITE);
        DrawTexture(close, 280, 440, RAYWHITE);
        DrawTexture(menu, 530, 440 + close.height - 80, RAYWHITE);

        EndDrawing();
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    }
}