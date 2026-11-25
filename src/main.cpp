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

    double getAmount() const
    {
        return amount;
    }

    string getCategory() const
    {
        return category;
    }

    void setAmount(double am)
    {
        if (am > 0)
        {
            amount = am;
        }
    }
};

int main()
{
    Expense e1(150.5, "Food");

    e1.show();

    e1.setAmount(200);
    e1.setAmount(-50);

    cout << e1.getAmount() << endl;

    Expense e3(50, "Bus");
    e3.show();

    e3.setAmount(100);



    return 0;
}