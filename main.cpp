#include "cell.h"
#include "cell.cpp"
#include "animal.h"
#include "animal.cpp"
using namespace std;

int main()
{
    cout << "Hello, Welcome..." << endl;
    string run = "yes";
    while (run == "yes")
    {
        cout << " Which part do you want to work with?" << endl
             << "  1) Genome" << endl
             << "  2) Cell" << endl
             << "  3) Animal" << endl
             << "  4) Virus" << endl
             << "  5) Close the App." << endl;
        int a;
        cin >> a;
        if (a == 5)
        {
            break;
        }
        string continu = "new";
        while (a == 1 and continu == "new")
        {
            int index = 0;
            string RNA;
            string DNA1;
            string DNA2;
            cout << "Please enter your ideal Genome :" << endl
                 << "RNA : ";
            cin >> RNA;
            cout << "DNA : ";
            cin >> DNA1;
            cout << "      ";
            cin >> DNA2;
            Genome G1(RNA, DNA1, DNA2);

            cout << "What do you want to do with your object?" << endl
                 << " 1) Print DNA's complement from RNA." << endl
                 << " 2) Small mutation." << endl
                 << " 3) Big mutation." << endl
                 << " 4) Reverse a substring." << endl;
            int x;
            cin >> x;
            continu = "this";
            while (continu == "this")
            {
                if (index > 0)
                {
                    cout << "What do you want to do with your object?" << endl
                         << " 1) Print DNA's complement from RNA." << endl
                         << " 2) Small mutation." << endl
                         << " 3) Big mutation." << endl
                         << " 4) Reverse a substring." << endl;
                    cin >> x;
                }
                if (x == 1)
                {
                    G1.printdan2();
                    index++;
                    cout << "wanna continue with this Genome or you want to creat new one or exit?(this/new/exit)  ";
                    cin >> continu;
                }
                else if (x == 2)
                {
                    cout << "Which character do you want to change?"
                         << "  ";
                    char c;
                    cin >> c;
                    cout << "And how many of that do you want to change in your object?"
                         << "  ";
                    int p;
                    cin >> p;
                    cout << "What is the character you want to be replaced instead of " << c << "?"
                         << "  ";
                    char t;
                    cin >> t;
                    G1.smalljahesh(c, t, p);
                    index++;
                    cout << "wanna continue with this Genome or you want to creat new one or exit?(this/new/exit)  ";
                    cin >> continu;
                }
                else if (x == 3)
                {
                    cout << "Which substring do you want to change?"
                         << "  ";
                    string c;
                    cin >> c;
                    cout << "Enter the substring do you want to be replaced instead of " << c << "?"
                         << "  ";
                    string t;
                    cin >> t;
                    G1.bigjahesh(c, t);
                    index++;
                    cout << "wanna continue with this Genome or you want to creat new one or exit?(this/new/exit)  ";
                    cin >> continu;
                }
                else if (x == 4)
                {
                    cout << "Which substring do you want to reverse?  ";
                    string c;
                    cin >> c;
                    G1.revers(c);
                    index++;
                    cout << "wanna continue with this Genome or you want to creat new one or exit?(this/new/exit)  ";
                    cin >> continu;
                }
            }
        }
        while (a == 2 and continu == "new")
        {
            int index = 0;
            cout << "How many Cromozoms do you want to have?  ";
            int w;
            cin >> w;
            Cell c(w);
            cout << "What do you want to do with your Cell?" << endl
                 << " 1) Delete wrong Cells." << endl
                 << " 2) Small mutation." << endl
                 << " 3) Big mutation." << endl
                 << " 4) Reverse a substring." << endl
                 << " 5) Palindrom." << endl;
            int x;
            cin >> x;
            continu = "this";
            while (continu == "this")
            {
                if (index > 0)
                {
                    cout << "What do you want to do with your Cell?" << endl
                         << " 1) Delete wrong Cells." << endl
                         << " 2) Small mutation." << endl
                         << " 3) Big mutation." << endl
                         << " 4) Reverse a substring." << endl
                         << " 5) Palindrom." << endl;
                    cin >> x;
                }
                if (x == 1)
                {
                    c.margcell();
                    index++;
                    cout << "wanna continue with this Cell or you want to creat new one or exit?(this/new/exit)  ";
                    cin >> continu;
                }
                else if (x == 2)
                {
                    cout << "What is the fist character you want to change?  ";
                    char c1;
                    cin >> c1;
                    cout << "Enter number of the Cromozom that you want " << c1 << " in it :  ";
                    int n1;
                    cin >> n1;
                    cout << "What is the character you want to be replaced instead of " << c1 << " in Cromozom " << n1 << " ?  ";
                    char c2;
                    cin >> c2;
                    cout << "Enter number of the Cromozom that you want " << c2 << " in it :  ";
                    int n2;
                    cin >> n2;
                    c.smalljahesh(c1, c2, n1, n2);
                    index++;
                    cout << "wanna continue with this Cell or you want to creat new one or exit?(this/new/exit)  ";
                    cin >> continu;
                }
                else if (x == 3)
                {
                    cout << "What is the fist substring you want to change?  ";
                    string s1;
                    cin >> s1;
                    cout << "Enter the number of the Cromozom that you want " << s1 << " in it :  ";
                    int n1;
                    cin >> n1;
                    cout << "What is the substring you want to be replaced instead of " << s1 << " in Cromozom " << n1 << " ?  ";
                    string s2;
                    cin >> s2;
                    cout << "Enter the number of the Cromozom that you want " << s2 << " in it :  ";
                    int n2;
                    cin >> n2;
                    c.bigjahesh(s1, n1, s2, n2);
                    index++;
                    cout << "wanna continue with this Cell or you want to creat new one or exit?(this/new/exit)  ";
                    cin >> continu;
                }
                else if (x == 4)
                {
                    cout << "Which is the substring you want to be reversed?  ";
                    string s;
                    cin >> s;
                    cout << "Enter the number of the Cromozom that you want to reverse " << s << " in it :  ";
                    int n;
                    cin >> n;
                    c.revers(s, n);
                    index++;
                    cout << "wanna continue with this Cell or you want to creat new one or exit?(this/new/exit)  ";
                    cin >> continu;
                }
                else if (x == 5)
                {
                    cout << "Enter the number of the Cromozom that you want to find its palindroms :  ";
                    int n;
                    cin >> n;
                    c.palindrom(n);
                    index++;
                    cout << "wanna continue with this Cell or you want to creat new one or exit?(this/new/exit)  ";
                    cin >> continu;
                }
            }
        }
        while (a == 3 and continu == "new")
        {
            cout << "Which option do you want?" << endl
                 << " 1) Percentage of genetic similarity." << endl
                 << " 2) Detecting being same kind." << endl
                 << " 3) Non-sexual reproduction." << endl
                 << " 4) sexual reproduction." << endl
                 << " 5) Delete wrong Cromozoms." << endl;
            int x;
            cin >> x;
            continu = "this";
            while (continu == "this")
            {
                if (x == 1)
                {
                    animal use;
                    cout << "How many Cromozoms you want that your first Animal have?  ";
                    int n1;
                    cin >> n1;
                    cout << "How many Cromozoms you want that your second Animal have?  ";
                    int n2;
                    cin >> n2;
                    cout << "Fist Animal :" << endl;
                    Cell c1(n1);
                    cout << "Second Animal :" << endl;
                    Cell c2(n2);
                    cout << use.Simi(c1, c2) << endl;
                    cout << "wanna continue with a new Animal or exit?(new/exit)  ";
                    cin >> continu;
                }
                else if (x == 2)
                {
                    animal a1, a2;
                    cout << "How many Cromozoms you want that your first Animal have?  ";
                    int n1;
                    cin >> n1;
                    cout << "How many Cromozoms you want that your second Animal have?  ";
                    int n2;
                    cin >> n2;
                    cout << "Fist Animal :" << endl;
                    a1.c.cell(n1);
                    cout << "Second Animal :" << endl;
                    a2.c.cell(n2);
                    if (a1 == a2)
                    {
                        cout << "True" << endl;
                    }
                    else
                    {
                        cout << "False" << endl;
                    }
                    cout << "wanna continue with a new Animal or exit?(new/exit)  ";
                    cin >> continu;
                }
                else if (x == 3)
                {
                    animal a;
                    cout << "How many Cromozoms you want that your Animal have?  ";
                    int n1;
                    cin >> n1;
                    a.c.cell(n1);
                    cout << "wanna continue with a new Animal or exit?(new/exit)  ";
                    cin >> continu;
                }
                else if (x == 4)
                {
                    animal a1;
                    animal a2;
                    animal use;
                    cout << "How many Cromozoms you want that your first Animal have?  ";
                    int n1;
                    cin >> n1;
                    cout << "How many Cromozoms you want that your second Animal have?  ";
                    int n2;
                    cin >> n2;
                    cout << "Fist Animal :" << endl;
                    a1.c.cell(n1);
                    cout << "Second Animal :" << endl;
                    a2.c.cell(n2);
                    use.tolidmesljensi(a1, a2);
                    cout << "wanna continue with a new Animal or exit?(new/exit)  ";
                    cin >> continu;
                }
                else if (x == 5)
                {
                    animal a;
                    cout << "How many Cromozoms you want that your Animal have?  ";
                    int n1;
                    cin >> n1;
                    a.c.cell(n1);
                    a.deletingcromo(a);
                    cout << "wanna continue with a new Animal or exit?(new/exit)  ";
                    cin >> continu;
                }
            }
        }
        while (a == 4 and continu == "new")
        {
            char check;
            cout << "Do you want to detect dangrous viruses?(y/n)  ";
            cin >> check;
            if (check == 'y')
            {
                cout << "How many virus you want to have?  ";
                int n;
                cin >> n;
                virus v(n);
                v.illness();
                cout << "wanna continue with a new Virus and Animal or exit?(new/exit)  ";
                cin >> continu;
            }
            else
            {
                break;
            }
        }
    }
    return 0;
}