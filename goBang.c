#include <stdio.h>
#include <stdlib.h>

#define N    15

int chessboard[N + 1][N + 1] = { 0 };

int whoseTurn = 0;

void initGame();
void printChessboard();
void playChess();
int judge(int, int);

int main()
{
    initGame();

    while (1)
    {
        whoseTurn++;

        playChess();
    }

    return 0;
}

void initGame()
{
    char c;

    printf("Please input \'y\' to enter the game:");
    c = getchar();
    if ('y' != c && 'Y' != c)
        exit(0);

    system("clear");
    printChessboard();
}

void printChessboard()
{
    int i, j;

    for (i = 0; i <= N; i++)
    {
        for (j = 0; j <= N; j++)
        {
            if (0 == i)
                printf("%3d", j);
            else if (j == 0)
                printf("%3d", i);
            else if (1 == chessboard[i][j])
                printf("  O");
            else if (2 == chessboard[i][j])
                printf("  X");
            else
                printf("  *");
        }
        printf("\n");
    }
}

void playChess()
{
    int i, j, winner;

    if (1 == whoseTurn % 2)
    {
        do {
        	printf("Turn to player 1, please input the position (the format should be: cow[a blank_space]col):");
        	scanf("%d %d", &i, &j);
        }while(i < 1 || i > 15 || j < 1 || j > 15);

        while(chessboard[i][j] != 0)
        {
            printf("This position  has been occupied, please input the position again:"); 
            scanf("%d %d", &i, &j);
        }

        chessboard[i][j] = 1; 
    }
    else
    {
        do {
        	printf("Turn to player 2, please input the position (the format should be: cow[a blank_space]col):");
        	scanf("%d %d", &i, &j);
        }while(i < 1 || i > 15 || j < 1 || j > 15);

        while(chessboard[i][j] != 0)
        {
            printf("This position  has been occupied, please input the position again:"); 
            scanf("%d %d", &i, &j);
        }

        chessboard[i][j] = 2;
    }

    system("clear");
    printChessboard();

    if (judge(i, j))
    {
        if (1 == whoseTurn % 2)
        {
            printf("Winner is player 1!\n");
            exit(0);
        }
        else
        {
            printf("Winner is player 2!\n");
            exit(0);
        }
    }
}

int judge(int x, int y)
{
    int i, j;
    int t = 2 - whoseTurn % 2;

    for (i = x - 4, j = y; i <= x; i++)
    {
        if (i >= 1 && i <= N - 4 && t == chessboard[i][j] && t == chessboard[i + 1][j] && t == chessboard[i + 2][j] && t == chessboard[i + 3][j] && t == chessboard[i + 4][j])
            return 1;
    }
    for (i = x, j = y - 4; j <= y; j++)
    {
        if (j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i][j + 1] && t == chessboard[i][j + 1] && t == chessboard[i][j + 3] && t == chessboard[i][j + 4])
            return 1;
    }
    for (i = x - 4, j = y - 4; i <= x, j <= y; i++, j++)
    {
        if (i >= 1 && i <= N - 4 && j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i + 1][j + 1] && t == chessboard[i + 2][j + 2] && t == chessboard[i + 3][j + 3] && t == chessboard[i + 4][j + 4])
            return 1;
    }
    for (i = x + 4, j = y - 4; i >= 1, j <= y; i--, j++)
    {
        if (i >= 1 && i <= N - 4 && j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i - 1][j + 1] && t == chessboard[i - 2][j + 2] && t == chessboard[i - 3][j + 3] && t == chessboard[i - 4][j + 4])
            return 1;
    }

    return 0;
}