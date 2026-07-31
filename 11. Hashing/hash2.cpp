#include <iostream>
#include <list>
using namespace std;

class HashTable
{
private:
    static const int SIZE = 10;
    list<pair<int, string>> table[SIZE];
    int totalElements = 0;

    int hashFunction(int key)
    {
        return key % SIZE;
    }

public:
    // insert
    void insert(int key, string value)
    {
        int index = hashFunction(key);

        for (auto &x : table[index])
        {
            if (x.first == key)
            {
                cout << "Key already Exist \n";
                return;
            }
        }

        table[index].push_back({key, value});
        totalElements++;

        cout << "Inserted Successfully \n";
    }

    // search
    void search(int key)
    {
        int index = hashFunction(key);

        for (auto &x : table[index])
        {
            if (x.first == key)
            {
                cout << "Found -> " << "Key = " << x.first << "Value = " << x.second << endl;
                return;
            }
        }

        cout << "Key Not Found" << endl;
    }

    // update
    void update(int key, string newValue)
    {
        int index = hashFunction(key);

        for (auto &x : table[index])
        {
            if (x.first == key)
            {
                x.second = newValue;
                cout << "Value Updated!!!";
                return;
            }
        }

        cout << "Key Not Found!!!";
    }

    // Delete
    void remove(int key)
    {
        int index = hashFunction(key);

        for (auto it = table[index].begin(); it != table[index].end(); it++)
        {
            if (it->first == key)
            {
                table[index].erase(it);
                totalElements--;

                cout << "Element Deleted!!!" << endl;
                return;
            }
        }
        cout << "Key Not Found!!! \n";
    }

    // Display
    void display()
    {
        cout << "\n Hash Table \n";

        for (int i = 0; i < SIZE; i++)
        {
            cout << i << " -> ";

            for (auto x : table[i])
            {
                cout << "(" << x.first << "," << x.second << ")";
            }
            cout << endl;
        }
    }

    // size
    void size()
    {
        cout << "Total Element : " << totalElements << endl;
    }

    // Is Empty

    // Clear
};

int
main()
{

    HashTable ht;

    int choice;
    int key;
    string value;

    do
    {
        cout << "\n------- HASH TABLE -------- \n";
        cout << "1. Insert \n";
        cout << "2. Search \n";
        cout << "3. Update \n";
        cout << "4. Delete \n";
        cout << "5. Display \n";
        cout << "6. Size \n";
        cout << "7. Is Empty \n";
        cout << "8. Clear \n";
        cout << "9. Exit \n";

        cout << "Enter your Choice : \n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter your Key : " << endl;
            cin >> key;
            cout << "Enter your Value : " << endl;
            cin >> value;

            ht.insert(key, value);
            break;

        case 2:

            cout << "Enter your Key : " << endl;
            cin >> key;

            ht.search(key);
            break;

        case 3:

            cout << "Enter your Key : " << endl;
            cin >> key;

            cout << "Enter your New Value : " << endl;
            cin >> value;

            ht.update(key, value);
            break;

        case 4:
            cout << "Enter your Key : " << endl;
            cin >> key;

            ht.remove(key);
            break;

        case 5:
            ht.display();
            break;

        case 6:
            ht.size();
            break;

            // case 7,  8

        case 9:
            cout << "Program Ended \n";
            break;

        default:
            cout << "Invalid Choice \n";
            break;
        }
    }while(choice != 9);

    return 0;
}