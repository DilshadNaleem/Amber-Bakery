#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std; 

struct Item { 
    string name;
    string category;
    double price;
};

struct User {
    string name;
    int age;
    string address;
    string phone;
    string email;
}; 

vector<Item>  bakeryItems = {
    {"Victoria Cake", "Cakes", 15.00},
    {"Chocolate Fudge Cake", "Cakes", 25.00},
    {"Carrot Cake", "Cakes", 12.00},
    {"Lemon Drizzle Cake", "Cakes", 10.00},
    {"Red Velvet Cake", "Cakes", 30.00},

    {"Sticky Toffee Pudding", "Desserts", 6.00},
    {"Eton Mess", "Desserts", 4.00},
    {"Bread and Butter Pudding", "Desserts", 7.00},
    {"Apple Crumble", "Desserts", 5.00},
    {"Chocolate Mousse", "Desserts", 8.00},

    {"Sourdough Bread", "Breads", 2.00},
    {"Whole Wheat Bread", "Breads", 3.00},
    {"Baguette", "Breads", 1.00},
    {"Focaccia Bread", "Breads", 4.00},
    {"Ciabatta Bread", "Breads", 2.00},

    {"Chocolate Chip Cookies", "Cookies", 3.00},
    {"Shortbread Cookies", "Cookies", 4.00},
    {"Gingerbread Cookies", "Cookies", 2.00},
    {"Double Chocolate Cookies", "Cookies", 5.00},
    {"Oatmeal Raisin Cookies", "Cookies", 3.00},

    {"Tea", "Beverages", 9.00},
    {"Coffee", "Beverages", 4.00},
    {"Fruit Juice", "Beverages", 3.00},
    {"Soft Drink", "Beverages", 2.00},
    {"Alcoholic Beverage", "Beverages", 5.00}
};

vector<User> staffUsers;

void displayCompanyDetail() {
    cout << "\n----------------------- Welcome to Amber Bakery System ------------------\n";
}

void aboutCompanyDetails() {
    cout << "\n----------------------- Welcome to Amber Bakery System --------------------\n\n";
    cout << " Amber Bakery is a renowned bakery dedicated to providing quality bakery items\n";
    cout << " and beverages to customers locally and internationally.\n\n";
    cout << " Vision: To combine traditional baking methods with modern dietary\n";
    cout << " consciousness to bring wholesome and irresistibly delicious artisanal baked\n";
    cout << " goods to our community every day.\n\n";
    cout << " Mission: To bake gourmet goodies that inspire joy, foster community, and\n";
    cout << " enrich the lives of every customer with warmth and sweetness.\n\n";
    cout << " Address: 24/2, 28th Lane, Flower Road, Colombo 7\n";
    cout << " Contact Number: 075-837-2881\n";
    cout << " Facebook: DeliciousAmberBakery@fb.com\n";
    cout << " Instagram: DeliciousAmberBakery@insta.com\n";
    cout << " Email: DeliciousAmberBakery@gmail.com\n";
    cout << " Website: www.DeliciousAmberBakery.co\n\n";
    cout << " Back to Home Page\n";
}

void displayBakeryItems() {
    cout << "\n..... Available Bakery Items .....\n\n";
    cout << "1) Cakes\n2) Desserts\n3) Breads\n4) Cookies\n5) Beverages\n\n";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    string category;
    switch (choice) {
        case 1: category = "Cakes"; break;
        case 2: category = "Desserts"; break;
        case 3: category = "Breads"; break;
        case 4: category = "Cookies"; break;
        case 5: category = "Beverages"; break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            return;
    }

    cout << "\nWelcome to the " << category << " section in Amber Bakery\n\n";
    bool found = false;

    for (const auto &item : bakeryItems) {
        if (item.category == category) {
            found = true;
            cout << left << setw(28) << item.name << "  $" << fixed << setprecision(2)
                 << item.price << "\n";
        }
    }

    if (!found) {
        cout << "No items available in this category.\n";
    }
}

void addUser() {
    User newUser;

    cout << "Enter staff name: ";
    cin >> newUser.name;

    cout << "Enter staff age: ";
    cin >> newUser.age;

    cout << "Enter staff address: ";
    cin >> newUser.address;

    cout << "Enter employee number: ";
    cin >> newUser.phone;

    cout << "Enter email: ";
    cin >> newUser.email;

    staffUsers.push_back(newUser);

    cout << "\n- - - - - - New user added successfully - - - - - -\n";
}

void addNewItem() {
    Item newItem;

    cout << "Enter new item name: ";
    cin >> newItem.name;

    cout << "Enter category (Cakes/Desserts/Breads/Cookies/Beverages): ";
    cin >> newItem.category;

    cout << "Enter price: ";
    cin >> newItem.price;

    bakeryItems.push_back(newItem);

    cout << "\n- - - - - - New item added successfully - - - - - -\n";
}

void logout() {
    cout << "\n- - - - - - Logged out successfully! - - - - - -\n";
}

void adminMenu() {
    char option;

    do {
        cout << "\n- - - - - - Welcome to Admin Access in Amber Bakery - - - - - -\n";
        cout << "1) View current bakery items\n";
        cout << "2) Add new bakery item\n";
        cout << "3) Add new user\n";
        cout << "4) Logout\n";
        cout << "5) Return to main menu\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case '1':
                displayBakeryItems();
                break;
            case '2':
                addNewItem();
                break;
            case '3':
                addUser();
                break;
            case '4':
                logout();
                return;
            case '5':
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        cout << "Do you want to continue? (Y/N): ";
        cin >> option;
    } while (option == 'Y' || option == 'y');
}

void customerMenu() {
    char option;

    do {
        cout << "\n- - - - - Welcome to Amber Bakery Customer Access - - - - -\n";
        cout << "1) View Available Bakery Items\n";
        cout << "2) Enter Contact Number\n";
        cout << "3) Enter Address\n";
        cout << "4) Log out\n";
        cout << "5) Return to main menu\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case '1':
                displayBakeryItems();
                break;
            case '2': {
                string contact;
                cout << "Enter the customer contact number: ";
                cin >> contact;
                break;
            }
            case '3': {
                string address;
                cout << "Enter the customer address: ";
                cin >> address;
                break;
            }
            case '4':
                logout();
                return;
            case '5':
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        cout << "Do you want to continue? (Y/N): ";
        cin >> option;
    } while (option == 'Y' || option == 'y');
}

bool validateLogin(const string &username, const string &password, const string &userType) {
    if (userType == "Admin") {
        return username == "Admin" && password == "Admin123";
    }

    if (userType == "Staff" || userType == "User") {
        return (username == "Staff" && password == "staff123") ||
               (username == "User" && password == "User123");
    }

    return false;
}

void login() {
    string userType, username, password;

    while (true) {
        displayCompanyDetail();
        cout << "Enter user type (Admin/Staff/User): ";
        cin >> userType;

        if (userType != "Admin" && userType != "Staff" && userType != "User") {
            cout << "Invalid user type. Please try again.\n";
            continue;
        }

        cout << "Enter user name: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (validateLogin(username, password, userType)) {
            cout << "\n- - - - - - Logged in successfully - - - - - -\n";
            if (userType == "Admin") {
                adminMenu();
            } else {
                customerMenu();
            }
            return;
        }

        cout << "Invalid username or password. Please try again.\n";
    }
}

void theMain() {
    int choice;
    do {
        displayCompanyDetail();
        cout << "1) Login\n2) About Us\n3) Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                aboutCompanyDetails();
                break;
            case 3:
                cout << "\n- - - - - - - THANK YOU - - - - - - -\n";
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (true);
}

int main() {
    theMain();
    return 0;
}
