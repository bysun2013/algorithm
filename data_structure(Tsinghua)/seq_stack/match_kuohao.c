#include "stack.h"

#define MAX_CHAR   50


int match(){
    char input[MAX_CHAR];
    stack ch,brackets;
    char c,*cursor=input;

    initStack(&ch);
    initStack(&brackets);
    printf("Please input a string including brackets:\n");
    scanf("%s",input);

    while(*cursor){
        switch(*cursor){
        case '[':
        case '(':
            push(&brackets,*cursor);
            break;
        case ']':
            pop(&brackets,&c);
            if(c!='[')
                goto error;
            break;
        case ')':
            pop(&brackets,&c);
            if(c!='(')
                goto error;
            break;
        default:
            push(&ch,*cursor);
            break;
        }
        cursor++;
    }

error:
//printf("The stack is %d£¬length is %d\n",isEmpty(brackets),getLen(brackets));

    if(!isEmpty(brackets))
        printf("The brackets is NOT matched !");
    else
        printf("The brackets is matched !");

    destroyStack(&brackets);
    destroyStack(&ch);
    return 0;
}
