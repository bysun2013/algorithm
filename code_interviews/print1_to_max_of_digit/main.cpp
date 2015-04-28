#include <iostream>

using namespace std;

void print_string(string &s)
{
    int len = s.size();
    int i = 0;

    while(s[i] == '0' && i < len)
        i++;
    if(i >= len)
        return;
    while(i < len){
        cout << s[i];
        i++;
    }
    cout << endl;
}

int print_num1(int n)
{
    if(n <= 0)
        return 0;
    string s(n, '0');

    while(1){
        int i = n-1;
        while(s[i] == '9'){
            s[i] = '0';
            i--;
        }
        if(i < 0)
            break;
        s[i]++;
        print_string(s);
    }
    return 0;
}

static void print1tomaxddight_recursively(string &s, int n, int index)
{
    if(index >= n){
        print_string(s);
        return;
    }

    for(int i = 0; i< 10; i++){
        s[index] = '0' + i;
        print1tomaxddight_recursively(s, n, index + 1);
    }
}

void print_num2(int n){
    if(n <= 0)
        return;
    string s(n, '0');
    print1tomaxddight_recursively(s, n, 0);
}

int main()
{
    int n;

    while(cin >> n)
        print_num2(n);

    return 0;
}
