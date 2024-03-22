#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include"mygraphics.h"
#include"myconsole.h"
using namespace std;
int overenter=0;
fstream New("New.txt");
fstream New2("highlights.txt");
string callUmpire()
{
	int i;
	string umpire;
	cout << "Enter Umpire Name:-\n1)- Aleem Dar\n2)- Billy Bowden\n3)- Steve Bucknor\n4)- Simon Taufel\n5)- Tony Hill" << endl;
	cin >> i;
	switch (i)
	{
	case 1:
		umpire = "Aleem Dar";
		break;
	case 2:
		umpire = "Billy Bowden";
		break;
	case 3:
		umpire = "Steve Bucknor";
		break;
	case 4:
		umpire = "Simon Taufel";
		break;
	case 5:
		umpire = "Tony Hill";
		break;
	default:
		cout << "Invalid input!\n1)- Aleem Dar\n2)- Billy Bowden\n3)- Steve Bucknor\n4)- Simon Taufel\n5)- Tony Hill";
		cin >> i;
	}
	return umpire;
}

string callCommentor()
{
	int i;
	string Commentor;
	cout << "Enter Commentor Name:-\n1)- Sunil Gavaskar\n2)- Tony Cozier\n3)- Harsha Bhogle\n4)- Bill Lawry\n5)- Tony Grieg" << endl;
	cin >> i;
	switch (i)
	{
	case 1:
		Commentor = "Sunil Gavaskar";
		break;
	case 2:
		Commentor = "Tony Cozier";
		break;
	case 3:
		Commentor = "Harsha Bhogle";
		break;
	case 4:
		Commentor = "Bill Lawry";
		break;
	case 5:
		Commentor = "Tony Grieg";
		break;
	default:
		cout << "Invalid input!\n1)- Sunil Gavaskar\n2)- Tony Cozier\n3)- Harsha Bhogle\n4)- Bill Lawry\n5)- Tony Grieg";
		cin >> i;
	}
	return Commentor;
}
string Sixer(int count)
{
		if (count == 0)
		{
			return "Massive six";
		}
		if (count  == 1)
		{

			return "Out of the boundary for a six";
		}
		if (count  == 2)
		{

			return "What a six!";
		}
	
};
string Four(int count)
{
	if (count == 0)
	{
		return "Massive four";
	}
	if (count == 1)
	{

		return  "To the fence for a four";
	}
	if (count == 2)
	{

		return "What a four!";
	}
};
string wide()
{
	return  "Wide Ball";
};
string noball()
{
	return "No Ball! Free hit";
};
string out()
{
	return "Out!!";
};
string single()
{
	return " 1 Run";
};
string dbl()
{
	return "2 Runs";
};
string norun() {
	return "Dot ball";
}
void commentry(string score)
{
	if (score == "1")
	{
		cout << single();
	}

	if (score == "0")
	{
		cout<< norun();
	}

	if (score == "2")
	{
		cout<< dbl();
	}
	if (score == "noball")
	{
	cout<< noball();
	}
	if (score == "wide")
	{
		cout<< wide();
	}

	if (score == "4")
	{
		static int count1 = -1;
			if (count1 == 2)
			{
				count1 = -1;
			}
		count1++;
		cout<< Four(count1);
	}
	if (score == "6")
	{
		static int count2 = -1;
		if (count2 == 2)
		{
			count2 = -1;
		}
		count2++;
		cout<< Sixer(count2);
	}


}

class Player
{
public:
	string name;
	int age;
	string role;
	string p_name;
	int runs;
	int wickets;
	double SR;
	double bat_average;
	double ball_average;
	Player()
	{
		this->name = "Player";
		this->age = 0;
		this->role = "Batter";
		this->runs = 0;
		this->wickets = 0;
		this->SR = 0;
		this->bat_average = 0;
		this->ball_average = 0;
	}
	Player(string name, int age, string role, int runs, int wickets, double SR, double bat_average, double ball_average)
	{
		this->name = name;
		this->age = age;
		this->role = role;
		this->runs = runs;
		this->wickets = wickets;
		this->SR = SR;
		this->bat_average = bat_average;
		this->ball_average = ball_average;
	}
	void setName(string name)
	{
		this->name = name;
	}
	string getName()
	{
		return name;
	}
	void setAge(int age)
	{
		this->age = age;
	}
	int getAge()
	{
		return age;
	}
	void setRole(int role)
	{
		this->role = role;
	}
	string getRole()
	{
		return role;
	}
	void setRuns(int runs)
	{
		this->runs = runs;
	}
	int getRuns()
	{
		return runs;
	}
	void setSR(float SR)
	{
		this->SR = SR;
	}
	double getSR()
	{
		return SR;
	}
	void setBatAvg(float avg)
	{
		this->bat_average = avg;
	}
	double getBatAvg()
	{
		return bat_average;
	}
	void setBalAvg(float b_avg)
	{
		this->ball_average = b_avg;
	}
	double getBalAvg()
	{
		return ball_average;
	}
};
class Team : public Player
{
public:
	string teamName;
	vector<Player> playerList;

public:
	Team()
	{

	}
	Team(string name)
	{
		this->teamName = name;
	}
	Team(const Team& obj)
	{
		this->teamName = obj.teamName;
		this->playerList = obj.playerList;
	}
	Team& operator=(const Team& obj)
	{
		if (this != &obj)
		{
			this->teamName = obj.teamName;
			this->playerList = obj.playerList;
		}
		return *this;
	}
	~Team()
	{
	}
	string getTeamName()
	{
		return teamName;
	}
	void addPlayer(Player player)
	{
		playerList.push_back(player);
	}
	string getPlayerName(int index)
	{
		return playerList[index].getName();
	}
	string getPlayerRole(int index)
	{
		return playerList[index].getRole();
	}
	void updateStats(string playerName, int runsScored, string role, int wicketsTaken, double sr, double bat_a, double ball_a)
	{

		for (Player& stats : playerList)
		{
			if (stats.name == playerName)
			{

				stats.runs += runsScored;
				stats.role = role;
				stats.wickets += wicketsTaken;
				stats.SR += sr;
				stats.bat_average += bat_a;
				stats.ball_average += ball_a;
				break;
			}
		}
	}

	void displayPlayerStats()
	{
		for (const Player& stats : playerList)
		{

			std::cout << "Team: " << getTeamName() << " Player: " << stats.name << " Role " << stats.role << ", Runs: " << stats.runs << ", Wickets: " << stats.wickets << " Batting Average: " << stats.bat_average << " Strike Rate: " << stats.SR << " Balling Average: " << stats.ball_average << std::endl;
		}
	}
	void displayTeam()
	{
		cout << "\t\t\t\t\t\t    Team: " << getTeamName() << endl << "****************************************" << endl;
		int count = 0;
		for (const Player& stats : playerList)
		{

			cout << count + 1 << ")- Player: " << stats.name << endl << "Role : " << stats.role << ", Runs : " << stats.runs << ", Wickets : " << stats.wickets << " Batting Average : " << stats.bat_average << " Strike Rate : " << stats.SR << " Balling Average : " << stats.ball_average << endl << "======================================================================================================================" << endl;
			count++;
		}

	}
	void displayAllPlayerNames()
	{
		int count = 0;
		for (const Player& stats : playerList)
		{

			cout << count + 1 << ")- Player: " << stats.name << endl << "Role : " << stats.role << endl << "======================================================================================================================" << endl;
			count++;
		}
	}



	//najam
	void savenewteam()
	{
		New << getTeamName() << endl;
		for (const Player& stats : playerList)
		{
			New << stats.name << endl << stats.role << endl << stats.runs << endl << stats.wickets << endl << stats.bat_average << endl << stats.SR << endl << stats.ball_average << endl;

		}
	}
	void loadnewteam()
	{
		New >> teamName;
		string x;
		for (const Player& stats : playerList)
		{
			New >> name >> role >> runs >> wickets >> bat_average >> SR >> ball_average;

		}
	}
};
int displayAllTeamsNames(vector<Team>& team)
{
	Team teams;
	if (team.empty())
	{
		cout << "No teams added yet." << endl;
		cout << endl;
	}
	else
	{

		cout << "Following are the Team List:" << endl;
		int count = 0, inp = 0;
		for (Team& teams : team)
		{
			cout << count + 1 << ")- " << teams.getTeamName() << endl;
			count++;
		}
		cin >> inp;
		while (inp > team.size() || inp <= 0)
		{
			cout << "Invalid Input!\n Enter again: " << endl;
			cin >> inp;
		}
		return inp;
	}
}
Team addTeam(string t_name)
{
	Team team(t_name);
	int inp;
	cout << "How many players are there in team: ";
	cin >> inp;
	for (int i = 0; i < inp; i++)
	{
		string playerName;
		int age, runs, wickets;
		double SR, bat_avg, ball_avg;
		string role;
		cout << "Enter Name: ";
		cin >> playerName;
		cout << "Enter Age: ";
		cin >> age;
		cout << "Enter Runs: ";
		cin >> runs;
		cout << "Enter Wickets: ";
		cin >> wickets;
		cout << "Enter Strike Rate: ";
		cin >> SR;
		cout << "Enter Batting Average: ";
		cin >> bat_avg;
		cout << "Enter Balling Average: ";
		cin >> ball_avg;
		Player player(playerName, age, role, runs, wickets, SR, bat_avg, ball_avg);
		team.addPlayer(player);
		team.updateStats(playerName, runs, role, wickets, SR, bat_avg, ball_avg);
	}
	return team;
}

class Match : public Team
{
protected:
	int balls, score1, score2, series, matchtype, Toss, target=1000;
	int x = 0;
	Team teamA, teamB;
	string scorecal;
	string umpire;
	string Commentor;
	vector<Player> PlayersA, PlayersB;
	bool superover = false;
public:
	Match()
	{
		this->balls = 0;
		this->score1 = 0;
		this->score2 = 0;
		this->series = 0;
		this->matchtype = 0;

	}
	void swap(int& x, int& y)
	{
		int temp = x;
		x = y;
		y = temp;
	}
	Match(int series, int matchtype, Team team1, Team team2)
	{
		this->matchtype = matchtype;
		if (matchtype == 1)
		{
			this->balls = 1 * 6;
			//t20 ki balls set kar lein  
		}
		if (matchtype == 2)
		{
			this->balls = 50 * 6;
		}
		if (matchtype == 3)
		{
			this->balls = 90 * 6;
		}
		this->score1 = 0;
		this->score2 = 0;
		this->series = series;
		this->teamA = team1;
		this->teamB = team2;
	}
	void setUmpire()
	{
		this->umpire = callUmpire();
	}
	string getUmpire()
	{
		return umpire;
	}

	void setCommentor()
	{
		this->Commentor = callCommentor();
	}
	string getCommentor()
	{
		return Commentor;
	}

	void input(int series, int matchtype, Team team1, Team team2)
	{
		this->matchtype = matchtype;
		if (matchtype == 1)
		{
			this->balls = 20* 6;
			//t20 ki balls set kar lein  
		}
		if (matchtype == 2)
		{
			this->balls = 50 * 6;
		}
		if (matchtype == 3)
		{
			this->balls = 90 * 6;
		}
		if (matchtype == 4)
		{
			this->balls = overenter * 6;
		}
	
		this->score1 = 0;
		this->score2 = 0;
		this->series = series;
		this->teamA = team1;
		this->teamB = team2;
	}
	void Game()
	{
		for (int i = 0; i < series; i++)
		{
			if (superover == false)
			{
				system("cls");
				setUmpire();
				system("cls");

				setCommentor();
				
				
				system("cls");
				Toss = TossR();
			}
			for (int j = 0; j < 2; j++)
			{
				if (Toss == 0)
				{
					cout << teamA.getTeamName() << " choose to Bat.\n";
					if (j == 0)
					{
						score1 = ScoreCalculator(score1, teamA, teamB);
					}
					else if (j == 1)
					{
						score2 = ScoreCalculator(score2, teamB, teamA);
					}
				}
				else
				{
					cout << teamB.getTeamName() << " choose to Bat.\n";

					if (j == 0)
					{
						score2 = ScoreCalculator(score2, teamB, teamA);
					}
					else if (j == 1)
					{
						score1 = ScoreCalculator(score1, teamA, teamB);
					}
				}

			}
		}
		system("cls");
		Winner();
	}


	//shahzad 
	int ScoreCalculator(int score, Team& team, Team& team2)
	{
		cout << "\n\n";
		cout << "----TEAM " << team.getTeamName() << " ----" << endl;
		team.displayAllPlayerNames();
		_getch();
		system("cls");
		int TotalScore = 0;
		int PlayerCheck = 0;
		int ball = 1;
		int bowler = 10;
		int overs = 0;
		bool noball = false;
		int p1, p2;
		p1 = PlayerCheck;
		p2 = p1 + 1;
		for (int i = 0; i < balls; i++)
		{
			//To check 'out' PLayerCheck is made
			if (PlayerCheck == 10)
			{
				cout << "All out!" << endl;
				return score;
			}
			system("cls");
			if (score >= target)
			{
				return score;
			}
			else
			{
			//target displaying 
			if (x > 0)
			{
				cout << "Batsman: "
					<< team.getPlayerName(p1)
					<< "\tRunner: "
					<< team.getPlayerName(p2) << "\tBowler: "
					<< team2.getPlayerName(bowler) << "\tOvers: "
					<< overs << "." << ball - 1 << "\tUmpire: "
					<< getUmpire() << endl
					<< "========================================================================================================================"
					<< endl << "Commentator: "
					<< "\t\t\t"; commentry(scorecal); cout << "\t\tCourtesy by SKYSPORTS"<<endl << "\t\t\t\t\t|\t\t\t|" << endl << "\t\t\t\t\t|     "
					<< team.getTeamName() << ": " << score << "-" << PlayerCheck << "\t|" << "Target: " << target <<endl
					<< "\t\t\t\t\t|\t\t\t|" << endl;
			}
			else
			{
				cout << "Batsman: "
					<< team.getPlayerName(p1)
					<< "\tRunner: "
					<< team.getPlayerName(p2) << "\tBowler: "
					<< team2.getPlayerName(bowler) << "\tOvers: "
					<< overs << "." << ball - 1 << "\tUmpire: "
					<< getUmpire() << endl
					<< "========================================================================================================================"
					<< endl << "Commentator: " << getCommentor()
					<< "\t\t\t"; commentry(scorecal); cout << "\t\tCourtesy by SKYSPORTS" << endl << "\t\t\t\t\t|\t\t\t|" << endl << "\t\t\t\t\t|     "
					<< team.getTeamName() << ": " << score << "-" << PlayerCheck << "\t|" << endl
					<< "\t\t\t\t\t|\t\t\t|" << endl;
			}
			cout << "\nBall " << ball << " score : ";
			cin >> scorecal;
			
			

				if (scorecal == "0")
				{
					score += 0;
					ball++;
				}
				else if (scorecal == "1")
				{
					swap(p1, p2);
					score += 1;
					ball++;
				}
				else if (scorecal == "2")
				{
					score += 2;
					ball++;
				}
				else if (scorecal == "3")
				{
					swap(p1, p2);
					score += 3;
					ball++;
				}
				else if (scorecal == "4")
				{
					score += 4;
					ball++;
				}
				else if (scorecal == "6")
				{
					score += 6;
					ball++;
				}
				else if (scorecal == "out")
				{
					if (noball == true)
					{
						cout << "Last ball was No-Ball so this can't be out. " << endl;
						i--;
						noball = false;
						continue;
					}
					PlayerCheck++;
					ball++;
					p1 = PlayerCheck;
					p2 = p1 + 1;
					if (p1 == p2)
					{
						p1++;
					}
				}
				else if (scorecal == "noball")
				{
					noball = true;
					int x;
					cout << "Enter score at noball(if any) :";
					cin >> x;
					if (x <= 6 && x != 5)
					{
						if (x % 2 != 0)
							swap(p1, p2);
						score = score + x;
					}
					score += 1;
					i--;
				}
				else if (scorecal == "wide")
				{
					int x;
					cout << "Enter score after wide(if any) :";
					cin >> x;
					if (x <= 4)
					{
						if (x % 2 != 0)
							swap(p1, p2);
						score = score + x;
					}
					score += 1;
					i--;
				}
				else
				{
					cout << "Enter correct score : \n";
					i--;
				}

				if (ball % 7 == 0)
				{
					ball = 1;
					overs++;
					bowler--;
					swap(p1, p2);
					//ending players are bowlers for them
					if (bowler < 5)
					{
						bowler = 10;
					}
				}
				//file handling
				New2 << team.getPlayerName(p1) << "  " << team2.getPlayerName(bowler) << "  " << scorecal << "  " << ball << "  " << ball << endl;
			}
		}
		cout << "\t\t\t\t\t";
		New2 << endl << score << endl;
		cout << team.getTeamName() << "'s Total Score is " << score << endl;
		_getch();
		target = score + 1;
		x++;
		system("cls");
		return score;
	}
	void Winner()
	{
		int winscore = 0;
		if (score1 > score2)
		{
			winscore = score1 - score2;
			cout << endl << endl << endl;
			cout << endl << endl << endl;
			cout << endl << endl << endl;
			cout << "-------------------------------------------------------------------"<<endl;
			cout << "\t\t"<<teamA.getTeamName() << " has WON by " << winscore << " runs\n";
			cout << "-------------------------------------------------------------------" << endl;

		}
		if (score1 < score2)
		{
			winscore = score2 - score1;
			cout << teamB.getTeamName() << " has WON by " << winscore << " runs\n";
		}
		if (score1 == score2)
		{
			cout << "Match has drawn \n\n";
			system("cls");
			cout << "Lets go for super over : \n";
			this->balls = 6;
			score1 = score2 = 0;
			superover = true;
			Game();
		}
		_getch();
	}
	int TossR()
	{
		int toss;
		cout << "Enter which team has won the toss(for Team1 Enter 0 & for Team2 Enter 1): ";
		cin >> toss;
		return toss;
	}
};
int MatchType()
{
	int choice = 0;
	COLORREF RED = RGB(255, 0, 0);
	COLORREF YELLOW = RGB(255, 255, 102);
	COLORREF BLUE = RGB(0, 0, 255);
	myDrawTextWithFont(340, 60, 40, (char*)"Choose match format:", BLUE, YELLOW);
	myDrawTextWithFont(340, 140, 40, (char*)"Press 1: T-20", BLUE, YELLOW);
	myDrawTextWithFont(340, 180, 40, (char*)"Press 2: One-Day", BLUE, YELLOW);
	myDrawTextWithFont(340, 220, 40, (char*)"Press 3: Test", BLUE, YELLOW);
	myDrawTextWithFont(340, 260, 40, (char*)"Press 4: Custom overs", BLUE, YELLOW);


	/*cout << "Choose match format:\n";
	cout << "Press 1: T-20\n";
	cout << "Press 2: One-Day\n";
	cout << "Press 3: Test\n";*/
	cin >> choice;
	return choice;
}
int main()
{
	COLORREF RED = RGB(255, 0, 0);
	COLORREF YELLOW = RGB(255, 255, 102);
	COLORREF BLUE = RGB(0, 0, 255);
	myDrawTextWithFont(500, 10, 40, (char*)"<< WELCOME EVERYONE >>", BLUE, YELLOW);
	cout << endl << endl;


	//cout << "Welcome to the Game: \n\n";
	vector<Team> teams;
	string teamNames[] = { "Pakistan", "India", "Australia", "England", "South Africa", "New Zealand", "West Indies", "Sri Lanka", "Bangladesh", "Afghanistan", "Zimbabwe", "Ireland" };

	for (int i = 0; i < 11; i++)
	{
		Team team(teamNames[i]);

		for (int j = 0; j < 11; j++)
		{
			string playerName;
			int age, runs, wickets;
			double SR, bat_avg, ball_avg;
			string role;
			switch (i)
			{
				// Team Pakistan
			case 0:
				switch (j)
				{
				case 0:
					playerName = "Babar Azam";
					age = 26;
					role = "Batsman";
					runs = 3485;
					wickets = 2;
					SR = 128.4;
					bat_avg = 41.5;
					ball_avg = 21.0;
					break;
				case 1:
					playerName = "Mohammad Rizwan";
					age = 23;
					role = "Batter/Keeper";
					runs = 569;
					wickets = 104;
					SR = 137.8;
					bat_avg = 19.0;
					ball_avg = 22.1;
					break;
				case 3:
					playerName = "Faheem Ashraf";
					age = 27;
					role = "Batsman";
					runs = 311;
					wickets = 36;
					SR = 129.0;
					bat_avg = 12.4;
					ball_avg = 27.2;
					break;
				case 2:
					playerName = "Fakhar Zaman";
					age = 31;
					role = "Batsman";
					runs = 1433;
					wickets = 0;
					SR = 128.2;
					bat_avg = 21.7;
					ball_avg = 0;
					break;
				case 4:
					playerName = "Imad Wasim";
					age = 27;
					role = "All Rounder";
					runs = 67;
					wickets = 83;
					SR = 139.6;
					bat_avg = 6.7;
					ball_avg = 21.7;
					break;
				case 5:
					playerName = "Shan Masood";
					age = 33;
					role = "Batsman";
					runs = 1903;
					wickets = 2;
					SR = 76.9;
					bat_avg = 33.6;
					ball_avg = 40.0;
					break;
				case 6:
					playerName = "Iftikhar Ahmed";
					age = 32;
					role = "Batter";
					runs = 985;
					wickets = 44;
					SR = 114.4;
					bat_avg = 39.4;
					ball_avg = 34.9;
					break;
				case 7:
					playerName = "Hasan Ali";
					age = 27;
					role = "Bowler";
					runs = 265;
					wickets = 148;
					SR = 119.6;
					bat_avg = 13.8;
					ball_avg = 23.1;
					break;
				case 8:
					playerName = "Shaheen Shah Afridi";
					age = 23;
					role = "Bowler";
					runs = 814;
					wickets = 4;
					SR = 132.6;
					bat_avg = 28.1;
					ball_avg = 65.0;
					break;
				case 9:
					playerName = "Ihsanullah";
					age = 32;
					role = "Bowler";
					runs = 0;
					wickets = 4;
					SR = 0;
					bat_avg = 0;
					ball_avg = 18.0;
					break;
				case 10:
					playerName = "Haris Rauf";
					age = 30;
					role = "Bowler";
					runs = 2797;
					wickets = 0;
					SR = 127.3;
					bat_avg = 49.1;
					ball_avg = 0;
					break;
				case 11:
					playerName = "Naseem Shah";
					age = 23;
					role = "Bowler";
					runs = 48;
					wickets = 64;
					SR = 120.0;
					bat_avg = 8.00;
					ball_avg = 22.73;
					break;
				}
				break;
				// Team India
			case 1:
				switch (j)
				{
				case 0:
					playerName = "Virat Kohli";
					age = 33;
					role = "Batsman";
					runs = 12169;
					wickets = 4;
					SR = 93.2;
					bat_avg = 59.1;
					ball_avg = 0;
					break;
				case 7:
					playerName = "Jasprit Bumrah";
					age = 28;
					role = "Bowler";
					runs = 34;
					wickets = 104;
					SR = 29.6;
					bat_avg = 8.5;
					ball_avg = 22.3;
					break;
				case 1:
					playerName = "Rohit Sharma";
					age = 34;
					role = "Batsman";
					runs = 9205;
					wickets = 8;
					SR = 88.9;
					bat_avg = 49.3;
					ball_avg = 30.5;
					break;
				case 5:
					playerName = "Ravindra Jadeja";
					age = 33;
					role = "All Rounder";
					runs = 1954;
					wickets = 220;
					SR = 87.8;
					bat_avg = 32.5;
					ball_avg = 24.4;
					break;
				case 2:
					playerName = "KL Rahul";
					age = 29;
					role = "Batsman";
					runs = 2006;
					wickets = 0;
					SR = 88.1;
					bat_avg = 44.6;
					ball_avg = 0;
					break;
				case 8:
					playerName = "Yuzvendra Chahal";
					age = 31;
					role = "Bowler";
					runs = 62;
					wickets = 92;
					SR = 105.4;
					bat_avg = 10.3;
					ball_avg = 26.4;
					break;
				case 3:
					playerName = "Shikhar Dhawan";
					age = 35;
					role = "Batsman";
					runs = 5977;
					wickets = 4;
					SR = 93.6;
					bat_avg = 44.6;
					ball_avg = 54.0;
					break;
				case 6:
					playerName = "Hardik Pandya";
					age = 28;
					role = "All Rounder";
					runs = 1267;
					wickets = 55;
					SR = 116.8;
					bat_avg = 36.2;
					ball_avg = 35.3;
					break;
				case 9:
					playerName = "Bhuvneshwar Kumar";
					age = 31;
					role = "Bowler";
					runs = 553;
					wickets = 138;
					SR = 87.5;
					bat_avg = 15.4;
					ball_avg = 29.1;
					break;
				case 4:
					playerName = "Rishabh Pant";
					age = 23;
					role = "Batsman";
					runs = 2071;
					wickets = 0;
					SR = 88.9;
					bat_avg = 43.2;
					ball_avg = 0;
					break;
				case 10:
					playerName = "Mohammed Shami";
					age = 30;
					role = "Bowler";
					runs = 147;
					wickets = 144;
					SR = 98.6;
					bat_avg = 10.2;
					ball_avg = 25.2;
					break;
				}
				break;
			case 2:
				switch (j)
				{
				case 0:
					playerName = "Aaron Finch";
					age = 35;
					role = "Batsman";
					runs = 5278;
					wickets = 2;
					SR = 87.1;
					bat_avg = 42.2;
					ball_avg = 64.0;
					break;
				case 1:
					playerName = "David Warner";
					age = 35;
					role = "Batsman";
					runs = 5451;
					wickets = 0;
					SR = 95.4;
					bat_avg = 45.4;
					ball_avg = 0;
					break;
				case 2:
					playerName = "Steven Smith";
					age = 32;
					role = "Batsman";
					runs = 4162;
					wickets = 0;
					SR = 86.3;
					bat_avg = 42.3;
					ball_avg = 0;
					break;
				case 3:
					playerName = "Mitchell Starc";
					age = 32;
					role = "Bowler";
					runs = 768;
					wickets = 184;
					SR = 98.2;
					bat_avg = 13.6;
					ball_avg = 20.8;
					break;
				case 4:
					playerName = "Pat Cummins";
					age = 28;
					role = "Bowler";
					runs = 479;
					wickets = 166;
					SR = 80.9;
					bat_avg = 13.1;
					ball_avg = 24.9;
					break;
				case 5:
					playerName = "Glenn Maxwell";
					age = 33;
					role = "All Rounder";
					runs = 3230;
					wickets = 51;
					SR = 123.6;
					bat_avg = 34.4;
					ball_avg = 41.3;
					break;
				case 6:
					playerName = "Adam Zampa";
					age = 29;
					role = "Bowler";
					runs = 105;
					wickets = 87;
					SR = 92.0;
					bat_avg = 10.5;
					ball_avg = 33.9;
					break;
				case 7:
					playerName = "Marcus Stoinis";
					age = 32;
					role = "All Rounder";
					runs = 1351;
					wickets = 43;
					SR = 95.4;
					bat_avg = 34.5;
					ball_avg = 36.6;
					break;
				case 8:
					playerName = "Alex Carey";
					age = 30;
					role = "Batsman";
					runs = 1175;
					wickets = 0;
					SR = 85.3;
					bat_avg = 35.6;
					ball_avg = 0;
					break;
				case 9:
					playerName = "Matthew Wade";
					age = 33;
					role = "Batsman";
					runs = 1247;
					wickets = 0;
					SR = 80.1;
					bat_avg = 28.3;
					ball_avg = 0;
					break;
				case 10:
					playerName = "Josh Hazlewood";
					age = 30;
					role = "Bowler";
					runs = 75;
					wickets = 108;
					SR = 98.6;
					bat_avg = 12.5;
					ball_avg = 25.6;
					break;
				}
				break;
				// Team England
			case 3:
				switch (j)
				{
				case 0:
					playerName = "Joe Root";
					age = 30;
					role = "Batsman";
					runs = 8249;
					wickets = 28;
					SR = 86.2;
					bat_avg = 49.6;
					ball_avg = 44.8;
					break;
				case 1:
					playerName = "Eoin Morgan";
					age = 34;
					role = "Batsman";
					runs = 7374;
					wickets = 1;
					SR = 90.3;
					bat_avg = 40.9;
					ball_avg = 70.0;
					break;
					// Add the remaining players' stats for Team England
				case 2:
					playerName = "Ben Stokes";
					age = 30;
					role = "All Rounder";
					runs = 4223;
					wickets = 78;
					SR = 95.2;
					bat_avg = 37.8;
					ball_avg = 39.9;
					break;
				case 3:
					playerName = "Jofra Archer";
					age = 26;
					role = "Bowler";
					runs = 241;
					wickets = 63;
					SR = 95.6;
					bat_avg = 10.0;
					ball_avg = 23.3;
					break;
				case 4:
					playerName = "Jos Buttler";
					age = 30;
					role = "Batsman";
					runs = 3843;
					wickets = 2;
					SR = 120.3;
					bat_avg = 40.5;
					ball_avg = 54.5;
					break;
				case 5:
					playerName = "Jason Roy";
					age = 30;
					role = "Batsman";
					runs = 3420;
					wickets = 3;
					SR = 107.2;
					bat_avg = 41.2;
					ball_avg = 43.3;
					break;
				case 6:
					playerName = "Chris Woakes";
					age = 32;
					role = "All Rounder";
					runs = 1578;
					wickets = 162;
					SR = 87.4;
					bat_avg = 24.6;
					ball_avg = 30.2;
					break;
				case 7:
					playerName = "Mark Wood";
					age = 31;
					role = "Bowler";
					runs = 170;
					wickets = 63;
					SR = 102.8;
					bat_avg = 10.0;
					ball_avg = 24.9;
					break;
				case 8:
					playerName = "Adil Rashid";
					age = 33;
					role = "Bowler";
					runs = 304;
					wickets = 150;
					SR = 99.1;
					bat_avg = 11.6;
					ball_avg = 30.1;
					break;
				case 9:
					playerName = "Tom Curran";
					age = 26;
					role = "All Rounder";
					runs = 380;
					wickets = 30;
					SR = 93.5;
					bat_avg = 25.3;
					ball_avg = 33.6;
					break;
				case 10:
					playerName = "Jonny Bairstow";
					age = 31;
					role = "Batsman";
					runs = 3204;
					wickets = 1;
					SR = 105.2;
					bat_avg = 47.1;
					ball_avg = 25.0;
					break;
				}
				break;

				// Team South Africa
			case 4:
				switch (j)
				{
				case 0:
					playerName = "Quinton de Kock";
					age = 28;
					role = "Batsman";
					runs = 5135;
					wickets = 1;
					SR = 94.0;
					bat_avg = 45.9;
					ball_avg = 99.0;
					break;
				case 1:
					playerName = "Kagiso Rabada";
					age = 26;
					role = "Bowler";
					runs = 283;
					wickets = 117;
					SR = 92.3;
					bat_avg = 8.7;
					ball_avg = 24.3;
					break;
					// Add the remaining players' stats for Team South Africa
				case 2:
					playerName = "Faf du Plessis";
					age = 37;
					role = "Batsman";
					runs = 5507;
					wickets = 34;
					SR = 87.0;
					bat_avg = 47.5;
					ball_avg = 54.2;
					break;
				case 3:
					playerName = "Rassie van der Dussen";
					age = 32;
					role = "Batsman";
					runs = 1359;
					wickets = 1;
					SR = 89.5;
					bat_avg = 51.9;
					ball_avg = 111.0;
					break;
				case 4:
					playerName = "Anrich Nortje";
					age = 27;
					role = "Bowler";
					runs = 37;
					wickets = 64;
					SR = 90.7;
					bat_avg = 4.1;
					ball_avg = 22.1;
					break;
				case 5:
					playerName = "David Miller";
					age = 32;
					role = "Batsman";
					runs = 3044;
					wickets = 14;
					SR = 100.2;
					bat_avg = 40.5;
					ball_avg = 56.2;
					break;
				case 6:
					playerName = "Lungi Ngidi";
					age = 25;
					role = "Bowler";
					runs = 52;
					wickets = 61;
					SR = 99.4;
					bat_avg = 5.8;
					ball_avg = 22.5;
					break;
				case 7:
					playerName = "Temba Bavuma";
					age = 31;
					role = "Batsman";
					runs = 2298;
					wickets = 1;
					SR = 83.2;
					bat_avg = 45.9;
					ball_avg = 129.0;
					break;
				case 8:
					playerName = "Tabraiz Shamsi";
					age = 31;
					role = "Bowler";
					runs = 55;
					wickets = 51;
					SR = 102.5;
					bat_avg = 9.6;
					ball_avg = 31.4;
					break;
				case 9:
					playerName = "Aiden Markram";
					age = 26;
					role = "Batsman";
					runs = 1693;
					wickets = 19;
					SR = 86.2;
					bat_avg = 27.5;
					ball_avg = 38.2;
					break;
				case 10:
					playerName = "Heinrich Klaasen";
					age = 29;
					role = "Batsman";
					runs = 1090;
					wickets = 0;
					SR = 109.4;
					bat_avg = 50.0;
					ball_avg = 0;
					break;
				}
				break;
				// Team New Zealand
			case 5:
				switch (j)
				{
				case 0:
					playerName = "Kane Williamson";
					age = 31;
					role = "Batsman";
					runs = 7115;
					wickets = 29;
					SR = 83.0;
					bat_avg = 54.3;
					ball_avg = 57.9;
					break;
				case 1:
					playerName = "Trent Boult";
					age = 32;
					role = "Bowler";
					runs = 574;
					wickets = 281;
					SR = 87.2;
					bat_avg = 14.9;
					ball_avg = 27.6;
					break;
					// Add the remaining players' stats for Team New Zealand
				case 2:
					playerName = "Ross Taylor";
					age = 37;
					role = "Batsman";
					runs = 8570;
					wickets = 2;
					SR = 83.4;
					bat_avg = 48.2;
					ball_avg = 129.0;
					break;
				case 3:
					playerName = "Martin Guptill";
					age = 34;
					role = "Batsman";
					runs = 6888;
					wickets = 2;
					SR = 88.1;
					bat_avg = 43.0;
					ball_avg = 32.0;
					break;
				case 4:
					playerName = "Lockie Ferguson";
					age = 30;
					role = "Bowler";
					runs = 47;
					wickets = 57;
					SR = 95.3;
					bat_avg = 7.8;
					ball_avg = 25.8;
					break;
				case 5:
					playerName = "Tom Latham";
					age = 29;
					role = "Batsman";
					runs = 2952;
					wickets = 0;
					SR = 82.0;
					bat_avg = 33.0;
					ball_avg = 0;
					break;
				case 6:
					playerName = "Mitchell Santner";
					age = 29;
					role = "All Rounder";
					runs = 1249;
					wickets = 69;
					SR = 81.0;
					bat_avg = 24.0;
					ball_avg = 34.0;
					break;
				case 7:
					playerName = "Tim Southee";
					age = 32;
					role = "Bowler";
					runs = 1803;
					wickets = 302;
					SR = 81.4;
					bat_avg = 14.0;
					ball_avg = 29.6;
					break;
				case 8:
					playerName = "Colin de Grandhomme";
					age = 35;
					role = "All Rounder";
					runs = 1346;
					wickets = 54;
					SR = 96.0;
					bat_avg = 29.0;
					ball_avg = 32.0;
					break;
				case 9:
					playerName = "Kyle Jamieson";
					age = 27;
					role = "Bowler";
					runs = 226;
					wickets = 46;
					SR = 74.0;
					bat_avg = 16.1;
					ball_avg = 14.9;
					break;
				case 10:
					playerName = "Henry Nicholls";
					age = 30;
					role = "Batsman";
					runs = 1913;
					wickets = 1;
					SR = 84.0;
					bat_avg = 38.0;
					ball_avg = 7.0;
					break;
				case 11:
					playerName = "Ish Sodhi";
					age = 29;
					role = "Bowler";
					runs = 83;
					wickets = 102;
					SR = 80.0;
					bat_avg = 10.0;
					ball_avg = 27.3;
					break;
				}
				break;
				// Team West Indies
			case 6:
				switch (j)
				{
				case 0:
					playerName = "Kieron Pollard";
					age = 34;
					role = "All Rounder";
					runs = 3022;
					wickets = 56;
					SR = 128.8;
					bat_avg = 25.2;
					ball_avg = 35.7;
					break;
				case 1:
					playerName = "Nicholas Pooran";
					age = 26;
					role = "Batsman";
					runs = 1359;
					wickets = 0;
					SR = 123.6;
					bat_avg = 29.3;
					ball_avg = 0;
					break;
					// Add the remaining players' stats for Team West Indies
				case 2:
					playerName = "Chris Gayle";
					age = 42;
					role = "Batsman";
					runs = 10408;
					wickets = 167;
					SR = 87.2;
					bat_avg = 40.6;
					ball_avg = 35.6;
					break;
				case 3:
					playerName = "Shimron Hetmyer";
					age = 24;
					role = "Batsman";
					runs = 1767;
					wickets = 2;
					SR = 107.5;
					bat_avg = 38.2;
					ball_avg = 28.0;
					break;
				case 4:
					playerName = "Jason Holder";
					age = 29;
					role = "All Rounder";
					runs = 1982;
					wickets = 152;
					SR = 95.2;
					bat_avg = 32.9;
					ball_avg = 26.9;
					break;
				case 5:
					playerName = "Evin Lewis";
					age = 29;
					role = "Batsman";
					runs = 1501;
					wickets = 2;
					SR = 98.0;
					bat_avg = 32.0;
					ball_avg = 40.0;
					break;
				case 6:
					playerName = "Shai Hope";
					age = 27;
					role = "Batsman";
					runs = 3715;
					wickets = 1;
					SR = 74.0;
					bat_avg = 52.0;
					ball_avg = 18.0;
					break;
				case 7:
					playerName = "Alzarri Joseph";
					age = 24;
					role = "Bowler";
					runs = 119;
					wickets = 48;
					SR = 93.5;
					bat_avg = 7.4;
					ball_avg = 27.9;
					break;
				case 8:
					playerName = "Fabian Allen";
					age = 25;
					role = "All Rounder";
					runs = 336;
					wickets = 11;
					SR = 123.1;
					bat_avg = 21.0;
					ball_avg = 36.2;
					break;
				case 9:
					playerName = "Hayden Walsh Jr.";
					age = 29;
					role = "Bowler";
					runs = 47;
					wickets = 36;
					SR = 66.3;
					bat_avg = 5.7;
					ball_avg = 17.4;
					break;
				case 10:
					playerName = "Andre Russell";
					age = 33;
					role = "All Rounder";
					runs = 1595;
					wickets = 65;
					SR = 135.2;
					bat_avg = 28.9;
					ball_avg = 29.5;
					break;
				case 11:
					playerName = "Oshane Thomas";
					age = 24;
					role = "Bowler";
					runs = 20;
					wickets = 35;
					SR = 109.6;
					bat_avg = 3.3;
					ball_avg = 24.4;
					break;
				}
				break;
				// Team Sri Lanka
			case 7:
				switch (j)
				{
				case 0:
					playerName = "Kusal Perera";
					age = 31;
					role = "Batsman";
					runs = 3228;
					wickets = 0;
					SR = 92.2;
					bat_avg = 30.7;
					ball_avg = 0;
					break;
				case 1:
					playerName = "Angelo Mathews";
					age = 34;
					role = "All Rounder";
					runs = 5361;
					wickets = 139;
					SR = 83.0;
					bat_avg = 41.7;
					ball_avg = 35.8;
					break;
					// Add the remaining players' stats for Team Sri Lanka
				case 2:
					playerName = "Dasun Shanaka";
					age = 30;
					role = "All Rounder";
					runs = 768;
					wickets = 7;
					SR = 114.0;
					bat_avg = 26.4;
					ball_avg = 53.0;
					break;
				case 3:
					playerName = "Dhananjaya de Silva";
					age = 30;
					role = "All Rounder";
					runs = 1672;
					wickets = 24;
					SR = 81.7;
					bat_avg = 28.4;
					ball_avg = 30.7;
					break;
				case 4:
					playerName = "Wanindu Hasaranga";
					age = 24;
					role = "All Rounder";
					runs = 628;
					wickets = 17;
					SR = 105.9;
					bat_avg = 30.0;
					ball_avg = 26.3;
					break;
				case 5:
					playerName = "Dushmantha Chameera";
					age = 29;
					role = "Bowler";
					runs = 40;
					wickets = 62;
					SR = 93.6;
					bat_avg = 6.7;
					ball_avg = 28.3;
					break;
				case 6:
					playerName = "Isuru Udana";
					age = 33;
					role = "All Rounder";
					runs = 237;
					wickets = 51;
					SR = 105.0;
					bat_avg = 16.9;
					ball_avg = 33.7;
					break;
				case 7:
					playerName = "Avishka Fernando";
					age = 23;
					role = "Batsman";
					runs = 732;
					wickets = 0;
					SR = 90.4;
					bat_avg = 32.6;
					ball_avg = 0;
					break;
				case 8:
					playerName = "Bhanuka Rajapaksa";
					age = 30;
					role = "Batsman";
					runs = 161;
					wickets = 0;
					SR = 96.4;
					bat_avg = 23.0;
					ball_avg = 0;
					break;
				case 9:
					playerName = "Kamindu Mendis";
					age = 22;
					role = "All Rounder";
					runs = 103;
					wickets = 2;
					SR = 81.9;
					bat_avg = 25.7;
					ball_avg = 29.5;
					break;
				case 10:
					playerName = "Akila Dananjaya";
					age = 28;
					role = "Bowler";
					runs = 98;
					wickets = 60;
					SR = 78.4;
					bat_avg = 7.5;
					ball_avg = 30.2;
					break;
				case 11:
					playerName = "Lahiru Kumara";
					age = 24;
					role = "Bowler";
					runs = 33;
					wickets = 45;
					SR = 91.6;
					bat_avg = 6.0;
					ball_avg = 35.3;
					break;
				}
				break;
				// Team Bangladesh
			case 8:
				switch (j)
				{
				case 0:
					playerName = "Tamim Iqbal";
					age = 33;
					role = "Batsman";
					runs = 7714;
					wickets = 2;
					SR = 78.3;
					bat_avg = 36.4;
					ball_avg = 35.0;
					break;
				case 1:
					playerName = "Mushfiqur Rahim";
					age = 34;
					role = "Batsman";
					runs = 6906;
					wickets = 4;
					SR = 79.2;
					bat_avg = 36.8;
					ball_avg = 65.0;
					break;
					// Add the remaining players' stats for Team Bangladesh
				case 2:
					playerName = "Shakib Al Hasan";
					age = 34;
					role = "All Rounder";
					runs = 6323;
					wickets = 260;
					SR = 83.2;
					bat_avg = 36.4;
					ball_avg = 28.1;
					break;
				case 3:
					playerName = "Mahmudullah";
					age = 35;
					role = "All Rounder";
					runs = 2851;
					wickets = 57;
					SR = 83.0;
					bat_avg = 28.9;
					ball_avg = 42.1;
					break;
				case 4:
					playerName = "Mustafizur Rahman";
					age = 25;
					role = "Bowler";
					runs = 186;
					wickets = 118;
					SR = 90.0;
					bat_avg = 7.9;
					ball_avg = 22.3;
					break;
				case 5:
					playerName = "Mehidy Hasan";
					age = 24;
					role = "Bowler";
					runs = 423;
					wickets = 76;
					SR = 70.8;
					bat_avg = 11.1;
					ball_avg = 32.4;
					break;
				case 6:
					playerName = "Mohammad Saifuddin";
					age = 24;
					role = "All Rounder";
					runs = 353;
					wickets = 40;
					SR = 86.3;
					bat_avg = 26.4;
					ball_avg = 37.3;
					break;
				case 7:
					playerName = "Liton Das";
					age = 27;
					role = "Batsman";
					runs = 1701;
					wickets = 0;
					SR = 88.4;
					bat_avg = 32.3;
					ball_avg = 0;
					break;
				case 8:
					playerName = "Taskin Ahmed";
					age = 26;
					role = "Bowler";
					runs = 84;
					wickets = 44;
					SR = 80.9;
					bat_avg = 7.2;
					ball_avg = 37.6;
					break;
				case 9:
					playerName = "Nasum Ahmed";
					age = 26;
					role = "Bowler";
					runs = 26;
					wickets = 20;
					SR = 84.7;
					bat_avg = 4.3;
					ball_avg = 16.6;
					break;
				case 10:
					playerName = "Afif Hossain";
					age = 23;
					role = "All Rounder";
					runs = 237;
					wickets = 8;
					SR = 110.3;
					bat_avg = 23.7;
					ball_avg = 33.5;
					break;
				case 11:
					playerName = "Shoriful Islam";
					age = 20;
					role = "Bowler";
					runs = 8;
					wickets = 14;
					SR = 50.4;
					bat_avg = 2.0;
					ball_avg = 19.4;
					break;
				}
				break;
				// Team Afghanistan
			case 9:
				switch (j)
				{
				case 0:
					playerName = "Rashid Khan";
					age = 23;
					role = "All Rounder";
					runs = 708;
					wickets = 139;
					SR = 99.0;
					bat_avg = 18.6;
					ball_avg = 14.4;
					break;
				case 1:
					playerName = "Mohammad Nabi";
					age = 36;
					role = "All Rounder";
					runs = 2712;
					wickets = 127;
					SR = 87.2;
					bat_avg = 23.2;
					ball_avg = 32.8;
					break;
					// Add the remaining players' stats for Team Afghanistan
				case 2:
					playerName = "Rahmanullah Gurbaz";
					age = 20;
					role = "Batsman";
					runs = 802;
					wickets = 0;
					SR = 129.1;
					bat_avg = 33.4;
					ball_avg = 0;
					break;
				case 3:
					playerName = "Hashmatullah Shahidi";
					age = 26;
					role = "Batsman";
					runs = 1486;
					wickets = 0;
					SR = 73.8;
					bat_avg = 30.9;
					ball_avg = 0;
					break;
				case 4:
					playerName = "Asghar Afghan";
					age = 33;
					role = "Batsman";
					runs = 2573;
					wickets = 4;
					SR = 72.5;
					bat_avg = 23.8;
					ball_avg = 47.5;
					break;
				case 5:
					playerName = "Mujeeb Ur Rahman";
					age = 20;
					role = "Bowler";
					runs = 112;
					wickets = 74;
					SR = 79.2;
					bat_avg = 9.3;
					ball_avg = 25.6;
					break;
				case 6:
					playerName = "Najibullah Zadran";
					age = 29;
					role = "Batsman";
					runs = 1515;
					wickets = 0;
					SR = 86.7;
					bat_avg = 27.2;
					ball_avg = 0;
					break;
				case 7:
					playerName = "Gulbadin Naib";
					age = 31;
					role = "All Rounder";
					runs = 1011;
					wickets = 49;
					SR = 83.2;
					bat_avg = 23.1;
					ball_avg = 33.0;
					break;
				case 8:
					playerName = "Naveen-ul-Haq";
					age = 22;
					role = "Bowler";
					runs = 63;
					wickets = 34;
					SR = 100.5;
					bat_avg = 9.0;
					ball_avg = 27.1;
					break;
				case 9:
					playerName = "Rahmat Shah";
					age = 28;
					role = "Batsman";
					runs = 2302;
					wickets = 2;
					SR = 73.8;
					bat_avg = 31.0;
					ball_avg = 68.0;
					break;
				case 10:
					playerName = "Karim Janat";
					age = 23;
					role = "All Rounder";
					runs = 144;
					wickets = 19;
					SR = 78.3;
					bat_avg = 14.4;
					ball_avg = 28.1;
					break;
				case 11:
					playerName = "Hamid Hassan";
					age = 34;
					role = "Bowler";
					runs = 64;
					wickets = 59;
					SR = 102.7;
					bat_avg = 8.0;
					ball_avg = 24.4;
					break;
				}
				break;
				// Team Zimbabwe
			case 10:
				switch (j)
				{
				case 0:
					playerName = "Sean Williams";
					age = 35;
					role = "All Rounder";
					runs = 3831;
					wickets = 82;
					SR = 84.9;
					bat_avg = 37.1;
					ball_avg = 35.5;
					break;
				case 1:
					playerName = "Brendan Taylor";
					age = 35;
					role = "Batsman";
					runs = 6683;
					wickets = 5;
					SR = 80.6;
					bat_avg = 34.8;
					ball_avg = 68.8;
					break;
					// Add the remaining players' stats for Team Zimbabwe
				case 2:
					playerName = "Sikandar Raza";
					age = 35;
					role = "All Rounder";
					runs = 2947;
					wickets = 82;
					SR = 82.5;
					bat_avg = 34.0;
					ball_avg = 47.9;
					break;
				case 3:
					playerName = "Craig Ervine";
					age = 35;
					role = "Batsman";
					runs = 2869;
					wickets = 2;
					SR = 74.2;
					bat_avg = 34.2;
					ball_avg = 65.0;
					break;
				case 4:
					playerName = "Ryan Burl";
					age = 27;
					role = "All Rounder";
					runs = 1280;
					wickets = 30;
					SR = 82.9;
					bat_avg = 26.7;
					ball_avg = 43.4;
					break;
				case 5:
					playerName = "Tendai Chatara";
					age = 31;
					role = "Bowler";
					runs = 73;
					wickets = 101;
					SR = 83.6;
					bat_avg = 12.6;
					ball_avg = 32.1;
					break;
				case 6:
					playerName = "Donald Tiripano";
					age = 34;
					role = "Bowler";
					runs = 126;
					wickets = 29;
					SR = 76.1;
					bat_avg = 12.6;
					ball_avg = 36.4;
					break;
				case 7:
					playerName = "Regis Chakabva";
					age = 34;
					role = "Batsman";
					runs = 1211;
					wickets = 0;
					SR = 70.1;
					bat_avg = 27.5;
					ball_avg = 0;
					break;
				case 8:
					playerName = "Wesley Madhevere";
					age = 21;
					role = "All Rounder";
					runs = 616;
					wickets = 16;
					SR = 82.6;
					bat_avg = 26.8;
					ball_avg = 47.0;
					break;
				case 9:
					playerName = "Brandon Mavuta";
					age = 24;
					role = "Bowler";
					runs = 40;
					wickets = 9;
					SR = 68.9;
					bat_avg = 13.3;
					ball_avg = 34.2;
					break;
				case 10:
					playerName = "Richard Ngarava";
					age = 22;
					role = "Bowler";
					runs = 17;
					wickets = 19;
					SR = 50.7;
					bat_avg = 8.5;
					ball_avg = 22.8;
					break;
				}
				break;
				// Team Ireland
			case 11:
				switch (j)
				{
				case 0:
					playerName = "Paul Stirling";
					age = 31;
					role = "All Rounder";
					runs = 4759;
					wickets = 45;
					SR = 90.1;
					bat_avg = 36.6;
					ball_avg = 33.0;
					break;
				case 1:
					playerName = "Kevin O'Brien";
					age = 38;
					role = "All Rounder";
					runs = 3698;
					wickets = 114;
					SR = 89.0;
					bat_avg = 30.0;
					ball_avg = 31.8;
					break;
					// Add the remaining players' stats for Team Ireland
				case 2:
					playerName = "Andy Balbirnie";
					age = 30;
					role = "Batsman";
					runs = 3451;
					wickets = 8;
					SR = 75.6;
					bat_avg = 35.9;
					ball_avg = 31.6;
					break;
				case 3:
					playerName = "William Porterfield";
					age = 36;
					role = "Batsman";
					runs = 5455;
					wickets = 26;
					SR = 72.7;
					bat_avg = 30.3;
					ball_avg = 35.0;
					break;
				case 4:
					playerName = "George Dockrell";
					age = 29;
					role = "Bowler";
					runs = 358;
					wickets = 68;
					SR = 73.6;
					bat_avg = 10.5;
					ball_avg = 29.4;
					break;
				case 5:
					playerName = "Andrew McBrine";
					age = 29;
					role = "Bowler";
					runs = 245;
					wickets = 45;
					SR = 80.1;
					bat_avg = 12.9;
					ball_avg = 32.6;
					break;
				case 6:
					playerName = "Simi Singh";
					age = 34;
					role = "All Rounder";
					runs = 905;
					wickets = 42;
					SR = 79.2;
					bat_avg = 29.2;
					ball_avg = 34.1;
					break;
				case 7:
					playerName = "Harry Tector";
					age = 22;
					role = "Batsman";
					runs = 492;
					wickets = 2;
					SR = 78.3;
					bat_avg = 27.3;
					ball_avg = 67.0;
					break;
				case 8:
					playerName = "Lorcan Tucker";
					age = 24;
					role = "Batsman";
					runs = 736;
					wickets = 0;
					SR = 76.2;
					bat_avg = 24.5;
					ball_avg = 0;
					break;
				case 9:
					playerName = "Mark Adair";
					age = 25;
					role = "All Rounder";
					runs = 335;
					wickets = 19;
					SR = 87.4;
					bat_avg = 20.9;
					ball_avg = 25.7;
					break;
				case 10:
					playerName = "Barry McCarthy";
					age = 29;
					role = "Bowler";
					runs = 244;
					wickets = 49;
					SR = 98.2;
					bat_avg = 15.2;
					ball_avg = 27.6;
					break;
				case 11:
					playerName = "Joshua Little";
					age = 22;
					role = "Bowler";
					runs = 59;
					wickets = 26;
					SR = 71.1;
					bat_avg = 8.4;
					ball_avg = 26.7;
					break;
				}
				break;
			}

			Player player(playerName, age, role, runs, wickets, SR, bat_avg, ball_avg);

			team.addPlayer(player);
			team.updateStats(playerName, runs, role, wickets, SR, bat_avg, ball_avg);
		}

		teams.push_back(team);
		//	cout << "Team " << teamNames[i] << " added successfully!" << endl;
		//	cout << endl;
	}

	bool decision = false;
	while (!decision)
	{
		myDrawTextWithFont(340, 100, 40, (char*)"Press 1 : START NEW GAME", BLUE, YELLOW);
		myDrawTextWithFont(340, 140, 40, (char*)"Press 2 : Display team stats.", BLUE, YELLOW);
		myDrawTextWithFont(340, 180, 40, (char*)"Press 3 : Add new team", BLUE, YELLOW);
		myDrawTextWithFont(340, 220, 40, (char*)"Press 4 : Save new team", BLUE, YELLOW);
		myDrawTextWithFont(340, 260, 40, (char*)"Press 5 : Load existing team", BLUE, YELLOW);
		myDrawTextWithFont(340, 300, 40, (char*)"Press 6 : Exit", BLUE, YELLOW);
		myDrawTextWithFont(340, 340, 40, (char*)"Enter your choice: ", BLUE, YELLOW);

		
		int selection;
		int match1 = 0;
		int team1_num = 1;
		int team2_num = 1;
		cin >> selection;
		cout << endl;
		string new_name;
		Match M;
		fstream New2("highlights.txt");
		system("cls");

		switch (selection)
		{
		case 1:
			match1 = MatchType();
			if (match1 == 4)
			{
				system("cls");
				cout << "Enter the overs you want to play: ";
				cin >> overenter;
			}
			system("cls");
			cout << "Enter the Team Number you want to select as Team1:-" << endl;
			team1_num = displayAllTeamsNames(teams);
			team1_num--;
			teams[team1_num].displayAllPlayerNames();
			_getch();
			system("cls");
			cout << "Enter the Team Number you want to select as Team2:-" << endl;
			team2_num = displayAllTeamsNames(teams);
			while (team2_num == team1_num + 1)
			{
				system("cls");
				cout << "It is already selected.\nSelect a different team: ";
				team2_num = displayAllTeamsNames(teams);
			}
			team2_num--;
			teams[team2_num].displayAllPlayerNames();
			_getch();
			M.input(1, match1, teams[team1_num], teams[team2_num]);
			M.Game();
			break;
		case 3:
			cout << "Enter a new Team Name: ";
			cin >> new_name;
			teams.push_back(addTeam(new_name));
			system("cls");
			cout << "Team " << new_name << " added successfully!" << endl;
			cout << endl;
			break;
		case 2:
		{
			if (teams.empty())
			{
				cout << "No teams added yet." << endl;
				cout << endl;
			}
			else
			{
				system("cls");
				cout << "Following are the Team List:" << endl;
				int count = 0;
				for (int i = 0; i < teams.size(); i++)
				{
					cout << i + 1 << ")- " << teams[i].getTeamName() << endl;
				}
				int inp;
				cout << "Enter the Team Number you want to see stats: ";
				cin >> inp;
				system("cls");
				teams[inp - 1].displayTeam();
				//_getch();
	
			}
			break;
		}
		case 4:
			int team_num;
			cout << "Enter team number do you wat to store: ";
			cin >> team_num;
			teams[team_num - 1].savenewteam();
			break;
		case 5:

			if (New.peek() != New.eof())
			{
				Team t1;
				t1.loadnewteam();
				teams.push_back(t1);
			}
			break;
		case 6:
			decision = true;
			break;

		default:
			cout << "Invalid choice. Please try again." << endl;
			cout << endl;
			break;
		}
	}
	return 0;
}