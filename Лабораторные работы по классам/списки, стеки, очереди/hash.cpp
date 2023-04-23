#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Запись данных
struct Record
{
    string name;
    string birthday;
    string address;
};

// Хеш-таблица
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

// Функция для сохранения массива в файл
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

// Функция для загрузки массива из файла
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
    // Создание массива записей
    const int arraySize = 100;
    Record *array = new Record[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        array[i].name = "Name" + std::to_string(rand() % 1000);
        int day = rand() % 30 + 1; // Generate a day between 1 and 30
        int month = rand() % 12 + 1; // Generate a month between 1 and 12
        int year = rand() % 100; // Generate a year between 0 and 99
        array[i].birthday = to_string(day * 10000 + month * 100 + year);
        array[i].address = "Address" + std::to_string(rand() % 1000);
    }
    // Сохранение массива в файл
    saveToFile(array, arraySize, "records.txt");

    // Загрузка массива из файла
    int loadedSize;
    Record *loadedArray = loadFromFile(loadedSize, "records.txt");

    // Вывод загруженного массива
    cout << "Loaded array:" << endl;
    for (int i = 0; i < loadedSize; i++)
    {
        cout << loadedArray[i].name << ", " << loadedArray[i].birthday << ", " << loadedArray[i].address << endl;
    }

    // Создание хеш-таблицы
    HashTable table(arraySize);
    for (int i = 0; i < loadedSize; i++)
    {
        table.insert(loadedArray[i]);
    }

    // Поиск элемента в хеш-таблице
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

    // Удаление элемента из хеш-таблицы
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

    // Добавление элемента в хеш-таблицу
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
    // Подсчет количества коллизий
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

    // Освобождение памяти
    delete[] array;
    delete[] loadedArray;
    system("pause");
    return 0;
}