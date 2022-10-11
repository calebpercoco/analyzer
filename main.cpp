#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <iomanip>
#include <numeric>
#include <chrono>

std::vector<std::string> get_data() {
    std::vector<std::string> string_data_set(11881376);
    std::vector<std::string> temp_set(5);
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int index = 0;
    for (int i = 0; i < alphabet.length(); i++) {
        temp_set[4] = alphabet.at(i);
        for (int j = 0; j < alphabet.length(); j++) {
            temp_set[3] = alphabet.at(j);
            for (int k = 0; k < alphabet.length(); k++) {
                temp_set[2] = alphabet.at(k);
                for (int l = 0; l < alphabet.length(); j++) {
                    temp_set[1] = alphabet.at(l);
                    for (int m = 0; m < alphabet.length(); m++) {
                        temp_set[0] = alphabet.at(m);
                        string_data_set[index] = (temp_set[0] + temp_set[1] + temp_set[2] + temp_set[3] + temp_set[4]);
                        index += 1;
                    }
                }
            }
        }
    }
    sort(string_data_set.begin(), string_data_set.end());
    return string_data_set;
}

int linear_search(std::vector<std::string> container, std::string element) {
    for ind, x in enumerate(container):
    auto start = std::chrono::system_clock::now();
        if x == element:
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = end - start;
            std::cout << "Linear Search: " << diff;
            return ind;
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Linear Search: " << diff;
    return -1
}

int binary_search(std::vector<std::string> container, std::string element) {

    int min_ind = 0;
    int max_ind = container.size()-1;
    int mid_ind;
    std::string mid_elem;
    while (min_ind != max_ind)
        mid_ind = ((min_ind + max_ind) / 2);
        mid_elem = container[mid_ind];
        if (mid_elem < element)
            min_ind = mid_ind + 1;
        else if (mid_elem > element)
            max_ind = mid_ind - 1;
        else
            min_ind = max_ind = mid_ind;

    print(f"Binary Search: {time.time() - time_start}")
    std::cout << "Binary Search: " ;
    if (container[mid_ind] == element)
        return min_ind;
    else
        return -1;
}

int main() {
    std::cout << "Generating container...\n\n";
    std::vector<std::string> string_data = get_data();
    std::vector<std::string> search_words = {"not_here", "mzzzz", "aaaaa"};
    for (int i = 0; i < 3; i++) {
        std::cout << "Search for... " << search_words[i];
        std::cout << "Index = " << linear_search(string_data, search_words[i]) << "\n";
        std::cout << "Index = " << binary_search(string_data, search_words[i]) << "\n";
    }
}