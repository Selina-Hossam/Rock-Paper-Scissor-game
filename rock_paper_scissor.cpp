#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
string choice(string arr[]) {
	string ch;
	srand(time(NULL));
	int i = (rand() % 3);
	ch = arr[i];
	return ch;

}
string standardize(string user_ch) {
	int size = user_ch.size();
	for (int i = 0; i < size; i++) {
		if (user_ch[i] >= 'A' && user_ch[i] <= 'Z') {
			user_ch[i]+= 32;
		}
	}
	return user_ch;
}
bool Check_valid(string user_ch) {
	if (user_ch == "rock" || user_ch == "paper" || user_ch == "scissor") return true;
	return false;

}
void check_win(string ch, string user_ch) {
	string arr[2] = { ch, user_ch };
	string winner;
	for (int i = 0; i < 2; i++) {
		if (arr[i] == "rock" && (arr[i + 1] == "scissor" || arr[i - 1] == "scissor")) {
			winner = arr[i];
			break;

		}



	
		else if (arr[i] == "scissor" && (arr[i + 1] == "paper" || arr[i - 1] == "paper")) {
			winner = arr[i];
			break;
		}

		else if (arr[i] == "paper" && (arr[i + 1] == "rock" || arr[i - 1] == "rock")) {
			winner = arr[i];
			break;
		}

		else {
			if (i >= 2) {
				winner = "Draw";

				break;
			}
		}
	}
		
		if (winner == ch) {
			cout << "The computer won!!\n";
			cout << "Computer choice: " << ch << "\n";
			cout << "Your choice: " << user_ch << "\n";
			return;
		}
		else if (winner == user_ch) {
			cout << "You won!!\n";
			cout << "Computer choice: " << ch << "\n";
			cout << "Your choice: " << user_ch << "\n";
			return;
		}cout << "Draw\n";
		cout << "Computer choice: " << ch << "\n";
		cout << "Your choice: " << user_ch << "\n";
	}

void rock_paper_scissor() {
	string choices[3] = { "rock", "paper", "scissor" };
	int status;
	bool cont=true;
	bool is_valid;
	cout << "WELCOME TO ROCK PAPER SCISSOR GAME!!!\n";
	while (cont == true) {
		string ch = choice(choices), user_ch;
		do {
			cout << "I chose my choice..\n";
			cout << "Your turn!! enter one of those: rock, paper, or scissor: " ;
			cin >> user_ch;

			user_ch = standardize(user_ch);
			is_valid = Check_valid(user_ch);
			if (is_valid) {
				check_win(ch, user_ch);
				cout << "DO you want to continue? if you want, press any number, otherwise press 0\n";
				cin >> status;
				if (status == 0) cont = false;
				else cont = true;

			}
			else {
				cout << "Invalid input!! Please try again...\n";
			}

		} while (!is_valid);
	}

	}


int main() {



	rock_paper_scissor();
	return 0;
}