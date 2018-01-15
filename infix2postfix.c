#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

//stack is used to push opening parenthesis(pop till same when closing parenthesis are seen)
//and operators according their precedences
struct stack
{
  int top;
  unsigned capacity;
  int* array;
};

struct stack* createStack(unsigned capacity)
{
  struct stack* s=(struct stack*)malloc(sizeof(struct stack));
  s->capacity=capacity;
  s->top=-1;
  s->array=(int*)malloc(s->capacity*sizeof(int));
  return s;
}

int isEmpty(struct stack* s)
{
  return s->top==-1;
}

char peek(struct stack* s)
{
  return s->array[s->top];
}

void push(struct stack *s,char op)
{
  s->array[++s->top]=op;
}

char pop(struct stack* s)
{
  if(isEmpty(s))
  {
    printf("Underflow\n");
    return '$';
  }
  return s->array[s->top--];
}

int isOperand(char ch)
{
  return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9');
}

int precedence(char ch)
{
  switch (ch) {
    case '+':
    case '-':
          return 1;
    case '*':
    case '/':
          return 2;
    case '^':
          return 3;
  }
  return -1;
}

int infix2postfix()
{
  char exp[80];
  int i=0,k=-1;
  printf("Enter Expression\n");
  scanf("%s",exp);
  char* postexp=(char*)malloc(strlen(exp)*sizeof(char));
  struct stack* s=createStack(strlen(exp));
  while(exp[i]!='\0')
  {
    if(isOperand(exp[i]))
    {
      postexp[++k]=exp[i];
    }
    else if(exp[i]=='(')
    {
      push(s,exp[i]);
    }
    else if(exp[i]==')')
    {
      while(!isEmpty(s) && peek(s)!='(')
      {
        postexp[++k]=pop(s);
      }
      if(!isEmpty(s) && peek(s)!='(')
      {
        return -1;
      }
      else
      {
        pop(s);
      }
    }
    else
    {
      while(!isEmpty(s) && precedence(exp[i])<=precedence(peek(s)))
      {
        postexp[++k]=pop(s);
      }
      push(s,exp[i]);
    }
    i++;
  }
  while(!isEmpty(s))
  {
    postexp[++k]=pop(s);
  }
  postexp[++k]='\0';
  printf("Postfix Expression:%s\n",postexp);
}
int main()
{
  infix2postfix();
}
