#include<stdio.h>
#include<stdlib.h>

int magiccheck(int**, int);
int uniquematrix(int*,int);
int** allocate_matrix(int);

int magiccheck(int** matrix, int size){

  int target = 0;
  //first set benchmark using first column:
  for(int i = 0; i < size ; i++){
    target = target + matrix[i][0];
  }


  //check if diagonals == target
  int diag1 = 0;
  int diag2 = 0;

  for (int i = 0; i < size ; i++){
    for (int j = 0; j < size ; j++){
      if (i == j){
	diag1 = diag1 + matrix[i][j];
      }
      if ( (i+j) == size - 1){
	diag2 = diag2 + matrix[i][j];
      }
    }
  }

  if (diag1 == target && diag2 == target){
    //check if rows are equal
    int sum =0;
    for (int i = 0 ; i < size ; i++){
      for(int j = 0; i < size ; i++){
        sum = sum + matrix[i][j];
      }
      if (sum != target){
	return 0;
      }
      sum = 0;
    }

    //check if cols are equal
    sum = 0;
    for (int j = 0; j < size ; j++){
      for (int i = 0; i < size ; i++){
	sum = sum + matrix[i][j];
      }
      if (sum != target){
	return 0;
      }
      sum = 0;
    }

    return 1;
  }
  else{
    return 0;
  }





}




int uniquematrix(int* data, int size){
  int counter = 0;
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      if (data[i] == data[j]){
	counter++;
      }
    }
    if (counter == 1){
      counter = 0;
    }
    else if (counter > 1){
      return 0;
    }
  }

  return 1;
}

   
int** allocate_matrix(int n){
  
  int** ret_val = malloc(n * sizeof(int*));
  for(int i = 0; i< n; i++){
    ret_val[i] = malloc(n * sizeof(int));
  }
  return ret_val;
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

  //STORING VALUES

  int n;
   if ( fscanf(fp,"%d ", &n) == EOF){
     printf("error");
     exit(0);
   }
 
  int counter = 1;
  int checkexit = 0;
  int entry;
  int * data = malloc(n*n*sizeof(int));
  int index  = 0;
  int linecounter = 0;

  while(linecounter != n){
   do{
     if ( fscanf(fp,"%d ", &entry) !=EOF){
      data[index] = entry;
      index++;
      counter++;
     }
     else{
       checkexit = 1;
       break;
     }
   } while(counter != n);
   if (counter == n && checkexit == 1){
     fscanf(fp, "%d\n", &entry);
       data[index] = entry;
       index++;
       counter = 0;
   }
     
  
  
   if (linecounter == n-1){
     break;
   }
   linecounter++;
  }


    





  fclose(fp);

  //MAKING MATRIX

   int ** matrix;
   matrix = allocate_matrix(n);
   index = 0;

   for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
	matrix[i][j] = data[index];
	index++;
    }
   }
   
   //CHECK MATRIX

   int unique = 0;
   int magic = 0;
   unique = uniquematrix(data,n*n);

   if (unique == 0){
     printf("not-magic\n");
     //free matrix
     exit(0);
   }
   else if (unique == 1){
     magic = magiccheck(matrix, n);
   }

   if (magic == 0){
      printf("not-magic\n");
     //free matrix
     exit(0);
   }
   else if (magic == 1){
     printf("magic\n");
     //free matrix
     exit(0);
     }

  return 0;
}
