# include <stdio.h>


int width;
int height;


void makeArray(grid[100][100] ,int widthIn, int heightIn){
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
    /*
     for (int k = 0; k< height; ++k)
     {
         for (int l = 0; l < width; ++l)
         {
             printf("%c", grid[k][l]);       
        }
         
    printf("\n");
    }
    */
 }

 //checks whether the provided co-ordinates are within the grid. Returns 0 if they are valid, 1 otherwise.
 
int isValid (int width, int height){
    if (width!=0 && width!=Gwidth){
        if (height!=0 && height!=Gheight){
            return 0;
        }
        else return 1;
    }
    else return 1;
}


//Initialises the bombgrid with bomb values, each co-ordinate is stored consecutively in the array, so sorting of the x,y pair is needed later.
void placeBombs(int bombgrid[20], int width, int height){
    int counter=0;
    int Bwidth;
    int Bheight;
    int nargs;
    char identifier;
    char input[10];
    //char bombgrid[4];

    while (counter<2){
    printf("Please enter Bomb co-ordinate number %d \n", counter+1);
    fgets(input, sizeof(input), stdin);
    nargs = sscanf(input, "%c %d %d\n", &identifier, &Bwidth, &Bheight);
    if (identifier=='q'){
        //(identifier!='b' || isValid(width, height)==1){
        printf("invalid input, try again \n");
        break;

        }
        else{
            printf("Bomb placed at %d, %d, \n", Bwidth, Bheight);
            bombgrid[counter*2]=Bwidth;
            bombgrid[counter*2+1]=Bheight;
            counter++;
        }
    }
}

printBoard(grid[100][100], int width, int height){
printf("this is coming from printboard function \n");

   for (int k = 0; k< height+2; ++k)
     {
         for (int l = 0; l < width+2; ++l)
         {
             printf("%c", grid[k][l]);       
        }
         
    printf("\n");
    }
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
        printf("not a valid letter command \n");
        return 1;
    }
    if (nargs<3){
        printf("invalid format....");
        return 1;
    }
    if (width>100 && height>100){
        printf("grid is too big");
        return 1;
    }

    makeArray(grid, width, height);
    printBoard(grid, width, height);
    placeBombs(bombgrid, width, height);
    

  for (int i = 0; i < 4; ++i)
  {
      printf("Bomb %d is %d \n", i*2+1, bombgrid[i*2]);
      printf("Bomb %d is %d \n", i*2+2, bombgrid[i*2+1]);
  }
  int totalMoves=height*width;
  for (int j=0; j<totalMoves+1; ++j){


  }
bombCheck(bombgrid, xcord, ycord)
    /*
    makeArray(grid, width, height);
    printBoard(grid, width, height);
    int *bombGridStart= placeBombs(grid, width, height);
    printf("%d, \n" ,*bombGridStart);


for (int i = 0; i < 2; ++i)
    {   
        
        printf("Bomb %d, is %c ,%c\n", i+1, bombgrid[ i*2], bombgrid[i*2+1]);
    }


    for (int i = 0; i < 2; ++i)
    {   
        
        printf("Bomb %d, is %c ,%c\n", i+1, *bombGridStart+ i*2, *bombGridStart+(i*2)+1);
    }
    */


    //scanf("%c %d %d", &identifier, &width, &height );
    //printf("the identifier was %c, the width  and height is %d, %d \n", identifier, width, height);
    //makeArray(width,height);
    //placeBombs();

    return 0;
}


