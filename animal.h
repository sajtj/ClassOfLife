#ifndef animal_h
#define animal_h
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include "cell.cpp"
using namespace std;

class animal : public Cell
{
public:
    friend class virus;
    Cell c;
    int getscore(char n1, char n2);
    pair<string, string> global_alignment(string X, string Y);
    float Simi(Cell &a, Cell &b);
    bool operator==(animal &obj);
    Cell tolidmeslgheyrjensi(Cell &a);
    Cell operator+(animal &obj);
    void tolidmesljensi(animal a, animal b);
    void deletingcromo(animal a);
};
class virus : public Genome
{
public:
    virus()
    {
    }
    vector<virus> viruses;
    vector<string> strs;
    virus(int n);
    string largsubs(string str1, string str2);
    string findlongestSubstring(vector<string> strs);
    string mokamel(string s);
    void illness();
};

#endif