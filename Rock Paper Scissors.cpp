// Simple Game of Rock Paper Scissors
// Keeps track of the score, and allows the user to play as long as they'd like.
// By: Omer Khan

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string opponentChoice()
{
	srand(time(NULL));
	int num = rand() % 3;
	switch (num)
	{
	case 0:
	{
		return "Rock";
		break;
	}
	case 1:
	{
		return "Paper";
		break;
	}
	case 2:
	{
		return "Scissors";
		break;
	}
	}
}

bool didYouWin(string userChoice, string opponentChoice)
{
	if (userChoice == "Rock" && opponentChoice == "Scissors")
		return true;
	if (userChoice == "Rock" && opponentChoice == "Paper")
		return false;
	if (userChoice == "Paper" && opponentChoice == "Scissors")
		return false;
	if (userChoice == "Paper" && opponentChoice == "Rock")
		return true;
	if (userChoice == "Scissors" && opponentChoice == "Rock")
		return false;
	if (userChoice == "Scissors" && opponentChoice == "Paper")
		return true;

}
int main()
{
	bool done = false;
	srand(time(NULL));

	int opponentScore = 0;
	int userScore = 0;

	while (done == false)
	{
		srand(time(NULL));

		string opponentDecision = opponentChoice();


		string userChoice;
		cout << "Enter 'Rock', 'Paper', or 'Scissors': ";
		cin >> userChoice;

		while (userChoice != "Rock" && userChoice != "Paper" && userChoice != "Scissors")
		{
			cout << "Sorry, invalid input.  Please try again: ";
			cin >> userChoice;
		}




		while (userChoice == opponentDecision)
		{
			cout << "Sorry, both you and your opponent have entered " << userChoice << ". Please enter another move: " << endl;
			cin >> userChoice;
			while (userChoice != "Rock" && userChoice != "Paper" && userChoice != "Scissors")
			{
				cout << "Sorry, invalid input.  Please try again: ";
				cin >> userChoice;
			}

			opponentDecision = opponentChoice();
		}

		cout << "Your Choice: " << userChoice << endl;
		cout << "Opponent Choice: " << opponentDecision << endl;

		if (didYouWin(userChoice, opponentDecision) == true)
		{
			cout << "Congratulations you win!" << endl;
			userScore++;
		}
		else
		{
			cout << "Sorry you lost." << endl;
			opponentScore++;
		}

		
		cout << endl <<  "User Score: " << userScore << "   " << "Opponent Score: " << opponentScore << endl;
		


		string finished;
		cout << "Are you done playing ('Yes'/'No')? ";
		cin >> finished;

		while (finished != "Yes" && finished != "No")
		{
			cout << "Sorry invalid response. Enter another answer: ";
			cin >> finished;
		}
		if (finished == "Yes")
			done = true;

		cout << endl;
	}



	return 0;
}

