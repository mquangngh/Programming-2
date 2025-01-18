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
 * Implemetation for class for describing a patient's care period in hospital.
 *
 * Note: Students need to implement almost all of this class by themselves.
 *
 * */
#include "careperiod.hh"
#include <iostream>

CarePeriod::CarePeriod(const std::string& start, Person* patient):
    patient_(patient), start_(start)
{
}

CarePeriod::CarePeriod(const Date &start, Person* patient):
    patient_(patient), start_(start)
{
}

CarePeriod::~CarePeriod()
{
}

void CarePeriod::close_period(const Date &end_date)
{
    end_ = end_date;
    has_left = true;
}

bool CarePeriod::is_ended()
{
    return has_left;
}

set<string> CarePeriod::get_staff_id()
{
    return staffs_;

}

void CarePeriod::add_staff(string staff)
{
    staffs_.insert(staff);
}

Date CarePeriod::get_start_date()
{
    return start_;
}

Date CarePeriod::get_end_date()
{
    return end_;
}

string CarePeriod::get_patient_id()
{
    return patient_->get_id();
}
