#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void changeIntensity(const char* inputFileName, const char* outputFileName, int originalLevels, int newLevels);

int main() 
{
	const char* inputFileName = "rose.raw";
	const char* outputFileName = "modified_rose.raw";
	int originalLevels = 256; // Original intensity levels (8 bits per pixel)
	int newLevels; // New intensity levels

	cout << "Enter the New Intensity Level for rose.raw image: ";
	cin >> newLevels;

    // Change intensity quantization levels and save the modified image
    changeIntensity(inputFileName, outputFileName, originalLevels, newLevels);

    cout << "Image modified and saved to " << outputFileName << endl;

	return 0;
}

// Function to change intensity quantization levels
void changeIntensity(const char* inputFileName, const char* outputFileName, int originalLevels, int newLevels) 
{
    // Check if the new intensity levels are valid
    if (newLevels <= 0 || newLevels > 256) {
        cerr << "Error: Invalid new intensity levels." << endl;
        return;
    }

    // Open the input file for reading
    ifstream inputFile(inputFileName, ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Error: Cannot open input file." << endl;
        return;
    }

    // Open the output file for writing
    ofstream outputFile(outputFileName, ios::binary);
    if (!outputFile.is_open()) {
        cerr << "Error: Cannot create output file." << endl;
        return;
    }

    // Calculate the scaling factor for intensity levels
    double scale = static_cast<double>(newLevels - 1) / (originalLevels - 1);

    // Read the input image data into a vector
    vector<unsigned char> imageData;
    unsigned char pixel;
    while (inputFile.read(reinterpret_cast<char*>(&pixel), sizeof(pixel))) {
        imageData.push_back(pixel);
    }

    // Modify intensity levels based on the scaling factor
    for (unsigned char& pixel : imageData) {
        int newIntensity = static_cast<int>(pixel * scale + 0.5); // Round to nearest integer
        pixel = static_cast<unsigned char>(newIntensity);
    }

    // Write the modified image data to the output file
    outputFile.write(reinterpret_cast<char*>(imageData.data()), imageData.size());
}