#include <iostream>
#include <fstream>
#include <map>

using namespace std;

map<string, int> split(const string& line, char delimiter){
    map<string, int> info;
    string name = "";
    string word = "";
    int points = 0;
    for (char character : line){
        if (character != delimiter){
            word += character;
        }
        else{
            name = word;
            word = "";
        }}
    points += stoi(word);
    info[name] = points;
    return info;
}

int main()
{
    map<string, int> info;

    string input;
    cout << "Input file: ";
    getline(cin, input);

    ifstream input_file(input);
    if (not input_file or input_file.eof()) {
        cout << "Error! The file " << input << " cannot be opened." << endl;
        return EXIT_FAILURE; }

    string line;
    while (getline(input_file, line))
    {
        map<string, int> temp = split(line, ':');
        for (auto pair : temp){
            if (info.find(pair.first) == info.end()){
                info[pair.first] = pair.second;
            }
            else{
                info[pair.first] += pair.second;
            }
        }}
    cout << "Final scores:" << endl;
    for (auto pair : info){
        cout << pair.first << ": " << pair.second << endl;
    }

    input_file.close();
    return 0;
}
