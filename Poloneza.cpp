#include "Poloneza.h"

int calculExpresie(std::string sir, std::vector<char> fp)
{
	std::stack<int> stiva;

	for (auto c : fp)
	{
		int nr, x, y;

		if (c >= '0' && c <= '9')
			nr = c - '0';
		else
		{
			if (stiva.empty())
			{
				std::cout << "Eroare: Exista prea multi operatori\n";
				return -1;
			}

			y = stiva.top();

			if (stiva.empty())
			{
				std::cout << "Eroare: Exista prea multi operatori\n";
				return -1;
			}
			else
				stiva.pop();

			x = stiva.top();

			if (c == '+')
				nr = x + y;
			else
				if (c == '-')
					nr = x - y;
				else
					if (c == '*')
						nr = x * y;
					else
						if (c == '/')
							nr = x / y;
						else
							nr = std::pow(x, y);

			if (stiva.empty())
			{
				std::cout << "Eroare: Exista prea multi operatori\n";
				return -1;
			}
			else
				stiva.pop();
		}

		stiva.push(nr);
	}

	return stiva.top();
}

void afisareFormaPoloneza(const std::vector<std::string>& exp)
{
	for (auto elem : exp)
	{
		std::vector<char> fp;
		if (verificareString(elem))
		{
			formareFormaPoloneza(elem, fp);
			std::cout << "\n\nForma poloneza este: ";
			afisareVector2(fp);
			std::cout << "Rezultatul acestei expresii este: " << calculExpresie(elem, fp) << std::endl << std::endl;
		}
		else
			std::cout << "Eroare: apar caractere nepermise\n";
	}
}

bool verificareString(const std::string& cuv)
{
	std::string aux = "0123456789+-*/^()";
	for (char c : cuv)
	{
		if (aux.find(c) == std::string::npos)
			return false;
	}
	return true;
}

void citireSiruriFormareVector(const std::string& numeFisier, std::vector<std::string>& exp)
{
	std::ifstream fin(numeFisier);
	if (!fin)
	{
		std::cerr << "Eroare la deschiderea fisierului\n";
		return;
	}

	std::string sir, cuv1;
	while (!fin.eof())
	{
		getline(fin, sir);

		auto pos = sir.find(';');

		if (pos == std::string::npos)
			exp.push_back(sir);
		else
		{
			while (pos != std::string::npos)
			{
				cuv1 = sir.substr(0, pos);
				exp.push_back(cuv1);
				sir = sir.substr(pos + 1);
				pos = sir.find(';');

				if (pos == std::string::npos)
					exp.push_back(sir);
			}
		}

	}

	fin.close();

}

std::vector<std::string> finisareVector(const std::vector<std::string>& v)
{
	std::vector<std::string> aux;
	for (std::string sir : v)
	{
		std::string sir_aux = "";
		for (char c : sir)
			if (c != ' ' && c != '\t')
				sir_aux += c;

		aux.push_back(sir_aux);
	}
	return aux;
}


int prioritate(char c)
{
	if (c == '(' || c == ')')
		return 0;

	if (c == '+' || c == '-')
		return 1;

	if (c == '*' || c == '/')
		return 2;

	return 3;
}

bool formareFormaPoloneza(const std::string& sir, std::vector<char>& fp)
{
	std::stack<char> stiva;

	for (char c : sir)
	{
		if (c >= '0' && c <= '9')
			fp.push_back(c);
		else
			if (c == '(')
				stiva.push(c);
			else
				if (c == ')')
				{
					char c_nou = stiva.top();
					while (stiva.empty() == 0 && c_nou != '(')
					{
						fp.push_back(c_nou);
						stiva.pop();
						c_nou = stiva.top();
					}
					if (stiva.empty())
					{
						std::cerr << "Eroare de parantezare\n";
						return false;
					}
					if (!stiva.empty())
						stiva.pop();
				}
				else
				{
					while (stiva.empty() == 0 && prioritate(stiva.top()) >= prioritate(c))
					{
						fp.push_back(stiva.top());
						stiva.pop();
					}
					stiva.push(c);

				}
	}

	while (!stiva.empty())
	{
		if (stiva.top() == '(')
		{
			std::cerr << "Eroare de parantezare\n";
			return false;
		}
		fp.push_back(stiva.top());
		stiva.pop();
	}
	return true;
}

void afisareVector1(const std::vector<std::string>& v)
{
	for (auto elem : v)
		std::cout << elem << '\n';
}

void afisareVector2(const std::vector<char>& v)
{
	for (auto elem : v)
		std::cout << elem << ' ';
	std::cout << std::endl;
}