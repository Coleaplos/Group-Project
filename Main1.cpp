#include "classesfitness.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    int username;
    int weight1{};
    int weight2{};
    int weight3{};
    int age1{};
    int age2{};
    int age3{};
    int email;
    int password{};
    int goal;
    int workouttype;
    int armexcersise;
    int backexcersise;
    int sholderexcersise;
    int abexcersise;
    int legexcersise;

    cout << "Please enter your username/Email:\n"; //login 
    cout << " 1 is Cole/cole@gmail.com, 2 is Matt/Matt@gmail.com, 3 is Thao/Thao@gmail.com: \n";
    cin >> username;
    if (username == 1)
    {
        while (true) { //if and invalid number is entered 
            cout << "Please enter your password: \n";
            cin >> password;
            bool fail = (password != 123);
            if (fail) {
                cout << " Password incorrect. Please try again. \n";
                cin.clear();
                cin.ignore();
            }
            else {
                break;
            }
        }
        cout << "you entered:  " << password;
        cout << "\n Welcome Cole please enter your weight: \n";
        cin >> weight1;
        cout << " please enter your age: \n";
        cin >> age1;
    }

    if (username == 2)
    {
        while (true) {
            cout << "Please enter your password: \n";
            cin >> password;
            bool fail = (password != 123);
            if (fail) {
                cout << " Password incorrect. Please try again. \n";
                cin.clear();
                cin.ignore();
            }
            else {
                break;
            }
        }
        cout << "you entered: " << password;
        cout << "\n Welcome Matt Thank you for your subscription. \n please enter your weight: \n";
        cin >> weight2;
        cout << " please enter your age: \n";
        cin >> age2;
    }
    if (username == 3)
    {
        while (true) {
            cout << "Please enter your password: \n";
            cin >> password;
            bool fail = (password != 123);
            if (fail) {
                cout << " Password incorrect. Please try again. \n";
                cin.clear();
                cin.ignore();
            }
            else {
                break;
            }
        }
        cout << "you entered: " << password;
        cout << "\n Welcome Thao please enter your weight: \n";
        cin >> weight3;
        cout << " please enter your age: \n";
        cin >> age3;
    }



    // Create instances for each class
    if (username == 1) {
        Account userAccount("Cole", "password123", "Cole@email.com");
        userAccount.createAccount();
        userAccount.login();
        while (true) {
            cout << " Select goal 1 if you would like to lose 10 pounds:\n" << endl;
            cout << " Select goal 2 if you would like to lose 20 pounds:\n" << endl;
            cout << " Select goal 3 if you would like to lose 30 pounds:\n" << endl;
            cout << "please set your goal: \n" << endl;
            cin >> goal;
            bool fail = (goal != 1 && goal != 2 && goal != 3);
            if (fail) {
                cout << "invald Number Please Try Again \n";
                cin.clear();
                cin.ignore();
            }
            else {
                break;
            }
        }
            if (goal == 1) {
                Goal userGoal("Weight Loss", 10.0f);
                userGoal.defineGoal();

                User user(1, "Cole", age1, weight1, "Beginner");
                user.setGoal(&userGoal);
            }
            if (goal == 2) {
                Goal userGoal("Weight Loss", 20.0f);
                userGoal.defineGoal();

                User user(1, "Cole", age1, weight1, "Beginner");
                user.setGoal(&userGoal);
            }
            if (goal == 3) {
                Goal userGoal("Weight Loss", 30.0f);
                userGoal.defineGoal();

                User user(1, "Cole", age1, weight1, "Beginner");
                user.setGoal(&userGoal);
            }

            userAccount.logout();
            return 0;
        }
        if (username == 2) {
            AccountPremium userAccountPremium("Matt", "password123", "Matt@email.com");
            userAccountPremium.createAccountPremium();
            userAccountPremium.loginPremium();
            while (true) {
                cout << " Select goal 1 if you would like to lose 10 pounds:\n" << endl;
                cout << " Select goal 2 if you would like to lose 20 pounds:\n" << endl;
                cout << " Select goal 3 if you would like to lose 30 pounds:\n" << endl;
                cout << "please set your goal: \n" << endl;
                cin >> goal;
                bool fail = (goal != 1 && goal != 2 && goal != 3);
                if (fail) {
                    cout << "invald Number Please Try Again \n";
                    cin.clear();
                    cin.ignore();
                }
                else {
                    break;
                }
            }
            if (goal == 1) {
                Goal userGoal("Weight Loss", 10.0f);
                userGoal.defineGoal();

                User user(2, "Matt", age2, weight2, "Beginner");
                user.setGoal(&userGoal);
            }
            if (goal == 2) {
                Goal userGoal("Weight Loss", 20.0f);
                userGoal.defineGoal();

                User user(2, "Matt", age2, weight2, "Beginner");
                user.setGoal(&userGoal);
            }
            if (goal == 3) {
                Goal userGoal("Weight Loss", 30.0f);
                userGoal.defineGoal();

                User user(2, "Matt", age2, weight2, "Beginner");
                user.setGoal(&userGoal);
            }

            userAccountPremium.logoutPremium();
            return 0;
        }
        if (username == 3) {
            Account userAccount("Thao", "password123", "Thao@email.com");
            userAccount.createAccount();
            userAccount.login();
            while (true) {
                cout << " Select goal 1 if you would like to lose 10 pounds:\n" << endl;
                cout << " Select goal 2 if you would like to lose 20 pounds:\n" << endl;
                cout << " Select goal 3 if you would like to lose 30 pounds:\n" << endl;
                cout << "please set your goal: \n" << endl;
                cin >> goal;
                bool fail = (goal != 1 && goal != 2 && goal != 3);
                if (fail) {
                    cout << "invald Number Please Try Again \n";
                    cin.clear();
                    cin.ignore();
                }
                else {
                    break;
                }
            }
            if (goal == 1) {
                Goal userGoal("Weight Loss", 10.0f);
                userGoal.defineGoal();

                User user(3, "Thao", age3, weight3, "Beginner");
                user.setGoal(&userGoal);
            }
            if (goal == 2) {
                Goal userGoal("Weight Loss", 20.0f);
                userGoal.defineGoal();

                User user(3, "Thao", age3, weight3, "Beginner");
                user.setGoal(&userGoal);
            }
            if (goal == 3) {
                Goal userGoal("Weight Loss", 30.0f);
                userGoal.defineGoal();

                User user(3, "Thao", age3, weight3, "Beginner");
                user.setGoal(&userGoal);
            }

            cout << "Please select what type of excersise you would like to do today: \n " << endl;
            cout << " 1 = arms \n 2 = legs \n 3 = abs \n 4 = back \n 5 = sholders " << endl;
            cin >> workouttype;
            if (workouttype == 1) {
                cout << "You selected Arms. \n" << endl;
                cout << " Select what arm excercise you would like to do. \n" << endl;
                cout << "1 is Skull Crusher. \n" << endl;
                cout << "2 is Cable Triceppush Down. \n" << endl;
                cout << "3 is Overhead Tricep Extension. \n" << endl;
                cout << "4 is Dumbbell Preacher Curl. \n" << endl; //Set up the bench at a 60-degree incline (one setting below fully upright). Select an appropriate weight dumbbell.Hold the dumbbell in one hand and stand behind the bench.Bring that arm over the top of the bench so the upper arm rests on the backrest, with your armpit hugging the top of the bench(you may have to bend your knees slightly).Start with your palm facing up, arm bent.Then begin the movement, by extending your forearm down as far as possible.Pause, then reverse the motion, curling the dumbbell up towards your shoulder.
                cout << "5 is Barbell Bicep Curl . \n" << endl; //Select a preloaded bar of an appropriate weight, or load up a barbell with plates. Take hold of the bar in a supinated grip(palms up), shoulder - width apart.Stand with your arms fully extended, elbows by your side.Feet should be directly below hips, knees slightly bent, and shoulder blades retracted.Keeping your elbows in the same position(by your side), contract your biceps and curl the bar upwards through a full range of motion.Once your elbows are fully bent and the bar is near your shoulders, pause, squeezing your biceps as you do so.Then, slowly lower back to the starting position, arms fully extended.
                cout << "6 is Cable Bicep Curl. \n" << endl; // Set the cable to the bottom of the tower and attach a straight bar attachment. Set the weight by adjusting the pin.Take hold of the bar in both hands, with a supinated(underhand) grip.Take a step back from the tower, positioning your feet to shoulder width apart, keeping a soft knee.Arms should be extended, bar by your thighs. Begin the curl by engaging your core, and bending your elbows to move the bar towards your shoulders.Keep your elbows tucked into your sides and ensure only your forearms move. When you reach the top, pause, squeezing your biceps.Reverse the movement, slowly lowering back to the starting position, arms fully extended.Repeat.
                cin >> armexcersise;
                if (armexcersise == 1) {
                    cout << "You selected Skull Crushers. \n" << endl;
                    cout << "Here is the steps to completing this excercise. \n" << endl;
                    cout << " Step One - Position the bench so it is lying flat.\n " << endl;
                    cout << " Step Two - Pick up two dumbbells you can comfortably use for the prescribed rep range. \n" << endl;
                    cout << " Step Three -  Sit on the end of the bench, resting the two dumbbells on your thighs, feet planted on the floor. \n " << endl;
                    cout << " Step Four - Lie back on the bench, extending your arms out above you as you do so, making sure your feet are still planted on the ground.Elbows should be soft and not locked out. \n " << endl;
                    cout << " Step Five - Start the movement by flexing your elbows, lowering the dumbbells' heads toward your ears, keeping your upper arms as still as possible. \n " << endl;
                    cout << " Step Six - When the weight is level with your ears, pause, then extend the forearms back to the starting position, squeezing your triceps at the extension. \n" << endl;
                    cout << " Repeat Steps. \n " << endl;
                };
                if (armexcersise == 2) {
                    cout << "You selected Cable Tricep Extension. \n" << endl;
                    cout << "Here is the steps to completing this excercise. \n" << endl;
                    cout << " Step One - Set up the cable to the highest setting on the tower with a rope attachment (or other attachment of your choice).\n " << endl;
                    cout << " Step Two - Stand with feet shoulder - width apart, facing the cable, taking hold of the rope in a pronated grip. \n" << endl;
                    cout << " Step Three -  Brace your core and keep your elbows close to your sides. \n " << endl;
                    cout << " Step Four - Press the rope handles down toward your outer thighs. \n " << endl;
                    cout << " Step Five - When your arms are fully extended, pause, squeezing your triceps. \n " << endl;
                    cout << " Step Six - Slowly return to the starting position, bending your elbows to bring your forearms back up. \n" << endl;
                    cout << " Repeat Steps. \n " << endl;
                };
                if (armexcersise == 3) {
                    cout << "You selected Overhead Tricep Extension. \n" << endl;
                    cout << "Here is the steps to completing this excercise. \n" << endl;
                    cout << " Step One - Grip the handle of the dumbbell in one hand.\n " << endl;
                    cout << " Step Two - Move your feet into a shoulder-width stance, engaging your core by bracing your stomach. \n" << endl;
                    cout << " Step Three -  Lift the dumbbell above your head, fully extending your arm so your upper arm is next to your ear, knuckles facing the ceiling. \n " << endl;
                    cout << " Step Four - Begin the movement by bending your elbow to lower the dumbbell behind your head. \n " << endl;
                    cout << " Step Five - Your upper arm should stay fixed beside your ear with only your forearm moving. \n " << endl;
                    cout << " Step Six - Once you have lowered as far as possible, pause, then extend your arm to return the dumbbell back to the starting position, squeezing your tricep as you extend. \n" << endl;
                    cout << " Repeat Steps. \n " << endl;
                };

            }
            if (workouttype == 2) {
                cout << "You selected Legs. \n" << endl;
                cout << " Select what Leg excercise you would like to do. \n" << endl;
                cout << "1 is Bulgarian Split-Squat . \n" << endl; // 
                cout << "2 is Barbell Hip Thrust. \n" << endl; //
                cout << "3 is Back Squats. \n" << endl; //
                cout << "4 is Hack Squat. \n" << endl; //
                cout << "5 is Romanian Deadlift. \n" << endl; //Grab the bar just outside your hips with your feet around hip width (2).Imagine you have apples in your armpits and you can’t let them fall out.Slide your hips back and up whilst only letting your knees bend slightly.Allow the bar to glide down your thighs and your shoulders come over your toes.The bar will typically finish around the middle of your shins.
                cin >> legexcersise;
                if (legexcersise == 1) {
                    cout << "You selected Bulgarian Split-Squat. \n" << endl;
                    cout << "Here is the steps to completing this excercise. \n" << endl;
                    cout << " Step One - Grip the handle of the dumbbell in one hand.\n " << endl;
                    cout << " Step Two - Move your feet into a shoulder-width stance, engaging your core by bracing your stomach. \n" << endl;
                    cout << " Step Three -  Lift the dumbbell above your head, fully extending your arm so your upper arm is next to your ear, knuckles facing the ceiling. \n " << endl;
                    cout << " Step Four - Begin the movement by bending your elbow to lower the dumbbell behind your head. \n " << endl;
                    cout << " Step Five - Your upper arm should stay fixed beside your ear with only your forearm moving. \n " << endl;
                    cout << " Step Six - Once you have lowered as far as possible, pause, then extend your arm to return the dumbbell back to the starting position, squeezing your tricep as you extend. \n" << endl;
                    cout << " Repeat Steps. \n " << endl;
                };
                if (workouttype == 3) {
                    cout << "You selected Abs. \n" << endl;
                    cout << " Select what Ab excercise you would like to do. \n" << endl;
                    cout << "1 is Skull Crusher. \n" << endl;
                    cout << "2 is Cable Triceppush Down. \n" << endl;
                    cout << "3 is Overhead Tricep Extension. \n" << endl;
                    cout << "4 is Dumbbell Preacher Curl. \n" << endl; //Set up the bench at a 60-degree incline (one setting below fully upright). Select an appropriate weight dumbbell.Hold the dumbbell in one hand and stand behind the bench.Bring that arm over the top of the bench so the upper arm rests on the backrest, with your armpit hugging the top of the bench(you may have to bend your knees slightly).Start with your palm facing up, arm bent.Then begin the movement, by extending your forearm down as far as possible.Pause, then reverse the motion, curling the dumbbell up towards your shoulder.
                    cout << "5 is Barbell Bicep Curl . \n" << endl; //Select a preloaded bar of an appropriate weight, or load up a barbell with plates. Take hold of the bar in a supinated grip(palms up), shoulder - width apart.Stand with your arms fully extended, elbows by your side.Feet should be directly below hips, knees slightly bent, and shoulder blades retracted.Keeping your elbows in the same position(by your side), contract your biceps and curl the bar upwards through a full range of motion.Once your elbows are fully bent and the bar is near your shoulders, pause, squeezing your biceps as you do so.Then, slowly lower back to the starting position, arms fully extended.   
                    cout << "6 is Cable Bicep Curl. \n" << endl; // Set the cable to the bottom of the tower and attach a straight bar attachment. Set the weight by adjusting the pin.Take hold of the bar in both hands, with a supinated(underhand) grip.Take a step back from the tower, positioning your feet to shoulder width apart, keeping a soft knee.Arms should be extended, bar by your thighs. Begin the curl by engaging your core, and bending your elbows to move the bar towards your shoulders.Keep your elbows tucked into your sides and ensure only your forearms move. When you reach the top, pause, squeezing your biceps.Reverse the movement, slowly lowering back to the starting position, arms fully extended.Repeat.
                    cin >> abexcersise;
                };
                if (workouttype == 4) {
                    cout << "You selected Back. \n" << endl;
                    cout << " Select what Back excercise you would like to do. \n" << endl;
                    cout << "1 is Skull Crusher. \n" << endl;
                    cout << "2 is Cable Triceppush Down. \n" << endl;
                    cout << "3 is Overhead Tricep Extension. \n" << endl;
                    cout << "4 is Dumbbell Preacher Curl. \n" << endl; //Set up the bench at a 60-degree incline (one setting below fully upright). Select an appropriate weight dumbbell.Hold the dumbbell in one hand and stand behind the bench.Bring that arm over the top of the bench so the upper arm rests on the backrest, with your armpit hugging the top of the bench(you may have to bend your knees slightly).Start with your palm facing up, arm bent.Then begin the movement, by extending your forearm down as far as possible.Pause, then reverse the motion, curling the dumbbell up towards your shoulder.
                    cout << "5 is Barbell Bicep Curl . \n" << endl; //Select a preloaded bar of an appropriate weight, or load up a barbell with plates. Take hold of the bar in a supinated grip(palms up), shoulder - width apart.Stand with your arms fully extended, elbows by your side.Feet should be directly below hips, knees slightly bent, and shoulder blades retracted.Keeping your elbows in the same position(by your side), contract your biceps and curl the bar upwards through a full range of motion.Once your elbows are fully bent and the bar is near your shoulders, pause, squeezing your biceps as you do so.Then, slowly lower back to the starting position, arms fully extended.
                    cout << "6 is Cable Bicep Curl. \n" << endl; // Set the cable to the bottom of the tower and attach a straight bar attachment. Set the weight by adjusting the pin.Take hold of the bar in both hands, with a supinated(underhand) grip.Take a step back from the tower, positioning your feet to shoulder width apart, keeping a soft knee.Arms should be extended, bar by your thighs. Begin the curl by engaging your core, and bending your elbows to move the bar towards your shoulders.Keep your elbows tucked into your sides and ensure only your forearms move. When you reach the top, pause, squeezing your biceps.Reverse the movement, slowly lowering back to the starting position, arms fully extended.Repeat.
                    cin >> backexcersise;
                };
                if (workouttype == 5) {
                    cout << "You selected Sholders. \n" << endl;
                    cout << " Select what Sholder excercise you would like to do. \n" << endl;
                    cout << "1 is Skull Crusher. \n" << endl;
                    cout << "2 is Cable Triceppush Down. \n" << endl;
                    cout << "3 is Overhead Tricep Extension. \n" << endl;
                    cout << "4 is Dumbbell Preacher Curl. \n" << endl; //Set up the bench at a 60-degree incline (one setting below fully upright). Select an appropriate weight dumbbell.Hold the dumbbell in one hand and stand behind the bench.Bring that arm over the top of the bench so the upper arm rests on the backrest, with your armpit hugging the top of the bench(you may have to bend your knees slightly).Start with your palm facing up, arm bent.Then begin the movement, by extending your forearm down as far as possible.Pause, then reverse the motion, curling the dumbbell up towards your shoulder.
                    cout << "5 is Barbell Bicep Curl . \n" << endl; //Select a preloaded bar of an appropriate weight, or load up a barbell with plates. Take hold of the bar in a supinated grip(palms up), shoulder - width apart.Stand with your arms fully extended, elbows by your side.Feet should be directly below hips, knees slightly bent, and shoulder blades retracted.Keeping your elbows in the same position(by your side), contract your biceps and curl the bar upwards through a full range of motion.Once your elbows are fully bent and the bar is near your shoulders, pause, squeezing your biceps as you do so.Then, slowly lower back to the starting position, arms fully extended.
                    cout << "6 is Cable Bicep Curl. \n" << endl; // Set the cable to the bottom of the tower and attach a straight bar attachment. Set the weight by adjusting the pin.Take hold of the bar in both hands, with a supinated(underhand) grip.Take a step back from the tower, positioning your feet to shoulder width apart, keeping a soft knee.Arms should be extended, bar by your thighs. Begin the curl by engaging your core, and bending your elbows to move the bar towards your shoulders.Keep your elbows tucked into your sides and ensure only your forearms move. When you reach the top, pause, squeezing your biceps.Reverse the movement, slowly lowering back to the starting position, arms fully extended.Repeat.
                    cin >> sholderexcersise;
                };


                userAccount.logout();
                return 0;
            }
        }

        Goal userGoal("Weight Loss", 10.0f);
        userGoal.defineGoal();

        User user(1, "John Doe", 28, 80.0f, "Beginner");
        user.setGoal(&userGoal);

        Workout workout(101, "Morning Routine", "Strength", 3);
        workout.chooseWorkout();

        Exercise exercise("Push-up", 3, 12, 30.0f);
        exercise.displayInstruction();
        exercise.performExercise();

        ProgressTracker tracker(200.0f, 5000, 45.0f);
        tracker.logProgress();
        tracker.syncData();

        MotivationalTool motivator("Timer");
        motivator.startTimer();
        motivator.playMusic();
        motivator.giveReward();

    }
