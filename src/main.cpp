#include <iostream>
#include <string>

using namespace std;

class Expense
{
private:
    double amount;
    string category;

public:
    Expense(double am, string cat) : amount(am), category(cat) {}

    void show() const
    {
        cout << "Amount: " << amount << endl;
        cout << "Category: " << category << endl;
    }
};

int main()
{
    Expense e1(150.5, "Food");

    e1.show();

    return 0;
}