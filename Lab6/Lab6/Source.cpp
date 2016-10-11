#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
int main() {

	ifstream results("Champ_Ladies_Short.txt");

	string fLine;
	string name;
	string event;
	int goe;

	getline(results, fLine);
	cout << fLine << endl;

	while (!results.eof()) {

		getline(results, name);
		cout << name;
		for (int i = 0; i < 7; i++) {
			results >> event;
			cout << event << ": ";
			for (int j = 0; j < 9; j++) {
				results >> goe;
				cout << goe << " ";
			}
			cout << endl;
			results.ignore();
		}
		cout << endl;
	}
	system("pause");

	return 0;
}
*/