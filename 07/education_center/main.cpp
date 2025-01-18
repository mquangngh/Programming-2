/*
 *
 * Desc:
 * Project: education center
 *
 * In this program, users can manage a course's information which includes
 * its enrollments, theme, location. Moreover, users can check the courses
 * of a specific theme or themes of a specific location.
 * Some additional features are checking available courses, favorite themes (most enrollments)
 *
 *
 * Program author
 * Name: Quang Nguyen
 * Student number: 152276070
 * UserID: phqung
 * E-Mail: quang.h.nguyen@tuni.fi
 *
 * Notes about the program and it's implementation (if any):
 *
 * */


#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <set>


using namespace std;

struct Course {

    string name;
    string theme;
    string location;
    int enrollments;
};
enum FIELDS {LOCATION, THEME, COURSE, ENROLLMENTS, FIELD_COUNT};

const unsigned int MAX_ENROLLMENTS = 50;

// A map accessing to location -> theme -> course_name -> course_info.
using Location_info = map<string, map<string, map<string, Course>>>;


vector<string> split(const string& s,
                               const char delimiter,
                               bool ignore_empty = false)
{
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter) + 1, tmp.size());
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


bool check_empty_field(vector<string>& fields)
{
    if (fields.size() != FIELD_COUNT) //check if the number of fields is four.
    {
        return false;
    }

    for (auto& field : fields)
    {//Check if one field is missing a value
        if (field.find_first_not_of(' ') == string::npos)
        {
            return false;
        }
    }
    return true;
}

// This function inserts information from the input file to the data structure.
void insert_course (Location_info& all_courses, string location, string theme,
string course, int enrollments)
{
    all_courses[location][theme][course]= {course, theme, location, enrollments};

}

// Process the input file and populate each line to the map
bool read_input_file (Location_info& all_courses)
{
    string input_file_name = "";
    cout <<"Input file: ";
    getline(cin,input_file_name);

    ifstream file_object(input_file_name);
    if (not file_object)
    {
        cout <<"Error: the input file cannot be opened";
        return false;
    }
    string line="";
    while (getline(file_object,line))
    {
        vector<string> fields = split(line,';');
        // Check if any part of the fields is empty
        if (not check_empty_field(fields))
        {
            cout <<"Error: empty field";
            return false;
        }
        int enrollment = 0;

        if (fields.at(ENROLLMENTS)=="full")
        { // In case of a full course, its enrollment is 50.
            enrollment = MAX_ENROLLMENTS;
        }
        else
        { // The enrollments info are converted to int before populating
            enrollment = stoi(fields.at(ENROLLMENTS));

        }
        // After checking and conversion, start inserting data to the map.
        insert_course(all_courses, fields.at(LOCATION), fields.at(THEME),
                                                        fields.at(COURSE), enrollment);
    }
    return true;
}


// This function shows all the location in alphabetical order.
void command_locations(Location_info& all_courses)
{
    for (auto& location : all_courses) // location is pair<string, map...>
    {
        cout <<location.first <<endl;  // print out the location name.
    }
}

//This function shows all the themes of the input location in alphabetical order.
void command_themes_in_location(Location_info& all_courses, string location)
{
    if (all_courses.find(location) == all_courses.end() )
    {// The location cannot be found
        cout << "Error: unknown location" << endl;
        return;
    }
    // Iterate through themes of the input location
    for (auto& theme : all_courses.at(location)) // theme is pair <string, map<...>>
    {
        cout << theme.first <<endl;             // print out the theme's name.
    }
}

// This function shows a course's information from the input location and theme
void command_courses(Location_info& all_courses, string location, string theme)
{   // First it checks if the input location is available, then checks the input theme
    if (all_courses.find(location) == all_courses.end() )
    {// The location cannot be found
        cout << "Error: unknown location name" << endl;
        return;
    }

     set<string> themes; //initialize a set of themes of the input location
     for (auto& info : all_courses.at(location)){
            themes.insert(info.first);
        }

     if (themes.find(theme) == themes.end() )
     {  // theme cannot be found in that location

         cout << "Error: unknown theme" << endl;
         return;
     }


    for (auto& course : all_courses.at(location).at(theme))
    {
        cout << course.first <<" --- "; // print course name

        auto& course_info = course.second;
        if (course_info.enrollments == MAX_ENROLLMENTS)
        {
            cout << "full" <<endl;
        }else
        {
            cout << course_info.enrollments << " enrollments" <<endl;
        }

    }
}

// This function removes the redundant character from user's input
string str_remove_character(string str, char ch) {
    string result_str; // Initialize an empty string to store the modified string


    for (size_t i = 0; i < str.size(); ++i)
    { // Loop through each character in the input string
        if (str[i] != ch) // Check if the character is not  the specified character
        {
            result_str += str[i]; // Append the character to the result string if it's different from 'ch'
        }
    }
    return result_str; // Return the modified string after removing occurrences of 'ch'
}

// This function shows all the available courses (their enrollments are less than 50)
void command_available(Location_info& all_courses)
{
    // Iterate through each location
    for (auto& location : all_courses)
    {
        // Iterate through each theme
        for (auto& theme : location.second)
        {
            //Iterate through each course
            for (auto& course : theme.second)
            {
                auto& course_info = course.second;
                if (course_info.enrollments < 50) // Check if the course is not full
                {
                    cout <<location.first << " : " << theme.first <<" : "<<course.first <<endl;
                }
            }
        }
    }
}

// This function shows all courses under input theme of all locations.
void command_courses_in_theme(Location_info& all_courses, string theme)
{
    set<string> courses; // Initialize set of courses under the given theme in all locations

    // Iterate through each location
    for (auto& location : all_courses)
    {   // Iterate through each theme
        for (auto& theme_info : location.second) // theme_info is pair <string, map <string, Courses> >>
            {   // If the theme's name matches the input theme, its courses will be inserted to the set.
                if (theme == theme_info.first){
                //  Iterate through each course of the specified theme
                for (auto& course_info : theme_info.second)
                {courses.insert(course_info.first);} // Insert course's name to the set.
        }}}
    // Print out all the found courses.
    for (auto& i: courses)
    {
        cout << i <<endl;
    }
    // In case there is no theme matches the input, the set is empty. Print out error message.
    if (courses.size() == 0){cout << "Error: unknown theme" << endl; return;}
}

// This function shows the favorite theme (most enrolled) in all location.
void command_favorite_theme(Location_info& all_courses)
{   //initialize a map with theme as key and enrollments as mapped value
    map<string, int> theme_enrol;
    // Iterate through each location
    for (auto& location: all_courses)

    {   // Iterate through each theme
        for (auto& theme : location.second)

        {   // Iterate through each course
            for (auto& course : theme.second)
            {
                auto& course_info = course.second;

                if (theme_enrol.find(theme.first) == theme_enrol.end())
                { // if theme is not in the theme_enrol map
                    theme_enrol[theme.first] = course_info.enrollments;
                }
                else{
                    // Otherwise, add up the enrollments
                    theme_enrol[theme.first] += course_info.enrollments;
                }
            }
        }
    }
    // After looping through all the courses, determine the favorite theme by comparing.
    int temp = 0; // a temporary number used to compare with the enrollments of each theme
    for (auto& theme: theme_enrol) //theme is pair <string, int>
    {
        if (theme.second >= temp)
        {
            temp = theme.second;
        }
    }
    if (temp == 0) // In case of an empty input
    {
        cout <<"No enrollments"<<endl;
    }
    // Print out favorite theme.
    // In case there are the same maximum number of enrollments in several themes it will print them all.
    else{
        cout << temp << " enrollments in themes" <<endl;
        for (auto& theme: theme_enrol)
        {
            if (theme.second == temp)
            {
                cout <<"--- " <<theme.first<< endl;
            }
        }
    }
}
int main()
{   Location_info all_courses;
    if (not read_input_file(all_courses))
    {
        return EXIT_FAILURE;
    }
    while (true)
    {
        string line = "";
        cout << "> ";
        getline(cin, line);
        vector<string> parts = split(line, ' ');

        string command = parts.at(0);

        if (command == "locations")
        {

            command_locations(all_courses);
            continue;
        }
        if (command == "themes_in_location")
        {   if (parts.size() != 2)
            {
                cout <<"Error: error in command "<<command <<endl;
                continue;
            }
            string location = parts.at(1);
            command_themes_in_location(all_courses, location);
            continue;
        }
        if (command == "courses")
        {   if (parts.size() < 3)
            {
                cout <<"Error: error in command "<<command <<endl;
                continue;
            }
            string location = parts.at(1);
            string theme = "";

            // if theme parameter consists of several words, each word is now
            // an element in vector parts, starting from the third element.
            //Thus, we need to add them.

            for (size_t i=2; i< parts.size(); ++i)
            {      // each element in vector possibly has quotation mark
                   // so we need to remove it before adding
                string theme_part =str_remove_character(parts.at(i),'"');
                if (i==parts.size()-1)
                {
                    theme +=  theme_part;       // the last word does not have space after it.
                }
                else{
                    theme +=  theme_part + ' '; //add a space between each word
                }
            }

            command_courses(all_courses,location,theme);
            continue;
        }
        if (command == "available")
        {
            command_available(all_courses);
            continue;
        }
        if (command == "courses_in_theme")
        {   if (parts.size() != 2)
            {
                cout <<"Error: error in command "<<command <<endl;
                continue;
            }
            string theme = parts.at(1);
            command_courses_in_theme(all_courses,theme);
            continue;
        }
        if (command == "favorite_theme")
        {
            command_favorite_theme(all_courses);
            continue;
        }
        if (command == "quit")
        {
            return EXIT_SUCCESS;
        }
        else{
            cout <<"Error: Unknown command: " << command <<endl;
            continue;
        }
    }
    return 0;
}
