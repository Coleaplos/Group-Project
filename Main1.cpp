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
// Function declarations
void sendNotification(const std::string& message);
void remindUserToWorkout(User* activeUser);
void notifyGoalAchieved(User* activeUser);
void shareWorkoutOnSocialMedia(const string& workoutName, const string& workoutCategory);

int main() {
    int username;
    int weight1{};
    int weight2{};
    int weight3{};
    int age1{};
    int age2{};
    int age3{};
    int password{};
    int goal;
    int workouttype;
    int armexercise;
    int legexercise;
    int abexercise;
    int backexercise;
    int shoulderexercise;

    // File paths for persistence
    const string userDataFile = "user_data.txt";
    const string workoutHistoryFile = "workout_history.txt";

    // Create users
    User cole(1, "Cole", false, 0, 0.0f, "Beginner");
    User matt(2, "Matt", true, 0, 0.0f, "Beginner");
    User thao(3, "Thao", false, 0, 0.0f, "Beginner");

    // Load data for all users
    cole.loadUserData(userDataFile + "_1");
    cole.loadWorkoutHistory(workoutHistoryFile + "_1");
    matt.loadUserData(userDataFile + "_2");
    matt.loadWorkoutHistory(workoutHistoryFile + "_2");
    thao.loadUserData(userDataFile + "_3");
    thao.loadWorkoutHistory(workoutHistoryFile + "_3");

    User* activeUser = nullptr;

    // User Login
    cout << "Please enter your username/Email:\n";
    cout << "1 = Cole (cole@gmail.com), 2 = Matt (matt@gmail.com), 3 = Thao (thao@gmail.com):\n";
    cin >> username;

    if (username == 1) {
        activeUser = &cole;
        while (true) {
            cout << "Please enter your password: \n";
            cin >> password;
            if (password != 123) {
                cout << "Password incorrect. Please try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }
        cout << "Welcome Cole! Please enter your weight:\n";
        cin >> weight1;
        cout << "Please enter your age:\n";
        cin >> age1;
        activeUser->updateUserInfo(age1, static_cast<float>(weight1));
    }
    else if (username == 2) {
        activeUser = &matt;
        while (true) {
            cout << "Please enter your password: \n";
            cin >> password;
            if (password != 456) {
                cout << "Password incorrect. Please try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }
        cout << "Welcome Matt! Please enter your weight:\n";
        cin >> weight2;
        cout << "Please enter your age:\n";
        cin >> age2;
        activeUser->updateUserInfo(age2, static_cast<float>(weight2));
    }
    else if (username == 3) {
        activeUser = &thao;
        while (true) {
            cout << "Please enter your password: \n";
            cin >> password;
            if (password != 789) {
                cout << "Password incorrect. Please try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }
        cout << "Welcome Thao! Please enter your weight:\n";
        cin >> weight3;
        cout << "Please enter your age:\n";
        cin >> age3;
        activeUser->updateUserInfo(age3, static_cast<float>(weight3));
    }
    else {
        cout << "Invalid username selection.\n";
        return 1;
    }

    // Main Program Loop
    while (true) {
        cout << "Select an option:\n";
        cout << "1. Set Goal\n";
        cout << "2. Select and Log Workout\n";
        cout << "3. View Workout History\n";
        cout << "4. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Select a goal:\n";
            cout << "1. Lose 10 pounds\n";
            cout << "2. Lose 20 pounds\n";
            cout << "3. Lose 30 pounds\n";
            cin >> goal;

            if (goal == 1) {
                Goal userGoal("Weight Loss", 10.0f);
                activeUser->setGoal(&userGoal);
                userGoal.defineGoal();
            }
            else if (goal == 2) {
                Goal userGoal("Weight Loss", 20.0f);
                activeUser->setGoal(&userGoal);
                userGoal.defineGoal();
            }
            else if (goal == 3) {
                Goal userGoal("Weight Loss", 30.0f);
                activeUser->setGoal(&userGoal);
                userGoal.defineGoal();
            }
            else {
                cout << "Invalid goal selection.\n";
            }
        }
        else if (choice == 2) { // Select and log workout
            cout << "Please select what type of exercise you would like to do today:\n";
            cout << "1 = Arms\n2 = Legs\n3 = Abs\n4 = Back\n5 = Shoulders\n";
            cin >> workouttype;

            std::string workoutCategory;
            std::string workoutName;

            if (workouttype == 1) { // Arms
                workoutCategory = "Arms";
                cout << "You selected Arms. Select an arm exercise:\n";
                cout << "1. Skull Crusher\n2. Cable Tricep Push Down\n3. Overhead Tricep Extension\n";
                cin >> armexercise;

                if (armexercise == 1) {
                    workoutName = "Skull Crusher";
                    Exercise skullCrusher("Skull Crusher", 3, 12, 0.0f);
                    skullCrusher.displayInstruction();
                }
                else if (armexercise == 2) {
                    workoutName = "Cable Tricep Push Down";
                    Exercise cablePushDown("Cable Tricep Push Down", 3, 12, 0.0f);
                    cablePushDown.displayInstruction();
                }
                else if (armexercise == 3) {
                    workoutName = "Overhead Tricep Extension";
                    Exercise overheadTriExtension("Overhead Tricep Extension", 3, 12, 0.0f);
                    overheadTriExtension.displayInstruction();
                }
                else {
                    cout << "Invalid exercise.\n";
                }
            }
            else if (workouttype == 2) { // Legs
                workoutCategory = "Legs";
                cout << "You selected Legs. Select a leg exercise:\n";
                cout << "1. Bulgarian Split Squat\n2. Barbell Hip Thrust\n3. Romanian Deadlift\n";
                cin >> legexercise;

                if (legexercise == 1) {
                    workoutName = "Bulgarian Split Squat";
                    Exercise bulgarianSplitSquat("Bulgarian Split Squat", 3, 10, 0.0f);
                    bulgarianSplitSquat.displayInstruction();
                }
                else if (legexercise == 2) {
                    workoutName = "Barbell Hip Thrust";
                    Exercise barbellHipThrust("Barbell Hip Thrust", 3, 10, 0.0f);
                    barbellHipThrust.displayInstruction();
                }
                else if (legexercise == 3) {
                    workoutName = "Romanian Deadlift";
                    Exercise romanianDeadlift("Romanian Deadlift", 3, 10, 0.0f);
                    romanianDeadlift.displayInstruction();
                }
                else {
                    cout << "Invalid exercise.\n";
                }
            }
            else if (workouttype == 3) { // Abs
                workoutCategory = "Abs";
                cout << "You selected Abs. Select an abs exercise:\n";
                cout << "1. Crunches\n2. Russian Twists\n3. Cable Crunches\n";
                cin >> abexercise;

                if (abexercise == 1) {
                    workoutName = "Crunches";
                    Exercise crunches("Crunches", 3, 12, 0.0f);
                    crunches.displayInstruction();
                }
                else if (abexercise == 2) {
                    workoutName = "Russian Twists";
                    Exercise russianTwists("Russian Twists", 3, 12, 0.0f);
                    russianTwists.displayInstruction();
                }
                else if (abexercise == 3) {
                    workoutName = "Cable Crunches";
                    Exercise cableCrunches("Cable Crunches", 3, 12, 0.0f);
                    cableCrunches.displayInstruction();
                }
                else {
                    cout << "Invalid exercise.\n";
                }
            }
            else if (workouttype == 4) { // Back
                workoutCategory = "Back";
                cout << "You selected Back. Select a back exercise:\n";
                cout << "1. Bent Over Barbell Row\n2. Pull Ups\n3. Dumbbell Shrugs\n";
                cin >> backexercise;

                if (backexercise == 1) {
                    workoutName = "Bent Over Barbell Row";
                    Exercise bentoverBarbell("Bent Over Barbell Row", 3, 12, 0.0f);
                    bentoverBarbell.displayInstruction();
                }
                else if (backexercise == 2) {
                    workoutName = "Pull Ups";
                    Exercise pullUps("Pull Ups", 3, 12, 0.0f);
                    pullUps.displayInstruction();
                }
                else if (backexercise == 3) {
                    workoutName = "Dumbbell Shrugs";
                    Exercise dumbbellShrugs("Dumbbell Shrugs", 3, 12, 0.0f);
                    dumbbellShrugs.displayInstruction();
                }
                else {
                    cout << "Invalid exercise.\n";
                }
            }
            else if (workouttype == 5) { // Shoulders
                workoutCategory = "Shoulders";
                cout << "You selected Shoulders. Select a shoulder exercise:\n";
                cout << "1. Overhead Press\n2. Lateral Raises\n3. Shrugs\n";
                cin >> shoulderexercise;

                if (shoulderexercise == 1) {
                    workoutName = "Overhead Press";
                    Exercise overheadPress("Overhead Press", 3, 12, 0.0f);
                    overheadPress.displayInstruction();
                }
                else if (shoulderexercise == 2) {
                    workoutName = "Lateral Raises";
                    Exercise lateralRaises("Lateral Raises", 3, 12, 0.0f);
                    lateralRaises.displayInstruction();
                }
                else if (shoulderexercise == 3) {
                    workoutName = "Shrugs";
                    Exercise shrugs("Shrugs", 3, 12, 0.0f);
                    shrugs.displayInstruction();
                }
                else {
                    cout << "Invalid exercise.\n";
                }
            }
            else {
                cout << "Invalid workout type.\n";
            }

            // Log the workout if a valid name was selected
            if (!workoutName.empty()) {
                activeUser->logWorkout(workoutName, workoutCategory);
                std::cout << "Workout logged: " << workoutName << " (" << workoutCategory << ")\n";
            }
        }

        else if (choice == 3) {
            cout << "Viewing Workout History:\n";
            activeUser->displayWorkoutHistory();
        }
        else if (choice == 4) {
            cout << "Saving data...\n";
            activeUser->saveUserData(userDataFile + "_" + to_string(activeUser->getId()));
            activeUser->saveWorkoutHistory(workoutHistoryFile + "_" + to_string(activeUser->getId()));
            cout << "Goodbye, " << activeUser->getName() << "!\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
            // Check and send workout reminders or goal achievement notifications
    remindUserToWorkout(activeUser);
    notifyGoalAchieved(activeUser);
    }

    // Save all user data before exiting
    cole.saveUserData(userDataFile + "_1");
    cole.saveWorkoutHistory(workoutHistoryFile + "_1");
    matt.saveUserData(userDataFile + "_2");
    matt.saveWorkoutHistory(workoutHistoryFile + "_2");
    thao.saveUserData(userDataFile + "_3");
    thao.saveWorkoutHistory(workoutHistoryFile + "_3");

    std::cout << "All user data saved successfully. Exiting program.\n";

    return 0;
}
void sendNotification(const std::string& message)
{
}

void remindUserToWorkout(User* activeUser)
{
}

void notifyGoalAchieved(User* activeUser)
{
}

void shareWorkoutOnSocialMedia(const string& workoutName, const string& workoutCategory)
{
}
