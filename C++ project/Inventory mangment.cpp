#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    float price;
};

vector<Item> inventory;

void loadFromFile() {
    ifstream file("inventory.txt");
    if (file.is_open()) {
        Item item;
        while (file >> item.id >> item.name >> item.quantity >> item.price) {
            inventory.push_back(item);
        }
        file.close();
    }
}

void saveToFile() {
    ofstream file("inventory.txt");
    for (const auto& item : inventory) {
        file << item.id << " " << item.name << " " << item.quantity << " " << item.price << endl;
    }
    file.close();
}

void addItem() {
    Item item;
    cout << "Enter item ID: "; cin >> item.id;
    cout << "Enter item name: "; cin >> item.name;
    cout << "Enter quantity: "; cin >> item.quantity;
    cout << "Enter price: "; cin >> item.price;
    inventory.push_back(item);
    cout << "Item added successfully.\n";
}

void updateItem() {
    int id;
    cout << "Enter item ID to update: "; cin >> id;
    for (auto& item : inventory) {
        if (item.id == id) {
            cout << "Enter new name: "; cin >> item.name;
            cout << "Enter new quantity: "; cin >> item.quantity;
            cout << "Enter new price: "; cin >> item.price;
            cout << "Item updated.\n";
            return;
        }
    }
    cout << "Item not found.\n";
}

void deleteItem() {
    int id;
    cout << "Enter item ID to delete: "; cin >> id;
    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i].id == id) {
            inventory.erase(inventory.begin() + i);
            cout << "Item deleted.\n";
            return;
        }
    }
    cout << "Item not found.\n";
}

void searchItem() {
    int id;
    cout << "Enter item ID to search: "; cin >> id;
    for (const auto& item : inventory) {
        if (item.id == id) {
            cout << "ID: " << item.id << ", Name: " << item.name
                 << ", Qty: " << item.quantity << ", Price: " << item.price << endl;
            return;
        }
    }
    cout << "Item not found.\n";
}

void displayItems() {
    cout << left << setw(10) << "ID" << setw(15) << "Name"
         << setw(10) << "Quantity" << setw(10) << "Price" << endl;
    cout << "--------------------------------------------------\n";
    for (const auto& item : inventory) {
        cout << left << setw(10) << item.id << setw(15) << item.name
             << setw(10) << item.quantity << setw(10) << item.price << endl;
    }
}

int main() {
    loadFromFile();
    int choice;
    do {
        cout << "\n===== Inventory Management System =====\n";
        cout << "1. Add Item\n2. Update Item\n3. Delete Item\n4. Search Item\n5. Display All Items\n6. Save & Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addItem(); break;
            case 2: updateItem(); break;
            case 3: deleteItem(); break;
            case 4: searchItem(); break;
            case 5: displayItems(); break;
            case 6: saveToFile(); cout << "Data saved. Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
    return 0;
}
