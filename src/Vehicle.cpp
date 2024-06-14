#include <iostream>
#include<string>
#include"Vehicle.h"


Vehicle::Vehicle(int a,string b,float c)
{
    no=a;
    model=b;
    price24h=c;
    //ctor
}

Vehicle::~Vehicle()
{
    //dtor
}

int Vehicle::get_no()
{
    return no;
}

string Vehicle::get_model()
{
    return model;
}

float Vehicle::get_price(int a)
{
    float total;
    total=a*price24h;
    return total;
}

