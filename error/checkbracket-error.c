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
  return top==MAX_STACK_SIZE-1;
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
  return data[top--];
}

Element peek()
{
  if(is_empty())
    error("stack empty error");
  return data[top];
}

int check_matching(char expr[]){

  int i, prev; 
  
  char ch;
  
  init_stack();
  
  while(expr[i] != '\0'){
  
    ch = expr[i];
  
    if(ch =='['|| ch == '('||ch =='{')
      push(ch);
  
    else if (ch == ']'||ch == ')'||ch == '}'){
  
      if(is_empty())
        return 2;
      prev = pop();

      if((ch==']'&&prev!='[')||(ch==')'&&prev!='(')||(ch=='}'&&prev!='{')){
        return 3;
      }
  
    }
  
  }

  if(is_empty()==0){
    return 1;
  }

  return 0;
}

int main() {
  char expr[4][80] = {"{A[(i+1)]=0;}" , "if((i==0)&&(j==0)","A[(i+1])=0;", "A[i]=f)(;"};

  int errorCode, i;

  for(i=0;i<4;i++){
    
    errorCode=check_matching(expr[i]);
    
    if(errorCode==0){
      printf("normal: %s\n",expr[i]);
    } 

    else{
      printf("error: %s (condition %d violated)\n",expr[i],errorCode);
    }
  }

  return 0;
}