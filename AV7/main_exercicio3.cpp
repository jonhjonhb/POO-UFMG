#include "BusinessTraveler.h"

int main()
{
    Traveler t1("Pedro");
    Pager p1("User 1");
    Traveler t2 = t1;
    Pager p2 = p1;

    std::cout << "Travelers: " << 
    std::endl << "t1:" << t1 << 
    std::endl << "t2:" << t2 << std::endl;
    std::cout << "Pagers: " << 
    std::endl << "p1:" << p1 << 
    std::endl << "p2:" << p2 << std::endl;

    BusinessTraveler t3("Gustavo");
    t3.setPagerID("User 2");
    BusinessTraveler t4(t1);
    t4.setPager(p1);
    BusinessTraveler t5(t3);

    std::cout << std::endl << "Business Travelers: "
    << std::endl << "t3:" << t3
    << std::endl << "t4:" << t4
    << std::endl << "t5:" << t5;
}