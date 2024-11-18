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

        cout << "Please select what type of excersise you would like to do today: \n " << endl;
        cout << " 1 = arms \n 2 = legs \n 3 = abs \n 4 = back \n 5 = sholders " << endl;
        cin >> workouttype;
        if (workouttype == 1) {
            cout << "You selected Arms. \n" << endl;
            cout << " Select what arm excercise you would like to do. \n" << endl;
            cout << "1 is Skull Crusher. \n" << endl;
            cout << "2 is Cable Triceppush Down. \n" << endl;
            cout << "3 is Overhead Tricep Extension. \n" << endl;
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
            cout << "3 is Romanian Deadlift. \n" << endl;
            cin >> legexcersise;
            if (legexcersise == 1) {
                cout << "You selected Bulgarian Split-Squat. \n" << endl;
                cout << "Here is the steps to completing this excercise. \n" << endl;
                cout << " Step One - Stand perpendicular to a flat bench (or box), 2-4 feet out from it, depending on your leg length. Hinge forward to pick up the dumbbells (if opting to use them), holding one in each hand, arms fully extended by your side.\n " << endl;
                cout << " Step Two - Take one leg back, resting the tops of your shoelaces on the bench top. Brace your core, keep your chest proud, and squeeze your shoulder blades together to stabilize yourself. Keep your eyes focused on a spot ahead of you. \n" << endl;
                cout << " Step Three -  Lower yourself down, bending the front leg, aiming to get the back knee close to the ground, but not touching it. In the bottom position, your front leg should be bent at a 90-degree angle, quad parallel to the floor, knee in line with toe. Keep your chest up and core braced throughout. \n " << endl;
                cout << " Step Four - Pause, then reverse the movement, pushing through your front foot and squeezing your glutes to drive yourself back to the starting position, straightening the front leg but not locking it out at the top. \n " << endl;
                cout << " Step Five - Repeat for the desired rep range, then swap legs. \n " << endl;
                cout << " Repeat Steps. \n " << endl;
            };
            if (legexcersise == 2) {
                cout << "You selected Barbell Hip Thrust. \n" << endl;
                cout << "Here is the steps to completing this excercise. \n" << endl;
                cout << " Step One -Keep the bench in its horizontal setting, making sure it's resting against a solid surface (like a wall), so that it won't move. Sit on the floor resting your upper back against the side of the bench and place your feet flat on the ground, between hip-width and shoulder-width apart, at a 90-degree angle.\n " << endl;
                cout << " Step Two - Place the barbell (or dumbbell if using) over your hips. \n" << endl;
                cout << " Step Three -  Brace your core, keep your head neutral and chin slightly tucked with your hands resting on top of the barbell. \n " << endl;
                cout << " Step Four - Push the floor away by driving through your heels and extending your hips towards the ceiling. Squeeze your glutes at the top of the contraction without overextending the lower back. \n " << endl;
                cout << " Step Five - Lower your hips, returning your bum to the floor in a controlled manner, keeping your upper back against the bench throughout. \n " << endl;
                cout << " Repeat Steps. \n " << endl;
            };
            if (legexcersise == 3) {
                cout << "You selected Romanian Deadlift. \n" << endl;
                cout << "Here is the steps to completing this excercise. \n" << endl;
                cout << " Step One - Imagine you have apples in your armpits and you can’t let them fall out.\n " << endl;
                cout << " Step Two - Move your feet into a shoulder-width stance, engaging your core by bracing your stomach. \n" << endl;
                cout << " Step Three - Slide your hips back and up whilst only letting your knees bend slightly. \n " << endl;
                cout << " Step Four - Allow the bar to glide down your thighs and your shoulders come over your toes. \n " << endl;
                cout << " Step Five - The bar will typically finish around the middle of your shins. \n " << endl;
                cout << " Repeat Steps. \n " << endl;
            };
            if (workouttype == 3) {
                cout << "You selected Abs. \n" << endl;
                cout << " Select what Ab excercise you would like to do. \n" << endl;
                cout << "1 is Crunches. \n" << endl;
                cout << "2 is Russuan Twists. \n" << endl;
                cout << "3 is Cable Crunches. \n" << endl;
                cin >> abexcersise;
                if (abexcersise == 1) {
                    cout << "You selected Crunches. \n" << endl;
                    cout << "Here is the steps to completing this excercise. \n" << endl;
                    cout << " Step One - Lie on your back with your knees bent at a 90-degree angle, feet flat on the floor, lower back in contact with the mat.\n " << endl;
                    cout << " Step Two - Placing your arms on your thighs, take a breath in, bracing your core. \n" << endl;
                    cout << " Step Three -  Lift your shoulder blades up, exhaling as you rise, crunching’ your abs. Your hands should move up your thighs towards your knees, keeping your chin tucked as you do so. \n " << endl;
                    cout << " Step Four - Lower back to the starting position, exhaling. \n " << endl;
                    cout << " Repeat Steps. \n " << endl;
                };
                if (abexcersise == 2) {
                    cout << "You selected Russuan Twists. \n" << endl;
                    cout << "Here is the steps to completing this excercise. \n" << endl;
                    cout << " Step One - Select an appropriately weighted med ball, kettlebell, or sandbag. \n " << endl;
                    cout << " Step Two - Sit on the floor with your knees bent, feet on the floor, holding the weight close in front of your chest. \n" << endl;
                    cout << " Step Three - Lean back slightly, lifting your feet off the floor so your legs form a V-shape. \n " << endl;
                    cout << " Step Four - Brace your core and rotate your torso, moving the weight to one side of your body. Bring it down so it is level with your hip, but not touching the ground. Keep your gaze fixed on the weight as you move it. \n " << endl;
                    cout << " Step Five - Pause, then return the weight to the center, before moving it down towards the other hip. \n " << endl;
                    cout << " Step Six - Return back to center. This counts as one rep. \n" << endl;
                    cout << " Repeat Steps. \n " << endl;
                };
                if (abexcersise == 3) {
                    cout << "You selected Cable Crunches. \n" << endl;
                    cout << "Here is the steps to completing this excercise. \n" << endl;
                    cout << " Step One - Set the cable machine up to the top of the tower and attach the rope attachment. \n " << endl;
                    cout << " Step Two - Take hold of the end of the ropes in both hands, taking a couple of steps away from the tower to move the weights off the stack whilst turning to face away from it. Kneel down, placing both knees on the floor directly below shoulders. \n" << endl;
                    cout << " Step Three - Hold the rope handles above the top of your head in an overhand grip, thumbs facing the ceiling. \n " << endl;
                    cout << " Step Four - Begin the crunch by bracing your core and taking a breath in. Hinge from your hips, breathing out as you contract for abs and curl your torso towards the ground. The rope should remain above your head at all times, chin tucked (imagine you are trying to hold an egg under your chin!) \n " << endl;
                    cout << " Step Five - Aim to lower until your elbows are close to your legs, squeezing your abs the whole time. \n " << endl;
                    cout << " Step Six - Pause, then slowly extend your torso to come back to starting position. \n" << endl;
                    cout << " Repeat Steps. \n " << endl;
                };
            };
            if (workouttype == 4) {
                cout << "You selected Back. \n" << endl;
                cout << " Select what Back excercise you would like to do. \n" << endl;
                cout << "1 is Bent Over Barbell Row. \n" << endl;
                cout << "2 is Pull Ups . \n" << endl;
                cout << "3 is Dumbbell Shrugs. \n" << endl;
                cin >> backexcersise;
                if (backexcersise == 1) {
                    cout << "You selected Bent Over Barbell Row. \n" << endl;
                    cout << "Here is the steps to completing this excercise. \n" << endl;
                    cout << " Step One - Assume a standing position while holding a dumbbell in each hand with a neutral grip. \n " << endl;
                    cout << " Step Two - Hinge forward until your torso is roughly parallel with the floor (or slightly above) and then begin the movement by driving the elbows behind the body while retracting the shoulder blades. \n" << endl;
                    cout << " Step Three - Pull the dumbbells towards your body until the elbows are at (or just past) the midline and then slowly lower the dumbbells back to the starting position under control. \n " << endl;
                    cout << " Repeat Steps. \n " << endl;
                };
                if (backexcersise == 2) {
                    cout << "You selected Pull Ups. \n" << endl;
                    cout << "Here is the steps to completing this excercise. \n" << endl;
                    cout << " Step One - Start with your hands on the bar approximately shoulder-width apart with your palms facing forward. \n " << endl;
                    cout << " Step Two - With arms extended above you, stick your chest out and curve your back slightly. That is your starting position.  \n" << endl;
                    cout << " Step Three - Pull yourself up towards the bar using your back until the bar is at chest level while breathing out.   \n " << endl;
                    cout << " Step Four - Slowly lower yourself to the starting position while breathing in. That is one rep. \n " << endl;
                    cout << " Repeat Steps. \n " << endl;
                };
                if (backexcersise == 3) {
                    cout << "You selected Dumbbell Shrugs. \n" << endl;
                    cout << "Here is the steps to completing this excercise. \n" << endl;
                    cout << " Step One - Assume a standing position with the dumbbells on both sides of your body.\n " << endl;
                    cout << " Step Two - Hinge forward, inhale, and grab the dumbbells with a neutral grip. \n" << endl;
                    cout << " Step Three - Stand up tall and ensure your spine remains neutral.  \n " << endl;
                    cout << " Step Four - Contract the traps to elevate the shoulders. Squeeze hard at the top and slowly lower the dumbbells back to the starting position. \n " << endl;
                    cout << " Repeat Steps. \n " << endl;
                };
            };
            if (workouttype == 5) {
                cout << "You selected Sholders. \n" << endl;
                cout << " Select what Sholder excercise you would like to do. \n" << endl;
                cout << "1 is Overhead Press. \n" << endl;
                cout << "2 is Lateral Raises. \n" << endl;
                cout << "3 is Shrugs. \n" << endl;
                cin >> sholderexcersise;
                if (sholderexcersise == 1) {
                    cout << "You selected Overhead Press. \n" << endl;
                    cout << "Here is the steps to completing this excercise. \n" << endl;
                    cout << " Step One - Stand with the bar on your front shoulders. Narrow grip, straight wrists, vertical forearms. Lock your knees and hips.\n " << endl;
                    cout << " Step Two - Raise your chest towards the ceiling by arching your upper-back. Try to touch your chin with your upper-chest. \n" << endl;
                    cout << " Step Three - Take a big breath, hold it, and press the bar in a vertical line. Don’t press it in front or behind your head. Press it over your head.  \n " << endl;
                    cout << " Step Four - Stay close to the bar while you press the weight up. Shift your torso forward once the bar has passed your forehead. \n " << endl;
                    cout << " Step Five - Hold the bar over your shoulders and mid-foot for proper balance. Lock your elbows. Shrug your shoulders to the ceiling. \n " << endl;
                    cout << " Repeat Steps. \n " << endl;
                };
                if (sholderexcersise == 2) {
                    cout << "You selected Lateral Raises. \n" << endl;
                    cout << "Here is the steps to completing this excercise. \n" << endl;
                    cout << " Step One - Select the desired weight from the rack, then take a few steps back into an open area.\n " << endl;
                    cout << " Step Two - Take a deep breath and raise the dumbbells to shoulder height using a neutral grip (palms facing in) while keeping the elbows slightly bent. \n" << endl;
                    cout << " Step Three - Slowly lower the dumbbells back to the starting position under control.  \n " << endl;
                    cout << " Repeat Steps. \n " << endl;
                };
                if (sholderexcersise == 3) {
                    cout << "You selected Shrugs. \n" << endl;
                    cout << "Here is the steps to completing this excercise. \n" << endl;
                    cout << " Step One - Choose an appropriate dumbbell weight\n " << endl;
                    cout << " Step Two - With a dumbbell in each hand, stand up tall with slightly soft knees. \n" << endl;
                    cout << " Step Three - Maintain a neutral posture and relaxed arms.  \n " << endl;
                    cout << " Step Four - Shrug your shoulders, aiming to bring the cap of your shoulder up towards your ear. \n " << endl;
                    cout << " Step Five - Be sure to focus on elevating the traps, rather than retracting your neck/chin. \n " << endl;
                    cout << " Step Six - Slowly lower your shoulders back to the start position. \n" << endl;
                    cout << " Repeat Steps. \n " << endl;
                };
            };

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

            cout << "Please select what type of excersise you would like to do today: \n " << endl;
            cout << " 1 = arms \n 2 = legs \n 3 = abs \n 4 = back \n 5 = sholders " << endl;
            cin >> workouttype;
            if (workouttype == 1) {
                cout << "You selected Arms. \n" << endl;
                cout << " Select what arm excercise you would like to do. \n" << endl;
                cout << "1 is Skull Crusher. \n" << endl;
                cout << "2 is Cable Triceppush Down. \n" << endl;
                cout << "3 is Overhead Tricep Extension. \n" << endl;
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
                cout << "3 is Romanian Deadlift. \n" << endl;
                cin >> legexcersise;
                if (legexcersise == 1) {
                    cout << "You selected Bulgarian Split-Squat. \n" << endl;
                    cout << "Here is the steps to completing this excercise. \n" << endl;
                    cout << " Step One - Stand perpendicular to a flat bench (or box), 2-4 feet out from it, depending on your leg length. Hinge forward to pick up the dumbbells (if opting to use them), holding one in each hand, arms fully extended by your side.\n " << endl;
                    cout << " Step Two - Take one leg back, resting the tops of your shoelaces on the bench top. Brace your core, keep your chest proud, and squeeze your shoulder blades together to stabilize yourself. Keep your eyes focused on a spot ahead of you. \n" << endl;
                    cout << " Step Three -  Lower yourself down, bending the front leg, aiming to get the back knee close to the ground, but not touching it. In the bottom position, your front leg should be bent at a 90-degree angle, quad parallel to the floor, knee in line with toe. Keep your chest up and core braced throughout. \n " << endl;
                    cout << " Step Four - Pause, then reverse the movement, pushing through your front foot and squeezing your glutes to drive yourself back to the starting position, straightening the front leg but not locking it out at the top. \n " << endl;
                    cout << " Step Five - Repeat for the desired rep range, then swap legs. \n " << endl;
                    cout << " Repeat Steps. \n " << endl;
                };
                if (legexcersise == 2) {
                    cout << "You selected Barbell Hip Thrust. \n" << endl;
                    cout << "Here is the steps to completing this excercise. \n" << endl;
                    cout << " Step One -Keep the bench in its horizontal setting, making sure it's resting against a solid surface (like a wall), so that it won't move. Sit on the floor resting your upper back against the side of the bench and place your feet flat on the ground, between hip-width and shoulder-width apart, at a 90-degree angle.\n " << endl;
                    cout << " Step Two - Place the barbell (or dumbbell if using) over your hips. \n" << endl;
                    cout << " Step Three -  Brace your core, keep your head neutral and chin slightly tucked with your hands resting on top of the barbell. \n " << endl;
                    cout << " Step Four - Push the floor away by driving through your heels and extending your hips towards the ceiling. Squeeze your glutes at the top of the contraction without overextending the lower back. \n " << endl;
                    cout << " Step Five - Lower your hips, returning your bum to the floor in a controlled manner, keeping your upper back against the bench throughout. \n " << endl;
                    cout << " Repeat Steps. \n " << endl;
                };
                if (legexcersise == 3) {
                    cout << "You selected Romanian Deadlift. \n" << endl;
                    cout << "Here is the steps to completing this excercise. \n" << endl;
                    cout << " Step One - Imagine you have apples in your armpits and you can’t let them fall out.\n " << endl;
                    cout << " Step Two - Move your feet into a shoulder-width stance, engaging your core by bracing your stomach. \n" << endl;
                    cout << " Step Three - Slide your hips back and up whilst only letting your knees bend slightly. \n " << endl;
                    cout << " Step Four - Allow the bar to glide down your thighs and your shoulders come over your toes. \n " << endl;
                    cout << " Step Five - The bar will typically finish around the middle of your shins. \n " << endl;
                    cout << " Repeat Steps. \n " << endl;
                };
                if (workouttype == 3) {
                    cout << "You selected Abs. \n" << endl;
                    cout << " Select what Ab excercise you would like to do. \n" << endl;
                    cout << "1 is Crunches. \n" << endl;
                    cout << "2 is Russuan Twists. \n" << endl;
                    cout << "3 is Cable Crunches. \n" << endl;
                    cin >> abexcersise;
                    if (abexcersise == 1) {
                        cout << "You selected Crunches. \n" << endl;
                        cout << "Here is the steps to completing this excercise. \n" << endl;
                        cout << " Step One - Lie on your back with your knees bent at a 90-degree angle, feet flat on the floor, lower back in contact with the mat.\n " << endl;
                        cout << " Step Two - Placing your arms on your thighs, take a breath in, bracing your core. \n" << endl;
                        cout << " Step Three -  Lift your shoulder blades up, exhaling as you rise, crunching’ your abs. Your hands should move up your thighs towards your knees, keeping your chin tucked as you do so. \n " << endl;
                        cout << " Step Four - Lower back to the starting position, exhaling. \n " << endl;
                        cout << " Repeat Steps. \n " << endl;
                    };
                    if (abexcersise == 2) {
                        cout << "You selected Russuan Twists. \n" << endl;
                        cout << "Here is the steps to completing this excercise. \n" << endl;
                        cout << " Step One - Select an appropriately weighted med ball, kettlebell, or sandbag. \n " << endl;
                        cout << " Step Two - Sit on the floor with your knees bent, feet on the floor, holding the weight close in front of your chest. \n" << endl;
                        cout << " Step Three - Lean back slightly, lifting your feet off the floor so your legs form a V-shape. \n " << endl;
                        cout << " Step Four - Brace your core and rotate your torso, moving the weight to one side of your body. Bring it down so it is level with your hip, but not touching the ground. Keep your gaze fixed on the weight as you move it. \n " << endl;
                        cout << " Step Five - Pause, then return the weight to the center, before moving it down towards the other hip. \n " << endl;
                        cout << " Step Six - Return back to center. This counts as one rep. \n" << endl;
                        cout << " Repeat Steps. \n " << endl;
                    };
                    if (abexcersise == 3) {
                        cout << "You selected Cable Crunches. \n" << endl;
                        cout << "Here is the steps to completing this excercise. \n" << endl;
                        cout << " Step One - Set the cable machine up to the top of the tower and attach the rope attachment. \n " << endl;
                        cout << " Step Two - Take hold of the end of the ropes in both hands, taking a couple of steps away from the tower to move the weights off the stack whilst turning to face away from it. Kneel down, placing both knees on the floor directly below shoulders. \n" << endl;
                        cout << " Step Three - Hold the rope handles above the top of your head in an overhand grip, thumbs facing the ceiling. \n " << endl;
                        cout << " Step Four - Begin the crunch by bracing your core and taking a breath in. Hinge from your hips, breathing out as you contract for abs and curl your torso towards the ground. The rope should remain above your head at all times, chin tucked (imagine you are trying to hold an egg under your chin!) \n " << endl;
                        cout << " Step Five - Aim to lower until your elbows are close to your legs, squeezing your abs the whole time. \n " << endl;
                        cout << " Step Six - Pause, then slowly extend your torso to come back to starting position. \n" << endl;
                        cout << " Repeat Steps. \n " << endl;
                    };
                };
                if (workouttype == 4) {
                    cout << "You selected Back. \n" << endl;
                    cout << " Select what Back excercise you would like to do. \n" << endl;
                    cout << "1 is Bent Over Barbell Row. \n" << endl;
                    cout << "2 is Pull Ups . \n" << endl;
                    cout << "3 is Dumbbell Shrugs. \n" << endl;
                    cin >> backexcersise;
                    if (backexcersise == 1) {
                        cout << "You selected Bent Over Barbell Row. \n" << endl;
                        cout << "Here is the steps to completing this excercise. \n" << endl;
                        cout << " Step One - Assume a standing position while holding a dumbbell in each hand with a neutral grip. \n " << endl;
                        cout << " Step Two - Hinge forward until your torso is roughly parallel with the floor (or slightly above) and then begin the movement by driving the elbows behind the body while retracting the shoulder blades. \n" << endl;
                        cout << " Step Three - Pull the dumbbells towards your body until the elbows are at (or just past) the midline and then slowly lower the dumbbells back to the starting position under control. \n " << endl;
                        cout << " Repeat Steps. \n " << endl;
                    };
                    if (backexcersise == 2) {
                        cout << "You selected Pull Ups. \n" << endl;
                        cout << "Here is the steps to completing this excercise. \n" << endl;
                        cout << " Step One - Start with your hands on the bar approximately shoulder-width apart with your palms facing forward. \n " << endl;
                        cout << " Step Two - With arms extended above you, stick your chest out and curve your back slightly. That is your starting position.  \n" << endl;
                        cout << " Step Three - Pull yourself up towards the bar using your back until the bar is at chest level while breathing out.   \n " << endl;
                        cout << " Step Four - Slowly lower yourself to the starting position while breathing in. That is one rep. \n " << endl;
                        cout << " Repeat Steps. \n " << endl;
                    };
                    if (backexcersise == 3) {
                        cout << "You selected Dumbbell Shrugs. \n" << endl;
                        cout << "Here is the steps to completing this excercise. \n" << endl;
                        cout << " Step One - Assume a standing position with the dumbbells on both sides of your body.\n " << endl;
                        cout << " Step Two - Hinge forward, inhale, and grab the dumbbells with a neutral grip. \n" << endl;
                        cout << " Step Three - Stand up tall and ensure your spine remains neutral.  \n " << endl;
                        cout << " Step Four - Contract the traps to elevate the shoulders. Squeeze hard at the top and slowly lower the dumbbells back to the starting position. \n " << endl;
                        cout << " Repeat Steps. \n " << endl;
                    };
                };
                if (workouttype == 5) {
                    cout << "You selected Sholders. \n" << endl;
                    cout << " Select what Sholder excercise you would like to do. \n" << endl;
                    cout << "1 is Overhead Press. \n" << endl;
                    cout << "2 is Lateral Raises. \n" << endl;
                    cout << "3 is Shrugs. \n" << endl;
                    cin >> sholderexcersise;
                    if (sholderexcersise == 1) {
                        cout << "You selected Overhead Press. \n" << endl;
                        cout << "Here is the steps to completing this excercise. \n" << endl;
                        cout << " Step One - Stand with the bar on your front shoulders. Narrow grip, straight wrists, vertical forearms. Lock your knees and hips.\n " << endl;
                        cout << " Step Two - Raise your chest towards the ceiling by arching your upper-back. Try to touch your chin with your upper-chest. \n" << endl;
                        cout << " Step Three - Take a big breath, hold it, and press the bar in a vertical line. Don’t press it in front or behind your head. Press it over your head.  \n " << endl;
                        cout << " Step Four - Stay close to the bar while you press the weight up. Shift your torso forward once the bar has passed your forehead. \n " << endl;
                        cout << " Step Five - Hold the bar over your shoulders and mid-foot for proper balance. Lock your elbows. Shrug your shoulders to the ceiling. \n " << endl;
                        cout << " Repeat Steps. \n " << endl;
                    };
                    if (sholderexcersise == 2) {
                        cout << "You selected Lateral Raises. \n" << endl;
                        cout << "Here is the steps to completing this excercise. \n" << endl;
                        cout << " Step One - Select the desired weight from the rack, then take a few steps back into an open area.\n " << endl;
                        cout << " Step Two - Take a deep breath and raise the dumbbells to shoulder height using a neutral grip (palms facing in) while keeping the elbows slightly bent. \n" << endl;
                        cout << " Step Three - Slowly lower the dumbbells back to the starting position under control.  \n " << endl;
                        cout << " Repeat Steps. \n " << endl;
                    };
                    if (sholderexcersise == 3) {
                        cout << "You selected Shrugs. \n" << endl;
                        cout << "Here is the steps to completing this excercise. \n" << endl;
                        cout << " Step One - Choose an appropriate dumbbell weight\n " << endl;
                        cout << " Step Two - With a dumbbell in each hand, stand up tall with slightly soft knees. \n" << endl;
                        cout << " Step Three - Maintain a neutral posture and relaxed arms.  \n " << endl;
                        cout << " Step Four - Shrug your shoulders, aiming to bring the cap of your shoulder up towards your ear. \n " << endl;
                        cout << " Step Five - Be sure to focus on elevating the traps, rather than retracting your neck/chin. \n " << endl;
                        cout << " Step Six - Slowly lower your shoulders back to the start position. \n" << endl;
                        cout << " Repeat Steps. \n " << endl;
                    };
                };

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
                    cout << "3 is Romanian Deadlift. \n" << endl;
                    cin >> legexcersise;
                    if (legexcersise == 1) {
                        cout << "You selected Bulgarian Split-Squat. \n" << endl;
                        cout << "Here is the steps to completing this excercise. \n" << endl;
                        cout << " Step One - Stand perpendicular to a flat bench (or box), 2-4 feet out from it, depending on your leg length. Hinge forward to pick up the dumbbells (if opting to use them), holding one in each hand, arms fully extended by your side.\n " << endl;
                        cout << " Step Two - Take one leg back, resting the tops of your shoelaces on the bench top. Brace your core, keep your chest proud, and squeeze your shoulder blades together to stabilize yourself. Keep your eyes focused on a spot ahead of you. \n" << endl;
                        cout << " Step Three -  Lower yourself down, bending the front leg, aiming to get the back knee close to the ground, but not touching it. In the bottom position, your front leg should be bent at a 90-degree angle, quad parallel to the floor, knee in line with toe. Keep your chest up and core braced throughout. \n " << endl;
                        cout << " Step Four - Pause, then reverse the movement, pushing through your front foot and squeezing your glutes to drive yourself back to the starting position, straightening the front leg but not locking it out at the top. \n " << endl;
                        cout << " Step Five - Repeat for the desired rep range, then swap legs. \n " << endl;
                        cout << " Repeat Steps. \n " << endl;
                    };
                    if (legexcersise == 2) {
                        cout << "You selected Barbell Hip Thrust. \n" << endl;
                        cout << "Here is the steps to completing this excercise. \n" << endl;
                        cout << " Step One -Keep the bench in its horizontal setting, making sure it's resting against a solid surface (like a wall), so that it won't move. Sit on the floor resting your upper back against the side of the bench and place your feet flat on the ground, between hip-width and shoulder-width apart, at a 90-degree angle.\n " << endl;
                        cout << " Step Two - Place the barbell (or dumbbell if using) over your hips. \n" << endl;
                        cout << " Step Three -  Brace your core, keep your head neutral and chin slightly tucked with your hands resting on top of the barbell. \n " << endl;
                        cout << " Step Four - Push the floor away by driving through your heels and extending your hips towards the ceiling. Squeeze your glutes at the top of the contraction without overextending the lower back. \n " << endl;
                        cout << " Step Five - Lower your hips, returning your bum to the floor in a controlled manner, keeping your upper back against the bench throughout. \n " << endl;
                        cout << " Repeat Steps. \n " << endl;
                    };
                    if (legexcersise == 3) {
                        cout << "You selected Romanian Deadlift. \n" << endl;
                        cout << "Here is the steps to completing this excercise. \n" << endl;
                        cout << " Step One - Imagine you have apples in your armpits and you can’t let them fall out.\n " << endl;
                        cout << " Step Two - Move your feet into a shoulder-width stance, engaging your core by bracing your stomach. \n" << endl;
                        cout << " Step Three - Slide your hips back and up whilst only letting your knees bend slightly. \n " << endl;
                        cout << " Step Four - Allow the bar to glide down your thighs and your shoulders come over your toes. \n " << endl;
                        cout << " Step Five - The bar will typically finish around the middle of your shins. \n " << endl;
                        cout << " Repeat Steps. \n " << endl;
                    };
                    if (workouttype == 3) {
                        cout << "You selected Abs. \n" << endl;
                        cout << " Select what Ab excercise you would like to do. \n" << endl;
                        cout << "1 is Crunches. \n" << endl;
                        cout << "2 is Russuan Twists. \n" << endl;
                        cout << "3 is Cable Crunches. \n" << endl;
                        cin >> abexcersise;
                        if (abexcersise == 1) {
                            cout << "You selected Crunches. \n" << endl;
                            cout << "Here is the steps to completing this excercise. \n" << endl;
                            cout << " Step One - Lie on your back with your knees bent at a 90-degree angle, feet flat on the floor, lower back in contact with the mat.\n " << endl;
                            cout << " Step Two - Placing your arms on your thighs, take a breath in, bracing your core. \n" << endl;
                            cout << " Step Three -  Lift your shoulder blades up, exhaling as you rise, crunching’ your abs. Your hands should move up your thighs towards your knees, keeping your chin tucked as you do so. \n " << endl;
                            cout << " Step Four - Lower back to the starting position, exhaling. \n " << endl;
                            cout << " Repeat Steps. \n " << endl;
                        };
                        if (abexcersise == 2) {
                            cout << "You selected Russuan Twists. \n" << endl;
                            cout << "Here is the steps to completing this excercise. \n" << endl;
                            cout << " Step One - Select an appropriately weighted med ball, kettlebell, or sandbag. \n " << endl;
                            cout << " Step Two - Sit on the floor with your knees bent, feet on the floor, holding the weight close in front of your chest. \n" << endl;
                            cout << " Step Three - Lean back slightly, lifting your feet off the floor so your legs form a V-shape. \n " << endl;
                            cout << " Step Four - Brace your core and rotate your torso, moving the weight to one side of your body. Bring it down so it is level with your hip, but not touching the ground. Keep your gaze fixed on the weight as you move it. \n " << endl;
                            cout << " Step Five - Pause, then return the weight to the center, before moving it down towards the other hip. \n " << endl;
                            cout << " Step Six - Return back to center. This counts as one rep. \n" << endl;
                            cout << " Repeat Steps. \n " << endl;
                        };
                        if (abexcersise == 3) {
                            cout << "You selected Cable Crunches. \n" << endl;
                            cout << "Here is the steps to completing this excercise. \n" << endl;
                            cout << " Step One - Set the cable machine up to the top of the tower and attach the rope attachment. \n " << endl;
                            cout << " Step Two - Take hold of the end of the ropes in both hands, taking a couple of steps away from the tower to move the weights off the stack whilst turning to face away from it. Kneel down, placing both knees on the floor directly below shoulders. \n" << endl;
                            cout << " Step Three - Hold the rope handles above the top of your head in an overhand grip, thumbs facing the ceiling. \n " << endl;
                            cout << " Step Four - Begin the crunch by bracing your core and taking a breath in. Hinge from your hips, breathing out as you contract for abs and curl your torso towards the ground. The rope should remain above your head at all times, chin tucked (imagine you are trying to hold an egg under your chin!) \n " << endl;
                            cout << " Step Five - Aim to lower until your elbows are close to your legs, squeezing your abs the whole time. \n " << endl;
                            cout << " Step Six - Pause, then slowly extend your torso to come back to starting position. \n" << endl;
                            cout << " Repeat Steps. \n " << endl;
                        };
                    };
                    if (workouttype == 4) {
                        cout << "You selected Back. \n" << endl;
                        cout << " Select what Back excercise you would like to do. \n" << endl;
                        cout << "1 is Bent Over Barbell Row. \n" << endl;
                        cout << "2 is Pull Ups . \n" << endl;
                        cout << "3 is Dumbbell Shrugs. \n" << endl;
                        cin >> backexcersise;
                        if (backexcersise == 1) {
                            cout << "You selected Bent Over Barbell Row. \n" << endl;
                            cout << "Here is the steps to completing this excercise. \n" << endl;
                            cout << " Step One - Assume a standing position while holding a dumbbell in each hand with a neutral grip. \n " << endl;
                            cout << " Step Two - Hinge forward until your torso is roughly parallel with the floor (or slightly above) and then begin the movement by driving the elbows behind the body while retracting the shoulder blades. \n" << endl;
                            cout << " Step Three - Pull the dumbbells towards your body until the elbows are at (or just past) the midline and then slowly lower the dumbbells back to the starting position under control. \n " << endl;
                            cout << " Repeat Steps. \n " << endl;
                        };
                        if (backexcersise == 2) {
                            cout << "You selected Pull Ups. \n" << endl;
                            cout << "Here is the steps to completing this excercise. \n" << endl;
                            cout << " Step One - Start with your hands on the bar approximately shoulder-width apart with your palms facing forward. \n " << endl;
                            cout << " Step Two - With arms extended above you, stick your chest out and curve your back slightly. That is your starting position.  \n" << endl;
                            cout << " Step Three - Pull yourself up towards the bar using your back until the bar is at chest level while breathing out.   \n " << endl;
                            cout << " Step Four - Slowly lower yourself to the starting position while breathing in. That is one rep. \n " << endl;
                            cout << " Repeat Steps. \n " << endl;
                        };
                        if (backexcersise == 3) {
                            cout << "You selected Dumbbell Shrugs. \n" << endl;
                            cout << "Here is the steps to completing this excercise. \n" << endl;
                            cout << " Step One - Assume a standing position with the dumbbells on both sides of your body.\n " << endl;
                            cout << " Step Two - Hinge forward, inhale, and grab the dumbbells with a neutral grip. \n" << endl;
                            cout << " Step Three - Stand up tall and ensure your spine remains neutral.  \n " << endl;
                            cout << " Step Four - Contract the traps to elevate the shoulders. Squeeze hard at the top and slowly lower the dumbbells back to the starting position. \n " << endl;
                            cout << " Repeat Steps. \n " << endl;
                        };
                    };
                    if (workouttype == 5) {
                        cout << "You selected Sholders. \n" << endl;
                        cout << " Select what Sholder excercise you would like to do. \n" << endl;
                        cout << "1 is Overhead Press. \n" << endl;
                        cout << "2 is Lateral Raises. \n" << endl;
                        cout << "3 is Shrugs. \n" << endl;
                        cin >> sholderexcersise;
                        if (sholderexcersise == 1) {
                            cout << "You selected Overhead Press. \n" << endl;
                            cout << "Here is the steps to completing this excercise. \n" << endl;
                            cout << " Step One - Stand with the bar on your front shoulders. Narrow grip, straight wrists, vertical forearms. Lock your knees and hips.\n " << endl;
                            cout << " Step Two - Raise your chest towards the ceiling by arching your upper-back. Try to touch your chin with your upper-chest. \n" << endl;
                            cout << " Step Three - Take a big breath, hold it, and press the bar in a vertical line. Don’t press it in front or behind your head. Press it over your head.  \n " << endl;
                            cout << " Step Four - Stay close to the bar while you press the weight up. Shift your torso forward once the bar has passed your forehead. \n " << endl;
                            cout << " Step Five - Hold the bar over your shoulders and mid-foot for proper balance. Lock your elbows. Shrug your shoulders to the ceiling. \n " << endl;
                            cout << " Repeat Steps. \n " << endl;
                        };
                        if (sholderexcersise == 2) {
                            cout << "You selected Lateral Raises. \n" << endl;
                            cout << "Here is the steps to completing this excercise. \n" << endl;
                            cout << " Step One - Select the desired weight from the rack, then take a few steps back into an open area.\n " << endl;
                            cout << " Step Two - Take a deep breath and raise the dumbbells to shoulder height using a neutral grip (palms facing in) while keeping the elbows slightly bent. \n" << endl;
                            cout << " Step Three - Slowly lower the dumbbells back to the starting position under control.  \n " << endl;
                            cout << " Repeat Steps. \n " << endl;
                        };
                        if (sholderexcersise == 3) {
                            cout << "You selected Shrugs. \n" << endl;
                            cout << "Here is the steps to completing this excercise. \n" << endl;
                            cout << " Step One - Choose an appropriate dumbbell weight\n " << endl;
                            cout << " Step Two - With a dumbbell in each hand, stand up tall with slightly soft knees. \n" << endl;
                            cout << " Step Three - Maintain a neutral posture and relaxed arms.  \n " << endl;
                            cout << " Step Four - Shrug your shoulders, aiming to bring the cap of your shoulder up towards your ear. \n " << endl;
                            cout << " Step Five - Be sure to focus on elevating the traps, rather than retracting your neck/chin. \n " << endl;
                            cout << " Step Six - Slowly lower your shoulders back to the start position. \n" << endl;
                            cout << " Repeat Steps. \n " << endl;
                        };
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
    }
