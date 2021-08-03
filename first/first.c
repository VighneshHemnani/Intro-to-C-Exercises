#include<stdio.h>
#include<stdlib.h>

int isTruncPrime(int);

int isTruncPrime(int input){

  int temp = input;
  int isnotprime = -1;

  while(temp!=0){
    int counter = 0;
    int start = 1;
    for (start = 1; start  <= temp ; start++){
      if (temp % start==0){
	counter++;
      }
    }
    if (counter==2){
      temp=temp/10;
      continue;
    }
    else if (counter >2){
      isnotprime=1;
      break;
    }
  }

  if (isnotprime==1){
    return isnotprime;
  }
  else if (isnotprime==-1){
    return isnotprime;
  }
  else{
    return isnotprime;
  }
  return isnotprime;
}

int main(int argc, char** argv){

 if (argc != 2){
    printf("insufficient arguments\n");
    exit(0);
  }
  FILE* fp = fopen(argv[1], "r");
  if(fp == NULL){
    printf("file does not exist\n");
    exit(0);
  }

  int num = 0;
  /* Now read the first line in the file */
  if(fscanf(fp, "%d\n", &num) == EOF){
    printf("empty file\n");
    exit(0);
  }

  for(int i = 0; i< num; i++){
    int hello;
    int result = 0;
    fscanf(fp, "%d\n", &hello);
    result =  isTruncPrime(hello);
      if (result == 1){
	printf("no\n");
      }
      else if (result==-1){
	printf("yes\n");
      }
    }

  fclose(fp);
  return 0;

}
