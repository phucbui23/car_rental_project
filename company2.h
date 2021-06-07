#ifndef COMPANY2_H
#define COMPANY2_H

using namespace std;

template <typename T> 
class LList {
public:
    int size;

    class Node {
    private:
        T data;
    public:
        Node *next;

    public:
        Node() {
            this->next = nullptr;
        };
        Node(T data, Node *next) {
            this->data = data;
            this->next = next;
        };
        ~Node(){};

        T getData(){
            return data;
        }
    };
public:
    Node *head;
    Node *tail;

public:
    LList() {
        this->size = 0;
        head = new Node();
        tail = new Node();
        this->head = this->tail = nullptr;
    };
    ~LList(){};

    int length() { 
        return size;
    }

    bool isEmpty() {
        return length() == 0;
    }

    void add(T &data) {
        if (isEmpty()) {
            Node *newNode = new Node(data, nullptr);
            this->head = newNode;
            this->tail = newNode;
            this->size++;
            return;
        }

        Node *newNode = new Node(data, nullptr);
        this->tail->next = newNode;
        this->tail = newNode;
        this->size++;
        return;
    }

    // T headData() {
    //     return this->head->data;
    // }

    // T tailData() {
    //     return this->tail->data;
    // }
};

//VIRTUAL CLASS
class Vehicle {
    public:
    string type, model, plate;
    int mileage, sits, price;
    bool status; //1 if available, else 0

    // Vehicle(){};
    // ~Vehicle(){};
    //Inheritance and Composition
    virtual bool serviceEngine() = 0;
    virtual bool serviceTransmission() = 0;
    virtual bool serviceTires() = 0;
};

//INHERITE CLASSES
class Convertible : public Vehicle {
    public:
    Convertible(){};
    Convertible(string model, string plate) {
        this->type = "Convertible";
        this->status = true;
        this->model = model;
        this->plate = plate;
    };

    ~Convertible(){};
    
    bool serviceEngine() {
        if (this->mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change oil.";
        }
        return true;
    };
    bool serviceTransmission() {
        if (this->mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change fluid.";
        }
        return true;
    };
    bool serviceTires() {
        if (this->mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change tires.";
        }
        return true;
    };

};

class Sedan : public Vehicle { 
    public:
    Sedan(){};

    Sedan(string model, string plate) {
        this->type = "Sedan";
        this->status = true;
        this->model = model;
        this->plate = plate;
    };

    ~Sedan(){};

    bool serviceEngine() {
        if (this->mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change oil.";
        }
        return true;
    };
    bool serviceTransmission() {
        if (this->mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change fluid.";
        }
        return true;
    };
    bool serviceTires() {
        if (this->mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change tires.";
        }
        return true;
    };
};

class SUV : public Vehicle {  
    public:
    SUV(){};
    SUV(string model, string plate) {
        this->type = "SUV";
        this->status = true;
        this->model = model;
        this->plate = plate;
    };

    ~SUV(){};

    bool serviceEngine() {
        if (this->mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change oil.";
        }
        return true;
    };
    bool serviceTransmission() {
        if (this->mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change fluid.";
        }
        return true;
    };
    bool serviceTires() {
        if (this->mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change tires.";
        }
        return true;
    };
};

// class Customer {
// private:
//     string name;
//     string email;
//     string dateOfBirth;
//     string address;
//     string licenseNum;
//     bool gender; //1 if male, else 0

// public:
//     Customer(){};
//     Customer(string name, string email, string dateOfBirth, string address, string licenseNum, bool gender) {
//         this->name = name;
//         this->email = email;
//         this->dateOfBirth = dateOfBirth;
//         this->address = address;
//         this->licenseNum = licenseNum;
//         this->gender = gender;
//     };
//     ~Customer();
// };

// class RentalContract {
// public:
//     Customer driver;
//     string paymentMethod;
//     int numberOfDaysRent;
//     int contractNumber;

//     //A person can rent many cars at once
//     Convertible conv_car;
//     Sedan sed_car;
//     SUV suv_car;
    
// public:
//     RentalContract(){};
//     //Create contract for booking convertible car
//     RentalContract(Customer info, string method, int time, int contractNumber, Convertible conv_car) {
//         this->driver = info;
//         this->paymentMethod = method;
//         this->numberOfDaysRent = time;
//         this->contractNumber = contractNumber;
//         this->conv_car = conv_car;
//     }; 

//     //Create contract for booking sedan car
//     RentalContract(Customer info, string method, int time, int contractNumber, Sedan sed_car) {
//         this->driver = info;
//         this->paymentMethod = method;
//         this->numberOfDaysRent = time;
//         this->contractNumber = contractNumber;
//         this->sed_car = sed_car;
//     }; 

//     //Create contract for booking suv car
//     RentalContract(Customer info, string method, int time, int contractNumber, SUV suv_car) {
//         this->driver = info;
//         this->paymentMethod = method;
//         this->numberOfDaysRent = time;
//         this->contractNumber = contractNumber;
//         this->suv_car = suv_car;
//     }; 

//     ~RentalContract(){};
//     void createContract();
//     void deleteContract();
//     int total(int price, int numberOfDaysRent) { return price * numberOfDaysRent; }
//     void printContract();

// };

class CarRentalManagement {
    public:
    LList<Convertible> *convertibleFleet;
    LList<Sedan> *sedanFleet;
    LList<SUV> *suvFleet;

    //Customers and Contracts
    //LList<Customer> *customerList;
    //LList<RentalContract> *contractList;

    public:
    CarRentalManagement();
    ~CarRentalManagement();
    void addConv();
    void addSedan();
    void addSUV();
    void printFleet();
    int totalVehicle() {
        return convertibleFleet->length() + sedanFleet->length() + suvFleet->length();
    }; 
    void CarRentalMgmt();

    //iterates through all vehicles it manages to check if the cars need service
    void serviceFleet();
    void printAllContract();
};

CarRentalManagement::CarRentalManagement() {
    convertibleFleet = new LList<Convertible>();
    sedanFleet = new LList<Sedan>();
    suvFleet = new LList<SUV>();
    //customerList = new LList<Customer>();
    //contractList = new LList<RentalContract>();
}

CarRentalManagement::~CarRentalManagement() {
    delete convertibleFleet;
    delete sedanFleet;
    delete suvFleet;
    //delete customerList;
    //delete contractList;
}

void CarRentalManagement::addConv() { 
    Convertible newConv1 = Convertible("DSA", "329HDS");
    newConv1.mileage = rand() % 5000 + 0;
    newConv1.sits = rand() % 7 + 4;
    newConv1.price = rand() % 500 + 150;

    Convertible newConv2 = Convertible("CA", "239HAN");
    newConv2.mileage = rand() % 5000 + 0;
    newConv2.sits = rand() % 7 + 4;
    newConv2.price = rand() % 500 + 150;

    Convertible newConv3 = Convertible("PPL", "902PLJ");
    newConv3.mileage = rand() % 5000 + 0;
    newConv3.sits = rand() % 7 + 4;
    newConv3.price = rand() % 500 + 150;

    Convertible newConv4 = Convertible("PGF", "678HIG");
    newConv4.mileage = rand() % 5000 + 0;
    newConv4.sits = rand() % 7 + 4;
    newConv4.price = rand() % 500 + 150;

    Convertible newConv5 = Convertible("SPE", "778GYH");
    newConv5.mileage = rand() % 5000 + 0;
    newConv5.sits = rand() % 7 + 4;
    newConv5.price = rand() % 500 + 150;

    this->convertibleFleet->add(newConv1);
    this->convertibleFleet->add(newConv2);
    this->convertibleFleet->add(newConv3);
    this->convertibleFleet->add(newConv4);
    this->convertibleFleet->add(newConv5);
}; //Add 5 Convertibles to the fleet

void CarRentalManagement::addSedan() { 
    Sedan newSed1 = Sedan("DSA", "329HDS");
    newSed1.mileage = rand() % 5000 + 0;
    newSed1.sits = rand() % 7 + 4;
    newSed1.price = rand() % 500 + 150;

    Sedan newSed2 = Sedan("CA", "239HAN");
    newSed2.mileage = rand() % 5000 + 0;
    newSed2.sits = rand() % 7 + 4;
    newSed2.price = rand() % 500 + 150;

    Sedan newSed3 = Sedan("PPL", "902PLJ");
    newSed3.mileage = rand() % 5000 + 0;
    newSed3.sits = rand() % 7 + 4;
    newSed3.price = rand() % 500 + 150;

    Sedan newSed4 = Sedan("PGF", "678HIG");
    newSed4.mileage = rand() % 5000 + 0;
    newSed4.sits = rand() % 7 + 4;
    newSed4.price = rand() % 500 + 150;

    Sedan newSed5 = Sedan("SPE", "778GYH");
    newSed5.mileage = rand() % 5000 + 0;
    newSed5.sits = rand() % 7 + 4;
    newSed5.price = rand() % 500 + 150;

    this->sedanFleet->add(newSed1);
    this->sedanFleet->add(newSed2);
    this->sedanFleet->add(newSed3);
    this->sedanFleet->add(newSed4);
    this->sedanFleet->add(newSed5);
}; //Add 5 Sedans to the fleet

void CarRentalManagement::addSUV() { 
    SUV newSUV1 = SUV("DSA", "329HDS");
    newSUV1.mileage = rand() % 5000 + 0;
    newSUV1.sits = rand() % 7 + 4;
    newSUV1.price = rand() % 500 + 150;

    SUV newSUV2 = SUV("CA", "239HAN");
    newSUV2.mileage = rand() % 5000 + 0;
    newSUV2.sits = rand() % 7 + 4;
    newSUV2.price = rand() % 500 + 150;

    SUV newSUV3 = SUV("PPL", "902PLJ");
    newSUV3.mileage = rand() % 5000 + 0;
    newSUV3.sits = rand() % 7 + 4;
    newSUV3.price = rand() % 500 + 150;

    SUV newSUV4 = SUV("PGF", "678HIG");
    newSUV4.mileage = rand() % 5000 + 0;
    newSUV4.sits = rand() % 7 + 4;
    newSUV4.price = rand() % 500 + 150;

    SUV newSUV5 = SUV("SPE", "778GYH");
    newSUV5.mileage = rand() % 5000 + 0;
    newSUV5.sits = rand() % 7 + 4;
    newSUV5.price = rand() % 500 + 150;

    this->suvFleet->add(newSUV1);
    this->suvFleet->add(newSUV2);
    this->suvFleet->add(newSUV3);
    this->suvFleet->add(newSUV4);
    this->suvFleet->add(newSUV5);
}; //Add 5 SUVs to the fleet

void CarRentalManagement::printFleet() {
    int choice;
    while(true) {
        cout << "============================\n";
        cout << "Choose the fleet you want to see!\n1. Convertible\n2. Sedan\n3. SUV\n4. Exit\n" << endl;
        cout << "Input your choice: "; cin >> choice;
        switch (choice) 
        {
            case 1:
            {
                system("clear");
                cout << "This is a Convertible Fleet!\n";
                cout << "============================\n";
                cout << "No.\tModel\tPlate\tMileage\tSits\tPrice\tStatus\n";
                LList<Convertible>::Node *tmp = new LList<Convertible>::Node();
                tmp = convertibleFleet->head;

                for (int i = 0; i < convertibleFleet->size; i++) {
                    cout << i + 1 << "\t" << tmp->getData().model << "\t" << tmp->getData().plate
                        << "\t" << tmp->getData().mileage << "\t" << tmp->getData().sits << "\t" << tmp->getData().price;
                    if (tmp->getData().status == true)
                    {
                        cout << "\tAvailable" << endl;
                    }
                    else
                        cout << "\tNot Available" << endl;

                    tmp = tmp->next;
                }
                break;
            }
            case 2:
            {
                system("clear");
                cout << "This is a Sedan Fleet!\n";
                cout << "============================\n";
                cout << "No.\tModel\tPlate\tMileage\tSits\tPrice\tStatus\n";
                LList<Sedan>::Node *tmp = new LList<Sedan>::Node();
                tmp = sedanFleet->head;

                for (int i = 0; i < sedanFleet->size; i++) {
                    cout << i + 1 << "\t" << tmp->getData().model << "\t" << tmp->getData().plate
                        << "\t" << tmp->getData().mileage << "\t" << tmp->getData().sits << "\t" << tmp->getData().price;
                    if (tmp->getData().status == true)
                    {
                        cout << "\tAvailable" << endl;
                    }
                    else
                        cout << "\tNot Available" << endl;

                    tmp = tmp->next;
                }
                break;
            }
            case 3:
            {
                system("clear");
                cout << "This is a SUV Fleet!\n";
                cout << "============================\n";
                cout << "No.\tModel\tPlate\tMileage\tSits\tPrice\tStatus\n";
                LList<SUV>::Node *tmp = new LList<SUV>::Node();
                tmp = suvFleet->head;

                for (int i = 0; i < suvFleet->size; i++) {
                    cout << i + 1 << "\t" << tmp->getData().model << "\t" << tmp->getData().plate
                        << "\t" << tmp->getData().mileage << "\t" << tmp->getData().sits << "\t" << tmp->getData().price;
                    if (tmp->getData().status == true)
                    {
                        cout << "\tAvailable" << endl;
                    }
                    else
                        cout << "\tNot Available" << endl;

                    tmp = tmp->next;
                }
                break;
            }
            case 4:
            {
                return;
            }
        }
    }
};

// void CarRentalManagement::serviceFleet() {
//     Node<Convertible> *tmp = convertibleFleet->head;
//     cout << "Checking Convertible fleet...\n";
//     for (int i = 0; i < convertibleFleet->length(); i++) {
//         if(tmp->data.serviceEngine() == true) {
//             cout << "Car " << tmp->data.plate << " has been maintained.\n";
//             tmp->data.mileage = 0;
//         }
//         if(tmp->data.serviceTransmission() == true) {
//             cout << "Car " << tmp->data.plate << " has been maintained.\n";
//             tmp->data.mileage = 0;
//         }
//         if(tmp->data.serviceTires() == true) {
//             cout << "Car " << tmp->data.plate << " has been maintained.\n";
//             tmp->data.mileage = 0;
//         }
//         tmp = tmp->next;
//     }
//     cout << "Done check Convertible fleet...\n";

//     Node<Sedan> *tmp_2 = sedanFleet->head;
//     cout << "Checking Sedan fleet...\n";
//     for (int i = 0; i < sedanFleet->length(); i++) {
//         if(tmp_2->data.serviceEngine() == true) {
//             cout << "Car " << tmp_2->data.plate << " has been maintained.\n";
//             tmp_2->data.mileage = 0;
//         }
//         if(tmp_2->data.serviceTransmission() == true) {
//             cout << "Car " << tmp_2->data.plate << " has been maintained.\n";
//             tmp_2->data.mileage = 0;
//         }
//         if(tmp_2->data.serviceTires() == true) {
//             cout << "Car " << tmp_2->data.plate << " has been maintained.\n";
//             tmp_2->data.mileage = 0;
//         }
//         tmp_2 = tmp_2->next;
//     }
//     cout << "Done check Sedan fleet...\n";

//     Node<SUV> *tmp_3 = suvFleet->head;
//     cout << "Checking SUV fleet...\n";
//     for (int i = 0; i < suvFleet->length(); i++) {
//         if(tmp_3->data.serviceEngine() == true) {
//             cout << "Car " << tmp_3->data.plate << " has been maintained.\n";
//             tmp_3->data.mileage = 0;
//         }
//         if(tmp_3->data.serviceTransmission() == true) {
//             cout << "Car " << tmp_3->data.plate << " has been maintained.\n";
//             tmp_3->data.mileage = 0;
//         }
//         if(tmp_3->data.serviceTires() == true) {
//             cout << "Car " << tmp_3->data.plate << " has been maintained.\n";
//             tmp_3->data.mileage = 0;
//         }
//         tmp_3 = tmp_3->next;
//     }
//     cout << "Done check SUV fleet...\n";
// };

#endif