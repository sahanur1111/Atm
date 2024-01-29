#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

/* Mini projrct - ATM
--Chack Balance
--Chash withdraw
--User Details
--Update Mobile No.
*/

                                             
class atm                                            // class atm
{
private:                                     //private member variables
        long int account_No;
        string name;
        int PIN;
        double balance;
        string mobile_No;

public:                                     //public member function
      // setData fnction is setting the data into the private member variables
      void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a)
      {
        account_No = account_No_a;    // assigning the formal argument to the private member var's
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
      }

      // getAccountNo function is returing the User's account no.
      long int getAccountNo()
      {
        return account_No;
      }

      // getAccountNo function is returing the User's Name.
      string getName()
      {
        return name;
      }

      // getAccountNo function is returing the User's PIN.
      int getPIN()
      {
        return PIN;
      }

      // getAccountNo function is returing the User's balance.
      double getBlance()
      {
        return balance;
      }

      // getAccountNo function is returing the User's Mobile no.
      string getMobileNo()
      {
        return mobile_No;
      }
    //setMOblile function is Updating the user mobile no
    void setMobile(string mob_prev, string mob_new)
    {
      if(mob_prev == mobile_No)        // it will check old Mobile no
      {
        mobile_No = mob_new;         //and  Update with new, if old matches
        cout<<endl<< "Sucessfully Updated Mobile no.";
        _getch();           // getch is to hold the screen ( untill user press any key )

      }

      else
      {
        cout<<endl<<"Incorrect !! old Mobile no";
        _getch();
      }
      
    }

    //CASH WITHDRAW FUNCTION IS USED TO WUTHDRAW MONEY FROM ATM
    void cashWithDraw(int amount_a)
    {
        if(amount_a > 0 && amount_a < balance) // check entered amount validity
        {
            balance -= amount_a;
            cout<< endl << "Please Collect Your Cash";
            cout<<endl <<"Available Balance :" <<balance;
            _getch();              // getch is to hold the screen(untill user press any key)
        }

        else
        {
          cout<<endl <<"Invalid Input or Insufficient Balance";
          getch();    // getch is to hold the screen (untill user press any key)   
        }
    }

};

////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
     int choice = 0, enterPIN;      // enterPIN and enterAccountNo. --> user authentication 
     long int enterAccountNo;

     system("cls");  //clean screen auto bcz this function

     //created User (object )
     atm user1;
     // Set User Details (into object)    (Setting Default Data)
     user1.setData(123456789, "SAHANUR ALAM", 1234, 5678.78, "9832744839");


     do
     {
        system("cls");

        cout<< endl << "***Welcome to MINI ATM***"<<endl;
        cout<<endl<<"Enter Your Account No."; // asking user to enter account no
        cin>>enterAccountNo;

        cout<<endl<<"Enter PIN ->";  // asking user to enter PIN
        cin>>enterPIN;

        //check whether enter values matches with user details
        if((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system("cls");
                //user Interface
                cout<< endl<<"**Welcome to ATM***"<<endl;
                cout<< endl<<" Please Select Options";
                cout<< endl<<"1. Check Balance";
                cout<< endl<<"2. Cash withdraw";
                cout<< endl<<"3.Show User Details";
                cout<< endl<<"4.Update Mobile no.";
                cout<< endl<<"5.Exit"<<endl<<"->";
                cin>>choice;             // taking user choice


                switch (choice)
                {
                case 1:
                    cout<<endl<<"Your Bank balance is : "<<user1.getBlance();            // getBalance is   printing the users bank balance
                    _getch();
                    break;


                case 2:
                    cout<<endl<<"Enter the amount :";
                    cin>>amount;
                    user1.cashWithDraw(amount); // calling cashwithdraw function
                                                //passing the withdraw amount
                    break;


                case 3:
                    cout<<endl<<"*** User Details are :- ";
                    cout<<endl<<" -> Account  no: "<< user1.getAccountNo();
                    cout<<endl<<" -> Name: Mr."<< user1.getName();
                    cout<<endl<<" -> Balance: "<< user1.getBlance();
                    cout<<endl<<" -> Mobile No: "<< user1.getMobileNo();

                    _getch();                // getting and printing user details
                    break;


                case 4:
                    cout<<endl<<"Enter old Mobile NO.";
                    cin>>oldMobileNo;             // take old mobile no   
                    cout<<endl<<"Enter New Mobile no.";
                    cin>>newMobileNo;            //take new mobile no

                    user1.setMobile(oldMobileNo, newMobileNo);   // now set new mobile no
                    break;


                case 5:
                exit(0);          // exit application

                
                default:
                    cout <<endl<<"Enter Valid Data !!!!!!";
                }
            } while (1);              //MENU //Condition will always TRUE and loop is capable of running infinite times
        }
        else
        {
          cout<<endl<<"User Details are Invalid !!!";
          _getch();
        }
     }while(1);
     
     return 0;
};