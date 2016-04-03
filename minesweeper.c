# include <stdio.h>
#include <stdlib.h>
/*
minesweeper.c written my Reuben Lema.

The main is at the bottom. 
It is prudent to note that the roles of width and height, x and y are actually reversed. This was due to incorrect 
programming for 2d arrays, thus the inputs have just been reversed when the user inputs them. To rectify this issue, 
every instance pairing of width/height or x/y would need to be swapped.
*/
int width;
int height;
int totalMoves;

/*This initialises the array after a success g int int command at the start. Storing each symbol on the main 2d array it 
stores +'s in each corner, | and - for sides and top/bottoms respectively and *'s for the gameboard.
*/
void makeArray(char grid[102][102] ,int widthIn, int heightIn){
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
  //printf("flag 1, %d width, %d height\n", widthIn, heightIn);
    if (widthIn>0 && widthIn<width+2){
        if (heightIn>0 && heightIn<height+2){
            return 0;
        }
        else{
         return 1;
       }
    }
    else {
      return 1;
  }
}


/*This function is used to accept the user inputs for the 10 bombs, it creates a list of the bomb co-ordinates so can check for doubling of bombs. This 
is done by storing x-y co-ordinate pairs in consecutive portions of the array so the x value is i*2 and the y value is y*2+1 for each pair. The main loop
runs 10 times thus it can check if less than 10 bombs have been placed as the identifier will not be correct.
*/
void placeBombs(int bombgrid[20], int width, int height){
    int counter=0;
    int Bwidth; //x cordinate of the Bomb
    int Bheight; // Y cordinate of the bomb
    int nargs;
    char identifier;
    char input[11];
    int checkRepeat(int bombgrid[totalMoves], int m, int l); //declaration of the method so it compiles properly.
    
    while (counter<10){
    fgets(input, sizeof(input), stdin);
    nargs = sscanf(input, "%c %d %d\n", &identifier, &Bheight, &Bwidth);
    int printheight=Bheight;
    int printwidth=Bwidth;
    Bheight=Bheight+1;
    Bwidth=Bwidth+1;
    int check=checkRepeat(bombgrid, Bwidth, Bheight); //this will check to see if the bomb has been repeated or not.
    if (identifier!='b' || isValid(Bwidth, Bheight)==1){
      printf("error\n");
        exit(1);
        }
        else if(check==1){
          printf("error\n");
          exit(1);
          }
        else{
           printf("%c %d %d\n", identifier, printheight, printwidth);
            bombgrid[(counter*2)]=Bwidth;
            bombgrid[(counter*2+1)]=Bheight;
            counter++;
        }
    }
}


/*This function traverses the 2d main grid and prints the characters there. It take the main grid and the original width and height
as parameters.
*/
void printBoard(char mygrid[102][102], int width, int height){

   for (int k = 0; k< width+2; ++k)
     {
         for (int l = 0; l < height+2; ++l)
         {
             printf("%c", mygrid[k][l]);       
        }
         
    printf("\n");
    }
}


  /*the grid passed has co-ordinates of two consecutive numbers stored. This checks to see if the provided co-ordinates are within 
  the array which is a list of co-ordinates that have already been provided. Returns 0 if no previous inputs are found, 1 if they are. */
  int checkRepeat(int gridCheck[totalMoves], int xcheck, int ycheck){
      for (int i=0; i<10;++i){
        int tempX=gridCheck[i*2];
        int tempY=gridCheck[i*2+1];
      
       if (xcheck==tempX && ycheck==tempY){
          return 1;
         }
      }
      return 0;


    }


    /*This function changes the value of the characters stored in the grid. It takes the main grid the x,y co ordinates and the new 
    symbol as arguments. It also checks for a doubling of moves for uncover and flags inputs.
    */
    void updategrid(char grid[102][102], int x, int y, char z){

      if (grid[x][y]!='*'){
       printf("error\n");
       exit(1);
      }
     else  grid[x][y]=z;
    }


    /*The method check how many bombs there are surrounding a given uncover move. It loops from each all the squares from (x-1)(y-1) to
    (x+1)(y+1) count all the surrounding bombs. Uses isBomb to check if co-ordinate is a bomb. 
    */
    char getbombcount(int bombgrid[20], int xvalue, int yvalue){
     int bombcount=0;
     char mychar;
     int isbomb(int bombgrid[20], int x, int y); //to avoid implicit declaration in compilation
    
      for (int i = 0; i < 3; ++i){
        for (int j=0; j<3; ++j){
          int getx=xvalue+(i-1);
          int gety=yvalue+(j-1);
          int temp=isbomb(bombgrid,getx, gety);
         bombcount=bombcount+ temp;
          }
      }

      /*Because the method is returning a char which is a number it needs to be of char not int type,
       other methods to convert the int bombcount didn't work so this is the final method, although it is very 
       in-efficient.*/
      if(bombcount==0){
        mychar='0';
      }
      if(bombcount==1){
        mychar='1';
      }
      if(bombcount==2){
        mychar='2';
      }
       if(bombcount==3){
        mychar='3';
      }
       if(bombcount==4){
        mychar='4';
      }
       if(bombcount==5){
        mychar='5';
      }
       if(bombcount==6){
        mychar='6';
      }
       if(bombcount==7){
        mychar='7';
      }
       if(bombcount==8){
        mychar='8';
      }
      return mychar;
    }



    /*This method checks whether a given x,y value co-ordinates are bombs or not. It loops through the 
    array of bombs co-ordinates and looks for the same values.
    */
int isbomb(int bombgrid[20], int xvalue, int yvalue){
for(int m=0;m<10;++m){
            if(bombgrid[m*2]==xvalue && bombgrid[m*2+1]==yvalue){
              return 1;
            }
          }
            return 0;
    }

    /*This function is required to add a flag to the flag grid, this allows for win through flagging all 
    the mines.
    */
void addflag(int flagGrid[20], int x, int y, int flagcount){
    int counter=flagcount-1;
    flagGrid[counter*2]= x;
    flagGrid[counter*2+1]=y;
}

    /*This is where the magic happens. Starts off by first accepting an input, checks three things first, 
    1) that the identifier is g, 2) that two valid integers have been provided,3) provided integers are 
    less than three. After this if these checks are passed the game board is set up and the bomb inputs are
    required. This moves to a separate function, see placebombs for info. After bombs have been placed the 
    game enters a loop of width*height, that can either be flags or uncovers, this continues until either an 
    invalid move, a bomb is uncovered, more than 10 flags placed, or all the squres and covered or flagged and 
    the user wins. 
    */
	int main(void)
{
    //printf("please enter a grid size to play on type g int int \n");

    int nargs;
    char identifier;
    char input[11];
    char grid[102][102]; //The grid is 102*102 to accomodate the maximum of 100*100 grid with two border symbols included.
    int bombgrid[20]={111,111,111,111,111, 111,111,111,111,111,111,111,111,111,111,111,111,111,111,111}; 
    //This has been initialised to avoid a 0,0 bomb turning up in the empty array.
    
    fgets(input, sizeof(input), stdin);
    nargs = sscanf(input, "%c %d %d\n", &identifier, &height, &width);
    totalMoves=height*width;
    if(identifier!='g'){
        printf("error\n");
        exit(1);
        return 1;
    }
    if (nargs<3){
        printf("error");
        exit(1);
        return 1;
    }
    if (width>100 || height>100){
        printf("error");
        exit(1);
        return 1;
    }
    if (totalMoves<10)
    {
      printf("error\n");
      exit(1);
    }
    printf("%c %d %d\n", identifier, height, width);

    makeArray(grid, height, width);
    placeBombs(bombgrid, width, height);
    printBoard(grid, width, height);

//the set up phase has been passed now for the game. This is done through a loop that repeats for all the squares which is height*width, 10 flags will be placed, the rest will be cleared.
    int flagscount=0;
    int xvalue; //the x variable input for flags and uncovers
    int yvalue; // the y variable input for flags and uncovers
    char input2[11]; 
    int isbomb(int bombgrid[20], int x, int y);
    int flagGrid[20];
    int flagGood=0;

    for (int i=0; i<totalMoves; ++i){
    fgets(input2, sizeof(input2), stdin);
    nargs = sscanf(input2, "%c %d %d\n", &identifier, &yvalue, &xvalue);
    int boardxvalue=xvalue+1;
    int boardyvalue=yvalue+1;
    if (identifier!='u' && identifier!='f'){
      printf("error\n");
      exit(1);
      }
      if (isValid(boardxvalue, boardyvalue)==1){
        printf("error\n");
        exit(1);
        }
      if(isbomb(bombgrid, boardxvalue, boardyvalue)==1 && identifier!='f'){
        printf("lose\n");
        exit(1);
        } 
      else{
      //The input is valid, first add the co-ordinate to the list of moves
      
      if (identifier=='u'){
        char symbol=getbombcount(bombgrid, boardxvalue, boardyvalue);
        updategrid(grid, boardxvalue, boardyvalue, symbol);
        printf("%c %d %d\n", identifier, yvalue, xvalue); //the print statement has to come second so double command exit in update grid function before they print
      }
      else{
          flagscount=flagscount+1;
          if (flagscount>10) //greater than 11 because the flagcount is incremented before the statement.
         {
          printf("error\n");
          exit(1);
          }
           addflag(flagGrid, xvalue, yvalue, flagscount);
           //this if statement is designed to see if all bombs have been flagged and to allow a win through that.
          if (flagscount==10){
            for(int f=0; f<10; ++f){
              int tempX=flagGrid[f*2];
              int tempY=flagGrid[f*2+1];
              if (isbomb(bombgrid, tempX, tempY)==1)
                {
                flagGood=flagGood+1;
                }
              }
              if (flagGood==10){
              printf("win\n");
                exit(0);
              }
          }
          updategrid(grid, boardxvalue, boardyvalue, identifier);
          printf("%c %d %d\n", identifier, yvalue, xvalue);
          }
        printBoard(grid, width, height);
      }
    }
    printf("won\n");
    exit(0);
}


