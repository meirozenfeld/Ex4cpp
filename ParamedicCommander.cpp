#include "ParamedicCommander.hpp"

using namespace std;


//pass through the board and call every paramedic in the board that in the same player
    void ParamedicCommander :: attack(vector<vector<Soldier *>> &board, pair<int, int> location){
       Soldier *s = board[location.first][location.second];
       int i=location.first;
       int j=location.second;
      for (int i = 0; i < board.size(); i++)
      {
          for (int j = 0; j < board[0].size(); j++)
          {
                 Soldier *a=board[i][j];
                 if( a != nullptr){
                 if(  Paramedic *fs = dynamic_cast<Paramedic*> (a)){
                     ParamedicCommander *footcom = dynamic_cast<ParamedicCommander*> (a);
                     if ( footcom == nullptr || ( i == location.first && j == location.second)) {                     
                     if ( fs->getNum() == s->getNum()){
                            if ( fs != nullptr){

                         fs->Paramedic::attack(board , {i,j});
                            }
                     }
                    }
                 }     
             }
          }
      }
      


    }


