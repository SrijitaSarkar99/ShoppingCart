#include <iostream>
#include <cstring>
using namespace std;
int ind = 0;
void mainMenu();
int search(string);
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
    void remove_item();
    void search_item();
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
    if (ind == 0)
    {
        cout << "Cart is empty. Please add some items" << endl;
        return;
    }
    double total_price = 0;
    cout << "*****FINAL BILL*****\n";
    cout << "ITEM ID \t ITEM NAME \t ITEM CATEGORY \t ITEM QUANTITY \t ITEM PRICE\n";
    for (int i = 0; i < ind; i++)
    {
        I[i].display_cart(i + 1);
        total_price += I[i].item_price;
    }
    cout << "\nTOTAL AMOUNT: Rs " << total_price;
    cout<<"\nThankyou for shopping...";
    exit(0);
}
void Item::remove_item()
{
    //display_cart(1); //calling to display current item list....
    cout<<"\nEnter the item number to be removed:     ";
    int id;
    cin>>id; //id to be removed....
    for(int i=id-1; i<ind-1; i++){ //shifing the objects...
        I[i]=I[i+1];
    }
    --ind;
    cout<<"\n Item removed...\n";
    //display_cart();
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
    void add_item(int ch)
    {
        // int ch;
        // while (1)
        // {

        //     cout << "Enter your choice:";
        //     cin >> ch;
        //     if (ch < 0 || ch > 3)
        //         cout << "Wrong choice\n";
        //     else
        //         break;
        // }
        
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
    void add_item(int ch)
    {
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
        cout << "1. Add Item\n2. Display Cart\n3. Remove Item\n4. Checkout\n5.EXIT\n";

        cout << "Enter your choice: ";
        cin >> ch1;
        switch (ch1)
        {
        case 1:
            menu();
            break;
        case 2:
            if (ind == 0)
            {
                cout << "Cart is empty. Please add some items" << endl;
                break;
            }
            cout << "ITEM ID \t ITEM NAME \t ITEM CATEGORY \t ITEM QUANTITY \t ITEM PRICE\n";
            for (int i = 0; i < ind; i++)
            {
                I[i].display_cart(i + 1);
            }
            break;
        case 3:
             I[0].remove_item();
             break;
        case 4:
            I[0].checkout();
            break;
        case 5:
        exit(0);
        default:
            cout << "Wrong choice";
            break;
        }
    }
}
void menu()
{
    int ch;
    while(1){
    cout << "Category of items available:\n";
    cout << " 1.Grocery \n 2.Stationary \n 3. Back to Main menu\n";
    cout << "Enter your choice:";
    cin >> ch;
    char choice;
    switch (ch)
    {
    case 1:
    {
            Grocery G;
            int ch;
        while (1)
        {
            
            cout << "\nEnter your choice:\n";
            cin >> ch;
            if (ch < 0 || ch > 3)
                cout << "Wrong choice\n";
            else
                break;
        }
        int index=search(G.grocery_item_id[ch - 1]);
        if(index==-1){
            
            G.add_item(ch);
            cout << "\nWant to add more items(Y/N)?";
            cin >> choice;
            if (choice == 'N')
                break;
        }
        else{
            int quantity;
        cout << "Enter the final quantity of " << I[index].item_name << " to be purchased: ";
        cin >> quantity;
        I[index].item_quantity+=quantity;
        I[index].item_price=I[index].item_quantity* G.grocery_price[ch - 1];
        cout << G.grocery_names[ch-1] << " costing total Rs " << G.grocery_price[ch - 1] << " added to the cart";
        }
    }
        break;
    case 2:
    {
            Stationary S;
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
        int index=search(S.stationary_item_id[ch - 1]);
        if(index==-1){
            
            S.add_item(ch);
            cout << "\nWant to add more items(Y/N)?";
            cin >> choice;
            if (choice == 'N')
                break;
        }
        else{
            int quantity;
        cout << "Enter the  quantity of " << I[index].item_name << " to be purchased: ";
        cin >> quantity;
        I[index].item_quantity+=quantity;
        I[index].item_price=I[index].item_quantity* S.stationary_price[ch - 1];
        cout << S.stationary_names[ch-1] << " costing total Rs " << S.stationary_price[ch - 1] << " added to the cart";
        }
    }   
        break;
    case 3:
    mainMenu();
    break;
    default:
        cout << "Wrong choice\n";
        
    }
    }
}
int search(string id)

{
    int item_quantity=0;
    for(int i=0;i<ind;i++)
    {
        if(I[i].item_id==id)
        {
        
        return i;
        }
        
    }
    return -1;
    
}