//Libraries
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

//namespaces 
using namespace std;

//Structure to add a Expense
struct Expense {
    int pid;
    string category;
    double amount;
    int date;
    string description;
};

//function to display menu
void Displaymenu(){
    cout<<"Select any Option from below:"<<endl;
    cout<<"1. Enter a new Expense"<<endl;
    cout<<"2. Show total expenditures"<<endl;
    cout<<"3. Calculate all expenditures"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter your Choice(1-4): "<<endl;
}

// Main Function
int main (){
    vector<Expense> expenses;
    int nextId = 1;
    int choice = 0;

}