#include "classesfitness.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

// WorkoutHistory methods
void WorkoutHistory::logWorkout(const std::string& workoutName) {
    history.emplace_back(workoutName);
    std::cout << "Logged workout: " << workoutName << "\n";
}

void WorkoutHistory::displayWorkoutHistory(bool premium) const {
    time_t currentTime = std::time(nullptr);
    std::cout << "Workout History:\n";
    for (const auto& entry : history) {
        double weeksElapsed = difftime(currentTime, entry.timestamp) / (7 * 24 * 3600);
        if (premium || weeksElapsed <= 4) {
            struct tm timeInfo;
            localtime_s(&timeInfo, &entry.timestamp);
            std::cout << "- " << entry.workoutName
                << " (Logged on: " << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S") << ")\n";
        }
    }
}

void WorkoutHistory::saveWorkoutHistory(const std::string& fileName) const {
    std::ofstream file(fileName);
    if (!file) {
        std::cerr << "Error: Unable to save workout history to " << fileName << "\n";
        return;
    }
    for (const auto& entry : history) {
        file << entry.workoutName << "\n" << entry.timestamp << "\n";
    }
}

void WorkoutHistory::loadWorkoutHistory(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Error: Unable to load workout history from " << fileName << "\n";
        return;
    }
    history.clear();
    std::string workoutName;
    time_t timestamp;
    while (std::getline(file, workoutName)) {
        file >> timestamp;
        file.ignore();
        history.emplace_back(workoutName, timestamp);
    }
}

// User methods
User::User(int id, const std::string& n, int a, float w, const std::string& f)
    : userId(id), name(n), age(a), weight(w), fitnessLevel(f), userGoal(nullptr) {}

void User::setGoal(Goal* goal) {
    userGoal = goal;
    std::cout << "Goal has been set for user " << name << ".\n";
}

void User::logWorkout(const std::string& workoutName) {
    workoutHistory.logWorkout(workoutName);
    std::cout << "Workout logged for user " << name << ": " << workoutName << "\n";
}

void User::displayWorkoutHistory(bool premium) const {
    workoutHistory.displayWorkoutHistory(premium);
}

void User::updateUserInfo(int newAge, float newWeight) {
    age = newAge;
    weight = newWeight;
    std::cout << "User " << name << "'s information updated: Age = " << age << ", Weight = " << weight << "\n";
}

void User::saveUserData(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to save user data to " << filename << "\n";
        return;
    }
    file << userId << "\n" << name << "\n" << age << "\n" << weight << "\n" << fitnessLevel << "\n";
}

void User::loadUserData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to load user data from " << filename << "\n";
        return;
    }
    file >> userId >> name >> age >> weight;
    file.ignore();
    std::getline(file, fitnessLevel);
}

void User::saveWorkoutHistory(const std::string& filename) const {
    workoutHistory.saveWorkoutHistory(filename);
}

void User::loadWorkoutHistory(const std::string& filename) {
    workoutHistory.loadWorkoutHistory(filename);
}

int User::getId() const { return userId; }
std::string User::getName() const { return name; }

// Goal methods
Goal::Goal(const std::string& gType, float target) : goalType(gType), targetValue(target) {}

void Goal::defineGoal() {
    std::cout << "Goal defined: " << goalType << " with target " << targetValue << ".\n";
}

//Exercise instructions method
void Exercise::displayInstruction() const {
    if (exerciseName == "Skull Crusher") {
        cout << "You selected Skull Crushers. \n";
        cout << "Here are the steps to completing this exercise: \n";
        cout << " Step One - Position the bench so it is lying flat.\n";
        cout << " Step Two - Pick up two dumbbells you can comfortably use for the prescribed rep range.\n";
        cout << " Step Three - Sit on the end of the bench, resting the two dumbbells on your thighs, feet planted on the floor.\n";
        cout << " Step Four - Lie back on the bench, extending your arms out above you as you do so, making sure your feet are still planted on the ground. Elbows should be soft and not locked out.\n";
        cout << " Step Five - Start the movement by flexing your elbows, lowering the dumbbells' heads toward your ears, keeping your upper arms as still as possible.\n";
        cout << " Step Six - When the weight is level with your ears, pause, then extend the forearms back to the starting position, squeezing your triceps at the extension.\n";
        cout << " Repeat these steps for the desired number of repetitions.\n\n";
    }
    else if (exerciseName == "Cable Tricep Push Down") {
        cout << "You selected Cable Tricep Push Down. \n";
        cout << "Here are the steps to completing this exercise: \n";
        cout << " Step One - Set up the cable to the highest setting on the tower with a rope attachment (or other attachment of your choice).\n";
        cout << " Step Two - Stand with feet shoulder-width apart, facing the cable, taking hold of the rope in a pronated grip.\n";
        cout << " Step Three - Brace your core and keep your elbows close to your sides.\n";
        cout << " Step Four - Press the rope handles down toward your outer thighs.\n";
        cout << " Step Five - When your arms are fully extended, pause, squeezing your triceps.\n";
        cout << " Step Six - Slowly return to the starting position, bending your elbows to bring your forearms back up.\n";
        cout << " Repeat these steps for the desired number of repetitions.\n\n";
    }
    else if (exerciseName == "Cable Tricep Extensions") {
        cout << "You selected Cable Tricep Extension. \n" << endl;
        cout << "Here is the steps to completing this excercise. \n" << endl;
        cout << " Step One - Set up the cable to the highest setting on the tower with a rope attachment (or other attachment of your choice).\n " << endl;
        cout << " Step Two - Stand with feet shoulder - width apart, facing the cable, taking hold of the rope in a pronated grip. \n" << endl;
        cout << " Step Three -  Brace your core and keep your elbows close to your sides. \n " << endl;
        cout << " Step Four - Press the rope handles down toward your outer thighs. \n " << endl;
        cout << " Step Five - When your arms are fully extended, pause, squeezing your triceps. \n " << endl;
        cout << " Step Six - Slowly return to the starting position, bending your elbows to bring your forearms back up. \n" << endl;
        cout << " Repeat Steps. \n " << endl;
    }
    else if (exerciseName == "Overhead Tricep Extensions") {
        cout << "You selected Overhead Tricep Extension. \n" << endl;
        cout << "Here is the steps to completing this excercise. \n" << endl;
        cout << " Step One - Grip the handle of the dumbbell in one hand.\n " << endl;
        cout << " Step Two - Move your feet into a shoulder-width stance, engaging your core by bracing your stomach. \n" << endl;
        cout << " Step Three -  Lift the dumbbell above your head, fully extending your arm so your upper arm is next to your ear, knuckles facing the ceiling. \n " << endl;
        cout << " Step Four - Begin the movement by bending your elbow to lower the dumbbell behind your head. \n " << endl;
        cout << " Step Five - Your upper arm should stay fixed beside your ear with only your forearm moving. \n " << endl;
        cout << " Step Six - Once you have lowered as far as possible, pause, then extend your arm to return the dumbbell back to the starting position, squeezing your tricep as you extend. \n" << endl;
        cout << " Repeat Steps. \n " << endl;
    }
    else if (exerciseName == "Bulgarian Split-Squat") {
        cout << "You selected Bulgarian Split-Squat. \n" << endl;
        cout << "Here is the steps to completing this excercise. \n" << endl;
        cout << " Step One - Grip the handle of the dumbbell in one hand.\n " << endl;
        cout << " Step Two - Move your feet into a shoulder-width stance, engaging your core by bracing your stomach. \n" << endl;
        cout << " Step Three -  Lift the dumbbell above your head, fully extending your arm so your upper arm is next to your ear, knuckles facing the ceiling. \n " << endl;
        cout << " Step Four - Begin the movement by bending your elbow to lower the dumbbell behind your head. \n " << endl;
        cout << " Step Five - Your upper arm should stay fixed beside your ear with only your forearm moving. \n " << endl;
        cout << " Step Six - Once you have lowered as far as possible, pause, then extend your arm to return the dumbbell back to the starting position, squeezing your tricep as you extend. \n" << endl;
        cout << " Repeat Steps. \n " << endl;
    }
}
