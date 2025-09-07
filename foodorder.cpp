#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

class MenuItem {
public:
    int id;
    string name;
    float price;

    MenuItem(int i, string n, float p) {
        id = i;
        name = n;
        price = p;
    }

    void display() {
        cout << setw(3) << id << "  " << setw(15) << name << "  Rs. " << fixed << setprecision(2) << price << endl;
    }
};

class Order {
private:
    vector<MenuItem> menu;
    vector<MenuItem> cart;
    string customerName;
public:
    Order() {
        menu.push_back(MenuItem(1, "Pizza", 180.0));
        menu.push_back(MenuItem(2, "Burger", 90.0));
        menu.push_back(MenuItem(3, "Pasta", 120.0));
        menu.push_back(MenuItem(4, "Fries", 60.0));
        menu.push_back(MenuItem(5, "Cold Drink", 40.0));
    }

    void takeCustomerInfo() {
        cout << "Enter your name: ";
        getline(cin, customerName);
    }

    void showMenu() {
        cout << "\n--- MENU ---\n";
        for (auto &item : menu) {
            item.display();
        }
    }

    void placeOrder() {
        int choice;
        do {
            showMenu();
            cout << "Enter item number to add to cart (0 to finish): ";
            cin >> choice;

            if (choice == 0)
                break;

            bool found = false;
            for (auto &item : menu) {
                if (item.id == choice) {
                    cart.push_back(item);
                    cout << item.name << " added to your cart.\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Invalid item ID!\n";

        } while (true);
    }

    void generateBill() {
        float total = 0;
        cout << "\n===== BILL =====\n";
        cout << "Customer: " << customerName << "\n";
        cout << "Items Ordered:\n";
        for (auto &item : cart) {
            cout << "- " << item.name << " : Rs. " << item.price << endl;
            total += item.price;
        }
        cout << "--------------------------\n";
        cout << "Total Amount: Rs. " << total << endl;
    }
};

int main() {
    Order myOrder;
    cin.ignore();  // To fix getline() issue after cin
    myOrder.takeCustomerInfo();
    myOrder.placeOrder();
    myOrder.generateBill();
    return 0;
}
