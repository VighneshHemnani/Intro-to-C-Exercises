#include<stdio.h>
#include<stdlib.h>

int** allocate_matrix(int, int);

int** allocate_matrix(int rows, int cols){
  
  int** ret_val = malloc(rows * sizeof(int*));
  for(int i = 0; i< rows; i++){
    ret_val[i] = malloc(cols * sizeof(int));
  }
  return ret_val;
}

int main (int argc, char** argv){

//1.INPUTTING VALUES:
  if (argc != 2){
      printf("insufficient arguments\n");
      exit(0);
    }
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL){
      printf("file does not exist\n");
      exit(0);
    }

    //1.1READING IN THE FIRST MATRIX:
    int m1r = 0;
    int m1c = 0;
    //1.1.2DIMENSIONS:
    if(fscanf(fp, "%d\t%d\n", &m1r, &m1c) == EOF){
      printf("empty file\n");
      exit(0);
    }
    //1.1.2VALUES
    int * data1 = malloc(m1r*m1c*sizeof(int));
    int counter = 0;
    int index = 0;
    int temp  = 0; 
    for (int i = 0 ; i < m1r ; i++){
      while(counter != m1c-1){
        fscanf(fp, "%d\t", &temp);
	data1[index] = temp;
        index++;
        counter++;
      }
      if (counter == m1c-1){
	fscanf(fp, "%d\n",&temp);
	data1[index]=temp;
	index++;
	counter = 0;
      }
    }


    /*printf("\nPRINTING ARRAY: ");
    for (int i = 0; i < m1r*m1c ; i++){
      printf("%d ",data1[i]);
     }*/


    //1.2 READING IN THE SECOND MATRIX:
    //1.2.1 DIMENSIONS:
    int m2r = 0;
    int m2c = 0;
    fscanf(fp, "%d\t%d\n", &m2r, &m2c);
    //1.2.2 VALUES
    int * data2 = malloc(m2r*m2c*sizeof(int));
    counter = 0;
    index = 0;
    temp  = 0; 
    for (int i = 0 ; i < m2r ; i++){
      while(counter != m2c-1){
        fscanf(fp, "%d\t", &temp);
	data2[index] = temp;
        index++;
        counter++;
      }
      if (counter == m2c-1){
	fscanf(fp, "%d\n",&temp);
	data2[index]=temp;
	index++;
	counter = 0;
      }
    }

    //INITIALIZING MATRCIES WITH VALUES
    int ** matrix1 = allocate_matrix(m1r, m1c);
    int ** matrix2 = allocate_matrix(m2r, m2c);
    index = 0;
    for(int i = 0; i < m1r; i++){
      for(int j = 0; j < m1c; j++){
	matrix1[i][j] = data1[index];
	index++;
      }
    }
    index = 0;
    for(int i = 0; i < m2r; i++){
      for(int j = 0; j < m2c; j++){
	matrix2[i][j] = data2[index];
	index++;
      }
    }

    //CHECK IF MATRIX MULTIPLCATION IS POSSIBLE

    if (m1c != m2r){
      printf("bad-matrices");
      return 0;
    }
    else if (m1c == m2r){
      //NEW MATRIX

      int ** result = allocate_matrix(m1r, m2c);
      for (int i = 0; i < m1r; i++){
	for (int j = 0; j < m2c ; j++){
	  result[i][j] = 0;
	  for (int k = 0; k < m1c ; k++){
	    result[i][j] += matrix1[i][k] * matrix2[k][j];
	  }
	}
      }

      //PRINTING MATRIX:
      for (int i = 0; i < m1r; i++){
	for (int j = 0; j < m2c; j++){
	  if (j == m2c-1){
	    printf("%d\n",result[i][j]);
	  }
	  else{
	    printf("%d\t",result[i][j]);
	  }
	}
      }
    }
 fclose(fp);
 return 0;
}
