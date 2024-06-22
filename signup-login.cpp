#include <iostream>
#include <fstream>
#include "report.cpp"
using namespace std;

string SLusername, SLpassword, SLtype, SLinviter = "none", SLstatus = "active", SLname;
int SLcredit = 0, SLcount = 0;
string t, u, p, c, co, n, i, s;
bool isLogin = false;

void AdminSignup()
{
    fstream f("Accounts.txt", ios::out);
    cout << "Enter Admin's username and password." << endl;
    cin >> SLusername >> SLpassword;
    cout << "Enter Admin's name. (no spaces)" << endl;
    cin >> SLname;
    f << "A" << ' ' << SLusername << ' ' << SLpassword << ' ' << SLcredit << ' ' << SLcount << ' ' << SLname << ' ' << SLinviter << ' ' << SLstatus << endl;
    cout << "Admin account created successfully." << endl;
    f.close();
    report(SLusername, "Signup", "none", "none", currentDateTime());
}

void UserSignup()
{
    SLinviter = "none";
    fstream f("Accounts.txt", ios::app);
    while (1)
    {
        cout << "Choose the type of account: " << endl
             << "C (Customer)" << endl
             << "E (Employee)" << endl
             << "CE (Customer-Employee)" << endl;
        cin >> SLtype;
        if (SLtype != "C" && SLtype != "E" && SLtype != "CE")
            cout << "Please choose one of the mentioned types." << endl;
        else
            break;
    }
    cout << "Enter User's username and password." << endl;
    cin >> SLusername >> SLpassword;
    cout << "Enter the user's name. (no spaces)" << endl;
    cin >> SLname;
    if (SLtype == "C" || SLtype == "CE")
    {
        char YN;
        cout << "Were you invited by one of our customers?" << endl;
        while (1)
        {
            cout << "Enter Y or N." << endl;
            cin >> YN;
            if (YN == 'Y' || YN == 'N')
                break;
        }
        if (YN == 'Y')
        {
            cout << "Enter the inviter's username." << endl;
            cin >> SLinviter;
        }
    }
    f << SLtype << ' ' << SLusername << ' ' << SLpassword << ' ' << SLcredit << ' ' << SLcount << ' ' << SLname << ' ' << SLinviter << ' ' << SLstatus << endl;
    cout << "Account created successfully." << endl;
    f.close();
    report(SLusername, "Signup", "none", "none", currentDateTime());
}

void login()
{   
    isLogin = false;
    SLstatus = "active";
    
    fstream f("Accounts.txt");
    while (1)
    {
        cout << "Enter username and password." << endl;
        cin >> SLusername >> SLpassword;
        while (f >> t >> u >> p >> c >> n >> co >> i >> s)
            if (u == SLusername && p == SLpassword)
            {
                if (s == "blocked")
                {
                    cout << "Your account is blocked." << endl;
                    SLstatus = s;
                }
                else
                {
                    cout << "Login successful!" << endl;
                    isLogin = true;
                    break;
                }
            }
        if (SLstatus == "blocked")
            break;
        else
        {
            if (isLogin)
                break;
            else
            {
                cout << "Username or password is incorrect." << endl;
                break;
            }
        }
    }
    f.close();
    report(SLusername, "Login", "none", "none", currentDateTime());
}

