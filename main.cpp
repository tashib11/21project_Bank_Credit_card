#include <bits/stdc++.h>
#include <ctime>

using namespace std;
class Bank
{
private:
    int pin, phone;
    float balance;
    string id, name, address;

public:
    void Menu();
    void bank_mangement();
    void ATM_system();
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
void Bank ::Menu()
{
c:
    system("cls"); // for clear the screen for further use
    cout << "\n \t\t Control Panel : ";
    cout << "\n \t 1.Bank Management.";
    cout << "\n \t 2.ATM System.";
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
        ATM_system();
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
void Bank ::bank_mangement()
{
c:
    system("cls");
    cout << "\n\n Bank management system" << endl;
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
void Bank ::ATM_system()
{
 c:
    system("cls");
    cout << "\n\n ATM management system" << endl;
    cout << "\n\t 1.Check balance" << endl;
    cout << "\t 2.Withdraw Amount" << endl;
    cout << "\t 3.Account Details" << endl;
    cout << "\t 4.Menu" << endl;
    cout << "\n\t ENTER CHOICE : " << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
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
void Bank::new_user()
{
 p:
 c:

    system("cls");
    fstream file;
    cout << "\n\n\t Add new User. " << endl;
    cout << "\t Enter id : ";
    cin >> id;
    cout << "\t Enter name : ";
    cin >> name;
    cout << "\t Enter pin( 4 digits) : ";
    cin >> pin;
    cout << "\t Enter Address : ";
    cin >> address;
    cout << "\t Enter Phone number : ";
    cin >> phone;
    cout << "\t Enter Balance : ";
    cin >> balance;
    file.open("bank.txt", ios::in);
    string i, nm, add;
    int pn, ph;
    float blnc;
    if (!file)
    {
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << name << ' ' << pin << ' ' << address << ' ' << phone << ' ' << balance << endl;
    }
    else
    {
        file >> i >> nm >> pn >> add >> ph >> blnc;
        while (!file.eof())
        {
            if (id == i)
            {
                cout << "\n User ID not available..please give new ID. " << endl;
                cout << "Press enter key to re-entry ";

                getchar();
                getchar();
                goto c;
            }
            file >> i >> nm >> pn >> add >> ph >> blnc;
        }
        file.close();
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << name << ' ' << pin << ' ' << address << ' ' << phone << ' ' << balance << endl;

        file.close();
    }

 


 cout << "\n\t Welcome, successful." << endl;
 cout << "\nPress enter key to go back ";

  getchar();
}

void Bank::pin_recovery()
{
    system("cls");
    cout << "\t Enter User_ID : ";
    cin >> id;
    int found = 0;
    fstream file;
    file.open("bank.txt", ios::in);
    string i, nm, add;
    int pn, ph;
    float blnc;
    if (file)
    {
        file >> i >> nm >> pn >> add >> ph >> blnc;

        while (!file.eof())
        {
            if (id == i)
            {
                system("cls");
                cout << "\n\t Pin number : " << pn << endl;
                cout << "\nRecovery successful" << endl;
                file.close(); // loop is closed
                found = 1;
            }
            file >> i >> nm >> pn >> add >> ph >> blnc;
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
void Bank ::deposit()
{
    system("cls");
    int found = 0;
    float depos;
    cout << "\n\tEnter User ID : ";
    string idd;
    cin >> idd;
    cout << "\tEnter pin : ";
    int pinn;
    cin >> pinn;

    fstream file, file1;
    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::app | ios::out);
    string i, nm, add;
    int pn, ph;
    float blnc;
    if (file)
    {
        file >> i >> nm >> pn >> add >> ph >> blnc;

        while (!file.eof())
        {
            if (idd == i && pinn == pn)
            {
                system("cls");
                cout << "\n\t Enter the deposit amount : ";
                cin >> depos;
                blnc += depos;
                file1 << " " << i << " " << nm << ' ' << pn << ' ' << add << ' ' << ph << ' ' << blnc << endl;

                cout << "\n Deposit successful" << endl;
                found = 1;
            }
            else
            {
                file1 << " " << i << " " << nm << ' ' << pn << ' ' << add << ' ' << ph << ' ' << blnc << endl;
            }
            file >> i >> nm >> pn >> add >> ph >> blnc;
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
void Bank ::withdraw()
{
    system("cls");
    int found = 0;
    float withd;
    cout << "\n\tEnter User ID : ";
    string idd;
    cin >> idd;
    cout << "\tEnter pin : ";
    int pinn;
    cin >> pinn;

    fstream file, file1;
    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::app | ios::out);
    string i, nm, add;
    int pn, ph;
    float blnc;
    if (file)
    {
        file >> i >> nm >> pn >> add >> ph >> blnc;

        while (!file.eof())
        {
            if (idd == i && pinn == pn)
            {
                system("cls");
                cout << "\n\t Enter the withdrawal amount : ";
                cin >> withd;
                if (blnc >= withd)
                {
                    blnc -= withd;
                    cout << "\n withdraw successful" << endl;
                }
                else
                {
                    cout << "\t Not enough Balance in your account" << endl;
                }

                file1 << " " << i << " " << nm << ' ' << pn << ' ' << add << ' ' << ph << ' ' << blnc << endl;

                found = 1;
            }
            else
            {
                file1 << " " << i << " " << nm << ' ' << pn << ' ' << add << ' ' << ph << ' ' << blnc << endl;
            }
            file >> i >> nm >> pn >> add >> ph >> blnc;
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

void Bank::amount_transfer()
{
    system("cls");
    int found = 0;
    float trans;
    cout << "Enter User_ID : ";
    string s_id;
    cin >> s_id;
    cout << "Enter receiver_ID : ";
    string r_id;
    cin >> r_id;
    fstream file, file1;
    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::app | ios::out);
    string i, nm, add;
    int pn, ph;
    float blnc;
    if (file)
    {
        file >> i >> nm >> pn >> add >> ph >> blnc;

        while (!file.eof())
        {
            if (i == s_id)
            {
            g:
                cout << "Enter transfer amount : ";
                cin >> trans;
                if (trans <= blnc)
                    found++;
                else
                {
                    cout << "\tNot enough fund \n\t Try again " << endl;
                    goto g;
                }
            }
            else if (i == r_id)
                found++;
            file >> i >> nm >> pn >> add >> ph >> blnc;
            if (found == 2)
                break;
        }
    }
    file.close();

    if (found == 2)
    {

        file.open("bank.txt", ios::in);
        file >> i >> nm >> pn >> add >> ph >> blnc;
        while (!file.eof())
        {

            if (i == s_id)
            {
            t:
                cout << "\t Enter your pin :";
                int pinn;
                cin >> pinn;
                if (pinn == pn)
                {
                    blnc -= trans;
                    file1 << " " << i << " " << nm << ' ' << pn << ' ' << add << ' ' << ph << ' ' << blnc << endl;
                }
                else
                {
                    cout << "\t Wrong pin \n\t Try again " << endl;
                    goto t;
                }
            }
            else if (i == r_id)
            {
                blnc += trans;
                file1 << " " << i << " " << nm << ' ' << pn << ' ' << add << ' ' << ph << ' ' << blnc << endl;
            }
            else
            {
                file1 << " " << i << " " << nm << ' ' << pn << ' ' << add << ' ' << ph << ' ' << blnc << endl;
            }
            file >> i >> nm >> pn >> add >> ph >> blnc;
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
void Bank::search_record()
{
    system("cls");
    fstream file;
    cout << "\n\t Enter user id : ";
    string s_id;
    cin >> s_id;
    file.open("bank.txt", ios::in);
    string i, nm, add;
    int pn, ph;
    float blnc;
    int found = 0;
    if (file)
    {
        file >> i >> nm >> pn >> add >> ph >> blnc;
        while (!file.eof())
        {

            if (i == s_id)
            {
            g:
                cout << "\t Enter pin : ";
                int pinn;
                cin >> pinn;
                if (pinn == pn)
                {
                    cout << "\n\tUser Recod" << endl;
                    cout << "\n Name : " << nm << "\nAddress : " << add << "\nPhone : " << ph << "\n Balance : " << blnc << endl;
                    ;
                    found = 1;
                }
                else
                {
                    cout << "\t Wrong pin .. Try again" << endl;
                    goto g;
                }
            }
            file >> i >> nm >> pn >> add >> ph >> blnc;
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
void Bank::payment()
{
    system("cls");
    fstream file, file1, file3;
    cout << "\n\t Enter user id : ";
    string s_id;
    cin >> s_id;
    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::app | ios::out);

    string i, nm, add;
    int pn, ph;
    float blnc;
    int found = 0;
    string bnm;
    float amount;

    if (file)
    {
        file >> i >> nm >> pn >> add >> ph >> blnc;
        while (!file.eof())
        {

            if (i == s_id)
            {
                cout << "\t Bill name : ";
                getchar();
                getline(cin, bnm);
            p:
                cout << "\t Enter Bill amount : ";
                cin >> amount;
                if (amount <= blnc)
                {
                g:
                    cout << "\t Enter pin : ";
                    int pinn;
                    cin >> pinn;
                    if (pinn == pn)
                    {
                        blnc -= amount;
                        file1 << " " << i << " " << nm << ' ' << pn << ' ' << add << ' ' << ph << ' ' << blnc << endl;
                        cout << "\n\t Successfully bill is   paid" << endl;

                        found = 1;
                        file3.open("bill.txt", ios::app | ios::out);
                        time_t now = time(0);
                        // tm *utc = gmtime(&now);
                        // char *xtime = asctime(utc);
                        char *xtime = ctime(&now);

                        file3 << i << ' ' << bnm << ' ' << amount << ' ' << xtime << endl;
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
                file1 << " " << i << " " << nm << ' ' << pn << ' ' << add << ' ' << ph << ' ' << blnc << endl;
            }
            file >> i >> nm >> pn >> add >> ph >> blnc;
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
void Bank::edit()
{
    system("cls");
    cout << "\n\t Enter user ID : ";
    string idd;
    cin >> idd;
    fstream file, file1;
    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::app | ios::out);
    string i, nm, add;
    int pn, ph;
    float blnc;
    int found = 0;
    if (file)
    {
        file >> i >> nm >> pn >> add >> ph >> blnc;
        while (!file.eof())
        {

            if (i == idd)
            {
            p:
                cout << "\t Enter pin : ";
                int pinn;
                cin >> pinn;

                if (pinn == pn)
                {
                    cout << "\t Name : ";
                    cin >> nm;
                    cout << "\t Address : ";
                    cin >> add;
                    cout << "\t pin : ";
                    cin >> pn;
                    cout << "\t phone : ";
                    cin >> ph;
                    file1 << " " << i << " " << nm << ' ' << pn << ' ' << add << ' ' << ph << ' ' << blnc << endl;
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
                file1 << " " << i << " " << nm << ' ' << pn << ' ' << add << ' ' << ph << ' ' << blnc << endl;
            }
            file >> i >> nm >> pn >> add >> ph >> blnc;
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
void Bank::delet()
{
    system("cls");
    cout << "\n\t Enter user ID : ";
    string idd;
    cin >> idd;
    fstream file, file1;
    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::app | ios::out);
    string i, nm, add;
    int pn, ph;
    float blnc;
    int found = 0;
    if (file)
    {
        file >> i >> nm >> pn >> add >> ph >> blnc;
        while (!file.eof())
        {

            if (i == idd)
            {
                cout << "\t Delete successfully" << endl;
                found = 1;
            }
            else
            {
                file1 << " " << i << " " << nm << ' ' << pn << ' ' << add << ' ' << ph << ' ' << blnc << endl;
            }
            file >> i >> nm >> pn >> add >> ph >> blnc;
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
void Bank::show_record()
{
    system("cls");
    cout << "\n\t All Records \n"
         << endl;
    fstream file;
    file.open("bank.txt", ios::in);
    string i, nm, add;
    int pn, ph;
    float blnc;
    if (file)
    {
        file >> i >> nm >> pn >> add >> ph >> blnc;
        while (!file.eof())
        {
            cout << "\n\t Name : " << nm << endl;
            cout << "\t User ID : " << i << endl;
            cout << "\t Address : " << add << endl;
            cout << "\t Phone : " << ph << endl;
            cout << "\t Balance : " << blnc << endl;
            cout << "\t--------------------------" << endl;
            file >> i >> nm >> pn >> add >> ph >> blnc;
        }
    }
    file.close();
    cout << "\t Press enter key to go back";

    getchar();
}
void Bank::show_payments()
{
    system("cls");
    cout << "\n\t\t All payment records " << endl;
    fstream file;
    file.open("bill.txt", ios::in);
    string i, bnm, day, month, ti;
    int year;
    int tar;
    int pn, ph;
    float blnc;
    if (file)
    {
        string ss;

        while (getline(file, ss))
        {
            cout << "\t" << ss << endl;
            cout << "\t------------------------------------" << endl;
        }
    }
    file.close();
    cout << "\t Press enter key to go back";
    getchar();
}
int main()
{
    Bank ob;
    ob.Menu();

    return 0;
}