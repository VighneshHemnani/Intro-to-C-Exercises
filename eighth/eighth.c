#include<stdio.h>
#include<stdlib.h>

struct treenode{
  int value;
  struct treenode *left;
  struct treenode * right;
};
struct treenode* root = NULL;
void insertNode(int);
//void printtree(struct treenode*);
void freetree(struct treenode*);
void searchNode(int);


//FUNCTIONS:


/*struct treenode* createtreenode(int value){
  struct treenode* temp = malloc(sizeof(struct treenode));
  temp->value = value;
  temp->left = NULL;
  temp->right = NULL;
  printf("allocated treenode to number %d",value);
  return temp;
  }*/

void insertNode(int newKey){

  struct treenode* temp = malloc(sizeof(struct treenode));
  temp->value = newKey;
  temp->left = NULL;
  temp->right = NULL;

  struct treenode* ptr = root;
  struct treenode* prev = NULL;
  int counter = -1;
  int height = 1;
  
  //if the tree is empty
  if (ptr == NULL){
    root = temp;
    printf("inserted %d\n",height);
    return;
  }


  //if the tree is not empty
  while(ptr!=NULL){
    //duplicate value found
    if (ptr->value == newKey){
      printf("duplicate\n");
      return;
    }

    //current node is greater than newKey (move left)
    else if (ptr->value > newKey){
      prev = ptr;
      ptr = ptr->left;
      counter = 0;
      height++;
      if (ptr==NULL){
	break;
      }
    }
    
    //current node is lesser than the newKey (move right)
    else{
      prev = ptr;
      ptr=ptr->right;
      counter = 1;
      height++;
      if (ptr==NULL){
	break;
      }
    }
    
  }
  

  //inserting new node at the failure point
  if (counter == 0){
    prev->left  = temp;
    printf("inserted %d\n",height);
    return;
  }
  else{
    prev->right = temp;
    printf("inserted %d\n",height);
    return;
  }
  return;
}

/*void printtree(struct treenode* currNode){

  if (currNode == NULL){
    return;
  }
  printf("%d",currNode->value);
  printtree(currNode->left);
  printtree(currNode->right);
  
}*/

void freetree(struct treenode* currNode){
  if (currNode == NULL){
    return;
  }
  freetree(currNode->left);
  freetree(currNode->right);
  free(currNode);
  
  }

void searchNode(int target){

  struct treenode* ptr = root;
  int height = 1;
  
  //if the tree is empty
  if (ptr == NULL){
    printf("absent\n");
    return;
  }


  //if the tree is not empty
  while(ptr!=NULL){
    //target found
    if (ptr->value == target){
      printf("present %d\n",height);
      return;
    }

    //current node is greater than newKey (move left)
    else if (ptr->value > target){
      // prev = ptr;
      ptr = ptr->left;
      height++;
      if (ptr==NULL){
	break;
      }
    }
    
    //current node is lesser than the newKey (move right)
    else{
      ptr=ptr->right;
      height++;
      if (ptr==NULL){
	break;
      }
    }
  }
printf("absent\n");
  
}











//MAIN METHOD:

int main (int argc, char** argv){




  FILE* fp = fopen(argv[1], "r");
  int num=0;
  char letter;
  root=NULL;

  while(fscanf(fp, "%c\t%d\n", &letter, &num) != EOF){
  
    if (letter == 'i'){
      insertNode(num);
    }
    else if (letter == 's'){
      searchNode(num);
    }
  }

  // printtree(root);
  freetree(root);
  fclose(fp);
  return 0;
}
