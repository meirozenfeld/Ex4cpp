#pragma once
#include "Paramedic.hpp"

using namespace std;


const int max_health_point_paracom = 100;
const int Damage_paracom = 200;

class ParamedicCommander : public  Paramedic {

public:

ParamedicCommander(int num_p) : Paramedic(max_health_point_paracom , Damage_paracom , num_p){}
ParamedicCommander(int max_health_point , int damage , int num_p) : Paramedic(max_health_point , damage , num_p){}
void attack(vector<vector<Soldier *>> &board, pair<int, int> location);

};
