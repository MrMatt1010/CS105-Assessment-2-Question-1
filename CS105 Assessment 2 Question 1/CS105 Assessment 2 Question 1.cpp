// CS105 Assessment 2 Question 1
// Student Name: Matt Taylor
// This program will allow up to 5 people to track their steps and get the average of all steps as per the brief

#include <iostream>
#include <string>
#include <vector>

class healthActivity {
private:
    std::string name;
    int steps;
    double distance; // Combined walking and running distance

public:
    healthActivity() : steps(0), distance(0.0) {}

    healthActivity(const std::string& n, int s, double d)
        : name(n), steps(s), distance(d) {}

    std::string getName() const {
        return name;
    }

    int getSteps() const {
        return steps;
    }

    double getDistance() const {
        return distance;
    }

    void setName(const std::string& n) {
        name = n;
    }

    void setSteps(int s) {
        steps = s;
    }

    void setDistance(double d) {
        distance = d;
    }
};

double calculateAverageSteps(const std::vector<healthActivity>& people) {
    int totalSteps = 0;

    for (const healthActivity& person : people) {
        totalSteps += person.getSteps();
    }

    if (people.size() > 0) {
        return static_cast<double>(totalSteps) / people.size();
    }

    return 0.0; // Avoid division by zero
}

double calculateAverageDistance(const std::vector<healthActivity>& people) {
    double totalDistance = 0.0;

    for (const healthActivity& person : people) {
        totalDistance += person.getDistance();
    }

    if (people.size() > 0) {
        return totalDistance / people.size();
    }

    return 0.0; // Avoid division by zero
}

int main() {
    std::vector<healthActivity> people;
    const int maxPeople = 5;

    for (int i = 0; i < maxPeople; ++i) {
        std::cout << "Person " << (i + 1) << ":\n";

        std::string name;
        std::cout << "Enter your name: ";
        std::cin >> name;

        int steps;
        std::cout << "Enter the number of steps: ";
        std::cin >> steps;

        double distance;
        std::cout << "Enter combined walking and running distance (km): ";
        std::cin >> distance;

        people.push_back(healthActivity(name, steps, distance));
    }

    for (const healthActivity& person : people) {
        std::cout << "Name: " << person.getName() << std::endl;
        std::cout << "Steps: " << person.getSteps() << std::endl;
        std::cout << "Combined distance (km): " << person.getDistance() << std::endl;
        std::cout << "-------------------------\n";
    }

    double averageSteps = calculateAverageSteps(people);
    std::cout << "Average Steps: " << averageSteps << std::endl;

    double averageDistance = calculateAverageDistance(people);
    std::cout << "Average Combined Distance (km): " << averageDistance << std::endl;

    return 0;
}


    



