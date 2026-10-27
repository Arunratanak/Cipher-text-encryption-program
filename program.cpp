#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char alphabet[26] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G',
    'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U',
    'V', 'W', 'X', 'Y', 'Z'};

string encrypt(string plaintext, int key)
{
    key = ((key % 26) + 26) % 26;

    string ciphertext = "";

    for (int i = 0; i < plaintext.length(); i++)
    {
        char c = plaintext[i];

        if (c >= 'A' && c <= 'Z')
        {
            int position = c - 'A';
            int newPosition = (position + key) % 26;

            ciphertext += alphabet[newPosition];
        }
        else if (c >= 'a' && c <= 'z')
        {
            int position = c - 'a';
            int newPosition = (position + key) % 26;

            ciphertext += alphabet[newPosition] + 32;
        }
        else
        {
            ciphertext += c;
        }
    }
    return ciphertext;
}

int main()
{
    string plaintext;
    int key;
    cout << "Enter the message you want to encrypt: ";
    cin >> plaintext;

    cout << "Enter the key: ";
    cin >> key;

    string encryptedMessage = encrypt(plaintext, key);

    cout << "\n_____ENCRYPTION RESULT_____" << endl;
    cout << "Original: " << plaintext << endl;
    cout << "Encrypted: " << encryptedMessage << endl;

    return 0;
}
