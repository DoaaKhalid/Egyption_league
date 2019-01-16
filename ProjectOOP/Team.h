#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Player.h"
#include "Match.h"
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
class Team 
{
private:
	string Name,Captain;
	int ID_Team , OwnGoals , Goals , Points;
	map<int,Player> Team_Members;
	map<int ,Team> Teams;
	vector<string> Team_Matches;
public:
	Team();
	void Add_Team();
	void Display_team_player();
	void Display_Team_Info();
	void Search_for_team();
	void Update_team_information();
	void Load_Teams();
	void Display_team_detailed_scores();
	void Display_team_Order(string);
	void Update_Total_Score(string s, int x);
	void Update_GoalKeepar_Score(string s, int x);
	void Put_Data_in_file();
	void Display_Matches();
	void DisPlay_Team_Match_With_Date();
	void Update_Points(string s, int x, int x1);
	friend void Load();
	friend void Display_teams_ordered_by_the_average_ages_of_its_players();
	friend void Display_3_Frist_Teams_By_Points();
	friend void Display_3_First_Teams_By_Total_Score();
	friend void Display_3_First_GoalKeepers();
	friend bool sortbyPoints(const pair<int, Team> &a, const pair<int, Team> &b);
	friend bool sortbyOwnGoals(const pair<int, Team> &a, const pair<int, Team> &b);
	friend bool sortGoalkeepers(const pair<int, Team> &a, const pair<int, Team> &b);
	friend bool sortbyavg(const pair<string, double> &a, pair<string, double> &b);
	friend Match;
	
	~Team();
};
