#ifndef CLASSES_FITNESS
#define CLASSES_FITNESS

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <fstream>

// Forward declarations
class Goal;
class WorkoutHistory;

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
    void addWorkout(const std::string& workoutName, const std::string& workoutType);
    void displayWorkoutHistory(bool isPremium, int limit) const;
    void displayAllWorkouts() const;
    void displayLastNWorkouts(size_t n) const;
    void logWorkout(const std::string& workoutName, const std::string& workoutType);
    void saveWorkoutHistory(const std::string& filename) const;
    void loadWorkoutHistory(const std::string& filename);
    void filterWorkoutsByDate(time_t startDate, time_t endDate) const;
    void filterWorkoutsByType(const std::string& workoutType) const;
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

    void displayInstruction() const;  // Declare the method
    void performExercise() { std::cout << "Performing exercise: " << exerciseName << ".\n"; }
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

public:
    User(int id, const std::string& name, bool isPremium, int age = 0, float weight = 0.0f, const std::string& fitnessLevel = "Beginner");

    void setGoal(Goal* goal);
    void logWorkout(const std::string& workoutName, const std::string& workoutType);
    notificationSystem.sendNotification("Workout logged: " + workoutName + " (" + workoutType + ")");
}

// Share a workout log on social media
void shareWorkoutLog(const std::string& platform, const std::string& workoutName, const std::string& workoutType) {
    std::string message = "Just completed " + workoutName + " (" + workoutType + ")! Feeling great!";
    socialMediaSystem.share(platform, message);
}

// Share an achievement on social media
void shareAchievement(const std::string& platform, const std::string& achievement) {
    std::string message = "I just achieved: " + achievement + "! #FitnessGoals";
    socialMediaSystem.share(platform, message);
}
    void displayWorkoutHistory();
    void displayWorkoutHistory(bool isPremium);
    void displayFilteredWorkoutsByDate(time_t startDate, time_t endDate);
    void displayFilteredWorkoutsByType(const std::string& type);
    void updateUserInfo(int newAge, float newWeight);

    void saveUserData(const std::string& filename) const;
    void loadUserData(const std::string& filename);
    void saveWorkoutHistory(const std::string& filename) const;
    void loadWorkoutHistory(const std::string& filename);

    int getId() const;
    std::string getName() const;

private:
    WorkoutHistory workoutHistory;
};

class Goal {
private:
    std::string goalType;
    float targetValue;
public:
    Goal(const std::string& gType, float target);
    void defineGoal();
};

#endif
