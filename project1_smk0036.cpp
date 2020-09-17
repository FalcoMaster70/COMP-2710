/*
* FILE NAME: Project_1.cpp
* smk0036@auburn.edu
* AUTHOR: Seth M Kinsaul
* I did not use any external sources for this assignment
* I use the g++ compiler using the local terminal to compile and recieve an output
* Calculate how many months it will take with the appropriate interest rates with a stereo costing 1000 dollars
*/
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
//Interest Rate of 18% per year and 1.5% per month
//15 of monthly payment goes to interest and 35 of monthly payment goes to the total cost of the stereo system

   //Variables
   int monthCount = 1;
   double interestRatePerYear = -1; //18%
   double loanAmount; //Stereo = 1000 dollars
   double monthlyPayment; //50 dollars a month of loanAmount
   double monthlyInterest; //how much interest is paid every individual month
   double principal; //monthlyPayment - monthlyInterest
   double rate; //1.5%   double monthlyInterest;
   double totalInterest; //used to display total interest paid after all calculations

   cout << "Loan Amount: ";
   cin >> loanAmount;


   while (interestRatePerYear < 0) {
      cout << "Interest Rate (%per year): ";
      cin >> interestRatePerYear;
      break;
      if (interestRatePerYear < 0) {
         cout << "Interest rates are too low (less than zero)";
      }
   }
   
   cout << "Monthly Payments: ";
   cin >> monthlyPayment;

   if (monthlyPayment < interestRatePerYear) {
      cout << "Error: monthly payment is less than interest." << endl;
      return 0;
   }

//AMORTIZATION TABLE 
   cout.setf(ios::fixed); //display decimal point for all numbers
   cout.setf(ios::showpoint); 
   cout.precision(2); //decimal places to two(Real Currency) 
   cout << "\n*******************************************************************" << endl;
   cout << "          Amortization Table" << endl;
   cout << "*******************************************************************" << endl;
   //must set width for the positions of our values
   cout << left << setw(10) << "Month" << setw(10) << "Balance" << setw(10) << " Payment" << setw(10) << " Rate"
        << setw(10) << " Interest" << setw(10) << "  Principal" << endl;
   cout << left << setw(10) << "0" << "$" << setw(10) << loanAmount
        << setw(10) << "N/A" << setw(10) << "N/A" << setw(10) << "N/A" << setw(10) << " N/A" << endl;
   
   
   while (loanAmount > 0.0) {
      //calculations
      rate = (interestRatePerYear / 12);  //1.5
      monthlyInterest = loanAmount * (rate * 0.01); // 15
      principal = monthlyPayment - monthlyInterest;//50 - 15 = 35
      loanAmount = loanAmount - principal; //
      monthlyInterest = roundf(monthlyInterest * 100) / 100;
      principal = roundf(principal * 100) / 100;
      
      // alignment
      cout.setf(ios::fixed);
      cout.setf(ios::showpoint);
      cout.precision(2);
   
      // print each value
      cout << left << setw(10) << monthCount << "$" << setw(10) << loanAmount << "$" << setw(9) << monthlyPayment << setw(10) << rate << "$" << setw(10) << monthlyInterest << "$" <<  setw(10) << principal << endl;   
   
   if (loanAmount < monthlyPayment) {
      monthlyInterest = loanAmount * (rate * 0.01);
      monthlyPayment = loanAmount + monthlyInterest;
      totalInterest += monthlyInterest; // increments in here as well to avoid error
   }
   totalInterest += monthlyInterest; // incrementing total interest             
   monthCount++; // incrementing months
   }
   cout << "*******************************************************************\n";
   cout << "\nIt takes " << monthCount - 1 << " months left to pay off the loan." << endl;
   cout << "Total interest paid is: $" << totalInterest;
   
   return 0;
      
}
      
