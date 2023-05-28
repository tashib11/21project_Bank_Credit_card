#include <bits/stdc++.h>
#include <ctime>

using namespace std;
class base
{
protected:
    int phone, cardNumber;
    string pin, id, name, address;
    long double creditLimit, balance, income;
    int phonee;
    string pinn, idd, namee, addresss;
    long double balancee;
};

class bank : public base
{

public:
    inline void Menu();

    void CreditCard_system();
    void credit_details();
    void credit_purchasing();
    void credit_payment();
    void bank_mangement();
    void new_user();
    void pin_recovery();
    void deposit();
    void withdraw();
    void amount_transfer();
    void payment();
    void search_record();
    void edit();
    void delet();
    void show_record();
    void show_payments();
};

void bank ::Menu()
{
c:
    system("cls"); // for clear the screen for further use
    cout << "\n \t\t Control Panel : ";
    cout << "\n \t 1.bank Management.";
    cout << "\n \t 2.Credit card Mangement.";
    cout << "\n \t 3.Exit. " << endl;
    cout << "\n\t Enter choise- ";
    int choise;
    cin >> choise;
    switch (choise)
    {
    case 1:
        bank_mangement();
        break;
    case 2:
        CreditCard_system();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "\n \t invalid...wrong option.Try again" << endl;
        break;
    }
    getchar();
    goto c;
}
void bank::bank_mangement()
{
c:
    system("cls");
    cout << "\n\n bank management system" << endl;
    cout << "\n\t 1.New User" << endl;
    cout << "\t 2.Pin Recovery" << endl;
    cout << "\t 3.Deposit Option" << endl;
    cout << "\t 4.Withdraw Option" << endl;
    cout << "\t 5.Transfer Option" << endl;
    cout << "\t 6.Payment Option" << endl;
    cout << "\t 7.Search User Record" << endl;
    cout << "\t 8.Edit user Record : " << endl;
    cout << "\t 9.Delete user Record : " << endl;
    cout << "\t 10.Show All Records : " << endl;
    cout << "\t 11.Payment All Records : " << endl;
    cout << "\t 12.Menu" << endl;
    cout << "\n\t ENTER CHOICE : ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        new_user();
        break;
    case 2:
        pin_recovery();
        break;
    case 3:
        deposit();
        break;
    case 4:
        withdraw();
        break;
    case 5:
        amount_transfer();
        break;
    case 6:
        payment();
        break;
    case 7:
        search_record();

        break;
    case 8:
        edit();
        break;
    case 9:
        delet();
        break;
    case 10:
        show_record();
        break;
    case 11:
        show_payments();
        break;
    case 12:
        Menu();
        break;

    default:
        cout << "\n \t invalid...wrong option.Try again" << endl;
        break;
    }
    getchar();
    goto c;
}
void bank ::CreditCard_system()
{
c:
    system("cls");
    cout << "\n\n Credit Card management system" << endl;
    cout << "\t 1.Account Details" << endl;
    cout << "\t 2.Purchase Credi Card" << endl;
    cout << "\t 3.Payment " << endl;
    cout << "\t 4.Menu" << endl;
    cout << "\n\t ENTER CHOICE : ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        credit_details();
        break;
    case 2:
        credit_purchasing();
        break;
    case 3:
        credit_payment();
        break;
    case 4:
        Menu();
        break;

    default:
        cout << "\n \t invalid...wrong option.Try again" << endl;
        break;
    }
    getchar();
    goto c;
}
void bank::new_user()
{

c:

    system("cls");
    fstream file;
    cout << "\n\n\t Add new User. " << endl;
    cout << "\t Enter id : ";
    cin >> idd;
    cout << "\t Enter name : ";
    cin >> namee;
    cout << "\t Enter pin( 4 digits) : ";
    for (int id = 1; id <= 4; id++)
    {

        char p;
        cin >> p;

        pinn += p;
    }
    cout << "\t Enter Address : ";
    cin >> addresss;
    cout << "\t Enter Phone number : ";
    cin >> phonee;
    cout << "\t Enter Balance : ";
    cin >> balancee;
    file.open("bank.txt", ios::in);

    long double balance;
    if (!file)
    {
        file.open("bank.txt", ios::app | ios::out);
        file << " " << idd << " " << namee << ' ' << pinn << ' ' << addresss << ' ' << phonee << ' ' << balancee << endl;
    }
    else
    {
        file >> id >> name >> pin >> address >> phone >> balance;
        while (!file.eof())
        {
            if (id == idd)
            {
                cout << "\n User ID not available..please give new ID. " << endl;
                cout << "Press enter key to re-entry ";

                getchar();
                getchar();
                goto c;
            }
            file >> id >> name >> pin >> address >> phone >> balance;
        }
        file.close();
        file.open("bank.txt", ios::app | ios::out);
        file << " " << idd << " " << namee << ' ' << pinn << ' ' << addresss << ' ' << phonee << ' ' << balancee << endl;

        file.close();
    }

    cout << "\n\t Welcome, successful." << endl;
    cout << "\nPress enter key to go back ";

    getchar();
}

void bank::pin_recovery()
{
    system("cls");
    cout << "\t Enter User_ID : ";
    cin >> idd;
    int found = 0;
    fstream file;
    file.open("bank.txt", ios::in);

    long double balance;
    if (file)
    {
        file >> id >> name >> pin >> address >> phone >> balance;

        while (!file.eof())
        {
            if (id == idd)
            {
                system("cls");
                cout << "\n\t Pin number : " << pin << endl;
                cout << "\nRecovery successful" << endl;
                file.close();
                found = 1;
                break;
            }
            file >> id >> name >> pin >> address >> phone >> balance;
        }
        file.close();
    }
    if (found == 0)
    {
        system("cls");
        cout << "\n\tUser ID not exist" << endl;
    }
    cout << "Press enter key to go back ";

    getchar();
}
void bank ::deposit()
{
    system("cls");
    int found = 0;
    long double depos;
    cout << "\n\tEnter User ID : ";
    cin >> idd;
    cout << "\t Enter pin( 4 digits) : ";
    for (int id = 1; id <= 4; id++)
    {

        char p;
        cin >> p;
        pinn += p;
    }

    fstream file, file1;
    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::app | ios::out);

    if (file)
    {
        file >> id >> name >> pin >> address >> phone >> balance;

        while (!file.eof())
        {
            if (idd == id && pinn == pin)
            {
                system("cls");
                cout << "\n\t Enter the deposit amount : ";
                cin >> depos;
                balance += depos;
                file1 << " " << id << " " << name << ' ' << pin << ' ' << address << ' ' << phone << ' ' << balance << endl;

                cout << "\n Deposit successful" << endl;
                found = 1;
            }
            else
            {
                file1 << " " << id << " " << name << ' ' << pin << ' ' << address << ' ' << phone << ' ' << balance << endl;
            }
            file >> id >> name >> pin >> address >> phone >> balance;
        }
    }
    file.close();
    file1.close();
    remove("bank.txt");
    rename("bank1.txt", "bank.txt");
    if (found == 0)
    {
        system("cls");
        cout << "User id or Pin is not matched" << endl;
    }
    cout << "Press enter key to go back ";

    getchar();
}
void bank ::withdraw()
{
    system("cls");
    int found = 0;
    long double withd;
    cout << "\n\tEnter User ID : ";
    cin >> idd;
    cout << "\t Enter pin( 4 digits) : ";
    for (int id = 1; id <= 4; id++)
    {

        char p;
        cin >> p;
        pinn += p;
    }

    fstream file, file1;
    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::app | ios::out);

    if (file)
    {
        file >> id >> name >> pin >> address >> phone >> balance;

        while (!file.eof())
        {
            if (idd == id && pinn == pin)
            {
                system("cls");
                cout << "\n\t Enter the withdrawal amount : ";
                cin >> withd;
                if (balance >= withd)
                {
                    balance -= withd;
                    cout << "\n withdraw successful" << endl;
                }
                else
                {
                    cout << "\t Not enough Balance in your account" << endl;
                }

                file1 << " " << id << " " << name << ' ' << pin << ' ' << address << ' ' << phone << ' ' << balance << endl;

                found = 1;
            }
            else
            {
                file1 << " " << id << " " << name << ' ' << pin << ' ' << address << ' ' << phone << ' ' << balance << endl;
            }
            file >> id >> name >> pin >> address >> phone >> balance;
        }
    }
    file.close();
    file1.close();
    remove("bank.txt");
    rename("bank1.txt", "bank.txt");
    if (found == 0)
    {
        cout << "User id or Pin is not matched" << endl;
    }
    cout << "Press enter key to go back ";

    getchar();
}

void bank::amount_transfer()
{
    system("cls");
    int found = 0;
    long double trans;
    cout << "Enter User_ID : ";
    string s_id;
    cin >> s_id;
    cout << "Enter receiver_ID : ";
    string r_id;
    cin >> r_id;
    fstream file, file1;
    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::app | ios::out);

    long double balance;
    if (file)
    {
        file >> id >> name >> pin >> address >> phone >> balance;

        while (!file.eof())
        {
            if (id == s_id)
            {
            g:
                cout << "Enter transfer amount : ";
                cin >> trans;
                if (trans <= balance)
                    found++;
                else
                {
                    cout << "\tNot enough fund \n\t Try again " << endl;
                    goto g;
                }
            }
            else if (id == r_id)
                found++;
            file >> id >> name >> pin >> address >> phone >> balance;
            if (found == 2)
                break;
        }
    }
    file.close();

    if (found == 2)
    {

        file.open("bank.txt", ios::in);
        file >> id >> name >> pin >> address >> phone >> balance;
        while (!file.eof())
        {

            if (id == s_id)
            {
            t:
                cout << "\t Enter pin( 4 digits) : ";
                string pinn;
                for (int id = 1; id <= 4; id++)
                {

                    char p;
                    cin >> p;
                    pinn += p;
                }
                if (pinn == pin)
                {
                    balance -= trans;
                    file1 << " " << id << " " << name << ' ' << pin << ' ' << address << ' ' << phone << ' ' << balance << endl;
                }
                else
                {
                    cout << "\t Wrong pin \n\t Try again " << endl;
                    goto t;
                }
            }
            else if (id == r_id)
            {
                balance += trans;
                file1 << " " << id << " " << name << ' ' << pin << ' ' << address << ' ' << phone << ' ' << balance << endl;
            }
            else
            {
                file1 << " " << id << " " << name << ' ' << pin << ' ' << address << ' ' << phone << ' ' << balance << endl;
            }
            file >> id >> name >> pin >> address >> phone >> balance;
        }
        cout << "\n\tSuccessfully Transferred" << endl;
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
    }
    else

    {
        cout << "\n\t Transfer can't possible" << endl;
    }

    cout << "Press enter key to go back ";

    getchar();
}
void bank::search_record()
{
    system("cls");
    fstream file;
    cout << "\n\t Enter user id : ";
    cin >> idd;
    file.open("bank.txt", ios::in);

    int found = 0;
    if (file)
    {
        file >> id >> name >> pin >> address >> phone >> balance;
        while (!file.eof())
        {

            if (id == idd)
            {
            g:
                cout << "\t Enter pin( 4 digits) : ";
                string pinn;
                for (int id = 1; id <= 4; id++)
                {

                    char p;
                    cin >> p;
                    pinn += p;
                }
                if (pinn == pin)
                {
                    cout << "\n\tUser Recod" << endl;
                    cout << "\n Name : " << name << "\nAddress : " << address << "\nPhone : " << phone << "\n Balance : " << balance << endl;
                    ;
                    found = 1;
                }
                else
                {
                    cout << "\t Wrong pin .. Try again" << endl;
                    goto g;
                }
            }
            file >> id >> name >> pin >> address >> phone >> balance;
        }
    }
    file.close();
    if (found == 0)
    {
        cout << "\t No record Found" << endl;
    }
    cout << "Press enter key to go back ";
    getchar();
}
void bank::payment()
{
    system("cls");
    fstream file, file1, file3;
    cout << "\n\t Enter user id : ";
    string s_id;
    cin >> s_id;
    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::app | ios::out);

    int found = 0;
    string bnm;
    long double amount;

    if (file)
    {
        file >> id >> name >> pin >> address >> phone >> balance;
        while (!file.eof())
        {

            if (id == s_id)
            {
                cout << "\t Bill name : ";
                getchar();
                getline(cin, bnm);
            p:
                cout << "\t Enter Bill amount : ";
                cin >> amount;
                if (amount <= balance)
                {
                g:
                    cout << "\t Enter pin( 4 digits) : ";
                    string pinn;
                    for (int id = 1; id <= 4; id++)
                    {

                        char p;
                        cin >> p;
                        pinn += p;
                    }
                    if (pinn == pin)
                    {
                        balance -= amount;
                        file1 << " " << id << " " << name << ' ' << pin << ' ' << address << ' ' << phone << ' ' << balance << endl;
                        cout << "\n\t Successfully bill is   paid" << endl;

                        found = 1;
                        file3.open("bill.txt", ios::app | ios::out);
                        time_t now = time(0);

                        char *xtime = ctime(&now);

                        file3 << id << ' ' << bnm << ' ' << amount << ' ' << xtime << endl;
                        file3.close();
                    }
                    else
                    {
                        cout << "\t wrong pin..try again" << endl;
                        goto g;
                    }
                }
                else
                {
                    cout << "\t You have No enough Fund" << endl;
                    goto p;
                }
            }
            else
            {
                file1 << " " << id << " " << name << ' ' << pin << ' ' << address << ' ' << phone << ' ' << balance << endl;
            }
            file >> id >> name >> pin >> address >> phone >> balance;
        }
    }
    file1.close();
    file.close();
    remove("bank.txt");
    rename("bank1.txt", "bank.txt");
    if (found == 0)
    {
        cout << "\n\t  bill is not  paid" << endl;
    }
    cout << "Press enter key to go back ";

    getchar();
}
void bank::edit()
{
    system("cls");
    cout << "\n\t Enter user ID : ";
    cin >> idd;
    fstream file, file1;
    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::app | ios::out);

    int found = 0;
    if (file)
    {
        file >> id >> name >> pin >> address >> phone >> balance;
        while (!file.eof())
        {

            if (id == idd)
            {
            p:
                cout << "\t Enter pin( 4 digits) : ";
                for (int id = 1; id <= 4; id++)
                {

                    char p;
                    cin >> p;
                    pinn += p;
                }

                if (pinn == pin)
                {
                    cout << "\t Name : ";
                    cin >> name;
                    cout << "\t Address : ";
                    cin >> address;
                    cout << "\t pin : ";
                    cin >> pin;
                    cout << "\t phone : ";
                    cin >> phone;
                    file1 << " " << id << " " << name << ' ' << pin << ' ' << address << ' ' << phone << ' ' << balance << endl;
                    cout << "\t Edit Successful" << endl;
                    found = 1;
                }
                else
                {
                    cout << "\t Wrong pin" << endl;
                    goto p;
                }
            }
            else
            {
                file1 << " " << id << " " << name << ' ' << pin << ' ' << address << ' ' << phone << ' ' << balance << endl;
            }
            file >> id >> name >> pin >> address >> phone >> balance;
        }
    }
    file.close();
    file1.close();
    remove("bank.txt");
    rename("bank1.txt", "bank.txt");
    if (found == 0)
    {
        cout << "\t can't find user ID" << endl;
    }
    cout << "\t Press enter key to go back";
    getchar();
}
void bank::delet()
{
    system("cls");
    cout << "\n\t Enter user ID : ";
    cin >> idd;
    cout << "\t Enter pin( 4 digits) : ";
    for (int id = 1; id <= 4; id++)
    {

        char p;
        cin >> p;
        pinn += p;
    }
    fstream file, file1;
    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::app | ios::out);

    int found = 0;
    if (file)
    {
        file >> id >> name >> pin >> address >> phone >> balance;
        while (!file.eof())
        {

            if (id == idd && pin == pinn)
            {
                cout << "\t Delete successfully" << endl;
                found = 1;
            }
            else
            {
                file1 << " " << id << " " << name << ' ' << pin << ' ' << address << ' ' << phone << ' ' << balance << endl;
            }
            file >> id >> name >> pin >> address >> phone >> balance;
        }
    }
    file.close();
    file1.close();
    remove("bank.txt");
    rename("bank1.txt", "bank.txt");
    if (found == 0)
    {
        cout << "\t can't find  user ID" << endl;
    }
    cout << "\t Press enter key to go back";
    getchar();
}
void bank::show_record()
{
    system("cls");
    cout << "\n\t All Records \n"
         << endl;
    fstream file;
    file.open("bank.txt", ios::in);

    if (file)
    {
        file >> id >> name >> pin >> address >> phone >> balance;
        while (!file.eof())
        {
            cout << "\n\t Name : " << name << endl;
            cout << "\t User ID : " << id << endl;
            cout << "\t Address : " << address << endl;
            cout << "\t Phone : " << phone << endl;
            cout << "\t Balance : " << balance << endl;
            cout << "\t--------------------------" << endl;
            file >> id >> name >> pin >> address >> phone >> balance;
        }
    }
    file.close();
    cout << "\t Press enter key to go back";

    getchar();
}
void bank::show_payments()
{
    system("cls");
    cout << "\n\t\t All payment records " << endl;
    fstream file;
    file.open("bill.txt", ios::in);

    if (file)
    {
        string ss;

        while (getline(file, ss)) // line by line
        {
            cout << "\t" << ss << endl;
            cout << "\t------------------------------------" << endl;
        }
    }
    file.close();
    cout << "\t Press enter key to go back";
    getchar();
}
void bank::credit_purchasing()
{
    system("cls");
    int done = 0;
    fstream file;
    cout << "\n\t Apply for purchasing  credit card " << endl;
    cout << "----------------------------" << endl;

    cout << "\n\n\t Enter your monthly income : ";
    cin >> income;
    if (income < 50000)
    {
        cout << "\t Not eligible for this ";
    }
    else
    {
        creditLimit = income * 1.5;
        cout << "Your credit limit is : " << creditLimit << endl;
        cout << "\t To continue process ,Press 1 else 0 : ";
        int ok = 0;
        cin >> ok;
        if (ok)
        {
            done = 1;
            cout << "\t Enter Name : ";
            cin >> name;
        p:
            cout << "\t Enter Balance less or equal to " << creditLimit << ": ";
            cin >> balance;
            if (balance > creditLimit)
            {
                cout << "\t exited the limit " << endl;
                goto p;
            }
            cout << "\t Enter pin( 4 digits) : ";
            for (int id = 1; id <= 4; id++)
            {

                char p;
                cin >> p;
                pin += p;
            }
            srand((unsigned)time(0)); // random number creation
            cardNumber = rand();
            cout << "\t your card number : " << cardNumber;

            file.open("credit.txt", ios::app | ios ::out);
            file << ' ' << name << ' ' << balance << ' ' << pin << ' ' << cardNumber << endl;
            file.close();
            cout << "\n\tsuccessful, Congratulation" << endl;
        }
        else
        {
            cout << "\t Thank You" << endl;
        }
    }
    if (done == 0)
        cout << "\n\t failed " << endl;

    cout << "\n\t Press enter key to go back";
    getchar();
}
void bank::credit_details()
{
    system("cls");
    fstream file;
    cout << "\n\t Enter card number : ";
    int cn;
    cin >> cn;
    file.open("credit.txt", ios::in);

    int found = 0;
    if (file)
    {
        file >> name >> balance >> pin >> cardNumber;
        while (!file.eof())
        {

            if (cn == cardNumber)
            {
            g:
                cout << "\t Enter pin( 4 digits) : ";
                string pinn;
                for (int id = 1; id <= 4; id++)
                {

                    char p;
                    cin >> p;
                    pinn += p;
                }
                if (pinn == pin)
                {
                    cout << "\n\tUser Recod" << endl;
                    cout << "\n Name : " << name << "\n Balance : " << balance << endl;
                    ;
                    found = 1;
                }
                else
                {
                    cout << "\t Wrong pin .. Try again" << endl;
                    goto g;
                }
            }
            file >> name >> balance >> pin >> cardNumber;
        }
    }
    file.close();
    if (found == 0)
    {
        cout << "\t No record Found" << endl;
    }
    cout << "Press enter key to go back ";
    getchar();
}
void bank ::credit_payment()
{
    system("cls");
    fstream file, file1;
    file.open("credit.txt", ios::in);
    file1.open("credit1.txt", ios::app | ios::out);
    cout << "\n\t Enter card number : ";
    int cn;
    cin >> cn;

    int found = 0;
    if (file)
    {
        file >> name >> balance >> pin >> cardNumber;
        while (!file.eof())
        {

            if (cn == cardNumber)
            {
            g:
                cout << "\t Enter pin( 4 digits) : ";
                string pinn;
                for (int id = 1; id <= 4; id++)
                {

                    char p;
                    cin >> p;
                    pinn += p;
                }
                if (pinn == pin)
                {
                    cout << "\t the bill : ";
                    double bill;
                    cin >> bill;
                    if (bill > balance)
                    {
                        cout << "\n\t Not have enough money in card" << endl;
                    }
                    else
                    {
                        balance -= bill;
                        cout << "\n\t Successfully paid" << endl;
                    }
                    found = 1;

                    file1 << ' ' << name << ' ' << balance << ' ' << pin << ' ' << cardNumber << endl;
                }
                else
                {
                    cout << "\t Wrong pin .. Try again" << endl;
                    goto g;
                }
            }
            else
            {
                file1 << ' ' << name << ' ' << balance << ' ' << pin << ' ' << cardNumber << endl;
            }
            file >> name >> balance >> pin >> cardNumber;
        }
    }
    file1.close();
    file.close();
    remove("credit.txt");
    rename("credit1.txt", "credit.txt");
    if (found == 0)
    {
        cout << "\n\t Sorry, Card Number is invalid" << endl;
    }
    cout << "\nPress enter key to go back ";
    getchar();
}
int main()
{
    bank b;
    b.Menu();

    return 0;
}