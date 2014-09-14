#include <stdio.h>
#include <stdlib.h>

/**
* ∫∫≈µÀ˛Œ Ã‚
* move size from source to dest, use temp as intermediate
*/

static int count = 0;

int hannoi(char source, char dest, char temp, int size)
{

    if(size == 1){
        count++;
        printf("%d: from %c to %c\n", size, source, dest);
        return 0;
    }

    hannoi(source, temp, dest, size-1);
    count++;
    printf("%d: from %c to %c\n", size, source, dest);
    hannoi(temp, dest, source, size-1);

    return 0;
}

int main()
{
    int size;
    printf("Please enter the size of hannoi: ");
    scanf("%d", &size);

    hannoi('a', 'b', 'c', size);

    printf("\nIt need %d moves at least.\n", count);
    return 0;
}
