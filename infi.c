#include <stdio.h>
#include <ctype.h>
#define size 20
char postfix[size],stack[size];
int k=-1;
int isoperator(char t){
    if( t=='^' || t=='/' ||  t=='*' || t=='+' || t=='-'){
        return 1;
    }
    else{
        return 0;
    }
}
void push(char elem){
    stack[++k]=elem;
}
char pop(){
    if(k==-1){
        return EOF;
    }
    else{
        return stack[k--];
    }
}
int precedence(char t){
    char st=pop();
    push(st);
    if(st==t){
        return 0;
    }
    else if(t=='^'){
        return 0;
    }
    else if(t=='/' || t=='*'){
        if(st=='+' || st=='-'){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if(t=='+' || t=='-'){
        return 1;
    }
    else{
        return 0;
    }
}
void infix_to_postfix(char infix[]){
    int i=0,j=0;
    char x;
    push('(');
    while((infix[i])!='\0'){
        char term=infix[i];
        if(isoperator(term)==1){
            if(precedence(term)==1){
                while((x=pop())!='('){
                    postfix[j++]=x;
                }
                push(x);
                push(term);
            }
            else{
                push(term);
            }
        }
        else if( term=='('){
            push(term);
        }
        else if(term==')'){
            while((x=pop())!='('){
                postfix[j++]=x;
            }
        }
        else{
            postfix[j++]=term;
        }
        i++;
    }
    while((x=pop())!='('){
        postfix[j++]=x;
    }
    postfix[j]='\0';
    printf("The Postfix expression: \n");
    int p=0;
    while(postfix[p]!='\0'){
        printf("%c",postfix[p++]);
    }
}
/*void eval(char postfix[]){
    int i=0;
    int val;
    int a,b;
    while(postfix[i]!='\0'){
        char term=postfix[i];
        if(isdigit(term)){
            push(term-'0');
        }
        if(isoperator(term)){
            a=pop();
            b=pop();
	    printf("a:%d b:%d",a,b);
            switch(term){
            	case '*':
                	val=b*a;
                	break;
            	case '/':
                	val=b/a;
                	break;
            	case '+':
                	val=b+a;
            	   	 break;
           	case '-':
               		 val=b-a;
               		 break;
            }
            push(val);
        }
	i++;
    }
    printf("Result:%d",pop());
}*/
void eval(char postfix[])
 {

	int i ;
	char ch;
	int val;
	int A, B ;

	for (i = 0 ; postfix[i] != '\0'; i++)
	{
		ch = postfix[i];
		if (isdigit(ch))
		{
			push(ch - '0');
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			A = pop();
			B = pop();

			switch (ch) 
			{
				case '*':
				val = B * A;
				break;

				case '/':
				val = B / A;
				break;

				case '+':
				val = B + A;
				break;

				case '-':
				val = B - A;
				break;
			}
			push(val);
		}
	}
	printf( " \n Result of expression evaluation : %d \n", pop()) ;
}

int main(){
    int ch;
    while(1){
        printf("\nEnter your choice:\n1.Infix to Postfix conversion 2.Evaluation of expression 3.Exit\n");
        scanf("%d",&ch);
        if(ch==1){
            char infix[size];
            printf("Enter the infix expression:\n");
            scanf("%s",infix);
            infix_to_postfix(infix);
        }
        else if(ch==2){
            char post[size];
            printf("Enter the postfix expression:\n");
            scanf("%s",post);
            eval(post);
        }
        else{
            return 0;
 	}
    }
}
