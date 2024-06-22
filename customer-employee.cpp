#include "employe.cpp"

class CustomerEmployee : public Customer , public Employee {
    public:
    CustomerEmployee() : Customer(), Employee() {
        Employee::type = "CE";
    }
};

/*int main() {
    CustomerEmployee ce;

    list[1].username = "a";
    list[0].setInviter("b");
    list[0].setCredit(100);

    ce.Customer::username = "mmd";
    ce.Customer::setCredit(2000000);
    ce.Customer::setCount(10);
    ce.transferMoney(list);
    cout << ce.Customer::getCredit() << endl;
}*/