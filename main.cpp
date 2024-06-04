#include "Poloneza.h"


int main()
{
	std::vector<std::string> exp;
	std::string numeFisier = "date.in";

	citireSiruriFormareVector(numeFisier, exp);

	exp = finisareVector(exp);

	afisareFormaPoloneza(exp);

	return 0;
}