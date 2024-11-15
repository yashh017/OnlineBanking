#include <iostream>
#include <string>
#include <cstdlib> // For exit function
using namespace std;

class Account {
public:
    char owner[10];
    int accno;
    int balance;
    char type[10];

    Account(int initial_balance) : balance(initial_balance) {}

    void get_details() {
        cout << "Enter the Account holder's name: ";
        cin >> owner;
        cout << "Enter the account number: ";
        cin >> accno;
        cout << "Enter the type of account you have (savings or current): ";
        cin >> type;
    }

    void display_data() const {
        cout << "The account holder's name is: " << owner << endl;
        cout << "The account number is: " << accno << endl;
        cout << "The account type is: " << type << endl;
        cout << "The current balance is: Rs " << balance << endl;
    }

    void update_balance(int new_balance) {
        balance = new_balance;
    }
};

class Yesno {
public:
    int opr = 0;
    char name[10];
    int balance2;
    int acc = 0;
    int acc2 = 0;
    int acc3 = 0;
    int amount = 0;
    int pin = 0;
    int pin3 = 0;
    int amt = 0;
    const int cor = 1625;
    const int pcor = 4512;
    const int acor = 153768051;

    Yesno(int initial_balance) : balance2(initial_balance) {}

    void pro_data(Account &account) {
        cout << "\nOptions:\n";
        cout << "1. Send money to another person\n";
        cout << "2. Transfer to another account\n";
        cout << "3. Check balance\n";
        cout << "4. Check another account's balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> opr;

        if (opr == 1) {
            cout << "Whom are you sending the money to?: ";
            cin >> name;
            cout << "Enter their account number: ";
            cin >> acc;
            cout << "Enter the amount: ";
            cin >> amount;
            cout << "Enter your 4-digit PIN: ";
            cin >> pin;

            if (pin != cor) {
                cout << "Invalid PIN!" << endl;
            } else if (account.balance < amount) {
                cout << "Insufficient Funds!" << endl;
            } else {
                account.update_balance(account.balance - amount);
                cout << "Rs " << amount << " sent successfully!" << endl;
                cout << "Available balance: Rs " << account.balance << endl;
            }

        } else if (opr == 2) {
            cout << "Enter the account number of your other account: ";
            cin >> acc2;
            cout << "Enter the amount to transfer: ";
            cin >> amt;
            cout << "Enter your PIN: ";
            cin >> pin;

            if (pin != cor) {
                cout << "Incorrect PIN!" << endl;
            } else if (account.balance < amt) {
                cout << "Insufficient Funds!" << endl;
            } else {
                account.update_balance(account.balance - amt);
                cout << "Rs " << amt << " transferred successfully!" << endl;
                cout << "Available balance: Rs " << account.balance << endl;
            }

        } else if (opr == 3) {
            cout << "Enter your PIN: ";
            cin >> pin;
            if (pin != cor) {
                cout << "Incorrect PIN!" << endl;
            } else {
                cout << "Your current balance is: Rs " << account.balance << endl;
            }

        } else if (opr == 4) {
            cout << "Enter the account number to check: ";
            cin >> acc3;
            cout << "Enter the PIN for that account: ";
            cin >> pin3;

            if (acc3 != acor || pin3 != pcor) {
                cout << "Incorrect credentials!" << endl;
            } else {
                cout << "The available balance of the other account is: Rs " << balance2+amt << endl;
            }

        } else if (opr == 5) {
            cout << "Exiting Now..." << endl;
            cout << "Thank you for using our services!" << endl;
            exit(0);
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }
};

int main() {
    Account a(100000);
    a.get_details();
    a.display_data();

    Yesno y(50000); // Setting initial balance for Yesno object representing another account
    while (true) { // Continuous loop until user exits
        y.pro_data(a);
    }

    return 0;
}
