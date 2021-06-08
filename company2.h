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
};

string randomStr(int n) {
    char alphabet[36] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                          'H', 'I', 'J', 'K', 'L', 'M', 'N', 
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                          'V', 'W', 'X', 'Y', 'Z', '0', '1',
                          '2', '3', '4', '5', '6', '7', '8', '9' };
  
    string str = "";
    for (int i = 0; i < n; i++) 
        str = str + alphabet[rand() % 36];
      
    return str;
};


int randomNum(int max, int min) {
    return (rand() % max + min);
};

class serviceHistory {
public:
    string note;
    string type, model, plate, checkpointID;
    int checkpoint;

public:
    serviceHistory(){};
    serviceHistory(string type, string model, string plate, int checkpoint) {
        this->type = type;
        this->model = model;
        this->plate = plate;
        this->checkpointID = randomStr(5);
        this->checkpoint = checkpoint;
    };
    // void serviceEngine();
    // void serviceTransmission();
    // void serviceTires();
};

//VIRTUAL CLASS
class Vehicle {
    public:
    string type, model, plate;
    int mileage, sits, price;
    bool status; //1 if available, else 0

    public:
    // class serviceHistory {
    //     public:
    //     string checkpointID;
    //     int checkpoint;

    //     public:
    //     serviceHistory(){};
    //     serviceHistory(int checkpoint){
    //         this->checkpointID = randomStr(5);
    //         this->checkpoint = checkpoint;
    //     };
        
    //     void serviceEngine();
    //     void serviceTransmission();
    //     void serviceTires();
    // };

    //Inheritance and Composition
    // virtual bool serviceEngine() = 0;
    // virtual bool serviceTransmission() = 0;
    // virtual bool serviceTires() = 0;
    // void serviceEngine();
    // void serviceTransmission();
    // void serviceTires();

    void serviceEngine(LList<serviceHistory> *service) {
        if (this->mileage > 500) {
            serviceHistory newCheckpoint(this->type, this->model, this->plate, this->mileage);
            newCheckpoint.note = "Change Engine";
            service->add(newCheckpoint);
            
            //system("clear");
            cout << "The ID of this service is: " << newCheckpoint.checkpointID << "\n";
            cout << "The mileage before service is: " << this->mileage << "\n";
            cout << "This car has run more than 500km! Change engine for the vehicle.\n";
            cout << "Mileage has been reduced 500 units\n";
            cout << "____________________________\n";
            this->mileage -= 500;
        }
        else cout << "This vehicle does not need to change Engine\n";
        cout << "____________________________\n";
    };
    void serviceTransmission(LList<serviceHistory> *service) {
        if (this->mileage > 700) {
            serviceHistory newCheckpoint(this->type, this->model, this->plate, this->mileage);
            newCheckpoint.note = "Change Transmission";
            service->add(newCheckpoint);
            
            //system("clear");
            cout << "The ID of this service is: " << newCheckpoint.checkpointID << "\n";
            cout << "The mileage before service is: " << this->mileage << "\n";
            cout << "This car has run more than 700km! Change transmission for the vehicle.\n";
            cout << "Mileage has been reduced 700 units\n";
            cout << "____________________________\n";
            this->mileage -= 700;
        }
        else cout << "This vehicle does not need to change Transmission\n";
        cout << "____________________________\n";
    };
    void serviceTires(LList<serviceHistory> *service) {
        if (this->mileage > 100) {
            serviceHistory newCheckpoint(this->type, this->model, this->plate, this->mileage);
            newCheckpoint.note = "Change Tires";
            service->add(newCheckpoint);
            
            //system("clear");
            cout << "The ID of this service is: " << newCheckpoint.checkpointID << "\n";
            cout << "The mileage before service is: " << this->mileage << "\n";
            cout << "This car has run more than 100km! Change tires for the vehicle.\n";
            cout << "Mileage has been reduced 100 units\n";
            cout << "____________________________\n";
            this->mileage -= 100;
        }
        else cout << "This vehicle does not need to change Tires\n";
        cout << "____________________________\n";
    };
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

    // void serviceEngine(LList<serviceHistory> *service) {
    //     if (this->mileage > 500) {
    //         serviceHistory newCheckpoint(this->mileage);
    //         service->add(newCheckpoint);
            
    //         system("clear");
    //         cout << "The ID of this service is: " << newCheckpoint.checkpointID << "\n";
    //         cout << "The mileage before service is: " << this->mileage << "\n";
    //         cout << "This car has run more than 500km! Change oil for the vehicle.\n";
    //         cout << "Mileage has been reduced 500 units";
    //         this->mileage -= 500;
    //     }
    //     else cout << "This vehicle does not need to change Engine";
    // };
    // void serviceTransmission(LList<serviceHistory> *service) {
    //     if (this->mileage > 700) {
    //         serviceHistory newCheckpoint(this->mileage);
    //         service->add(newCheckpoint);
            
    //         system("clear");
    //         cout << "The ID of this service is: " << newCheckpoint.checkpointID << "\n";
    //         cout << "The mileage before service is: " << this->mileage << "\n";
    //         cout << "This car has run more than 700km! Change transmission for the vehicle.\n";
    //         cout << "Mileage has been reduced 700 units";
    //         this->mileage -= 700;
    //     }
    //     else cout << "This vehicle does not need to change Transmission";
    // };
    // void serviceTires(LList<serviceHistory> *service) {
    //     if (this->mileage > 100) {
    //         serviceHistory newCheckpoint(this->mileage);
    //         service->add(newCheckpoint);
            
    //         system("clear");
    //         cout << "The ID of this service is: " << newCheckpoint.checkpointID << "\n";
    //         cout << "The mileage before service is: " << this->mileage << "\n";
    //         cout << "This car has run more than 100km! Change tires for the vehicle.\n";
    //         cout << "Mileage has been reduced 100 units";
    //         this->mileage -= 100;
    //     }
    //     else cout << "This vehicle does not need to change Engine";
    // };
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
    LList<serviceHistory> *service;
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
    void printServiceHistory();
    void printAllContract();
};

CarRentalManagement::CarRentalManagement() {
    convertibleFleet = new LList<Convertible>();
    sedanFleet = new LList<Sedan>();
    suvFleet = new LList<SUV>();
    service = new LList<serviceHistory>();
    //customerList = new LList<Customer>();
    //contractList = new LList<RentalContract>();
}

CarRentalManagement::~CarRentalManagement() {
    delete convertibleFleet;
    delete sedanFleet;
    delete suvFleet;
    delete service;
    //delete customerList;
    //delete contractList;
}

void CarRentalManagement::addConv() { 
    Convertible newConv1 = Convertible(randomStr(3), randomStr(6));
    newConv1.mileage = randomNum(5000,0);
    newConv1.sits = randomNum(7,4);
    newConv1.price = randomNum(500,150);

    Convertible newConv2 = Convertible(randomStr(3), randomStr(6));
    newConv2.mileage = randomNum(5000,0);
    newConv2.sits = randomNum(7,4);
    newConv2.price = randomNum(500,150);

    Convertible newConv3 = Convertible(randomStr(3), randomStr(6));
    newConv3.mileage = randomNum(5000,0);
    newConv3.sits = randomNum(7,4);
    newConv3.price = randomNum(500,150);

    Convertible newConv4 = Convertible(randomStr(3), randomStr(6));
    newConv4.mileage = randomNum(5000,0);
    newConv4.sits = randomNum(7,4);
    newConv4.price = randomNum(500,150);

    Convertible newConv5 = Convertible(randomStr(3), randomStr(6));
    newConv5.mileage = randomNum(5000,0);
    newConv5.sits = randomNum(7,4);
    newConv5.price = randomNum(500,150);

    this->convertibleFleet->add(newConv1);
    this->convertibleFleet->add(newConv2);
    this->convertibleFleet->add(newConv3);
    this->convertibleFleet->add(newConv4);
    this->convertibleFleet->add(newConv5);
}; //Add 5 Convertibles to the fleet

void CarRentalManagement::addSedan() { 
    Sedan newSed1 = Sedan(randomStr(3), randomStr(6));
    newSed1.mileage = randomNum(5000,0);
    newSed1.sits = randomNum(7,4);
    newSed1.price = randomNum(500,150);

    Sedan newSed2 = Sedan(randomStr(3), randomStr(6));
    newSed2.mileage = randomNum(5000,0);
    newSed2.sits = randomNum(7,4);
    newSed2.price = randomNum(500,150);

    Sedan newSed3 = Sedan(randomStr(3), randomStr(6));
    newSed3.mileage = randomNum(5000,0);
    newSed3.sits = randomNum(7,4);
    newSed3.price = randomNum(500,150);

    Sedan newSed4 = Sedan(randomStr(3), randomStr(6));
    newSed4.mileage = randomNum(5000,0);
    newSed4.sits = randomNum(7,4);
    newSed4.price = randomNum(500,150);

    Sedan newSed5 = Sedan(randomStr(3), randomStr(6));
    newSed5.mileage = randomNum(5000,0);
    newSed5.sits = randomNum(7,4);
    newSed5.price = randomNum(500,150);

    this->sedanFleet->add(newSed1);
    this->sedanFleet->add(newSed2);
    this->sedanFleet->add(newSed3);
    this->sedanFleet->add(newSed4);
    this->sedanFleet->add(newSed5);
}; //Add 5 Sedans to the fleet

void CarRentalManagement::addSUV() { 
    SUV newSUV1 = SUV(randomStr(3), randomStr(6));
    newSUV1.mileage = randomNum(5000,0);
    newSUV1.sits = randomNum(7,4);
    newSUV1.price = randomNum(500,150);

    SUV newSUV2 = SUV(randomStr(3), randomStr(6));
    newSUV2.mileage = randomNum(5000,0);
    newSUV2.sits = randomNum(7,4);
    newSUV2.price = randomNum(500,150);

    SUV newSUV3 = SUV(randomStr(3), randomStr(6));
    newSUV3.mileage = randomNum(5000,0);
    newSUV3.sits = randomNum(7,4);
    newSUV3.price = randomNum(500,150);

    SUV newSUV4 = SUV(randomStr(3), randomStr(6));
    newSUV4.mileage = randomNum(5000,0);
    newSUV4.sits = randomNum(7,4);
    newSUV4.price = randomNum(500,150);

    SUV newSUV5 = SUV(randomStr(3), randomStr(6));
    newSUV5.mileage = randomNum(5000,0);
    newSUV5.sits = randomNum(7,4);
    newSUV5.price = randomNum(500,150);

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

void CarRentalManagement::serviceFleet() {
    LList<Convertible>::Node *tmp = new LList<Convertible>::Node();
    LList<Sedan>::Node *tmp2 = new LList<Sedan>::Node();
    LList<SUV>::Node *tmp3 = new LList<SUV>::Node();

    tmp = convertibleFleet->head;
    cout << "Checking Convertible fleet...\n";
    cout << "============================\n";
    for (int i = 0; i < convertibleFleet->size; i++) {
        tmp->getData().serviceTires(this->service);
        tmp->getData().serviceEngine(this->service);
        tmp->getData().serviceTransmission(this->service);
        tmp = tmp->next;
    }
    cout << "Done check Convertible fleet...\n";
    cout << "============================\n";

    tmp2 = sedanFleet->head;
    cout << "Checking Sedan fleet...\n";
    cout << "============================\n";
    for (int i = 0; i < sedanFleet->length(); i++) {
        tmp2->getData().serviceTires(this->service);
        tmp2->getData().serviceEngine(this->service);
        tmp2->getData().serviceTransmission(this->service);
        tmp2 = tmp2->next;
    }
    cout << "Done check Sedan fleet...\n";
    cout << "============================\n";

    tmp3 = suvFleet->head;
    cout << "Checking SUV fleet...\n";
    cout << "============================\n";
    for (int i = 0; i < suvFleet->length(); i++) {
        tmp3->getData().serviceTires(this->service);
        tmp3->getData().serviceEngine(this->service);
        tmp3->getData().serviceTransmission(this->service);
        tmp3 = tmp3->next;
    }
    cout << "Done check SUV fleet...\n";
    cout << "============================\n";
};

void CarRentalManagement::printServiceHistory() {
    system("clear");
    cout << "This is the service history!\n";
    cout << "============================\n";
    cout << "Service ID\tCar Type\tModel\tPlate\tMileage run\tNote\n";
    cout << "------------------------------------------------------------------------------------\n";
    LList<serviceHistory>::Node *tmp = new LList<serviceHistory>::Node();
    tmp = service->head;
    for (int i = 0; i < service->size; i++)
    {
        cout << tmp->getData().checkpointID << "\t\t" << tmp->getData().type << "\t" << tmp->getData().model
             << "\t" << tmp->getData().plate << "\t" << tmp->getData().checkpoint << "\t\t" << tmp->getData().note << "\n";
        tmp = tmp->next;
    }
}

#endif