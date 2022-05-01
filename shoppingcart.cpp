#include <iostream>
#include <cstring>
using namespace std;

int ind = 0;
void mainMenu();

void menu();
// parent class
class Item
{
public:
    string item_id;
    string item_name;
    int item_quantity;
    int item_price;
    string item_category;
    // void add_item();
    void display_cart(int i)
    {
        cout << i << "\t" << item_id << "\t" << item_name << "\t" << item_category << "\t" << item_quantity << "\t" << item_price << "\n";
    }
    void checkout();
    // void remove_item();
    void add_cart(string id, string name, string category, int quantity, int price)
    {
        item_id = id;
        item_name = name;
        item_category = category;
        item_quantity = quantity;
        item_price = price;
    }
};
Item I[20];
void Item::checkout()
{
    double total_price = 0;
    cout << "*****FINAL BILL*****\n";
    cout << "ITEM ID \t ITEM NAME \t ITEM CATEGORY \t ITEM QUANTITY \t ITEM PRICE\n";
    for (int i = 0; i < ind; i++)
    {
        I[i].display_cart(i + 1);
        total_price += I[i].item_price;
    }
    cout << "\nTOTAL AMOUNT: Rs " << total_price;
}

class Grocery : protected Item
{
public:
    string grocery_names[3] = {"sugar", "salt", "rice"};
    double grocery_price[3] = {50, 20, 60};
    string grocery_item_id[3] = {"G01", "G02", "G03"};
    Grocery()
    {
        cout << "Items available in grocery category: \n";
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << "\t" << grocery_names[i] << "\t" << grocery_price[i] << "\n";
        }
    }
    void add_item()
    {
        int ch;
        while (1)
        {

            cout << "Enter your choice:";
            cin >> ch;
            if (ch < 0 || ch > 3)
                cout << "Wrong choice\n";
            else
                break;
        }
        item_name = grocery_names[ch - 1];
        item_id = grocery_item_id[ch - 1];
        item_category = "Grocery";
        cout << "Enter the quantity of " << item_name << " to be purchased: ";
        cin >> item_quantity;
        item_price = item_quantity * grocery_price[ch - 1];
        cout << item_name << " costing Rs " << grocery_price[ch - 1] << " added to the cart";
        I[ind].add_cart(item_id, item_name, item_category, item_quantity, item_price);
        ind++;
    }
};
class Stationary : protected Item
{
public:
    string stationary_names[3] = {"Pen", "Notebook", "Pencil"};
    double stationary_price[3] = {10, 50, 5};
    string stationary_item_id[3] = {"S01", "S02", "S03"};
    Stationary()
    {
        cout << "Items available in stationary category: \n";
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << " " << stationary_names[i] << "\t" << stationary_price[i] << "\n";
        }
    }
    void add_item()
    {
        int ch;
        while (1)
        {
            cout << "Enter your choice:";
            cin >> ch;
            if (ch < 0 || ch > 3)
                cout << "Wrong choice\n";
            else
                break;
        }
        item_name = stationary_names[ch - 1];
        item_id = stationary_item_id[ch - 1];
        item_category = "Stationary";
        cout << "Enter the quantity of " << item_name << " to be purchased: ";
        cin >> item_quantity;
        item_price = item_quantity * stationary_price[ch - 1];
        cout << item_name << " costing Rs " << stationary_price[ch - 1] << " added to the cart";
        I[ind].add_cart(item_id, item_name, item_category, item_quantity, item_price);
        ind++;
    }
};

int main()
{
    // Item I[5];
    mainMenu();
}

void mainMenu()
{
    int ch1;

    while (1)
    {
        cout << "*****MAIN MENU*****\n\n";
        cout << "1. Add Item\n2. Display Cart\n3. Checkout\n";
        cout << "Enter your choice: ";
        cin >> ch1;
        switch (ch1)
        {
        case 1:
            menu();
            break;
        case 2:
            cout << "ITEM ID \t ITEM NAME \t ITEM CATEGORY \t ITEM QUANTITY \t ITEM PRICE\n";
            for (int i = 0; i < ind; i++)
            {
                I[i].display_cart(i + 1);
            }
            break;
        case 3:
            I[0].checkout();
            break;
        default:
            cout << "Wrong choice";
            break;
        }
    }
}
void menu()
{
    int ch;
    cout << "Category of items available:\n";
    cout << " 1.Grocery \n 2.Stationary\n";
    cout << "Enter your choice:";
    cin >> ch;
    char choice;
    switch (ch)
    {
    case 1:
        while (1)
        {
            Grocery G;
            G.add_item();
            cout << "\nWant to add more Grocery(Y/N)?";
            cin >> choice;
            if (choice == 'N')
                break;
        }
        break;
    case 2:
        while (1)
        {
            Stationary S;
            S.add_item();
            cout << "\nWant to add more Stationary(Y/N)?";
            cin >> choice;
            if (choice == 'N')
                break;
        }
        break;
    default:
        cout << "Wrong choice\n";
        break;
    }
}