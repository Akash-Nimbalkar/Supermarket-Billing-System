// Supermarket Billing system (~Akash Nimbalkar)
#include <iostream>
#include <fstream>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float discount;
    string pname;

public:
    void menu();
    void administration();
    void buyer();
    void add();
    void list();
    void receipt(int a, string b);
    ~shopping()
    {
        cout << "\n\n Destructor is called...Memory is deallocated\n\n"
             << endl;
    }
};
void shopping ::menu()
{

    int choice;
    string email;
    string password;

    cout << "..............Super Market Main Menu................\n\n";
    cout << "1) Administrator\n";
    cout << "2) Buyer\n";
    cout << "3) Exit\n";
    cout << "Please Select!\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Please Login\n";
        cout << "Enter Email\n";
        cin >> email;
        cout << "Enter Password\n";
        cin >> password;

        if (email == "akash@gmail.com" && password == "akash@123")
        {
            administration();
        }
        else
        {
            cout << "Invalid Email or Password";
        }
        break;

    case 2:
        buyer();
        break;

    case 3:
        exit(0);
        break;

    default:
        cout << "Please Select from the given options";
    }
}
void shopping ::administration()
{

    int choice;
    cout << "............Administration menu............\n";
    cout << "1)Add the product\n";
    cout << "2)Back to main menu\n";
    cout << "Please enter your choice\n";

    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        menu();
        break;

    default:
        cout << "Invalid Choice";
    }
}
void shopping ::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "Add new product\n";
    cout << "Product code of the product\n";
    cin >> pcode;
    cout << "Name of the product\n";
    cin >> pname;
    cout << "Price of the product\n";
    cin >> price;
    cout << "Enter the discount\n";
    cin >> discount;

    data.open("Database.txt", ios::in);
    if (!data)
    {
        data.open("Database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        { 
            if (c == pcode)
            {
                token++; 
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }

    if (token == 1)
        goto m;
    else
    {
        data.open("Database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
    }
    cout << "\n\n\t\t Record inserted !";
}
void shopping ::buyer()
{

    int choice;
    cout << "..........Buyer...........\n";
    cout << "1)Buy Product\n";
    cout << "2)Go Back\n";
    cout << "Enter your choice :\n";

    cin >> choice;

    switch (choice)
    {

    case 1:
        cout << " Showing list of available products\n"
             << endl;
        list();
        break;

    case 2:
        menu();
        break;
    default:
        cout << "Invalid Choice\n";
    }
}
void shopping ::receipt(int a, string b)
{
    if (b == "DairyMilk")
    {
        cout << "You purchased product " << b << " having price 80Rs.\n"
             << endl;
        cout << "Please pay 80 Rs. at the cash counter\n"
             << endl;
    }
    else
    {
        cout << "You purchased product " << b << " having price 25Rs.\n"
             << endl;
        cout << "Please pay 25 Rs. at the cash counter\n"
             << endl;
    }
    cout << "\t\t Thank You\n\n";
}
void shopping ::list()
{

    int prod_code;
    string prod_name;
    cout << " Check Database is opened or not\n"
         << endl;
    cout << "Enter product code & name of product\n";
    cin >> prod_code >> prod_name;
    receipt(prod_code, prod_name);
}

int main()
{

    shopping p;
    p.menu();
    return 0;
}