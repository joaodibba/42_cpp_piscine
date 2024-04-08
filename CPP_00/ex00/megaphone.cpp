#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; av[i]; i++){
		for(int j = 0; av[i][j]; j++){
			av[i][j] = std::toupper(av[i][j]);
			std::cout << av[i][j];
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}