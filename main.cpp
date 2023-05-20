#include<bits/stdc++.h>
    
using namespace std ;
    class Bank{
        private:
        int pin;
        float balance;
        string id,name,address;
        public:
        void Menu();
        void bank_mangement();
        void ATM_system();
         void new_user();
    };
    void Bank :: Menu(){
        c:
        system("cls"); // for clear the screen for further use
        cout<<"\n \t\t Control Panel : ";
        cout<<"\n \t 1.Bank Management.";
        cout<<"\n \t 2.ATM System.";
        cout<<"\n \t 3.Exit. "<<endl;
         cout<<"\n\t Enter choise- ";
        int choise;
        cin>>choise;
        switch(choise){
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
                    cout<<"\n \t invalid...wrong option.Try again"<<endl;
                    break;
        }
        getchar();
        goto c;
    }
  void  Bank :: bank_mangement(){
          c:
        system("cls");
         cout<<"\n\n Bank management system"<<endl;
         cout<<"\n\t 1.New User"<<endl;
         cout<<"\t 2.Already User"<<endl;
         cout<<"\t 3.Deposit Option"<<endl;
         cout<<"\t 4.Withdraw Option"<<endl;
         cout<<"\t 5.Transfer Option"<<endl;
         cout<<"\t 6.Payment Option"<<endl;
         cout<<"\t 7.Search User Record"<<endl;
         cout<<"\t 8.Edit user Record : "<<endl;
         cout<<"\t 9.Edit user Record : "<<endl;
         cout<<"\t 10.Show All Records : "<<endl;
         cout<<"\t 11.Payment All Records : "<<endl;
         cout<<"\t 12.Menu"<<endl;
         cout<<"\n\t ENTER CHOICE : "<<endl;
         int choice; cin>>choice;
         switch (choice)
         {
         case 1:
         new_user();
                break;
         case 2:
                break;
         case 3:
                break;
          case 4:
                     break;
        case 5:
                break;
         case 6:
                break;
         case 7:
                break;
          case 8:
                     break;
       case 9:
                break;
         case 10:
                break;
         case 11:
                break;
          case 12:
               Menu();
                     break;
         
         default:
          cout<<"\n \t invalid...wrong option.Try again"<<endl;
                    break;

         }
         getchar();
         goto c;
    }
      void  Bank :: ATM_system(){
        c:
        system("cls");
         cout<<"\n\n ATM management system"<<endl;
         cout<<"\n\t 1.Check balance"<<endl;
         cout<<"\t 2.Withdraw Amount"<<endl;
         cout<<"\t 3.Account Details"<<endl;
         cout<<"\t 4.Menu"<<endl;
         cout<<"\n\t ENTER CHOICE : "<<endl;
         int choice; cin>>choice;
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
                    cout<<"\n \t invalid...wrong option.Try again"<<endl;
            break;
         }
         getchar();
         goto c;


    }
   void Bank::new_user(){
    c:
        system("cls");
        fstream file;
        cout<<"\n\n\t Add new User. "<<endl;
        cout<<"\t Enter id : ";
        cin>>id;
        cout<<"\t Enter name : ";
        cin>>name;
        cout<<"\t Enter pin( 4 digits) : ";
          cin>>pin;
        cout<<"\t Enter Address : ";
        cin>>address;
        cout<<"\t Enter Balance : ";
        cin>>balance;
        file.open("bank.txt",ios::in);
        string i,nm,add;
        int pn; float blnc;
        if(!file){
            file.open("bank.txt",ios::app|ios::out);
            file<<" "<<id<<" "<<name<< ' '<< pin<< ' '<<address << ' '<<balance<<endl;
        }else{
             file>>i>>nm>>pn>>add>>blnc;
             while(!file.eof()){
                if(id==i){
                    cout<<"\n User ID not available..please give new ID. "<<endl;
                    getchar();
                    getchar();
                    goto c;
                }
             file>>i>>nm>>pn>>add>>blnc;

             }
             file.close();
             file.open("bank.txt",ios::app|ios::out);
            file<<" "<<id<<" "<<name<< ' '<< pin<< ' '<<address << ' '<<balance<<endl;
      
            file.close();

        }
                cout<<"\n\t Welcome, successful."; // this line is not executed why?
          getchar();
    

    }
int main()
{
    Bank ob;
    ob.Menu();
    
return 0;
}