#include <iostream>
#include <vector>
#include <random>
using namespace std;

vector<vector<int> >generateRandomMatrix(int rows, int cols) {
    vector<vector<int> > matrix(rows, vector<int>(cols));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0,1000);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = dist(gen);
        }
    }

    return matrix;
}

parsec_roi_begin();

int main(){
    const int tensorSize = 256;
    const int numIndices = 1000;

    vector<vector<int> >inputTensor = generateRandomMatrix(tensorSize, tensorSize);
    vector<int> indices(numIndices);

    for (int i = 0; i < numIndices; ++i) {
        indices[i] = rand() % (tensorSize * tensorSize);
    }

    vector<int> gatheredElements(numIndices);

    for (int i = 0; i < numIndices; ++i) {
        int index = indices[i];
        int row = index / tensorSize;
        int col = index % tensorSize;
        gatheredElements[i] = inputTensor[row][col];
    }

    for (int i = 0; i < numIndices; ++i) {
        std::cout << "Gathered Element " << i << ": " << gatheredElements[i] << std::endl;
    }
    
}
parsec_roi_end();