/**
    题目：用两个栈实现队列

    某队列的声明如下：
        template<typename T> class CQueue {
        public:
            CQueue() {}
            ~CQueue() {}
            void appendTail(const T& node); // append a element to tail
            void deleteHead(); // remove a element from head
        private:
            T m_stack1;
            T m_stack2;
        };

    DONE in 2014.4.12 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack s1,s2;

void init_queue(){
    initStack(&s1);
    initStack(&s2);
}

void destroy_queue(){
    destroyStack(&s1);
    destroyStack(&s2);
}

void append_tail(SElemType e){
    push(&s1, e);
}

void delete_head(){
    SElemType e;
    if(!isEmpty_S(s2)){
        pop(&s2, &e);
        return;
    }

    while(!isEmpty_S(s1)){
        pop(&s1, &e);
        push(&s2, e);
    }

    if(isEmpty_S(s2)){
        printf("The queue is empty!\n");
        return;
    }
    pop(&s2, &e);
}

void print_queue(){
    SElemType *ep;

    printf("\nThe queue is:\n");

    if(!isEmpty_S(s2)){
        ep=s2.top-1;
        while(ep>=s2.base){
            printf("%d ", *ep);
            ep--;
        }
    }

    if(!isEmpty_S(s1)){
        ep=s1.base;
        while(ep!=s1.top){
            printf("%d ", *ep);
            ep++;
        }
    }
}

int main()
{
    int i;
    init_queue();
    for(i=1;i<10;i++){
        append_tail(2*i);
    }
    print_queue();

    for(i=1;i<6;i++){
        delete_head();
    }
    print_queue();

    for(i=15;i<30;i++){
        append_tail(2*i);
    }
    print_queue();

    return 0;
}
