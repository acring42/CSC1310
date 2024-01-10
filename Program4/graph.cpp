/************************************************
 * Name: Austin Ring
 * Date: 4/18/21
 ************************************************/
#include "GraphMatrix.h"
#include "GraphList.h"
#include "Stack.h"

int main(){
    int numVert, vert1, vert2;
    string filename;
    cout << "Which file would you like to use? ex. filename.txt" << endl;
    getline(cin, filename);
    ifstream file;
    file.open(filename);
    file >> numVert;
    GraphMatrix myGraphMatrix(numVert);
    GraphList myGraphList(numVert);

    while(file >> vert1){
        file >> vert2;
        myGraphMatrix.addEdge(vert1,vert2);
        myGraphList.addEdge(vert1,vert2);
    }

    myGraphMatrix.printGraph();
    myGraphList.printGraph();
    file.close();

    Stack<int> stackObj;
    bool* visited = new bool[numVert];
    for(int i=0; i<numVert; i++)
        visited[i] = false;
    int num;

    stackObj.push(0);
    cout << "\nNow traversing and printing graph vertices with DFS." << endl;
    while(!stackObj.isEmpty()){
        stackObj.pop(num);
        cout<< num << " ";
        visited[num] = 1;
        for(int i=numVert-1; i>0; --i){
            if(myGraphMatrix.isThereAnEdge(num, i) && !visited[i]){
                stackObj.push(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}