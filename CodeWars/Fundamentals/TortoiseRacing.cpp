#include <iostream>
#include <vector>
#include <cmath>

class Tortoise {
public:
    static std::vector<int> race (int v1, int v2, int g);
};

std::vector<int> Tortoise::race (int v1, int v2, int g) {
    if (v1 >= v2)
        return { -1, -1, -1 };

    // lead * secondsInAnHour / velocity difference
    int seconds = (g * 3600) / (v2 -v1);
    int minutes = seconds / 60;
    int hours = minutes / 60;

    return {hours, minutes % 60, seconds % 60};
}

int main () {
    for (auto& x : Tortoise::race (720, 850, 70))
        std::cout << x << " ";
    std::cout << std::endl;

    for (auto& x : Tortoise::race (80, 91, 37))
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
