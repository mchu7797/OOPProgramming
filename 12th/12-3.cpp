//
// Created by Minseok Chu on 2023-10-30.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    const char *inputFileName = "enc.txt";
    const char *outputFilename = "result.txt";

    ifstream inputStream(inputFileName);
    ofstream outputStream(outputFilename);

    if (!inputStream) {
        cout << inputFileName << " : Read Error!" << endl;
        return EXIT_FAILURE;
    }

    if (!outputStream) {
        cout << outputFilename << " : Write Error!" << endl;
        return EXIT_FAILURE;
    }

    int count[26] = {0};
    int charData;

    while ((charData = inputStream.get()) != EOF) {
        cout << (char) charData;

        if (charData >= 'A' && charData <= 'Z') {
            count[charData - 'A']++;
        }

        if (charData >= 'a' && charData <= 'z') {
            count[charData - 'a']++;
        }
    }

    for (int i = 0; i < 26; ++i) {
        outputStream << (char) (i + 'A') << ":" << count[i] << endl;
    }

    inputStream.close();
    outputStream.close();

    return EXIT_SUCCESS;
}