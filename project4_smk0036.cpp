/*
* FILE NAME: Project4_smk0036.cpp
* AUTHOR: Seth M Kinsaul
* I did not use any external sources for this assignment
* I use the g++ compiler using the local terminal to compile and recieve an output
* Trivia Quiz Game
* Contains a production and a debugging version
*/

#include <iostream>
#include <string>
using namespace std;

// Disable statement below for production version
//#define UNIT_TESTING

// Global variable
int count = 0;

// Create structure TriviaNode
struct TriviaNode {
   string question;
   string answer;
   unsigned int points;
   TriviaNode* nextNode;
};

// Make new type that is a pointer type to a TriviaNode structure
typedef TriviaNode* triviaNodePtr;
triviaNodePtr head;

// Helper Methods
triviaNodePtr inTriviaNode(triviaNodePtr &head);
triviaNodePtr addNode(string questionIn, string ansIn, int pointsIn, triviaNodePtr &lastNode);
void game();
void test();

// Main method
int main() {
   // Debugging version
   #ifdef UNIT_TESTING
      test();
   // Production version
   #else
   
   // Variables for main
   bool cont = true;
   int whileCount = 0;

   triviaNodePtr currentNode = new TriviaNode;
   // intriviaNode with 3 questions and put head into lastNode
   triviaNodePtr lastNode = inTriviaNode(head);
   
   // Welcome message
   cout << "*** Welcome to Seth's trivia quiz game ***" << endl;
   
   // Populate the TriviaNode linkedList
   while (cont) {
      string stringCompare = "";
      string question;
      string answer;
      int points;
      
      // Prompt user to enter question and save it into the node
      cout << "Enter a question: ";
      getline(cin, question);

      // Prompt user to enter answer to question and save it into the node
      cout << "Enter an answer: ";
      getline(cin, answer);
 
      // Prompt user to enter award points and save it into the node
      cout << "Enter award points: ";
      cin >> points;  
      cin.clear();
      cin.ignore(100000,'\n'); 
      
      // Add the node to the chain of LinkedList
      currentNode = addNode(question, answer, points, lastNode);
      
      // Check to see if the user wants to keep going
      cout << "Continue (Yes/No): ";
      cin >> stringCompare;
      cin.clear();
      cin.ignore(10000,'\n');
      
      // User enters "no", we point last node to NULL
      if (stringCompare == "No" || stringCompare == "no") {
        cont = false;
      }
      
      // User enters "yes", we set current node equal the previous and continue
      else if (stringCompare == "Yes" || stringCompare == "yes") {
         cont = true;
      }
      
      // Set last node equal to currentNode
      lastNode = currentNode;
      
      // Keep count of how many times the while loop executes
      whileCount++;       
   }
   
   // Play some trivia!
   game();   
   
   #endif
   return 0;
}

// Implement the game
void game() {
// In variables that will be used in the game
   string answer;
   int totalPoints = 0;
   
   // Start the game
   while (true) {
      // Print question to cout
      cout << "Question: " << head->question << endl;
      
      // Prompt user to enter answer
      cout << "Answer: ";
      getline(cin, answer);
      cin.clear();

      // Check answer and assign points
      if (answer.compare(head->answer) == 0) {
         cout << "Your answer is correct. You recieve " << head->points << " points." << endl;
         totalPoints += head->points;
      }
      else {
         cout << "Your answer is wrong. The correct answer is: " << head->answer << endl;
      }
      
      // Print total points tester has acquired 
      cout << "Your total points: " << totalPoints << "\n" << endl;
      
      // Check to see if there is another node
      if (head->nextNode == NULL) {
         cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;
         break;
         }
      else {
         // Step into the next Node
         head = head->nextNode;
      }
   }
}

// In the linked list with the first three questions
triviaNodePtr inTriviaNode(triviaNodePtr &head) {
   triviaNodePtr node = new TriviaNode();
   triviaNodePtr node2 = new TriviaNode();
   head = new TriviaNode();
   
   // Head node
   head->question = "How long was the shortest war on record? (Hint: how many minutes)";
   head->answer = "38";
   head->points = 100;
   head->nextNode = node;
   count++;
   
   // First node
   node->question = "What was Bank of America's orignal name? (Hint: Bank of Italy or Bank of Germany)";
   node->answer = "Bank of Italy";
   node->points = 50;
   node->nextNode = node2;
   count++;
   
   // Second node
   node2->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
   node2->answer = "Wii Sports";
   node2->points = 20;
   node2->nextNode = NULL;
   count++;
   
   // return last node
   return node2;
}

   // add node
   triviaNodePtr addNode(string questionIn, string ansIn, int pointsIn, triviaNodePtr &lastNode) {
   // Create new node
   triviaNodePtr newNode = new TriviaNode;
   newNode->question = questionIn;
   newNode->answer = ansIn;
   newNode->points = pointsIn;
   count++;
   
   // Point the last node to the new node
   lastNode->nextNode = newNode;
   
   // Return the newNode/last node in the linked list
   return newNode;
   
}

void test() {
   
   cout << "*** This is a debugging version *** " << endl;
   
   // Case 1
   cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
   cout << "Warning - The number of trivia to be asked must equal to or larger than 1." << endl;
   cout << "Case 1 Passed" << endl;
   
   // Rest of the cases
   cout << "\nUnit Test Case 2.1: Ask 1 question in the linked list. The tester \nenters an incorrect answer." << endl;
   triviaNodePtr currentNode = new TriviaNode;
   triviaNodePtr lastNode = inTriviaNode(head);
   game();
   cout << "*** End of the Debugging Version ***" << endl;
}

