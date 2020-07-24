#include "Sniper.hpp"
#include "math.h"

using namespace std;


// attack the strogest soldier (by his health points)
    void Sniper :: attack(vector<vector<Soldier *>> &board, pair<int, int> location){
       int num_player=board[location.first][location.second]->getNum();
        // Soldier *attack= findMax(board, location , num_player);
       
            int max_health=0;
            Soldier *attack = nullptr;
            int z=0;
            int v=0;
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]!=nullptr){
                        if(board[i][j]->getNum()!=num_player){
                            if(board[i][j]->getHealth()>max_health){
                                attack=board[i][j];
                                max_health=board[i][j]->getHealth();
                                z=i;
                                v=j;
                            }
                        }
                    }    
                }
            }
       if ( attack != nullptr){
            int att = board[location.first][location.second]->getDamge();
            int hel = attack->getHealth() - att;
        if(hel <= 0){
            board[z][v]=nullptr;
        }
        else{
            attack->setHealth(hel);
        }
     }
       
    }  
    


