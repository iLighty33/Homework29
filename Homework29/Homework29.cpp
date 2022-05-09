#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	// Задача 1

	ofstream out;

	string path1 = "file.txt";
		
	out.open("path1, ios::app");

	if (out.is_open()) {
		string input;
		do {
			cout << "Введите строку:\n";
			getline(cin, input);
			out << input << "\n";
		} while (input != "end");
	}
	else
		cout << "Открыть файл не удалось\n";

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
		cout << "Файл открыть не удалось\n";

	in.close();
	remove("file.txt");


	return 0;
}