/*
	Title:  Lab2.cpp
	Author: Austin Ring
	Date:  2/1/21
	Purpose:  Demonstrate your knowledge of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string, int, int);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrModified;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << sumOfNumbers(num) << endl;
				
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				if(isMember(myArray, num, ARRAY_SIZE) == true)
					cout << "\nYes! Your number is a member of the array" << endl;
				else
					cout << "\nNo! Your number is not a member of the array" << endl;
				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				stringReverser(userString, userString.length());
				
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				if(isPalindrome(userStrModified, 0, userStrModified.length()-1) == true)
					cout << "Yes, "<< userString << " user is a palindrome!" << endl;
				else
					cout << "No, "<< userString << " is not a palindrome!" << endl;
				
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here
				cout << multiply(num1, num2) << endl;
				
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


//implement the five recursive functions below!!!!
int sumOfNumbers(int a){
	if (a == 0)
		return 0;
	else
		return a + sumOfNumbers(a-1);
}

bool isMember(int* array, int value, int size){
	if (array[size]==value)
		return true;

	else{
		if (size==0)
			return false;
		else
			return isMember(array, value, size-1);
	}
}

void stringReverser(string word, int size){
	if (size == 0)
		return;
	else{
		cout << word[size-1];
		stringReverser(word,size-1);
	}
	
}

bool isPalindrome(string word2, int s, int e){
	if(s>=e)
		return true;
	if(word2[s] != word2[e])
		return false;
	return isPalindrome(word2, ++s, --e);

}

int multiply(int one, int two){
	if(two==0)
		return 0;
	else
		return one + multiply(one,two-1);
}