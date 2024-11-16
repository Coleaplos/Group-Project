#ifndef CLASSES_FITNESS
#define CLASSES_FITNESS

#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Forward declarations for the class relationships
class User; //This is the operators information( there name, weight, and age)
class Account; // The user will only have access to a free profile that allows 50 exercises and workout history for up to 4 weeks. As well as a premium one that does not limit historical data accessibility.
class Goal; // This is the users goals
class Workout; //Users can log their daily workouts, selecting from previously added exercises and specifying the duration or reps/sets.
class ProgressTracker; //Provides a weekly summary showing a user’s progress, such as sets, reps, calories burned, and progress toward goals.
class MotivationalTool; // This will help the user time there workouts and keep them focused 
class Notification; //This will give the user a reminder to work out
class SocialNetwork; // Users will be able to inform friends and other users about there accomplishments and there workouts 
class Exercise; // Users can add, update, delete, and view exercises categorized by type (e.g., cardio, strength)
class EngagementAwards; //Provide users with positive feedback upon meeting goals. Users would get a rate of payment ($0.50 per goal complete) each time the user's goal is complete.

// Class: User
class User {
private:
    int userId;
    std::string name;
    int age;
    float weight;
    std::string fitnessLevel;
    Goal* userGoal;

public:
    User(int id, const std::string& n, int a, float w, const std::string& f)
        : userId(id), name(n), age(a), weight(w), fitnessLevel(f), userGoal(nullptr) {}

    void setGoal(Goal* goal) { userGoal = goal; }
    void selectWorkout() { std::cout << name << " has selected a workout.\n"; }
    void trackProgress() { std::cout << name << " is tracking progress.\n"; }
    void joinChallenge() { std::cout << name << " joined a challenge.\n"; }
};

// Class: Account
class Account {
private:
    std::string username;
    std::string password;
    std::string email;

public:
    Account(const std::string& u, const std::string& p, const std::string& e)
        : username(u), password(p), email(e) {}

    void createAccount() { std::cout << "Account for " << username << " created.\n"; }
    void login() { std::cout << username << " logged in.\n"; }
    void logout() { std::cout << username << " logged out.\n"; }

};

class AccountPremium{
private:
    std::string username; 
    std::string password; 
    std::string email; 
    std::string usernamepremium;
    std::string passwordpremium;
    std::string emailpremium;

public:

    AccountPremium(const std::string& i, const std::string& p, const std::string& e)
        : usernamepremium(i), password(p), email(e) {}
    void createAccountPremium() { std::cout << "Premium account for " << usernamepremium << " created.\n"; }
    void loginPremium() { std::cout << usernamepremium << " logged in.\n"; }
    void logoutPremium() { std::cout << usernamepremium << " logged out.\n"; }
};

// Class: Goal
class Goal {
private:
    std::string goalType;
    float targetValue;

public:
    Goal(const std::string& gType, float target) : goalType(gType), targetValue(target) {}

    void defineGoal() { std::cout << "Goal defined: " << goalType << " with target " << targetValue << ".\n"; }
};

// Class: Workout
class Workout {
private:
    int workoutId;
    std::string name;
    std::string type;
    int difficultyLevel;

public:
    Workout(int id, const std::string& n, const std::string& t, int difficulty)
        : workoutId(id), name(n), type(t), difficultyLevel(difficulty) {}

    void chooseWorkout() { std::cout << "Workout chosen: " << name << ".\n"; }
    void displayInstructions() { std::cout << "Displaying workout instructions for " << name << ".\n"; }
};

// Class: Exercise
class Exercise {
private:
    std::string exerciseName;
    int sets;
    int reps;
    float duration;

public:
    Exercise(const std::string& name, int s, int r, float d)
        : exerciseName(name), sets(s), reps(r), duration(d) {}

    void displayInstruction() { std::cout << "Instructions for " << exerciseName << ".\n"; }
    void performExercise() { std::cout << "Performing exercise: " << exerciseName << ".\n"; }
};

// Class: ProgressTracker
class ProgressTracker {
private:
    float caloriesBurned;
    int stepsTaken;
    float workoutDuration;

public:
    ProgressTracker(float c, int s, float d)
        : caloriesBurned(c), stepsTaken(s), workoutDuration(d) {}

    void logProgress() {
        std::cout << "Logging progress: " << caloriesBurned << " kcal burned, "
            << stepsTaken << " steps taken.\n";
    }
    void syncData() { std::cout << "Syncing progress data.\n"; }
};

// Class: MotivationalTool
class MotivationalTool {
private:
    std::string toolType;
    bool isActive;

public:
    MotivationalTool(const std::string& type) : toolType(type), isActive(false) {}

    void startTimer() { std::cout << "Timer started for " << toolType << ".\n"; }
    void playMusic() { std::cout << "Playing motivational music.\n"; }
    void giveReward() { std::cout << "Reward granted for completing a challenge.\n"; }
};


#endif

