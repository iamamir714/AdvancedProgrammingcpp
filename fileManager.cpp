
#include "customer.cpp"
using namespace std;

int countOfUsers()
{
    int count = 0;
    fstream f("Accounts.txt");
    while (f >> t >> u >> p >> c >>co >> n >> i >> s)
        count++;
    f.close();
    return count;
}

void readFile(Customer list[]) {
    int tempCount = 0;
    ifstream f1("Accounts.txt");
    while (f1 >> t >> u >> p >> c >> co >> n >> i >> s)
    {
        list[tempCount].type = t;
        list[tempCount].username = u;
        list[tempCount].password = p;
        list[tempCount].setCredit(stod(c));
        list[tempCount].setName(n);
        list[tempCount].setCount(stod(co));
        list[tempCount].setInviter(i);
        list[tempCount].setStatus(s);
        tempCount++;
    }
    f1.close();
}

void updateFile (Customer list[], int count) {
    ofstream f2("Accounts.txt");
    for (int j = 0; j < count; j++)
    {
        f2 << list[j].type << ' ' << list[j].username << ' ' << list[j].password << ' ' << list[j].getCredit() << ' ' << list[j].getCount() << ' ' << list[j].getName() << ' ' << list[j].getInviter() << ' ' << list[j].getStatus() << endl;
    }
    f2.close();
} 