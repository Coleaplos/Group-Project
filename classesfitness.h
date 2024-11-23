#ifndef CLASSESFITNESS_H
#define CLASSESFITNESS_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <algorithm>

// Forward declarations
class Goal;
class WorkoutHistory;

class WorkoutEntry {
public:
    std::string workoutName;
    time_t timestamp;
    std::string workoutType;

    WorkoutEntry(const std::string& name, const std::string& type, time_t time = std::time(nullptr))
        : workoutName(name), workoutType(type), timestamp(time) {
    }
};

class WorkoutHistory {
private:
    std::vector<WorkoutEntry> workouts;

public:
    void addWorkout(const std::string& workoutName, const std::string& workoutType) {
        workouts.emplace_back(workoutName, workoutType);
    }

    void displayWorkoutHistory(bool isPremium, int limit) const {
        size_t count = 0;
        for (const auto& workout : workouts) {
            if (count >= limit && !isPremium) break;
            std::cout << "Workout: " << workout.workoutName
                << " | Type: " << workout.workoutType
                << " | Date: " << std::ctime(&workout.timestamp);
            ++count;
        }
    }

    void displayAllWorkouts() const {
        for (const auto& workout : workouts) {
            std::cout << "Workout: " << workout.workoutName
                << " | Type: " << workout.workoutType
                << " | Date: " << std::ctime(&workout.timestamp);
        }
    }

    void displayLastNWorkouts(size_t n) const { // Add declaration for this method
        size_t count = std::min(n, workouts.size());
        for (size_t i = workouts.size() - count; i < workouts.size(); ++i) {
            const auto& workout = workouts[i];
            std::cout << "Workout: " << workout.workoutName
                << " | Type: " << workout.workoutType
                << " | Date: " << std::ctime(&workout.timestamp);
        }
    }

    void saveWorkoutHistory(const std::string& filename) const {
        std::ofstream file(filename, std::ios::out);
        for (const auto& workout : workouts) {
            file << workout.workoutName << "," << workout.workoutType << "," << workout.timestamp << "\n";
        }
    }

    void loadWorkoutHistory(const std::string& filename) {
        std::ifstream file(filename, std::ios::in);
        workouts.clear();
        std::string line;
        while (std::getline(file, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.rfind(',');
            if (pos1 != std::string::npos && pos2 != std::string::npos) {
                std::string name = line.substr(0, pos1);
                std::string type = line.substr(pos1 + 1, pos2 - pos1 - 1);
                time_t time = std::stoll(line.substr(pos2 + 1));
                workouts.emplace_back(name, type, time);
            }
        }
    }
};

// Notification System
class Notification {
public:
    void sendNotification(const std::string& message) const {
        std::cout << "[Notification]: " << message << std::endl;
    }
};

// Social Media Sharing
class SocialMedia {
public:
    void share(const std::string& platform, const std::string& message) const {
        std::cout << "[Shared on " << platform << "]: " << message << std::endl;
    }
};

class Exercise {
private:
    std::string exerciseName;
    int sets;
    int reps;
    float duration;

public:
    Exercise(const std::string& name, int s, int r, float d)
        : exerciseName(name), sets(s), reps(r), duration(d) {
    }

    void displayInstruction() const {
        std::cout << "Exercise: " << exerciseName
            << " | Sets: " << sets
            << " | Reps: " << reps
            << " | Duration: " << duration << " minutes.\n";
    }
};

class User {
private:
    int userId;
    std::string name;
    bool isPremium;
    int age;
    float weight;
    std::string fitnessLevel;
    Notification notificationSystem; // Notification system
    SocialMedia socialMediaSystem;   // Social media sharing system
    WorkoutHistory workoutHistory;

public:
    User(int id, const std::string& name, bool premium, int age = 0, float weight = 0.0f, const std::string& fitnessLevel = "Beginner")
        : userId(id), name(name), isPremium(premium), age(age), weight(weight), fitnessLevel(fitnessLevel) {
    }

    void setGoal(Goal* goal);
    void logWorkout(const std::string& workoutName, const std::string& workoutType) {
        workoutHistory.addWorkout(workoutName, workoutType);
        notificationSystem.sendNotification("Workout logged: " + workoutName + " (" + workoutType + ")");

    }
    void shareWorkoutLog(const std::string& platform, const std::string& workoutName, const std::string& workoutType) {
        std::string message = "Just completed " + workoutName + " (" + workoutType + ")! Feeling great!";
        socialMediaSystem.share(platform, message);
    }

    void displayWorkoutHistory() const {
        workoutHistory.displayAllWorkouts();
    }

    void saveUserData(const std::string& filename) const {
        std::ofstream file(filename, std::ios::out);
        file << userId << "," << name << "," << age << "," << weight << "," << fitnessLevel << "\n";
    }

    void loadUserData(const std::string& filename) {
        std::ifstream file(filename, std::ios::in);
        if (file.is_open()) {
            std::string line;
            if (std::getline(file, line)) {
                size_t pos1 = line.find(',');
                size_t pos2 = line.find(',', pos1 + 1);
                size_t pos3 = line.find(',', pos2 + 1);
                size_t pos4 = line.find(',', pos3 + 1);

                userId = std::stoi(line.substr(0, pos1));
                name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                age = std::stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
                weight = std::stof(line.substr(pos3 + 1, pos4 - pos3 - 1));
                fitnessLevel = line.substr(pos4 + 1);
            }
        }
    }

    int getId() const { return userId; }
    std::string getName() const { return name; }
    void updateUserInfo(int newAge, float newWeight);
    void saveWorkoutHistory(const string& filename) const;
    void loadWorkoutHistory(const string& filename);
};

class Goal {
private:
    std::string goalType;
    float targetValue;

public:
    Goal(const std::string& gType, float target) : goalType(gType), targetValue(target) {}

    void defineGoal() {
        std::cout << "Goal set: " << goalType << " with target value: " << targetValue << "\n";
    }
};

#endif
