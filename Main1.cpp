#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include <ctime>
#include <thread>
#include <chrono>
#include "classesfitness.h"

using namespace std;

// Function to send a notification
void sendNotification(const string& message) {
    cout << "[Notification]: " << message << endl;
}

// Function to simulate sharing on social media
void shareOnSocialMedia(const string& platform, const string& message) {
    cout << "Shared on " << platform << ": " << message << endl;
}

int main() {
    int username;
    float weight{};
    int age{};
    int password{};
    int goal;
    int workoutType;

    // File paths for persistence
    const string userDataFile = "user_data";
    const string workoutHistoryFile = "workout_history";

    // Create users
    User cole(1, "Cole", false, 0, 0.0f, "Beginner");
    User matt(2, "Matt", true, 0, 0.0f, "Beginner");
    User thao(3, "Thao", false, 0, 0.0f, "Beginner");

    // Load data for all users
    cole.loadUserData(userDataFile + "_1.txt");
    cole.loadWorkoutHistory(workoutHistoryFile + "_1.txt");
    matt.loadUserData(userDataFile + "_2.txt");
    matt.loadWorkoutHistory(workoutHistoryFile + "_2.txt");
    thao.loadUserData(userDataFile + "_3.txt");
    thao.loadWorkoutHistory(workoutHistoryFile + "_3.txt");

    User* activeUser = nullptr;

    // User Login
    cout << "Please enter your username/Email:\n";
    cout << "1 = Cole (cole@gmail.com), 2 = Matt (matt@gmail.com), 3 = Thao (thao@gmail.com):\n";
    cin >> username;

    if (username == 1) {
        activeUser = &cole;
        password = 123;
    }
    else if (username == 2) {
        activeUser = &matt;
        password = 456;
    }
    else if (username == 3) {
        activeUser = &thao;
        password = 789;
    }
    else {
        cout << "Invalid username selection.\n";
        return 1;
    }

    cout << "Please enter your password: \n";
    int inputPassword;
    cin >> inputPassword;
    if (inputPassword != password) {
        cout << "Password incorrect. Exiting program.\n";
        return 1;
    }

    cout << "Welcome, " << activeUser->getName() << "! Please enter your weight:\n";
    sendNotification("Welcome back, " + activeUser->getName() + "! Ready to crush your fitness goals?");
    cin >> weight;
    cout << "Please enter your age:\n";
    cin >> age;
    activeUser->updateUserInfo(age, weight);

    // Main Program Loop
    while (true) {
        cout << "\nSelect an option:\n";
        cout << "1. Set Goal\n";
        cout << "2. Select and Log Workout\n";
        cout << "3. View Workout History\n";
        cout << "4. Share Progress on Social Media\n";
        cout << "5. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Select a goal:\n";
            cout << "1. Lose 10 pounds\n";
            cout << "2. Lose 20 pounds\n";
            cout << "3. Lose 30 pounds\n";
            cin >> goal;

            if (goal >= 1 && goal <= 3) {
                Goal userGoal("Weight Loss", 10.0f * goal);
                activeUser->setGoal(&userGoal);
                userGoal.defineGoal();
                sendNotification("Your goal to lose " + to_string(10 * goal) + " pounds has been set. Stay focused!");
            }
            else {
                cout << "Invalid goal selection.\n";
            }
        }
        else if (choice == 2) { // Select and log workout
            cout << "Select a workout type:\n";
            cout << "1. Arms\n2. Legs\n3. Abs\n4. Back\n5. Shoulders\n";
            cin >> workoutType;

            string workoutCategory, workoutName;
            switch (workoutType) {
            case 1: workoutCategory = "Arms"; workoutName = "Skull Crusher"; break;
            case 2: workoutCategory = "Legs"; workoutName = "Bulgarian Split Squat"; break;
            case 3: workoutCategory = "Abs"; workoutName = "Crunches"; break;
            case 4: workoutCategory = "Back"; workoutName = "Pull Ups"; break;
            case 5: workoutCategory = "Shoulders"; workoutName = "Overhead Press"; break;
            default:
                cout << "Invalid workout type.\n";
                continue;
            }

            activeUser->logWorkout(workoutName, workoutCategory);
            sendNotification("Workout logged: " + workoutName + " (" + workoutCategory + ")");
        }
        else if (choice == 3) {
            cout << "Viewing Workout History:\n";
            activeUser->displayWorkoutHistory();
        }
        else if (choice == 4) {
            string platform;
            cout << "Enter the social media platform (e.g., Facebook, Twitter, Instagram):\n";
            cin.ignore(); // Clear newline character left in the input buffer
            getline(cin, platform);
            string message = activeUser->getName() + " just completed a workout!";
            shareOnSocialMedia(platform, message);
        }
        else if (choice == 5) {
            cout << "Saving data...\n";
            activeUser->saveUserData(userDataFile + "_" + to_string(activeUser->getId()) + ".txt");
            activeUser->saveWorkoutHistory(workoutHistoryFile + "_" + to_string(activeUser->getId()) + ".txt");
            cout << "Goodbye, " << activeUser->getName() << "!\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
