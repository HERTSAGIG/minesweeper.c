# include <stdio.h>
#include <stdlib.h>

int width;
int height;
int totalMoves;


void makeArray(char grid[100][100] ,int widthIn, int heightIn){
     int width=widthIn+2; //plus two here so that the borders don't reduce the size of the game board
     int height=heightIn+2;
    char corner='+';
     char top='-';
     char sides='|';
     char stars= '*';
     
     for (int i = 0; i < height; ++i)
     {   
         for (int j = 0; j < width; ++j)
         {
             if ((i==0 &&j==0) || (i==height-1&&j==0) ||(i==0&&j==width-1)|| (i==height-1&&j==width-1))
             {
                 grid [i][j]=corner;
             }
        else if (i==0 || i==height-1)
            {
            grid [i][j]=top;
            }
        else if (j==0 ||j==width-1){
            grid [i][j]=sides;   
            }
            else{
            grid [i][j]= stars;       
            }
        }

    }   
 }

 //checks whether the provided co-ordinates are within the grid. Returns 0 if they are valid, 1 otherwise.
 
int isValid (int widthIn, int heightIn){
 // printf("flag 1, %d width, %d height\n", widthIn, heightIn);
    if (widthIn>0 && widthIn<width+1){
        if (heightIn>0 && heightIn<height+1){
            return 0;
        }
        else{
          printf("flag 2 \n");
         return 1;
       }
    }
    else {
      printf("flag 3\n");
      return 1;
  }
}


//Initialises the bombgrid with bomb values, each co-ordinate is stored consecutively in the array, so sorting of the x,y pair is needed later.
void placeBombs(int bombgrid[20], int width, int height){
    int counter=0;
    int Bwidth; //x cordinate of the Bomb
    int Bheight; // Y cordinate of the bomb
    int nargs;
    char identifier;
    char input[10];
    int checkRepeat(int bombgrid[totalMoves], int m, int l); //declaration of the method so it compiles properly.
    
    while (counter<10){
    printf("Please enter Bomb co-ordinate number %d \n", counter+1);
    fgets(input, sizeof(input), stdin);
    nargs = sscanf(input, "%c %d %d\n", &identifier, &Bwidth, &Bheight);
    Bheight=Bheight+1;
    Bwidth=Bwidth+1;
    int check=checkRepeat(bombgrid, Bwidth, Bheight);
    if (identifier!='b' || isValid(Bwidth, Bheight)==1){
        //(identifier=='q'){
      printf("error 5 \n");
        exit(1);
        }
        else if(check==1){
          printf("error 10\n");
          exit(1);
          }
        else{
            printf("Bomb placed at %d, %d, \n", Bwidth, Bheight);
            bombgrid[counter*2]=Bwidth;
            bombgrid[counter*2+1]=Bheight;
            counter++;
        }
    }
}

void printBoard(char mygrid[100][100], int width, int height){
//printf("this is coming from printboard function \n");
   for (int k = 0; k< height+2; ++k)
     {
         for (int l = 0; l < width+2; ++l)
         {
             printf("%c", mygrid[k][l]);       
        }
         
    printf("\n");
    }
}


  //the grid passed has co-ordinates of two consecutive numbers stored. This checks to see if the provided co-ordinates are within the array which is a list of co-ordinates 
  //that have already been provided. Returns 0 if no previous inputs are found, 1 if they are.
  int checkRepeat(int gridCheck[totalMoves], int xcheck, int ycheck){
     printf("%d is the xcheck, %d is the ycheck\n", xcheck, ycheck );
     
      for (int i=0; i<totalMoves+1;++i){
        int tempX=gridCheck[i*2];
        int tempY=gridCheck[i*2+1];
      
       if (xcheck==tempX && ycheck==tempY){
        printf("error 4 \n");
          return 1;
         }
      }
      return 0;


    }

    void updategrid(char grid[100][100], int x, int y, char z){
      if (grid[x][y]!='*'){
       printf("error 9\n");
      }
     else  grid[x][y]=z;
    }
	int main(void)
{
    printf("please enter a grid size to play on type g int int \n");

    int nargs;
    char identifier;
    char input[10];
    char grid[100][100];
    int bombgrid[20];
    
    fgets(input, sizeof(input), stdin);
    nargs = sscanf(input, "%c %d %d\n", &identifier, &width, &height);
    if(identifier!='g'){
        printf("error 1 \n");
        exit(1);
        return 1;
    }
    if (nargs<3){
        printf("error 2");
        exit(1);
        return 1;
    }
    if (width>100 && height>100){
        printf("error 3");
        exit(1);
        return 1;
    }

    totalMoves=height*width;
    makeArray(grid, width, height);
    placeBombs(bombgrid, width, height);
    printBoard(grid, width, height);

//the set up phase has been passed now for the game. This is done through a loop that repeats for all the squares which is height*width, 10 flags will be placed, the rest will be cleared.
    //int flagscount=0;
    int xvalue; //the x variable input for flags and uncovers
    int yvalue; // the y variable input for flags and uncovers
    char trackmoves[totalMoves];
    char input2 [10];
    //char flag= 'z';


    for (int i=0; i<totalMoves; ++i){
      printf("Please enter a co-ordinate to uncover or flag\n");
      fgets(input2, sizeof(input2), stdin);
    nargs = sscanf(input2, "%c %d %d\n", &identifier, &xvalue, &yvalue);
    printf("THe identifier is: %c \n", identifier );
    if (identifier!='u' && identifier!='f'){
      printf("error 6\n");
      exit(1);
    }
    if (isValid(xvalue, yvalue)==1){
      printf("error 7\n");
      exit(1);
    }
    /*
    if (checkRepeat(trackmoves, xvalue, yvalue)==1){
      printf("error 8\n");
      exit(1);
    }
    */
    else{
      //The input is valid, first add the co-ordinate to the list of moves
      trackmoves[i*2]=xvalue;
      trackmoves[i*2+1]=yvalue;
     updategrid(grid, xvalue, yvalue, identifier);
      printBoard(grid, width, height);
    }
    }
    return 0;
}


