#include <iostream>
#include <unordered_map>
using namespace std;

class Warehouse {
private:
    string name;
    unordered_map<string, int> inventory;
    static int totalItemsStored;

public:
    Warehouse(string name) : name(name) {}

    bool addItem(string item, int quantity) {
        if (quantity > 0) {
            inventory[item] += quantity;
            totalItemsStored += quantity;
            return true;
        }
        return false;
    }

    bool removeItem(string item, int quantity) {
        if (inventory.count(item) && inventory[item] >= quantity && quantity > 0) {
            inventory[item] -= quantity;
            totalItemsStored -= quantity;
            if (inventory[item] == 0) {
                inventory.erase(item);
            }
            return true;
        }
        return false;
    }

    static int getTotalItemsStored() {
        return totalItemsStored;
    }
};

// Initialize the static variable
int Warehouse::totalItemsStored = 0;

int main() {
    Warehouse w1("Warehouse A");
    Warehouse w2("Warehouse B");

    if (w1.addItem("Laptops", 50)) {
        cout << "Added 50 Laptops to Warehouse A\n";
    }

    if (w2.addItem("Monitors", 30)) {
        cout << "Added 30 Monitors to Warehouse B\n";
    }

    if (w1.removeItem("Laptops", 10)) {
        cout << "Removed 10 Laptops from Warehouse A\n";
    }

    cout << "Total items stored across all warehouses: " << Warehouse::getTotalItemsStored() << endl;
    return 0;
}
