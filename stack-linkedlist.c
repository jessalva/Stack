#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

//create structure for stack
struct stackNodes
{
  int data;
  struct stackNodes* next;
};


//create function that generates and return stack Nodes
struct stackNodes* createNode(int data)
{
  struct stackNodes* new_node=(struct stackNodes*)malloc(sizeof(struct stackNodes));
  new_node->data=data;
  new_node->next=NULL;
  return new_node;
}

//push function for stack
void push(struct stackNodes** root,int data)
{
  struct stackNodes* push_node=createNode(data);
  push_node->next=*root;//link previous linked list with stack
  *root=push_node;//set pushed node as top of the stack
  printf("%d Pushed on to stack\n",(*root)->data);
}

//checks whether stack is empty or not
int isEmpty(struct stackNodes* root)
{
  return !root;//true when root is NULL
}

//pop function for stack
int pop(struct stackNodes** root)
{
  if(isEmpty(*root))
  {
    return INT_MIN;
  }
  struct stackNodes* popNode=*root;
  *root=(*root)->next;
  int popvalue=popNode->data;
  free(popNode);

  return popvalue;
}

//return peek value of stack
int peek(struct stackNodes* root)
{
  if(isEmpty(root))
  {
    return INT_MIN;
  }
  return root->data;
}


int main()
{
  struct stackNodes* root=NULL;
  stackMenu(root);
  return 0;
}

//Function for displaying Menu for Stack operation
void stackMenu(struct stackNodes* root)
{
  int opt,item;
  printf("Enter Option\n");
  printf("1.Push\n");
  printf("2.Pop\n" );
  printf("3.Peek\n");
  printf("4.Check Empty\n" );
  printf("5.Display Stack\n");
  printf("6.Exit\n");
  scanf("%d",&opt);
  switch (opt) {
    case 1:
        scanf("%d",&item);
        push(&root,item);
        stackMenu(root);
        break;
    case 2:
        printf("Popped %d\n",pop(&root));
        stackMenu(root);
        break;
    case 3:
        printf("Peek %d\n",peek(root));
        stackMenu(root);
        break;
    case 4:
        if(isEmpty(root))
        {
          printf("Empty\n");
        }
        else
        {
          printf("Not Empty\n");
        }
        stackMenu(root);
        break;
    case 5:
        displayStack(root);
        stackMenu(root);
        break;
    default:
        exit(0);
  }
}


void displayStack(struct stackNodes* root)
{
  struct stackNodes* dispNode=root;
  printf("Top\n");
  while(dispNode!=NULL)
  {
    printf("%d\n",dispNode->data);
    dispNode=dispNode->next;
  }
}
