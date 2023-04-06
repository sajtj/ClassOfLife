#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include<algorithm>
using namespace std;

class Genome
{
public:
    string RNA;
    string DNA[2];
    Genome()
    {
    }
    vector<char> rna;
    vector<char> dna1;
    vector<char> dna2;
    Genome(string r, string d1, string d2)
    {
        RNA = r;
        DNA[0] = d1;
        DNA[1] = d2;
        for (int i = 0; i < RNA.size(); i++)
        {
            rna.push_back(RNA[i]);
        }
        for (int i = 0; i < DNA[0].size(); i++)
        {
            dna1.push_back(DNA[0][i]);
            dna2.push_back(DNA[1][i]);
        }
    }
    void printdan2()
    {
        for (int i = 0; i < rna.size(); i++)
        {
            if (rna[i] == 'A')
            {
                cout << 'T';
            }
            else if (rna[i] == 'T')
            {
                cout << 'A';
            }
            else if (rna[i] == 'C')
            {
                cout << 'G';
            }
            else if (rna[i] == 'G')
            {
                cout << 'C';
            }
        }
        cout << endl;
    }
    void smalljahesh(char x, char y, int n)
    {
        // RNA :
        vector<char> r = rna;
        int index = 0;
        for (int i = 0; i < rna.size(); i++)
        {
            if (rna[i] == x)
            {
                index++;
            }
        }
        int t = 0;
        if (index >= n)
        {
            for (int i = 0; i < rna.size(); i++)
            {
                if (t == n)
                {
                    break;
                }
                if (rna[i] == x)
                {
                    r.at(i) = y;
                    t++;
                }
            }
            cout << "RNA : ";
            for (int i = 0; i < r.size(); i++)
            {
                cout << r[i];
            }
            cout << endl;
        }
        else
        {
            cout << "there aren't enough " << x << " in RNA." << endl;
        }
        // DNA :
        char mokamel;
        if (y == 'A')
        {
            mokamel = 'T';
        }
        else if (y == 'T')
        {
            mokamel = 'A';
        }
        else if (y == 'C')
        {
            mokamel = 'G';
        }
        else if (y == 'G')
        {
            mokamel = 'C';
        }
        index = 0;
        t = 0;
        vector<char> d1 = dna1;
        vector<char> d2 = dna2;
        for (int i = 0; i < dna1.size(); i++)
        {
            if (dna1[i] == x or dna2[i] == x)
            {
                index++;
            }
        }
        if (index >= n)
        {
            for (int i = 0; i < dna1.size(); i++)
            {
                if (t == n)
                {
                    break;
                }

                if (dna1[i] == x or dna2[i] == x)
                {
                    if (dna1[i] == x)
                    {
                        d1.at(i) = y;
                        d2.at(i) = mokamel;
                        t++;
                    }
                    else if (dna2[i] == x)
                    {
                        d2.at(i) = y;
                        d1.at(i) = mokamel;
                        t++;
                    }
                }
            }
            cout << "DNA : ";
            for (int i = 0; i < d1.size(); i++)
            {
                cout << d1[i];
            }
            cout << endl
                 << "      ";
            for (int i = 0; i < d2.size(); i++)
            {
                cout << d2[i];
            }
            cout << endl;
        }
        else
        {
            cout << "there aren't enough " << x << " in DNA." << endl;
        }
    }
    void bigjahesh(string a, string b)
    {
        bool h = true;
        int f = 0;
        string a1;
        string a2;
        // RNA :
        vector<char> r = rna;
        int n;
        for (int i = 0; i < rna.size(); i++)
        {
            a1 = "";
            if (i == rna.size() - 1)
            {
                cout << a << " not found in RNA." << endl;
                h = false;
            }
            if (rna[i] == a[0])
            {
                for (int j = i; j < a.size() + i; j++)
                {
                    a1 = a1 + rna[j];
                }
                if (a1 == a)
                {
                    if (a.size() >= b.size())
                    {
                        for (int j = i; j < a.size() + i; j++)
                        {
                            if (f >= b.size())
                            {
                                n = i + f;
                                r.erase(r.begin() + n);
                            }
                            else
                            {
                                r.at(j) = b[f];
                                f++;
                            }
                        }
                        break;
                    }
                    else
                    {
                        for (int j = i; j < b.size() + i; j++)
                        {
                            if (f >= a.size())
                            {
                                r.insert(r.begin() + j, b[f]);
                                f++;
                            }
                            else
                            {
                                r.at(j) = b[f];
                                f++;
                            }
                        }
                        break;
                    }
                }
            }
            else
            {
                continue;
            }
        }
        if (h == true)
        {
            cout << "RNA : ";
            for (int i = 0; i < r.size(); i++)
            {
                cout << r[i];
            }
            cout << endl;
        }
        // DNA :
        vector<char> d1 = dna1;
        vector<char> d2 = dna2;
        string mokamel;
        a1 = "";
        a2 = "";
        f = 0;
        h = true;
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i] == 'A')
            {
                mokamel = mokamel + 'T';
            }
            else if (b[i] == 'T')
            {
                mokamel = mokamel + 'A';
            }
            else if (b[i] == 'C')
            {
                mokamel = mokamel + 'G';
            }
            else if (b[i] == 'G')
            {
                mokamel = mokamel + 'C';
            }
        }
        for (int i = 0; i < dna1.size(); i++)
        {
            a1 = "";
            a2 = "";
            if (i == dna1.size() - 1)
            {
                cout << a << " not found in DNA." << endl;
                h = false;
            }
            if (dna1[i] == a[0])
            {
                for (int j = i; j < a.size() + i; j++)
                {
                    a1 = a1 + dna1[j];
                }
                if (a1 == a)
                {
                    if (a.size() >= b.size())
                    {
                        for (int j = i; j < a.size() + i; j++)
                        {
                            if (f >= b.size())
                            {
                                n = i + f;
                                d1.erase(d1.begin() + n);
                                d2.erase(d2.begin() + n);
                            }
                            else
                            {
                                d1.at(j) = b[f];
                                d2.at(j) = mokamel[f];
                                f++;
                            }
                        }
                        break;
                    }
                    else
                    {
                        for (int j = i; j < b.size() + i; j++)
                        {
                            if (f >= a.size())
                            {
                                d1.insert(d1.begin() + j, b[f]);
                                d2.insert(d2.begin() + j, mokamel[f]);
                                f++;
                            }
                            else
                            {
                                d1.at(j) = b[f];
                                d2.at(j) = mokamel[f];
                                f++;
                            }
                        }
                        break;
                    }
                }
            }
            else if (dna2[i] == a[0])
            {
                for (int j = i; j < a.size() + i; j++)
                {
                    a2 = a2 + dna2[j];
                }
                if (a2 == a)
                {
                    if (a.size() >= b.size())
                    {
                        for (int j = i; j < a.size() + i; j++)
                        {
                            if (f >= b.size())
                            {
                                d2.erase(d2.begin() + j);
                                d1.erase(d1.begin() + j);
                            }
                            else
                            {
                                d2.at(j) = b[f];
                                d1.at(j) = mokamel[f];
                                f++;
                            }
                        }
                        break;
                    }
                    else
                    {
                        for (int j = i; j < a.size(); j++)
                        {
                            if (f >= b.size())
                            {
                                d2.insert(d2.begin() + j, b[f]);
                                d1.insert(d1.begin() + j, mokamel[f]);
                                f++;
                            }
                            else
                            {
                                d2.at(j) = b[f];
                                d1.at(j) = mokamel[f];
                                f++;
                            }
                        }
                        break;
                    }
                }
            }
            else
            {
                continue;
            }
        }
        if (h == true)
        {
            cout << "DNA : ";
            for (int i = 0; i < d1.size(); i++)
            {
                cout << d1[i];
            }
            cout << endl
                 << "      ";
            for (int i = 0; i < d2.size(); i++)
            {
                cout << d2[i];
            }
            cout << endl;
        }
    }
    void revers(string a)
    {
        string a1;
        string a2;
        string ra1;
        string ra2;
        int t = 0;
        int index = 0;
        // RNA :
        vector<char> r = rna;
        for (int i = 0; i < rna.size(); i++)
        {
            a1 = "";
            if (rna[i] == a[0])
            {
                for (int j = i; j < a.size() + i; j++)
                {
                    a1 = a1 + rna[j];
                }
            }
            if (a1 == a)
            {
                index++;
                for (int k = a.size() - 1; k >= 0; k--)
                {
                    ra1 = ra1 + a1[k];
                }
                for (int j = i; j < a.size() + i; j++)
                {
                    r.at(j) = ra1[t];
                    t++;
                }
                break;
            }
        }
        if (index == 0)
        {
            cout << a << " not found in RNA." << endl;
        }
        else
        {
            cout << "RNA : ";
            for (int i = 0; i < r.size(); i++)
            {
                cout << r[i];
            }
            cout << endl;
        }
        // DNA :
        vector<char> d1 = dna1;
        vector<char> d2 = dna2;
        string mokamel;
        string rmokamel;
        t = 0;
        index = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 'A')
            {
                mokamel = mokamel + 'T';
            }
            else if (a[i] == 'T')
            {
                mokamel = mokamel + 'A';
            }
            else if (a[i] == 'C')
            {
                mokamel = mokamel + 'G';
            }
            else if (a[i] == 'G')
            {
                mokamel = mokamel + 'C';
            }
        }
        for (int i = 0; i < dna1.size(); i++)
        {
            a1 = "";
            a2 = "";
            if (dna1[i] == a[0])
            {
                for (int j = i; j < a.size() + i; j++)
                {
                    a1 = a1 + dna1[j];
                }
                if (a1 == a)
                {
                    index++;
                    ra1 = "";
                    for (int k = a.size() - 1; k >= 0; k--)
                    {
                        ra1 = ra1 + a1[k];
                    }
                    for (int k = a.size() - 1; k >= 0; k--)
                    {
                        rmokamel = rmokamel + mokamel[k];
                    }
                    for (int j = i; j < a.size() + i; j++)
                    {
                        d1.at(j) = ra1[t];
                        d2.at(j) = rmokamel[t];
                        t++;
                    }
                    break;
                }
            }
            else if (dna2[i] == a[0])
            {
                for (int j = i; j < a.size() + i; j++)
                {
                    a2 = a2 + dna2[j];
                }
                if (a2 == a)
                {
                    index++;
                    for (int k = a.size() - 1; k >= 0; k--)
                    {
                        ra2 = ra2 + a2[k];
                    }
                    for (int k = a.size() - 1; k >= 0; k--)
                    {
                        rmokamel = rmokamel + mokamel[k];
                    }
                    for (int j = i; j < a.size() + i; j++)
                    {
                        d2.at(j) = ra2[t];
                        d1.at(j) = rmokamel[t];
                        t++;
                    }
                    break;
                }
            }
        }
        if (index == 0)
        {
            cout << a << " not found in DNA." << endl;
        }
        else
        {
            cout << "DNA : ";
            for (int i = 0; i < d1.size(); i++)
            {
                cout << d1[i];
            }
            cout << endl
                 << "      ";
            for (int i = 0; i < d2.size(); i++)
            {
                cout << d2[i];
            }
            cout << endl;
        }
    }
};
