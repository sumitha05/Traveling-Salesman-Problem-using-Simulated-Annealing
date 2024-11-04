#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <utility>
#include <numeric>
#include <fstream>
#include <sstream>

using namespace std;

struct City {
    int id;
    double x, y;
};

double euclideanDistance(const City &a, const City &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double calculateTourCost(const vector<City> &cities, const vector<int> &tour) {
    double cost = 0;
    for (size_t i = 0; i < tour.size() - 1; i++) {
        cost += euclideanDistance(cities[tour[i]], cities[tour[i + 1]]);
    }
    cost += euclideanDistance(cities[tour.back()], cities[tour[0]]);
    return cost;
}

vector<int> getNeighborTour(const vector<int> &tour) {
    vector<int> newTour = tour;
    int i = rand() % tour.size();
    int j = (i + 1 + rand() % (tour.size() - 1)) % tour.size();
    swap(newTour[i], newTour[j]);
    return newTour;
}

double acceptanceProbability(double oldCost, double newCost, double temperature) {
    if (newCost < oldCost) return 1.0;
    return exp((oldCost - newCost) / temperature);
}

vector<int> simulatedAnnealing(const vector<City> &cities, int iterations, double startTemp, double endTemp) {
    int n = cities.size();
    vector<int> currentTour(n), bestTour;
    iota(currentTour.begin(), currentTour.end(), 0);
    bestTour = currentTour;

    double currentCost = calculateTourCost(cities, currentTour);
    double bestCost = currentCost;
    double temperature = startTemp;
    double coolingRate = pow(endTemp / startTemp, 1.0 / iterations);

    for (int i = 0; i < iterations; i++) {
        vector<int> neighborTour = getNeighborTour(currentTour);
        double neighborCost = calculateTourCost(cities, neighborTour);

        if (acceptanceProbability(currentCost, neighborCost, temperature) > ((double) rand() / RAND_MAX)) {
            currentTour = neighborTour;
            currentCost = neighborCost;
        }

        if (currentCost < bestCost) {
            bestTour = currentTour;
            bestCost = currentCost;
        }

        temperature *= coolingRate;
    }
    cout << "Optimal TSP tour cost: " << bestCost << endl;
    return bestTour;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <dataset_file>" << endl;
        return 1;
    }

    srand(time(0));

    ifstream file(argv[1]);
    if (!file.is_open()) {
        cerr << "Could not open the file: " << argv[1] << endl;
        return 1;
    }

    vector<City> cities;
    string line;

    // Skip header lines until "NODE_COORD_SECTION"
    while (getline(file, line)) {
        if (line == "NODE_COORD_SECTION") {
            break;
        }
    }

    // Read city coordinates until "EOF"
    while (getline(file, line)) {
        if (line == "EOF") break;

        istringstream iss(line);
        int id;
        double x, y;

        if (!(iss >> id >> x >> y)) {
            cerr << "Error reading line: " << line << endl;
            cerr << "Ensure each line has an ID followed by x and y coordinates." << endl;
            return 1;
        }

        cities.push_back({id, x, y});
    }
    file.close();

    int iterations = 10000;
    double startTemp = 1000.0;
    double endTemp = 0.01;

    // Simulated annealing algorithm
    vector<int> optimalTour = simulatedAnnealing(cities, iterations, startTemp, endTemp);

    cout << "Optimal TSP tour sequence: ";
    for (int city : optimalTour) {
        cout << city + 1 << " ";  // Adding 1 to match the city IDs from the file
    }
    cout << endl;

    return 0;
}
