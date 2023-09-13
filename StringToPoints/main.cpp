#include <iostream>
#include <vector>
#include <string>
#include <sstream>

struct Point {
    int x, y;
};

// Function to parse a string "(x,y)" into a Point struct
Point parsePoint(const std::string& str) {
    Point point;
    char dummy; // To capture the '(' and ','
    std::istringstream iss(str);
    iss >> dummy >> point.x >> dummy >> point.y >> dummy;
    return point;
}

// Function to convert an array of strings to a vector of Points
std::vector<Point> stringsToPoints(const std::string inputArr[], int size) {
    std::vector<Point> points;
    for (int i = 0; i < size; ++i) {
        points.push_back(parsePoint(inputArr[i]));
    }
    return points;
}

int main() {
    std::string inputArr[] = {"(2,2)", "(3,1)", "(2,6)", "(0,1)", "(2,3)", "(5,2)"};
    int size = sizeof(inputArr) / sizeof(inputArr[0]);

    std::vector<Point> points = stringsToPoints(inputArr, size);

    // Printing the parsed Points
    for (const Point& p : points) {
        std::cout << "(" << p.x << "," << p.y << ")" << std::endl;
    }

    return 0;
}
