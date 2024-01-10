/**********************************************************************
	Title:        TravelAgent.cpp
	Author:       Austin Ring
	Date Created: 3/3/2021
***********************************************************************/

#include "LinkedList.h"
#include "Destination.h"

void picture();

int main(){
    LinkedList<Destination*> list;
    cout << "Hello! My name is Gavin O Cleirigh and I am your professional travel agent, tour director, and guide!" << endl;
    picture();
    ifstream file;
    file.open("placeFile.txt");
    string temp1, temp2, name;
    float tempA;
    int tempB, salary, randNum;
    char response;

    while(!file.eof()){
        getline(file, temp1, '#');
        getline(file, temp2, '#');
        file >> tempA;
        file.ignore();
        file >> tempB;
        file.ignore();
        Destination* newObject = new Destination(temp1, temp2, tempA, tempB);
        list.insertNode(newObject);
    }
    file.close();
    int totalNodes = list.getLength();
    
	for(int i=0; i<(totalNodes); i++){
		cout << "-----Destination " << i+1 << " -----" << endl;
        cout << *(list.getNodeValue(i));
	}

    cout << "Please answer the following four questions and I will determine the place you should travel." << endl;
    cout << "\n\t1. What is your full name?\t";
    getline(cin, name);

    cout << "\n\t2. How much money do you make per year?\t";
    cin >> salary;
    while(!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Oops! You entered something wonky. Please enter a number:  ";
        cin >> response;
    }
    cin.ignore();

    cout << "\n\t3. Do you prefer Chocolate over Vanilla ice cream? (y/n)\t";
    cin >> response;
    while(!cin || (response != 'y' && response != 'n')){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Oops! You entered something wonky. Please enter a character:  ";
        cin >> response;
    }

    cout << "\n\t4. Do you watch a lot of TV/Movies? (y/n)\t";
    cin >> response;
    while(!cin || (response != 'y' && response != 'n')){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Oops! You entered something wonky. Please enter a character:  ";
        cin >> response;
    }

    srand(time(0));
    randNum = rand()%list.getLength();
    cout << endl << *(list.getNodeValue(randNum)) << endl;

    cout << "\nHAVE FUN!!" << endl;
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
LinkedList<T>::LinkedList(){
    head = NULL;
    tail = NULL;
    int numNodes = 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
LinkedList<T>::~LinkedList(){
    ListNode *node, *next;

    node = head;
    while(node!=NULL){
        next = node->next;
        delete node;
        node = next;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
int LinkedList<T>::getLength(){
	ListNode *node;
    int counter = 0;
	
	node = head;
	
	while(node != tail){
		++counter;
		node = node->next;
		if (node == tail){
			counter++;
        }
	}
    numNodes = counter;
	return numNodes;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
T LinkedList<T>::getNodeValue(int a){
    ListNode *node;

    if(a == 0)
        return head->value;
	node = head;
    int current = 0;
	while(current <= a && node != NULL){
        if(current == a)
            return node->value;
		current++;
		node = node->next;
	}
    return node->value;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void LinkedList<T>::insertNode(T b){
    ListNode *newNode = new ListNode;
    ListNode *temp, *previous = NULL;

    newNode->value = b;
    newNode->next = NULL;

    if(!head){
        head = newNode;
        tail = newNode;
    }
    if(*tail->value < *b){
        tail->next = newNode;
        tail = newNode;
    }

    else{
        temp = head;
        previous = NULL;

        while(temp != NULL && *temp->value < *b){
            previous = temp;
            temp = temp->next;
        }
        if(previous == NULL){
            head = newNode;
            newNode->next = temp;
        }
        else{
            previous->next = newNode;
            newNode->next = temp;
        }     
    }
    
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void picture (){
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                                                                                                                                      " << endl;
    cout << "                                                             .%&&#&%@@@@%@@#.                                                                         " << endl;
    cout << "                                                        %@&@@@@@@@(@@@@@&&@@@@@@@                                                                     " << endl;
    cout << "                                                      &&@@@@@@@(&&@@@@@@@&&@@@@@@&@(                                                                  " << endl;
    cout << "                                                     &@@@@&&&&%%##(#//((//(##%%&@&&&@&                                                                " << endl;
    cout << "                                                    %@@@@#**,*,***,,.,..,,,,**//#%&&&@%(                                                              " << endl;
    cout << "                                                   *(&##/*,,,,,.........,,,,,**//(%&@%&&*                                                             " << endl;
    cout << "                                                    &&&(**,,,,,.........,,,,,***/(#%@&@%*                                                             " << endl;
    cout << "                                                   .&&&#**,,,,,.........,,,,,***/(%&&@@@#                                                             " << endl;
    cout << "                                                    .%%&**,,,,,..........,,,,***//%&@&&@&                                                             " << endl;
    cout << "                                                     ,%@**//**/**,,,,,*(%&%#((/(/((%&&@@&&                                                            " << endl;
    cout << "                                                      (&*//#@@@&&%,.,/#(%/#@%#%#///(&@&(##                                                            " << endl;
    cout << "                                                      (#*****,*,,,,,,**,,***/*,***//##%/**                                                            " << endl;
    cout << "                                                       **,,,,..,,*,,,*/*,..,.,,,*//(##(**/                                                            " << endl;
    cout << "                                                       ,(**,,,,.**,,,*/*,,,,,,**//(/(#//,                                                             " << endl;
    cout << "                                                         ***,,,,,%@&&@&&/,,,,***///(((*,                                                              " << endl;
    cout << "                                                         ****,********/**//****///(((#/                                                               " << endl;
    cout << "                                                         ./*****(%@&&&#/(%&%/*//(((((.                                                                " << endl;
    cout << "                                                          ,/******//(#(((/****/(/(##(,                                                                " << endl;
    cout << "                                                           ,/////****,*****///((###((##                                                               " << endl;
    cout << "                                                             ((///******/(/((#####(/( ...,,                                                           " << endl;
    cout << "                                                               (##((###(######%#(//..,.  /(((,,,                                                      " << endl;
    cout << "                                                              ,///(#######%##(/**  .,.  /((((////*,.......                                            " << endl;
    cout << "                                                              ./**/////(((///*    .,. */(((////////////////*........                                  " << endl;
    cout << "                                                          ..  .*(,,********.     .,. *////((/////////////////////////, ..                             " << endl;
    cout << "                                                    ,////*,,. ../,,,,,,,,., ..  ....*****/////%//////////////////////////*                            " << endl;
    cout << "                                               ,*/////////.. . . ,,,...,.,,.,.. ...********//**/////////////*/**/***///*//                            " << endl;
    cout << "                                            */////////(///...     .,........    .,*******////*//(////////*******/**/*///(/                            " << endl;
    cout << "                                          ,//////////(///* .  ..,   ,.....      ,*********,*/////////////*********/*////((                            " << endl;
    cout << "                                         ./////////(////*%*       ...          .**********///(////////***********/////((((                            " << endl;
    cout << "                                         //////////////*#.                    .**********/*/*//////*****//******/*/////(((                            " << endl;
    cout << "                                         ////////(/(//*#/                    .*********//*//*/*///*****//*****/(*////(((((                            " << endl;
    cout << "                                        ./////*//((/////                     ***********//************////***////////(((((                            " << endl;
    cout << "                                        ,/////*///(//*(.                    **********/(///*//******/////*///(/*////((((((                            " << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}