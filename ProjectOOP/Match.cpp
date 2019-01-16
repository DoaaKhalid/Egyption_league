#include "Match.h"
#include <queue>
#include <fstream>

Match::Match()
{
}
void Match::Enter_match_Data()
{
	ofstream Match_File;
	Match_File.open("Match.txt", ios::out | ios::app);
	Match m;
	Load_Matches();
	cout << "Enter Match ID : " << endl;
	string s;
	cin >> s;
	m.ID_Match = stoi(s);
	while (true)
	{
		while (checkNom(s) == false)
		{
			cout << "Error On Type Enter Only Num !!" << endl;
			cin >> s;
		}
		auto it1 = matches.find(m.ID_Match);
		if (it1 == matches.end())
		{
			Match_File << m.ID_Match << "\t";
			break;
		}
		else
		{
			cout << "Error This ID Is Alrady Found !!" << endl;
			cin >> s;
			m.ID_Match = stoi(s);
		}
	}
	m.ID_Match = stoi(s);

	cout << "Enter Two  Teams : ";
	cin >> m.team1 >> m.team2;
	Team t1;
	t1.Load_Teams();
	bool T1 = false, T2 = false;
	while (true)
	{
		for (auto it = t1.Teams.begin(); it != t1.Teams.end(); it++)
			if (it->second.Name == m.team1)
				T1 = true;
			else if (it->second.Name == m.team2)
				T2 = true;
		if (T1 == false)
		{
			cout << "This Team Not Exist Enter Team1" << endl;
			cin >> m.team1;
		}
		if (T2 == false)
		{
			cout << "This Team Not Exist Enter Team2" << endl;
			cin >> m.team2;
		}
		if (T1 && T2)
			break;
	}
	cout << "Enter Scores : ";
	string ss, s1;
	cin >> ss >> s1;
	while (checkNom(ss) == false && checkNom(s1))
	{
		cout << "Error On Type Enter Only Num !!" << endl;
		cin >> s >> s1;
	}
	m.Score_Team_One = stoi(ss);
	m.Score_Team_two = stoi(s1);
	Player p;
	if (m.Score_Team_One > 0)
	{
		cout << "First Team : " << m.team1 << endl;
		for (int i = 0; i < m.Score_Team_One; i++)
		{
			cout << "Enter Player Name" << endl;
			string s; cin >> s;
			p.Update_Player_Score(m.team1, s);
		}
	}
	if (m.Score_Team_two > 0)
	{
		cout << "Scond Team : " << m.team2 << endl;
		for (int i = 0; i < m.Score_Team_two; i++)
		{
			cout << "Enter Player Name" << endl;
			string s; cin >> s;
			p.Update_Player_Score(m.team2, s);
		}
	}

	while (true)
	{
		auto it = lega.find(make_pair(m.team1, m.team2));
		if (it == lega.end())
		{
			m.lega.insert(make_pair(make_pair(m.team1, m.team2), make_pair(m.Score_Team_One, m.Score_Team_two)));
			Match_File << m.team1 << "\t" << m.Score_Team_One << "\t" << m.team2 << "\t" << m.Score_Team_two << "\t";
			break;
		}
		else
		{
			cout << "Error This Match Is Already Found !!" << endl;
			cout << "Enter Two Teams" << endl;
			cin >> m.team1 >> m.team2;
		}
	}
	cout << "Enter Match Date :" << endl;
	cin >> m.Date;
	while (validDate(m.Date) == false)
	{
		cout << "Invalid Data Enter Date" << endl;
		cin >> m.Date;
	}
	Match_File << m.Date << "\t";
	cout << "Enter Match Referee : " << endl;
	cin >> m.Footbool_referee;
	Match_File << m.Footbool_referee << "\t";
	cout << "Enter Stadium Name : " << endl;
	cin >> m.Stadium_Name;
	Match_File << m.Stadium_Name << endl;
	matches.insert(make_pair(m.ID_Match, m));
	Team t;
	t.Update_Total_Score(m.team1, m.Score_Team_One);
	t.Update_Total_Score(m.team2, m.Score_Team_two);
	t.Update_GoalKeepar_Score(m.team1, m.Score_Team_two);
	t.Update_GoalKeepar_Score(m.team2, m.Score_Team_One);
	t.Update_Points(m.team1, m.Score_Team_One, m.Score_Team_two);
	t.Update_Points(m.team2, m.Score_Team_two, m.Score_Team_One);
}
void Match::display_all_matches()
{
	Load_Matches();
	map<int, Match> ::iterator it;
	for (auto it = matches.begin(); it != matches.end(); it++)
	{
		cout << "ID :" << it->second.ID_Match << endl;
		cout << "Date :" << it->second.Date << endl;
		cout << "Footbool referee :" << it->second.Footbool_referee << endl;
		cout << " Stadium Name :" << it->second.Stadium_Name << endl;
		cout << it->second.team1 << "(" << it->second.Score_Team_One << ")" << "-" << it->second.team2 << "(" << it->second.Score_Team_two << ")" << endl;
		cout << "_____________________________________" << endl;
	}
}
void Match::Put_Data_in_Match()
{
	ofstream matches_File;
	matches_File.open("Match.txt", ios::out);
	for (auto it = matches.begin(); it != matches.end(); it++)
	{
		matches_File << it->second.ID_Match << "\t";
		matches_File << it->second.team1 << "\t" << it->second.Score_Team_One << "\t" << it->second.team2 << "\t" << it->second.Score_Team_two << "\t";
		matches_File << it->second.Date << "\t";
		matches_File << it->second.Footbool_referee << "\t";
		matches_File << it->second.Stadium_Name << endl;
	}
	matches_File.close();
}
void Match::Update_Match() {
	display_all_matches();
	Team a;
	bool flag = false;
	int id;
	cout << "Enter MatCh ID" << endl;
	string s;
	cin >> s;
	while (checkNom(s) == false)
	{
		cout << "Error On Type Enter Only Num !!" << endl;
		cin >> s;
	}
	id = stoi(s);
	cout << "Choose What  You To Update" << endl;
	cout << "Press  1 To First_Team Name " << endl;
	cout << "Press  2 To Second_Team Name" << endl;
	cout << "Press 3 To First_Team_Score " << endl;
	cout << "Press 4  To Second_Team_Score" << endl;
	cout << "Press 5 To Referee Name" << endl;
	cout << "Press 6  To Stadium Name " << endl;
	int ch;
	cin >> ch;
	switch (ch)
	{
	case (1): {
		string s;
		cout << "Enter New Name" << endl;
		cin >> s;
		for (auto i = matches.begin(); i != matches.end(); i++)
			if (i->second.ID_Match == id)
			{
				i->second.team1 = s;
				flag = true;
			}
		break;
	}
	case (2): {
		string s;
		cout << "Enter New Name" << endl;
		cin >> s;
		for (auto i = matches.begin(); i != matches.end(); i++)
			if (i->second.ID_Match == id)
			{
				i->second.team2 = s;
				flag = true;
			}
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
		for (auto i = matches.begin(); i != matches.end(); i++)
			if (i->second.ID_Match == id)
			{
				i->second.Score_Team_One = sco;
				a.Update_Total_Score(i->second.team1, sco);
				flag = true;
			}

		break;
	}
	case(4): {
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
		for (auto i = matches.begin(); i != matches.end(); i++)
			if (i->second.ID_Match == id)
			{
				i->second.Score_Team_two = sco;
				a.Update_Total_Score(i->second.team2, sco);
				flag = true;
			}
		break;

	}
	case(5): {
		string s;
		cout << "Enter New Referee Name" << endl;
		cin >> s;
		for (auto i = matches.begin(); i != matches.end(); i++)
			if (i->second.ID_Match == id)
			{
				i->second.Footbool_referee = s;
				flag = true;
			}
		break;

	}
	case(6): {
		string s;
		cout << "Enter New Stadium Name" << endl;
		cin >> s;
		for (auto i = matches.begin(); i != matches.end(); i++)
			if (i->second.ID_Match == id)
			{
				i->second.Stadium_Name = s;
				flag = true;
			}
		break;

	}
	default: {
		cout << "Please Choose From 1 : 4 Only " << endl;
		break;
	}
	}
	if (!flag)
	{
		cout << "This Match is'nt Exist !!" << endl;
		Update_Match();
	}
	Put_Data_in_Match();
}
bool validDate(string &date) {
	if (date.length() > 10 || date.length() < 8)return false;
	if (!(date[0] >= 48 && date[0] <= 57 && date[1] >= 48 && date[1] <= 57))
		date.insert(0, "0");
	if (!(date[3] >= 48 && date[3] <= 57 && date[4] >= 48 && date[4] <= 57))
		date.insert(3, "0");
	string int_only = date;
	int_only.erase(2, 1);
	int_only.erase(4, 1);
	if (!checkNom(int_only))return false;
	date[2] = date[5] = '-';
	int day = ((date[0] - 48) * 10) + (date[1] - 48);
	int month = ((date[3] - 48) * 10) + (date[4] - 48);
	int year = (((date[6] - 48) * 1000) + ((date[7] - 48) * 100) + ((date[8] - 48) * 10) + (date[9] - 48));
	if (day > 31 || day < 1 || month>12 || month < 1 || year < 1979)
		return false;
	return true;
}
void Match::Load_Matches()
{
	queue <string> Match_info;
	string word2;
	ifstream MatchFile("Match.txt");
	if (MatchFile.is_open())
	{

		while (!MatchFile.eof() && MatchFile.peek() != std::ifstream::traits_type::eof())
		{
			MatchFile >> word2;
			Match_info.push(word2);
		}
		MatchFile.close();
		while (!Match_info.empty())
		{
			Match M;
			M.ID_Match = stoi(Match_info.front());
			Match_info.pop();
			M.team1 = Match_info.front();
			Match_info.pop();
			M.Score_Team_One = stoi(Match_info.front());
			Match_info.pop();
			M.team2 = Match_info.front();
			Match_info.pop();
			M.Score_Team_two = stoi(Match_info.front());
			Match_info.pop();
			M.Date = Match_info.front();
			Match_info.pop();
			M.Footbool_referee = Match_info.front();
			Match_info.pop();
			M.Stadium_Name = Match_info.front();
			Match_info.pop();
			matches.insert(make_pair(M.ID_Match, M));
			lega.insert(make_pair(make_pair(M.team1, M.team2), make_pair(M.Score_Team_One, M.Score_Team_two)));
			if (Match_info.size() == 1)
				break;
		}
	}
}
void Display_Match_Certain_date()
{
	Match m;
	m.Load_Matches();
	cout << "Enter Date " << endl;
	string s;
	cin >> s;
	while (!validDate(s))
	{
		cout << "Invalid Data Enter Date" << endl;
		cin >> s;
	}
	bool Exist = true;
	for (auto it = m.matches.begin(); it != m.matches.end(); it++)
	{
		if (it->second.Date == s)
		{
			cout << "ID :" << it->second.ID_Match << endl;
			cout << "Date :" << it->second.Date << endl;
			cout << "Footbool referee :" << it->second.Footbool_referee << endl;
			cout << " Stadium Name :" << it->second.Stadium_Name << endl;
			cout << it->second.team1 << "(" << it->second.Score_Team_One << ")" << "-" << it->second.team2 << "(" << it->second.Score_Team_two << ")" << endl;
			cout << "_____________________________________" << endl;
			Exist = false;
		}
	}
	if (Exist)
		cout << "No Matches in This Time" << endl;
}
void Match::Display_held_matches_and_to_be_held_matches()
{
	vector<string>helded;
	Team t;
	t.Load_Teams();
	Load_Matches();
	for (auto i = matches.begin(); i != matches.end(); i++)
	{
		cout << "\t \t \t \t\t" << endl;
		cout << "Team : " << i->second.team1 << endl;
		cout << "_____________________" << endl;
		string s = i->second.team1;
		cout << "\t \t \t \t\t" << endl;
		cout << "Held Matches with : " << endl;
		cout << "\t \t \t \t\t" << endl;
		for (auto it = matches.begin(); it != matches.end(); it++)
		{
			if (s == it->second.team1)
			{
				cout << it->second.team2 << endl;
				helded.push_back(it->second.team2);
			}
			else if (s == it->second.team2)
			{
				cout << it->second.team1 << endl;
				helded.push_back(it->second.team1);
			}
		}
		cout << "\t \t \t \t\t" << endl;
		cout << "========" << endl;
		cout << "\t \t \t \t\t" << endl;
		cout << "To be Held Matches with : " << endl;
		cout << "\t \t \t \t\t" << endl;
		for (auto it = t.Teams.begin(); it != t.Teams.end(); it++)
		{
			auto f = find(helded.begin(), helded.end(), it->second.Name);
			if (f == helded.end() && it->second.Name != s)
			{
				cout << it->second.Name << endl;
			}
		}
		helded.clear();
		cout << endl;
		cout << "______________________________________" << endl;
	}
}

Match::~Match()
{
}
