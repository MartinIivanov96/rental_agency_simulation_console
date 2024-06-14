#ifndef BIKE_H
#define BIKE_H

#include <Vehicle.h>


class Bike : public Vehicle
{
    public:
        Bike(int a, string b);
        virtual ~Bike();
        virtual void print();
    protected:

    private:
};

#endif // BIKE_H
