#include <iostream>
#include <stack>

using namespace std;

class stack_min{
public:
    void push(int value){
        s.push(value);
        if(s_min.empty()){
            s_min.push(value);
            return;
        }
        int min_value = s_min.top();
        if(min_value > value)
            min_value = value;
        s_min.push(min_value);
    }
    int pop(){
        if(s.empty())
            return -1;
        int value = s.top();
        s.pop();
        s_min.pop();

        return value;
    }
    int min(){
        if(s_min.empty())
            return -1;
        return s_min.top();
    }
private:
    stack<int> s;
    stack<int> s_min;
};

int main()
{
    stack_min s;
    s.push(3);
    cout << s.min() <<endl;
    s.push(4);
    cout << s.min() <<endl;
    s.push(2);
    cout << s.min() <<endl;
     s.push(1);
    cout << s.min() <<endl;
    s.pop();
    cout << s.min() <<endl;
     s.pop();
    cout << s.min() <<endl;

     s.push(0);
    cout << s.min() <<endl;
    return 0;
}
