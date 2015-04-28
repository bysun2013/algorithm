#include <iostream>
#include <stack>

using namespace std;

bool is_pop_order(const int *ppush, const int *ppop, int len)
{
    if(!ppush && !ppop)
        return true;
    else if(!ppush)
        return false;
    else if(!ppop)
        return false;
    if(len <= 0)
        return false;

    stack<int> s;
    int cur = 0, cur_pop = 0;
    while(cur_pop < len){
        int value = ppop[cur_pop];
        if(s.empty() || s.top() != value){
            while(cur < len && ppush[cur] != value){
                s.push(ppush[cur]);
                cur++;
            }
            if(cur >= len)
                return false;
            cur++, cur_pop++;
        }else if(!s.empty() && s.top() == value){
//            cout << s.top() << " ";
            s.pop();
            cur_pop++;
        }
    }
    return true;
}

int main()
{
    int ppush[] = {1,2,3,4,5};
    int ppop1 [] = {4,5,3,2,1};
    int ppop2[] = {4,3,5,1,2};

    cout << boolalpha << is_pop_order(ppush, ppop1, 5) <<endl;
    cout << boolalpha << is_pop_order(ppush, ppop2, 5) <<endl;

    int ppush_1[] = {1};
    int ppop1_1 [] = {4};
    cout << boolalpha << is_pop_order(ppush_1, ppop1_1, 1) <<endl;
    cout << boolalpha << is_pop_order(NULL, NULL, 0) <<endl;
    return 0;
}
