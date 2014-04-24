#include "HString.h"

int HStrAssign(HString *s,char *c){
    int len,i;
    char *cur;
    cur=c;
    len=0;
 //   if(s->ch) free(s->ch);
    while(*cur){
        len++; cur++;
   }
    if(len==0)
        s->ch=NULL;
    else{
        s->ch=(char*)malloc(sizeof(char)*(len+1));
        if(!s->ch)
           return 1;
        for(i=0,cur=c;*cur;i++,cur++)
            s->ch[i]=*cur;
        s->ch[len]='\0';
    }
    s->len=len;
    return 0;
}
int GetLength(HString *s){
    return s->len;
}
int EmptyHStr(HString *s){
    return s->len==0;
}
int CmpHStr(HString *s,HString *t){
   int i;
    for(i=0;i<s->len&&i<t->len;i++)
        if(s->ch[i]!=t->ch[i])
            return s->ch[i]-t->ch[i];

    return s->len-t->len;
}
int ClearHStr(HString* s){
    s->len=0;
    if(s->ch){
        free(s->ch);
        s->ch=NULL;
    }

    return 0;
}
int ConcatHStr(HString *s,HString *t1,HString *t2){
    int i;
    if(s->ch)
        free(s->ch);
    s->len=t1->len+t2->len;
    s->ch=(char*)malloc((s->len+1)*sizeof(char));
    if(!s->ch)
        return 1;
    for(i=0;i<t1->len;i++)
        s->ch[i]=t1->ch[i];
    for(i=0;i<t2->len;i++)
        s->ch[t1->len+i]=t2->ch[i];
    s->ch[s->len]='\0';
    return 0;
}
int SubHStr(HString *sub,HString *s,int pos,int len){
    int i;
    if(!s->ch||pos>=s->len||len>s->len)
        return 1;
    if(sub->ch)
        free(sub->ch);
    sub->ch=(char*)malloc((len+1)*sizeof(char));

    for(i=0;i<len;i++)
        sub->ch[i]=s->ch[pos+i];
    sub->ch[len]='\0';
    sub->len=len;
    return 0;
}

int printHStr(HString *s){
    if(!s->ch)
        return 1;
    printf("\nThe string is:");
    printf("\n%s\n",s->ch);
    return 0;
}

int IndexHStr(HString *s,HString *sub,int pos){
    int i=pos,j=0;

    while(i<=s->len-sub->len){
        if(s->ch[i]==sub->ch[j]){
          i++;j++;
        }
        else{
            i=i-j+1;j=0;
        }
        if(j>=sub->len)
            break;
    }
    if(i>s->len-sub->len+1)
        return -1;
    return i-j;
}

//This function need take some time to understand it
static void get_next(HString *s,int next[]){
    int i=0; next[0]=-1; int j=-1;
    while(i<s->len){
        if(j==-1||s->ch[i]==s->ch[j]){
            j++;i++;next[i]=j;
        }else
            j=next[j];
    }
}

/*This function using KMP is difficult to make it right,
**  just for fun!
** For NOW ,it's NOT OK!
*/
int KMPIndexHStr(HString *s,HString *sub,int pos){
    int i; int j=0;
    int next[sub->len];
    get_next(sub,next);
    for(i=0;i<sub->len;i++)
        printf("%d\t",next[i]);
    i=pos;
    while(i<s->len&&j<sub->len){
        if(j==-1||s->ch[i]==sub->ch[j]){
            j++;i++;
        }else
            j=next[j];
    }
    if(j>=sub->len)
        return i-j;
    else
        return -1;
}
