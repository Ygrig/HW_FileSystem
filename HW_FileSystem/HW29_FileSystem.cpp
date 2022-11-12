#include <iostream>
#include <fstream>
#include <string>

bool overwrite(std::string path, std::string str2);

int main() {
	
	std::cout << "Task 29.1\n";
	std::ofstream out;
	out.open("file.txt", std::ios::app);
	if (out.is_open()) {
		std::string input;
		do {
			std::cout << "Input string:\n";
			getline(std::cin, input);
			out << input << "\n";
		} while (input != "end");
	}
	else
		std::cout << "File opening error.\n";
	out.close();

	std::ifstream in;
	in.open("file.txt");
	if (in.is_open()) {
		while (!in.eof()) {
			std::string str;
			getline(in, str);
			std::cout << str << "\n";
		}
	}
	else
		std::cout << "File opening error.\n";
	in.close();
	remove("file.txt");
	
	std::cout << "Task 29.2\n";
	std::string path = "file2.txt";
	std::string str2 = "string changed";
	if (overwrite(path, str2))
		std::cout << "File content is overwritten.\n";
	else
		std::cout << "FALSE\n";

	return 0;
}

bool overwrite(std::string path, std::string str2) {
	std::ofstream out2;
	out2.open (path, std::ios::out | std::ios::in);
	if (out2.is_open()) {
		out2 << str2 << "\n";
		out2.close();
		return true;
	}
	else
		return false;

}