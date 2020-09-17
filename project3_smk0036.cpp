/*
* FILE NAME: Project_1.cpp
* AUTHOR: Seth M Kinsaul
* I did not use any external sources for this assignment
* This program takes the numbers on two files and merges them into one output file
*/
///////////
//include//
///////////
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/////////////////////
//method prototypes//
/////////////////////
bool check_file(string);

vector<int> readFile(string);

void writeFile(string, vector<int>);

vector<int> merge(vector<int>, vector<int>);

void to_string(vector<int>);

///////////
//methods//
///////////

int main() {
  /////////////
  //variables//
  /////////////
  string file1;
  string file2;
  string file3;
  vector<int> numbers1, numbers2, numbers3;
  string file1_size = "6";
  int file2_size = 0;
  int output_size = 0;

  cout << "*** Welcome to Seth's sorting program ***";
  //use the first file
  do {
  cout << "\nEnter the first input file name: ";
  cin >> file1;
} while (cin.fail() || !check_file(file1));
//read and display numbers from file1
numbers1 = readFile(file1);
file1_size = numbers1.size();
cout << "The list of 6 numbers in file " + file1 + " is:" << endl;
  to_string(numbers1);
//use the second file
  do {
  cout << "\nEnter the second input file name: ";
  cin >> file2;
} while (cin.fail() || !check_file(file2));
//read and display numbers from file2
numbers2 = readFile(file2);
  cout << "The list of 5 numbers in file " + file2 + " is:" << endl;
  to_string(numbers2);
  //merge
  numbers3 = merge(numbers1, numbers2);
//use output file
  do {
    cout << "\nEnter the output file name: ";
    cin >> file3;
  } while (cin.fail());
//write to the output file with the combined vector
  writeFile(file3, numbers3);
    cout << "The sorted list of 11 numbers is:" << endl;
    to_string(numbers3);
    cout << "***Please check the new file - " +  file3 + " ***\n*** Goodbye. ***";
    return 0;

}

//////////////////////////
//method functionalities//
//////////////////////////
bool check_file(string file) {
  /* Input file stream. (ifstream) */
  ifstream stream;

  /* Check whether file exists. */
  stream.open(file.c_str());
  if (stream.fail()) {
    return false;
  }
  stream.close();
  return true;
 }

 vector<int> readFile(string file) {
  /* Input file stream. (ifstream) */
  ifstream stream;

  /* Vector containing numbers from file. (vector<int>) */
  vector<int> v;

  /* Integer read from file. (int) */
  int i;
  vector<int, allocator<int> >::iterator j;
  int index = 0;
  /* Add each number in the file to a vector. */
  stream.open(file.c_str());
  while (stream.good()) {
    if (index > 0) {
    stream >> i;
    j = v.insert(j, i);
  }
  index++;
  }

  stream.close();
  return v;
 }

 void writeFile(string file, vector<int> v) {
    /* Output file stream. (ofstream) */
    ofstream stream;
    stream.open(file.c_str());
    unsigned short i;

    for(i = 0; i < v.size(); i++) {
      stream << v.at(i) << endl;
    }

    stream.close();
 }

 vector<int> merge(vector<int> v1, vector<int> v2) {
  /* variables */
  unsigned short a = 0, b = 0;
  vector<int, allocator<int> >::iterator c;
  vector<int> v3;

  /* Compare both vectors. */
  while (a < v1.size() && b < v2.size()) {
    if (v1[a] > v2[b]) {
      c = v3.insert(c, v2.at(b));
      b++;
    } else {
      c = v3.insert(c, v1.at(a));
      a++;
    }
  }

  /* Add any remaining numbers from vector one. */
  if(a < v1.size()) {
    while(a < v1.size()) {
      c = v3.insert(c, v1.at(a));
      a++;
    }
  }

  /* Add any remaining numbers from vector two. */
  if(b < v2.size()) {
    while(b < v2.size()) {
      c = v3.insert(c, v2.at(b));
      b++;
    }
  }

  sort(v3.begin(), v3.end());
  return v3;
 }

 void to_string(vector<int> v) {
  /* Vector interator number (unsigned short) */
  unsigned short j;

  /* Display the numbers contained in a vector. */
  for(j = 0; j < v.size(); j++) {
    cout << v.at(j) << endl;
  }
 }
