#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//structure to represent the integer stack
struct stack
{
  int top;
  unsigned capacity;
  int* array;
};

//function to create stack
struct stack* createStack(unsigned capacity)
{
  struct stack* s=(struct stack*)malloc(sizeof(struct stack));
  s->capacity=capacity;
  s->top=-1;

  s->array=(int*)malloc(s->capacity*sizeof(int));
  return s;
}


//function to check whether stack is full
//useful to prevent overflow
int checkFull(struct stack* s)
{
  return s->top==s->capacity-1;
}


//function to check whether stack is empty
//useful to prevent underflow
int checkEmpty(struct stack* s)
{
  return s->top==-1;
}


//function to perfrom push operation
//takes two arguements;number to pushed;stack
void push(int pushnum,struct stack* s)
{
  if(checkFull(s))
  {
    printf("Stack Full\n");
    printf("Overflow\n");
    return;
  }
  s->array[++s->top]=pushnum;
  printf("Pushed %d\n",pushnum);
}


//function to pop element from stack
int pop(struct stack* s)
{
  if(checkEmpty(s))
  {
    printf("Stack Empty\n");
    printf("Underflow\n" );
    return INT_MIN;
  }
    return s->array[s->top--];
}



//peek function to return the topmost element of the stack
int peek(struct stack* s)
{
  if(checkEmpty(s))
  {
    return INT_MIN;
  }
  return s->array[s->top];
}


int main()
{
  unsigned cap;
  printf("Enter Capacity of Stack\n");
  scanf("%d",&cap);
  struct stack* s=createStack(cap);
  stackMenu(s);
  return 0;
}



void stackMenu(struct stack* s)
{
  int opt,item;
  printf("Enter Option\n");
  printf("1.Push\n");
  printf("2.Pop\n" );
  printf("3.Peek\n");
  printf("4.Check Empty\n" );
  printf("5.Check Full\n" );
  printf("6.Display Stack\n");
  printf("7.Exit\n");
  scanf("%d",&opt);
  switch (opt) {
    case 1:
        scanf("%d",&item);
        push(item,s);
        stackMenu(s);
        break;
    case 2:
        printf("Popped %d\n",pop(s));
        stackMenu(s);
        break;
    case 3:
        printf("Peek %d\n",peek(s));
        stackMenu(s);
        break;
    case 4:
        if(checkEmpty(s))
        {
          printf("Empty\n");
        }
        else
        {
          printf("Not Empty\n");
        }
        stackMenu(s);
        break;
    case 5:
        if(checkFull(s))
        {
          printf("Full\n");
        }
        else
        {
          printf("Not Full\n");
        }
        stackMenu(s);
        break;
    case 6:
        displayStack(s);
        stackMenu(s);
        break;
    case 7:
        exit(0);
  }
}



void displayStack(struct stack* s)
{
  int topindex=s->top;
  printf("Top  -> ");
  for(int i=topindex;i>=0;i--)
  {
    printf("%d\n",s->array[i]);
    printf("\t");
  }
  printf("\n" );
}
