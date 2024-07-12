#include <iostream>
#include <iomanip>
#include "Account.h" // Account class definition
#include "SavingsAccount.h" // SavingsAccount class definition
#include "CheckingAccount.h" // CheckingAccount class definition
using namespace std;

int main()
{
   Account account1( 800.0 ); // create Account object
   SavingsAccount account2( 300.0, .06 ); // create SavingsAccount object
   CheckingAccount account3( 700.0, 2.0 ); // create CheckingAccount object

   cout << fixed << setprecision( 2 );

   // display initial balance of each object
   cout << "account1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   cout << "\nAttempting to debit $45.00 from account1." << endl;
   account1.debit( 45.0 );
   cout << "\nAttempting to debit $35.00 from account2." << endl;
   account2.debit( 35.0 );
   cout << "\nAttempting to debit $70.00 from account3." << endl;
   account3.debit( 70.0 );

   // display balances
   cout << "\naccount1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   cout << "\nCrediting $55.00 to account1." << endl;
   account1.credit( 55.0 ); 
   cout << "\nCrediting $50.00 to account2." << endl;
   account2.credit( 50.0 ); 
   cout << "\nCrediting $40.00 to account3." << endl;
   account3.credit( 40.0 ); 

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