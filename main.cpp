
#include "menu.cpp"

int main()
{
    srand(time(0));
    readFile(list);
    int firstChoice;
    fstream fsl("Accounts.txt");
    fsl >> t >> u >> p;
    if (t != "A") {
        AdminSignup();
        fsl.close();
    }
    while (1)
    {
        cout << "-----------------------------------------" << endl;
        cout << "Choose an option." << endl
             << "1. Signup" << endl
             << "2. Login" << endl
             << "3. Exit" << endl;
        cin >> firstChoice;
        switch (firstChoice)
        {
        case 1:
            UserSignup();
            readFile(list);
            break;
        case 2:
            login();
            readFile(list);
            break;
        case 3:
            updateFile(list, countOfUsers());
            exit(0);
        default:
            cout << "Please try again." << endl;
        }
        if (isLogin) {
            fstream ft("Accounts.txt");
            while (ft >> t >> u >> p >> c >> co >> n >> i >> s) {
                if (u == SLusername && t == "A") {
                    adminMenu(obj.userSearch(list, SLusername));
                    break;
                }
                else if (u == SLusername && t == "C") {
                    customerMenu(obj.userSearch(list, SLusername));
                    break;
                }
                else if (u == SLusername && t == "CE") {
                    customerEmployeeMenu(obj.userSearch(list, SLusername));
                    break;
                }
                else if (u == SLusername && t == "E") {
                    employeeMenu(obj.userSearch(list, SLusername));
                    break;
                }
            }
            ft.close();
        }
    }
    return 0;
}