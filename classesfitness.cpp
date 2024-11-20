#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <sstream>
#include "classesfitness.h"

using namespace std;

// WorkoutHistory methods
void WorkoutHistory::displayLastNWorkouts(size_t n) const {
    size_t count = std::min(n, workouts.size());
    for (size_t i = workouts.size() - count; i < workouts.size(); ++i) {
        const auto& entry = workouts[i];
        struct tm timeInfo;
        localtime_s(&timeInfo, &entry.timestamp);
        std::cout << "- " << entry.workoutName
            << " (" << entry.workoutType << ") on "
            << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S") << "\n";
    }
}

void WorkoutHistory::displayAllWorkouts() const {
    for (const auto& entry : workouts) {
        struct tm timeInfo;
        localtime_s(&timeInfo, &entry.timestamp);
        std::cout << "- " << entry.workoutName
            << " (" << entry.workoutType << ") on "
            << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S") << "\n";
    }
}

void WorkoutHistory::addWorkout(const std::string& workoutName, const std::string& workoutType) {
    workouts.emplace_back(workoutName, workoutType);
}

void WorkoutHistory::saveWorkoutHistory(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file for saving workout history.\n";
        return;
    }
    for (const auto& entry : workouts) {
        file << entry.workoutName << "," << entry.workoutType << "," << entry.timestamp << "\n";
    }
}

void WorkoutHistory::displayWorkoutHistory(bool isPremium, int limit) const {
    time_t currentTime = std::time(nullptr);
    int count = 0;
    std::cout << "Workout History:\n";
    for (const auto& entry : workouts) {
        if (!isPremium && count >= limit) break;
        struct tm timeInfo;
        localtime_s(&timeInfo, &entry.timestamp);
        std::cout << "- " << entry.workoutName
            << " (" << entry.workoutType << ") on "
            << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S") << "\n";
        count++;
    }
}

void WorkoutHistory::filterWorkoutsByDate(time_t startDate, time_t endDate) const {
    struct tm startTm, endTm;
    if (localtime_s(&startTm, &startDate) != 0) {
        std::cerr << "Error converting startDate to local time.\n";
        return;
    }
    if (localtime_s(&endTm, &endDate) != 0) {
        std::cerr << "Error converting endDate to local time.\n";
        return;
    }
    std::cout << "Workouts between "
        << std::put_time(&startTm, "%Y-%m-%d")
        << " and "
        << std::put_time(&endTm, "%Y-%m-%d") << ":\n";
    for (const auto& entry : workouts) {
        if (entry.timestamp >= startDate && entry.timestamp <= endDate) {
            struct tm timeInfo;
            if (localtime_s(&timeInfo, &entry.timestamp) == 0) {
                std::cout << "- " << entry.workoutName
                    << " (" << entry.workoutType << ") on "
                    << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S") << "\n";
            }
            else {
                std::cerr << "Error converting timestamp to local time.\n";
            }
        }
    }
}

void WorkoutHistory::filterWorkoutsByType(const std::string& workoutType) const {
    std::cout << "Workouts of type: " << workoutType << "\n";
    for (const auto& entry : workouts) {
        if (entry.workoutType == workoutType) {
            struct tm timeInfo;
            if (localtime_s(&timeInfo, &entry.timestamp) == 0) {
                std::cout << "- " << entry.workoutName
                    << " on " << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S") << "\n";
            }
            else {
                std::cerr << "Error converting timestamp to local time.\n";
            }
        }
    }
}

void WorkoutHistory::loadWorkoutHistory(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file for loading workout history.\n";
        return;
    }
    workouts.clear(); // Clear existing data
    std::string line, name, type;
    time_t timestamp;
    while (std::getline(file, line)) {
        std::istringstream stream(line);
        if (std::getline(stream, name, ',') && std::getline(stream, type, ',') && stream >> timestamp) {
            workouts.emplace_back(name, type, timestamp);
        }
    }
}

// User methods

class user;

User::User(int id, const std::string& name, bool premiumStatus, int age, float weight, const std::string& fitnessLevel)
    : userId(id), name(name), isPremium(premiumStatus), age(age), weight(weight), fitnessLevel(fitnessLevel) {
}

Goal* userGoal; // Add this to User class in classesfitness.h


void User::setGoal(Goal* goal) {
    userGoal = goal;
    std::cout << "Goal has been set for user " << name << ".\n";
}
void WorkoutHistory::logWorkout(const std::string& workoutName, const std::string& workoutType) {
    workouts.emplace_back(workoutName, workoutType);
}

void User::logWorkout(const std::string& workoutName, const std::string& workoutType) {
    WorkoutHistory workoutHistory;
    workoutHistory.addWorkout(workoutName, workoutType); // Use the updated addWorkout method
}

void User::displayWorkoutHistory(bool isPremium) const{
    if (isPremium) {
        std::cout << "Displaying full workout history for premium user.\n";
    }
    else {
        std::cout << "Displaying limited workout history for standard user.\n";
    }
}

void User::displayFilteredWorkoutsByDate(time_t startDate, time_t endDate) {
    WorkoutHistory workoutHistory;
    workoutHistory.filterWorkoutsByDate(startDate, endDate);
}

void User::displayFilteredWorkoutsByType(const std::string& type) {
    WorkoutHistory workoutHistory;
    workoutHistory.filterWorkoutsByType(type);
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
    WorkoutHistory workoutHistory;
    workoutHistory.saveWorkoutHistory(filename);
}

void User::loadWorkoutHistory(const std::string& filename) {
    WorkoutHistory workoutHistory;
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
    else if (exerciseName == "Overhead Tricep Extensions") {
        cout << "You selected Overhead Tricep Extension. \n" << endl;
        cout << "Here is the steps to completing this exercise. \n" << endl;
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
        cout << "Here is the steps to completing this exercise. \n" << endl;
        cout << " Step One - Grip the handle of the dumbbell in one hand.\n " << endl;
        cout << " Step Two - Move your feet into a shoulder-width stance, engaging your core by bracing your stomach. \n" << endl;
        cout << " Step Three -  Lift the dumbbell above your head, fully extending your arm so your upper arm is next to your ear, knuckles facing the ceiling. \n " << endl;
        cout << " Step Four - Begin the movement by bending your elbow to lower the dumbbell behind your head. \n " << endl;
        cout << " Step Five - Your upper arm should stay fixed beside your ear with only your forearm moving. \n " << endl;
        cout << " Step Six - Once you have lowered as far as possible, pause, then extend your arm to return the dumbbell back to the starting position, squeezing your tricep as you extend. \n" << endl;
        cout << " Repeat Steps. \n " << endl;
    }
    else if (exerciseName == "Barbell Hip Thrust") {
        cout << "Here is the steps to completing this exercise. \n" << endl;
        cout << " Step One -Keep the bench in its horizontal setting, making sure it's resting against a solid surface (like a wall), so that it won't move. Sit on the floor resting your upper back against the side of the bench and place your feet flat on the ground, between hip-width and shoulder-width apart, at a 90-degree angle.\n " << endl;
        cout << " Step Two - Place the barbell (or dumbbell if using) over your hips. \n" << endl;
        cout << " Step Three -  Brace your core, keep your head neutral and chin slightly tucked with your hands resting on top of the barbell. \n " << endl;
        cout << " Step Four - Push the floor away by driving through your heels and extending your hips towards the ceiling. Squeeze your glutes at the top of the contraction without overextending the lower back. \n " << endl;
        cout << " Step Five - Lower your hips, returning your bum to the floor in a controlled manner, keeping your upper back against the bench throughout. \n " << endl;
        cout << " Repeat Steps. \n " << endl;
    }
    else if (exerciseName == "Romanian Deadlift") {
        cout << "Here is the steps to completing this exercise. \n" << endl;
        cout << " Step One - Imagine you have apples in your armpits and you can’t let them fall out.\n " << endl;
        cout << " Step Two - Move your feet into a shoulder-width stance, engaging your core by bracing your stomach. \n" << endl;
        cout << " Step Three - Slide your hips back and up whilst only letting your knees bend slightly. \n " << endl;
        cout << " Step Four - Allow the bar to glide down your thighs and your shoulders come over your toes. \n " << endl;
        cout << " Step Five - The bar will typically finish around the middle of your shins. \n " << endl;
        cout << " Repeat Steps. \n " << endl;
    }
    else if (exerciseName == "Crunches") {
        cout << "Here is the steps to completing this exercise. \n" << endl;
        cout << " Step One - Lie on your back with your knees bent at a 90-degree angle, feet flat on the floor, lower back in contact with the mat.\n " << endl;
        cout << " Step Two - Placing your arms on your thighs, take a breath in, bracing your core. \n" << endl;
        cout << " Step Three -  Lift your shoulder blades up, exhaling as you rise, crunching’ your abs. Your hands should move up your thighs towards your knees, keeping your chin tucked as you do so. \n " << endl;
        cout << " Step Four - Lower back to the starting position, exhaling. \n " << endl;
        cout << " Repeat Steps. \n " << endl;
    }
    else if (exerciseName == "Russian Twists") {
        cout << "Here is the steps to completing this exercise. \n" << endl;
        cout << " Step One - Select an appropriately weighted med ball, kettlebell, or sandbag. \n " << endl;
        cout << " Step Two - Sit on the floor with your knees bent, feet on the floor, holding the weight close in front of your chest. \n" << endl;
        cout << " Step Three - Lean back slightly, lifting your feet off the floor so your legs form a V-shape. \n " << endl;
        cout << " Step Four - Brace your core and rotate your torso, moving the weight to one side of your body. Bring it down so it is level with your hip, but not touching the ground. Keep your gaze fixed on the weight as you move it. \n " << endl;
        cout << " Step Five - Pause, then return the weight to the center, before moving it down towards the other hip. \n " << endl;
        cout << " Step Six - Return back to center. This counts as one rep. \n" << endl;
        cout << " Repeat Steps. \n " << endl;
    }
    else if (exerciseName == "Cable Crunches") {
        cout << "Here is the steps to completing this exercise. \n" << endl;
        cout << " Step One - Set the cable machine up to the top of the tower and attach the rope attachment. \n " << endl;
        cout << " Step Two - Take hold of the end of the ropes in both hands, taking a couple of steps away from the tower to move the weights off the stack whilst turning to face away from it. Kneel down, placing both knees on the floor directly below shoulders. \n" << endl;
        cout << " Step Three - Hold the rope handles above the top of your head in an overhand grip, thumbs facing the ceiling. \n " << endl;
        cout << " Step Four - Begin the crunch by bracing your core and taking a breath in. Hinge from your hips, breathing out as you contract for abs and curl your torso towards the ground. The rope should remain above your head at all times, chin tucked (imagine you are trying to hold an egg under your chin!) \n " << endl;
        cout << " Step Five - Aim to lower until your elbows are close to your legs, squeezing your abs the whole time. \n " << endl;
        cout << " Step Six - Pause, then slowly extend your torso to come back to starting position. \n" << endl;
        cout << " Repeat Steps. \n " << endl;
    }
    else if (exerciseName == "Bent Over Barbell Row") {
        cout << "Here is the steps to completing this exercise. \n" << endl;
        cout << " Step One - Assume a standing position while holding a dumbbell in each hand with a neutral grip. \n " << endl;
        cout << " Step Two - Hinge forward until your torso is roughly parallel with the floor (or slightly above) and then begin the movement by driving the elbows behind the body while retracting the shoulder blades. \n" << endl;
        cout << " Step Three - Pull the dumbbells towards your body until the elbows are at (or just past) the midline and then slowly lower the dumbbells back to the starting position under control. \n " << endl;
        cout << " Repeat Steps. \n " << endl;
    }
    else if (exerciseName == "Pull Ups") {
        cout << "Here is the steps to completing this exercise. \n" << endl;
        cout << " Step One - Start with your hands on the bar approximately shoulder-width apart with your palms facing forward. \n " << endl;
        cout << " Step Two - With arms extended above you, stick your chest out and curve your back slightly. That is your starting position.  \n" << endl;
        cout << " Step Three - Pull yourself up towards the bar using your back until the bar is at chest level while breathing out.   \n " << endl;
        cout << " Step Four - Slowly lower yourself to the starting position while breathing in. That is one rep. \n " << endl;
        cout << " Repeat Steps. \n " << endl;
    }
    else if (exerciseName == "Dumbbell Shrugs") {
        cout << "Here is the steps to completing this exercise. \n" << endl;
        cout << " Step One - Assume a standing position with the dumbbells on both sides of your body.\n " << endl;
        cout << " Step Two - Hinge forward, inhale, and grab the dumbbells with a neutral grip. \n" << endl;
        cout << " Step Three - Stand up tall and ensure your spine remains neutral.  \n " << endl;
        cout << " Step Four - Contract the traps to elevate the shoulders. Squeeze hard at the top and slowly lower the dumbbells back to the starting position. \n " << endl;
        cout << " Repeat Steps. \n " << endl;
    }
    else if (exerciseName == "Overhead Press") {
        cout << "Here is the steps to completing this exercise. \n" << endl;
        cout << " Step One - Stand with the bar on your front shoulders. Narrow grip, straight wrists, vertical forearms. Lock your knees and hips.\n " << endl;
        cout << " Step Two - Raise your chest towards the ceiling by arching your upper-back. Try to touch your chin with your upper-chest. \n" << endl;
        cout << " Step Three - Take a big breath, hold it, and press the bar in a vertical line. Don’t press it in front or behind your head. Press it over your head.  \n " << endl;
        cout << " Step Four - Stay close to the bar while you press the weight up. Shift your torso forward once the bar has passed your forehead. \n " << endl;
        cout << " Step Five - Hold the bar over your shoulders and mid-foot for proper balance. Lock your elbows. Shrug your shoulders to the ceiling. \n " << endl;
        cout << " Repeat Steps. \n " << endl;
    }
    else if (exerciseName == "Lateral Raises") {
        cout << "Here is the steps to completing this exercise. \n" << endl;
        cout << " Step One - Select the desired weight from the rack, then take a few steps back into an open area.\n " << endl;
        cout << " Step Two - Take a deep breath and raise the dumbbells to shoulder height using a neutral grip (palms facing in) while keeping the elbows slightly bent. \n" << endl;
        cout << " Step Three - Slowly lower the dumbbells back to the starting position under control.  \n " << endl;
        cout << " Repeat Steps. \n " << endl;
    }
    else if (exerciseName == "Shrugs") {
        cout << "Here is the steps to completing this exercise. \n" << endl;
        cout << " Step One - Choose an appropriate dumbbell weight\n " << endl;
        cout << " Step Two - With a dumbbell in each hand, stand up tall with slightly soft knees. \n" << endl;
        cout << " Step Three - Maintain a neutral posture and relaxed arms.  \n " << endl;
        cout << " Step Four - Shrug your shoulders, aiming to bring the cap of your shoulder up towards your ear. \n " << endl;
        cout << " Step Five - Be sure to focus on elevating the traps, rather than retracting your neck/chin. \n " << endl;
        cout << " Step Six - Slowly lower your shoulders back to the start position. \n" << endl;
        cout << " Repeat Steps. \n " << endl;
    }
}
