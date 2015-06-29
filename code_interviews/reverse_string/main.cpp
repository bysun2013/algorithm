#include <iostream>

using namespace std;

void my_reverse(char *pbegin, char *pend){
    if(pbegin == NULL || pend == NULL)
        return;

    while(pbegin < pend){
        char c = *pbegin;
        *pbegin = *pend;
        *pend = c;
        pbegin++, pend--;
    }
}

char* reverse_string(char *s){
    if(!s)
        return NULL;
    char *pbegin, *pend;
    pbegin = pend = s;
    while(*pend != '\0')
        ++pend;

    my_reverse(pbegin, --pend);
    pbegin = pend = s;
    while(*pbegin){
        if(*pbegin == ' '){
            pbegin++, pend++;
        }else if(*pend == '\0' || *pend == ' '){
            my_reverse(pbegin, --pend);
            pbegin = ++pend;
        }else{
            pend++;
        }
    }

    return s;
}


char *left_rotate(char *s, int n){
    if(s == NULL || n <= 0)
        return s;

    char *pbegin, *pend;
    pbegin = pend = s;
    while(*pend != '\0')
        ++pend;
    my_reverse(pbegin, --pend);

    my_reverse(pbegin, pend - n);
    my_reverse(pend - n +1, pend);

    return s;
}

int main()
{
    char s[100];
    int n;
    cin.getline(s, 100);
    cout << reverse_string(s) << endl;

    cin >> n;
    cout << left_rotate(s, n) << endl;
    return 0;
}
