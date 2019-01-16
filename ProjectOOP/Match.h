#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Player.h"
#include "Match.h"
#include <map>
#include "Team.h"
using namespace std;
class Match
{
private:
	int ID_Match, Score_Team_One, Score_Team_two;
	string Date, Footbool_referee, Stadium_Name, team1, team2;
public:


	Match();
	map<pair<string, string>, pair<int, int>> lega;
	map<int, Match> matches;
	void Enter_match_Data();
	void display_all_matches();
	void Put_Data_in_Match();
	void Update_Match();
	void Load_Matches();
	void Display_held_matches_and_to_be_held_matches();
	friend void Display_Match_Certain_date();
	friend bool validDate(string &date);
	friend class Team;
	~Match();
};
