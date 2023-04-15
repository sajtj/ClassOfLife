#ifndef animall
#define animall
#include "animal.h"
using namespace std;
int animal::getscore(char n1, char n2)
{
    int penalty = -1;
    int reward = 1;
    if (n1 == n2)
    {
        return reward;
    }
    else
    {
        return penalty;
    }
}
pair<string, string> animal::global_alignment(string X, string Y)
{
    int penalty = -1;
    int reward = 1;
    int m = X.length();
    int n = Y.length();
    int score_matrix[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        score_matrix[i][0] = penalty * i;
    }
    for (int j = 0; j <= n; j++)
    {
        score_matrix[0][j] = penalty * j;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int match = score_matrix[i - 1][j - 1] + getscore(X[i - 1], Y[j - 1]);
            int deletion = score_matrix[i - 1][j] + penalty;
            int insertion = score_matrix[i][j - 1] + penalty;

            score_matrix[i][j] = max(match, max(deletion, insertion));
        }
    }

    int i = m;
    int j = n;
    string aligned_X = "";
    string aligned_Y = "";

    while (i > 0 or j > 0)
    {
        int current_score = score_matrix[i][j];
        int left_score = score_matrix[i - 1][j];

        if (i > 0 and j > 0 and X[i - 1] == Y[j - 1])
        {
            aligned_X = X[i - 1] + aligned_X;
            aligned_Y = Y[j - 1] + aligned_Y;
            i--;
            j--;
        }
        else if (i > 0 and current_score == left_score + penalty)
        {
            aligned_X = X[i - 1] + aligned_X;
            aligned_Y = "-" + aligned_Y;
            i--;
        }
        else
        {
            aligned_X = "-" + aligned_X;
            aligned_Y = Y[j - 1] + aligned_Y;
            j--;
        }
    }

    return make_pair(aligned_X, aligned_Y);
}
float animal::Simi(Cell &a, Cell &b)
{
    float index = 0;
    double per = 0;
    double newper = 0;
    double percentage = 0;
    for (int i = 0; i < a.cromozoms.size(); i++)
    {
        per = 0;
        newper = 0;
        for (int j = 0; j < b.cromozoms.size(); j++)
        {
            index = 0;
            string X = a.cromozoms[i].DNA[0];
            string Y = b.cromozoms[j].DNA[0];
            pair<string, string> alignment = global_alignment(X, Y);
            for (int k = 0; k < alignment.first.size(); k++)
            {
                if (alignment.first[k] == alignment.second[k])
                {
                    index++;
                }
            }
            if (a.cromozoms[i].DNA[0].size() >= b.cromozoms[j].DNA[0].size())
            {
                index = (index / a.cromozoms[i].DNA[0].size()) * 100;
            }
            else
            {
                index = (index / b.cromozoms[j].DNA[0].size()) * 100;
            }
            per = per + index;
        }
        newper = per / b.cromozoms.size();
        percentage = percentage + newper;
    }
    percentage = percentage / a.cromozoms.size();
    if (a.cromozoms.size() == 0)
    {
        percentage = 0;
    }
    return percentage;
}
bool animal::operator==(animal &obj)
{
    if (obj.c.cromozoms.size() != c.cromozoms.size())
    {
        return false;
    }
    else if (obj.c.cromozoms.size() == c.cromozoms.size() and Simi(c, obj.c) >= 70)
    {
        return true;
    }
}
Cell animal::tolidmeslgheyrjensi(Cell &a)
{
    Cell temp = a;
    Cell parent;
    parent.cromozoms = a.cromozoms;
    Cell child;
    int n = a.cromozoms.size();
    int index = 0;
    vector<int> indexs;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        temp.cromozoms.push_back(temp.cromozoms[i]);
    }
    while (Simi(child, parent) < 70 or child.cromozoms.size() != n)
    {
        if (child.cromozoms.size() == n and Simi(child, parent) < 70)
        {
            child.cromozoms.clear();
        }
        index = rand() % (2 * n);
        bool flag = false;
        for (int i = 0; i < indexs.size(); i++)
        {
            if (index == indexs[i])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            indexs.push_back(index);
            child.cromozoms.push_back(temp.cromozoms[index]);
        }
    }
    return child;
}
Cell animal::operator+(animal &obj)
{
    Cell c1 = tolidmeslgheyrjensi(c);
    Cell c2 = tolidmeslgheyrjensi(obj.c);
    Cell child;
    int counter = 0;
    int index = 0;
    int n = c1.cromozoms.size();
    vector<int> indexs;
    srand(time(NULL));

    while (Simi(child, c1) <= 70 and Simi(child, c2) <= 70)
    {
        if (counter == 1000)
        {
            break;
        }
        child.cromozoms.clear();
        while (child.cromozoms.size() != n / 2)
        {
            bool flag = false;
            index = rand() % n;
            for (int i = 0; i < indexs.size(); i++)
            {
                if (index == indexs[i])
                {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
            {
                indexs.push_back(index);
                child.cromozoms.push_back(c1.cromozoms[index]);
            }
        }
        indexs.clear();
        while (child.cromozoms.size() != n)
        {
            bool flag = false;
            index = rand() % n;
            for (int i = 0; i < indexs.size(); i++)
            {
                if (index == indexs[i])
                {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
            {
                indexs.push_back(index);
                child.cromozoms.push_back(c2.cromozoms[index]);
            }
        }
        counter++;
        if (Simi(child, c1) >= 70 and Simi(child, c2) <= 70)
        {
            child.cromozoms.clear();
        }
        else if (Simi(child, c1) <= 70 and Simi(child, c2) >= 70)
        {
            child.cromozoms.clear();
        }
    }
    if (Simi(c1, child) >= 70 and Simi(c2, child) >= 70)
    {
        cout << "Child is : " << endl;
        for (int i = 0; i < child.cromozoms.size(); i++)
        {
            cout << i + 1 << " Cromozom :  ";
            for (int j = 0; j < child.cromozoms[i].dna1.size(); j++)
            {
                cout << child.cromozoms[i].dna1[j];
            }
            cout << endl;
            cout << "              ";
            for (int j = 0; j < child.cromozoms[i].dna2.size(); j++)
            {
                cout << child.cromozoms[i].dna2[j];
            }
            cout << endl;
        }
        return child;
    }
    else
    {
        cout << "tolidmesl jensi anjam nemishavad." << endl;
    }
}
void animal::tolidmesljensi(animal a, animal b)
{
    if (a.c.cromozoms.size() % 2 != 0 or b.c.cromozoms.size() % 2 != 0 or a.c.cromozoms.size() != b.c.cromozoms.size())
    {
        cout << "tolidmesl jensi anjam nemishavad" << endl;
    }
    else
    {
        a + b;
    }
}
void animal::deletingcromo(animal a)
{
    bool check = false;
    int t = 0;
    int n = a.c.cromozoms.size();
    for (int i = 0; i < n; i++)
    {
        vector<char> mokamel;
        for (int k = 0; k < a.c.cromozoms[t].dna1.size(); k++)
        {
            if (a.c.cromozoms[t].dna1[k] == 'A')
            {
                mokamel.push_back('T');
            }
            else if (a.c.cromozoms[t].dna1[k] == 'T')
            {
                mokamel.push_back('A');
            }
            else if (a.c.cromozoms[t].dna1[k] == 'C')
            {
                mokamel.push_back('G');
            }
            else if (a.c.cromozoms[t].dna1[k] == 'G')
            {
                mokamel.push_back('C');
            }
        }
        for (int j = 0; j < a.c.cromozoms[t].dna1.size(); j++)
        {
            if (a.c.cromozoms[t].dna2[j] != mokamel[j])
            {
                a.c.cromozoms.erase(a.c.cromozoms.begin() + t);
                check = true;
                break;
            }
        }
        if (check == false)
        {
            t++;
        }
    }
}

virus::virus(int n)
{
    for (int i = 0; i < n; i++)
    {
        string r;
        virus v;
        cout << i + 1 << " Virus : " << endl;
        cin >> r;
        v.RNA = r;
        viruses.push_back(v);
    }
    cout << "And how many Cromozoms do you want your animal contain?  ";
    int m;
    cin >> m;
    Cell a(m);
    for (int i = 0; i < m; i++)
    {
        strs.push_back(a.cromozoms[i].DNA[0]);
    }
}
string virus::largsubs(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    int maxlen = 0;
    int endpos = -1;
    int LSuff[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0 or j == 0)
                LSuff[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
            {
                LSuff[i][j] = LSuff[i - 1][j - 1] + 1;
                if (LSuff[i][j] > maxlen)
                {
                    maxlen = LSuff[i][j];
                    endpos = i - 1;
                }
            }
            else
                LSuff[i][j] = 0;
        }
    }

    if (maxlen == 0)
        return "";

    return str1.substr(endpos - maxlen + 1, maxlen);
}
string virus::findlongestSubstring(vector<string> strs)
{
    if (strs.size() == 0)
    {
        return "";
    }
    string result = strs[0];
    for (int i = 1; i < strs.size(); i++)
    {
        result = largsubs(result, strs[i]);
        if (result == "")
        {
            break;
        }
    }
    return result;
}
string virus::mokamel(string s)
{
    string str;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A')
        {
            str = str + 'T';
        }
        else if (s[i] == 'T')
        {
            str = str + 'A';
        }
        else if (s[i] == 'C')
        {
            str = str + 'G';
        }
        else if (s[i] == 'G')
        {
            str = str + 'C';
        }
    }
    return str;
}
void virus::illness()
{
    string LCS = findlongestSubstring(strs);
    string mokamelLCS = mokamel(LCS);
    string str;
    int index = 0;
    bool check = false;
    for (int i = 0; i < viruses.size(); i++)
    {
        index = 0;
        while (index != viruses[i].RNA.size())
        {
            if (LCS[index] == viruses[i].RNA[index] or mokamelLCS[index] == viruses[i].RNA[index])
            {
                for (int j = index; j < LCS.size() + index; j++)
                {
                    str = str + viruses[i].RNA[j];
                }
                if (str == LCS or str == mokamelLCS)
                {
                    check = true;
                    cout << "Virus " << i + 1 << " is dangrous." << endl;
                }
            }
            index++;
        }
    }
    if (check == false)
    {
        cout << "All of the viruses are safe." << endl;
    }
}
#endif