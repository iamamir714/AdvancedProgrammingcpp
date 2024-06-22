#include <iostream>
using namespace std;

//address

struct Address
{
    string city;
    string street;
    string allay;
    double postalCode;
    Address(string, string, string, int);
    void setCode(double);
    void display();
};
Address::Address(string c = "city", string s = "street", string a = "allay", int cod = 0)
{
    city = c;
    street = s;
    allay = a;
    setCode(cod);
}
void Address::setCode(double cod)
{
    postalCode = (cod >= 0) ? cod : -cod;
}
void Address::display()
{
    cout << "City: " << city << endl;
    cout << "Street: " << street << endl;
    cout << "Allay: " << allay << endl;
    cout << "Postal Code: " << postalCode << endl;
}

//date

struct Date
{
    int year;
    int month;
    int day;
    Date(int y, int, int);
    void setY(int);
    void setM(int);
    void setD(int);
    void display();
};
Date::Date(int y = 0, int m = 0, int d = 0)
{
    setY(y);
    setM(m);
    setD(d);
}
void Date::setY(int y)
{
    year = (y >= 0) ? y : -y;
}
void Date::setM(int m)
{
    month = (m >= 0) ? m : -m;
}
void Date::setD(int d)
{
    day = (d >= 0) ? d : -d;
}
void Date::display()
{
    cout << "Year: " << year << endl;
    cout << "Month: " << month << endl;
    cout << "Day: " << day << endl;
}


//user


class user
{
    string name;
    Date dateOfBirth;
    Address address;
    double credit;
    int countOfActivities;
    string inviter;
    string status;
    public:
    string type;
    string username;
    string password;
    user() {
    }
    user(string type, string username, string password, double credit, int countOfActivities, string name, string inviter, string status) {
        this -> type = type;
        this -> username = username;
        this -> password = password;
        this -> credit = credit;
        this -> countOfActivities = countOfActivities;
        this -> name = name;
        this -> inviter = inviter;
        this -> status = status;
    }

    // setter
    void setName(string);
    void setDate(Date);
    void setAddress(Address);
    void setCredit(double);
    void setCount(int);
    void setInviter(string);
    void setStatus(string);
    void setType(string);
    // getter
    string getUsername();
    string getPassword();
    string getName();
    Date getDate();
    Address getAddress();
    double getCredit();
    int getCount();
    string getInviter();
    string getStatus();
    string getType();
};

void user::setName(string n)
{
    name = n;
}
void user::setDate(Date d)
{
    dateOfBirth = d;
}
void user::setAddress(Address a)
{
    address = a;
}
void user::setCredit(double c)
{
    credit = (c >= 0) ? c : -c;
}
void user::setCount(int count)
{
    countOfActivities = (count >= 0) ? count : -count;
}
void user::setInviter(string i) {
    inviter = i;
}
void user::setStatus(string s) {
    status = s;
}
void user::setType(string t) {
    type = t;
}

//getter

string user::getUsername()
{
    return username;
}
string user::getPassword()
{
    return password;
}
string user::getName()
{
    return name;
}
Date user::getDate()
{
    return dateOfBirth;
}
Address user::getAddress()
{
    return address;
}
double user::getCredit()
{
    return credit;
}
int user::getCount()
{
    return countOfActivities;
}
string user::getStatus()
{
    return status;
}
string user::getInviter() {
    return inviter;
}
string user::getType() {
    return type;
}


