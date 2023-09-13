#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::string FindIntersection(std::string strArr[], int arrLength) {
    std::stringstream string1(strArr[0]);
    std::stringstream string2(strArr[1]);
    std::string segment;
    std::vector<std::string> seglist;
    std::vector<std::string> seglist_2;

    // Parse input to vectors
    while (std::getline(string1, segment, ',')) {
        int number = std::stoi(segment);
        seglist.push_back(std::to_string(number));
    }
    while (std::getline(string2, segment, ',')) {
        int number = std::stoi(segment);
        seglist_2.push_back(std::to_string(number));
    }

    std::vector<std::string> results_vec;
    for (auto &elem : seglist) {
        for (auto &elem2 : seglist_2) {
            if (elem == elem2) {
                results_vec.push_back(elem);
            }
        }
    }

    // Parse result vector to output
    std::stringstream output;
    if (results_vec.empty()) {
        return "false";
    }
    else {
        for (auto it = results_vec.begin(); it != results_vec.end(); it++) {
            if (it != results_vec.begin()) {
                output << ",";
            }
            output << *it;
        }
    }
    return output.str();
}

int main() {
    std::string str_array[] =  {"1, 3, 4, 7, 13", "1, 2, 4, 13, 15"};
    int arrLenght = sizeof(str_array) / sizeof(*str_array);

    std::cout << FindIntersection(str_array, arrLenght) << std::endl;

    return 0;
}
