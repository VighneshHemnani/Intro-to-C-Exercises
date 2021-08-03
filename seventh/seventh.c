#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv){

  
    

    for (int  i = 1; i<argc;i++){
     
      // int currlen = strlen(argv[i]);
      //char* res  = malloc(sizeof(char)*(currlen));
      // strcpy(res, argv[i]);
      // printf("%c",res[currlen-1]);


      printf("%c",argv[i][strlen(argv[i])-1]);

    }

    // printf("\n\n%s\n\n",res);


   // printf("\n\n%c\n\n",argv[1][4]);

  return 0;
}



