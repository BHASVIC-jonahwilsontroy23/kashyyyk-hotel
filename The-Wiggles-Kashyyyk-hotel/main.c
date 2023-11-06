//notes section:
//ben will try to break out code, so make sure to add validation checks!
//need to have the profile data stored on the computer itself.
//checkout will use temp variables and update global on finish, while the others can use global variables in the funcs.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


#define maxStringVariables 3
#define maxIntegerVariables 6
char userCharArray[6][maxStringVariables][64];
int userIntArray[6][maxIntegerVariables];

//variable dictionary:
//userCharArray[profile][which var]'s variables:
// name -> [0]
// surname -> [1]
// bookingID -> [2]
//

//userIntArray[profile][which var]'s   variables:
// child guest count -> [0]
// adult guest count -> [1]
// length of stay -> [2]
// board type (FB=0, HB=1, BB=2)-> [3]
// daily newspaper option -> [4]
// Date of birth -> [5]
//Room number -> [6]

//userRoomArray[room][in use]
//1 - in use
//0 - not in use

int bookingIDRetriever() {
    char enteredBookingID[68];
    int profile;
    int done = 0;
    fflush(stdin);
    do {
        printf("Enter bookingID (or 'exit' to exit): ");
        scanf("%64s", enteredBookingID);
        printf("Input = %s\n", enteredBookingID);
        for (int i = 0; i < 6; i++) {
            if (strcmp(enteredBookingID, userCharArray[i][2])) {
                profile = i;
                printf(">Match found with profile %d.", i);
                done = 1;
            } else if (strcmp(enteredBookingID, "exit")) {
                profile = 10;
                done = 1;
            } else {
                printf("Try again.\n");
            }
        }
    } while (!done);
    return profile;
}

void ArraychildGC(int profile) {
    printf("how many children are included in your booking?");
    fflush(stdin);
    scanf("%d", &userIntArray[profile][0]);
}
void ArrayAdultGC(int profile){
    printf("how many adults are in your booking?");
    fflush(stdin);
    scanf("%d",&userIntArray[profile][1]);
}
void ArrayLengthOS(int profile){
    printf("how long are you staying for?");
    fflush(stdin);
    scanf("%d", &userIntArray[profile][2]);
}
void BoardType(int profile) {
    printf("what tyoe of stay are you having? please enter BB/FB/HB");
    fflush(stdin);



}
//function area
int checkIn(int roomsOccupied) {
    //ed
    // Key: userCharArray[profile][which var][which letter of string]
    // Key: userIntArray[profile][variable]
    int profile = bookingIDRetriever();
    if (profile == 10) {
        exit(0);
    }


    //at any point, an input of 0 or e (your choice) will clear and exits the function by using "return roomsOccupied"

    // strcpy(userCharArray[2][2], "Smith9999"); // this is how to ammend the string var bookingID for profile 3. prolly.

    //task list:
    //exit immediately if all rooms are full.
    //take name, and surname  as char array inputs
    //take child guests, adult guests, length of stay, board type, daily newspaper option, and Date of birth (in days since year 0)  as integer array inputs
    //display room options
    //take room choice input
    //update room info and profile info.

    fflush(stdin);

    printf("how many children are included in your booking?");
    scanf("%d", &userIntArray[profile][0]);
    printf("how many adults are in your booking?");
    scanf("%d",&userIntArray[profile][1]);
    printf("how long are you staying for?");
    scanf("%d", &userIntArray[profile][2]);
    printf("what type of booking do you have? FB=0 HB=1 BB=2");
    scanf("%d",&userIntArray[profile][2]);
    printf("would you like a daily newspaper? yes=1 no=0")
    scanf("%d",&userIntArray[profile][3])
    printf("what is your DOB? please write in format: ddmmyyyy")
    scanf("%d",&userIntArray[profile][4])
    



    int profile = roomsOccupied;
    ArraychildGC(profile);

    //booking id ranodm number will be 4 digits long

    roomsOccupied++; //this is an easy way to check how many rooms are used. you can replace this with a different system if you'd like.
    return(roomsOccupied);
}

void checkOut() {
    //christian
    // Key: userCharArray[profile][which var][which letter of string]
    // Key: userIntArray[profile][variable]
    int profile = bookingIDRetriever();
    if (profile == 10) {
        exit(0);
    }

    //at any point, an input of 0 or e (your choice) will exit the function by using "return 0


    char BookingID = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int namePos = 0;
    int sNamePos = 0;
    int idPos = 0;
    bool idFound = false;

    int cost = 0;




    //task list:
    //figure out which profile to check out by asking for bookingID, and checking for matches



    //calculate total cost of room

    else if (userIntArray[6]==1 || userIntArray[6]==2)
    {
        cost = 100
    }
    else if (userIntArray[6]==3)
    {
        cost = 85
    }
    else if (userIntArray[6]==4 || userIntArray[6]==5)
    {
        cost = 75
    }
    else if (userIntArray[6]==6)
    {
        cost = 50
    }

}







    // calculate  total cost of parties board (meal)
    //if had daily newspapers add 5.50
    //if user age > 65 10% discount on the room rate
    // if any guests are 16 and under 50% discount on board rate for them

    //show users booing id and main guests name
    //each of the subtotals amounts frm amove where it is tleast >0
    //display overall bill
    //update room occupancy and profile info.

    //nice job!

    if (userIntArray[profile][4] == 1) {

}


void bookTable() {
    //jonah

    char enteredBookingID[68];
    int profile;
    for (int i=0;i<6;i++) {
        fflush(stdin);

        printf("Enter bookingID: ")
        scanf("%s", enteredBookingID);
        strcpy(userCharArray[2][2], "Smith9999");
        printf("\n [2][2] = %s", userCharArray[2][2]);
        if (strcmp(enteredBookingID, userCharArray[i][2])) {
            profile = i;
        } else {
            profile = 10;
        }
    }
        printf("\n i = %d",profile);
    // Key: userCharArray[profile][which var][which letter of string]
    // Key: userIntArray[profile][variable]

    //at any point, an input of 0 or e (your choice) will exit the function by using "return 0"


    //task list:
    // store tables: tatooine [0], endor [1], naboo [2] -> int tables[3]
    //take and validate booking id
    // if (userIntArray[profile][3] == 2) then exit
    //


}

//main
int main() {
    //declaring variables and other shiz
    char choice = 'x';
    int roomsOccupied = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            userIntArray[i][j] = j;
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 64; k++) {
                userCharArray[i][j][k] = k;
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 1; j++) {
            userRoomArray = 0;
        }



    while (1) {           // choice loop
        printf("\nChoose a function (i to check in, o to check out, or b to book a table):\n");
        scanf(" %c", &choice);
        if (choice == 'i') {          // check in
            //ed
            printf(">Checking in...\n");
            roomsOccupied = checkIn(roomsOccupied);
        }
        else if (choice == 'o') {   // check out
            //christian
            printf("\n>Checking out...");
            checkOut();
        }
        else if (choice == 'b') {   // booking a table
            //jonah
            printf("\n>Booking in...");
            bookTable();
        }
        else {                   //invalid input
            printf("\n>Invalid Input. Try again.");
        }
        //this is the end of while loop
    }
    return 0;
}
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