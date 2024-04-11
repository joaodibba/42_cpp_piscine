#include <string>
#include <iostream>
#include <fstream>

static bool validateInputs(const std::string& s1, const std::string& s2)
{
	if (s1 == s2)
	{
		std::cerr << "Error: string1 and string2 are the same" << std::endl;
		return (false);
	}
	return (true);
}

static std::string processFile(std::ifstream& file, const std::string& s1, const std::string& s2)
{
	std::string line;
	std::string content;
	while (std::getline(file, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.replace(pos, s1.length(), s2);
			pos += s2.length();
		}
		content += line + "\n";
	}
	return (content);
}

static void replaceInFile(std::string filename, const std::string s1, const std::string s2)
{
	if (!validateInputs(s1, s2)) return;

	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}

	std::string content = processFile(file, s1, s2);
	file.close();

	std::ofstream newfile(filename + ".replace");
	if (!newfile.is_open())
	{
		std::cerr << "Error: could not create new file" << std::endl;
		return;
	}
	newfile << content;
	newfile.close();
}

int main(int ac, char **av)
{
	if (ac != 4 || av[1][0] == '\0' || av[2][0] == '\0' || av[3][0] == '\0')
	{
		std::cerr << "Usage: ./sedIsForLosers <filename> <string1> <string2>" << std::endl;
		return (0);
	}
	replaceInFile(av[1], av[2], av[3]);
	return (0);
}