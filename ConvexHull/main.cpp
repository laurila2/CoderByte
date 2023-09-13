/*
 * Jarvis March algorithm
 * Santeri L.
 * last modified: 29.8.2023
*/


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

/*
 * To find orientation of ordered triplet (p, q, r).
 * The function returns following values
 * 0 --> p, q and r are colinear
 * 1 --> Clockwise
 * 2 --> Counterclockwise
*/
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;  // colinear

    return (val > 0)? 1: 2;  // clock or counterclock wise
}

// Prints convex hull of a set of n points
std::string convexHull(std::vector<Point> points, int n) {
    // There must be at least 3 points
    if (n < 3)
        return 0;

    // Initialize Result vector
    std::vector<Point> hull;

    // Find the leftmost point
    int leftmost_point = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[leftmost_point].x)
            leftmost_point = i;

    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again.  This loop runs O(h)
    // times where h is number of points in result or output.
    int p = leftmost_point, q;
    do
    {
        // Add current point to result
        hull.push_back(points[p]);

        // Search for a point 'q' such that orientation(p, x,
        // q) is counterclockwise for all points 'x'. The idea
        // is to keep track of last visited most counterclock-
        // wise point in q. If any point 'i' is more counterclock-
        // wise than q, then update q.
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {
           // If i is more counterclockwise than current q, then
           // update q
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }

        // Now q is the most counterclockwise with respect to p
        // Set p as q for next iteration, so that q is added to
        // result 'hull'
        p = q;

    }
    while (p != leftmost_point);  // While we don't come to first point

    // Print Result
    for (int i = 0; i < static_cast<int>(hull.size()); i++)
        std::cout << "(" << hull[i].x << ", "
              << hull[i].y << ")\n";

    std::string result = std::to_string(hull.size());

    return result;
}

int main()
{
    std::string inputArr[] = {"(2,2)", "(3,1)", "(2,6)", "(0,1)", "(2,3)", "(5,2)"};
    int size = sizeof(inputArr) / sizeof(inputArr[0]);

    std::vector<Point> points = stringsToPoints(inputArr, size);
    std::cout << convexHull(points, size) << std::endl;
    return 0;
}
