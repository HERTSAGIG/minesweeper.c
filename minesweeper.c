# include <stdio.h>

int main()
{
	printf("please enter a grid size to play on type g int int \n");
	int width;
	int height;
    int nargs;
	char identifier;
    char input[10];
    int grid[100][100];
    
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
   
    
    makeArray(grid[100][100],width, height);
    //printBoard();
	//scanf("%c %d %d", &identifier, &width, &height );
	//printf("the identifier was %c, the width  and height is %d, %d \n", identifier, width, height);
	//makeArray(width,height);
    //placeBombs();

	return 0;
}

int makeArray(grid[100][100], int widthIn, int heightIn){
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
     for (int k = 0; k< height; ++k)
     {
         for (int l = 0; l < width; ++l)
         {
             printf("%c", grid[k][l]);       
        }
         
    printf("\n");
    }
     return 0;
 }
 //checks whether the provided co-ordinates are valid or not. Returns 0 if they are valid, 1 otherwise.
 /*
int isValid (int width, int height){
    if (width!=0 && width!=Gwidth){
        if (height!=0 && height!=Gheight){
            return 0;
        }
        else return 1;
    }
    else return 1;
}
void placeBombs(){
    int counter=0;
    int width;
    int height;
    int nargs;
    char identifier;
    char input[10];

    while (counter<10){}
    fgets(input, sizeof(input), stdin);
    nargs = sscanf(input, "%c %d %d\n", &identifier, &width, &height);
    if (identifier!='b' || isValid(width, height)==1){
        printf("invalid input, try again");
        }
        else{

        }
    }

int printBoard(){
printf("this is coming from printboard function \n");

printf("%c \n",Globalboard[4][4]);

   /* for (int k = 0; k< Gheight; ++k)
     {
         for (int l = 0; l < Gwidth; ++l)
         {
             printf("%c", Globalboard[k][l]);       
        }
         
    printf("\n");
    }
    return 0;
    */
	


