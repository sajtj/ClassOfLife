#ifndef cell_h
#define cell_h

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

class Genome
{
public:
    Genome(){}
    string RNA;
    string DNA[2];
    vector<char> rna;
    vector<char> dna1;
    vector<char> dna2;
    Genome(string r, string d1, string d2);
    void printdan2();
    void smalljahesh(char x, char y, int n);
    void bigjahesh(string a, string b);
    void revers(string a);
};
class Cell : public Genome
{
public:
    Cell()
    {
    }
    vector<Genome> cromozoms;
    Cell(int n);
    void cell(int n);
    void margcell();
    void bigjahesh(string a, int n, string b, int m);
    void smalljahesh(char x, char y, int n, int m);
    void revers(string a, int n);
    string mokamel(string a);
    void palindrom(int n);
};

#endif
