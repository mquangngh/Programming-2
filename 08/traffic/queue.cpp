#include "queue.hh"
#include <iostream>
// Implement the member functions of Queue here
using namespace std;
Queue::Queue(unsigned int cycle): cycle_(cycle)
{

}

Queue::~Queue()
{
    while (first_ != nullptr)
    {
        Vehicle* temp = first_;

        first_ = first_ -> next;
        delete temp;
    }

}
// If the color of traffic light is red, inserts a vehicle, the register
// number of which is reg, to the queue.
void Queue::enqueue(const string &reg)
{ // It is possible to add vehicle regardless of traffic light color.
    // in case of green light, any added vehicle is dequeued
    if (is_green_)
    {
        cout << "GREEN: The vehicle " << reg << " need not stop to wait" << endl;
    }
    else // in case of red light, new vehicle is added to the last place
    {
        Vehicle* new_vehicle = new Vehicle;
        new_vehicle ->reg_num = reg;
        new_vehicle ->next = nullptr;
        if (first_ == nullptr)
        {
            first_ = new_vehicle; // in case there is no vehicle, the first vehicle is also the last one
        }
        else // in case there are vehicles, the previous last vehicle will be the second last
            // and it points to the new_vehicle , which is added at last position.
        {
            last_ ->next= new_vehicle;
        }

        last_ = new_vehicle;
    }

}

void Queue::switch_light()
{
    if (is_green_ == false) // switching red -> green
    {
        cout << "GREEN: ";
        if (first_ == nullptr) // if at the moment you switch light, there is no vehicle
        {
            cout << "No vehicles waiting in traffic lights" << endl;
            is_green_ = true; // if there is no vehicle, light is changed
        }
        else
        {   cout <<"Vehicle(s) ";
            for (unsigned int i =0; i < cycle_ and first_ != nullptr; ++i)
            { // iterate through each vehicle in the queue, from first to the vehicle at "cycle-th" position
                cout << first_ ->reg_num << " ";
                dequeue();
            }
            cout << "can go on" << endl;
        }

         // after all "cycle_" vehicles go on, the light is automatically changed to red, so no need to change anything
    }
    else // before switching it is green , now switched to red
    { // in this case print the situation of the queue
        is_green_ = false;
        print();



    }
}

void Queue::reset_cycle(unsigned int cycle)
{
    cycle_ = cycle;
}
void Queue::dequeue()
{
    if (first_ != nullptr) // if there is vehicle
    {
        Vehicle* temp = first_;
        first_ = first_ ->next;
        delete temp;
    }
}
// Prints the color of traffic light and the register numbers of those
// cars that are waiting in the traffic light queue (if any).
void Queue::print() const
{
    if (is_green_)
    {
        cout << "GREEN: ";

    }
    else
    {
        cout << "RED: ";
    }
    if (first_ == nullptr)
    {
        cout << "No vehicles waiting in traffic lights" << endl;
    }
    else
    {
        cout << "Vehicle(s) ";
        Vehicle* current = first_;
        while (current != nullptr)
        {
            cout << current ->reg_num << " ";
            current = current ->next;
        }
        cout << "waiting in traffic lights" << endl;
    }
}





