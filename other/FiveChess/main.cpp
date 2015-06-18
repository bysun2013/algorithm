#include <iostream>
#include "FiveChess.h"
#include "player.h"

using namespace std;

int main()
{
    fivechess fc;
    player pa("Andy", BLACK, fc);
    player pb("Bing", WHITE, fc);

    int x, y;
    int ret;
    while(1){
        cout << pa << ", Please enter x,y: ";
        cin >> x >> y;
        while((ret = pa.play(x, y)) < 0){
            cout << pa << ", Please enter x,y: ";
            cin >> x >> y;
        }
        if(ret > 0){
            cout << pa << " is winner!" << endl;
            break;
        }

        cout << pb << ", Please enter x,y: ";
        cin >> x >> y;
        while((ret = pb.play(x, y)) < 0){
            cout << pb << ", Please enter x,y: ";
            cin >> x >> y;
        }
        if(ret > 0){
            cout << pb << " is winner! Game Over!!!" << endl;
            break;
        }
    }

    return 0;
}
