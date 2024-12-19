#include <iostream>
#include <vector>
#include <optional>

class HashTable {
private:
    std::vector<std::optional<int>> table; // Используем std::optional для обозначения пустых ячеек
    int tableSize;
    int currentSize;

    int hashFunction(int key) {
        return key % tableSize; // Простая хэш-функция
    }

public:
    HashTable(int size) : tableSize(size), currentSize(0) {
        table.resize(tableSize, std::nullopt); // Инициализация таблицы с пустыми значениями
    }

    void insert(int key) {
        if (currentSize == tableSize) {
            std::cout << "Hash table is full!" << std::endl;
            return;
        }

        int index = hashFunction(key);
        while (table[index].has_value()) { // Линейное пробирование
            index = (index + 1) % tableSize;
        }
        
        table[index] = key; // Вставляем ключ
        currentSize++;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int count = 0;
        while (table[index].has_value()) {
            if (table[index].value() == key) {
                return true; // Ключ найден
            }
            index = (index + 1) % tableSize; // Продолжаем искать
            count++;
            if (count >= tableSize) {
                break; // Защитное условие, чтобы не зациклиться
            }
        }
        return false; // Ключ не найден
    }

    void remove(int key) {
        int index = hashFunction(key);
        int count = 0;
        while (table[index].has_value()) {
            if (table[index].value() == key) {
                table[index] = std::nullopt; // Удаляем ключ
                currentSize--;
                return;
            }
            index = (index + 1) % tableSize; // Продолжаем искать
            count++;
            if (count >= tableSize) {
                break; // Защитное условие
            }
        }
        std::cout << "Key not found!" << std::endl;
    }

    void display() {
        for (int i = 0; i < tableSize; i++) {
            if (table[i].has_value()) {
                std::cout << "Index " << i << ": " << table[i].value() << std::endl;
            } else {
                std::cout << "Index " << i << ": empty" << std::endl;
            }
        }
    }
};

int main() {
    HashTable hTable(10); // Создаем хэш-таблицу размером 10

    hTable.insert(10);
    hTable.insert(20);
    hTable.insert(30);
    hTable.insert(42);
    hTable.insert(52);
    
    std::cout << "Current hash table:" << std::endl;
    hTable.display();

    std::cout << "Searching for 20: " << (hTable.search(20) ? "Found" : "Not found") << std::endl;
    std::cout << "Searching for 99: " << (hTable.search(99) ? "Found" : "Not found") << std::endl;

    hTable.remove(20);
    std::cout << "After removing 20:" << std::endl;
    hTable.display();

    return 0;
}
