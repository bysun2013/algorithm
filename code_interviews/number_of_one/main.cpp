#include <iostream>

using namespace std;

int num_of_one(unsigned int n)
{
    int count = 0;
    cout << "unsigned int " << n << endl;
    while(n){
        if(n & 1)
            count++;
        n >>= 1;
    }

    return count;
}

int num_of_one2(int n)
{
    int count = 0;

    while(n){
        ++count;
        n = n & ( n-1);
    }

    return count;
}

int main()
{
    int x;
    while(cin >> x){
        cout << "The number of 1: " << num_of_one2(x)<< endl;
    }

    return 0;
}
