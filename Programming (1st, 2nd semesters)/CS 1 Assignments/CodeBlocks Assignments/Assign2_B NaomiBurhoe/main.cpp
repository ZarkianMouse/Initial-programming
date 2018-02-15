/* Program: Fire! Fire! Copyright of Naomi Burhoe c.2016
Author: Naomi Burhoe
Purpose: To determine of a certain class size exceeds the maximum
number of people allowed in a particular classroom at any one time
*/
#include <iostream>

using namespace std;

int main()
{
   //creating the repetitive loop for menu selection
    bool repeatingLoop = true;
    cout << "We are determining if different class sizes can be placed\nin designated classrooms ";
    cout << "based on the maximum capacity\nof the room, as determined by fire safety regulations\n\n";

   // let us begin the program
   while(repeatingLoop) {
    // these constants represent the max number of people allowed in designated rooms at any one time
        const int LH312 = 42;
        const int CAS41 = 44;
        const int KH133 = 38;

        // variable for room designation in menu
        int chosenRoom;

        // creating the menu selection

        cout << "Choose a room from the following based on max capacity: \n";
        cout << "Leigh Hall room 312 = 42\n";
        cout << "College of Arts and Sciences room 41 = 44\n";
        cout << "Kolbe Hall room 133 = 38\n";
        cin >> chosenRoom;

        // variable for people to attend class in designated room
        int peopleInRoom;
        int peopleLeft;

        // menu selection output for Leigh Hall room 312
        if(chosenRoom == 42) {
            cout << "\nInput number of people to attend class: ";
            cin >> peopleInRoom;

            // determining if class size exceeds maximum capacity
            if(peopleInRoom > LH312) {
                cout << "Class cannot be held in Leigh Hall 312.";
            }
            else {
                cout << "Class can be held in Leigh Hall 312 as planned\n";

                // determining how many people can still be placed in class since it doesn't exceed max capacity
                peopleLeft = LH312 - peopleInRoom;
                cout << peopleLeft << " people can still be placed in class.\n";
            }
        }

        // menu selection output for College of Arts and Sciences room 41
        if(chosenRoom == 44) {
            cout << "\nInput number of people to attend class: ";
            cin >> peopleInRoom;

            // determining if class size exceeds maximum capacity
            if(peopleInRoom > CAS41) {
                cout << "Class cannot be held in College of Arts and Sciences room 4\n";
            }
            else {
                cout << "Class can be held in College of Arts and Sciences room 41 as planned\n";

                // determining how many people can still be placed in class since it doesn't exceed max capacity
                peopleLeft = CAS41 - peopleInRoom;
                cout << peopleLeft << " people can still be placed in class.\n";
            }
        }
        // menu selection output for Leigh Hall room 312
        if(chosenRoom == 38) {
            cout << "\nInput number of people to attend class: ";
            cin >> peopleInRoom;

            // determining if class size exceeds maximum capacity
            if(peopleInRoom > KH133) {
                cout << "Class cannot be held in Kolbe Hall room 133\n";
            }
            else {
                cout << "Class can be held in Kolbe Hall room 133 as planned\n";

                // determining how many people can still be placed in class since it doesn't exceed max capacity
                peopleLeft = KH133 - peopleInRoom;
                cout << peopleLeft << " people can still be placed in class.\n";
            }
        }
    }


}
