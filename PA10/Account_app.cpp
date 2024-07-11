#include <iostream>
#include <iomanip>
#include "Account.h" // Account class definition
#include "SavingsAccount.h" // SavingsAccount class definition
#include "CheckingAccount.h" // CheckingAccount class definition
using namespace std;

int main()
{
   Account account1( 500.0 ); // create Account object
   SavingsAccount account2( 200.0, .06 ); // create SavingsAccount object
   CheckingAccount account3( 350.0, 1.25 ); // create CheckingAccount object

   cout << fixed << setprecision( 2 );

   // display initial balance of each object
   cout << "account1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   cout << "\nAttempting to debit $25.00 from account1." << endl;
   account1.debit( 300.0 ); // try to debit $25.00 from account1
   cout << "\nAttempting to debit $30.00 from account2." << endl;
   account2.debit( 100.0 ); // try to debit $30.00 from account2
   cout << "\nAttempting to debit $40.00 from account3." << endl;
   account3.debit( 250.0 ); // try to debit $40.00 from account3

   // display balances
   cout << "\naccount1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   cout << "\nCrediting $40.00 to account1." << endl;
   account1.credit( 250.0 ); // credit $40.00 to account1
   cout << "\nCrediting $65.00 to account2." << endl;
   account2.credit( 150.0 ); // credit $65.00 to account2
   cout << "\nCrediting $20.00 to account3." << endl;
   account3.credit( 200.0 ); // credit $20.00 to account3

   // display balances
   cout << "\naccount1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   // add interest to SavingsAccount object account2
   double interestEarned = account2.calculateInterest();
   cout << "\nAdding $" << interestEarned << " interest to account2." 
      << endl;
   account2.credit( interestEarned );

   cout << "\nNew account2 balance: $" << account2.getBalance() << endl;

   return 0;
   
}