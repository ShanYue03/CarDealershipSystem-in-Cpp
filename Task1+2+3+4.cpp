#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <random>
#include <algorithm>
#include <ctime> 

using namespace std;

const string FILENAME = "users.txt";

// Function prototypes
void saveUsersToFile(const map<string, string>& users);
void loadUsersFromFile(map<string, string>& users);
void addNewUser(map<string, string>& users);
bool authenticateUser(const map<string, string>& users, const string& id, const string& password);

void saveUsersToFile(const map<string, string>& users) {
    ofstream outfile(FILENAME);
    if (outfile.is_open()) {
        for (const auto& user : users) {
            outfile << user.first << " " << user.second << endl;
        }
        outfile.close();
    } else {
        cerr << "Unable to open file for writing." << endl;
    }
}

void loadUsersFromFile(map<string, string>& users) {
    ifstream infile(FILENAME);
    if (infile.is_open()) {
        string id, password;
        while (infile >> id >> password) {
            users[id] = password;
        }
        infile.close();
    } else {
        cerr << "No user file found. Starting with an empty user list." << endl;
    }
}

void addNewUser(map<string, string>& users) {
    string id, password;
    cout << "Enter new user ID: ";
    cin >> id;
    cout << "Enter new user password: ";
    cin >> password;
    users[id] = password;
}

bool authenticateUser(const map<string, string>& users, const string& id, const string& password) {
    auto it = users.find(id);
    if (it != users.end() && it->second == password) {
        return true;
    }
    return false;
}

struct Car{
    string id;
    string brand;
    string color;
    string countryOfManufacture;
    int yearOfManufacture;
    double price;
};

vector<Car> carDatabase;

string generateCarID(const string& brand){
    string id = brand.substr(0, 3);
    id += to_string(rand() % 1000000 + 1000000);
    return id;
}

void saveCarDatabase() {
    ofstream outFile("cars.txt");
    if (outFile.is_open()) {
    for (const auto& car : carDatabase) {
        outFile << car.id << ","
                << car.brand << ","
                << car.color << ","
                << car.countryOfManufacture << ","
                << car.yearOfManufacture << ","
                << car.price << endl;
    }
    outFile.close();
}   else{
        cerr << "Unable to open file for writing." << endl;
     }
}


void loadCarDatabase() {
    ifstream inFile("cars.txt");
    string line;
    carDatabase.clear();
    while (getline(inFile, line)) {
        istringstream ss(line);
        Car car;
        string year, price;
        getline(ss, car.id, ',');
        getline(ss, car.brand, ',');
        getline(ss, car.color, ',');
        getline(ss, car.countryOfManufacture, ',');
        getline(ss, year, ',');
        getline(ss, price, ',');
        car.yearOfManufacture = stoi(year);
        car.price = stod(price);
        carDatabase.push_back(car);
    }
    inFile.close();
}

void addCar() {
    loadCarDatabase();
    Car newCar;
    cout << "Enter car brand: ";
    cin >> newCar.brand;
    cout << "Enter car color: ";
    cin >> newCar.color;
    cout << "Enter country of manufacture: ";
    cin >> newCar.countryOfManufacture;
    cout << "Enter year of manufacture: ";
    cin >> newCar.yearOfManufacture;
    cout << "Enter car price: RM";
    cin >> newCar.price;
    newCar.id = generateCarID(newCar.brand);
    carDatabase.push_back(newCar);
    saveCarDatabase();
    cout << "Car added successfully with ID: " << newCar.id << endl;
}

void modifyCarData(){
    loadCarDatabase();
    string carID;
    cout << "Enter the car ID to modify: ";
    cin >> carID;
    for(auto& car : carDatabase){
        if(car.id == carID){
            cout << "Enter new car brand: ";
            cin >> car.brand;
            cout << "Enter new car color: ";
            cin >> car.color;
            cout << "Enter new country of manufacture: ";
            cin >> car.countryOfManufacture;
            cout << "Enter new year of manufacture: ";
            cin >> car.yearOfManufacture;
            cout << "Enter new car price: RM";
            cin >> car.price;
            saveCarDatabase();
            cout << "Car data updated successfully." << endl;
            return;
        }
    }
    cout << "Car ID not found." << endl;
}

void displayAllCars() {
    loadCarDatabase();
    for (const auto& car : carDatabase) {
        cout << "ID: " << car.id << ", Brand: " << car.brand << ", Color: " << car.color
             << ", Country of Manufacture: " << car.countryOfManufacture << ", Year: "
             << car.yearOfManufacture << ", Price: RM" << car.price << endl;
    }
}

bool compareByBrand(const Car& a, const Car& b) {
    return a.brand < b.brand;
}

bool compareByPrice(const Car& a, const Car& b) {
    return a.price < b.price;
}

bool compareByID(const Car& a, const Car& b) {
    return a.id < b.id;
}

void sortByBrand() {
    //Display in alphabetical order (A-Z)
    loadCarDatabase();
    sort(carDatabase.begin(), carDatabase.end(), compareByBrand);
    saveCarDatabase();
    cout << "Cars sorted by brand." << endl;
}

void sortByPrice() {
    //Ascending from top to bottom
    loadCarDatabase();
    sort(carDatabase.begin(), carDatabase.end(), compareByPrice);
    saveCarDatabase();
    cout << "Cars sorted by price." << endl;
}

void sortByID() {
    //Display in alphabetical order (A-Z),if the brands are the same, sort in ascending order by considering the last few digits of the ID
    loadCarDatabase();
    sort(carDatabase.begin(), carDatabase.end(), compareByID);
    saveCarDatabase();
    cout << "Cars sorted by ID." << endl;
}

void sortByBestSellingBrand() {
    // Display the number of car brands in descending order
    loadCarDatabase();
    map<string, int> brandCount;
    for (const auto& car : carDatabase) {
        brandCount[car.brand]++;
    }

    sort(carDatabase.begin(), carDatabase.end(), [&brandCount](const Car& a, const Car& b) {
        return brandCount[a.brand] > brandCount[b.brand];
    });

    saveCarDatabase();
    cout << "Cars sorted by best-selling brand." << endl;
}

// Function to track and display the number of cars sold
void trackNumberOfCarsSold() {
    loadCarDatabase();
    cout << "Total number of cars sold: " << carDatabase.size() << endl;
}

// Function to remove a car record based on the car ID
void removeCarRecord() {
    string carID;
    cout << "Enter the car ID to remove: ";
    cin >> carID;
    auto it = remove_if(carDatabase.begin(), carDatabase.end(), [&carID](const Car& car) {
        return car.id == carID;
    });
    if (it != carDatabase.end()) {
        carDatabase.erase(it, carDatabase.end());
        saveCarDatabase();
        cout << "Car record removed successfully." << endl;
    } else {
        cout << "Car ID not found." << endl;
    }
}

// Function to check and display the current stock of cars
void checkStock() {
    loadCarDatabase();
    cout << "Total cars in stock: " << carDatabase.size() << endl;
}

// Linear Search Function
int linearSearch(const vector<Car>& cars, const string& id) {
    for (size_t i = 0; i < cars.size(); ++i) {
        if (cars[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Binary Search Function
int binarySearch(const vector<Car>& cars, const string& brand) {
    int left = 0;
    int right = cars.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (cars[mid].brand == brand) {
            return mid; // return index
        } else if (cars[mid].brand < brand) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // no find return -1
}

// Search Car By ID using Linear Search
void searchCarByID() {
    string carID;
    cout << "Enter the car ID to search: ";
    cin >> carID;
    int index = linearSearch(carDatabase, carID);
    if (index != -1) {
        const auto& car = carDatabase[index];
        cout << "Car found: ID: " << car.id << ", Brand: " << car.brand << ", Color: " << car.color
             << ", Country of Manufacture: " << car.countryOfManufacture << ", Year: "
             << car.yearOfManufacture << ", Price: RM" << car.price << endl;
    } else {
        cout << "Car ID not found." << endl;
    }
}

// Search Best Selling Brand using Binary Search
void searchBestSellingBrand() {
    loadCarDatabase();

    sort(carDatabase.begin(), carDatabase.end(), [](const Car& a, const Car& b) {
        return a.brand < b.brand;
    });

    map<string, int> brandCount;
    for (const auto& car : carDatabase) {
        if (brandCount.find(car.brand) == brandCount.end()) {
            int index = binarySearch(carDatabase, car.brand);
            if (index != -1) {
                int count = 0;
                for (size_t i = index; i < carDatabase.size() && carDatabase[i].brand == car.brand; ++i) {
                    ++count;
                }
                brandCount[car.brand] = count;
            }
        }
    }

    string bestSellingBrand;
    int maxCount = 0;
    for (const auto& entry : brandCount) {
        if (entry.second > maxCount) {
            bestSellingBrand = entry.first;
            maxCount = entry.second;
        }
    }

    if (!bestSellingBrand.empty()) {
        cout << "Best-selling brand: " << bestSellingBrand << " with " << maxCount << " cars sold." << endl;
    } else {
        cout << "No cars in the database." << endl;
    }
}

int main() {
    srand(time(0));
    map<string, string> users;

    loadUsersFromFile(users);

    int choice;

    do{
        cout << "----------------------------------" << endl;
        cout << "\t     Welcome" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Login\n2. Register\n3. Exit\nEnter your choice: ";
        cin >> choice;

        if(choice==3){
            cout<< "See you!";
            break;
        }

        if (choice == 1) {
            bool identified = false;
            while (!identified) {
                string id, password;
                cout << "Enter your ID: ";
                cin >> id;
                cout << "Enter your password: ";
                cin >> password;

                if (authenticateUser(users, id, password)) {
                    cout << "Authentication successful. Welcome!" << endl;
                    identified = true;
                } else {
                    cout << "\nInvalid ID or password." << endl;
                }
            }

            int menuChoice = 0;
            while (menuChoice != 13) {
                cout << "----------------------------------" << endl;
                cout << "\t  Option to Choose" << endl;
                cout << "----------------------------------" << endl;
                cout << "1. Add a new car\n2. Modify car data\n3. Display all cars\n4. Sort cars by brand\n";
                cout << "5. Sort cars by price\n6. Sort cars by ID\n7. Sort cars by best-selling brand\n";
                cout << "8. Search car by ID\n9. Search best-selling brand\n10. Track number of cars sold\n";
                cout << "11. Remove car record\n12. Check stock\n13. Exit\n";
                cout << "Enter your choice: ";
                cin >> menuChoice;

                switch (menuChoice) {
                    case 1:
                        addCar();
                        break;
                    case 2:
                        modifyCarData();
                        break;
                    case 3:
                        displayAllCars();
                        break;
                    case 4:
                        sortByBrand();
                        break;
                    case 5:
                        sortByPrice();
                        break;
                    case 6:
                        sortByID();
                        break;
                    case 7:
                        sortByBestSellingBrand();
                        break;
                    case 8:
                        searchCarByID();
                        break;
                    case 9:
                        searchBestSellingBrand();
                        break;
                    case 10:
                        trackNumberOfCarsSold();
                        break;
                    case 11:
                        removeCarRecord();
                        break;
                    case 12:
                        checkStock();
                        break;
                    case 13:
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
            }
            cout << "\nThank you and Goodbye!" << endl;
        } else if (choice == 2) {
            addNewUser(users);
            saveUsersToFile(users);
            cout << "New user registered successfully." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    }while(choice!=3);

    return 0;
}


