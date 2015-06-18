#include "player.h"

using namespace std;

player::player(const string &s, colors color, fivechess &f)
    :fc(f), name(s), use_color(color)
{
    cout << "Create Player " << name << endl;
}

int player::play(int x, int y){

    if(fc.check_valid(x, y) < 0 )
        return -1;
    fc.show();
    int result = fc.judge(*this, x, y);
    if(result == 1){
        cout << *this << " win!" << endl;
        return 1;
    }
    return 0;
}

ostream & operator <<(ostream &os, const player &p){
    os << "Player " << p.name << (p.use_color == WHITE ? "(W) ": "(B) ");
    return os;
}
