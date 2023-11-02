#include <stdio.h>
#include <string.h>

//struct area (this is just to get all 6 profiles to work individually)
struct profile {
    char name[64];
    char surname[64];
    int childGuestCount;
    int adultGuestCount;
    int boardType;
};

//function area
char checkIn() {
    //ed
    char userCharArray[which var][which letter of string] //for this decleration, enter max possible array depth/length
    int userIntArray[each term has the variables value] //enter max int variables used for this decleration :0

    //at any point, an input of 0 or e (your choice) will exit the function by using "return 0" or "exit" i think :/

    //task list:
    //


    return userCharArray and the userIntArray somehow..
}

char checkOut() {
    //christian
    char userCharArray[which var][which letter of string] //for this decleration, enter max possible array depth/length
    int userIntArray[each term has the variables value] //enter max int variables used for this decleration :0

    //at any point, an input of 0 or e (your choice) will exit the function by using "return 0" or "exit" i think :/


    //task list:
    //calculate total cost of room
    // calculate  total cost of parties board (meal)
    //if had daily newspapers add 5.50
    //if user age > 65 10% discount on the room rate
    // if any guests are 16 and under 50% discount on board rate for them

    //show users booing id and main guests name
    //each of the subtotals amounts frm amove where it is tleast >0
    //overall bill

    //

    //nice job!



    return userCharArray and the userIntArray somehow..
}

char bookTable() {
    //jonah
    char userCharArray[which var][which letter of string] //for this decleration, enter max possible array depth/length
    int userIntArray[each term has the variables value] //enter max int variables used for this decleration :0

    //at any point, an input of 0 or e (your choice) will exit the function by using "return 0" or "exit" i think :/


    //task list:
    // store tables: tatooine, endor, naboo

    return userCharArray and the userIntArray somehow..
}

//main
int main() {
    //declaring variables and other shiz
    char choice = 'x';

    //
    //hotel program loop
    while (1) {
        printf("\nChoose a function (i to check in, o to check out, or b to book a table): ");
        scanf("%c", &choice);

        if (choice == 'i') {          // check in
            //ed
            printf("\n>Checking in...");
            checkIn();
            //set each char array term in the desired profile to the function's
            //set each int array term in the desired profile to the function's

        } else if (choice == 'o') {   // check out
            //christian
            printf("\n>Checking out...");
            checkOut();
            //set each char array term in the desired profile to the function's
            //set each int array term in the desired profile to the function's

        } else if (choice == 'b') {   // booking a table
            //jonah
            printf("\n>Booking in...");
            bookTable();
            //set each char array term in the desired profile to the function's
            //set each int array term in the desired profile to the function's

        } else {                   //invalid input
            printf("\n>Invalid Input. Try again.");
        }



        //this is the end of while loop
    }
    return 0;
}

//notes section:
//ben will try to break out code, so make sure to add validation checks!
//need to have the profile data stored on the computer itself.


//test
//hello there ed and christian
// hello there
//car
//tractor
//jesus                         chic fil a
//balls
//chicken fingers
// // //
//

int main2() {   // for testing purposes
    char userProfile_char[which profile][which var][stores th rest strings];
    int userProfile_int[profiles][which variable];
    char tables[][]

    return 0;
}