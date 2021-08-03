#include<stdio.h>
#include<stdlib.h>

struct treenode{
  int value;
  struct treenode *left;
  struct treenode * right;
};
struct treenode* root = NULL;
struct treenode* findMin(struct treenode*);
void insertNode(int);
//void printtree(struct treenode*);
void freetree(struct treenode*);
void searchNode(int);
void deleteNode(int);


//FUNCTIONS:

struct treenode* findMin(struct treenode* subtreehead){

  struct treenode* ptr = subtreehead;
  struct treenode* prev = NULL;
  
  while(ptr->left !=NULL){
    prev = ptr;
    ptr = ptr->left;
  }

  if(ptr == subtreehead){
    return ptr;
  }
  else{
    return prev;
  }
}

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

    //current node is greater than target (move left)
    else if (ptr->value > target){
      // prev = ptr;
      ptr = ptr->left;
      height++;
      if (ptr==NULL){
	break;
      }
    }
    
    //current node is lesser than the target (move right)
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

void deleteNode(int target){
  //first step: find the target value in the BST:
  struct treenode* ptr = root;
  struct treenode* prev = NULL;

  //EMPTY TREE:
  if (ptr == NULL){
    printf("fail\n");
    return;
  }

  //FINDING TARGET:

  while(ptr!=NULL){
    //target found
    if (ptr->value == target){
      if (prev==NULL){
	prev = ptr;
	break;
      }
      break;
    }
    //current node is greater than target (move left)
    else if (ptr->value > target){
      prev = ptr;
      ptr = ptr->left;
      if (ptr==NULL){
	break;
      }
    }
    //current node is lesser than the newKey (move right)
    else{
      prev = ptr;
      ptr=ptr->right;
      if (ptr==NULL){
	break;
      }
    }
  }

  //DELETION:

  if (ptr == NULL){
    printf("fail\n");
    return;
  }

   struct treenode* head = NULL;
   

  //case 1: ptr has two children:

  if (ptr->left != NULL && ptr->right != NULL){


    //find minimum node in the right subtree:
    head = ptr->right;
    struct treenode* parentofmin = NULL;
    struct treenode* min = NULL;
    parentofmin = findMin(head);

    // if min is the head of right sub tree
    if(parentofmin->left == NULL){
      min = parentofmin;
    }
    // if min is below the head of right sub tree
    else{
    min = parentofmin->left;
    }

    
    //if min has no children
    if (min->left == NULL && min->right == NULL){
      if(min == parentofmin){
	ptr->value = min->value;
	ptr->right = min->left;
      }
      else{
	ptr->value = min->value;
	parentofmin->left=min->right;
	printf("success\n");
	return;
      }
    }
    
    //if min has a right child
    if (min->left == NULL && min->right != NULL){
      ptr->value = min->value;
      // if min is the head of right sub tree
      if (min == parentofmin){
	ptr->right = min->right;
       	printf("success\n");
	return;
      }
      // if min is below the head of right sub tree
      else{
	parentofmin->left=min->right;
	printf("success\n");
	return;
      }

    }

    /* temp = ptr->left;
    prev = ptr;
    while (temp->right != NULL){
      prev = temp;
      temp = temp->right;
    }
    ptr->value = temp->value;
    prev->right = temp->right;
    printf("success\n");
    return;*/

  }

  //case 2: ptr has one child and one leaf node:

   struct treenode* temp2 = NULL;
   if (ptr->right != NULL){
     temp2 = ptr->right;
   }
   else{
     temp2 = ptr->left;
   }

   if (ptr == prev->left){
     if (prev == ptr){
       root=temp2;
     }
     else{
     prev->left = temp2;
     }
     printf("success\n");
     return;
   }
   else{
     if (prev==ptr){
       root=temp2;
     }
     else{
       prev->right = temp2;
     }
     printf("success\n");
     return;
   }

}
























//MAIN METHOD:

int main (int argc, char** argv){




  FILE* fp = fopen(argv[1], "r");
  if (fp==NULL){
    printf("error");
  }

  int num=0;
  char letter;
  root=NULL;
  int check=0;

  while(fscanf(fp, "%c\t%d\n", &letter, &num) != EOF){
  
    if (letter == 'i'){
      insertNode(num);
      check++;
    }
    else if (letter == 's'){
      searchNode(num);
      check++;
    }
    else if (letter == 'd'){
      deleteNode(num);
      check++;
  }
  }
  
  if (check==0){
    printf("error");
  }

  // printtree(root);
  freetree(root);
  fclose(fp);
  return 0;
}
