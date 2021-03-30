#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "ParkingLot.h"
#include "ParkingLotManager.h"

int main(int argc, char* argv[])
{
	std::string filename;
	if (argc < 2)
	{
		filename = "../../resource/input.txt";
	}
	else
	{
		filename = argv[1];
	}
	std::string input_line;
	std::ifstream input_file(filename, std::ios::in);
	if (!input_file.is_open())
	{
		std::cout << "Could not open input file " << filename << ". Please ensure the file provided in the command line argument is correct and the file exists." << std::endl;
	}
	else
	{
		ParkingLotManager manager; // The ParkingLotManager instance responsible for executing the given commands
		ParkingLot parking_lot; // The ParkingLot instance on which the commands are executed
		while (std::getline(input_file, input_line))
		{
			std::vector<std::string> input_tokens; // vector for tokens/words on a single line in the input file
			std::stringstream ss(input_line);
			std::string token;
			const char delim = ' ';
			while (std::getline(ss, token, delim)) // reading each line of input file
			{
				input_tokens.push_back(token); // creating the vector of tokens/words of the line
			}
			manager.executeCommand(parking_lot, input_tokens);
		}
		input_file.close(); // closing the input file
	}
	return 0;
}
