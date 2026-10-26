#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string getCipherKey() {
    return "QWERTYUIOPASDFGHJKLZXCVBNM";
}

string encryptMessage(const string& message, const string& cipherAlphabet) {
    const string normalAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string encryptedText = "";

    for (char c : message) {
        if (isupper(c)) {
            size_t index = normalAlphabet.find(c);
            encryptedText += cipherAlphabet[index];
        }
        else if (islower(c)) {
            char upperC = toupper(c);
            size_t index = normalAlphabet.find(upperC);
            encryptedText += tolower(cipherAlphabet[index]);
        }

        else {
            encryptedText += c;
        }
    }
    return encryptedText;
}

int main() {
    string secretMessage;
    cout << "Enter the message you want to encrypt: ";
    getline(cin, secretMessage);

    string secretKey = getCipherKey();
    string encryptedMessage = encryptMessage(secretMessage, secretKey);
    
    cout << "\n_____ENCRYPTION RESULT_____" << endl;
    cout << "Original: " << secretMessage << endl;
    cout << "Encrypted: " << encryptedMessage << endl;

    return 0;
}
