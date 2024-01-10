#include "queue.h"

int main(){
    Queue normLine, ipLine;
    int input, input2;
    string name, name2;

    do{
        cout << "1)\tAdd rider to wait line." << endl;
        cout << "2)\tRemove rider from line." << endl;
        cout << "3)\tDone for the day." << endl;
        cout << "Pick 1-3:" << endl;
        cin >> input;
        while(input>3 || input<1){
            cout << "Input Invalid! Please Choose 1-3!" << endl;
            cin >> input;
        }
        cin.ignore();

        switch(input){
            case 1:
                cout << "Name?" << endl;
                getline(cin, name);
                cout << name << ", do you have a(n):" << endl;
                cout << "1) Normal Pass?" << endl;
                cout << "2) Instant Access Pass" << endl;
                cout << "Choose 1 or 2:" << endl;
                cin >> input2;
                while(input2 != 1 && input2 != 2){
                    cout << "Input Invalid! Please Choose 1 or 2!" << endl;
                    cin >> input2;
                }
                cin.ignore();
                if(input2 == 1)
                    normLine.enqueue(name);
                else
                    ipLine.enqueue(name);
                break;
            case 2:
                if(ipLine.isEmpty()){
                    name2 = normLine.dequeue();
                    if(normLine.isEmpty() == false)
                        cout << name2 << ", Normal Pass holder, YOU ARE RIDING!" << endl;
                }
                else{
                    name2 = ipLine.dequeue();
                    cout << name2 << ", Instant Pass holder, YOU ARE RIDING!" << endl;
                }
                break;
            default:
                break;
        }

    }while(input != 3);
    cout << "IT IS QUITTING TIME!" << endl;

    return 0;
}