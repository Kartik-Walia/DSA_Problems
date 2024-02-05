#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, int> map1 = {{1, 10}, {2, 20}, {3, 30}};
    std::unordered_map<int, int> map2 = {{1, 10}, {2, 20}, {3, 30}};

    if (map1 == map2) {
        std::cout << "Maps are equal.\n";
    } else {
        std::cout << "Maps are not equal.\n";
    }

    return 0;
}
