#ifndef VEHICLE_H
#define VEHICLE_H
#include<string>



class Vehicle
{
private:
        int no;
    string model;
    float price24h;
public:
        Vehicle(int a, string b, float c);
        virtual ~Vehicle();
        int get_no();
        string get_model();
        float get_price(int a);
        virtual void print()=0;

    protected:

};

#endif // VEHICLE_H
