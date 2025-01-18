#ifndef MAMMAL_H
#define MAMMAL_H
#include "animal.hh"

class mammal: public Animal
{
public:
    mammal();
    void suckle(std::ostream& output) const;
};

#endif // MAMMAL_H
