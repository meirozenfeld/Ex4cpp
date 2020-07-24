#include "FootSoldier.hpp"
#include "math.h"

using namespace std;


void FootSoldier::attack(vector<vector<Soldier *>> &board, pair<int, int> dest)
{

    double closest=board.size()*board.size();
    int ci,cj;
    int found =0;
    
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board.size();j++)
        {
            Soldier *s;
            s= board[i][j];
            if(s!=nullptr && (s->getNum() != board[dest.first][dest.second]->getNum()))
            {
                double dist = sqrt((i-dest.first)*(i-dest.first) + (j-dest.second)*(j-dest.second));
                if(dist<closest)
                {
                    closest =dist;
                    ci = i;
                    cj = j;
                    found = 1;
                }
            }
        }
    }
    if(found){
        Soldier *s = board[ci][cj];
        int hp = s->getHealth() - board[dest.first][dest.second]->getDamge();
        if(hp <= 0)
        {
            board[ci][cj] = nullptr;
        }
        else
        {
            s->setHealth(hp);
        }
    }
}
