#ifndef COMPANY_H
#define COMPANY_H

using namespace std;

template <typename T> 
class Node {
public:
    T data;
    Node<T> *next, *prev;

public:
    Node(/*Node<T> *next, Node<T> *prev*/) {
        next = prev = nullptr;
    };
    Node(T &data, Node<T> *next, Node<T> *prev) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    };
    ~Node(){};
};

template <typename T> 
class LList {
private:
    int size;
public:
    Node<T> *head;
    Node<T> *tail;

    //public:
public:
    LList() {
        size = 0;
        head = tail = new Node<T>();
    };
    ~LList(){};

    int length() { 
        return size;
    }

    bool isEmpty() {
        return length() == 0;
    }

    void addFirst(T &data) {
        if (length() == 0)
            head = tail = new Node<T>(data, nullptr, nullptr);
        else
        {
            Node<T> newNode(data, head, nullptr);
            head = &newNode;
        }
        size++;
    }

    void addLast(T &data) {
        if (isEmpty())
            head = tail = new Node<T>(data, nullptr, nullptr);
        else {
            Node<T> *tmp = tail;
            tail = tail->next = new Node<T>(data, nullptr, tmp);
        }
        size++;
    }

    T headData() {
        return head->data;
    }

    T tailData() {
        return tail->data;
    }

    void removeFrist(){};

};

//VIRTUAL CLASS
class Vehicle {
    public:
    string type, model, plate;
    int mileage, sits, price;
    bool status; //1 if available, else 0

    public:

    Vehicle(){};
    ~Vehicle(){};
    //Inheritance and Composition
    virtual bool serviceEngine() = 0;
    virtual bool serviceTransmission() = 0;
    virtual bool serviceTires() = 0;
};

//INHERITE CLASSES
class Convertible : public Vehicle {
    public:
    Convertible() {
        type = "Convertible";
        status = true;
    };
    ~Convertible(){};
    
    bool serviceEngine() {
        if (mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change oil.";
        }
        return true;
    };
    bool serviceTransmission() {
        if (mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change fluid.";
        }
        return true;
    };
    bool serviceTires() {
        if (mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change tires.";
        }
        return true;
    };

};

class Sedan : public Vehicle { 
    public:
    Sedan(){};
    ~Sedan(){};

    bool serviceEngine() {
        if (mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change oil.";
        }
        return true;
    };
    bool serviceTransmission() {
        if (mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change fluid.";
        }
        return true;
    };
    bool serviceTires() {
        if (mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change tires.";
        }
        return true;
    };
};

class SUV : public Vehicle {  
    public:
    SUV(){};
    ~SUV(){};

    bool serviceEngine() {
        if (mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change oil.";
        }
        return true;
    };
    bool serviceTransmission() {
        if (mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change fluid.";
        }
        return true;
    };
    bool serviceTires() {
        if (mileage > 1000) {
            cout << "This car has run more than 1000km! Need to change tires.";
        }
        return true;
    };
};

class Customer {
private:
    string name;
    string email;
    string dateOfBirth;
    string address;
    string licenseNum;
    bool gender; //1 if male, else 0

public:
    Customer(){};
    Customer(string name, string email, string dateOfBirth, string address, string licenseNum, bool gender) {
        this->name = name;
        this->email = email;
        this->dateOfBirth = dateOfBirth;
        this->address = address;
        this->licenseNum = licenseNum;
        this->gender = gender;
    };
    ~Customer();
};

class RentalContract {
public:
    Customer driver;
    string paymentMethod;
    int numberOfDaysRent;
    int contractNumber;

    //A person can rent many cars at once
    Convertible conv_car;
    Sedan sed_car;
    SUV suv_car;
    
public:
    RentalContract(){};
    //Create contract for booking convertible car
    RentalContract(Customer info, string method, int time, int contractNumber, Convertible conv_car) {
        this->driver = info;
        this->paymentMethod = method;
        this->numberOfDaysRent = time;
        this->contractNumber = contractNumber;
        this->conv_car = conv_car;
    }; 

    //Create contract for booking sedan car
    RentalContract(Customer info, string method, int time, int contractNumber, Sedan sed_car) {
        this->driver = info;
        this->paymentMethod = method;
        this->numberOfDaysRent = time;
        this->contractNumber = contractNumber;
        this->sed_car = sed_car;
    }; 

    //Create contract for booking suv car
    RentalContract(Customer info, string method, int time, int contractNumber, SUV suv_car) {
        this->driver = info;
        this->paymentMethod = method;
        this->numberOfDaysRent = time;
        this->contractNumber = contractNumber;
        this->suv_car = suv_car;
    }; 

    ~RentalContract(){};
    void createContract();
    void deleteContract();
    int total(int price, int numberOfDaysRent) { return price * numberOfDaysRent; }
    void printContract();

};

class CarRentalManagement {
    public:
    LList<Convertible> *convertibleFleet;
    LList<Sedan> *sedanFleet;
    LList<SUV> *suvFleet;

    //Customlers and Contracts
    //LList<Customer> *customerList;
    LList<RentalContract> *contractList;

    public:
    CarRentalManagement();
    ~CarRentalManagement();
    void addConv(CarRentalManagement *company);
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
    convertibleFleet = nullptr;
    sedanFleet = nullptr;
    suvFleet  =  nullptr;
    //customerList = nullptr;
    contractList = nullptr;
}

CarRentalManagement::~CarRentalManagement() {
    delete convertibleFleet;
    delete sedanFleet;
    delete suvFleet;
    //delete customerList;
    delete contractList;
}

void CarRentalManagement::addConv(CarRentalManagement *company) { 
    Convertible newConv1 = Convertible();
    newConv1.model = "DSA";
    newConv1.plate = "329HDS";

    newConv1.mileage = rand() % 5000 + 0;
    newConv1.sits = rand() % 7 + 4;
    newConv1.price = rand() % 500 + 150;

    Convertible newConv2 = Convertible();
    newConv2.model = "CA";
    newConv2.plate = "239HAN";

    newConv2.mileage = rand() % 5000 + 0;
    newConv2.sits = rand() % 7 + 4;
    newConv2.price = rand() % 500 + 150;

    Convertible newConv3 = Convertible();
    newConv3.model = "PPL";
    newConv3.plate = "902PLJ";

    newConv3.mileage = rand() % 5000 + 0;
    newConv3.sits = rand() % 7 + 4;
    newConv3.price = rand() % 500 + 150;

    Convertible newConv4 = Convertible();
    newConv4.model = "PGF";
    newConv4.plate = "678HIG";

    newConv4.mileage = rand() % 5000 + 0;
    newConv4.sits = rand() % 7 + 4;
    newConv4.price = rand() % 500 + 150;

    Convertible newConv5 = Convertible();
    newConv5.model = "SPE";
    newConv5.plate = "778GYH";

    newConv5.mileage = rand() % 5000 + 0;
    newConv5.sits = rand() % 7 + 4;
    newConv5.price = rand() % 500 + 150;

    company->convertibleFleet->addLast(newConv1);
    company->convertibleFleet->addLast(newConv2);
    company->convertibleFleet->addLast(newConv3);
    company->convertibleFleet->addLast(newConv4);
    company->convertibleFleet->addLast(newConv5);
}; //Add 5 Convertibles to the fleet

void CarRentalManagement::printFleet() {
    int choice;
    cout << "Choose the fleet you want to see!\n1. Convertible\n2. Sedan\n3. SUV\n" << endl;
    cout << "Input: "; cin >> choice;

    switch (choice) {
        case 1: 
        {
            cout << "This is a Convertible Fleet!\n";
            cout << "============================\n"; 
            cout << "No.\tModel\tPlate\tMileage\tSits\tPrice\tStatus\n";

            Node<Convertible> *tmp = convertibleFleet->head;
            int i = 1;
            while(tmp->next != NULL) {
                cout << i << "\t" << tmp->data.model << "\t" << tmp->data.plate 
                    << "\t" << tmp->data.mileage << "\t" << tmp->data.sits << "\t" << tmp->data.price;
                if(tmp->data.status == true) {
                    cout << "\tAvailable" << endl;
                } else cout << "\tNot Available" << endl;

                tmp = tmp->next; i++;
            }
            break;
        }
        case 2:
        {
            cout << "This is a Sedan Fleet!\n";
            cout << "============================\n"; 
            cout << "No.\tModel\tPlate\tMileage\tSits\tPrice\tStatus\n";
            Node<Sedan> *tmp = sedanFleet->head;
            int i = 0;
            while(tmp->next != NULL) {
                cout << i << "\t" << tmp->data.model << "\t" << tmp->data.plate 
                    << "\t" << tmp->data.mileage << "\t" << tmp->data.sits << "\t" << tmp->data.price;
                if(tmp->data.status == true) {
                    cout << "\tAvailable" << endl;
                } else cout << "\tNot Available" << endl;
                tmp = tmp->next; i++;
            }
            break;
        }
        case 3: 
        {
            cout << "This is a SUV Fleet!\n";
            cout << "============================\n"; 
            cout << "No.\tModel\tPlate\tMileage\tSits\tPrice\tStatus\n";
            Node<SUV> *tmp = suvFleet->head;
            int i = 1;
            while(tmp->next != NULL) {
                cout << i << "\t" << tmp->data.model << "\t" << tmp->data.plate 
                    << "\t" << tmp->data.mileage << "\t" << tmp->data.sits << "\t" << tmp->data.price;
                if(tmp->data.status == true) {
                    cout << "\tAvailable" << endl;
                } else cout << "\tNot Available" << endl;
                tmp = tmp->next; i++;
            }
            break;
        } 
    }
};

void CarRentalManagement::serviceFleet() {
    Node<Convertible> *tmp = convertibleFleet->head;
    cout << "Checking Convertible fleet...\n";
    for (int i = 0; i < convertibleFleet->length(); i++) {
        if(tmp->data.serviceEngine() == true) {
            cout << "Car " << tmp->data.plate << " has been maintained.\n";
            tmp->data.mileage = 0;
        }
        if(tmp->data.serviceTransmission() == true) {
            cout << "Car " << tmp->data.plate << " has been maintained.\n";
            tmp->data.mileage = 0;
        }
        if(tmp->data.serviceTires() == true) {
            cout << "Car " << tmp->data.plate << " has been maintained.\n";
            tmp->data.mileage = 0;
        }
        tmp = tmp->next;
    }
    cout << "Done check Convertible fleet...\n";

    Node<Sedan> *tmp_2 = sedanFleet->head;
    cout << "Checking Sedan fleet...\n";
    for (int i = 0; i < sedanFleet->length(); i++) {
        if(tmp_2->data.serviceEngine() == true) {
            cout << "Car " << tmp_2->data.plate << " has been maintained.\n";
            tmp_2->data.mileage = 0;
        }
        if(tmp_2->data.serviceTransmission() == true) {
            cout << "Car " << tmp_2->data.plate << " has been maintained.\n";
            tmp_2->data.mileage = 0;
        }
        if(tmp_2->data.serviceTires() == true) {
            cout << "Car " << tmp_2->data.plate << " has been maintained.\n";
            tmp_2->data.mileage = 0;
        }
        tmp_2 = tmp_2->next;
    }
    cout << "Done check Sedan fleet...\n";

    Node<SUV> *tmp_3 = suvFleet->head;
    cout << "Checking SUV fleet...\n";
    for (int i = 0; i < suvFleet->length(); i++) {
        if(tmp_3->data.serviceEngine() == true) {
            cout << "Car " << tmp_3->data.plate << " has been maintained.\n";
            tmp_3->data.mileage = 0;
        }
        if(tmp_3->data.serviceTransmission() == true) {
            cout << "Car " << tmp_3->data.plate << " has been maintained.\n";
            tmp_3->data.mileage = 0;
        }
        if(tmp_3->data.serviceTires() == true) {
            cout << "Car " << tmp_3->data.plate << " has been maintained.\n";
            tmp_3->data.mileage = 0;
        }
        tmp_3 = tmp_3->next;
    }
    cout << "Done check SUV fleet...\n";
};

#endif