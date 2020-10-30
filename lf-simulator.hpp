#include <vector>

class Contract
{
private:
    int delai_engagement;
    int delai_max;
    int prix_max;
    int num_contrat;

public:
    void getPrice();
};

class Machine
{
private:
    int deliveryTime;
    int resaleValue;
    int purchaseValue;
    int meanTimeProcess;
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
private:
    int date;
};
class MachineDate2 : Machine2
{
private:
    int date;
};
class MachineDate3 : Machine3
{
private:
    int date;
};

class Company
{
private:
    int funds;
    std::vector<Machine1> machines1;
    std::vector<Machine2> machines2;
    std::vector<Machine3> machines3;
    std::vector<MachineDate1> machine1Orders;
    std::vector<MachineDate2> machine2Orders;
    std::vector<MachineDate3> machine2Orders;
    int orderThreshold;
    int orderSize;

public:
    void setOrderThreshold();
    void addOrders(int nb, int date);
    void newKitOrder(int nb, int date);
    void newMachineOrder(int machineType, int date);
    void newMachine1();
    void newMachine2();
    void newMachine3();
};

