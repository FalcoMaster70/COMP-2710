/*
* Seth's Duel Simulator
* FILE NAME: project1_smk0036.cpp
* smk0036@auburn.edu
* AUTHOR: Seth M Kinsaul
* I did not use any external sources for this assignment
* I use the g++ compiler using the local terminal to compile and recieve an output
* Using my methods we will devise a game where Aaron, Bob, and charlie try to shoot and each other to decide who is still alive.
*/
# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include <ctime>
# include <cstdlib>
using namespace std;

//variables
int num1;
int num2;
const string pDiv = "/10000";
int aWins;
int bWins;
int cWins;
int aWins2;
int bWins2;
int cWins2;
string target;
double shoot_target_result = rand() % 100;
int duel = 10000;
bool A_Alive; //Aaron(33.33% shot confirm{1/3})
bool B_Alive; //Bob(50% shot comfirm)
bool C_Alive; //Charlie(100% shot confirm)
bool True = true;
bool False = false;
double aProb = 33;
double bProb = 50;
double cProb = 100000;

   //////////////
   //prototypes//
   //////////////
   
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
  /* Input: A_alive indicates whether Aaron is alive */
  /* B_alive indicates whether Bob is alive */
  /* C_alive indicates whether Charlie is alive */
  /* Return: true if at least two are alive */
  /* otherwise return false */

void Aaron_shoots1(bool& B_alive, bool& C_alive);
  /* Strategy 1: Use call by reference
  * Input: B_alive indicates whether Bob alive or dead
  * C_alive indicates whether Charlie is alive or dead
  * Return: Change B_alive into false if Bob is killed.
  * Change C_alive into false if Charlie is killed.
  */

void Bob_shoots(bool& A_alive, bool& C_alive);
  /* Call by reference
  * Input: A_alive indicates if Aaron is alive or dead
  * C_alive indicates whether Charlie is alive or dead
  * Return: Change A_alive into false if Aaron is killed.
  * Change C_alive into false if Charlie is killed.
  */

void Charlie_shoots(bool& A_alive, bool& B_alive);
  /* Call by reference
  * Input: A_alive indicates if Aaron is alive or dead
  * B_alive indicates whether Bob is alive or dead
  * Return: Change A_alive into false if Aaron is killed.
  * Change B_alive into false if Bob is killed.
  */

void Aaron_shoots2(bool& B_alive, bool& C_alive);
  /* Strategy 2: Use call by reference
  * Input: B_alive indicates whether Bob alive or dead
  * C_alive indicates whether Charlie is alive or dead
  * Return: Change B_alive into false if Bob is killed.
  * Change C_alive into false if Charlie is killed.
  */
   
   //Test methods for the listed prototype functions
void test_at_least_two_alive(void);
 /* This is a test driver for at_least_two_alive() */

void test_Aaron_shoots1(void);
 /* This is a test driver for Aaron_shoots() */

void test_Bob_shoots(void);
 /* This is a test driver for Bob_shoots() */
 
void test_Charlie_shoots(void);
 /* This is a test driver for Charlie_shoots() */
 
void test_Aaron_shoots2(void);
 /* This is a test driver for Aaron_shoots2() */

//continue key
void continueKey() {
   cout << "\nPress any key to continue...";
   cin.ignore().get(); //Pause Command for Linux Terminal
}

   //////////////
   //Strategy 1//
   //////////////
void strategy1Driver() {
   cout << "Ready to test strategy 1 (run " << duel << " times):" << endl;
   continueKey();
   
   for (int i = 0; i < duel; i++) {
      A_Alive = B_Alive = C_Alive = true;
      do {
         if (A_Alive) {
            Aaron_shoots1(B_Alive, C_Alive);
         }
         if (B_Alive) {
            Bob_shoots(A_Alive, C_Alive);
         }
         if (C_Alive) {
            Charlie_shoots(A_Alive, B_Alive);
         }
      } while (at_least_two_alive(A_Alive, B_Alive, C_Alive));
      if (A_Alive) {
         aWins += 1;
      }
      if (B_Alive) {
         bWins += 1;
      }
      if (C_Alive) {
         cWins += 1;
      }
      cout << "\n";
      double percentageA = aWins * 0.01;
      double percentageB = bWins* 0.01;
      double percentageC = cWins * 0.01;
      cout << "Aaron won " << aWins << pDiv << " duels or " << percentageA << "%";
      cout << "\nBob won " << bWins << pDiv << " duels or " << percentageB << "%";
      cout << "\nCharlie won " << cWins << pDiv << " duels or " << percentageC << "%";
   }
}
   
   //////////////
   //Strategy2 //
   //////////////
void strategy2Driver() {
   cout << "\n\nReady to test strategy 2 (run " << duel << " times):" << endl;
   continueKey();
   
   for (int i = 0; i < duel; i++) {
      A_Alive = B_Alive = C_Alive = true;
      do {
         if (A_Alive) {
            Aaron_shoots2(B_Alive, C_Alive);
         }
         if (B_Alive) {
            Bob_shoots(A_Alive, C_Alive);
         }
         if (C_Alive) {
            Charlie_shoots(A_Alive, B_Alive);
         }
      } while (at_least_two_alive(A_Alive, B_Alive, C_Alive));
      if (A_Alive) {
         aWins2 += 1;
      }
      if (B_Alive) {
         bWins2 += 1;
      }
      if (C_Alive) {
         cWins2 += 1;
      }
      cout << "\n";
   }
   double percentageA = aWins * 0.01;
   double percentageB = bWins * 0.01;
   double percentageC = cWins * 0.01;
   cout << "Aaron won " << aWins2 << pDiv << " duels or " << percentageA << "%";
   cout << "\nBob won " << bWins2 << pDiv << " duels or " << percentageB << "%";
   cout << "\nCharlie won " << cWins2 << pDiv << " duels or " << percentageC << "%";
   
   if (aWins2 > aWins) {
      num2 = 2;
      num1 = 1;
   }
   else if (aWins2 == aWins) {
      cout << "\n\nStrategy 2 is equal to strategy 1." << endl;
      return;
   }
   else {
      num2 = 1;
      num1 = 2;
   }
   cout << "\n\nStrategy " << num2 << " is better than strategy " << num1 << "." << endl;
}
int main() {
   srand(time(0));
   //welcome msg
   cout << "\t ** Welcome to Seth's Duel Simulator **";
   test_at_least_two_alive();
   test_Aaron_shoots1();
   test_Bob_shoots();
   test_Charlie_shoots();
   test_Aaron_shoots2();
   strategy1Driver();
   strategy2Driver();
}

//Implementation of Methods
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   int i = 0;
   if (A_alive) {
      i++;  
   }
   if (B_alive) {
      i++;
   }
   if (C_alive) {
      i++;
   }
   if (i > 1) {
      return true;
   }
   else {
      return false;
   }
}
 
void Aaron_shoots1(bool& B_alive, bool& C_alive) {
   target = "Charlie";
   int randomNum = rand()%100;
   
   if (C_alive) {
      cout << "\n\t\tAaron is shooting at Charlie";
      target = "Charlie";
   }
   else { 
      cout << "\n\t\tAaron is shooting at Bob";
      target = "Bob";
   }
   if (randomNum <= aProb) {
      cout << "\n\t\t\t" << target << " is dead.";
      if (target == "Charlie") {
         C_Alive = false;
         return;
      }
      else {
         B_Alive = false;
         return;
      }
   }
}

void Bob_shoots(bool& A_alive, bool& C_alive) {
   A_Alive = A_alive;
   C_Alive = C_alive;
   int randomNum = rand()%100;
   
   if (C_Alive) {
      cout << "\n\t\tBob is shooting at Charlie";
      target = "Charlie";
   }
   else {
      cout << "\n\t\tBob is shooting at Aaron";
      target = "Aaron";
   }
   
   if (randomNum <= bProb) {
      cout << "\n\t\t\t" << target << " is dead.\n";
      if (target == "Charlie") {
         C_Alive = false;
      }
      else {
         A_Alive = false;
      }
   }
   else {
      cout << "\n\t\t\tBob misses.\n";
   }
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
   A_Alive = A_alive;
   B_Alive = B_alive;
   
   if (B_Alive) {
      cout << "\n\t\tCharlie is shooting at Bob";
      B_Alive = false;
      target = "Bob";
   }
   else {
      cout << "\n\t\tCharlie is shooting at Aaron";
      A_Alive = false;
      target = "Aaron";
   }
   cout << "\n\t\t\t" << target << " is dead.\n";
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
   B_Alive = B_alive;
   C_Alive = C_alive;
   int randomNumb = rand()%100;
   
   if ((B_Alive == true) && (C_Alive == true)) {
      cout << "\n\t\tAaron misses his first shot on purpose" << endl;
      cout << "\t\t\tBoth Bob and Charlie are alive." << endl;
      return;
   }
   
   if (C_Alive) {
      cout << "\n\t\tAaron is shooting at Charlie";
      target = "Charlie";
   }
   else {
      cout << "\n\t\tAaron is shooting at Bob";
      target = "Bob";
   }
   
   if (randomNumb <= aProb) {
      cout << "\n\t\t\t" << target << " is dead.\n";
      if (target == "Charlie") {
         C_Alive = false;
         return;
      }
      else {
         B_Alive = false;
         return;
      }
   }
   else {
      cout << "\n\t\t\tAaron misses.\n";
      return;
   }
}   
   
   
   //////////////////
   //method testing//
   //////////////////
void test_at_least_two_alive(void) {
   cout << "\nUnit Testing 1: Function – at_least_two_alive()\n";
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\tCase passed ...\n";
   continueKey();
}
   /* Implementation of the test driver for Aaron_shoots1() */
void test_Aaron_shoots1(void) {
   cout << "\nUnit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
   cout << "\tCase 1: Bob alive, Charlie alive";
   Aaron_shoots1(True, True);
   cout << "\n\tCase 2: Bob dead, Charlie alive";
   Aaron_shoots1(False, True);
   cout << "\n\tCase 3: Bob alive, Charlie dead";
   Aaron_shoots1(True, False);
   continueKey();
}

/* Implementation of the test driver for Bob_shoots() */
void test_Bob_shoots(void) {
   cout << "\nUnit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
   cout << "\tCase 1: Aaron alive, Charlie alive";
   Bob_shoots(True, True);
   cout << "\tCase 2: Aaron dead, Charlie alive";
   Bob_shoots(False, True);
   cout << "\tCase 3: Aaron alive, Charlie dead";
   Bob_shoots(True, False);
   continueKey();
}
 
 /* Implementation of the test driver for Charlie_shoots() */
void test_Charlie_shoots(void) {
   cout << "\nUnit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
   cout << "\tCase 1: Aaron alive, Bob alive";
   Charlie_shoots(True, True);
   cout << "\tCase 2: Aaron dead, Bob alive";
   Charlie_shoots(False, True);
   cout << "\tCase 3: Aaron alive, Bob dead";
   Charlie_shoots(True, False);
   continueKey();
}
 
 /* Implementation of the test driver for Aaron_shoots2() */
void test_Aaron_shoots2(void) {
   cout << "\nUnit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
   cout << "\tCase 1: Bob alive, Charlie alive";
   Aaron_shoots2(True, True);
   cout << "\tCase 2: Bob dead, Charlie alive";
   Aaron_shoots2(False, True);
   cout << "\tCase 3: Bob alive, Charlie dead";
   Aaron_shoots2(True, False);
   continueKey();
}
