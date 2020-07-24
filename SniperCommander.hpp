#pragma once
#include "Sniper.hpp"

using namespace std;


const int max_health_point_snipecom = 120;
const int Damage_snipecom = 100;


class SniperCommander : public  Sniper {

public:
SniperCommander(int num_p) : Sniper(max_health_point_snipecom , Damage_snipecom , num_p){}
SniperCommander(int max_health_point , int damage , int num_p) : Sniper(max_health_point , damage , num_p){}
void attack(vector<vector<Soldier *>> &board, pair<int, int> location);

};
