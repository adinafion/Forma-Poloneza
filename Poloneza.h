#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>

void citireSiruriFormareVector(const std::string& numeFisier, std::vector<std::string>& si);
std::vector<std::string> finisareVector(const std::vector<std::string>& v);
int prioritate(char c);
bool formareFormaPoloneza(const std::string& sir, std::vector<char>& fp);
void afisareVector1(const std::vector<std::string>& v);
void afisareVector2(const std::vector<char>& v);
bool verificareString(const std::string& cuv);
void afisareFormaPoloneza(const std::vector<std::string>& exp);
int calculExpresie(std::string sir, std::vector<char> fp);