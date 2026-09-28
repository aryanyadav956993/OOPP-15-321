#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Item
{
public:
    string name;
    int quantity;
    double price;
};

void displayCart(const vector<Item>& cart)
{
    cout << "\nShopping Cart\n";

    cout << left << setw(15) << "Item"
         << setw(10) << "Quantity"
         << setw(10) << "Price"
         << setw(15) << "Amount" << endl;

    cout << "\n";

    for (auto item : cart)
    {
        cout << left << setw(15) << item.name
             << setw(10) << item.quantity
             << setw(10) << item.price
             << setw(15) << item.quantity * item.price
             << endl;
    }
}

double calculateTotal(const vector<Item>& cart)
{
    double total = 0;

    for (auto item : cart)
    {
        total += item.quantity * item.price;
    }

    return total;
}

Item findMostExpensiveItem(const vector<Item>& cart)
{
    Item expensive = cart[0];

    for (auto item : cart)
    {
        if (item.price > expensive.price)
        {
            expensive = item;
        }
    }

    return expensive;
}

void applyDiscount(vector<Item>& cart)
{
    for (auto& item : cart)
    {
        if (item.price > 1000)
        {
            item.price = item.price * 0.90;
        }
    }
}

int main()
{
    vector<Item> cart =
    {
        {"Laptop", 1, 55000},
        {"Mouse", 2, 800},
        {"Keyboard", 1, 1500},
        {"Headphones", 2, 2500}
    };

   
    displayCart(cart);

    
    double total = calculateTotal(cart);

    cout << "\nTotal Amount Payable: Rs. "
         << fixed << setprecision(2) << total << endl;

    // Find expensive item
    Item expensive = findMostExpensiveItem(cart);

    cout << "Most Expensive Item: " << expensive.name << endl;
    cout << "Highest Unit Price: Rs. "
         << expensive.price << endl;

    applyDiscount(cart);

    cout << "\nAfter Applying 10% Discount:\n";

    displayCart(cart);

 
    double updatedTotal = calculateTotal(cart);

    cout << "\nUpdated Cart Total: Rs. "
         << updatedTotal << endl;

    return 0;
}