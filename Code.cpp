#include <string>
#include <iostream>

using namespace std;

class Vigenere
{
public:
    static string keyGen(string str, string key)
    {
        int strLen = str.size();
        int index = 0;
        while(key.size() != str.size()){
            if( index == strLen ){
                index = 0;
            }
            key += key[index];
            index++;
        }

        return key;
    }

    static string encrypt(string str, string key)
    {
        string encText;
        for (int i = 0; i < str.size(); i++)
        {
            char x = (str[i] + key[i]) % 26;
            x += 'A';
            encText += x;
        }
        return encText;
    }

    static string decrypt(string encText, string key)
    {
        string text;
        for (int i = 0; i < encText.size(); i++)
        {
            char x = (encText[i] - key[i] + 26) % 26;
            x += 'A';
            text += x;
        }
        return text;
    }
};

int main()
{
    string text;
    cout << "Enter text:" << endl;
    cin >> text;
    string keyword;
    cout << "Enter keyword:" << endl;
    cin >> keyword;
 
    string key = Vigenere::keyGen(text, keyword);
    string encText = Vigenere::encrypt(text, key);
 
    cout << "Encrypted text: " << encText << endl;
    cout << "Decrypted text : " << Vigenere::decrypt(encText, key) << endl;
}
