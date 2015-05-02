#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> record;
        char c;
        unsigned int i;
        for(i=0;i<s.size();i++){
           // cout << "This is " << i << " time" <<endl;
            switch(s[i]){
            case '[':
            case '{':
            case '(':
                record.push(s[i]);
                break;
            case ']':
                if(record.empty())
                    return false;
                c = record.top();
                if(c != '[')
                    return false;
                record.pop();
                break;
            case '}':
                if(record.empty())
                    return false;
                c = record.top();
                if(c != '{')
                    return false;
                record.pop();
                break;
            case ')':
                if(record.empty())
                    return false;
                c = record.top();
                if(c != '(')
                    return false;
                record.pop();
                break;
            default:
                cout << "wrong char" << endl;
                break;
            }
        }
        if(record.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    Solution s;
    string str1("(){}{}[]");
    string str2("(){{}}[]");
    string str3("]");
    cout << str1 << boolalpha << s.isValid(str1) << endl;
    cout << str2 << boolalpha << s.isValid(str2) << endl;
    cout << str3 << boolalpha << s.isValid(str3) << endl;

    return 0;
}

