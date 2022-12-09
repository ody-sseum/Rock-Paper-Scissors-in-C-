#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

int player(), computer();
void scoreboard(int), decisionRPS(int, int);

int playerScore = 0, computerScore = 0;

int main(){
	char repeatPlay;
	int roundChc, playerChc, computerChc;
	Start:
	cout << "Welcome to Rock, Paper, Scissors!" << endl;
	do {
	cout << "How many rounds would you like? ";
	cin >> roundChc;
	} while (roundChc <= 0);
	cout << "Thank you for entering! Loading game.";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	//round system
	for (int i = 1; i <= roundChc; i++){
	system("cls");
	scoreboard(i);
	playerChc = player();
	computerChc = computer();
	cout << "The computer is thinking.";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".\n";
	Sleep(1000);
	//RPSchecker
		if (playerChc == computerChc){
			cout << "You and the computer chose ";
			switch (playerChc) {
				case 1:
					cout << "rock!\n";
					break;
				case 2:
					cout << "paper!\n";
					break;
				case 3:
					cout << "scissors!\n";
					break;
			}
		}
		else {
			decisionRPS(playerChc, computerChc);
		}
	system("pause");
	}
	cout << "Calculating results.";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	system("cls");
	if (playerScore > computerScore) {
		cout << "The winner is the player with a score of " << playerScore << " to " << computerScore << "!" << endl;
	}
	else if (playerScore < computerScore) {
		cout << "The winner is the computer with a score of " << computerScore << " to " << playerScore <<  "!" << endl;
	}
	else {
		cout << "The game ends in a tie with a score of " << computerScore << " to " << playerScore << "!" << endl;
	}
	cout << "Would you like to play again [Y/N]? ";
	cin >> repeatPlay;
	if (repeatPlay == 'y' || repeatPlay == 'Y') {
		system("cls");
		playerScore = 0;
		computerScore = 0;
		goto Start;
	}
	cout << "Thank you for playing!\n";
	system("pause");
}

int player(){
	int playerRPS;
	do {
	cout << "[1] Rock \n[2] Paper \n[3] Scissors\nChoice: ";
	cin >> playerRPS;
	} while (playerRPS > 3 || playerRPS < 1);
	return playerRPS;
}

int computer(){
	int computerRPS;
	srand(time(0));
	computerRPS = rand() % 3 + 1;
	return computerRPS;
}

void decisionRPS(int player, int computer){
	switch (player) {
		case 1:
			if (computer == 2) {
				computerScore++;
			}
			else {
				playerScore++;
			}
			break;
		case 2:
			if (computer == 3) {
				computerScore++;
			}
			else {
				playerScore++;
			}
			break;
		case 3:
			if (computer == 1) {
				computerScore++;
			}
			else {
				playerScore++;
			}
			break;
	}
}

void scoreboard(int i){
	cout << "Round " << i << endl;
	cout << "**********" << endl;
	cout << playerScore << " - " << computerScore << endl;
	cout << "**********" << endl;
}
