#include <iostream>
#include <limits>

using namespace std;

// Constant GST rate (6%)
const double GST_rate = 0.06;

// Array of item names and prices
string item_names[] = {"Orange", "Noodle Cup", "Egg", "Bread", "Yogurt"};
double item_prices[] = {3.50, 5.0, 1.50, 2.00, 2.20};

// Number of items in the store
int num_items = sizeof(item_names) / sizeof(item_names[0]);

// Array to track quantities of items added to the cart
int quantities[5] = {0};

// Function to display the available grocery items
void showGroceryOptions() {
    cout << "===== Fresh Mart Grocery Menu =====\n";
    for (int i = 0; i < num_items; i++) {
        cout << i + 1 << ". " << item_names[i] << " - RM " << item_prices[i] << " per unit\n";
    }
    cout << "===================================\n";
}

// Function to allow users to select items and specify quantity
void additem_tocart() {
    int choice, quantity;

    while (true) {
        cout << "What would you like to buy today? (Enter the item number, or 0 to finish): ";
        cin >> choice;

        // Exit selection if user enters 0
        if (choice == 0)
            break;

        // Validate user input
        if (choice >= 1 && choice <= num_items) {
            cout << "How many (item) would you like to add?: ";
            cin >> quantity;

            if (quantity > 0) {
                // Add selected quantity to the cart
                quantities[choice - 1] += quantity;
                cout << item_names[choice - 1] << " added to cart. Total: "
                     << quantities[choice - 1] << "\n";
            } else {
                cout << "Invalid quantity! Enter a positive number.\n";
            }
        } else {
            cout << "Invalid choice! Please enter a valid product number.\n";
        }
    }
}

// Function to allow users to remove items from the cart
void remove_items() { // #
    int choice, quantity;

    while (true) {
        cout << "Enter product number to remove (0 to stop): ";
        cin >> choice;

        // Exit removal process if user enters 0
        if (choice == 0)
            break;

        // Validate user input and ensure the item is in the cart
        if (choice >= 1 && choice <= num_items && quantities[choice - 1] > 0) {
            cout << "Enter quantity to remove: ";
            cin >> quantity;

            if (quantity > 0) {
                if (quantity > quantities[choice - 1]) {
                    // If user tries to remove more than in the cart, remove all
                    cout << "Cannot remove more than in cart! Removing all.\n";
                    quantities[choice - 1] = 0;
                } else {
                    quantities[choice - 1] -= quantity;
                }

                cout << item_names[choice - 1] << " remaining: "
                     << quantities[choice - 1] << "\n";
            } else {
                cout << "Invalid quantity! Enter a positive number.\n";
            }
        } else {
            cout << "Invalid choice! The cart is empty.\n";
        }
    }
}

// Function to display items in the cart
void view_cart() { // #
    cout << "\n======= Your Cart =======\n";
    bool empty = true;
    for (int i = 0; i < num_items; i++) {
        if (quantities[i] > 0) {
            cout << item_names[i] << " (x" << quantities[i] << ")\n";
            empty = false;
        }
    }
    if (empty) {
        cout << "Your cart is empty!\n";
    }
    cout << "========================\n";
}

// Function to clear all items from the cart
void clear_cart() { // #
    for (int i = 0; i < num_items; i++) {
        quantities[i] = 0;
    }
    cout << "Cart cleared!\n";
}

// Function to handle invalid input
void handleInvalidInput() { // #
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input! Please enter a valid option.\n";
}

// Function to calculate total cost including GST
double calculate_total() {
    double total = 0;
    for (int i = 0; i < num_items; i++) {
        total += item_prices[i] * quantities[i];
    }
    return total + (total * GST_rate);
}

// Function to display an itemized bill with subtotal, GST, and total payable amount
void display_bill() {
    cout << "\n======= Itemized Bill =======\n";
    double total = 0;

    // Display each selected item with quantity and price
    for (int i = 0; i < num_items; i++) {
        if (quantities[i] > 0) {
            double itemTotalCost = item_prices[i] * quantities[i];
            cout << item_names[i] << " (x" << quantities[i] << ") - RM "
                 << itemTotalCost << "\n";
            total += itemTotalCost;
        }
    }

    // Calculate GST and total payable amount
    double GST = total * GST_rate;
    double final_amount = total + GST;

    // Display final bill summary
    cout << "------------------------------\n";
    cout << "Subtotal: RM " << total << endl;
    cout << "GST (6%): RM " << GST << endl;
    cout << "----------------------" << endl;
    cout << "TOTAL: RM " << final_amount << " (including tax)" << endl;
}

// Main function to run the grocery billing system
int main() {
    int choice;
    while (true) {
        cout << "\n===== Main Menu =====\n";
        cout << "1. Show Grocery Items\n";
        cout << "2. Add Items to Cart\n";
        cout << "3. View Cart\n"; // #
        cout << "4. Remove Items\n"; // #
        cout << "5. Clear Cart\n"; // #
        cout << "6. Checkout and Display Bill\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) { // #
            handleInvalidInput();
            continue;
        }

        switch (choice) {
            case 1:
                showGroceryOptions();
                break;
            case 2:
                additem_tocart();
                break;
            case 3:
                view_cart(); // #
                break;
            case 4:
                remove_items(); // #
                break;
            case 5:
                clear_cart(); // #
                break;
            case 6:
                display_bill();
                return 0;
            case 0:
                cout << "Thank you for shopping with Fresh Mart! Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please select a valid option.\n";
        }
    }
}
