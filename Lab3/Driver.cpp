#include "Song.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;

//LOOK!!  ENTER YOUR FUNCTION PROTOTYPES HERE
void insertion(Song*, int);
void bubble(Song*, int);
void quick(Song*, int, int);
int partition(Song*, int, int);

int main()
{
	Song *mySongArray;
	mySongArray = new Song[150000];
	int numSongs = 0;
	float length;
	string temp;
	
	ofstream outFile;
	ifstream inFile;

	time_t start, end;
	char filename[50];
	cout << "\n\nWhat is the name of the file with songs? (example.txt)\n";
	cin >> filename;
	inFile.open(filename);
	
	if(!inFile)
	{
		cout << "\n\nSorry, I can't open the file songs.txt\n\n";
		exit(1);
	}
	
	while(getline(inFile, temp) && numSongs != 150000)
	{
		mySongArray[numSongs].setTitle(temp);
		getline(inFile, temp);
		mySongArray[numSongs].setArtist(temp);
		inFile >> length;
		inFile.ignore();
		mySongArray[numSongs].setLength(length);
		numSongs++;
	}
	cout << "\n\nYou have created " << numSongs << " Song objects.\n\n";
	
	
	
	//sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); //Starts timer.   
	
	//LOOK!!!!  CALL THE INSERTION SORT ALGORITHM HERE
	insertion(mySongArray, numSongs);
	
	
	end = getTime(); //Ends timer.
	outFile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	
	//sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE REVERSE BUBBLE SORT ALGORITHM HERE
	bubble(mySongArray, numSongs);
	
	end = getTime(); //Ends timer.
	outFile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	
	//sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE QUICKSORT ALGORITHM HERE
	quick(mySongArray, 0, numSongs-1);
	
	end = getTime(); //Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outFile.open("sortFileQuick.txt");
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	delete [] mySongArray;
	return 0;
}

//LOOK!  WRITE YOUR INSERTION SORT FUNCTION HERE
void insertion(Song* array, int num1){
	string songs, artist;
	float length;
	int temp1;

	for(int i=1; i<num1; i++){
		songs = array[i].getTitle();
		artist = array[i].getArtist();
		length = array[i].getLength();
		temp1 = i-1;

		while(temp1>=0 && array[temp1].getTitle() > songs){
			array[temp1+1].setTitle(array[temp1].getTitle());
			array[temp1+1].setArtist(array[temp1].getArtist());
			array[temp1+1].setLength(array[temp1].getLength());
			temp1=temp1-1;
		}
		array[temp1+1].setTitle(songs);
		array[temp1+1].setArtist(artist);
		array[temp1+1].setLength(length);

	}
}

//LOOK!  WRITE YOUR REVERSE BUBBLE SORT FUNCTION HERE
void bubble(Song* array, int num2){
	string song, artist;
	float length;

	for(int max=(num2-1); max>0; max--){
		for(int i=0; i<max; i++){
			if(array[i+1].getTitle() > array[i].getTitle()){
				song = array[i+1].getTitle();
				artist = array[i+1].getArtist();
				length = array[i+1].getLength();
				array[i+1] = array[i];
				array[i].setTitle(song);
				array[i].setArtist(artist);
				array[i].setLength(length);
			}
		}
	}
}
//LOOK!  WRITE YOUR RECURSIVE QUICK SORT FUNCTION HERE
void quick(Song* array, int low, int high){
	int pivot = 0;

	if(low>=high){
		return;
	}
	pivot=partition(array, low, high);
	quick(array, low, pivot);
	quick(array, pivot+1, high);
}
//LOOK!  WRITE YOUR PARTITION FUNCTION HERE
int partition(Song* array, int left, int right){
	string pivot, song, artist;
	float length;
	int middle;
	bool done = false;
	middle = left + (right-left)/2;
	pivot = array[middle].getTitle();
	int l = left;
	int r = right;

	while(!done){
		while(array[l].getTitle() < pivot)
			++l;
		while(pivot < array[r].getTitle())
			--r;

		if(l>=r)
			done = true;
		else{
			song = array[l].getTitle();
			artist = array[l].getArtist();
			length = array[l].getLength();
			array[l] = array[r];
			array[r].setTitle(song);
			array[r].setArtist(artist);
			array[r].setLength(length);
			++l;
			--r;
		}
	}
	return r;
}
