#include <iostream>
#include <string>
#include <vector>
#ifndef RECURSIVE_FUNC
#define RECURSIVE_FUNC
#endif

std::vector<std::string> split(const std::string& s, const char delimiter, bool ignore_empty = false){
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

int sum_recursive(const std::vector<int>& v){
    RECURSIVE_FUNC

        // Base case: when the vector is empty
        if (v.empty()) {
        return 0;
    }

    // Sum the first element and recursively sum the rest of the vector
    return v[0] + sum_recursive(std::vector<int>(v.begin() + 1, v.end()));
}

// Do not modify the rest of the code, or the automated testing won't work.
#ifndef UNIT_TESTING
int main()
{
    std::cout << "Enter integers separated by spaces: ";
    std::string line;
    getline(std::cin, line);
    std::vector<std::string> strings = split(line, ' ', true);
    std::vector<int> integers;
    for(const auto& s : strings){
        integers.push_back(stoi(s));
    }

    std::cout << "Sum: " << sum_recursive(integers) << std::endl;
}
#endif
