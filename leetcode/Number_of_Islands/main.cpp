/*
https://leetcode.com/problems/number-of-islands/

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:
11110
11010
11000
00000
Answer: 1

Example 2:
11000
11000
00100
00011
Answer: 3
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

using namespace std;


/*
深度遍历， 26ms
*/
class Solution_dfs
{
public:
    int numIslands(vector<vector<char> > &grid)
    {
        int row = grid.size();
        if(row <= 0)
            return 0;
        int column = grid[0].size();
        if(column <= 0)
            return 0;
        vector<vector<bool> > flag(row);
        for(int i = 0; i< row; i++)
            for(int j = 0; j< column; j++){
                bool b = true;
                if(grid[i][j] == '1')
                    b = false;
                flag[i].push_back(b);
            }

        int islands = dfs(flag, row, column);
        return islands;
    }

private:
    int dfs(vector<vector<bool> > &flag, int row, int column)
    {
        int sum = 0;
        for(int i = 0; i< row; i++)
            for(int j = 0; j< column; j++)
            {
                if(flag[i][j] == false){
                    dfs_visit(flag, i, j, row, column);
                    sum++;
                }
            }
        return sum;
    }
    void dfs_visit(vector<vector<bool> > &flag, int i, int j, int row, int column)
    {
/*
        if(i < 0 || i >=row || j < 0 || j >= column){
            cout << "invalid argument" << endl;
            return;
        }
*/
        if(flag[i][j] == false)
            flag[i][j] = true;
        else{
            cout << "it's bad!!!" << endl;
            return;
        }

        if(j-1 >= 0 && flag[i][j-1] == false)
            dfs_visit(flag, i, j-1, row, column);
        if(j+1 < column && flag[i][j+1] == false)
            dfs_visit(flag, i, j+1, row, column);
        if(i-1 >= 0 && flag[i-1][j] == false)
            dfs_visit(flag, i-1, j, row, column);
        if(i+1 < row && flag[i+1][j] == false)
            dfs_visit(flag, i+1, j, row, column);
    }
};

/*
广度遍历， 23ms
*/
class Solution_bfs {
public:
    int numIslands(vector<vector<char> > &grid) {
         int row = grid.size();
        if(row <= 0)
            return 0;
        int column = grid[0].size();
        if(column <= 0)
            return 0;

        vector<vector<bool> > flag(row);
        for(int i = 0; i< row; i++)
            for(int j = 0; j< column; j++){
                bool b = true;
                if(grid[i][j] == '1')
                    b = false;
                flag[i].push_back(b);
            }

        int islands = 0;
        for(int i = 0; i < row; i++)
            for(int j = 0; j< column; j++){
                    if(flag[i][j] == false){
                        bfs(flag, row, column, i, j);
                        islands++;
                    }
            }

        return islands;
    }
private:
    struct position{
        int row;
        int column;
        position(int x, int y):row(x),column(y){}
    };
    void bfs(vector<vector<bool> > &flag, int row, int column, int x, int y)
    {
        queue<position> q;
        int i, j;

        if(flag[x][y] == true)
            throw runtime_error("serious problem");
        flag[x][y] = true;
        q.push(position(x,y));

        while(!q.empty()){
            position &cur = q.front();
            i = cur.row;
            j = cur.column;
            q.pop();

            if(i-1>= 0 && flag[i-1][j] == false){
                flag[i-1][j] = true;
                q.push(position(i-1, j));
            }

            if(i+1 <row && flag[i+1][j] == false){
                flag[i+1][j] = true;
                q.push(position(i+1, j));
            }

            if(j-1>= 0 && flag[i][j-1] == false){
                flag[i][j-1] = true;
                q.push(position(i, j-1));
            }

            if(j+1 < column && flag[i][j+1] == false){
                flag[i][j+1] = true;
                q.push(position(i, j+1));
            }

        }
    }
};

/*
改动grid二维数组，10ms
*/
class Solution {
public:
    int numIslands(vector<vector<char> > &grid) {
         int row = grid.size();
        if(row <= 0)
            return 0;
        int column = grid[0].size();
        if(column <= 0)
            return 0;

        int islands = 0;
        for(int i = 0; i < row; i++)
            for(int j = 0; j< column; j++){
                    if(grid[i][j] == '1'){
                        bfs(grid, row, column, i, j);
                        islands++;
                    }
            }

        return islands;
    }
private:
    struct position{
        int row;
        int column;
        position(int x, int y):row(x),column(y){}
    };
    void bfs(vector<vector<char> > &flag, int row, int column, int x, int y)
    {
        queue<position> q;
        int i, j;

        if(flag[x][y] == '0')
            throw runtime_error("serious problem");
        flag[x][y] = '0';
        q.push(position(x,y));

        while(!q.empty()){
            position &cur = q.front();
            i = cur.row;
            j = cur.column;
            q.pop();

            if(i-1>= 0 && flag[i-1][j] == '1'){
                flag[i-1][j] = '0';
                q.push(position(i-1, j));
            }

            if(i+1 <row && flag[i+1][j] ==  '1'){
                flag[i+1][j] = '0';
                q.push(position(i+1, j));
            }

            if(j-1>= 0 && flag[i][j-1] ==  '1'){
                flag[i][j-1] = '0';
                q.push(position(i, j-1));
            }

            if(j+1 < column && flag[i][j+1] == '1'){
                flag[i][j+1] = '0';
                q.push(position(i, j+1));
            }

        }
    }
};

const int ROWS = 1;
const int COLUMN = 1;
int main()
{
    Solution s;
    char a[ROWS][COLUMN] = {
        {'1'},
    };
    vector<vector<char> > grid;

    for(int i = 0; i < ROWS;i++)
        grid.push_back(vector<char>(a[i], a[i]+COLUMN));

    cout << s.numIslands(grid) << endl;
    return 0;
}
