#include "lf-simulator.hpp"

int ProductOrder::getPrice()
{
    float price;
    float fulfillingTime = (float)date - (float)issueDate;
    float duration = pContract->duration;
    float maxDuration = pContract->maxDuration;
    float maxPrice = pContract->maxPrice;
    if (fulfillingTime < duration)
    {
        price = maxPrice;
    }
    else if (fulfillingTime <= maxDuration)
    {

        price = (1 - (fulfillingTime - duration) / (maxDuration - duration)) * maxPrice;
    }
    else
    {
        price = 0;
    }
    return (int)price;
}

ProductOrder::~ProductOrder() {
    pCompany->funds += getPrice();
}

void updateProdChain() {

}

void goForward(Company company)
{
    if (company.ongoingMachineOrder)
    {
        if (company.machine1Orders.size() && company.machine1Orders.back().date == date)
        {
            company.newMachine1();
            company.machine1Orders.pop_back();
        }
        if (company.machine2Orders.size() && company.machine2Orders.back().date == date)
        {
            company.newMachine2();
            company.machine2Orders.pop_back();
        }
        if (company.machine3Orders.size() && company.machine3Orders.back().date == date)
        {
            company.newMachine3();
            company.machine3Orders.pop_back();
        }
        company.ongoingMachineOrder = (bool)(company.machine1Orders.size() + company.machine2Orders.size() + company.machine3Orders.size());
    }
    if (company.ongoingKitOrder && company.kitOrderDate == date) {
        company.kitStock += company.kitOrderNumber;
        company.ongoingKitOrder = false;
    }
    updateProdChain();
}

int main(int argc, char *argv[])
{
    Company company;
    int startTime = 0;
    int endTime = 0;

    for (date = 0; date < 0; date++)
    {
        // Counting minutes
        if (!date % (24 * 60))
        {
            // First minute of the day
            company.funds = company.funds * (1.0 + 1.0 / 3650) - 3.0 / 3650 * company.kitStock * 10;
        }
        goForward();
    }
}
