#include <iostream>
#include <fstream>
#include <string.h>
#include "fileManager.cpp"
using namespace std;

Customer obj;

class Employee : public user
{
public:
    Employee() : user() {};
    Employee(string username, string password, string name) : user() {
        setType("E");
        this -> username = username;
        this -> password = password;
        setCredit(0);
        setCount(0);
        setName(name);
        setInviter("none");
        setStatus("active");
    }
    int countOfCustomers();
    void display();
    void displayCustomers();
    void displaySorted();
    void edit();
    void block();
    void history();
};

int Employee::countOfCustomers()
{
    int count = 0;
    fstream f("Accounts.txt");
    while (f >> t >> u >> p >> c >> co >> n >> i >> s)
        if (t == "C" || t == "CE")
            count++;
    return count;
}
void Employee::display()
{
    cout << username << ' ' << password << endl;
}
void Employee::displayCustomers()
{
    fstream f("Accounts.txt");
    while (f >> t >> u >> p >> c >> co >> n >> i >> s)
    {
        if (t == "C" || t == "CE")
            cout << t << ' ' << u << ' ' << p << ' ' << c << ' ' << co << ' ' << n << ' ' << i << ' ' << s << endl;
    }
    f.close();
    report(SLusername, "Display", "none", "none", currentDateTime());
}
void Employee::displaySorted()
{
    int count = countOfCustomers();
    Customer sortedList[count];
    readFile(sortedList);
    for (int j = 0; j < count; j++)
        for (int k = 0; k < count - j - 1; k++)
            if (sortedList[k].getCredit() < sortedList[k + 1].getCredit())
                swap(sortedList[k], sortedList[k + 1]);
    for (int j = 0; j < count; j++)
        cout << j + 1 << ' ' << sortedList[j].username << ' ' << sortedList[j].getCredit() << endl;
    report(SLusername, "Sort", "none", "none", currentDateTime());
}
void Employee::edit()
{
    int count = countOfUsers();
    string editUser;

    readFile(list);

    while (1)
    {
        cout << "Enter the username." << endl;
        cin >> editUser;
        int index = obj.userSearch(list, editUser);
        if (index >= 0)
        {
            if (list[index].type == "C" || list[index].type == "CE")
            {
                cout << "Enter the new properties." << endl;
                cout << "Username: ";
                cin >> list[index].username;
                cout << "Password: ";
                cin >> list[index].password;
                string tempInviter;
                cout << "Inviter: ";
                cin >> tempInviter;
                list[index].setInviter(tempInviter);
                int tempCredit;
                cout << "Credit: ";
                cin >> tempCredit;
                list[index].setCredit(tempCredit);

                updateFile(list, count);
                break;
            }
            else
                cout << "You do not have access to edit that account." << endl;
        }
        else
            cout << "User was not found." << endl;
    }
    report(SLusername, "Edit", editUser, "none", currentDateTime());
}
void Employee::block() {
    int count = countOfUsers();
    Customer list[count];
    string blockUser;
    int blockIndex;

    readFile(list);

    while(1) {
        cout << "Enter the username you want to block." << endl;
        cin >> blockUser;
        blockIndex = obj.userSearch(list, blockUser);
        if (blockIndex >= 0) {
            if (list[blockIndex].getType() == "C") {
                string choiceBlock;
                cout << "Do you want to block the account?" << endl;
                while (1)
                {
                    cout << "Enter Y or N." << endl;
                    cin >> choiceBlock;
                    if (choiceBlock == "Y")
                    {
                        list[blockIndex].setStatus("blocked");
                        break;
                    }
                    else if (choiceBlock == "N")
                    {
                        list[blockIndex].setStatus("active");
                        break;
                    }
                }
                report(SLusername, "Block", blockUser, choiceBlock, currentDateTime());
                break;
            }
            else
                cout << "Access denied." << endl;
        }
        else
            cout << "User was not found." << endl;
    }

    updateFile(list, count);
}
void Employee::history() {
    string husername, hactivity, htarget, hdetail, htime; 
    fstream fh("Report.txt");
    cout << "History of activities: " << endl;
    while (fh >> husername >> hactivity >> htarget >> hdetail >> htime)
        cout << husername << ' ' << hactivity << ' ' << htarget << ' ' << hdetail << ' ' << htime << endl;
    fh.close();
    report(SLusername, "Report", "none", "none", currentDateTime());
}

/*int main()
{
    Employee cos;
    cos.username = "emp";
    cos.edit();
    cos.history();
}*/