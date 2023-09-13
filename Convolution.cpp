#include <iostream>
#include <vector>
#include <random>

using namespace std;


vector<vector<int> >generateRandomMatrix(int rows, int cols) {
    vector<vector<int> > matrix(rows, vector<int>(cols));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0,20);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = dist(gen);
        }
    }

    return matrix;
}


vector<vector<int> >getConvolution(const vector<vector<int> >& inputImage, const vector<vector<int> >& kernel) {
    int inputHeight = inputImage.size();
    int inputWidth = inputImage[0].size();
    int kernelSize = kernel.size();

    int outputHeight = inputHeight - kernelSize + 1;
    int outputWidth = inputWidth - kernelSize + 1;

    vector<vector<int> >output(outputHeight, vector<int>(outputWidth, 0.0));

    // Perform convolution
    for (int i = 0; i < outputHeight; ++i) {
        for (int j = 0; j < outputWidth; ++j) {
            for (int m = 0; m < kernelSize; ++m) {
                for (int n = 0; n < kernelSize; ++n) {
                    output[i][j] += inputImage[i + m][j + n] * kernel[m][n];
                }
            }
        }
    }

    return output;
}

parsec_roi_begin();
int main() {
    
    const int tensorSize = 256;
    const int kernelSize = 5;

    // Generate random input image and kernel
    vector<vector<int> >inputImage = generateRandomMatrix(tensorSize, tensorSize);
    vector<vector<int> >kernel = generateRandomMatrix(kernelSize, kernelSize);

    // Perform convolution with stride 1 and the random kernel
    vector<vector<int> >output = getConvolution(inputImage, kernel);

    // Print a portion of the resulting image for demonstration (adjust as needed)
    const int displaySize = 10;
    for (int i = 0; i < displaySize; ++i) {
        for (int j = 0; j < displaySize; ++j) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
parsec_roi_end();