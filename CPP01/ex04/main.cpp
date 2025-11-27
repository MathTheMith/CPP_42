#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int main(int ac, char **av) 
{
	if (ac == 4)
	{
		std::string s1 = av[2];
		std::string s2 = av[3];
		std::string output_filename = std::string(av[1]) + ".replace";
		std::ifstream file(av[1]);

		if (!file.is_open()) {
			std::cerr << "Error: impossible to open the file." << std::endl;
			return 1;
		}
		std::string line;
		std::string final_line;
		std::ofstream output(output_filename.c_str());
		if (!output.is_open())
        	std::cerr << "Error: impossible to create the file !" << std::endl;
		while (std::getline(file, line))
		{
		    std::size_t pos = 0;
		    final_line.clear();
		    while ((pos = line.find(s1)) != std::string::npos)
		    {
		        final_line += line.substr(0, pos);
		        final_line += s2;
		        line = line.substr(pos + s1.length());
		    }
		    final_line += line;
		    output << final_line << "\n";
		}
		file.close();
		return 0;
	}
	return (1);
}
