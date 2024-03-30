#include "header.h"

int main()
{
    InitWindow(HEIGHT, WIDTH, NAME_GAME);
    InitAudioDevice();

    int flag = 0, play = 0;

    while (play == 0)
    {
        flag = GameArkanoid();
        if (flag == 1)
        {
            flag = GameMechanics();
            if (flag == 1)
            {
                break;
            }
            if (flag == 3)
            {
                flag = GameLose();
                if (flag == 0)
                {
                    break;
                }
            }
            if (flag == 5)
            {
                flag = GameWin();
                if (flag == 0)
                {
                    break;
                }
            }
        }
        if (flag == 2)
        {
            break;
        }
        if (flag == 52) 
        {
            flag = Settings();
        }
        else {
            flag = GameArkanoid();
        }
    }

    CloseWindow();
    return 0;
}