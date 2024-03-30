#include "header.h"

int GameArkanoid(void)
{
    int flag = 0;

    Texture2D play, exit, nameGame, web, setting;
    Texture2D StickMan[4];

    Sound sound;
    sound = LoadSound("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/HelloHello.ogg");

    play = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Play.png");
    exit = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Exit.png");
    nameGame = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/NameGame.png");
    web = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Web.png");
    setting = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Seting.png");

    StickMan[0] = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/stickMan1.png");
    StickMan[1] = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/stickMan2.png");
    StickMan[2] = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/stickMan3.png");
    StickMan[3] = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/stickMan4.png");

    int frameIndex = 0;
    float frameTime = 0.0f;

    while (!WindowShouldClose())
    {

        frameTime += GetFrameTime();
        if (frameTime >= 0.15f)
        {
            frameIndex++;
            if (frameIndex > 3) {
                frameIndex = 0;
            }
            frameTime = 0.0f;
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Rectangle HELLO = {
                100,
                620,
                StickMan[0].width,
                StickMan[0].height
            };
            Rectangle EXIT = {
                   415,
                   340 + play.height + 100,
                   exit.width,
                   exit.height
            };
            Rectangle PLAY = {
                   390,
                   420,
                   play.width,
                   play.height
            };
            Rectangle SETING = {
                   800,
                   700,
                   setting.width,
                   setting.height
            };

            if (CheckCollisionPointRec(GetMousePosition(), HELLO))
            {
                PlaySound(sound);
            }
            if (CheckCollisionPointRec(GetMousePosition(), PLAY))
            {
                flag = 1;
                return flag;
            }
            if (CheckCollisionPointRec(GetMousePosition(), EXIT))
            {
                flag = 2;
                return flag;
                break;
            }

            if (CheckCollisionPointRec(GetMousePosition(), SETING))
            {
                flag = 52;
                return flag;
                break;
            }
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        BeginDrawing();

        ClearBackground(BLACK);

        DrawTexture(nameGame, 280, 190, RAYWHITE);
        DrawTexture(web, GetScreenWidth() - 210, -5, RAYWHITE);
        DrawTexture(play, 390, 420, RAYWHITE);
        DrawTexture(setting, 800, 700, RAYWHITE);

        DrawTexture(StickMan[frameIndex], 100, 620, WHITE);

        DrawTexture(exit, 415, 340 + play.height + 100, RAYWHITE);

        EndDrawing();
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
    }
}
