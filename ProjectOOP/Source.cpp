#include <iostream>
#include <string>
#include <list>
#include "Player.h"
#include "Match.h"
#include <map>
#include <fstream>
#include <queue>
#include <typeinfo>
using namespace std;
int c;
char h;
void main_menu();
void team_selection()
{
	system("CLS");
	Team t;
	int x;
	cout << "Select operation you want from the following" << endl;
	cout << "______________________________________________" << endl;
	cout << "\t \t \t \t" << endl;
	cout << "1 - Enter New Team Information " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "2 - Display Team Information " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "3 - Update Team Information " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "4 - Search For Team " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "5 - Display Team Players " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "6 - Display Team Detailed Score " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "7 - Display Team Matches with all Details " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "8 - Display team matches as held matches and to be held matches " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "9 - Return To The Main Menu " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "Press The Number of Your Choice From The Menu " << endl;
	cin >> x;
	if (x == 1)
	{
		system("CLS");
		do {
			t.Add_Team();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			team_selection();
	}
	else if (x == 2)
	{
		system("CLS");
		do {
			t.Load_Teams();
			t.Display_Team_Info();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			team_selection();
	}
	else if (x == 3)
	{
		system("CLS");
		do {

			t.Update_team_information();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			team_selection();
	}
	else if (x == 4)
	{
		system("CLS");
		do {

			t.Search_for_team();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			team_selection();

	}
	else if (x == 5)
	{
		system("CLS");
		do {

			t.Display_team_player();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			team_selection();
	}
	else if (x == 6)
	{
		system("CLS");
		do {

		t.Display_team_detailed_scores();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			team_selection();
	}
	else if (x == 7)
	{
		system("CLS");
		do {

			t.Display_Matches();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			team_selection();
	}
	else if (x == 8)
	{
		system("CLS");
		do {

			t.DisPlay_Team_Match_With_Date();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			team_selection();
	}
	else if (x == 9)
	{
		main_menu();
	}
	else
	{
		while (x>9)
		{
			team_selection();
		}
	}
}
void player_selection()
{
	system("CLS");
	Player p;
	int x;
	cout << "Select operation you want from the following" << endl;
	cout << "______________________________________________" << endl;
	cout << "\t \t \t \t" << endl;
	cout << "1 - Enter New Player Information " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "2 - Display Player Information " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "3 - Display player role with description " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "4 - Update Player Information  " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "5 - Search For Player " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "6 - Return To The Main Menu " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "Press The Number of Your Choice From The Menu " << endl;
	cin >> x;
	if (x == 1)
	{
		system("CLS");
		do {

			p.Enter_data();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			player_selection();

	}
	else if (x == 2)
	{

		system("CLS");
		do {
			p.Load_Players();
			p.Display_Data();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			player_selection();
	}
	else if (x == 3)
	{

		system("CLS");
		do {

			p.Display_Role();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			player_selection();
	}
	else if (x == 4)
	{

		system("CLS");
		do {

			p.Update_Player();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			player_selection();
	}
	else if (x == 5)
	{

		system("CLS");
		do {

			p.Display_Spacific_Player_info();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			player_selection();
	}
	else if (x == 6)
	{
		main_menu();
	}
	else
	{
		while (x>6)
		{
			player_selection();
		}
	}
}
void Match_selection()
{
	system("CLS");
	Match m;
	int x;
	cout << "Select operation you want from the following" << endl;
	cout << "______________________________________________" << endl;
	cout << "\t \t \t \t" << endl;
	cout << "1 - Enter New Match Information " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "2 - Display All Matches with Details " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "3 - Display held Matches and to be held Matches " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "4 - Update a certain Match" << endl;
	cout << "\t \t \t \t" << endl;
	cout << "5 - Return To The Main Menu " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "Press The Number of Your Choice From The Menu " << endl;
	cin >> x;
	if (x == 1)
	{
		system("CLS");
		do {

			m.Enter_match_Data();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			Match_selection();

	}
	else if (x == 2)
	{
		system("CLS");
		do {

			m.display_all_matches();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			Match_selection();
	}
	else if (x == 3)
	{
		system("CLS");
		do {

			m.Display_held_matches_and_to_be_held_matches();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			Match_selection();
	}
	else if (x == 4)
	{
		system("CLS");
		do {

			m.Update_Match();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			Match_selection();
	}
	else if (x == 5)
	{
		main_menu();
	}
	else
	{
		while (x>5)
		{
			Match_selection();
		}
	}
}
void General_selection()
{
	system("CLS");
	Team t;
	Player p;
	Match m;
	int x;
	cout << "Select operation you want from the following" << endl;
	cout << "______________________________________________" << endl;
	cout << "\t \t \t \t" << endl;
	cout << "1 - Display Teams ordered by their Points " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "2 - Display top (3) players who score the greatest no of goals " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "3 - Display top (3) goalkeepers who have the fewest no of goals " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "4 - Display top (3) players ordered by their ranks" << endl;
	cout << "\t \t \t \t" << endl;
	cout << "5 - Display teams ordered by no. of scored goals" << endl;
	cout << "\t \t \t \t" << endl;
	cout << "6 - Display teams ordered by the average ages of its players" << endl;
	cout << "\t \t \t \t" << endl;
	cout << "7 - Display matches in a certain date" << endl;
	cout << "\t \t \t \t" << endl;
	cout << "8 - Return To The Main Menu " << endl;
	cout << "\t \t \t \t" << endl;
	cout << "Press The Number of Your Choice From The Menu " << endl;
	cin >> x;
	if (x == 1)
	{

		system("CLS");
		do {
			Display_3_Frist_Teams_By_Points();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			General_selection();
	}
	else if (x == 2)
	{

		system("CLS");
		do {

			Display_3_Frist_Players_By_Goals();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			General_selection();
	}
	else if (x == 3)
	{

		system("CLS");
		do {
			Display_3_First_GoalKeepers();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			General_selection();
	}
	else if (x == 4)
	{

		system("CLS");
		do {
			Display_3_Frist_Players_By_Rank();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			General_selection();
	}
	else if (x == 5)
	{

		system("CLS");
		do {
			Display_3_First_Teams_By_Total_Score();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			General_selection();
	}
	else if (x == 6)
	{

		system("CLS");
		do {
			Display_teams_ordered_by_the_average_ages_of_its_players();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			General_selection();
	}
	else if (x == 7)
	{
		system("CLS");
		do {
			Display_Match_Certain_date();
			cout << "Press y if you want to add another data or n To return the previous player menu " << endl;
			cin >> h;
			while (h != 'n' && h != 'y')
			{
				cout << "Invalid Charachter ! Please Enter Correct Charachter " << endl;
				cin >> h;
			}
		} while (h != 'n');
		if (h == 'n')
			General_selection();
	}
	else if (x == 8)
	{
		main_menu();
	}
	else
	{
		while (x>8)
		{
			General_selection();
		}
	}
}
void main_menu()
{
	system("CLS");
	Player p;
	Match m;
	cout << "\t \t \t \t \t " << endl;
	cout << "\t \t \t \t \t Egyptian League Management System" << endl;
	cout << "\t \t \t \t \t _________________________________" << endl;
	cout << "\t \t \t \t \t " << endl;
	cout << "\t \t \t \tPlease Choose The department You want From The Following" << endl;
	cout << "\t \t \t \t \t        ____________________" << endl;
	cout << "\t \t \t \t \t " << endl;
	cout << "\t \t \t \t \t \t    1 - Team  " << endl;
	cout << "\t \t \t \t \t" << endl;
	cout << "\t \t \t \t \t \t    2 - Players " << endl;
	cout << "\t \t \t \t \t " << endl;
	cout << "\t \t \t \t \t \t    3 - Matchs" << endl;
	cout << "\t \t \t \t \t " << endl;
	cout << "\t \t \t \t \t \t    4 - General" << endl;
	cout << "\t \t \t \t \t " << endl;
	cout << "\t \t \t \t \t \t    5 - Exit" << endl;
	cout << "\t \t \t \t \t " << endl;

	do {
		cin >> c;
		if (c == 1)
		{
			team_selection();
		}
		else if (c == 2)
		{
			player_selection();
		}
		else if (c == 3)
		{
			Match_selection();
		}
		else if (c == 4)
		{
			General_selection();
		}
		else
		{
			while (c > 6)
			{
				main_menu();
			}
		}
	} while (c != 5);
}

int main()
{
	main_menu();
	return 0;
}