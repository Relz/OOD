#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const string INPUT_FILE_NAME = "input.txt";

int main()
{
	ifstream inputFile(INPUT_FILE_NAME);

	string line;
	while (getline(inputFile, line))
	{
		stringstream ss(line);
		string shapeName;
		ss >> shapeName;
		shapeName.pop_back();

		cout << shapeName << "\n";
	}

	return EXIT_SUCCESS;
}