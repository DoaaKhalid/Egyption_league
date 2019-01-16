#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map> 
#include <set>
using namespace std;
class Player
{
private:
	string Name , TeamName;
	int Player_Number;
	vector <Player> Players;
	const string PlayerType[4] = { "Forward" , "midfielder" , "Defender" ,"Goalkeeper" };
	int Rank, Score, Age;
	string Type;
public:
	Player();
	void Enter_data();
	void Load_Players();//Get Data Of All Players From File
	void Display_Data();//Shiw All Player Information On Consol
	void Display_Role();//Display Player Role 
	void Display_Team_member(string n , int);//
	void Update_Player();//Load Player In Vector & Update Player
	void Display_Spacific_Player_info();//Search For Player 
	void put_data();//Put Data IN File
	void Update_Player_Score(string, string);
	friend void Display_3_Frist_Players_By_Rank();
	friend void Display_3_Frist_Players_By_Goals();
	friend void Display_teams_ordered_by_the_average_ages_of_its_players();
	friend bool sortbyavg(const pair<string, double> &a, pair<string, double> &b);
	friend bool checkNom(string);
	
	friend class Match;
	friend class Team;
	~Player();
};
