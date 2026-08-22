#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std; 

struct Expense {
    int id;
    string category;
    double amount;
    string description;
};

const string FILE_NAME = "Expenditures.txt";

void loadExpenses(vector<Expense>& expenses, int& nextId) {
    ifstream file(FILE_NAME);
    if (!file.is_open()) {
        return;
    }

    string line;
    int maxId = 0;

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string idStr, category, amountStr, description;

        // Parse pipe-separated format: ID|Category|Amount|Description
        if (getline(ss, idStr, '|') &&
            getline(ss, category, '|') &&
            getline(ss, amountStr, '|') &&
            getline(ss, description)) {

            Expense exp;
            exp.id = stoi(idStr);
            exp.category = category;
            exp.amount = stod(amountStr);
            exp.description = description;

            expenses.push_back(exp);

            if (exp.id > maxId) {
                maxId = exp.id;
            }
        }
    }

    file.close();
    nextId = maxId + 1;
}

void saveExpenses(const vector<Expense>& expenses) {
    ofstream file(FILE_NAME, ios::trunc);
    if (!file.is_open()) {
        cerr << "Error opening file for writing!\n";
        return;
    }

    for (const auto& exp : expenses) {
        file << exp.id << "|"
             << exp.category << "|"
             << fixed << setprecision(2) << exp.amount << "|"
             << exp.description << "\n";
    }

    file.close();
}

void displayMenu() {
    cout << "\n=== Personal Expense Tracker (Persistent) ===\n";
    cout << "1. Add Expense\n";
    cout << "2. View All Expenses\n";
    cout << "3. Calculate Total Spending\n";
    cout << "4. Exit\n";
    cout << "Enter choice (1-4): ";
}

int main() {
    vector<Expense> expenses;
    int nextId;
    loadExpenses(expenses, nextId);
    cout << "Loaded " << expenses.size() << " saved expense(s) from " << FILE_NAME << "\n";

    int choice = 0;

    while (choice != 4) {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            Expense temp;
            temp.id = nextId++;

            cout << "Enter category (e.g. Food, Transport): ";
            cin >> temp.category;

            cout << "Enter amount: Rs";
            cin >> temp.amount;

            cin.ignore(1000, '\n'); // Clear leftover newline
            cout << "Enter brief description: ";
            getline(cin, temp.description); // Supports multi-word descriptions

            expenses.push_back(temp);
            saveExpenses(expenses); // Auto-save
            cout << "Expense added and saved successfully!\n";

        } else if (choice == 2) {
            if (expenses.empty()) {
                cout << "\nNo expenses recorded yet.\n";
            } else {
                cout << "\n------------------- Expense History -------------------\n";
                cout << left << setw(6) << "ID"
                          << setw(16) << "Category"
                          << setw(12) << "Amount"
                          << "Description\n";
                cout << "-------------------------------------------------------\n";

                for (const auto& exp : expenses) {
                    cout << left << setw(6) << exp.id
                              << setw(16) << exp.category
                              << "Rs" << setw(11) << fixed << setprecision(2) << exp.amount
                              << exp.description << "\n";
                }
            }

        } else if (choice == 3) {
            double total = 0.0;
            for (const auto& exp : expenses) {
                total += exp.amount;
            }
            cout << "\nTotal Spending: $" << fixed << setprecision(2) << total << "\n";

        } else if (choice == 4) {
            cout << "\nExiting Expense Tracker. Goodbye!\n";
        } else {
            cout << "Invalid option. Please enter 1-4.\n";
        }
    }

    return 0;
}