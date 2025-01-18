#include <fstream>
#include <iostream>
#include <string>
//using namespace std;

//int main()
//{
    //string filename = "";
    //getline(cin,filename);
    //cout <<"Input file: " <<filename <<".input"<<endl;
    //cout <<"Output file: " <<filename <<".output"<<endl;
    //ifstream file_object(filename);
    //if ( not file_object)
    //{
       // cout << "Error! The file "<<filename<<".input " <<"cannot be opened.";
        //return EXIT_FAILURE;
    //}
    //else{
      //  while(getline(file_object,line)){
        //    for (int i=1,i<)
          //  line
        //}
    //}
//}


int main() {
    std::string inputFileName, outputFileName;

    // Get input file name
    std::cout << "Input file: ";
    std::cin >> inputFileName;

    // Get output file name
    std::cout << "Output file: ";
    std::cin >> outputFileName;

    // Open input file
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error! The file " << inputFileName << " cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }

    // Open output file
    std::ofstream outputFile(outputFileName);

    // Read input file line by line and write to output file with line numbers
    std::string line;
    int lineNumber = 1;
    while (std::getline(inputFile, line)) {
        outputFile << lineNumber << " " << line << std::endl;
        lineNumber++;
    }

    // Close files
    inputFile.close();
    outputFile.close();



    return 0;
}

