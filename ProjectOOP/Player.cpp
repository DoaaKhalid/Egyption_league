#include "Player.h"
#include "Team.h"
#include <fstream>
#include <queue>
Player::Player()
{
	this->Score = 0;
}

void Player::Load_Players() //function load player data from the file to the data memnbers
{
	queue <string> Players_Info;
		string line;
		ifstream myfile("Players.txt");
		if (myfile.is_open())
		{
			Player p;
			while (!myfile.eof() && myfile.peek() != std::ifstream::traits_type::eof())
			{
				myfile >> line;
				Players_Info.push(line);
			}
			myfile.close();
			while (!Players_Info.empty())
			{
				p.Player_Number = stoi(Players_Info.front());
				Players_Info.pop();
				p.Name = Players_Info.front();
				Players_Info.pop();
				p.Rank = stoi(Players_Info.front());
				Players_Info.pop();
				p.Score = stoi(Players_Info.front());
				Players_Info.pop();
				p.Age = stoi(Players_Info.front());
				Players_Info.pop();
				p.TeamName = Players_Info.front();
				Players_Info.pop();
				p.Type = Players_Info.front();
				Players_Info.pop();
				Players.push_back( p);
				if (Players_Info.size() == 1)
					break;
				
			}
		}
}

//_____________________________________________________________________________________________________

void Player::put_data()         //help function 
{
	ofstream Player_Info;
	Player_Info.open("Players.txt", ios::out);

	for (auto it = Players.begin(); it != Players.end(); it++)
	{
		Player_Info << it->Player_Number << "\t";
		Player_Info << it->Name << "\t";
		Player_Info << it->Rank << "\t";
		Player_Info << it->Score << "\t";
		Player_Info << it->Age << "\t";
		Player_Info << it->TeamName << "\t";
		Player_Info << it->Type << endl;
	}
	Player_Info.close();
}

//______________________________________________________________________________________________________
void Player::Update_Player() //function update data of the player
{
	Load_Players();
	cout << "The List Of Players :" << endl;
	for (auto i = Players.begin(); i != Players.end(); i++)
		cout << i->Player_Number << "\t" << i->Name << "\t" << i->TeamName << endl;
	cout << "Enter ID & Team Name Of Player : " << endl;
	string name;
	int id;
	cin >> id >> name;
	cout << "Choose What  You To Update" << endl;
	cout << "Press  1 To Name " << endl;
	cout << "Press  2 To Position " << endl;
	cout << "Press 3 To Score " << endl;
	cout << "Press 4  To Rank" << endl;
	int ch;
	cin >> ch;
	switch (ch)
	{
	case (1): {
		string s;
		cout << "Enter New Name" << endl;
		cin >> s;
		for (auto i = Players.begin(); i != Players.end(); i++)
			if (i->TeamName == name && i->Player_Number == id)
				i->Name = s;
		break;
	}
	case (2): {
		cout << "Enter PlayerType" << endl;
		cout << " 1 - Forward" << endl;
		cout << " 2 - midfielder" << endl;
		cout << " 3 - Defender" << endl;
		cout << " 4 - Goalkeeper" << endl;
		int nm;
		cin >> nm;
		for (auto i = Players.begin(); i != Players.end(); i++)
			if (i->TeamName == name && i->Player_Number == id)
				i->Type = PlayerType[nm - 1];
		break;
	}
	case (3): {
		int sco;
		cout << "Enter New Score" << endl;
		string s;
		cin >> s;
		while (checkNom(s) == false)
		{
			cout << "Error On Type Enter Only Num !!" << endl;
			cin >> s;
		}
		sco = stoi(s);
		for (auto i = Players.begin(); i != Players.end(); i++)
			if (i->TeamName == name && i->Player_Number == id)
				i->Score = sco;


		break;
	}
	case(4): {
		int rank;
		cout << "Enter New Rank " << endl;
		cin >> rank;
		for (auto i = Players.begin(); i != Players.end(); i++)
			if (i->TeamName == name && i->Player_Number == id)
				i->Rank = rank;
		break;
	}
	default: {
		cout << "Please Choose From 1 : 4 Only " << endl;
		break;
	}
	}
	put_data();
}
void Player::Enter_data() //enter data of player from the console th
{
	ofstream Player_Info;
	Player_Info.open("Players.txt", ios::out | ios::app);
	Player p;
	string s;
	cout << "Enter Player_Number" << endl;
	cin >> s;
	if(checkNom(s))
	p.Player_Number=stoi(s);
	else
	{
		cout << "Error" << endl;
		Enter_data();
	}
	Player_Info << p.Player_Number << "\t";
	cout << "Enter Player_Name:";
	cin >> p.Name;
	Player_Info << p.Name << "\t";
	
	cout << "Enter Player_Rank" << endl;
	cin >> p.Rank;
	Player_Info << p.Rank << "\t";

	cout << "Enter Player_Score" << endl;
	Player_Info << p.Score << "\t";

	cout << "Enter Player_Age" << endl;
	cin >> p.Age;
	Player_Info << p.Age << "\t";
	cout << "Enter Player_Team" << endl;
	cin >> p.TeamName;
	Player_Info << p.TeamName << "\t";

	cout << "Enter PlayerType" << endl;
	cout << " 1 - Forward" << endl;
	cout << " 2 - midfielder" << endl;
	cout << " 3 - Defender" << endl;
	cout << " 4 - Goalkeeper" << endl;
	int Ch;
	cin >> Ch;
	Player_Info << p.PlayerType[Ch - 1] << endl;
	Type = p.PlayerType[Ch - 1];
	Players.push_back(p);
	
	Player_Info.close();
}
void Player::Display_Data()
{
	cout << "The Player_Number \t" << "The Player_Name \t" << "The Player_Rank \t" << "The Player_Score\t";
	cout << "The Player_Age \t" << "The Player_Type \t" << endl;
	vector<Player> ::iterator i;
	for (i = Players.begin(); i != Players.end(); i++)
	{
		cout << i->Player_Number <<"\t\t\t";
		cout << i->Name << "\t\t\t";
		cout << i->Rank << "\t\t\t";
		cout << i->Score << "\t\t\t";
		cout << i->Age << "\t       ";
		cout << i->Type << endl;
	}
}
void Player::Display_Role()
{
	Load_Players();
	cout << "The Players_Role" << endl;
	for (auto i = Players.begin(); i != Players.end(); i++)
	{

		cout << i->Type << endl;
		if (Type == "Forward")
		{
			cout << "Forward : " << endl;
			cout << "His tasks are scoring goals and deflecting the defenses" << endl;
			cout << "____________________________________________________________________" << endl;
		}
		else if (Type == "Midfielder")
		{
			cout << "Midfielder : " << endl;
			cout << "The midfield is divided into" << endl;
			cout << "CDM : Center Defensive Midfielder" << endl;
			cout << "This player is a balance between defense and attack" << endl;
			cout << "It performs defensive missions and covers gaps in the case of defenders progress" << endl;
			cout << "CM : Center Midfielder" << endl;
			cout << "The task of the wing is to distribute the balls to the attackers";
			cout << "and move the game on the sides and activate the lateral spread on both sides of the stadium";
			cout << "____________________________________________________________________" << endl;

		}
		else if (Type == "Defender")
		{
			cout << "Defender" << endl;
			cout << "The line of defense is divided into" << endl;
			cout << "CB : Center Defensive :" << endl;
			cout << "The center of defense in the area is the approach of the goalkeeper , ";
			cout << "and his task is to defend the home and protect the goal and help the heart of defense goalkeeper in the protection of the goal";
			cout << "RB and LB : Right Back and Left Back" << endl;
			cout << "He is basically a 'defender' but he plays offensive roles" << endl;
			cout << "___________________________________________________________________________________________________________________________________" << endl;

		}
		else
		{
			cout << "GoalKeeper : " << endl;
			cout << "Each Team must have GoalKeeper , The goalkeeper is responsible";
			cout << "for protecting the goal from entering the goals" << endl;
			cout << "The goalkeeper can hold the ball with his hand,";
			cout << "foot or any place of his body";
			cout << "____________________________________________________________________" << endl;

		}
	}
}
bool sortbyavg(const pair<string, double> &a, pair<string, double> &b)
{
	//return (a.second.OwnGoals > b.second.OwnGoals);
	return (a.second > b.second);

}// To Compare To Sort Teams
void Display_teams_ordered_by_the_average_ages_of_its_players()
{
	Player p;
	Team T;
    p.Load_Players();
	T.Load_Teams();
	vector<pair<string, double>> Ages;
	double sum = 0;
	double avg;
	for (auto it2 = T.Teams.begin(); it2 != T.Teams.end(); it2++)
	{
		int count = 0;
		for (auto it = p.Players.begin(); it != p.Players.end(); it++)
		{
			if (it->TeamName == it2->second.Name)
			{
              sum += it->Age;
			  count++;
			}
			if (count > 0)
				avg = sum / count;
			else
				avg = 0;
		}
		Ages.push_back(make_pair(it2->second.Name, avg));
	}
	sort(Ages.begin(), Ages.end(), sortbyavg);
	for (auto it = Ages.begin(); it != Ages.end(); it++)
	{
		cout << it->first << "  ";
		if (it->second > 0)
			cout << it->second << endl;
		else
			cout << "This Team Haven't Players !!" << endl;

	}
}
void Player::Display_Spacific_Player_info()
{
	Load_Players();
	int id;
	string Name, Teams, s;
	cout << "Enter ID And Name And TeamName: ";
	cin >> s >> Name >> Teams;
	while (checkNom(s) == false)
	{
		cout << "Error On Type Enter Only Num !!" << endl;
		cout << "Enter ID And Name And TeamName: ";
		cin >> s >> Name >> Teams;
	}
	id = stoi(s);
	bool Flag = true;
	cout << "The Player_Number \t" << "The Player_Name \t" << "The Player_Rank \t" << "The Player_Score\t";
	cout << "The Player_Age \t" << "The Player_Type \t" << endl;
	for (auto i = Players.begin(); i != Players.end(); i++)
	{
		if (i->Player_Number == id && i->Name == Name && i->TeamName == Teams)
		{
			cout << i->Player_Number << "\t\t\t";
			cout << i->Name << "\t\t\t";
			cout << i->Rank << "\t\t\t";
			cout << i->Score << "\t\t\t";
			cout << i->Age << "\t\t";
			cout << i->Type << endl;
			Flag = true;
			break;
		}
		else
			Flag = false;
	}
	if (Flag == false)
		cout << "This Player Not Exist" << endl;
	Players.clear();
}
void Player::Display_Team_member(string n , int x)
{
	Load_Players();
	cout << "The Player_Number \t" << "The Player_Name \t" << "The Player_Rank \t" << "The Player_Score\t";
	cout << "The Player_Age \t" << "The Player_Type \t" << endl;
	for (auto i = Players.begin(); i != Players.end(); i++)
	{
		if (i->TeamName == n && x == 0) // Part Display Teams
		{
			cout << i->Player_Number << "\t\t\t";
			cout << i->Name << "\t\t";
			cout << i->Rank << "\t\t\t";
			cout << i->Score << "\t\t\t";
			cout << i->Age << "\t\t";
			cout << i->Type << endl;
		}
		else if(i->Type == "Goalkeeper" && i->TeamName == n && x > 0)
		{
			cout << i->Player_Number << "\t\t\t";
			cout << i->Name << "\t\t";
			cout << i->Rank << "\t\t\t";
			cout << i->Score << "\t\t\t";
			cout << i->Age << "\t\t";
			cout << i->Type << endl;
		}
	}
	Players.clear();
}
void Player::Update_Player_Score(string s, string x)
{
	Load_Players();
	for (auto i = Players.begin(); i != Players.end(); i++)
		if (i->Name == x && i->TeamName == s)
			i->Score += 1;
	put_data();
	Players.clear();
}

void Display_3_Frist_Players_By_Rank()
{
	Player p;
	p.Load_Players();
	map <int, Player> mp;
	for (auto i = p.Players.begin(); i != p.Players.end(); i++)
		mp.insert(make_pair(i->Rank, *i));
	multimap <int, Player> ::reverse_iterator it;
	int counter = 0;
	for (it = mp.rbegin(); it != mp.rend(); it++)
	{
		cout << it->second.Name << endl;
		counter++;
		if (counter == 3)
			break;
	}
}
void Display_3_Frist_Players_By_Goals()
{
	Player p;
	p.Load_Players();
	map <int, Player> mp;
	for (auto i = p.Players.begin(); i != p.Players.end(); i++)
		mp.insert(make_pair(i->Score, *i));
	multimap <int, Player> ::reverse_iterator it;
	int counter = 0;
	for (it = mp.rbegin(); it != mp.rend(); it++)
	{
		cout << it->second.Name << endl;
		counter++;
		if (counter == 3)
			break;
	}
}
bool checkNom(string s)
{
	bool flag =true;
	for (int i = 0; i < s.size(); i++)
	{
		if (!(s[i] >= 48 && s[i] <= 57))
			flag = false;
	}
	return flag;
}
Player::~Player()
{
}
/*General Functions */