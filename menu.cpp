#include "admin.cpp"
using namespace std;

//menus

void customerMenu(int temptm) {
    Customer ctemp; //
    ctemp.setCredit(list[temptm].getCredit());
    ctemp.setCount(list[temptm].getCount());

    while(1) {
        int choice;
        cout << "Choose an option." << endl << "1. Add money" << endl << "2. Withdraw money" << endl << "3. Transfer money" << endl << "4. Balance" << endl << "5. Logout" << endl;
        cin >> choice;
        if (choice > 0 && choice < 6)
            switch (choice) {
                case 1: 
                    ctemp.increse(list); break;
                case 2: 
                    ctemp.withdraw(); break;
                case 3:
                    ctemp.transferMoney(list); break;
                case 4: 
                    ctemp.balance(); break;
                case 5:
                    isLogin = false; break;
            }
        if (isLogin == false) {
            list[temptm].setCredit(ctemp.getCredit());
            list[temptm].setCount(ctemp.getCount());
            break;
        }
    }
}

void employeeMenu(int temptm) {
    Employee etemp; // inahaaaaaaaa
    while(1) {
        int choice;
        cout << "Choose an option." << endl << "1. Display customers" << endl << "2. Display customers by credit" << endl << "3. Edit a customer's info" << endl << "4. Block a customer's account" << endl << "5. History" << endl << "6. Logout" << endl;
        cin >> choice;
        if (choice > 0 && choice < 7)
            switch (choice) {
                case 1: 
                    etemp.displayCustomers(); break;
                case 2: 
                    etemp.displaySorted(); break;
                case 3:
                    etemp.edit(); break;
                case 4: 
                    etemp.block(); break;
                case 5:
                    etemp.history(); break;
                case 6: 
                    isLogin = false; break;
            }
        if (isLogin == false)
            break;
    }
}

void customerEmployeeMenu(int temptm) {
    CustomerEmployee cetemp;
    cetemp.Customer::setCredit(list[temptm].getCredit());
    cetemp.Customer::setCount(list[temptm].getCount());

    while(1) {
        int choice;
        cout << "Choose an option." << endl << "1. Display customers" << endl << "2. Display customers by credit" << endl << "3. Edit a customer's info" << endl << "4. Block a customer's account" << endl << "5. History" << endl;
        cout << "6. Add money" << endl << "7. Withdraw money" << endl << "8. Transfer money" << endl << "9. Balance" << endl << "10. Logout" << endl;
        cin >> choice;
        if (choice > 0 && choice < 11)
            switch (choice) {
                case 1: 
                    cetemp.displayCustomers(); break;
                case 2: 
                    cetemp.displaySorted(); break;
                case 3:
                    cetemp.edit(); break;
                case 4: 
                    cetemp.block(); break;
                case 5:
                    cetemp.history(); break;
                case 6: 
                    cetemp.increse(list); break;
                case 7: 
                    cetemp.withdraw(); break;
                case 8:
                    cetemp.transferMoney(list); break;
                case 9: 
                    cetemp.balance(); break;
                case 10:
                    isLogin = false; break;
            }
        if (isLogin == false) {
            list[temptm].setCredit(cetemp.Customer::getCredit());
            list[temptm].setCount(cetemp.Customer::getCount());
            break;
        }
    }
}

void adminMenu(int temptm) {
    Admin atemp;
    while(1) {
        int choice;
        cout << "Choose an option." << endl << "1. Random gift" << endl << "2. Delete an account" << endl << "3. Logout" << endl;
        cin >> choice;
        if (choice > 0 && choice < 4)
            switch (choice) {
                case 1: 
                    atemp.randomgift(); break;
                case 2: 
                    atemp.deleteAccount(list); break;
                case 3:
                    isLogin = false; break;
            }
        if (isLogin == false)
            break;
    }
}