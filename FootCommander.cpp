#include "FootCommander.hpp"

using namespace std;


   //cure all te soldier that are 1 step close to him of the same player
    void FootCommander :: attack(vector<vector<Soldier *>> &board, pair<int, int> location){
       Soldier *s = board[location.first][location.second];
       int i=location.first;
       int j=location.second;
      for (int i = 0; i < board.size(); i++)
      {
          for (int j = 0; j < board[0].size(); j++)
          {
                 Soldier *a=board[i][j];
                 if( a != nullptr){
                    FootSoldier *fs = dynamic_cast<FootSoldier*> (a);
                 if( fs!=nullptr){
                     FootCommander *footcom = dynamic_cast<FootCommander*> (a);
                     if ( footcom == nullptr || ( i == location.first && j == location.second)) {                     
                     if ( fs->getNum() == s->getNum()){
                         fs->FootSoldier::attack(board , {i,j});
                     }
                    }
                 }
                
             }



          }
          
      }
      


    }


