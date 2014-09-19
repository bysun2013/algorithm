/*
* 给定一个字符串，要求把字符串前面的若干个字符移动到字符串的尾部，
* 如把字符串“abcdef”前面的2个字符'a'和'b'移动到字符串的尾部，
* 使得原字符串变成字符串“cdefab”。
*
* 请写一个函数完成此功能，要求对长度为n的字符串
* 操作的时间复杂度为 O(n)，空间复杂度为 O(1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rotate_string(char *s, int start, int end)
{
    int length;
    int i = start, j = end;
    if(!s)
        return 0;

    length = strlen(s);
    if(start < 0 || end > length - 1)
        return -1;

    while(i<j){
        char c;
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++, j--;
    }

    return 0;
}

/*
* 首先旋转整个字符串，然后分别旋转最后rotate_num个字符和前面的字符
*/
int rotate_left(char *s, int rotate_num)
{
    int length;
    int err = 0;

    if(!s)
        return 0;
    if(rotate_num == 0)
        return 0;

    length = strlen(s);
    /* if rotate_num is bigger than length, modulo */
    rotate_num = rotate_num % length;

    err = rotate_string(s, 0, length - 1);
    if(err)
        return err;
    err = rotate_string(s, 0, length - rotate_num - 1);
    if(err)
        return err;
    err = rotate_string(s, length - rotate_num, length -1);
    if(err)
        return err;

    return err;
}

#define MAX_LENGH 100
int main()
{
    char s[MAX_LENGH];
    int rotate_num;
    printf("Please enter one string:\n");
    scanf("%s", s);
    printf("Please enter the number to rotate: ");
    scanf("%d", &rotate_num);

    rotate_left(s, rotate_num);
    printf("The rotated string is %s\n", s);

    return 0;
}
