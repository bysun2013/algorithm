/*
    https://leetcode.com/problems/gas-station/
    Accepted
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

struct left_gas
{
    int operator()(int gas, int cost)
    {
        return (gas - cost);
    }
};

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        if(gas.size() != cost.size())
            throw logic_error("different size");
        vector<int> left;

        transform(gas.begin(), gas.end(), cost.begin(), back_inserter(left), left_gas());

        int length = left.size();
        if(length == 0)
            return 0;
        int i = 0, start = 0, sum = 0;
        sum += left[i];
        i = (i+1)%length;
        while(i != start)
        {
            if(sum < 0)
            {
                sum = 0;
                start = i;
                if(start == 0)
                    return -1;
            }
            sum += left[i];
            i = (i+1)%length;
        }

        if(sum < 0)
            return -1;
        return start;
    }
};

int main()
{
    int gas_array[] = {4};
    int cost_array[] = {5};
    vector<int> gas(gas_array, gas_array + 1);
    vector<int> cost(cost_array, cost_array + 1);

    Solution s;
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
