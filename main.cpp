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
#include "company.h"

int main(){
    system("clear");
    CarRentalManagement carRent;
    //cout << carRent.totalVehicle() << endl; 
    //carRent.addConv();
    // carRent.addSedan();
    // carRent.addSUV();

    // cout << "Total number of car in the company: " << carRent.totalVehicle() << "\n";
    // carRent.printFleet();

    // Convertible newConv1 = Convertible(randomStr(3), randomStr(6));
    // newConv1.mileage = randomNum(5000,0);
    // newConv1.sits = randomNum(7,4);
    // newConv1.price = randomNum(500,150);

    // newConv1.serviceEngine(carRent.service);
    // carRent.printServiceHistory();


    carRent.addConv();
    carRent.addSedan();
    carRent.addSUV();

    carRent.serviceFleet();
    carRent.printServiceHistory();

    //carRent.createContract();
    carRent.printAllContract();
    

    return 0;
};