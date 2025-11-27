/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:51:42 by mvachon           #+#    #+#             */
/*   Updated: 2025/11/27 15:51:42 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int main(int ac, char **av) 
{
	if (ac != 4)
		return (0);
	std::string s1(av[2]);
	std::string s2(av[3]);
	std::string output_filename = std::string(av[1]) + ".replace";
	std::ifstream file(av[1]);
	if (!file.is_open()) {
		std::cout << "Error: impossible to open the file." << std::endl;
		return 1;
	}
	std::string line;
	std::string final_line;
	std::ofstream output(output_filename.c_str());
	if (!output.is_open())
    	std::cout << "Error: impossible to create the file !" << std::endl;
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
}
