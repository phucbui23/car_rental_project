#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <cstring>
#include <map>
#include <stdlib.h>
//#include <windows.h>
//#include "company.h"
#include "company2.h"

int main(){
    system("clear");
    CarRentalManagement carRent;
    //cout << carRent.totalVehicle() << endl; 
    carRent.addConv();
    carRent.addSedan();
    carRent.addSUV();

    cout << "Total number of car in the company: " << carRent.totalVehicle() << "\n";
    carRent.printFleet();

    return 0;
};