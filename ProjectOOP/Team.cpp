#include "Team.h"
#include"Match.h"
#include "Player.h"
#include <fstream>
#include <queue>
Team::Team()
{
	this->Goals = 0;                         //Default constructor of class team
	this->OwnGoals = 0;
	this->Points = 0;
}
void Team::Load_Teams()                      //a function used for loading team data from the file which we stored in to the data members of the class
{
	queue <string> Teams_Info;               //first we declared a queue of string to store words from the line in the file
	string word;                             //Declareing string word that will take the word from line
	ifstream TeamFile("Teams.txt");          //opening the team file;
	if (TeamFile.is_open())                  //if the file is exist and opened do the following
	{
		Player p;                            //create object of player to call load player data function because we need players data on the list of players on teams
		p.Load_Players();                    //calling the function from the object
		
		while (!TeamFile.eof() && TeamFile.peek() != std::ifstream::traits_type::eof())  //while the file doesn't reach it's end and the cursor not reach the end of file do the following
		{
			TeamFile >> word;                //take the string word from the file 
			Teams_Info.push(word);           //then push it into the queue we declared
		}
		TeamFile.close();                    //closing the file
		while (!Teams_Info.empty())          //while the queue is not empty do the following
		{
			Team T;                          //create an object of class team to save data and put it to the maps which we will call later
			                                 // queue saved the data from file in the same order of data members of the class so we will take every element in the queue and store it in the object data member then pop it from the queue and so on ..
			T.Name = Teams_Info.front();         
			Teams_Info.pop();
			T.ID_Team = stoi(Teams_Info.front());
			Teams_Info.pop();
			T.OwnGoals = stoi(Teams_Info.front());
			Teams_Info.pop();
			T.Goals = stoi(Teams_Info.front());
			Teams_Info.pop();
			T.Captain = Teams_Info.front();
			Teams_Info.pop();
			T.Points = stoi(Teams_Info.front());
			Teams_Info.pop();
			vector <  Player >::iterator it;            //declaring a vector of player iterator 
			for ( it = p.Players.begin(); it != p.Players.end(); it++)             
			{                                           //looping on the players vector
				if (it->TeamName == T.Name)             //if the team name of player object is equal to team object name 
				{
					Player test;                        
	                                                    //create another object of player then take the data of the object and store it here in the object we created
					test.Age = it->Age;                 
					test.Name = it->Name;
					test.Rank = it->Rank;
					test.TeamName = it->TeamName;
					
					test.Player_Number = it->Player_Number;
           T.Team_Members.insert(make_pair(test.Player_Number, test));   //taking the object "test" which we created and insert it to team member map as that each node in team member map contain the player number and his data 
				}
					
			}
			Teams.insert(make_pair(T.ID_Team, T));                      //here we take the whole object t we created from class team and insert it to teams map which contain all teams, each node contain team id and it's details
			if (Teams_Info.size() == 1)                                 //if we reached the end of file break the loop
				break;
		}
	}
	
}

//______________________________________________________________________________________________________________

void Team::Display_Team_Info()      //Function for display all teams informations
{
	Load_Teams();                   // the function we created above that load data from file
	for (auto i = Teams.begin(); i != Teams.end(); i++)          //teams map is the map in which we stored all teams with there ids so we will loop on the map and display data from teams objects we stored
	{
		Player p;                   //creating player object to call Display_Team_member function from it
		
		cout << "Team Name : " << i->second.Name << endl;          
		cout << "Team ID : " << i->second.ID_Team << endl;         
		cout << "Team Score :" << i->second.OwnGoals << endl;                                                      //////
		cout << "Team Captain :" << i->second.Captain << endl;                                                         //
		if (i->second.Team_Members.size() != 0)       //if the team has members in it                               //
		{                                                                                                              ///////  displaying team data from each object in the map
			cout << "Team Members :" << endl;                                                                          //
			p.Display_Team_member(i->second.Name, 0);                                                              //////
		}
		else                                         //if the team has no members print that there isn't no members
			cout << "The Team has no Members" << endl;             
		cout << "........................................................................... " << endl;
	}
}
void Team::Display_team_player()         //Function that takes Team name and print it's players with their details
{
	Load_Teams();                        // the function we created above that load data from file
	string Name;                         //declaring a string name to take it from the user as a team name 
	cout << "Enter Team Name" << endl;
	cin >> Name;                         //Entering team name
	for (auto i = Teams.begin(); i != Teams.end(); i++)     //looping on teams map which contains all teams      
	{
		if (i->second.Name == Name)                         //searching if the team name of the object in the map is equal to the team name we got from the user
		{                                                   //if exist we print the players data of the team from the function Display_Team_member  /////
			cout << "Team Players : " << endl;                                                                                                         //
			map<int, Team> ::iterator it;// to see map of Teams                                                                                        //
			i->second.Team_Members;                                                                                                                    //
			map<int, Player> ::iterator it1; //iterator in list of players to see player in each team                                                  //
			it1 = i->second.Team_Members.begin();                                                                                                      //
			it1->second.Display_Team_member(it1->second.TeamName , 0);                                                   ////////////////////////////////
			it1++;                                                                                                                                    
			break;                                                                                                                                   
		}                                                                                                                                              
	}                                                                                                                                                                                                                                                                                       //
}                     

//___________________________________________________________________________________________________________________
void Team::Add_Team()
{
	Load_Teams();
	ofstream Teams_File;
	Teams_File.open("Teams.txt", ios::out | ios::app);
	Team t;
	cout << "Enter Team Name : " << endl;
	cin >> t.Name;
	Teams_File << t.Name << "\t";

	string s;
	cout << "Enter Team ID :" << endl;
	cin >> s;
	while (true)
	{

		if (checkNom(s))
			t.ID_Team = stoi(s);
		else
		{
			cout << "Error Enter Int Data" << endl;
			cin >> s;
		}
		t.ID_Team = stoi(s);
		auto it = Teams.find(t.ID_Team);
		if (it != Teams.end())
		{
			cout << "This Team ID Already Exist" << endl;
			cin >> s;
		}
		else
			break;
	}
	t.ID_Team = stoi(s);
	Teams_File << t.ID_Team << "\t";
	Teams_File << t.OwnGoals << "\t";
	t.Goals = 0;
	Teams_File << t.Goals << "\t";
	cout << "Enter Team Captain \n";
	cin >> t.Captain;
	Teams_File << t.Captain << "\t";//"\t"; 
	Teams_File << t.Points << endl;

	char ch;
	while (true)
	{
		cout << "Press (y) To Add Team Player :  (n) To Skip \n";
		cin >> ch;
		if (ch == 'n' || ch == 'N')
			break;
		Player p;
		p.Enter_data();
		t.Team_Members.insert(make_pair(p.Player_Number, p));
		p.Players.push_back(p);
	}
	Teams.insert(make_pair(t.ID_Team, t));
	//////////////////////////////////////////////////////////////

}


//_________________________________________________________________________________________________________________________


void Team::Search_for_team()                    //Function That search for a team and it's information
{
	Load_Teams(); // the function we created above that load data from file
	Player p;
	p.Load_Players();
	bool found = 0;                             // declaring checker found
	int id_search;                              //integer we will take from the user describe the id he want to search for
	string name_search;                         //String we will take from the user describe the Team name he want to search for
	cout << "Enter ID & Name For team You want to search " << endl;
	string s, s1;                               
	cin >> s >> name_search;                    //Entering team name and id
	while (!checkNom(s))                                       ///////////
	{                                                                  //
		cout << "Error On Type Enter Only Num !!" << endl;             ////// check validation data
		cin >> s >> name_search;                              //////////
	}
	id_search = stoi(s);

	map<int, Team> ::iterator it;
	for (it = Teams.begin(); it != Teams.end(); it++) 
	{
		/*
		    looping on teams map which contain all teams, if the team name and id existed
			in an object of the map we will display the data of the object as the details of team he searched for
		*/
		if (it->first == id_search && it->second.Name == name_search)
		{
			cout << "Name OF team You want is : " << Teams[id_search].Name << endl;
			cout << "ID OF team You want is : " << Teams[id_search].ID_Team << endl;
			cout << "Capitan OF team You want is : " << Teams[id_search].Captain << endl;
			cout << "Players OF team You want is : " << endl;
			map<int, Player> ::iterator it1;                 //iterator in list of players to see player in each team 
			it1 = it->second.Team_Members.begin();
			it1->second.Display_Team_member(it1->second.TeamName, 0);
			it1++;
			found = true;
			break;
		}
	}
	if (!found)   // if the team name and id doesn't exist we will print that the team not found
		cout << "Not Found !!" << endl;
}

//____________________________________________________________________________________________________________________

void Team::Update_team_information()    //Function for updating team information
{
	Load_Teams();                       // the function we created above that load data from file
	Display_Team_Info();                //display team information for prevent the user entering wrong data
	int id_search;                      //integer we will take from the user describe the id he want to update it's team
	string name_search;                 //String we will take from the user describe the Team name he want to update it's team
	int ch;                             
	string s;
	cout << "Enter Team Name & ID Of team : " << endl;
	cin >> name_search >> s;
	while (checkNom(s) == false)                            /////////////////
	{                                                                      //
		cout << "Error On Type Enter Only Num !!" << endl;                 /////// check data validation
		cin >> s >> name_search;                                           //
	}                                                      //////////////////
	id_search = stoi(s);
	cout << "What you want Update : " << endl;            //////////////////
	cout << " update Name press 1" << endl;                               //
	cout << " update ID OF team  press 2" << endl;                        ////// Check what type of updating he want
	cout << " update Capitan OF team  press 3" << endl;                   //
	cout << " update Players OF team  press 4" << endl;                   //
	cin >> ch;                                           ///////////////////
	switch (ch)
	{
	case 1:
	{
		/*
		in case of choosing update Name, we will take from him the new team name and replace it with the old one
		in the data stored
		*/
		string new_s;
		cout << "Enter New Name" << endl;
		cin >> new_s;
		for (auto i = Teams.begin(); i != Teams.end(); i++)
			if (i->second.Name == name_search   && i->second.ID_Team == id_search)
				i->second.Name = new_s;
		break;
	}
	case 2:
	{
		/*
		in case of choosing update ID OF team , we will take from him the new id name and replace it with the old one
		in the data stored
		*/
		int  new_s;
		cout << "Enter New ID" << endl;
		cin >> new_s;
		for (auto i = Teams.begin(); i != Teams.end(); i++)
			if (i->second.Name == name_search   && i->second.ID_Team == id_search)
				i->second.ID_Team = new_s;
		break;
	}
	case 3:
	{
		/*
		in case of choosing update Capitan OF team , we will take from him the new captain name and replace it with the old one
		in the data stored
		*/
		string  new_s;
		cout << "Enter New Captain" << endl;
		cin >> new_s;
		for (auto i = Teams.begin(); i != Teams.end(); i++)
			if (i->second.Name == name_search   && i->second.ID_Team == id_search)
				i->second.Captain = new_s;
		break;
	}
	case 4:
	{
		/*
		in case of choosing update Players OF team , we will take from him the new captain name and replace it with the old one
		in the data stored
		*/
		Player p;
		p.Update_Player();
		break;
	}
	}
	Put_Data_in_file(); //Function that take data we updated and update it into the file
}


//______________________________________________________________________________________________________________________________

//!!!!!!!!!!!!!!!!!!!!!! how ?
void Team::Display_team_Order(string n)       //Function that display teams ordered by their points
{
	Load_Teams();                             // the function we created above that load data from file
	/*Here we loop on teams map and checking on it if the object team name is the same as 
	the string we got from the user 
	if that is true we will Display the team name and it's id */
	for (auto i = Teams.begin(); i != Teams.end(); i++)
	{
		if (i->second.Name == n) // Check Team Name From Function Display_3_Frist_Teams
		{	
			cout << "Team Name : ";
			cout << i->second.Name << endl;
			cout << "Team Num  : ";
			cout << i->second.ID_Team << endl;
		}
	}
} // Display Spacific Team From Function Display_3_Frist_Teams

//_________________________________________________________________________________________________________________

void Team::Display_Matches()                  //Function for display team matches with all details
{
	string s;                
	Match m;                                  //creating object of class matches to call Load_Matches function from it
	m.Load_Matches();                         //calling load matches function
	Load_Teams();                             //Function that display teams ordered by their points
	cout << "Enter Name Team You Want To Display : ";
	cin >> s;                                 //taking the team name he want to display it's all matches details
	/*here we loop on matches map and check if the name of the team i took from the user exist or not 
	if it's exist  */
	for (auto it = m.matches.begin(); it != m.matches.end(); it++)
		if (it->second.team1 == s || it->second.team2 == s)
		{
			cout << "ID :" << it->second.ID_Match << endl;
			cout << "Date :" << it->second.Date << endl;
			cout << "Footbool referee :" << it->second.Footbool_referee << endl;
			cout << "Stadium Name :" << it->second.Stadium_Name << endl;
			cout << it->second.team1 << "(" << it->second.Score_Team_One << ")" << " - " << it->second.team2 << "(" << it->second.Score_Team_two << ")" << endl;
			cout << "_________________________________________________________" << endl;
		}

}

//__________________________________________________________________________________________________________

void Team::Update_Total_Score(string s, int x) //Help Function To increase Goals , when  call  in enter match
{
	Load_Teams(); 
	for (auto i = Teams.begin(); i != Teams.end(); i++)
		if (i->second.Name == s)
			i->second.OwnGoals += x;
	Put_Data_in_file();
}

//_____________________________________________________________________________________________________________

void Team::Update_Points(string s, int x, int x1) //Help Function To increase Points, when  call  in enter match
{
	Load_Teams();
	for (auto i = Teams.begin(); i != Teams.end(); i++)
		if (i->second.Name == s)
		{
			if (x > x1)
				i->second.Points += 3;
			else if (x == x1)
				i->second.Points += 1;
			else
				continue;
		}
	Put_Data_in_file();
}

//______________________________________________________________________________________________________________

void Team::Update_GoalKeepar_Score(string s, int x)//Help Function To increase Goalkeepers , when  call  in enter match
{
	Load_Teams();
	string n = s;
	int a = x;
	for (auto i = Teams.begin(); i != Teams.end(); i++)
		if (i->second.Name == n)
			i->second.Goals += a;
	Put_Data_in_file();
}
void Team::Put_Data_in_file() //Save Data In File After Any Operation 
{
	ofstream Teams_File;
	Teams_File.open("Teams.txt", ios::out);
	for (auto it = Teams.begin(); it != Teams.end(); it++)
	{
		Teams_File << it->second.Name << "\t";
		Teams_File << it->second.ID_Team << "\t";
		Teams_File << it->second.OwnGoals << "\t";
		Teams_File << it->second.Goals << "\t";
		Teams_File << it->second.Captain << "\t";
		Teams_File << it->second.Points << endl;
	}
	Teams_File.close();
}
//_________________________________________________________________________________________

void Team::Display_team_detailed_scores() //display all points and details of the team he want
{
	Match m;
	Load_Teams();
	m.Load_Matches();
	string s;
	cout << "Enter The Team Name You Want the details of : " << endl;
	cin >> s;
	for (auto it = Teams.begin(); it != Teams.end(); it++)
	{
		if (it->second.Name == s)
		{
			cout << "The Total Score of The " << s << " Team is : " << it->second.OwnGoals << endl;
			cout << "Divided to : " << endl;
			for (auto i = m.matches.begin(); i != m.matches.end(); i++)
			{
				if (s == i->second.team1 || s == i->second.team2)
				{
					if (s == i->second.team1)
					{
						cout << i->second.Score_Team_One << " Score on The Match with " << i->second.team2 << endl;
						cout << "The final score of match was" << i->second.Score_Team_One << " : " << i->second.Score_Team_two << endl;
						if (i->second.Score_Team_One > i->second.Score_Team_two)
						{
							cout << "The Winner was : " << i->second.team1 << endl;
							cout << "The Loser was : " << i->second.team2 << endl;
						}
						else
						{
							cout << "The Winner was : " << i->second.team2 << endl;
							cout << "The Loser was : " << i->second.team1 << endl;
						}
						cout << "on Date : " << i->second.Date << endl;;
						cout << "on Stadium Match : " << i->second.Stadium_Name << endl;
						cout << "Football Referee was :" << i->second.Footbool_referee << endl;
						cout << "________________________________________________________" << endl;
					}
					else if (s == i->second.team2)
					{
						cout << i->second.Score_Team_two << " Score on The Match with " << i->second.team1 << endl;
						cout << "The final score of match was" << i->second.Score_Team_two << " : " << i->second.Score_Team_One << endl;
						if (i->second.Score_Team_two > i->second.Score_Team_One)
						{
							cout << "The Winner was : " << i->second.team2 << endl;
							cout << "The Loser was : " << i->second.team1 << endl;
						}
						else
						{
							cout << "The Winner was : " << i->second.team1 << endl;
							cout << "The Loser was : " << i->second.team2 << endl;
						}
						cout << "on Date : " << i->second.Date << endl;;
						cout << "on Stadium Match : " << i->second.Stadium_Name << endl;
						cout << "Football Referee was :" << i->second.Footbool_referee << endl;
						cout << "________________________________________________________" << endl;
					}
				}
			}
		}
	}
}
/* General Functions */

bool sortbyPoints(const pair<int, Team> &a, const pair<int, Team> &b) //sort teams by their points
{
	//overloading to sort function 
	return (a.second.Points > b.second.Points);
}// To Compare To Sort Teams by points

//___________________________________________________________________________________________________

bool sortbyOwnGoals(const pair<int, Team> &a, const pair<int, Team> &b)//overloading to sort function //sort teams by their scores
{
	return (a.second.OwnGoals > b.second.OwnGoals);
}// To Compare To Sort Teams by Goals

//___________________________________________________________________________________________________

bool sortGoalkeepers(const pair<int, Team> &a, const pair<int, Team> &b)//overloading to sort function //sort teams by their less goals of the team
{
	return a.second.Goals < b.second.Goals;
}

//_____________________________________________________________________________________________________

void Display_3_Frist_Teams_By_Points()
{
	Team s;
	s.Load_Teams();
	vector < pair <int, Team> > Sor;
	multimap<int, Team>::iterator it2;
	for (it2 = s.Teams.begin(); it2 != s.Teams.end(); it2++)
	{
		Sor.push_back(make_pair(it2->first, it2->second)); // Push Map in Vector To Sort 
	}
	sort(Sor.begin(), Sor.end(), sortbyPoints); // Sort Here 
	for (int j = 0; j < Sor.size(); j++)
	{
		cout << j + 1 << " - "; // To Write The Order Of Team 
		s.Display_team_Order(Sor[j].second.Name);
	}
}// To Display First Three Team in League
 /*Sort Teams By Goals*/

//____________________________________________________________________________________________________
void Display_3_First_Teams_By_Total_Score()
{
	Team s;
	s.Load_Teams();
	vector <pair <int, Team> > Sor;
	multimap<int, Team>::iterator it2;
	for (it2 = s.Teams.begin(); it2 != s.Teams.end(); it2++)
	{
		Sor.push_back(make_pair(it2->first, it2->second)); // Push Map in Vector To Sort 
	}
	sort(Sor.begin(), Sor.end(), sortbyOwnGoals); // Sort Here 
	for (int j = 0; j < Sor.size(); j++)
	{
		cout << j + 1 << " - "; // To Write The Order Of Team 
		s.Display_team_Order(Sor[j].second.Name);
	}
}// To Display First Three Team in League

 //____________________________________________________________________________________________________

void Display_3_First_GoalKeepers()
{
	Team s;
	s.Load_Teams();
	vector <pair <int, Team> > Sor;
	map<int, Team>::iterator it2;
	for (it2 = s.Teams.begin(); it2 != s.Teams.end(); it2++)
	{
		Sor.push_back(make_pair(it2->first, it2->second)); // Push Map in Vector To Sort 
	}
	sort(Sor.begin(), Sor.end(), sortGoalkeepers); // Sort Here 
	Player p;
	for (int j = 0; j < 3; j++)
	{
		cout << j + 1 << " - " << Sor[j].second.Name << endl; // To Write The Order Of Team 
		p.Display_Team_member(Sor[j].second.Name , 1);
	}
}

//____________________________________________________________________________________________________


void Team::DisPlay_Team_Match_With_Date() //display team held matches sorted by date
{
	Load_Teams();
	Match M;
	M.Load_Matches();
	string s, s1;
	vector <Match> Played, notPlayed;
	cout << "Enter Team Name & Date " << endl;
	cin >> s >> s1;
	while (!validDate(s1))
	{
		cout << "InValid Date Enter Valid Date" << endl;
		cin >> s1;
	}
	string ch;
	int y = 0, m = 0, d = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		ch += s1[i];
		if (i == 1)
		{
			d = stoi(ch);
			ch.clear();
			i++;
		}
		if (i == 4)
		{
			m = stoi(ch);
			ch.clear();
			i++;
		}
		if (i == 9)
		{
			y = stoi(ch);
			ch.clear();
			break;
		}
	}
	ch.clear();
	for (auto it1 = M.matches.begin(); it1 != M.matches.end(); it1++)
	{
		if (s == it1->second.team1 || s == it1->second.team2)
		{
			int Y = 0, Mo = 0, D = 0;
			for (int i = 0; i < it1->second.Date.size(); i++)
			{
				ch += it1->second.Date[i];
				if (i == 1)
				{
					D = stoi(ch);
					ch.clear();
					i++;
				}
				if (i == 4)
				{
					Mo = stoi(ch);
					ch.clear();
					i++;
				}
				if (i == 9)
				{
					Y = stoi(ch);
					ch.clear();
					break;
				}
			}
			if (Y < y)
				Played.push_back(it1->second);
			else if (Mo < m)
				Played.push_back(it1->second);
			else if (D < d)
				Played.push_back(it1->second);
			else if (Y == y && Mo == m && D == d)
				Played.push_back(it1->second);
			else
				notPlayed.push_back(it1->second);
		}
	}
	cout << "Held Matches : " << endl;
	for (int i = 0; i < Played.size(); i++)
	{
		cout << Played[i].ID_Match << "\t" << Played[i].team1 << "\t";
		cout << Played[i].Score_Team_One << "\t" << Played[i].team2 << "\t";
		cout << Played[i].Score_Team_two << "\t" << Played[i].Date << endl;
		cout << "_______________________________________" << endl;
	}
	cout << "TO Be Held Matches : " << endl;
	for (int i = 0; i < notPlayed.size(); i++)
	{
		cout << notPlayed[i].ID_Match << "\t" << notPlayed[i].team1 << "\t";
		cout << notPlayed[i].Score_Team_One << "\t" << notPlayed[i].team2 << "\t";
		cout << notPlayed[i].Score_Team_two << "\t" << notPlayed[i].Date << endl;
		cout << "_______________________________________" << endl;
	}

}

Team::~Team()
{
}
