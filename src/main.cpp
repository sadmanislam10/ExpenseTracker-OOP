#include <iostream>
#include <string>

using namespace std;

enum class Category
{
    Food,
    Transport,
    Rent,
    Other
};

string categoryToString(Category c)
{
    switch (c)
    {
    case Category::Food:
        return "Food";
    case Category::Transport:
        return "Transport";
    case Category::Rent:
        return "Rent";
    default:
        return "Other";
    }
}

class Expense
{
private:
    double amount;
    Category category;
    static int count;

public:
    Expense(double am, Category cat) : amount(am), category(cat) { count++; }

    void show() const
    {
        cout << "Amount: " << amount << endl;
        cout << "Category: " << categoryToString(category) << endl;
    }

    double getAmount() const
    {
        return amount;
    }

    Category getCategory() const
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
    }
};

int Expense::count = 0;

int main()
{
    Expense e1(150.5, Category::Food);

    e1.show();

    e1.setAmount(200);
    e1.setAmount(-50);

    cout << e1.getAmount() << endl;

    Expense e3(50, Category::Other);
    e3.show();

    e3.setAmount(100);

    cout << Expense::getCount() << endl;

    {
        Expense temp(10,Category::Transport);
        cout << Expense::getCount() << endl;
    }

    cout << Expense::getCount() << endl;

    return 0;
}