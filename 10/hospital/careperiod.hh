/* Class CarePeriod
 * ----------
 * COMP.CS.110 SPRING 2024
 * * Program author
 * Name: Quang Nguyen
 * Student number: 152276070
 * UserID: phqung
 * E-Mail: quang.h.nguyen@tuni.fi
 *
 * ----------
 * Class for describing a patient's care period in hospital.
 *
 * Note: Students need to implement almost all of this class by themselves. 
 *
 * This is the header file for the class CarePeriod used in this program.
 * It contains the methods and attributes neccessary for managing patients'
 * and staffs information during a period.
 * */
#ifndef CAREPERIOD_HH
#define CAREPERIOD_HH

#include "person.hh"
#include "date.hh"
#include <string>
#include <map>
#include <set>
using namespace std;
class CarePeriod
{
public:
    /**
      * @brief CarePeriod
      * @param start date given as a string (ddmmyyyy)
      * @param patient whose care period will be created
      */
    CarePeriod(const std::string& start, Person* patient);

    /**
      * @brief CarePeriod
      * @param start date given as a Date object
      * @param patient whose care period will be created
      */
    CarePeriod(const Date& start, Person* patient);

    /**
      * @brief destructor
      */
    ~CarePeriod();

    // More public methods
    /**
     * @brief close_period
     * @param end_date: date when a period is closed
     * Assign the end date to the period, patient now has left the hospital
     */
    void close_period(const Date& end_date);


    /**
     * @brief is_ended
     * @return true if the care period is closed, false otherwise
     */
    bool is_ended();

    /**
     * @brief get_staff_id
     * @return the information of a staff
     */
    set<string> get_staff_id();

    /**
     * @brief get_patient_id
     * @return patient's id
     */
    string get_patient_id();

    /**
     * @brief add_staff
     * @param staff
     * Assign staff to patient during the period
     */
    void add_staff(std::string staff);

    /**
     * @brief get_start_date
     * @return the date when the period starts
     */
    Date get_start_date();

    /**
     * @brief get_end_date
     * @return the date when the period ends
     */
    Date get_end_date();




private:
    Person* patient_;
    Date start_;
    Date end_;

    // More attributes and methods

    // boolean value if patient has left hospital or not
    // by default, the patient has not left hospital.
    bool has_left = false;

    // Container of staffs assigned to patient in a certain period
    set<string> staffs_;
};

#endif // CAREPERIOD_HH
