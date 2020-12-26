#include<stdio.h>
#include <windows.h>
#include <Windows.h>

void gotoxy(int, int);

int main (void)
{
    FILE *ptr_file;
    POINT p;

    int col=1;
    int x=p.x / 8;
    int y=(p.y - 23) / 16;
    int i,j;
    char overworld[50][150];

    for (i = 0 ; i < 50 ; i++)      //This part of the code will draw the edges within to draw
    {
        for (j = 0; j < 150 ; j++)
        {
            if (((i==0) || (i==50-1)) && (j<150))
            {
                printf(".");
            }
            else if((j==0) || (j==150-1))
            {
                printf(".");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }


    for(i=0 ; i<50 ; i++)
        for(j=0; j<150 ; j++)
            overworld[i][j]=' ';
    
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);	//maximize window
    
    char Wall = 'X', Nun = 32, Tree= 'T', Ore= 'o', House='A', Edit, input;

    while(input!='x')
    {
        input = getch();

        switch(input)
        {
        case '1':
            Edit = Nun;
            break;
        case '2':
            Edit = Wall;
            break;
        case '3':
            Edit = Ore;
            break;
        case '4':
            Edit = Tree;
            break;
        case '5':
            Edit = House;
            break;
        case 'w':
            y--;
            break;
        case 'a':
            x--;
            break;
        case 's':
            y++;
            break;
        case 'd':
            x++;
            break;
        }
        gotoxy(200,2);
        printf("       ");
        gotoxy(200,2);
        printf("%d,%d", x,y+1);

        gotoxy(x,y);

        if(GetAsyncKeyState(VK_SPACE) & 0x80000000)
        {
            overworld[y][x]=Edit;
            printf("%c", Edit);
        }
    }
    char FileName[250];
    char userfile[255];
    system("cls");
    printf("Save map as: ");
    scanf("%s", FileName);
    sprintf(userfile, "%s.txt", FileName);
    ptr_file = fopen(userfile, "w");

    if (!ptr_file)
        return 1;

    for (int i=0; i<50 ; i++)
    {
        for(int j=0; j<150 ; j++)
            fprintf(ptr_file,"%c", overworld[i][j]);
        fprintf(ptr_file,"\n");
    }
    fclose(ptr_file);

    return  0;
}

void gotoxy(int x, int y)	//http://micodigocpp.blogspot.com/2013/11/crear-la-funcion-gotoxy-en-dev-c.html
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
