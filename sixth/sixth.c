#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char ** argv){
  int vloc = -1;

  
    for(int i = 1; i < argc ; i++){

      for (int j = 0 ; j < strlen(argv[i]);j++){
	if (argv[i][j] == 'A'|| argv[i][j] == 'E' || argv[i][j] == 'I' || argv[i][j] == 'O' || argv[i][j] == 'U' || argv[i][j] == 'a'|| argv[i][j] == 'e' || argv[i][j] == 'i' || argv[i][j] == 'o' || argv[i][j] == 'u'){
	  vloc = j;
	  break;
	}
      }

      //starts with a consonant
    if (vloc > 0){
      for (int k = vloc ; k < strlen(argv[i]);k++){
	printf("%c",argv[i][k]);
      }
      for (int k = 0 ; k<vloc;k++){
	printf("%c",argv[i][k]);
      }
      printf("ay");
    }
   
      //starts with a vowel
    else if (vloc == 0){
      printf("%s",argv[i]);
      printf("yay");
    }
    printf(" ");
    }
  return 0;
}

