#pragma once
#include "Soldier.hpp"

using namespace std;


const int max_health_point_snipe = 100;
const int Damage_snipe = 50;

class Sniper : public  Soldier {


public:

Sniper(int num_p) : Soldier(max_health_point_snipe , Damage_snipe , num_p){}
Sniper(int max_health_point , int damage , int num_p) : Soldier(max_health_point , damage , num_p){}
void attack(vector<vector<Soldier *>> &board, pair<int, int> location);
//Soldier* findMax(vector<vector<Soldier *>> &board,std::pair<int,int> location , uint player_number);

};

