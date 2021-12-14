
#include "ArrayQueue.h" // ADT Queue operations
//#include "LinkedQueue.h" // ADT Queue operations

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Customer
{
    int ArrivalTime;
    int DepartTime;
    Customer(int at = 0)
    {
        ArrivalTime = at;
        DepartTime = 4 + rand() % 6;
    }
    bool finishedBanking()
    {
        return --DepartTime < 0;
    }
    bool operator< (const Customer& c) const
    {
        return ArrivalTime < c.ArrivalTime;
    }
};

struct teller
{
    int customer;
    int timeC;

    bool customerComplete()
    {
        return --timeC < 0;
    }
    bool free;
    bool TellerisFree()
    {
        if (free)
        {
            return true;
        }
        if (customerComplete())
        {
            free = true;
        }
        return free;
    }
    void CallingCustomer()
    {
        free = false;
    }
};

int main()
{
    const int NumberofTellers = 4;
    const int Minutes = 100;
    float waitTotal = 0;
    int servedCustomer = 0;
    double a, d; //arrival and departure
 //objects
    ArrayQueue<Customer> line;
    Customer c;
    teller server[NumberofTellers] = {};
  
//counting
    int time = 0;
    int count = 0;
    while (time < Minutes)
    {
        a = float(rand()) / float(RAND_MAX);
        if (a <= .2 && a >= 0) //every 5 minutes
        {
            count++;
            cout << "Customer " << count << " has arrived : " << time << " minutes since opening." << endl;
            c.ArrivalTime = time;
            line.enqueue(count);
            
        }
        for (int i = 0; i < NumberofTellers; i++)
        {
            d = float(rand()) / float(RAND_MAX);
            if (d <= .16) // every 6 minutes
            {
                if (server[i].TellerisFree() && !line.isEmpty())
                {
                    printf("Serving Customer: %d",line.peekFront());
                    cout << endl;
                    servedCustomer++;
                    //c.DepartTime = time + rand()% 6;
                    int dep = 2 + rand() % 6;
                    c.DepartTime = time + dep;
                    printf("Customer: %d", line.peekFront());
                    cout << " left bank at " << dep << " minutes after being served" << endl;

                    waitTotal += c.DepartTime - c.ArrivalTime;
                    server[time].CallingCustomer();
                    line.dequeue();
                    c.finishedBanking();
                }
            }
        }
        time++;
    }
    cout << "\n\t Bank has now closed!\n";

    cout << "\n #of the customers served: " << servedCustomer << endl;
 
    cout << "\nAverage Wait Time: " << (waitTotal / servedCustomer) << endl;



    return 0;
}  // end main

// 1 teller
//Customer 1 has arrived : 4 minutes since opening.
//Serving Customer : 1
//Customer : 1 left bank at 4 minutes after being served
//Customer 2 has arrived : 5 minutes since opening.
//Serving Customer : 2
//Customer : 2 left bank at 5 minutes after being served
//Customer 3 has arrived : 21 minutes since opening.
//Customer 4 has arrived : 22 minutes since opening.
//Serving Customer : 3
//Customer : 3 left bank at 2 minutes after being served
//Serving Customer : 4
//Customer : 4 left bank at 7 minutes after being served
//Customer 5 has arrived : 28 minutes since opening.
//Customer 6 has arrived : 29 minutes since opening.
//Serving Customer : 5
//Customer : 5 left bank at 6 minutes after being served
//Serving Customer : 6
//Customer : 6 left bank at 5 minutes after being served
//Customer 7 has arrived : 36 minutes since opening.
//Customer 8 has arrived : 43 minutes since opening.
//Serving Customer : 7
//Customer : 7 left bank at 7 minutes after being served
//Serving Customer : 8
//Customer : 8 left bank at 6 minutes after being served
//Customer 9 has arrived : 47 minutes since opening.
//Serving Customer : 9
//Customer : 9 left bank at 4 minutes after being served
//Customer 10 has arrived : 56 minutes since opening.
//Serving Customer : 10
//Customer : 10 left bank at 2 minutes after being served
//Customer 11 has arrived : 58 minutes since opening.
//Serving Customer : 11
//Customer : 11 left bank at 4 minutes after being served
//Customer 12 has arrived : 61 minutes since opening.
//Customer 13 has arrived : 68 minutes since opening.
//Serving Customer : 12
//Customer : 12 left bank at 3 minutes after being served
//Customer 14 has arrived : 71 minutes since opening.
//Customer 15 has arrived : 72 minutes since opening.
//Customer 16 has arrived : 81 minutes since opening.
//Customer 17 has arrived : 83 minutes since opening.
//Serving Customer : 13
//Customer : 13 left bank at 4 minutes after being served
//Customer 18 has arrived : 88 minutes since opening.
//Serving Customer : 14
//Customer : 14 left bank at 7 minutes after being served
//Customer 19 has arrived : 93 minutes since opening.
//Customer 20 has arrived : 95 minutes since opening.
//Serving Customer : 15
//Customer : 15 left bank at 4 minutes after being served
//
//Bank has now closed!
//
//#of the customers served : 15
//
//Average Wait Time : 6.73333

// 4 tellers
//Customer 1 has arrived : 2 minutes since opening.
//Serving Customer : 1
//Customer : 1 left bank at 2 minutes after being served
//Customer 2 has arrived : 13 minutes since opening.
//Serving Customer : 2
//Customer : 2 left bank at 6 minutes after being served
//Customer 3 has arrived : 16 minutes since opening.
//Customer 4 has arrived : 20 minutes since opening.
//Serving Customer : 3
//Customer : 3 left bank at 6 minutes after being served
//Serving Customer : 4
//Customer : 4 left bank at 4 minutes after being served
//Customer 5 has arrived : 23 minutes since opening.
//Serving Customer : 5
//Customer : 5 left bank at 7 minutes after being served
//Customer 6 has arrived : 31 minutes since opening.
//Serving Customer : 6
//Customer : 6 left bank at 5 minutes after being served
//Customer 7 has arrived : 40 minutes since opening.
//Customer 8 has arrived : 41 minutes since opening.
//Serving Customer : 7
//Customer : 7 left bank at 4 minutes after being served
//Customer 9 has arrived : 42 minutes since opening.
//Serving Customer : 8
//Customer : 8 left bank at 3 minutes after being served
//Serving Customer : 9
//Customer : 9 left bank at 2 minutes after being served
//Customer 10 has arrived : 51 minutes since opening.
//Serving Customer : 10
//Customer : 10 left bank at 6 minutes after being served
//Customer 11 has arrived : 55 minutes since opening.
//Serving Customer : 11
//Customer : 11 left bank at 2 minutes after being served
//Customer 12 has arrived : 61 minutes since opening.
//Serving Customer : 12
//Customer : 12 left bank at 7 minutes after being served
//Customer 13 has arrived : 67 minutes since opening.
//Serving Customer : 13
//Customer : 13 left bank at 3 minutes after being served
//Customer 14 has arrived : 70 minutes since opening.
//Customer 15 has arrived : 72 minutes since opening.
//Serving Customer : 14
//Customer : 14 left bank at 3 minutes after being served
//Serving Customer : 15
//Customer : 15 left bank at 4 minutes after being served
//Customer 16 has arrived : 74 minutes since opening.
//Serving Customer : 16
//Customer : 16 left bank at 5 minutes after being served
//Customer 17 has arrived : 80 minutes since opening.
//Serving Customer : 17
//Customer : 17 left bank at 3 minutes after being served
//Customer 18 has arrived : 83 minutes since opening.
//Serving Customer : 18
//Customer : 18 left bank at 6 minutes after being served
//Customer 19 has arrived : 88 minutes since opening.
//Serving Customer : 19
//Customer : 19 left bank at 6 minutes after being served
//Customer 20 has arrived : 89 minutes since opening.
//Customer 21 has arrived : 91 minutes since opening.
//Customer 22 has arrived : 93 minutes since opening.
//Serving Customer : 20
//Customer : 20 left bank at 3 minutes after being served
//Serving Customer : 21
//Customer : 21 left bank at 6 minutes after being served
//Customer 23 has arrived : 99 minutes since opening.
//Serving Customer : 22
//Customer : 22 left bank at 7 minutes after being served
//
//Bank has now closed!
//
//#of the customers served : 22
//
//Average Wait Time : 5.31818