#include <iostream>
#include <ctime>
#include <iomanip>

int main() {

    std::time_t start = std::time(nullptr);
    std::tm timer = *std::localtime(&start);
    std::cout << "Enter the start of the timer report in the format MM:SS>";
    std::cin >> std::get_time(&timer, "%M:%S");

    int totalTime = timer.tm_min * 60 + timer.tm_sec;
    std::time_t currentTime = std::time(nullptr);
    int tmp = 0;

    while(totalTime >= 0){
        std::time_t left = std::time(nullptr);
        int diff = std::difftime(left,currentTime);

        if (diff > tmp) {
            std::cout << std::put_time(&timer, "%M:%S") << std::endl;
            if (timer.tm_sec - 1 < 0) {
                timer.tm_sec = 60;
                --timer.tm_min;
            }
            --timer.tm_sec;
            --totalTime;
        }
        tmp = diff;
    }
    std::cout << "DING! DING! DING!" << std::endl;
    return 0;
}
