#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

int main()
{
	
	setlocale(LC_ALL, "Russian");

	std::string c;
	std::string N[100];

	std::ifstream in("text.txt", std::ios::in);
	std::ofstream out("out.txt", std::ios::out);

	int y = 0;
	int n;
	char symbol;
	std::cin >> n;
	in >> symbol;
	
	while (!in.eof())
	{
		in >> c;
		for (int x = 0; x < c.length(); x++) 
		{	
			std::cout << c << std::endl;
			c[x] = (char)tolower(c[x]);
			if (symbol == c[c.length() - 1]) 
			{
				N[y] = c;
				y++;
				break;
			}
		}
	}
	for (int i = 0; i < y - 1; i++) {
		for (int j = i + 1; j < y; j++) {
			if (N[i].length() < N[j].length()) {
				swap(N[i], N[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		out << N[i] << " ";
	}
	return 0;
}