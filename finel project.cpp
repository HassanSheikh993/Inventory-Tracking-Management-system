#include <iostream>
using namespace std;


class Unsold_product {
public:
    struct product {
        string name;
        string supplier;
        int quantity;
        int sold_quantity;
        float price;
        product* next;
    };
    product* unsold = NULL;
    product* sold = NULL;  // Added sold list

    // Function to add inventory details (unsold inventory)
    void add_inventory() {
        product* newProduct = new product;
        cout << "Enter the product name: ";
        cin >> newProduct->name;
        cout << "Enter the supplier name: ";
        cin >> newProduct->supplier;
        cout << "Enter the quantity: ";
        cin >> newProduct->quantity;
        cout << "Enter the price: ";
        cin >> newProduct->price;
        newProduct->next = NULL;

        if (unsold == NULL) {
            unsold = newProduct;
        }
        else {
            product* temp = unsold;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newProduct;
        }
        cout << "Data saved successfully." << endl;
    }

    // Search for an unsold product
    void search_inventory(string name) {
        product* temp = unsold;
        while (temp != NULL) {
            if (temp->name == name) {
                cout << "Unsold product found!" << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Supplier: " << temp->supplier << endl;
                cout << "Quantity: " << temp->quantity << endl;
                cout << "Price: " << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Product not found." << endl;
    }

    // Display unsold inventory
    void displayInventory() {
        product* temp = unsold;
        if (unsold == NULL) {
            cout << "Unsold items inventory is empty." << endl;
        }
        else {
            cout << "Unsold items inventory:" << endl;
            while (temp != NULL) {
                cout << "Name: " << temp->name << endl;
                cout << "Supplier: " << temp->supplier << endl;
                cout << "Quantity: " << temp->quantity << endl;
                cout << "Price: " << temp->price << endl;
                cout << "------------------------" << endl;
                temp = temp->next;
            }
        }
    }

    // Delete an unsold product
    void delete_unsold_product(string name) {
        if (unsold == NULL) {
            cout << "Unsold items inventory is empty." << endl;
            return;
        }
        else if (unsold->name == name) {
            product* temp = unsold;
            unsold = unsold->next;
            delete temp;
            cout << "Unsold product deleted successfully." << endl;
            return;
        }
        else {
            product* current = unsold;
            product* previous = NULL;
            while (current != NULL) {
                if (current->name == name) {
                    previous->next = current->next;
                    delete current;
                    cout << "Unsold product deleted successfully." << endl;
                    return;
                }
                previous = current;
                current = current->next;
            }
        }
        cout << "Product not found." << endl;
    }

   // Function to mark a product as sold and update the inventory
    void markProductAsSold(string name, int soldQuantity) {
        product* current = unsold;
        while (current != NULL) {
            if (current->name == name) {
                if (current->quantity >= soldQuantity) {
                    current->quantity -= soldQuantity;
                    current->sold_quantity += soldQuantity;
                    if (current->quantity == 0) {
                        delete_unsold_product(name);
                    }
                    // Create a new node in the sold list
                    product* soldProduct = new product;
                    soldProduct->name = current->name;
                    soldProduct->supplier = current->supplier;
                    soldProduct->quantity = soldQuantity;
                    soldProduct->sold_quantity = soldQuantity;
                    soldProduct->price = current->price;
                    soldProduct->next = NULL;
                    if (sold == NULL) {
                        sold = soldProduct;
                    } else {
                        product* temp = sold;
                        while (temp->next != NULL) {
                            temp = temp->next;
                        }
                        temp->next = soldProduct;
                    }
                    cout << "Product marked as sold successfully!" << endl;
                    return;
                } else {
                    cout << "Insufficient quantity to mark as sold." << endl;
                    return;
                }
            }
            current = current->next;
        }
        cout << "Unsold product not found." << endl;
    }
     void searchSoldProduct(string name) {
        product* current = sold;
        while (current != NULL) {
            if (current->name == name) {
                cout << "Sold product found!" << endl;
                cout << "Name: " << current->name << endl;
                cout << "Quantity: " << current->quantity << endl;
                cout << "Sold Quantity: " << current->sold_quantity << endl;
                cout << "Price: " << current->price << endl;
                cout << "Supplier: " << current->supplier << endl;
                return;
            }
            current = current->next;
        }
        cout << "Sold product not found." << endl;
    }

    void displaySoldInventory() {
        if (sold == NULL) {
            cout << "Sold items inventory is empty." << endl;
            return;
        }
        cout << "Sold items inventory:" << endl;
        product* current = sold;
        while (current != NULL) {
            cout << "Name: " << current->name << endl;
            cout << "Quantity: " << current->quantity << endl;
            cout << "Sold Quantity: " << current->sold_quantity << endl;
            cout << "Price: " << current->price << endl;
            cout << "Supplier: " << current->supplier << endl;
            cout << "------------------------" << endl;
            current = current->next;
        }
    }

    // Function to place an order for a sold product
    void order(string name, int soldQuantity) {
        cout << "Placing an order for " << name << " with quantity " << soldQuantity << endl;
        // Add code to place the order
    }
};

class Registration {
public:
    void login_admin(Unsold_product& obj) {
        int password;
        char enter;

        do {
            cout << "Enter the password: ";
            cin >> password;

            if (password == 1234) {
                do {
                	system("cls");
                        cout << "+---------------------------------+" << endl;
    cout << "|         Menu Options            |" << endl;
    cout << "+---------------------------------+" << endl;
    cout << "| 1. Add unsold product           |" << endl;
    cout << "| 2. Search unsold product        |" << endl;
    cout << "| 3. Display unsold inventory     |" << endl;
    cout << "| 4. Delete unsold product        |" << endl;
    cout << "| 5. Registration page            |" << endl;
    cout << "| 6. Mark product as sold         |" << endl;
    cout << "| 7. Search sold product          |" << endl;
    cout << "| 8. Display sold inventory       |" << endl;
    cout << "| 9. Exit                         |" << endl;
    cout << "+---------------------------------+" << endl;
                    cin >> enter;

                    switch (enter) {
                        case '1':
                        	system("cls");
                            obj.add_inventory();
                            system("pause");
                            break;
                        case '2': {
                        	system("cls");
                            string name;
                            cout << "Enter the name of the product: ";
                            cin >> name;
                            obj.search_inventory(name);
                            system("pause");
                            break;
                        }
                        case '3':
                        	system("cls");
                            obj.displayInventory();
                            system("pause");
                            break;
                        case '4': {
                        	system("cls");
                            string name;
                            cout << "Enter the name of the product to delete: ";
                            cin >> name;
                            obj.delete_unsold_product(name);
                            system("pause");
                            break;
                        }
                        case '5':
                        	system("cls");
                            return;  // Return to the registration page
                        case '6': {
                        	system("cls");
                            string name;
                            int quantity;
                            cout << "Enter unsold product name to mark as sold: ";
                            cin >> name;
                            cout << "Enter quantity sold: ";
                            cin >> quantity;
                            obj.markProductAsSold(name, quantity);
                            system("pause");
                            break;
                        }
                     
                        case '7': {
                        	system("cls");
                            string name;
                            cout << "Enter sold product name to search: ";
                            cin >> name;
                            obj.searchSoldProduct(name);
                            system("pause");
                            break;
                        }
                        case '8':
                        	system("cls");
                            obj.displaySoldInventory();
                            system("pause");
                            break;
                        case '9':
                        	system("cls");
                            cout << "Exiting program." << endl;
                            system("pause");
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                    }

                    cout << endl;
                } while (enter != '9');
            }
            else {
                cout << "Invalid password. Please try again." << endl;
            }
        } while (password != 1234);
    }

    void login_employee(Unsold_product& obj) {
        int password;
        char enter;
do{
        cout << "Enter the password: ";
        cin >> password;

        if (password == 1122) {
            do {
            	system("cls");
                    cout << "+---------------------------------+" << endl;
    cout << "|         Menu Options            |" << endl;
    cout << "+---------------------------------+" << endl;
    cout << "| 1. Search unsold product        |" << endl;
    cout << "| 2. Display unsold inventory     |" << endl;
    cout << "| 3. Mark product as sold         |" << endl;
    cout << "| 4. Registration page            |" << endl;
    cout << "+---------------------------------+" << endl;


                cin >> enter;

                switch (enter) {
                    case '1': {
                    		system("cls");
                        string name;
                        cout << "Enter the name of the product: ";
                        cin >> name;
                        obj.search_inventory(name);
                        system("pause");
                        break;
                    }
                    case '2':
                    		system("cls");
                        obj.displayInventory();
                        system("pause");
                        break;
                    case '3': {
                    		system("cls");
                        string name;
                        int quantity;
                        cout << "Enter unsold product name to mark as sold: ";
                        cin >> name;
                        cout << "Enter quantity sold: ";
                        cin >> quantity;
                        obj.markProductAsSold(name, quantity);
                        system("pause");
                        break;
                    }
                    case '4':
                    		system("cls");
                        return;  // Return to the registration page
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                }
            } while (enter != '4');
        }
        else {
            cout << "Invalid password. Please try again." << endl;
        }
    }while(password != 1122);
    }

    void registration_page(Unsold_product& obj) {
        int choice;
         do {
         	system("cls");
   /* cout << "          -----------------------------------------------------" << endl;
    cout << "          |      Inventory Tracking and Control System        |" << endl;
    cout << "          -----------------------------------------------------" << endl;  */
    
    cout << "  _____                      _                     __           _               \n";
cout << "  \\_   \\_ ____   _____ _ __ | |_ ___  _ __ _   _  / _\\_   _ ___| |_ ___ _ __ ___   \n";
cout << "    / /\\/ '_ \\ \\ / / _ \\ '_ \\| __/ _ \\| '__| | | | \\ \\| | | / __| __/ _ \\ '_ ` _ \\  \n";
cout << " /\\/ /_ | | | \\ V /  __/ | | | || (_) | |  | |_| | _\\ \\ |_| \\__ \\ ||  __/ | | | | | \n";
cout << " \\____/ |_| |_|\\_/ \\___|_| |_|\\__\\___/|_|   \\__, | \\__/\\__, |___/\\__\\___|_| |_| |_| \n";
cout << "                                            |___/      |___/                        \n";

                                                        
    cout<<endl<<endl;
    cout << "    +-------------------------+" << endl;
    cout << "    |       User Options      |" << endl;
    cout << "    +-------------------------+" << endl;
    cout << "    | 1. Admin                |" << endl;
    cout << "    | 2. Employee             |" << endl;
    cout << "    | 3. Exit                 |" << endl;
    cout << "    +-------------------------+" << endl;

cout<<endl<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                login_admin(obj);
                break;
            case 2:
                login_employee(obj);
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }while (true);
    } 
};

int main() {
	
	
	cout<<endl<<endl;
		system("color 3e");
    Unsold_product unsoldObj;

    Registration regObj;

    regObj.registration_page(unsoldObj);

    return 0;
}
