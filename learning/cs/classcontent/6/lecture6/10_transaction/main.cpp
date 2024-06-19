#include <iostream>
#include <cstring>
using namespace std;

struct Transaction {
    char product[80];
    int    quantity;
    double unitPrice;
};

Transaction createTrans(char *prod, int quantity, double price)
{
    Transaction t;
    strcpy(t.product, prod);
    t.quantity = quantity;
    t.unitPrice = price;
    return t;
}

double getTotalPrice(const Transaction &t)
{
    return t.quantity * t.unitPrice;
}

void printTrans(const Transaction &t)
{
    cout << "Product: '" << t.product
        << "', Quantity: " << t.quantity
        << ", Unit Price: " << t.unitPrice
        << ", Total Price: " << getTotalPrice(t) << endl;
}

int main()
{
    Transaction t = createTrans("Bubble Tea", 15, 10.99);
    printTrans(t);

    return 0;
}
