#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<limits.h>


struct stack
{
  int top;
  unsigned capacity;
  char* array;
};

struct stack* createStack(unsigned capacity)
{
  struct stack* s=(struct stack*)malloc(sizeof(struct stack));
  s->capacity=capacity;
  s->top=-1;
  s->array=(char*)malloc(capacity*sizeof(char));
}

void push(struct stack* s,char c)
{
  if(isFull(s))
  {
    return;
  }
  s->array[++s->top]=c;
}

char pop(struct stack* s)
{
  if(isEmpty(s))
  {
    return '$';
  }
  return s->array[s->top--];
}

int isFull(struct stack* s)
{
  return s->top == s->capacity -1;
}

int isEmpty(struct stack* s)
{
  return s->top == -1;
}

int main()
{
  char strval[80];
  printf("Enter String:" );
  scanf("%[^\n]s",strval);

  struct stack* s=createStack(strlen(strval));
  int i=0;
  while (!isFull(s)) {
    push(s,strval[i]);
    i++;
  }
  i=0;
  while(!isEmpty(s))
  {
    strval[i]=pop(s);
    i++;
  }
  printf("Reverse of String:%s\n",strval);
}
