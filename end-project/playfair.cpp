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
    PlayFair(std::string encryptKey, std::string overlappedPair);

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

PlayFair::PlayFair(std::string encryptKey, std::string overlappedPair) {
    if (overlappedPair.length() != 2) {
        throw std::invalid_argument("Overlapped fair must be string of length 2");
    }

    this->mPair = overlappedPair;
    this->mKey = encryptKey;
}

void PlayFair::MakeTable() {
    std::string encryptKeyBase = RemoveDuplicates(mKey);
    std::string anotherElements;

    bool overlapFound = false;

    for (int i = 0; i < encryptKeyBase.size(); i++) {
        int j = 0;

        // encryptKeyBase에 있는 mPair 요소 치환
        while (j < mPair.size()) {
            if (encryptKeyBase[i] == mPair[j]) {
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

    /* 알파벳 요소 중 mKey와 겹치는 문자를 제외하고 anotherElements에 추가*/
    for (char i = 'a'; i <= 'z'; i++) {
        /* mPair 중복 제거 */
        /* mPair 중복 제거가 선행되지 않으면, 0으로 치환되서 들어가야 할 문자가 mKey와 겹친다고 테이블에서 그냥 빠져버릴 수 있음 */

        if (i == mPair[0] || i == mPair[1]) {
            if (!overlapFound) {
                anotherElements.push_back('0');
                overlapFound = true;
            } else {
                continue;
            }
        }

        /* mKey 중복 제거 */

        bool notDuplicated = true;

        for (int j = 0; j < encryptKeyBase.size(); ++j) {
            if (i == encryptKeyBase[j]) {
                notDuplicated = false;
            }
        }

        if (notDuplicated) {
            anotherElements.push_back(i);
        }
    }

    /* 테이블 채우기 */

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
    std::cout << "'0' can be '" << mPair[0] << "' or '" << mPair[1] << "'" << std::endl;
}


std::string PlayFair::EncryptString(std::string string) {
    /* 알파벳이 아닌 문자 전부 제거 */
    for (int i = 0; i < string.size(); ++i) {
        if (!isalpha(string[i])) {
            string.erase(i, 1);
        }
    }

    /* 테이블이 소문자로 구성되어 있기 때문에 모든 알파벳을 소문자로 변경 */
    for (int i = 0; i < string.size(); ++i) {
        if (isupper(string[i])) {
            string[i] = tolower(string[i]);
        }
    }

    /* mPair에 해당하는 문자를 0으로 먼저 치환 */
    for (int i = 0; i < string.size(); ++i) {
        if (string[i] == mPair[0] || string[i] == mPair[1]) {
            string[i] = '0';
        }
    }

    /* 문자 짝들 중 서로 같은 글자일 경우 그 사이에 x 추가 */
    for (int i = 0; i < string.size(); i += 2) {
        if (string[i] == string[i + 1]) {
            string.insert(i + 1, "x");
        }
    }

    /* 문자열 짝수개로 만들기 */
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
            // Anything else.
            int temp = charPosition[0][1];
            charPosition[0][1] = charPosition[1][1];
            charPosition[1][1] = temp;
        }

        string[i] = mTable[charPosition[0][0] * 5 + charPosition[0][1]];
        string[i + 1] = mTable[charPosition[1][0] * 5 + charPosition[1][1]];
    }

    for (int i = 0; i < string.size(); ++i) {
        if (string[i] == '0') {
            string[i] = mPair[0];
        }
    }

    return string;
}

void PlayFair::EncryptFile(std::string inputFilename, std::string outputFilename) {
    std::ifstream inputFile(inputFilename, std::ios::in);
    std::ofstream outputFile(outputFilename, std::ios::out);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        throw std::runtime_error("Cannot open encryption files!");
    }

    outputFile << "ENCRYPTION KEY  : " << mKey << std::endl;
    outputFile << "OVERLAPPED PAIR : '" << mPair[0] << "', '" << mPair[1] << "'" << std::endl;

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
