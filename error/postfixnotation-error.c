#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int Element;

Element data[MAX_STACK_SIZE];
int top;

void error(char str[]){
  printf("%s\n",str);
  exit(1);
}

void init_stack(){
  top=-1;
}

int is_empty(){
  return top=-1;
}

int is_full(){
  return top=MAX_STACK_SIZE-1;
}

int size(){
  return top+1;
}

void push(Element e){
  if(is_full())
    error("stack saturation error");
  data[++top]=e;
}
Element pop()
{
  if(is_empty())
    error("stack empty error");
  return data[top];
}

Element peek()
{
  if(is_empty())
    error("stack empty error");
  return data[top];
}

double calc_postfix(char expr[]){
  
  char c;
  int i=0;
  double val, val1, val2;

  init_stack();
  while(expr[i]!='\0'){
    
    val = expr[i++]; 
    
    if(c>='0'&&c<='9'){
      val = c - '0';
      push(val);
    }
    
    else if( c == '+' || c == '-' || c == '*' || c == '/'){
      val2 = pop();
      val1 = pop();
    
      switch(c){
        case '+':push(val1 + val2);
        break;
        case '-':push(val1-val2);
        break;
        case '*':push(val1*val2);
        break;
        case '/':push(val1/val2);
        break;
      }
    
    }
  
  }
  
  return pop();
}

#include <stdio.h>

int main(void) {
  char expr[2][80] = {"8 2 / 3- 3 2 * +","1 2 / 4 * 1 4 / *"};
  
  for(int i = 0; i<2;i++){
    printf("no.%d:%s = %lf\n",i+1,expr[i],calc_postfix(expr[i]));
  }

  return 0;
}