#include <iostream>
#include <string>
#include <vector>


// TODO: Implement split function here
// Do not change main function
 std::vector< std::string >  split(std::string line,char separator,bool ignore_empty=false)
{
    std::vector<std::string > parts = {};
    std::string::size_type length = line.length();


    std:: string part = "";
    for (std::string::size_type i = 0; i<length;++i){
        if (ignore_empty){
                if (line.at(i) != separator){
                    part += line.at(i);
                    if(i == length-1){parts.push_back(part);}
                }else{
                    if (part != ""){
                        parts.push_back(part);}
                    part = "";
                   continue;
                }
        }
        else{
            if (line.at(i) != separator){
                part += line.at(i);
                if(i == length-1){parts.push_back(part);}
            }else{

                parts.push_back(part);
                part="";
                if(i == length-1){parts.push_back(part);}


            }

        }

    }return parts;

}

int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
