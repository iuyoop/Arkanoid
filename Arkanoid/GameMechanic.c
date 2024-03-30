#include "header.h"

static int Level;
static int GodMode;
static int Musics;

int GameMechanics(void)
{
    FILE* file = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/LEVEL.txt", "r");
    fread(&Level, sizeof(int), 1, file);
    fclose(file);

    FILE* GOD = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/GODMODE.txt", "r");
    fread(&GodMode, sizeof(int), 1, GOD);
    fclose(GOD);

    FILE* MUSIC = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/MUSIC.txt", "r");
    fread(&Musics, sizeof(int), 1, MUSIC);
    fclose(MUSIC);

    int score = 0;
    Texture2D menu, exitKey, nameGame, youLose, toStart;
    Texture2D cube[15];

    Sound soundPress;
    soundPress = LoadSound("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Press.ogg");

    Music musicMenu, Bit8, Circus, WelcomeBack;
    Bit8 = LoadMusicStream("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/MenuMusicV2.mp3");
    Circus = LoadMusicStream("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Circus.mp3");
    WelcomeBack = LoadMusicStream("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/WelcomeBack.mp3");

    if (Musics == 0) {
        musicMenu = Bit8;
    }
    if (Musics == 1) {
        musicMenu = Circus;
    }
    if (Musics == 2) {
        musicMenu = WelcomeBack;
    }
    SetMusicVolume(musicMenu, 0.5f);

    for (int i = 0; i < 15; i++) {
        cube[i] = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Cube.png");
    }

    int delCube1[15];
    for (int i = 0; i < 15; i++) {
        delCube1[i] = 0;
    }
    int delCube2[15];
    for (int i = 0; i < 15; i++) {
        delCube2[i] = 0;
    }
    int delCube3[15];
    for (int i = 0; i < 15; i++) {
        delCube3[i] = 0;
    }
    int delCube4[15];
    for (int i = 0; i < 15; i++) {
        delCube4[i] = 0;
    }

    int flag = 0;
    int posCubeX = 50, posCubeY = 100;

    PLATE plate;
    plate.width = 100;
    plate.height = 5;
    plate.x = GetScreenWidth() / 2 - plate.width / 2;
    plate.y = GetScreenHeight() - 50;
    plate.speed = 500;

    BALL ball;
    ball.x = GetScreenWidth() / 2 - plate.width / 2 + 45;
    ball.y = GetScreenHeight() - 50 - 25;
    ball.radius = 5;
    ball.speedX = 400;
    ball.speedY = 400;


    menu = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Menu.png");
    exitKey = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/ExitKey.png");
    nameGame = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/NameGameForGame.png");
    toStart = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/ToStart.png");

    while (!WindowShouldClose())
    {
        UpdateMusicStream(musicMenu);
        PlayMusicStream(musicMenu);
        if (IsKeyDown(KEY_LEFT))
        {
            plate.x -= plate.speed * GetFrameTime();
            if (flag != 1)
                ball.x -= plate.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_RIGHT))
        {
            plate.x += plate.speed * GetFrameTime();
            if (flag != 1)
                ball.x += plate.speed * GetFrameTime();
        }

        Rectangle plateRectangle = { plate.x, plate.y, plate.width, plate.height };

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Rectangle MENU = {
                   10,
                   5,
                   menu.width,
                   menu.height
            };
            if (CheckCollisionPointRec(GetMousePosition(), MENU))
            {
                return 0;
                break;
            }

            Rectangle EXIT_KEY = {
                   HEIGHT - 75,
                   10,
                   exitKey.width,
                   exitKey.height
            };
            if (CheckCollisionPointRec(GetMousePosition(), EXIT_KEY))
            {
                return 1;
                break;
            }
        }

        if ((IsKeyPressed(KEY_SPACE)) || (flag == 1))
        {
            ball.x += ball.speedX * GetFrameTime();
            ball.y += ball.speedY * GetFrameTime();
            Vector2 ballVector = { ball.x, ball.y };

            if ((ball.x > GetScreenWidth()))
            {
                PlaySound(soundPress);
                ball.x = GetScreenWidth();
                ball.speedX *= -1;
            }
            if (ball.x <= 0)
            {
                PlaySound(soundPress);
                ball.speedX *= -1;
            }

            if (ball.y > GetScreenHeight() && GodMode == 0)
            {
                return 3;
            }
            if (ball.y > GetScreenHeight() && GodMode == 1)
            {
                PlaySound(soundPress);
                ball.speedY *= -1;
            }

            if (ball.y < 63 + 3)
            {
                PlaySound(soundPress);
                ball.speedY *= -1;
            }

            if (CheckCollisionCircleRec(ballVector, ball.radius, plateRectangle))
            {
                PlaySound(soundPress);
                if (ball.speedY > 0)
                {
                    ball.speedY *= -1;
                }
            }
            flag = 1;
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        BeginDrawing();

        ClearBackground(BLACK);

        if (Level >= 1){
            for (int i = 0; i < 15; i++)
            {
                if (delCube1[i] != 1)
                {
                    DrawTexture(cube[i], posCubeX + (i * 60), posCubeY, RAYWHITE);
                    Rectangle Cube = { posCubeX + (i * 60), posCubeY, cube[i].width, cube[i].height };
                    Vector2 ballVector = { ball.x, ball.y };

                    if ((CheckCollisionCircleRec(ballVector, ball.radius, Cube)))
                    {
                        PlaySound(soundPress);
                        score++;
                        delCube1[i] = 1;

                        if (ball.y > posCubeY + cube[i].height)
                            ball.speedY *= -1;
                        if (ball.y < posCubeY)
                            ball.speedY *= -1;

                        if (ball.x > posCubeX + (i * 60) + cube[i].width)
                            ball.speedX *= -1;
                        if (ball.x < posCubeX + (i * 60))
                            ball.speedX *= -1;
                    }
                }
            }
        }
        if (Level >= 2) {
            for (int i = 0; i < 15; i++)
            {
                if (delCube2[i] != 1)
                {
                    DrawTexture(cube[i], posCubeX + (i * 60), posCubeY + 80, RAYWHITE);
                    Rectangle Cube = { posCubeX + (i * 60), posCubeY + 80, cube[i].width, cube[i].height };
                    Vector2 ballVector = { ball.x, ball.y };

                    if ((CheckCollisionCircleRec(ballVector, ball.radius, Cube)))
                    {
                        PlaySound(soundPress);
                        score++;
                        delCube2[i] = 1;

                        if (ball.y > posCubeY + 80 + cube[i].height)
                            ball.speedY *= -1;
                        if (ball.y < posCubeY + 80)
                            ball.speedY *= -1;

                        if (ball.x > posCubeX + (i * 60) + cube[i].width)
                            ball.speedX *= -1;
                        if (ball.x < posCubeX + (i * 60))
                            ball.speedX *= -1;
                    }
                }
            }
        }
        if (Level >= 3) {
            for (int i = 0; i < 15; i++)
            {
                if (delCube3[i] != 1)
                {
                    DrawTexture(cube[i], posCubeX + (i * 60), posCubeY + 160, RAYWHITE);
                    Rectangle Cube = { posCubeX + (i * 60), posCubeY + 160, cube[i].width, cube[i].height };
                    Vector2 ballVector = { ball.x, ball.y };

                    if ((CheckCollisionCircleRec(ballVector, ball.radius, Cube)))
                    {
                        PlaySound(soundPress);
                        score++;
                        delCube3[i] = 1;

                        if (ball.y > posCubeY + 160 + cube[i].height)
                            ball.speedY *= -1;
                        if (ball.y < posCubeY + 160)
                            ball.speedY *= -1;

                        if (ball.x > posCubeX + (i * 60) + cube[i].width)
                            ball.speedX *= -1;
                        if (ball.x < posCubeX + (i * 60))
                            ball.speedX *= -1;
                    }
                }
            }
        }
        if (Level >= 4) {
            for (int i = 0; i < 15; i++)
            {
                if (delCube4[i] != 1)
                {
                    DrawTexture(cube[i], posCubeX + (i * 60), posCubeY + 240, RAYWHITE);
                    Rectangle Cube = { posCubeX + (i * 60), posCubeY + 240, cube[i].width, cube[i].height };
                    Vector2 ballVector = { ball.x, ball.y };

                    if ((CheckCollisionCircleRec(ballVector, ball.radius, Cube)))
                    {
                        PlaySound(soundPress);
                        score++;
                        delCube4[i] = 1;

                        if (ball.y > posCubeY + 240 + cube[i].height)
                            ball.speedY *= -1;
                        if (ball.y < posCubeY + 240)
                            ball.speedY *= -1;

                        if (ball.x > posCubeX + (i * 60) + cube[i].width)
                            ball.speedX *= -1;
                        if (ball.x < posCubeX + (i * 60))
                            ball.speedX *= -1;
                    }
                }
            }
        }

        DrawTexture(menu, 10, 5, RAYWHITE);
        DrawTexture(exitKey, HEIGHT - 75, 5, RAYWHITE);
        DrawTexture(nameGame, 370, 3, RAYWHITE);
        DrawRectangle(0, 63, HEIGHT, 1, WHITE);

        if (flag == 0)
        {
            DrawTexture(toStart, 175, 425, RAYWHITE);
        }
        if (score == 15 * Level)
        {
            return 5;
        }

        DrawCircle((int)ball.x, (int)ball.y, ball.radius, WHITE);
        DrawRectangle(plate.x, plate.y, plate.width, plate.height, WHITE);

        EndDrawing();
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    }
}

int Settings(void) 
{
    FILE *file = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/LEVEL.txt", "r");
    fread(&Level, sizeof(int), 1, file);
    fclose(file);

    FILE* GOD = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/GODMODE.txt", "r");
    fread(&GodMode, sizeof(int), 1, GOD);
    fclose(GOD);

    FILE* MUSIC = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/MUSIC.txt", "r");
    fread(&Musics, sizeof(int), 1, MUSIC);
    fclose(MUSIC);

    Texture2D menu, settings, level, left, right, god;
    Texture2D one, two, three, four;
    Texture2D yes, no;
    Texture2D musicSetting, Music8Bit, Circus, WelcomeBack;

    menu = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Menu.png");
    settings = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Settings.png");

    level = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Level.png");
    left = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Left.png");
    right = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Right.png");

    god = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/God.png");
    yes = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Yes.png");
    no = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/No.png");

    one = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/1.png");
    two = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/2.png");
    three = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/3.png");
    four = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/4.png");

    musicSetting = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/MusicSetting.png");
    Music8Bit = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/8bit.png");
    Circus = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Circ.png");
    WelcomeBack = LoadTexture("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/assets/Welcome.png");

    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Rectangle MENU = {
                   820,
                   10,
                   menu.width,
                   menu.height
            };
            if (CheckCollisionPointRec(GetMousePosition(), MENU))
            {
                return 0;
                break;
            } 

            Rectangle RightLevel = {
                   575,
                   290,
                   right.width,
                   right.height
            };
            if (CheckCollisionPointRec(GetMousePosition(), RightLevel))
            {
                Level++;
                FILE* file = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/LEVEL.txt", "w");
                fwrite(&Level, sizeof(int), 1, file);
                fclose(file);
                if (Level > 4) {
                    Level = 1;
                    FILE* file = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/LEVEL.txt", "w");
                    fwrite(&Level, sizeof(int), 1, file);
                    fclose(file);
                }
            }
            Rectangle LeftLevel = {
                   325,
                   280,
                   left.width,
                   left.height
            };
            if (CheckCollisionPointRec(GetMousePosition(), LeftLevel))
            {
                Level--;
                FILE* file = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/LEVEL.txt", "w");
                fwrite(&Level, sizeof(int), 1, file);
                fclose(file);
                if (Level < 1) {
                    Level = 4;
                    FILE* file = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/LEVEL.txt", "w");
                    fwrite(&Level, sizeof(int), 1, file);
                    fclose(file);
                }
            }

            Rectangle RightgGod = {
                   575,
                   480,
                   right.width,
                   right.height
            };
            if (CheckCollisionPointRec(GetMousePosition(), RightgGod))
            {
                GodMode++;
                FILE* GOD = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/GODMODE.txt", "w");
                fwrite(&GodMode, sizeof(int), 1, GOD);
                fclose(GOD);
                if (GodMode > 1) {
                    GodMode = 0;
                    FILE* GOD = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/GODMODE.txt", "w");
                    fwrite(&GodMode, sizeof(int), 1, GOD);
                    fclose(GOD);
                }
            }
            Rectangle LeftGod = {
                   325,
                   480,
                   left.width,
                   left.height
            };
            if (CheckCollisionPointRec(GetMousePosition(), LeftGod))
            {
                GodMode--;
                FILE* GOD = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/GODMODE.txt", "w");
                fwrite(&GodMode, sizeof(int), 1, GOD);
                fclose(GOD);
                if (GodMode < 0) {
                    GodMode = 1;
                    FILE* GOD = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/GODMODE.txt", "w");
                    fwrite(&GodMode, sizeof(int), 1, GOD);
                    fclose(GOD);
                }
            }

            Rectangle RightgMusic = {
                   650,
                   680,
                   right.width,
                   right.height
            };
            if (CheckCollisionPointRec(GetMousePosition(), RightgMusic))
            {
                Musics++;
                FILE* MUSIC = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/MUSIC.txt", "w");
                fwrite(&Musics, sizeof(int), 1, MUSIC);
                fclose(MUSIC);
                if (Musics > 2) {
                    Musics = 0;
                    FILE* MUSIC = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/MUSIC.txt", "w");
                    fwrite(&GodMode, sizeof(int), 1, MUSIC);
                    fclose(MUSIC);
                }
            }
            Rectangle LeftMusic = {
                   250,
                   680,
                   left.width,
                   left.height
            };
            if (CheckCollisionPointRec(GetMousePosition(), LeftMusic))
            {
                Musics--;
                FILE* MUSIC = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/MUSIC.txt", "w");
                fwrite(&Musics, sizeof(int), 1, MUSIC);
                fclose(MUSIC);
                if (Musics < 0) {
                    Musics = 2;
                    FILE* MUSIC = fopen("C:/Users/user/Desktop/ƒети/сан“ехники/языки чего-то тама/Arkanoid/MUSIC.txt", "w");
                    fwrite(&Musics, sizeof(int), 1, MUSIC);
                    fclose(MUSIC);
                }
            }
        }
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        BeginDrawing();

        ClearBackground(BLACK);
        DrawTexture(menu, 820, 10, RAYWHITE);
        DrawTexture(settings, 275, 5, RAYWHITE);

        DrawTexture(level , 375, 150, RAYWHITE);
        DrawTexture(left, 325, 280, RAYWHITE);
        DrawTexture(right, 575, 290, RAYWHITE);

        DrawTexture(god, 350, 375, RAYWHITE);
        DrawTexture(left, 325, 480, RAYWHITE);
        DrawTexture(right, 575, 480, RAYWHITE);

        DrawTexture(musicSetting, 370, 580, RAYWHITE);
        DrawTexture(left, 250, 680, RAYWHITE);
        DrawTexture(right, 650, 680, RAYWHITE);

        if (Level == 4) {
            DrawTexture(four, 450, 280, RAYWHITE);
        }
        if (Level == 3) {
            DrawTexture(three, 450, 280, RAYWHITE);
        }
        if (Level == 2) {
            DrawTexture(two, 450, 280, RAYWHITE);
        }
        if (Level == 1) {
            DrawTexture(one, 450, 280, RAYWHITE);
        }

        if (GodMode == 1) {
            DrawTexture(yes, 425, 480, RAYWHITE);
        }
        if (GodMode == 0) {
            DrawTexture(no, 425, 480, RAYWHITE);
        }

        if (Musics == 0) {
            DrawTexture(Music8Bit, 400, 680, RAYWHITE);
        }
        if (Musics == 1) {
            DrawTexture(Circus, 375, 680, RAYWHITE);
        }
        if (Musics == 2) {
            DrawTexture(WelcomeBack, 350, 680, RAYWHITE);
        }

        EndDrawing();
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
    }
}