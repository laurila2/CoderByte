/*
 *  Closest Enemy -tehtävä
 *  Santeri Laurila
 *  v0.1
 *  viimeisin muokkaus, 25.8.2023
*/

#include <climits>
#include <iostream>
#include <vector>

int ClosestEnemy(int arr[], int arrLength) {
    // Find the index of 1
    int index_of_1 = -1;
    for (int i = 0; i < arrLength; ++i) {
        if (arr[i] == 1) {
            index_of_1 = i;
            break;
        }
    }

    // If no 1 is found
    if (index_of_1 == -1) {
        return 0;
    }

    // Initialize variables to store the position of the nearest enemies
    int left_enemy = INT_MAX;  // Initialize to a large value
    int right_enemy = INT_MAX; // Initialize to a large value

    // Iterate through the array to find the nearest enemies
    for (int i = index_of_1; i < arrLength; ++i) {
            if (arr[i] == 2) {
                right_enemy = i - index_of_1;
                break;
            }
    }
    for (int i = index_of_1; i >= 0; --i) {
        if (arr[i] == 2) {
            left_enemy = index_of_1 - i;
            break;
        }
    }

    // Determine the closest enemy and return the result
    if (left_enemy == INT_MAX && right_enemy == INT_MAX) {
        return 0;
    }
    else {
        return std::min(left_enemy, right_enemy);
    }
}

int main(void) {
  int A[] = {1, 0, 0, 0, 2, 2, 2};
  int B[] = {2, 0, 0, 0, 2, 2, 1, 0};

  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << "Closest Enemy is at: " << ClosestEnemy(A, arrLength) << std::endl;
  std::cout << "Closest Enemy is at: " << ClosestEnemy(B, arrLength) << std::endl;

  return 0;
}
