#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool overwrite(string& path, string& str);

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

	// Задача 2

	cout << "\nЗадача 2.\n";

	string path2 = "file2.txt";
	string str = "Строка, которая заменяет содержимое файла";

	overwrite(path2, str) ? cout << "True" << "\n" : cout << "False" << "\n";

	remove("file2.txt");

	return 0;
}

// Задача 2

bool overwrite(string& path, string& str) {
	ofstream out2;
	out2.open(path, ios::in || ios::out);

	if (out2.is_open()) {
		out2 << str << "\n";
		out2.close();
		return true;
	}
	return false;
}

