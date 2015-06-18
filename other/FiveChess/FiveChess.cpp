#include "FiveChess.h"

using namespace std;

fivechess::fivechess(){
    for(int i = 0; i < LENGTH;i++){
        for(int j = 0; j < LENGTH; j++)
            board[i][j] = '-';
    }
}
void fivechess::show(){
    for(int i = 0; i < LENGTH; i++){
        for(int j = 0; j < LENGTH; j++)
            cout << board[i][j];
        cout << endl;
    }
}

int fivechess::check_valid(int x, int y){
    if(x < 0 || x >= LENGTH || y < 0 || y >= LENGTH){
        cout << "x or y is out of range, please try again!" << endl;
        return -1;
    }

    if(board[x][y] != '-'){
        cout << "This position is set, please try again!" << endl;
        return -1;
    }

    return 0;
}

// 检查水平方向
int fivechess::judge_horizontal_line(const player &p, int x, int y){
    char c = (p.color() == BLACK) ? 'B':'W';
    //该点左右方向上相同的点个数
    int left = 0, right = 0;

    int i = y;
    while(i >= 0 && board[x][i] == c){
        i--;
        left++;
    }
    i = y;
    while(i < LENGTH && board[x][i] == c){
        i++;
        right++;
    }

    if(left + right >= 6)
        return 1;
    else
        return 0;
}

//检查左上到右下方向
int fivechess::judge_right_bottom_line(const player &p, int x, int y){
    char c = p.color() == BLACK ? 'B':'W';
    //该点左右方向上相同的点个数
    int left = 0, right = 0;
    int i = y, j = x;
    while(i >= 0 && j >= 0 && board[j][i] == c){
        i--;
        j--;
        left++;
    }
    i = y;
    j = x;
    while(i < LENGTH && j < LENGTH && board[j][i] == c){
        i++;
        j++;
        right++;
    }

    if(left + right >= 6)
        return 1;
    else
        return 0;
}

//检查右上到左下方向
int fivechess::judge_left_bottom_line(const player &p, int x, int y){
    char c = p.color() == BLACK ? 'B':'W';
    //该点左右方向上相同的点个数
    int left = 0, right = 0;
    int i = y, j = x;
    while(i >= 0 && j < LENGTH && board[j][i] == c){
        i--;
        j++;
        left++;
    }
    i = y;
    j = x;
    while(i < LENGTH && j >= 0 && board[j][i] == c){
        i++;
        j--;
        right++;
    }

    if(left + right >= 6)
        return 1;
    else
        return 0;
}

int fivechess::judge(const player &p, int x, int y){
    if(judge_horizontal_line(p, x, y) > 0)
        return 1;

     if(judge_left_bottom_line(p, x, y) > 0)
        return 1;

    if(judge_right_bottom_line(p, x, y) > 0)
        return 1;

    return 0;
}

