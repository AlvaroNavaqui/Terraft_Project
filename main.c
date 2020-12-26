#include<stdio.h>
#include <windows.h>
#include <Windows.h>

void Coordinates(int xs, int ys,int x, int y, char Overworld[y][x], int ObvX, int ObvY);
void printmap();
void printmap(char Overworld[50][150]);


int main()
{
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);

    POINT p;
    FILE *ptr_file;
    char buf[1000], Input, Edit;
    int i=0, j=0;
    int x=40, xs;
    int y=20, ys;
    int ObvX=x, ObvXs, ObvY=y-1, ObvYs;
    char Overworld[50][150];

    ptr_file =fopen("C:/Users/alvar/OneDrive/Escritorio/Drogas/New/Terracraft_Editor/Mapa1.txt","r");
    if (!ptr_file)
        return 1;

    while (fgets(buf,1000, ptr_file)!=NULL) //Loads Map in Overworld[][].
    {                                       

        for(int j=0 ; j<150 ; j++)
            Overworld[i][j]=buf[j];
        i++;                                //......
    }

    gotoxy(0,0);
    printmap(Overworld);
    
    while(Input!='x')             //Main Loop, while X isnt the Input.
    {

        Coordinates(xs, ys, x, y, Overworld, ObvX, ObvY);
        Input = getch();
        xs=x;
        ys=y;
        ObvXs=ObvX;
        ObvYs=ObvY;

        switch(Input)
        {
        case 'w':
            y--;
            ObvY=y-1;
            ObvX=x;
            break;
        case 'a':
            x--;
            ObvX=x-1;
            ObvY=y;
            break;
        case 's':
            y++;
            ObvY=y+1;
            ObvY++;
            ObvX=x;
            break;
        case 'd':
            x++;
            ObvX=x+1;
            ObvX++;
            ObvY=y;
            break;
        }
        if(Overworld[y][x]==32)
        {

            //    gotoxy(ObvX,ObvY);
            //    printf(".");

            gotoxy(x,y);
            Overworld[ys-1][xs]=72;
            printf("H");

            gotoxy(xs,ys);
            Overworld[ys-1][xs]=32;
            printf(" ");

            gotoxy(x,y);

        }
        else
        {
            gotoxy(xs,ys);
            x=xs;
            y=ys;
            ObvX = (ObvX + x)/2;
            ObvY = (ObvY + y)/2;
            gotoxy(ObvX,ObvY);
            printf(".");
        }
    }
    fclose(ptr_file);
    return 0;
}

void printmap(char Overworld[50][150])
{

    for (int i=0 ; i<50 ; i++)
    {
        for (int j=0 ; j<150 ; j++)
        {
            if(i==0 || i==49)
                printf("-");
            else if (j==0 || j==149)
                printf(".");
            else
                printf("%c", Overworld[i][j]);
        }
        printf("\n");

    }



}

void Coordinates(int xs, int ys, int x, int y, char Overworld[y][x], int ObvX, int ObvY)
{
    gotoxy(200,2);          //Coordinates top right.
    printf("       ");
    gotoxy(200,2);
    printf("%d,%d", x,y);
    gotoxy(200,3);
    printf("%d,%d", xs,ys);

    gotoxy(200,5);
    printf("%d", Overworld[ObvY][ObvX]);

    gotoxy(200,1);
    printf("%d,%d", ObvX, ObvY);

    gotoxy(200,6);



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
