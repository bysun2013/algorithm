#include <stdio.h>
#include <stdlib.h>

#include "HString.h"

int main()
{
    HString hs,ht,cncat;
    char *ch1="ABCDEFGHIJ12345";
    char *ch2="ABCDEFFGH";
    HStrAssign(&hs,ch1);
    HStrAssign(&ht,ch2);
    printHStr(&hs);
    printf("The length of string is %d, is the string empty:%d\n",GetLength(&hs),EmptyHStr(&hs));

    printf("The string %s and %s ,The result compared is %d .",ch1,ch2,CmpHStr(&hs,&ht));

    ConcatHStr(&cncat,&hs,&ht);
    printHStr(&cncat);

    ClearHStr(&ht);
    printHStr(&ht);

    SubHStr(&ht,&cncat,hs.len-1,6);
    printHStr(&ht);

    printf("\nThe string %s in %s is %d.\n",ht.ch,cncat.ch,IndexHStr(&cncat,&ht,0));

    printf("\nThe string %s in %s with KMP is %d.\n",ht.ch,cncat.ch,KMPIndexHStr(&cncat,&ht,0));
    return 0;
}
