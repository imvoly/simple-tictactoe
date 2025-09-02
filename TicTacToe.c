#include <stdio.h>
#include <stdbool.h>
const char symbols[]={'O', 'X', '.'};
void clearBuffer(void)
{
    int c;
    while((c=getchar())!= '\n' && c!=EOF) {}
}

bool checkwin(int map[4][4])
{
    for(int i=1; i<4; i++) if (map[1][i] == map[2][i] && map[2][i] == map[3][i] && map[1][i] != 2) return true;
    for(int i=1; i<4; i++) if (map[i][1] == map[i][2] && map[i][2] == map[i][3] && map[i][1] != 2) return true;
    if (map[1][1] == map[2][2] && map[2][2] == map[3][3] && map[2][2] != 2) return true;
    if (map[1][3] == map[2][2] && map[2][2] == map[3][1] && map[2][2] != 2) return true;
    return false;
}
bool checkDraw(int map[4][4])
{
    for(int i=1; i<4; i++)
    for(int j=1; j<4; j++)
        if(map[i][j]==2) return false;
    return true;
}
void arrayZeroing(int map[4][4])
{
    for(int i=1; i<4; i++)
            for(int j=1; j<4; j++)
                map[i][j]=2;
}
void arrayPrinting(int map[4][4])
{
    for(int i=1; i<4; i++)
            {
                for(int j=1; j<4; j++)
                    printf("%c ", symbols[map[i][j]]);
                printf("\n");
            }
}


int main(){
    bool UserWantsToContinue=true; bool turn=0;
    int map[4][4]; char input[100]; bool draw=1;
    int p1, a, b;
    do {
        //Turning the array into 2
        arrayZeroing(map);
        printf("This is a game of tic tac toe, as soon as you press enter you will see the map you start with. X is player 0, 0 is player 1. I know, weird.");
        getchar();
        //Game Printing
        arrayPrinting(map);
        while(true)
            {
                if(turn==0) 
                    {
                        printf("Player 0 turn.\nChoose where you want to mark in i and j coordinates.\nBy that I mean, type in i, press enter, then do the same for j.\n");
                        while(true)
                            {
                                fgets(input, sizeof(input), stdin);
                                if(sscanf(input, "%d %d", &a, &b) !=2 )
                                    {
                                        printf("Invalid input. Input should be in the format: 1 2, or maybe 3 1.\n");
                                        continue;
                                    }
                                if(a<1 || a>3 || b<1 || b>3)
                                    {
                                        printf("Invalid input. Numbers should be in the 1-3 range. Try again.\n");
                                        continue;
                                    }
                                if(map[a][b]!=2)
                                    {
                                        printf("Square already filled. BRO YOU CAN LITERALLLY SEE THE GAME. New input pls.\n");
                                        continue;
                                    }
                                break;
                            }
                        map[a][b]=1;
                        turn=1;
                        //Game Printing
                        arrayPrinting(map);
                    }
                if(checkwin(map)) break;
                if(checkDraw(map)) {draw=1;break;}
                
                if(turn==1) 
                    {
                        printf("Player 1 turn.\nChoose where you want to mark in i and j coordinates.\nBy that I mean, type in i, press enter, then do the same for j.\n");
                        while(true)
                            {
                                fgets(input, sizeof(input), stdin);
                                if(sscanf(input, "%d %d", &a, &b) !=2 )
                                    {
                                        printf("Invalid input. Input should be in the format: 1 2, or maybe 3 1.\n");
                                        continue;
                                    }
                                if(a<1 || a>3 || b<1 || b>3)
                                    {
                                        printf("Invalid input. Numbers should be in the 1-3 range. Try again.\n");
                                        continue;
                                    }
                                if(map[a][b]!=2)
                                    {
                                        printf("Square already filled. BRO YOU CAN LITERALLLY SEE THE GAME. New input pls.\n");
                                        continue;
                                    }
                                break;
                            }
                        map[a][b]=0;
                        turn=0;
                        //Game Printing
                        arrayPrinting(map);
                    }
                if(checkwin(map)) break;
                if(checkDraw(map)) {draw=1;break;}
            }
        printf("The final map was:\n");
        //Game Printing
        arrayPrinting(map);
        if(draw==0)printf("And the winner was player %d\n", !turn);
        else printf("The game was a draw.\n");
        printf("Do you want to continue? Press 1 for yes, and 0 for no.\n");
        scanf("%d", &UserWantsToContinue); clearBuffer();
    } while(UserWantsToContinue);
    return 0;
} 