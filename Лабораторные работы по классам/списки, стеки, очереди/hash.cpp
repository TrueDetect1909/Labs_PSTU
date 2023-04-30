#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

  
struct Record
{
    string name;
    string birthday;
    string address;
};


class HashTable
{
private:
    vector<Record> *table;
    int tableSize;

public:
    HashTable(int size)
    {
        tableSize = size;
        table = new vector<Record>[tableSize];
    }
    ~HashTable()
    {
        delete[] table;
    }
    int hashFunction(string key)
    {
        int hashValue = 0;
        for (int i = 0; i < key.length(); i++)
        {
            hashValue += key[i];
        }
        return hashValue % tableSize;
    }
    void insert(Record record)
    {
        int index = hashFunction(record.birthday);
        table[index].push_back(record);
    }
    bool remove(string key)
    {
        int index = hashFunction(key);
        for (int i = 0; i < table[index].size(); i++)
        {
            if (table[index][i].birthday == key)
            {
                table[index].erase(table[index].begin() + i);
                return true;
            }
        }
        return false;
    }
    Record *search(string key)
    {
        int index = hashFunction(key);
        for (int i = 0; i < table[index].size(); i++)
        {
            if (table[index][i].birthday == key)
            {
                return &table[index][i];
            }
        }
        return nullptr;
    }
    int countCollisions()
    {
        int collisions = 0;
        for (int i = 0; i < tableSize; i++)
        {
            if (table[i].size() > 1)
            {
                collisions += table[i].size() - 1;
            }
        }
        return collisions;
    }
};

      
void saveToFile(Record *array, int size, string filename)
{
    ofstream outFile;
    outFile.open(filename);
    for (int i = 0; i < size; i++)
    {
        outFile << array[i].name << "," << array[i].birthday << "," << array[i].address << endl;
    }
    outFile.close();
}

      
Record *loadFromFile(int &size, string filename)
{
    ifstream inFile;
    inFile.open(filename);
    string line;
    size = 0;
    while (getline(inFile, line))
    {
        size++;
    }
    inFile.clear();
    inFile.seekg(0, ios::beg);
    Record *array = new Record[size];
    for (int i = 0; i < size; i++)
    {
        getline(inFile, line);
        int commaIndex1 = line.find(",");
        int commaIndex2 = line.find(",", commaIndex1 + 1);
        array[i].name = line.substr(0, commaIndex1);
        array[i].birthday = line.substr(commaIndex1 + 1, commaIndex2 - commaIndex1 - 1);
        array[i].address = line.substr(commaIndex2 + 1);
    }
    inFile.close();
    return array;
}

int main()
{
       
    const int arraySize = 100;
    Record *array = new Record[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        array[i].name = "Name" + std::to_string(rand() % 1000);
        int day = rand() % 30 + 1; 
        int month = rand() % 12 + 1;  
        int year = rand() % 100; 
        array[i].birthday = to_string(day * 10000 + month * 100 + year);
        array[i].address = "Address" + std::to_string(rand() % 1000);
    }
        
    saveToFile(array, arraySize, "records.txt");

        
    int loadedSize;
    Record *loadedArray = loadFromFile(loadedSize, "records.txt");

       
    cout << "Loaded array:" << endl;
    for (int i = 0; i < loadedSize; i++)
    {
        cout << loadedArray[i].name << ", " << loadedArray[i].birthday << ", " << loadedArray[i].address << endl;
    }

    HashTable table(arraySize);
    for (int i = 0; i < loadedSize; i++)
    {
        table.insert(loadedArray[i]);
    }

    string searchKey;
    cout << "Enter birthday to search: ";
    getline(cin, searchKey);
    Record *result = table.search(searchKey);
    if (result != nullptr)
    {
        cout << "Record found: " << result->name << ", " << result->birthday << ", " << result->address << endl;
    }
    else
    {
        cout << "Record not found." << endl;
    }
    string removeKey;
    cout << "Enter birthday to remove: ";
    getline(cin, removeKey);
    if (table.remove(removeKey))
    {
        cout << "Record removed." << endl;
    }
    else
    {
        cout << "Record not found." << endl;
    }
    Record newRecord;
    cout << "Enter data for new record:" << endl;
    cout << "Name: ";
    getline(cin, newRecord.name);
    cout << "Birthday: ";
    getline(cin, newRecord.birthday);
    cout << "Address: ";
    getline(cin, newRecord.address);
    table.insert(newRecord);
    saveToFile(array, arraySize, "records.txt");
       
    HashTable table1(40);
    HashTable table2(75);
    HashTable table3(90);
    for (int i = 0; i < loadedSize; i++)
    {
        table1.insert(loadedArray[i]);
        table2.insert(loadedArray[i]);
        table3.insert(loadedArray[i]);
    }
    int collisions1 = table1.countCollisions();
    int collisions2 = table2.countCollisions();
    int collisions3 = table3.countCollisions();
    cout << "Number of collisions for table size 40: " << collisions1 << endl;
    cout << "Number of collisions for table size 75: " << collisions2 << endl;
    cout << "Number of collisions for table size 90: " << collisions3 << endl;

      
    delete[] array;
    delete[] loadedArray;
    system("pause");
    return 0;
}