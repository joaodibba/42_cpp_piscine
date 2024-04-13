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
		std::string newLine;
		std::size_t pos = 0;
		while (pos < line.length())
		{
			if (line.substr(pos, s1.length()) == s1)
			{
				newLine += s2;
				pos += s1.length();
			}
			else
				newLine += line[pos++];
		}
		content += newLine + "\n";
	}
	return (content);
}

static void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
	if (!validateInputs(s1, s2))
		return;

	std::string content;
	try {
		std::ifstream file(filename);
		if (!file.is_open()){
			std::cerr << "Error: could not open file " << filename << std::endl;
			return;
		}
		content = processFile(file, s1, s2);
		file.close();
	} catch (const std::ifstream::failure& e) {
		std::cerr << "Exception opening/reading file: " << e.what() << std::endl;
		return;
	} catch (const std::exception& e) {
		std::cerr << "Error during file processing: " << e.what() << std::endl;
		return;
	}
	try {
		std::ofstream newfile(filename + ".replace");
		if (!newfile.is_open()){
			std::cerr << "Error: could not create new file" << std::endl;
			return;
		}
		newfile << content;
		newfile.close();
	} catch (const std::ofstream::failure& e) {
		std::cerr << "Exception opening/writing file: " << e.what() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error during file creation: " << e.what() << std::endl;
	}
}

int main(int ac, char **av)
{
	if (ac == 4 && av[1][0] && av[2][0] && av[3][0])
		replaceInFile(av[1], av[2], av[3]);
	else
		std::cerr << "Usage: ./sedIsForLosers <filename> <string1> <string2>" << std::endl;
	return (0);
}