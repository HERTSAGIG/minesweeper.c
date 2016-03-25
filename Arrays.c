#include <stdio.h>
 
int main (void){
     int width=9;
     int height=99;
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