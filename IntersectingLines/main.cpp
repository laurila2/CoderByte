#include <iostream>
#include <vector>
#include <sstream>
#include <string>

std::vector<std::pair<double, double>> parseToVec(std::string inputArray[], int arraySize) {
    std::vector<std::pair<double, double>> result;

    for (int i = 0; i < arraySize; i++) {
        std::string currentString = inputArray[i];

        // Check if the string starts with "(" and ends with ")"
        if (currentString.front() == '(' && currentString.back() == ')') {
            // Remove the parentheses
            currentString = currentString.substr(1, currentString.length() - 2);

            std::istringstream iss(currentString);
            double x, y;
            char comma;

            // Attempt to extract the two doubles separated by a comma
            if (iss >> x >> comma && comma == ',' && iss >> y) {
                result.push_back(std::make_pair(x, y));
            } else {
                // Parsing failed, handle the error or skip the invalid input
                std::cerr << "Failed to parse line " << i + 1 << ": " << inputArray[i] << std::endl;
            }
        }
        else {
            // Invalid format, handle the error or skip the invalid input
            std::cerr << "Invalid format in line " << i + 1 << ": " << inputArray[i] << std::endl;
        }
    }

    return result;
}

// Function to find the intersection point between two lines represented by pairs of points
std::string IntersectingLines(std::vector<std::pair<double, double>>& pairs) {

    double x1 = pairs.at(0).first;
    double y1 = pairs.at(0).second;
    double x2 = pairs.at(1).first;
    double y2 = pairs.at(1).second;
    double x3 = pairs.at(2).first;
    double y3 = pairs.at(2).second;
    double x4 = pairs.at(3).first;
    double y4 = pairs.at(3).second;

    // Calculate the slopes of the lines
    double m1 = (y2 - y1) / (x2 - x1);
    double m2 = (y4 - y3) / (x4 - x3);

    // Check if the lines are parallel
    if (m1 == m2) {
        return "no intersection.";
    }

    // Calculate the intersection point
    double x = (m1 * x1 - y1 - m2 * x3 + y3) / (m1 - m2);
    double y = m1 * (x - x1) + y1;

    // Parse result
    std::stringstream result;
    result << "(" << x  << "," << y << ")";

    return result.str();
}

int main() {

    std::string inputArray[] = {
        "(9,-2)",
        "(-2,9)",
        "(3,4)",
        "(10,11)"
    };
    std::vector<std::pair<double, double>> pairs = parseToVec(inputArray, 4);

    std::string result = IntersectingLines(pairs);
    std::cout << "Intersection point: " << result << std::endl;

    return 0;
}
