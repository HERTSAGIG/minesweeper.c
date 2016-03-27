# include <stdio.h>

int main()
{
	printf("please enter a grid size to play on type g int int \n");
	int width;
	int height;
	char identifier;
	scanf("%c %d %d", &identifier, &width, &height );
	printf("the identifier was %c, the width  and height is %d, %d \n", identifier, width, height);
	Arrays(width,height);
	return 0;
}

int Arrays(int width1, int height1){
     int width=width1;
     int height=height1;
     int game [height][width];
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
                 game [i][j]=corner;
             }
        else if (i==0 || i==height-1)
            {
            game [i][j]=top;
            }
        else if (j==0 ||j==width-1){
            game [i][j]=sides;   
            }
            else{
            game [i][j]= stars;       
            }
        }
    }   
     for (int k = 0; k< height; ++k)
     {
         for (int l = 0; l < width; ++l)
         {
             printf("%c", game[k][l]);       
        }
         
    printf("\n");
    }
     return 0;
 }