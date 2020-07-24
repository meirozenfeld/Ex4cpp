#include "Board.hpp"
#include <iostream>
#include <limits>
#include <math.h>
using namespace std;

namespace WarGame {


         Soldier*& Board :: operator[](std::pair<int,int> location){
             return board[location.first][location.second];
        }


        Soldier* Board:: operator[](std::pair<int,int> location) const{
            return  board[location.first][location.second];
        }

        void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction) {
            int check =0;
            if ( player_number ==1 ) check =2;
            else check =1;
            //Down
            if (direction == Down){
            if(source.first - 1  < 0) throw ("std::invalid_argument");
             else if (board[source.first-1][source.second] != nullptr) throw ("std::invalid_argument");
                Soldier *s = board[source.first][source.second];
                board[source.first][source.second] = nullptr; // to check
                board[source.first-1][source.second] = s;
                s->attack( board ,{source.first-1,source.second} );
            }
            // UP
            if (direction == Up){
            if(source.first + 1  >= board.size()) throw ("std::invalid_argument");
             else if (board[source.first+1][source.second] != nullptr) throw ("std::invalid_argument");            
                Soldier *s = board[source.first][source.second];
                if(s==nullptr){throw ("std::invalid_argument");
                }
                board[source.first+1][source.second] = s;
               board[source.first][source.second] = nullptr; // to check 
                s->attack( board ,{source.first+1,source.second});
            }
            //Left
            if (direction == Left){
            if(source.second -1 < 0) throw ("std::invalid_argument");
             else if (board[source.first][source.second-1] != nullptr) throw ("std::invalid_argument");
                Soldier *s = board[source.first][source.second];
                board[source.first][source.second] = nullptr; // to check
                board[source.first][source.second-1] = s;
                s->attack( board ,{source.first,source.second-1} );
            }
            //Right
            if (direction == Right){
            if(source.second + 1  >= board[0].size()) throw ("std::invalid_argument");
             else if (board[source.first][source.second+1] != nullptr) throw ("std::invalid_argument");
                Soldier *s = board[source.first][source.second];
                board[source.first][source.second] = nullptr; // to check
                board[source.first][source.second+1] = s;
                s->attack( board ,{source.first,source.second+1} );
            }


        }




         bool Board::has_soldiers(uint player_number) const {
            int count=0;
             for(int i=0; i<board.size();i++){
                 for(int j=0; j<board[i].size();j++){
                     Soldier* s= board[i][j];
                     if (s!=nullptr){
                     if( s->getNum()==player_number){
                        return true;
                     }
                     }
                 }

             }
             return false;
         }
}
