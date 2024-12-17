#include <iostream>

int ft_toupper(int c)
{
	if(c >= 97 && c <= 122)
		return (c -= 32);
	return (c);
}

int main(int ac, char **argv)
{
	if(ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";	
	else
	{
		int i = 1, j;

		while(argv[i])
		{
			j = 0;
			while(argv[i][j])
			{
				argv[i][j] = ft_toupper(argv[i][j]);
				j++;
			}
			std::cout << argv[i];
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}