/************************************************
 * Name: Austin Ring
 * Date: 4/18/21
 ************************************************/
#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H
#include <iostream>
#include <fstream>
using namespace std;

class GraphMatrix{
    private:
        int ** vertexMatrix;
        int numVertices, numEdges;

    public:
        GraphMatrix(int vert){
            this->numVertices = vert;
            vertexMatrix = new int*[numVertices];
            for(int i=0; i<numVertices; i++){
                vertexMatrix[i] = new int[numVertices];
                for(int x=0; x<numVertices; x++)
                    vertexMatrix[i][x]=0;
            }
        }
        //////////////////////////////////////////////////////////
        ~GraphMatrix(){
            for(int i=0; i<numVertices; i++)
                delete [] vertexMatrix[i];
            delete [] vertexMatrix;
        }
        //////////////////////////////////////////////////////////
        void addEdge(int vert1, int vert2){
            vertexMatrix[vert1][vert2]=1;
        }
        //////////////////////////////////////////////////////////
        void printGraph(){
            cout << "\nAdjacency List:" << endl;
            for(int i=0; i<numVertices; i++){
                for(int x=0;x<numVertices; x++)
                    cout << vertexMatrix[i][x] << ' ';
                cout << endl;
            }
        }
        //////////////////////////////////////////////////////////
        bool isThereAnEdge(int row, int col){
            if(vertexMatrix[row][col]==1)
                return true;
            else
                return false;
        }
        //////////////////////////////////////////////////////////
};

#endif