#include <iostream>
#include <vector>
#include <random>

using namespace std;


int main() {

    const int tensorSize = 256;
    const int numIndices=1000;
    const int numDataSamples =1000;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0,1000);

    vector<vector<int> > inputTensor(tensorSize, vector<int>(tensorSize));
    

    // Generate random indices (between 0 and tensorSize*tensorSize - 1)
    vector<int> indices(numIndices);
    for (int i = 0; i < numIndices; ++i) {
        indices[i] = rand() % (tensorSize * tensorSize);
    }

    // Generate random data samples (you can replace this with your actual data)
    vector<float> data(numDataSamples);
    for (int i = 0; i < numDataSamples; ++i) {
        data[i] = dist(gen);
    }

    for (int i = 0; i < numIndices; ++i) {
        int index = indices[i];
        if (index >= 0 && index < tensorSize * tensorSize) {
            int row = index/tensorSize;
            int col =index%tensorSize;
            inputTensor[row][col] = data[i];
        }
    }

    // Print some elements of the resulting tensor to verify
    std::cout << "Sample tensor elements:" << std::endl;

    for (int i = 0; i < inputTensor.size(); ++i) {
        for (int j = 0; j < inputTensor[i].size(); ++j) {
            std::cout << inputTensor[i][j] << " ";
        }
        std::cout << std::endl; // Move to the next row
    }
    
    std::cout << std::endl;

    // Clean up allocated memory
    //delete[] tensor;

    return 0;
}
