// CS105 Assessment 2 Question 1
// Student Name: Matt Taylor
// This program will allow up to 5 people to track their steps as per the brief

#include <iostream>
#include <string>
#include <vector>

// Base class
class healthActivity {
private:
    std::string name;
    int steps;
    double walking;
    double running;
    double combinedDistance;

public:
    // Default constructor
    healthActivity() : steps(0), walking(0.0), running(0.0), combinedDistance(0.0) {}

    healthActivity(int s, double w, double r, const std::string& n)
        : steps(s), walking(w), running(r), name(n) {
        combinedDistance = w + r;
    }

    // Getter methods
    std::string getName() const {
        return name;
    }

    int getSteps() const {
        return steps;
    }

    double getWalking() const {
        return walking;
    }

    double getRunning() const {
        return running;
    }

    double getCombinedDistance() const {
        return combinedDistance;
    }

    // Setter methods
    void setName(const std::string& n) {
        name = n;
    }

    void setSteps(int s) {
        steps = s;
    }

    void setWalking(double w) {
        walking = w;
    }

    void setRunning(double r) {
        running = r;
    }
};

// Function to calculate and display the average combined distance
double calculateAverageCombinedDistance(const std::vector<healthActivity>& people) {
    double totalCombinedDistance = 0.0;

    for (const healthActivity& person : people) {
        totalCombinedDistance += person.getCombinedDistance();
    }

    if (people.size() > 0) {
        return totalCombinedDistance / people.size();
    }

    return 0.0; // Use this to avoid division by zero
}

int main() {
    std::vector<healthActivity> people; // Vector of healthActivity objects 
    const int maxPeople = 5;

    for (int i = 0; i < maxPeople; ++i) {
        std::cout << "Person " << (i + 1) << ":\n";

        std::string name;
        std::cout << "Enter your name: ";
        std::cin >> name;

        int steps;
        std::cout << "Enter the number of steps: ";
        std::cin >> steps;

        double walking;
        std::cout << "Enter walking distance: ";
        std::cin >> walking;

        double running;
        std::cout << "Enter running distance: ";
        std::cin >> running;

        // Created a healthActivity object and added it to the vector
        people.push_back(healthActivity(steps, walking, running, name));
    }

    // This prints all the details of all people along with their steps + walking and running distances
    for (const healthActivity& person : people) {
        std::cout << "Name: " << person.getName() << std::endl;
        std::cout << "Steps: " << person.getSteps() << std::endl;
        std::cout << "Walking distance (km): " << person.getWalking() << std::endl;
        std::cout << "Running distance (km): " << person.getRunning() << std::endl;
        std::cout << "Combined distance (km): " << person.getCombinedDistance() << std::endl;
        std::cout << "-------------------------\n";
    }

    double averageCombinedDistance = calculateAverageCombinedDistance(people);
    std::cout << "Average Combined Distance (km): " << averageCombinedDistance << std::endl;

    return 0;
}

    



