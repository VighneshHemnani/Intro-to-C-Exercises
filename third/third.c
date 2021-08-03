#include<stdio.h>
#include<stdlib.h>

struct node{
  int value;
  struct node * next;
};
struct node * hashtable[1000];
int hashfunction(int);
void insertNum(int);
void searchNum(int);


int hashfunction(int key){
  int i;
  
  i = abs(key) % 1000;
  return i;
}

void insertNum(int key){

  //CREATE NODE:

  struct node * temp = malloc(sizeof(struct node));
  temp->value = key;
  temp->next = NULL;

  //CREATE HASHKEY:                                      

  int index = hashfunction(key);

  //INSERT:

    //case 1: if array element is EMPTY

  if (hashtable[index] == NULL){
    hashtable[index] = temp;
    printf("inserted\n");
    return;
  }


    //case 2; if array element is not EMPTY (ADD TO FRONT ALGORITHM)

  else if (hashtable[index] != NULL){
    struct node * ptr = hashtable[index];
    struct node * curr = ptr;
    while(curr!= NULL){
      if (curr->value == temp->value){
	printf("duplicate\n");
	return;
      }
      curr=curr->next;
    }
    temp->next = ptr;
    hashtable[index] = temp;
    printf("inserted\n");
    return;
  }
}


void searchNum(int target){

 int index = hashfunction(target);
 struct node * ptr;
 if (hashtable[index] == NULL){
   printf("absent");
 }
 else if (hashtable[index] != NULL){

   ptr = hashtable[index];
   while(ptr != NULL){
     if (ptr->value == target){
       printf("present\n");
       return;
     }
     ptr=ptr->next;
   }
   printf("absent\n");
   return;

 }
}




  int main(int argc, char** argv){
    
    FILE* fp = fopen(argv[1], "r");

    if(fp == NULL){
      printf("file does not exist\n");
      exit(0);
    }

    char letter;
    int number;

    while(fscanf(fp, "%c\t%d\n", &letter, &number) != EOF){
     
      //insert number into the hash table
      if (letter == 'i'){
	insertNum(number);
      }
      //search number in the hash table
      else if (letter == 's'){
	searchNum(number);
      }
    }
  

    fclose(fp);
    return 0;
  }
