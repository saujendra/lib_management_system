#include<iostream>
#include<fstream>
using namespace std;

class temp {
public:
    string  id, name, author, search;
    fstream file;
    void addbook();
    void showall();
    void extractbook();
};

void temp::addbook() {
    cout << "\nEnter book id: ";
    cin.ignore(); 
    getline(cin, id);

    file.open("bookdata.txt", ios::in);
    string line;
    bool exists = false;
    while (getline(file, line)) {
        if (line.find(id) != string::npos) {
            exists = true;
            break;
        }
    }
    file.close();

    if (exists) {
        cout << "Book ID already exists! Unable to add.\n";
        return;
    }

    cout << "Enter book name: ";
    getline(cin, name);

    cout << "Enter book author name: ";
    getline(cin, author);

    file.open("bookdata.txt", ios::out | ios::app);
    file << id << "*" << name << "*" << author << endl;
    file.close();
}




void temp::showall() {
    file.open("bookdata.txt", ios::in);
    if (!file.is_open()) {
        cout << "File not found or unable to open!" << endl;
        return;
    }

    cout << "\n\n";
    cout << "\t\t\t Book id \t\t\t Book name\t\t\t authors name" << endl;

    string id, name, author;
    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author, '\n')) {
        cout << "\t\t\t  " << id << "\t\t\t\t  " << name << "\t\t\t\t   " << author << endl;
    }

    file.close();
}


void temp::extractbook() {
    showall();
    cout << "Enter book id: ";
    getline(cin, search);

    file.open("bookdata.txt", ios::in);
    if (!file.is_open()) {
        cout << "File not found or unable to open!" << endl;
        return;
    }
  
    cout << "\n\n";
    cout << "\t\t\t Book id \t\t\t Book name\t\t\t authors name" << endl;

    while (!file.eof()) {
        getline(file, id, '*');
        getline(file, name, '*');
        getline(file, author, '\n');

        if (search == id) {
            cout << "\t\t\t  " << id << "\t\t\t\t  " << name << "\t\t\t\t  "<< author << endl;
            cout << "Book Extracted Successfully" << endl;
            break;
        }
    }

    file.close();
}

int main() {
    temp obj;
    char choice;

    do {
        cout << "-------------------\n\n";
        cout << "1-show all Books\n\n";
        cout << "2-Extract Book\n\n";
        cout << "3-Add books(ADMIN)\n\n ";
        cout << "4-Exit\n\n";
        cout << "........................." << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cin.ignore();
                obj.showall();
                break;
            case '2':
                cin.ignore();
                obj.extractbook();
                break;
            case '3':
                cin.ignore();
                obj.addbook();
                break;
            case '4':
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != '4');

    return 0;
}
