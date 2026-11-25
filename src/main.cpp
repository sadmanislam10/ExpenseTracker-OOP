#include <iostream>
#include <string>

using namespace std;

class Expense
{
private:
    double amount;
    string category;
    static int count;

public:
    Expense(double am, string cat) : amount(am), category(cat) { count++; }

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

    static int getCount()
    {
        return count;
    }

    ~Expense()
    {
        count--;
        cout << "Destroyed " << category << endl;
    }
};

int Expense::count = 0;

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

    cout << Expense::getCount() << endl;

    {
        Expense temp(10, "TEST");
        cout << Expense::getCount() << endl;
    }

    cout << Expense::getCount() << endl;

    return 0;
}