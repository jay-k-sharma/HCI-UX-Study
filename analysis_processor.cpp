#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

struct DataPoint {
    double value;
};

std::vector<DataPoint> readCSV(const std::string &filename) {
    std::vector<DataPoint> data;
    std::ifstream file(filename);
    std::string line, value;
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        while (std::getline(ss, value, ',')) {
            DataPoint point;
            point.value = std::stod(value);
            data.push_back(point);
        }
    }

    return data;
}

double calculateMean(const std::vector<DataPoint> &data) {
    double sum = 0.0;
    for (const auto &point : data) {
        sum += point.value;
    }
    return sum / data.size();
}

double calculateStandardDeviation(const std::vector<DataPoint> &data, double mean) {
    double sum = 0.0;
    for (const auto &point : data) {
        sum += std::pow(point.value - mean, 2);
    }
    return std::sqrt(sum / data.size());
}

int main() {
    std::string filename = "data.csv";
    std::vector<DataPoint> data = readCSV(filename);

    if (data.empty()) {
        std::cerr << "Error: No data found in the file." << std::endl;
        return 1;
    }

    double mean = calculateMean(data);
    double stdDev = calculateStandardDeviation(data, mean);

    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Standard Deviation: " << stdDev << std::endl;

    return 0;
}
