#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	// ������ 1

	ofstream out;

	string path1 = "file.txt";
		
	out.open("path1, ios::app");

	if (out.is_open()) {
		string input;
		do {
			cout << "������� ������:\n";
			getline(cin, input);
			out << input << "\n";
		} while (input != "end");
	}
	else
		cout << "������� ���� �� �������\n";

	out.close();

	ifstream in;
	in.open("file.txt");

	if (in.is_open()) {
		while (!in.eof()) {
			string str;
			getline(in, str);
			cout << str << endl;
		}
	}
	else
		cout << "���� ������� �� �������\n";

	in.close();
	remove("file.txt");


	return 0;
}