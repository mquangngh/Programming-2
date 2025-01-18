/*
 * *
 * Program author
 * Name: Quang Nguyen
 * Student number: 152276070
 * UserID: phqung
 * E-Mail: quang.h.nguyen@tuni.fi
 *
 * Notes about the program and it's implementation (if any):
 *
 * */
#include "hospital.hh"
#include "utils.hh"
#include <iostream>
#include <set>
using namespace std;
Hospital::Hospital()
{
}

Hospital::~Hospital()
{
    // Deallocating staff
    for( std::map<std::string, Person*>::iterator
         iter = staff_.begin();
         iter != staff_.end();
         ++iter )
    {
        delete iter->second;
    }

    // Remember to deallocate patients also
    for( std::map<std::string, Person*>::iterator
         iter = all_patients_.begin();
         iter != all_patients_.end();
         ++iter )
    {
        delete iter->second;
    }

    for( std::map<std::string, std::vector<CarePeriod*>>::iterator
         iter = care_periods_.begin();
         iter != care_periods_.end();
         ++iter )
    {
        for (auto& period: iter->second)
        {
            delete period;
        }

    }
}

void Hospital::set_date(Params params)
{
    std::string day = params.at(0);
    std::string month = params.at(1);
    std::string year = params.at(2);
    if( not utils::is_numeric(day, false) or
        not utils::is_numeric(month, false) or
        not utils::is_numeric(year, false) )
    {
        std::cout << NOT_NUMERIC << std::endl;
        return;
    }
    utils::today.set(stoi(day), stoi(month), stoi(year));
    std::cout << "Date has been set to ";
    utils::today.print();
    std::cout << std::endl;
}

void Hospital::advance_date(Params params)
{
    std::string amount = params.at(0);
    if( not utils::is_numeric(amount, true) )
    {
        std::cout << NOT_NUMERIC << std::endl;
        return;
    }
    utils::today.advance(stoi(amount));
    std::cout << "New date is ";
    utils::today.print();
    std::cout << std::endl;
}

void Hospital::recruit(Params params)
{
    std::string specialist_id = params.at(0);
    if( staff_.find(specialist_id) != staff_.end() )
    {
        std::cout << ALREADY_EXISTS << specialist_id << std::endl;
        return;
    }
    Person* new_specialist = new Person(specialist_id);
    staff_.insert({specialist_id, new_specialist});
    std::cout << STAFF_RECRUITED << std::endl;
}

void Hospital::print_all_staff(Params)
{
    if( staff_.empty() )
    {
        std::cout << "None" << std::endl;
        return;
    }
    for( std::map<std::string, Person*>::const_iterator iter = staff_.begin();
         iter != staff_.end();
         ++iter )
    {
        std::cout << iter->first << std::endl;
    }
}

void Hospital::add_medicine(Params params)
{
    std::string medicine = params.at(0);
    std::string strength = params.at(1);
    std::string dosage = params.at(2);
    std::string patient = params.at(3);
    if( not utils::is_numeric(strength, true) or
        not utils::is_numeric(dosage, true) )
    {
        std::cout << NOT_NUMERIC << std::endl;
        return;
    }
    std::map<std::string, Person*>::const_iterator
            patient_iter = current_patients_.find(patient);
    if( patient_iter == current_patients_.end() )
    {
        std::cout << CANT_FIND << patient << std::endl;
        return;
    }
    patient_iter->second->add_medicine(medicine, stoi(strength), stoi(dosage));
    // The medicine added for a patient is also saved in hospital's system
    // along with the id of the patients taking it
    all_medicines_[medicine].insert(patient);
    std::cout << MEDICINE_ADDED << patient << std::endl;
}

void Hospital::remove_medicine(Params params)
{
    std::string medicine = params.at(0);
    std::string patient = params.at(1);
    std::map<std::string, Person*>::const_iterator
            patient_iter = current_patients_.find(patient);
    if( patient_iter == current_patients_.end() )
    {
        std::cout << CANT_FIND << patient << std::endl;
        return;
    }
    patient_iter->second->remove_medicine(medicine);
    // When the medicine is removed from a patient,
    // the patient's id is at the same time removed from the hospital's
    // system of that medicine.
    all_medicines_.at(medicine).erase(patient);
    std::cout << MEDICINE_REMOVED << patient << std::endl;
}

void Hospital::enter(Params params)
{
    std::string patient_id=params.at(0);
    // If patient is already in the hospital
    if ( current_patients_.find(patient_id) != current_patients_.end() )
    {
        cout << ALREADY_EXISTS << patient_id <<endl;
        return;
    }
    // Check if patient has been in the hospital before
    // if not, adding Person for patient
    if ( all_patients_.find(patient_id) == all_patients_.end() )
    {
        all_patients_[patient_id]= new Person(patient_id);
    }
    // A new/ex patient has the same procedure:
    Person* new_patient = all_patients_.find(patient_id)->second;
    current_patients_[patient_id]=new_patient;

    CarePeriod* care_period = new CarePeriod(utils::today, new_patient);
    care_periods_[patient_id].push_back(care_period);

    // Adding patient's id in its real-time addition
    all_patient_ids_.push_back((patient_id));

    cout << PATIENT_ENTERED <<endl;
}

void Hospital::leave(Params params)
{   string patient_id = params.at(0);


    // If patient is not in the hospital at the moment
    if ( current_patients_.find(patient_id) == current_patients_.end())
    {
        cout << CANT_FIND << patient_id <<endl;
        return;
    }
    // If patient is in the hospital at the moment
    else {
        current_patients_.erase(patient_id);


        // The latest ongoing period is closed when the patient leaves
        vector<CarePeriod*>& periods = care_periods_[patient_id];
        periods.back()->close_period(utils::today);

        cout << PATIENT_LEFT << endl;
    }

}

void Hospital::assign_staff(Params params)
{
    string staff_id = params.at(0);
    string patient_id = params.at(1);

    // If staff is not in the hospital
    if ( staff_.find(staff_id) == staff_.end())
    {
        cout << CANT_FIND << staff_id << endl;
        return;
    }

    // If patient is not currently in the hospital
    if ( current_patients_.find(patient_id) == current_patients_.end())
    {
        cout << CANT_FIND << patient_id << endl;
        return;
    }

    // Retrieve all the periods of the patient
    vector<CarePeriod*>& periods = care_periods_[patient_id];

    // Access to the last element in vector
    // which is the current ongoing care period
    periods.back()->add_staff(staff_id);
    cout << STAFF_ASSIGNED << patient_id << endl;
}

void Hospital::print_patient_info(Params params)
{
    string patient_id = params.at(0);

    // If patient has never been in the hospital
    if ( all_patients_.find(patient_id) == all_patients_.end())
    {
        cout << CANT_FIND << patient_id << endl;
        return;
    }

    // Retrieve all the periods of the patient
    std::vector<CarePeriod*>& periods = care_periods_[patient_id];

    //Accessing to each period
    for (auto& period : periods)
    {
        cout << "* Care period: " ;
        period->get_start_date().print();
        cout <<" - ";
        if (period->is_ended())
        {
           period->get_end_date().print();
        }

        cout << endl << "  - Staff: ";

        // Access to all staff worked in a specific period
        set<string> staff_in_period = period->get_staff_id();
        if ( staff_in_period.empty())
        {
            cout << "None";
        }
        else
        {
            for ( auto& staff : staff_in_period )
            {
                cout << staff << ' ';
            }
        }
        cout <<endl;
    }

    cout << "* Medicines:";
    all_patients_[patient_id]-> print_medicines("  - ");
}

void Hospital::print_care_periods(Params params)
{
    string staff_id = params.at(0);
    if ( staff_.find(staff_id) == staff_.end())
    {
        cout << CANT_FIND << staff_id <<endl;
        return;
    }

    // Container of all the periods that the staff has worked.
    vector<CarePeriod*> periods_of_staff;

    // Access to each patient among all patients that have visited hospital
    for ( auto& patient_id :all_patient_ids_)
    {
        // Container of all periods of this patient
        vector<CarePeriod*> periods = care_periods_.at(patient_id);

        //Iterate through each period
        for ( auto&  period : periods)

            // Container of all the staffs working in a specific period
        {   set<string> staff_ids = period->get_staff_id();

            // If the given staff appears in that period
            if (staff_ids.find(staff_id) != staff_ids.end())
            {
                periods_of_staff.push_back(period);
            }
        }
    }
    if (periods_of_staff.empty())
    {
        cout <<"None" << endl;
        return;
    }
    for (auto& period : periods_of_staff)
    {
        period->get_start_date().print();
        cout << " - ";
        if ( period->is_ended())
        {
            period ->get_end_date().print();
        }
        cout <<endl << "* Patient: " << period->get_patient_id() <<endl;
    }
}

void Hospital::print_all_medicines(Params)
{
    if ( all_medicines_.empty() )
    {
        cout << "None" <<endl;
        return;
    }
    // Iterate through each medicine used in the hospital and
    // the patients who is still taking it
    for (auto& [medicine,patient_set] : all_medicines_)
    {
        if (!patient_set.empty())
        {
            cout << medicine << " prescribed for" <<endl;
            for (auto& patient : patient_set)
            {
                cout << "* " << patient <<endl;
            }
        }
    }
}

void Hospital::print_all_patients(Params)
{
    if (all_patients_.empty())
    {
        cout <<"None" <<endl;
        return;
    }
    for (auto& [patient_id, period_info] : care_periods_)
    {
        cout << patient_id <<endl;
        for (auto& period : period_info)
        {
            cout << "* Care period: ";
            period->get_start_date().print();
            cout << " - ";
            if (period->is_ended())
            {
                period->get_end_date().print();
            }
            cout <<endl <<"  - Staff: ";

            set<string> staff_info = period->get_staff_id();

            if ( staff_info.empty())
            {
                cout << "None";
            }
            else
            {
                for (auto& staff : staff_info)
                {
                    cout << staff <<' ';
                }
            }
            cout <<endl;
        }
        cout <<"* Medicines:";
        all_patients_[patient_id]->print_medicines("  - ");
    }
}

void Hospital::print_current_patients(Params)
{
    if (current_patients_.empty())
    {
        cout <<"None" <<endl;
        return;
    }
    for (auto& [patient_id, period_info] : care_periods_)
    {
        // if this patient is still currently in hospital
        if (current_patients_.find(patient_id) != current_patients_.end())
        {
            cout << patient_id <<endl;
            for (auto& period : period_info)
            {
                cout << "* Care period: ";
                period->get_start_date().print();
                cout << " - ";
                if (period->is_ended())
                {
                    period->get_end_date().print();
                }
                cout <<endl <<"  - Staff: ";

                set<string> staff_info = period->get_staff_id();

                if ( staff_info.empty())
                {
                    cout << "None";
                }
                else
                {
                    for (auto& staff : staff_info)
                    {
                        cout << staff <<' ';
                    }
                }
                cout <<endl;
            }
            cout <<"* Medicines:";
            current_patients_[patient_id]->print_medicines("  - ");
        }
    }
}

