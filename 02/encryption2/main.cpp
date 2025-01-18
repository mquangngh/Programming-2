#include <iostream>
#include<cctype>
using namespace std;

int main()
{
    string key;
    cout << "Enter the encryption key: ";
    cin >>key;
    int length = key.length();
    if ( length != 26){
        cout << "Error! The encryption key must contain 26 characters.";
        return EXIT_FAILURE;
    }
    for (int i=0;i<length;++i){
        char letter;
        letter = key.at(i);

        if(isupper(letter)){
            cout << "Error! The encryption key must contain only lower case characters.";
            return EXIT_FAILURE;
        }

    }
    for( char character = 'a'; character < 'z'; ++character ){
        string::size_type location = 0;
        location = key.find(character);

        if ( location == string::npos ) {
            cout <<"Error! The encryption key must contain all alphabets a-z.";
            return EXIT_FAILURE;

        }


    }
    string encrypted = "";
    cout <<"Enter the text to be encrypted: ";
    cin >> encrypted;
    int length2 = encrypted.length();
    for (int i=0;i<length2;++i){
        char letter;
        letter = encrypted.at(i);

        if(isupper(letter) or isdigit(letter)){
            cout << "Error! The text to be encrypted must contain only lower case characters.";
            return EXIT_FAILURE;
        }

    }cout <<"Encrypted text: ";
    char encrypted_char;
    for (int i = 0;i<length2;++i){
        encrypted_char=encrypted.at(i);
        int index = 0;
        for( char character = 'a'; character < 'z'; ++character ){
            if (character!=encrypted_char){
                index += 1;
            }else {
                break;
            }
        }string result;
        result=key.at(index);

        cout<<result;
    }






    return 0;
}
