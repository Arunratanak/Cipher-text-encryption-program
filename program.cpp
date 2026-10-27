#include <iostream>
#include <string>
#include <limits>

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

string decrypt(string ciphertext, int key)
{
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
    int choice;
    while (true)
    {
        cout << "Choose an option: \n";
        cout << "1. Encrypt\n";
        cout << "2. Decrypt\n";
        cout << "Enter (1 or 2): ";
        if (cin >> choice && (choice == 1 || choice == 2))
        {
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // fix 3
        cout << "Invalid choice. Please try again.\n\n";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // fix 2

    string text;
    int key;

    if (choice == 1)
    {
        cout << "Enter the message you want to encrypt: ";
    }
    else
    {
        cout << "Enter the message you want to decrypt: ";
    }
    getline(cin, text);

    cout << "Enter the key: ";
    while (!(cin >> key)) // fix 1, with validation
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid key. Enter a number: ";
    }

    if (choice == 1)
    {
        string encryptedMessage = encrypt(text, key);
        cout << "\n_____ENCRYPTION RESULT_____" << endl;
        cout << "Original: " << text << endl;
        cout << "Encrypted: " << encryptedMessage << endl;
    }
    else
    {
        string plaintext = decrypt(text, key);
        cout << "\n_____DECRYPTION RESULT_____" << endl;
        cout << "Original: " << text << endl;
        cout << "Decrypted: " << plaintext << endl;
    }

    return 0;
}