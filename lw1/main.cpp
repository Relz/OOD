#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const string INPUT_FILE_NAME = "input.txt";

int main()
{
	ifstream inputFile(INPUT_FILE_NAME);

	string line;
	while (getline(inputFile, line))
	{
		cout << line << "\n";
	}

	return EXIT_SUCCESS;
}