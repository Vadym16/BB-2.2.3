#include <iostream>
#include <ctime>
#include <string>

using namespace std;

bool game(string pc, string user);

int main()
{
	setlocale(LC_ALL, "ukr");
	srand(time(NULL));
	char choice;

	do {
		cout << "Виберіть дію:\n 1.Почати гру\n 3.Вихід" << endl;
		cin >> choice;

		if (choice == '1') {
			string pcnum;
			for (int i = 0; i < 3; i++) {
				pcnum += '0' + rand() % 10;
			}
			// cout << "комп'ютер загадав: " <<pcnum<<endl;

			bool gameWon = false;
			while (!gameWon) {
				string usernum;
				cout << "Введіть ваш варіант: ";
				cin >> usernum;

				gameWon = game(pcnum, usernum);

				if (gameWon) {
					cout << "\nВи виграли гру!" << endl;
				}
			}
		}
	} while (choice != '3');

	cout << "Гру завершено." << endl;
	return 0;
}

bool game(string pc, string user) {
	int true_num = 0;  
	int pos_num = 0;   

	bool pc_[3] = { false };
	bool user_[3] = { false };

	for (int i = 0; i < 3; i++) {
		if (pc[i] == user[i]) {
			pos_num++;
			pc_[i] = true;
			user_[i] = true;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (!user_[i]) {
			for (int j = 0; j < 3; j++) {
				if (!pc_[j] && user[i] == pc[j]) {
					true_num++;
					pc_[j] = true;
					break;
				}
			}
		}
	}

	cout << "Вгадано чисел не на своїх позиціях: " << true_num
		<< ", На правильних позиціях: " << pos_num << endl;

	return pos_num == 3;
}
