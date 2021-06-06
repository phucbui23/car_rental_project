#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <cstring>
#include <map>
#include <stdlib.h>
//#include "company.h"
#include "company2.h"

int main(){
    // CarRentalManagement *theCompany = new CarRentalManagement();
    // //Convertible testCar = Convertible();
    // Convertible newConv1 = Convertible();
    // newConv1.model = "DSA";
    // newConv1.plate = "329HDS";

    //theCompany->convertibleFleet->add(newConv1);
    //cout << theCompany->convertibleFleet->length();
    //theCompany->addConv(theCompany);
    // theCompany->printFleet();
    // delete theCompany;

    //LList<Convertible> *newFleet = new LList<Convertible>();
    //cout << newFleet->isEmpty();


    // LList<int> list;
    // cout << list.size;
    // LList<Convertible> con;
    // cout << con.size;

    CarRentalManagement carRent;
    cout << carRent.totalVehicle() << endl; 

    carRent.addConv();
    

    return 0;
};