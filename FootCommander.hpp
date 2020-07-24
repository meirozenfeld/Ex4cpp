#pragma once
#include "FootSoldier.hpp"

using namespace std;

const int max_health_point_footcom = 150;
const int Damage_footcom = 20;

class FootCommander : public  FootSoldier {



public:

FootCommander(int num_p) : FootSoldier(max_health_point_footcom , Damage_footcom , num_p){}
FootCommander(int max_health_point , int damage , int num_p) : FootSoldier(max_health_point , damage , num_p){}
void attack(vector<vector<Soldier *>> &board, pair<int, int> location);

};
