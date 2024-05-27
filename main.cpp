#include <iostream>

using namespace std;

bool empty(const string& word) {
    return word[0] == '\0';
}

int sizeOfString(const string& str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool allDigitsAreNumbers(const string& word) {
    for (int i = 0; i < sizeOfString(word); i++) {
        if (!isDigit(word[i])) {
            return false;
        }
    }
    return true;
}

int thereIsADot(const string& word) {
    for (int i = 0; i < sizeOfString(word); i++) {
        if (word[i] == '.') {
            if(i == sizeOfString(word) - 1) {
                break;
            }
            return i;
        }
    }
    return -1;
}

bool verifyDigitsInFloat(const string& word, int dotIndex) {
    string temp1, temp2;
    for (int i = 0; i < dotIndex; i++) {
        temp1 += word[i];
    }
    for (int i = dotIndex + 1; i < sizeOfString(word); i++) {
        temp2 += word[i];
    }

    if (allDigitsAreNumbers(temp1) && allDigitsAreNumbers(temp2)) {
        return true;
    } else {
        return false;
    }
}

bool isWord(const string& word) {
    if (empty(word)) {
        return false;
    }

    if (!isAlpha(word[0])) {
        return false;
    }

    for (int i = 1; i < sizeOfString(word); i++) {
        if (!isAlpha(word[i]) && !isDigit(word[i])) {
            return false;
        }
    }

    return true;
}

bool isValidWord(const string& word) {
    char myList[] = {'"', '\''};
    string temp;

    if (allDigitsAreNumbers(word)) {
        return true;
    }

    int dotIndex = thereIsADot(word);
    if (verifyDigitsInFloat(word, dotIndex)) {
        return true;
    }

    if (word[0] == myList[0] && (word[sizeOfString(word) - 1] == myList[0])) { // NOLINT(*-branch-clone)
        return true;
    } else if(word[0] == myList[1] && (word[sizeOfString(word) - 1] == myList[1]) && sizeOfString(word) == 3) {
        return true;
    } else {
        return isWord(word);
    }
}

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    if (isValidWord(word)) {
        cout << word << " is a valid word." << endl;
    } else {
        cout << word << " is not a valid word." << endl;
    }

    return 0;
}
