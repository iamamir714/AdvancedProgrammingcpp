#include <fstream>
#include <math.h>
#include "signup-login.cpp"
#include "user.cpp"
using namespace std;


class Customer : public user
{
public:
    // constructor
    Customer();
    Customer(string, string, double, int, string, string, string);
    // customer's functions
    void balance();
    void increse(Customer l[]);
    void withdraw();
    int userSearch(Customer l[], string u);
    void transferMoney(Customer l[]);
    void tax(double tcash);
};

Customer::Customer() : user() {
    setType("C");
    username = "username";
    password = "password";
    setCredit(0);
    setCount(0);
    setName("name");
    setInviter("none");
    setStatus("active");
}
Customer::Customer(string username, string password, double credit, int countOfActivities, string name, string inviter, string status) : user()
{
    setType("C");
    this -> username = username;
    this -> password = password;
    setCredit(credit);
    setCount(countOfActivities);
    setName(name);
    setInviter(inviter);
    setStatus(status);
}

void Customer::balance() {
    cout << "Credit: " << getCredit() << endl;
    report(SLusername, "Balance", "none", to_string(getCredit()), currentDateTime());
}
void Customer::increse(Customer l[])
{
    double increaseAmount;
    cout << "Enter the amount of money you want to add to your credit." << endl;
    cin >> increaseAmount;
    increaseAmount = (increaseAmount > 0) ? increaseAmount : -increaseAmount;
    setCredit(getCredit() + increaseAmount);
    cout << "Success!" << endl;
    setCount(getCount() + 1);
    if (getCount() > 5)
        tax(increaseAmount);
    // bonus
    double cash = increaseAmount * 2 / 100;
    int tempIndex = userSearch(l, getInviter());
    if (tempIndex >= 0)
        l[tempIndex].setCredit(l[tempIndex].getCredit() + cash);
    report(SLusername, "Increse", "none", to_string(increaseAmount), currentDateTime());
}
void Customer::withdraw()
{
    int draw;
    cout << "Enter the amount of money you want to withdraw." << endl;
    cin >> draw;
    draw = fabs(draw);
    if (draw <= getCredit())
    {
        setCredit(getCredit() - draw);
        cout << "Success!" << endl;
    }
    else
        cout << "You do not have enough money." << endl;
    setCount(getCount() + 1);
    if (getCount() > 5)
        tax(draw);
    report(SLusername, "Withdraw", "none", to_string(draw), currentDateTime());
}
void Customer::transferMoney(Customer l[])
{
    double transMoney;
    string targetUser;
    string tempUsername;
    cout << "Enter the Username of the Acount you want to tranfer to: ";
    cin >> targetUser;
    cout << "Enter the amount of money you want to transfer: ";
    cin >> transMoney;
    transMoney = (transMoney >= 0) ? transMoney : -transMoney;
    int index = userSearch(l, targetUser);
    if (index >= 0)
    {
        if (getCredit() >= transMoney)
        {
            setCredit(getCredit() - transMoney);
            l[index].setCredit(l[index].getCredit() + transMoney);
            cout << "Success!" << endl;
            if (getCount() > 5)
                tax(transMoney);
            double cash = transMoney * 2 / 100;
            int tempIndex = userSearch(l, l[index].getInviter());
            if (tempIndex >= 0) {
            l[tempIndex].setCredit(l[tempIndex].getCredit() + cash);
            }
        }
        else
        {
            cout << "You do not have enough credit to transfer." << endl;
        }
        report(SLusername, "Transfer", targetUser, to_string(transMoney), currentDateTime());
    }
    else
    {
        cout << "User was not found." << endl;
    }
    setCount(getCount() + 1);
}

void Customer::tax(double tcash)
{
    if (type == "C") {
    tcash /= 100;
    setCredit(getCredit() - tcash);
    if (getCredit() < 0)
        setStatus("blocked");
    }
    else if (type == "CE" && tcash > 1000000) {
        tcash /= 100;
        setCredit(getCredit() - tcash);
        if (getCredit() < 0)
            setStatus("blocked");
    }
}
int Customer::userSearch(Customer l[], string u)
{
    for (int i = 0; i < 10; i++)
        if (l[i].username == u)
            return i;
    return -1;
}


Customer list[100];

/*int main()
{
    
    list[1].username = "a";
    list[0].setInviter("a");
    list[0].setCredit(100);
    list[0].transferMoney(list);
    cout << list[0].getCredit() << ' ' << list[1].getCredit() << endl;

}*/
