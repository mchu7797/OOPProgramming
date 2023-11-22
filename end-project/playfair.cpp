//
// Created by Minseok Chu on 11/14/23.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

class PlayFair {
    char mTable[25] = {0};
    std::string mPair;
    std::string mKey;

public:
    PlayFair(const std::string &encryptKey, std::string overlappedPair);

    void MakeTable();

    void ShowTable();

    std::string EncryptString(std::string string);

    void EncryptFile(std::string inputFilename, std::string outputFilename);
};

std::string RemoveDuplicates(std::string string) {
    for (int i = 0; i < string.size(); i++) {
        int j = i + 1;

        while (j < string.size()) {
            if (string[i] == string[j]) {
                string.erase(j, 1);
            } else {
                ++j;
            }
        }
    }

    return string;
}

PlayFair::PlayFair(const std::string &encryptKey, std::string overlappedPair) {
    if (overlappedPair.length() != 2) {
        throw std::invalid_argument("mKey must be string of length 2");
    }

    this->mPair = encryptKey;
    this->mKey = overlappedPair;
}

void PlayFair::MakeTable() {
    std::string encryptKeyBase = RemoveDuplicates(mPair);
    std::string anotherElements;

    bool overlapFound = false;

    for (int i = 0; i < encryptKeyBase.size(); i++) {
        int j = 0;

        while (j < mKey.size()) {
            if (encryptKeyBase[i] == mKey[j]) {
                if (overlapFound) {
                    encryptKeyBase.erase(i, 1);
                } else {
                    encryptKeyBase.replace(i, 1, "0");
                    overlapFound = true;
                    ++j;
                }
            } else {
                ++j;
            }
        }
    }

    for (char i = 'a'; i <= 'z'; i++) {
        int j = 0;

        while (j < encryptKeyBase.size()) {
            if (encryptKeyBase[j] == i) {
                break;
            }
            ++j;
        }

        int k = 0;

        while (k < mKey.size()) {
            if (mKey[k] == i) {
                break;
            }
            ++k;
        }

        if (k < mKey.size()) {
            if (!overlapFound) {
                anotherElements.push_back('0');
                overlapFound = true;
            }

            continue;
        }

        if (j == encryptKeyBase.size()) {
            anotherElements.push_back(i);
        }
    }

    int n = 0;
    int m = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (n < encryptKeyBase.size()) {
                mTable[i * 5 + j] = encryptKeyBase[n++];
            } else {
                if (m < anotherElements.size()) {
                    mTable[i * 5 + j] = anotherElements[m++];
                }
            }
        }
    }
}


void PlayFair::ShowTable() {
    std::cout << "-- Encrypt Matrix --" << std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << mTable[i * 5 + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-- Matrix Ends --" << std::endl;
    std::cout << "'0' can be '" << mKey[0] << "' or '" << mKey[1] << "'" << std::endl;
}


std::string PlayFair::EncryptString(std::string string) {
    for (int i = 0; i < string.size(); i++) {
        if (!isalpha(string[i])) {
            string.erase(i, 1);
        }
    }

    for (int i = 0; i < string.size(); i++) {
        int j = 0;

        while (j < mKey.size()) {
            if (string[i] == mKey[j]) {
                break;
            } else {
                ++j;
            }
        }

        if (j < mKey.size()) {
            i = '0';
        }
    }

    for (int i = 0; i < string.size(); i += 2) {
        if (string[i] == string[i + 1]) {
            string.insert(i + 1, "x");
        }
    }

    if (string.length() % 2 != 0) {
        string.push_back('x');
    }

    for (int i = 0; i < string.size(); i += 2) {
        int charPosition[2][2] = {0};

        // Make positions of encryption table
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (mTable[j * 5 + k] == string[i]) {
                    charPosition[0][0] = j;
                    charPosition[0][1] = k;
                }
                if (mTable[j * 5 + k] == string[i + 1]) {
                    charPosition[1][0] = j;
                    charPosition[1][1] = k;
                }
            }
        }

        if (charPosition[1][0] == charPosition[0][0]) {
            // If y point is same.
            charPosition[0][1] = charPosition[0][1] + 1 > 4 ? 0 : charPosition[0][1] + 1;
            charPosition[1][1] = charPosition[1][1] + 1 > 4 ? 0 : charPosition[1][1] + 1;
        } else if (charPosition[1][1] == charPosition[0][1]) {
            // If x point is same.
            charPosition[0][0] = charPosition[0][0] + 1 > 4 ? 0 : charPosition[0][0] + 1;
            charPosition[1][0] = charPosition[1][0] + 1 > 4 ? 0 : charPosition[1][0] + 1;
        } else {
            int temp = charPosition[0][1];
            charPosition[0][1] = charPosition[1][1];
            charPosition[1][1] = temp;
        }

        string[i] = mTable[charPosition[0][0] * 5 + charPosition[0][1]];
        string[i + 1] = mTable[charPosition[1][0] * 5 + charPosition[1][1]];
    }

    return string;
}

void PlayFair::EncryptFile(std::string inputFilename, std::string outputFilename) {
    std::ifstream inputFile(inputFilename, std::ios::in);
    std::ofstream outputFile(outputFilename, std::ios::out);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        throw std::runtime_error("Cannot open encryption files!");
    }

    outputFile << "ENCRYPTION KEY  : " << mPair << std::endl;
    outputFile << "OVERLAPPED PAIR : '" << mKey[0] << "', '" << mKey[1] << "'" << std::endl;

    while (!inputFile.eof()) {
        std::string rawLine, newLine;
        getline(inputFile, rawLine, '.');
        outputFile << EncryptString(rawLine) << std::endl;
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    std::string encryptKey, overlappedPair, input;
    int modeSelection;

    std::cout << "TYPE ENCRYPT KEY : ";
    std::cin >> encryptKey;

    std::cout << "TYPE OVERLAPPED PAIR : ";
    std::cin >> overlappedPair;

    std::cout << "TYPE MODE SELECTION CODE (0 => File, 1 => Console) : ";
    std::cin >> modeSelection;

    std::cin.ignore();

    PlayFair playFair(encryptKey, overlappedPair);

    playFair.MakeTable();
    playFair.ShowTable();

    if (modeSelection == 0) {
        std::string inputFilename, outputFilename;

        std::cout << "TYPE INPUT FILE PATH : ";
        std::cin >> inputFilename;

        std::cout << "TYPE OUTPUT FILE PATH : ";
        std::cin >> outputFilename;

        playFair.EncryptFile(inputFilename, outputFilename);

        std::cout << "ENCRYPTION ENDED!" << std::endl;
    } else if (modeSelection == 1) {
        while (true) {
            std::cout << "TYPE STRING FOR ENCRYPT : ";
            getline(std::cin, input);

            if (input == "exit") {
                break;
            }

            std::cout << input << std::endl;
            std::cout << playFair.EncryptString(input) << std::endl;
        }
    } else {
        throw std::runtime_error("Mode selection code must be 1 or 0");
    }

    return EXIT_SUCCESS;
}
