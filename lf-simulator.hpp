#include <vector>

class ProductOrder;
class Company;

class Contract
{
public:
    int duration;
    int maxDuration;
    int maxPrice;
    int contractType;

public:
    ~Contract();
};

class Machine
{
public:
    int deliveryTime;
    int resaleValue;
    int purchaseValue;
    int meanTimeProcess;

    Machine operator++(); // updates the machine'state
};

class Machine1 : Machine
{
};
class Machine3 : Machine
{
};
class
    Machine2 : Machine
{
private:
    int meanTimeProcessBis;
};

class MachineDate1 : Machine1
{
public:
    int date;
};
class MachineDate2 : Machine2
{
public:
    int date;
};
class MachineDate3 : Machine3
{
public:
    int date;
};

class ProductOrder
{
public:
    int setNumber;
    int issueDate;
    Contract* pContract;
    Company* pCompany;

    ProductOrder();
    ~ProductOrder(); // updates company funds when destoyed
    int getPrice();
};

class Company
{
public:
    int funds;
    std::vector<Machine1> machines1;
    std::vector<Machine2> machines2;
    std::vector<Machine3> machines3;
    std::vector<MachineDate1> machine1Orders;
    std::vector<MachineDate2> machine2Orders;
    std::vector<MachineDate3> machine3Orders;

    // Kit orders (input)
    int kitOrderThreshold;
    int kitOrderSize;

    // Products limit (output)
    int orderLimit;

    int kitStock;

    // Orders
    bool ongoingMachineOrder = false;
    bool ongoingKitOrder = false;
    unsigned int kitOrderDate;
    unsigned int kitOrderNumber;

public:
    void setOrderThreshold();
    void addOrders(int nb, int date);
    void newKitOrder(int nb, int date);
    void newMachineOrder(int machineType, int date);
    void newMachine1();
    void newMachine2();
    void newMachine3();
    void sellMachine1();
    void sellMachine2();
    void sellMachine3();
};

extern int date;