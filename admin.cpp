
#include "customer-employee.cpp"
#include <time.h>
#include <unistd.h>
using namespace std;


class Admin : public user
{
public:
    Admin() : user() {}
    void deleteAccount(Customer list[])
    {
        int numOfUsers = countOfUsers();

        readFile(list);

        string deleteUser;
        cout << "Enter the username you want to delete." << endl;
        cin >> deleteUser;
        int index = obj.userSearch(list, deleteUser);
        if (index >= 0)
        {
            for (int j = index; j < numOfUsers - 1; j++)
            {
                list[j].type = list[j + 1].type;
                list[j].username = list[j + 1].username;
                list[j].password = list[j + 1].password;
                list[j].setCredit(list[j + 1].getCredit());
                list[j].setName(list[j + 1].getName());
                list[j].setCount(list[j + 1].getCount());
                list[j].setInviter(list[j + 1].getInviter());
                list[j].setStatus(list[j + 1].getStatus());
            }
            updateFile(list, numOfUsers - 1);
            cout << "Account deleted." << endl;
        }
        else
            cout << "User was not found." << endl;
    }
    void randomgift()
    {
        srand(time(0));
        double gift;
        int numOfUsers = countOfUsers();

        readFile(list);

        cout << "Enter the price you want to gift."<<endl;
        cin >> gift;
        while(1) {
            int giftindex = (rand() % (numOfUsers));
            if (list[giftindex].type == "C" || list[giftindex].type == "CE") {
                list[giftindex].setCredit(list[giftindex].getCredit() + gift);
                cout << "Success!" << endl;
                break;
            }
        }

        updateFile(list, numOfUsers);
    }
};

/*int main()
{
    Admin admon;
    admon.randomgift();
}*/
