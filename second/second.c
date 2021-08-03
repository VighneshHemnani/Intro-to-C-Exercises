#include<stdio.h>
#include<stdlib.h>

struct node{
  int value;
  struct node * next;
};
struct node * head = NULL;
void freeLL();
void insertNode(int);
void deleteNode(int);
void printLL();

void freeLL(){
  struct node* temp = head;
  while(temp != NULL){
    struct node * temp2 = temp;
    temp = temp->next;
    free(temp2);
  }
}

void insertNode(int newvalue){
  struct node* temp = malloc(sizeof(struct node));
  temp->value = newvalue;
  temp->next = NULL;
  //EMPTY LINKED LIST:
  if (head == NULL){
    head = temp;
    return;
  }
  //NON-EMPTY LINKED LIST:
  else if (head!=NULL){
    struct node* ptr = head;
    struct node* follow = NULL;
    while(ptr != NULL){
      //beginning or middle of LL
      if ((ptr->value) > newvalue){
	 temp->next = ptr;
	 if (follow==NULL){
	   head = temp;
	   return;
	 }
	 else if (follow!=NULL){
	   follow->next=temp;
	   return;
	 }
      }
      if ((ptr->value) == newvalue){
	return;
      }
      follow=ptr;
      ptr = ptr->next;
    }
     //end of LL
     if(follow!=NULL){
       follow->next = temp;
       temp->next = NULL;
        return;
     }
  }
}

void deleteNode(int target){

  struct node* ptr = head;
  struct node* follow  = NULL;

  while(ptr!=NULL){
    //finding position of target in LL
    if (ptr->value == target){
      break;
    }
    follow=ptr;
    ptr = ptr->next;
  }



  //target does not exist in LL
  if (ptr==NULL){
    return;
  }
  //target is the first node
  else if (ptr == head){
    head = head->next;
  }
  //target is in the middle of the LL
  else{
    follow->next = ptr->next;
  }

}



void printLL(){
    struct node* temp = head;
    int counter = 0;

    while(temp!=NULL){
      counter++;
      temp = temp->next;
    }
    printf("%d\n",counter);
    temp = head;
    while(temp != NULL){
      printf("%d\t", temp->value);
      temp = temp->next;
    }
    printf("\n");
}






int main (int argc, char** argv){
 
 //incorrect arguments
  if (argc != 2){
    printf("error: insufficient arguments\n");
    exit(0);
  }


  //OPENING FILES AND CREATING NECCESSARY VARIABLES
  FILE* fp = fopen(argv[1], "r");
  if(fp == NULL){
    printf("error\n");
    exit(0);
  }
  int isFileEmpty = 0;
  char letter;
  int num = 0;

  

  //INSERTING/DELETING NUMBERS
  while(fscanf(fp, "%c\t%d\n", &letter, &num) != EOF){
    isFileEmpty++;
    if (letter == 'i'){
      insertNode(num);
      
      continue;
    }
    else if (letter == 'd'){
      deleteNode(num);
      
      continue;
    }
  }



  //PRINTING OUT LINKED LIST

  if(isFileEmpty==0){
    printf("0");
  }
  else if (isFileEmpty>0){
    printLL();
    //printf("PRINTING NON-EMPTY LINKED LIST.");
  }
 
  //CLOSING FILE ACCESS AND FREEING MEMORY

  freeLL();
  fclose(fp);
  return 0;
}
