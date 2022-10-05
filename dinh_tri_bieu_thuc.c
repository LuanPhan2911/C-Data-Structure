#include<stdio.h>
#include<string.h>
#include "arrStack.c"
int isOperand(char ch){
	if(ch>=48 && ch <= 57){
		return 1;
	}
	return 0;
}
void ignore(char * str){
	if(str[strlen(str)-1]=='\n'){
		str[strlen(str)-1]='\0';
	}
}
int priority(char ch){
	if(ch=='+' || ch=='-'){
		return 1;
	}
	if(ch=='*' || ch=='/'|| ch=='%'){
		return 2;
	}
	return 0;
}

void strAdd (char * str, char ch){
	int len = strlen(str);
	str[len]= ch;
	str[len+1]=' ';
	str[len+2]='\0';
}
void infixToPosfix(char *infix, char * posfix){
	
	Stack s;
	makenullStack(&s);
	int len = strlen(infix), i;
	for(i=0; i<len; i++){
		char token = infix[i];
		if(token!=' '){
			if(isOperand(token)){
				strAdd(posfix, token);
			}
			else if(token=='('){
				push(token, &s);
			}else if(token==')'){
				while(top(s)!='('){
					strAdd(posfix,top(s));
					pop(&s);
				}
				pop(&s);
			}
			else {
				while(!emptyStack(s)&& priority(top(s))>=priority(token)){
					strAdd(posfix,top(s));
					pop(&s);
				}
				push(token, &s);
			}
		}
	}
	while(!emptyStack(s)){
		strAdd(posfix, top(s));
		pop(&s);
	}
}
int calculate(int a, int b, char ch){
	switch(ch){
		case '+':
			return a+b;
			break;
		case '-':
			return a-b;
			break;
		case '*':
			return a*b;
			break;
		case '/':
			return a/b;
			break;
		default:
			break;
	}
}
int posfixToResult(char *posfix){
	Stack s;
	makenullStack(&s);
	int len= strlen(posfix), i;
	char token;
	int val1, val2, value;
	for(i=0; i<len; i++){
		token = posfix[i];
		if(token!=' '){
			if(isOperand(token)){
				push(token-48, &s);
			}else {
				val1= top(s);
				pop(&s);
				val2=top(s);
				pop(&s);
				value=calculate(val2, val1,token);
				push(value, &s);
			}
		}
	
	}
	return top(s);
	
}
int main(){
	char infix[50], posfix[50];
	fgets(infix, 50, stdin);
	ignore(infix);
	infixToPosfix(infix, posfix);
	printf("%s\n", posfix);
	int result =posfixToResult(posfix);
	printf("%d ", result);
return 0;
}

