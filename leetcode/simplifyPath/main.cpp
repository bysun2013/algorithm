#include <iostream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int size  = path.size();
        if(size == 0)
            return path;
        int i =0, j=0;
        while(j< size){
            while(j < size && path[j] != '.'){
                if(i != j)
                    path[i] = path[j];
                if(path[j] == '/' ){
                    while(path[j] == '/')
                        j++;
                }else{
                    j++;
                }
                i++;
            }

            if(i > 0){
                if(j+1 < size){
                    if(path[j+1] != '.'){
                        i--;
                        j++;
                    }else{
                        i--;
                        while(i > 0 && path[i-1] != '/')
                            i--;
                        if(i > 0)
                            i--;
                        j+=2;
                    }
                }else{
                    break;
                }
            }else{
                j++;
            }
        }
        if(i > 1 && path[i-1] == '/')
            i--;
        if(i == 0)
            return "/";
        return path.substr(0, i);
    }
};

int main()
{
    Solution s;
    string str1, str2;

    str1 = "/.";
    str2 = "/a/./b/../../c/";

    cout << s.simplifyPath(str1) << endl;
    cout << s.simplifyPath(str2) << endl;

    return 0;
}
