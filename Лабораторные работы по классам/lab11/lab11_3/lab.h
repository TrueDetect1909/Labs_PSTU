#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Vector {
private:
    std::vector<T> data;
public:
    Vector() {}

    void fill(int n) {
        for (int i = 0; i < n; i++) {
            T value;
            std::cin >> value;
            data.push_back(value);
        }
    }

    void add(T key, int pos) {
        auto it = std::find(data.begin(), data.end(), key);
        if (it != data.end()) {
            data.insert(data.begin() + pos, key);
        }
    }

    void remove(T key) {
        auto it = std::find(data.begin(), data.end(), key);
        if (it != data.end()) {
            data.erase(it);
        }
    }

    void subtract() {
        T min = *std::min_element(data.begin(), data.end());
        T max = *std::max_element(data.begin(), data.end());
        T diff = max - min;
        for (auto& value : data) {
            value -= diff;
        }
    }

    void print() {
        for (auto& value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};