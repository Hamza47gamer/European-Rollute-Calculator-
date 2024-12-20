
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>

// Function to simulate PRNG (Linear Congruential Generator)
int predictLCG(int prev) {
    const int a = 1664525;
    const int c = 1013904223;
    const int m = 4294967296;
    return (a * prev + c) % m;
}

// Function to predict outcomes based on a simulated algorithm
std::string predictOutcome(const std::vector<int>& history) {
    if (history.empty()) return "Insufficient data";
    int predicted_number = predictLCG(history.back());
    std::string color = (predicted_number % 2 == 0) ? "Red" : "Black";
    std::string odd_even = (predicted_number % 2 == 0) ? "Even" : "Odd";
    std::string dozen = (predicted_number <= 12) ? "1st Dozen" : 
                        (predicted_number <= 24) ? "2nd Dozen" : "3rd Dozen";
    std::string column = (predicted_number % 3 == 1) ? "1st Column" : 
                         (predicted_number % 3 == 2) ? "2nd Column" : "3rd Column";

    std::string result = "Prediction:
";
    result += "Number: " + std::to_string(predicted_number) + "
";
    result += "Color: " + color + "
";
    result += "Odd/Even: " + odd_even + "
";
    result += "Dozen: " + dozen + "
";
    result += "Column: " + column + "
";

    return result;
}

int main() {
    std::vector<int> history;
    std::cout << "Enter the last 10 numbers: ";
    for (int i = 0; i < 10; i++) {
        int num;
        std::cin >> num;
        history.push_back(num);
    }

    std::string prediction = predictOutcome(history);
    std::cout << prediction;

    // Save prediction to file
    std::ofstream outfile("prediction.txt");
    outfile << prediction;
    outfile.close();

    return 0;
}
