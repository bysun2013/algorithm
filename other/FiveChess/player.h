#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include "FiveChess.h"

using std::ostream;
using std::string;

class fivechess;
enum colors {WHITE, BLACK};
class player{
private:
    fivechess &fc;
    string name;
    colors use_color;
public:
    colors color() const { return use_color; }
    player(const string &s, colors color, fivechess &f);
    int play(int x, int y);
    friend ostream & operator <<(ostream &os, const player &p);
};

#endif // PLAYER_H_INCLUDED
