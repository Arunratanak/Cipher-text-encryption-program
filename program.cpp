#include <iostream>
#include <string>
using namespace std;

string decrypt(string ciphertext, int key)
{
    char alphabet[26] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G',
        'H', 'I', 'J', 'K', 'L', 'M', 'N',
        'O', 'P', 'Q', 'R', 'S', 'T', 'U',
        'V', 'W', 'X', 'Y', 'Z'};

    key = ((key % 26) + 26) % 26;

    string plaintext = "";

    for (int i = 0; i < ciphertext.length(); i++)
    {
        char c = ciphertext[i];

        if (c >= 'A' && c <= 'Z')
        {
            int position = c - 'A';
            int newPosition = (position - key + 26) % 26;

            plaintext += alphabet[newPosition];
        }
        else if (c >= 'a' && c <= 'z')
        {
            int position = c - 'a';
            int newPosition = (position - key + 26) % 26;

            plaintext += alphabet[newPosition] + 32;
        }

        else
        {
            plaintext += c;
        }
    }
    return plaintext;
}

int main()
{
    string ciphertext;
    int key;

    cout << "Enter ciphertext: ";
    cin >> ciphertext;

    cout << "Enter the key: ";
    cin >> key;

    string plaintext = decrypt(ciphertext, key);

    cout << "PLaintext: " << plaintext << endl;

    return 0;
}