#ifndef FIVECHESS_H_INCLUDED
#define FIVECHESS_H_INCLUDED

#include "player.h"


class player;
class fivechess{
public:
    fivechess();
    void show();
    int check_valid(int x, int y);
    int judge(const player &p, int x, int y);
    char color(int x, int y) const { return board[x][y]; }
    char& color(int x, int y) { return board[x][y]; }
private:
    enum{LENGTH = 11};
    char board[LENGTH][LENGTH];
    int judge_horizontal_line(const player &p, int x, int y);
    int judge_left_bottom_line(const player &p, int x, int y);
    int judge_right_bottom_line(const player &p, int x, int y);
};

#endif // FIVECHESS_H_INCLUDED
