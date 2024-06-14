

/*------------------------------------------------------------------------
Matrikelnummer - 3093084
Nachname - Ivanov
Vorname - Martin
Uni e-mail - martin.ivanov@stud.uni-due.de
Studiengang - ISE Computer Engineering
-----------------------------------------------------------------------*/

#include <iostream>
#include<string>
#include<iomanip>
/*
std::
std::string a;
a=a+to_string(2);
*/
using namespace std;

class DayOfYear
{
    friend class Rental;
private:
    short unsigned int dayOfYear, year;
    static const int days[];
public:

    DayOfYear() : dayOfYear(1),year(2021)
    {}


    DayOfYear(int c, int d, int e)
    {
        year=c;
        if(d==1)
            dayOfYear=e;
        else
            dayOfYear=days[d-1]+e;
    }

    int get_dayOfYear()
    {
        return dayOfYear;
    }

    friend DayOfYear operator++(DayOfYear &a)
    {
        if(a.dayOfYear==365)
        {
            a.year++;
            a.dayOfYear=1;
            return a;
        }
        else
        {
            a.dayOfYear++;
            return a;
        }
    }

    friend istream& operator>>(istream& in, DayOfYear &a)
    {
        unsigned int month,day;
        char s;
        in>>a.year>>s>>month>>s>>day;
        if(month==1)
        {
            a.dayOfYear=day;
        }
        else if(month==3)
        {
            a.dayOfYear=day+a.days[1];
        }
        else
        {
        a.dayOfYear=a.days[month-2]+day;
        }
        return in;

    }

    friend ostream& operator<<(ostream& out, DayOfYear &a)
    {
        short unsigned month=1,day=1;
            if(a.get_dayOfYear()<=a.days[0])
            {
                    month=1;
                    day=a.get_dayOfYear();
                    out<<a.year<<'-'<<month<<'-'<<day;
                }
                else if(a.get_dayOfYear()>a.days[0]&&a.get_dayOfYear()<=a.days[1])
                {
                    month=2;
                    day=a.get_dayOfYear()-a.days[0];
                    out<<a.year<<'-'<<month<<'-'<<day;
                }
                else if(a.get_dayOfYear()>a.days[1]&&a.get_dayOfYear()<=a.days[2])
                {
                    month=3;
                    day=a.get_dayOfYear()-a.days[1];
                    out<<a.year<<'-'<<month<<'-'<<day;
                }
                else if(a.get_dayOfYear()>a.days[2]&&a.get_dayOfYear()<=a.days[3])
                {
                    month=4;
                    day=a.get_dayOfYear()-a.days[2];
                    out<<a.year<<'-'<<month<<'-'<<day;
                }
                else if(a.get_dayOfYear()>a.days[3]&&a.get_dayOfYear()<=a.days[4])
                {
                    month=5;
                    day=a.get_dayOfYear()-a.days[3];
                    out<<a.year<<'-'<<month<<'-'<<day;
                }
                else if(a.get_dayOfYear()>a.days[4]&&a.get_dayOfYear()<=a.days[5])
                {
                    month=6;
                    day=a.get_dayOfYear()-a.days[4];
                    out<<a.year<<'-'<<month<<'-'<<day;
                }
                 else if(a.get_dayOfYear()>a.days[5]&&a.get_dayOfYear()<=a.days[6])
                {
                    month=7;
                    day=a.get_dayOfYear()-a.days[5];
                    out<<a.year<<'-'<<month<<'-'<<day;
                }
                 else if(a.get_dayOfYear()>a.days[6]&&a.get_dayOfYear()<=a.days[7])
                {
                    month=8;
                    day=a.get_dayOfYear()-a.days[6];
                    out<<a.year<<'-'<<month<<'-'<<day;
                }
                 else if(a.get_dayOfYear()>a.days[7]&&a.get_dayOfYear()<=a.days[8])
                {
                    month=9;
                    day=a.get_dayOfYear()-a.days[7];
                    out<<a.year<<'-'<<month<<'-'<<day;
                }
                 else if(a.get_dayOfYear()>a.days[8]&&a.get_dayOfYear()<=a.days[9])
                {
                    month=10;
                    day=a.get_dayOfYear()-a.days[8];
                    out<<a.year<<'-'<<month<<'-'<<day;
                }
                 else if(a.get_dayOfYear()>a.days[9]&&a.get_dayOfYear()<=a.days[10])
                {
                    month=11;
                    day=a.get_dayOfYear()-a.days[9];
                    out<<a.year<<'-'<<month<<'-'<<day;
                }
                 else if(a.get_dayOfYear()>a.days[10]&&a.get_dayOfYear()<=a.days[11])
                {
                    month=12;
                    day=a.get_dayOfYear()-a.days[10];
                    out<<a.year<<'-'<<month<<'-'<<day;
                }
        return out;

    }



};


class Vehicle
{
private:
    const int no;
    string model;
    float price24h;
public:
    Vehicle(int a, string b, float c) : no(a),model(b),price24h(c)
    {}

    Vehicle(int d, string e) : no(d),model(e)
    {}

    virtual ~Vehicle() {};

    int get_no()
    {
        return no;
    }

    string get_model()
    {
        return model;
    }

    float get_price(int a)
    {
        float price;
        price=a*price24h;
        return price;
    }

    virtual void print()=0;
};


class Bike: public Vehicle
{
public:
    Bike(int a, string b) : Vehicle(a,b,9.99)
    {}

    ~Bike()
    {}

    virtual void print()
    {
        cout<<Vehicle::get_no()<<':'<<Vehicle::get_model()<<" (Bike)"<<endl;
    }


};


class EMotorVehicle: public Vehicle
{
public:
    EMotorVehicle(int a, string b, float c) : Vehicle(a,b,c)
    {}

    EMotorVehicle(int c,string d): Vehicle(c,d)
    {}

    virtual bool is_streetLegal()=0;

    virtual void print()
    {
        if(is_streetLegal()==true)
        {
            cout<<get_no()<<':'<<get_model(); }
        else if(is_streetLegal()==false) {
            cout<<"(not street legal)"<<endl;
        }
    }
};


class EBike: public EMotorVehicle
{
   public:
   EBike(int a, string b) :EMotorVehicle(a,b,29.99)
   {}

   bool is_streetLegal()
   {
       return true;
   }

    virtual void print()
   {

        cout<<get_no()<<':'<<get_model()<<" (EBike)"<<endl;

   }
};


class EScooter: public EMotorVehicle
{
private:
    bool streetLegal;
public:
   EScooter(int a, string b,float c=19.99) : EMotorVehicle(a,b,c),streetLegal(false)
    {}
    virtual bool is_streetLegal()
    {
        return streetLegal;
    }

    virtual void print()
    {
        cout<<get_no()<<':'<<get_model()<<" (EScooter)"<<endl;
    }

};

class Rental
{
    friend class DayOfYear;
    friend class Schedule;
private:
    int no=1;
    string customer;
    DayOfYear from;
    int days;

    static int last_no;
public:
    Rental(string a, DayOfYear& b,int c=1) : no(last_no),customer(a),from(b),days(c)
    {
        last_no++;
    }

    int get_no()
    {
        return no;
    }

    int get_days()
    {
        return days;
    }

    DayOfYear get_from()
    {

        return from;
    }

    DayOfYear get_until()
    {
       DayOfYear until;
       until=from;
       for(int x=0;x<days;x++)
       {
           ++until;
       }
        return until;
    }


    void print()
    {
        DayOfYear a,b;
        a=get_from();
        b=get_until();
        cout<<a<<" to "<<b<<" , rental no. "<< no<<" for "<<customer;
    }

};

class Schedule
{
    friend class Vehicle;
    friend class Agency;
    friend class Rental;
private:
    Vehicle* vehicle;
    Rental* year[365];
    Schedule* next;
public:
    Schedule(Vehicle *a)
    {
    vehicle=a;
    next=NULL;
    for(int b=0;b<365;b++)
    {
        year[b]=NULL;
    }
    }

    Vehicle* get_vehicle()
    {
        return vehicle;
    }

    Schedule* get_next()
    {
        return next;
    }

    Schedule* set_next(Schedule* a)
    {
        next=a;
        return next;
    }

    bool is_free(DayOfYear& a, int b)
    {
    bool z=true;
    for(int x=a.get_dayOfYear()-1;x<a.get_dayOfYear()+b;x++)
    {

        if(year[x]!=NULL)
        {
            z=false;
            break;
        }
        else
            z=true;
    }
    return z;
    }

    float book(string name, DayOfYear& start, int days)
    {
        int y=start.get_dayOfYear()-1;
        float z=vehicle->get_price(days);
        Rental *newrental= new Rental(name,start,days);
        for(int x=y;x<days+start.get_dayOfYear();x++)
        {

            year[x]=newrental;
        }
        cout<<"booked, price for this rental: "<<z<<endl;
        return z;



    }

    void print(DayOfYear& a)
    {
        cout<<"SCHEDULE FOR ";
        vehicle->print();
        cout<<endl;
        int x=a.get_dayOfYear()-1;
        if(year[x]!=NULL)
            year[x]->print();



    }


    void print()
    {
        cout<<"SCHEDULE FOR ";
        vehicle->print();
        cout<<endl;
        for(int x=0;x<365;x++)
        {
            if(year[x]!=NULL)
            {
            year[x]->print();
            int b=year[x]->get_days();
            cout<<" , total : "<<vehicle->get_price(b)<<endl;
            }
        }


    }



};


class Agency
{
    friend class Vehicle;
    friend class Rental;
private:
    float profitPercentage,profit;
    Schedule *head,*last;
protected:
    Schedule* searchFor(int a)
    {
         Schedule *b=NULL;
         b=head;
        if(b==nullptr)
            cout<<"Vehicle not found."<<endl;
    Vehicle *c=NULL;
    int d;
    while(b!=NULL)
    {
       c=b->get_vehicle();
       d=c->get_no();
       if(d==a)
           break;
       b=b->get_next();
    }
    return b;
    }
public:
    Agency(): profitPercentage(0.2),profit(0.00),head(NULL),last(NULL)
    {}

    float get_profit()
    {
        return profit;
    }

    void set_profitPercentage(float a)
    {
        profitPercentage=a;
        cout<<"Profit percentage has been set!"<<endl;
    }

    void add(Vehicle* a)
    {
        if(a!=NULL)
        {
            if(head==NULL)
            {
                last=new Schedule(a);
                head=last;
            }
            else
                last=last->set_next(new Schedule(a));
        }

    }


    bool isFree(int vehnum, DayOfYear& start, int numdays) //
    {
        bool z=false;
        Schedule *a=head;
        z=a->is_free(start,numdays);
        return z;
     }


    float book(int vehno, string customer, DayOfYear &startday, int numdays)
    {
        if(numdays>365)
        {
            cout<<"Rental period for more than 1 year is not offered."<<endl;
            return 0;
        }
        else
        {
        Schedule *a=NULL;
        float sumpr;
        a=searchFor(vehno);
        if(a->is_free(startday,numdays)==false)
        {
            cout<<"Sorry this vehicle is already booked for the chosen duration."<<endl;
        }
        else
        {
            sumpr=a->book(customer,startday,numdays);
            profit+= sumpr*profitPercentage;
        }
        return profit;
        }
    }

    int chooseVehicle()
    {
        if(head==NULL){
            cout<<"No vehicles available."<<endl;
            return 0;
        }
        int choice;
        Schedule *a=head;
        while(a!=NULL)
        {
            a->vehicle->print();
            a=a->get_next();

        }
        cout<<"Choose vehicle number: ";
        cin>>choice;
        return choice;


    }

    void print(DayOfYear &a)
    {
        Schedule *b=head;
        while(b!=NULL)
        {
        b->print(a);
        b=b->get_next();

        }

    }

    void print()
    {
    Schedule *a = head;
    while(a!=NULL)
    {
        a->print();
        a=a->get_next();
    }
    cout << "profit: " << fixed << setprecision(2)
    << profit << " EUR" << endl;
    }


};






const int DayOfYear::days[12]={31,59,90,120,151,181,212,242,273,303,334,365};
int Rental::last_no=0;

int main()
{
   Agency MVR;
   DayOfYear today(2021,01,01),tomorrow;
   tomorrow=today;
   ++tomorrow;
   char selection;
   float percentage;
   DayOfYear start;
   int days,vehid=1,bikes=0,ebikes=0,escooters=0,choice,a,x;
   string custname;
   do
   {
       cout<<"------------------------------------------------------------"<<endl;
       cout<<"------------------SIMPLIFIED SIMULATION---------------------"<<endl;
       cout<<"--------------------OF A RENTAL AGENCY----------------------"<<endl;
       cout<<"------------------------------------------------------------"<<endl;
       cout<<"____________________________________________________________"<<endl;
       cout<<"                         MENU                               "<<endl;
       cout<<"A - end of simulation"<<endl;
       cout<<"B - set new simulation date"<<endl;
       cout<<"C - new rental manually"<<endl;
       cout<<"D - print rental of today"<<'-'<<today<<endl;
       cout<<"E - print rental of tomorrow"<<'-'<<tomorrow<<endl;
       cout<<"F - print all rentals"<<endl;
       cout<<"G - print agency profit"<<endl;
       cout<<"H - set agency profit percent"<<endl;
       cout<<"I - add Bikes"<<endl;
       cout<<"J - add E-Bikes"<<endl;
       cout<<"K - add E-Scooters"<<endl;
       cout<<"L - new rental simulation"<<endl;
       cout<<"Your Choice : ";
       cin>>selection;
       if(selection=='a')
            selection='A';
       else if(selection=='b')
        selection='B';
        else if(selection=='c')
        selection='C';
        else if(selection=='d')
        selection='D';
        else if(selection=='e')
        selection='E';
        else if(selection=='f')
        selection='F';
        else if(selection=='g')
        selection='G';
        else if(selection=='h')
        selection='H';
        else if(selection=='i')
        selection='I';
        else if(selection=='j')
        selection='J';
        else if(selection=='k')
        selection='K';
        else if(selection=='l')
        selection='L';
       switch (selection)
       {
       case 'A':
            cout<<"Simulation ended!"<<endl;
            return 0;
       case 'B':
            cout<<"Input date of today in format dd-mm-yyyy: ";
            cin>>today;
            tomorrow=today;
            ++tomorrow;
            cout<<"Inputed";

            break;
       case 'C':
            cout<<"------------------------------------------------------------"<<endl;
            cout<<"--------------------------VEHICLES--------------------------"<<endl;
            a=MVR.chooseVehicle();
            cout<<"Start date of rental: ";
            cin>>start;
            cout<<"Number of days: ";
            cin>>days;
            cout<<"Customers name for the reservation: ";
            cin>>custname;
            MVR.book(a,custname,start,days);

            break;
       case 'D':
            MVR.print(today);

            break;
       case 'E':
            MVR.print(tomorrow);

            break;
       case 'F':
            MVR.print();

            break;
       case 'G':
            cout<<"Agency's Profit: "<<setprecision(2)<<MVR.get_profit()<<" EUR"<<endl;

            break;
       case 'H':
           cout<<"Agency profit percent: ";
           cin>>percentage;
           MVR.set_profitPercentage(percentage);
           break;
       case 'I':
           cout<<"How many Bikes: ";
           cin>>choice;
           for(x=0;x<choice;x++)
           {
              MVR.add(new Bike(vehid++,"Motorbike"+to_string(++bikes)));
           }
            cout<<"Added"+to_string(choice)+" Bikes";
           break;
       case 'J':
            cout<<"How many E-Bikes: ";
            cin>>choice;
            for(x=0;x<choice;x++)
            {
                MVR.add(new Bike(vehid++,"E-Bike"+to_string(++ebikes)));
            }
            cout<<"Added"+to_string(choice)+" E-Bikes";
           break;
       case 'K':
            cout<<"How many E-Scooters: ";
            cin>>choice;
            for(int x=0;x<choice;x++)
            {
                MVR.add(new EScooter(vehid++,"E-Scooter"+to_string(++escooters)));

            }
            cout<<"Added"+to_string(choice)+" E-Scooters";
            break;
       case 'L':
            Rental newrental("Martin",today,3);
            newrental.print();

            break;

       }


   }
   while(selection!='A'&&'a');
    return 0;
}
