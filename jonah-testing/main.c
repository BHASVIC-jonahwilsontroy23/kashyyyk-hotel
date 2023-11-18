//notes section:
//ben will try to break out code, so make sure to add validation checks!
//need to have the profile data stored on the computer itself.
//checkout will use temp variables and update global on finish, while the others can use global variables in the func
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>



#define maxStringVariables 3
#define maxIntegerVariables 8
#define maxRoomVariables 1
char userCharArray[6][maxStringVariables][64];
int userIntArray[6][maxIntegerVariables];
int userRoomArray[6][maxRoomVariables];

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
//meals orders -> [7]

//userRoomArray[room][in use]
//1 - in use
//0 - not in use

int bookingIDRetriever() {
    char enteredBookingID[68];
    int profile = 12;
    int done = 0;
    fflush(stdin);
    do {
        printf("Enter bookingID (or 'exit' to exit): ");
        scanf("%s", enteredBookingID);
        printf("Input = %s\n", enteredBookingID);
        for (int i = 0; i<6; i++) {
            if (!strcmp(enteredBookingID, userCharArray[i][2])) {
                profile = i;
                printf(">Match found with profile %d.", i);
                done = 1;
            }
        }

        if (!strcmp(enteredBookingID, "exit")) {
            profile = 11;
            done = 1;
        }
        if (!done) {
            printf("Try again.\n");
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

void checkIn() {
    printf("\n temp checking in\n");
}

void checkOut() {
    //christian
    // Key: userCharArray[profile][which var][which letter of string]
    // Key: userIntArray[profile][variable]
    int profile = bookingIDRetriever();
    if (profile > 10) {
        printf(">Exiting...\n");
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

    int totalCost = 0;
    int roomCost = 0;
    int boardCost = 0;
    int newsPaperCost =0;




    //task list:
    //figure out which profile to check out by asking for bookingID, and checking for matches



    //calculate total cost of room

    if (userIntArray[profile][6]==1 || userIntArray[profile][6]==2)
    {
        roomCost = 100;
    }
    else if (userIntArray[profile][6]==3)
    {
        roomCost = 85;
    }
    else if (userIntArray[profile][6]==4 || userIntArray[profile][6]==5)
    {
        roomCost = 75;
    }
    else if (userIntArray[profile][6]==6)
    {
        roomCost = 50;
    }

// calculate  total cost of parties board (meal)

    if (userIntArray[profile][3]==1)
    {
        boardCost=20*userIntArray[profile][2];
    }
    else if (userIntArray[profile][3]==2)
    {
        boardCost=15*userIntArray[profile][2];
    }
    else if (userIntArray[profile][3]==3)
    {
        boardCost=5*userIntArray[profile][2];
    }



    //if had daily newspapers add 5.50

    if (userIntArray[profile][4] == 1)
    {
        newsPaperCost = 5.5;
    }


    //if user age > 65 10% discount on the room rate

    if (userIntArray[profile][5]>65)
    {
        roomCost=roomCost*0.9;
    }


    // if any guests are 16 and under 50% discount on board rate for them

    boardCost=(userIntArray[profile][1]*boardCost)+(userIntArray[profile][0]*0.5*boardCost);
    //show users booking id and main guests name
    printf("booking id is %c",profile);
    printf("Main guest name is %c %c",userCharArray[profile][0],userCharArray[profile][1]);
    //each of the subtotals amounts frm amove where it is tleast >0

    totalCost=newsPaperCost+roomCost+boardCost;


    if (newsPaperCost >0)
    {
        printf("Newspaper cost =%d",newsPaperCost);
    }

    if (roomCost >0)
    {
        printf("room cost =%d",roomCost);
    }

    if (boardCost >0)
    {
        printf("board cost =%d",boardCost);
    }

    printf("total cost =%d",totalCost);

    //update room occupancy and profile info.

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 64; j++) {
            userCharArray[profile][i][j] = 0;
        }
    }

    for (int i = 0; i < 6; i++) {
        userIntArray[profile][i] = 0;
    }

}


int bookTable(int tableBookings[3][7][2]) {
    //jonah
    fflush(stdin);
    int profile = bookingIDRetriever();  //cases for exiting early
    if (profile > 10) {
        printf(">Exiting...\n");
        return (tableBookings[3][7][2]);
    }

    if (userIntArray[profile][3] == 2) {
        printf("Table booking not available for the Bed & Breakfast plan.\n");
        return (tableBookings[3][7][2]);
    } else if (userIntArray[profile][0] + userIntArray[profile][1] > 4) { //if total guests > max chairs at any table
        printf("Too many guests.\n");
        return (tableBookings[3][7][2]);
    }

    //declerations
    int desiredTime = 11; //if still 11, make them try again.
    int desiredDay = 11;
    int desiredTable = 11;
    char endDecision = 'r';

    //user inputs and their validations
    do {
    do {
        printf("\n     --=Table booking=--\nPick a Time (enter 0 for 7pm, or 1 for 9pm): ");
        scanf("%d", &desiredTime);
    } while (desiredTime != 0 && desiredTime != 1);
    do {
        printf("Pick a Day (0=mon, 1=tue, 2=wed, 3=thu, 4=fri, 5=sat, 6=sun): ");
        scanf("%d", &desiredDay);
    } while (desiredDay > 6 || desiredDay < 0);
    do {
        printf("Pick a Table (0=Endor, 1=Naboo, 2=Tatooine): ");
        scanf("%d", &desiredTable);
    } while (desiredTable > 2 || desiredTable < 0);

    if (tableBookings[desiredTable][desiredDay][desiredTime] <= (userIntArray[profile][0] + userIntArray[profile][1])) {
        printf("%d seats there is available.\n Type y to book this slot, ", 4-tableBookings[desiredTable][desiredDay][desiredTime]);
    }
    printf("type r to look for another slot, type e to exit: ");
    scanf(" %c", &endDecision); //maybe add ampersand!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
          if (endDecision == 'y' && tableBookings[desiredTable][desiredDay][desiredTime] == 0) {
              tableBookings[desiredTable][desiredDay][desiredTime] += (userIntArray[profile][0] + userIntArray[profile][1]);
              userIntArray[profile][7]++; //increments meals booked variable
          } else if (tableBookings[desiredTable][desiredDay][desiredTime] == 1) {
              printf("Space is not available in the specified time slot.");
          }
} while (endDecision == 'r' || endDecision == 'a');



//    int tableBookings[3][7][2]; // 3 tables, 7 days, 2 times
//meals orders -> [7] //userIntArray[profile][7]

    // Key: userCharArray[profile][which var][which letter of string]
    // Key: userIntArray[profile][variable]

    //at any point, an input of 0 or e (your choice) will exit the function by using "return 0"


    //task list:
    // store tables: tatooine [0], endor [1], naboo [2] -> int tables[3]
    // show table names
    //7 pm or 9 m, everyday of the week
    //validate table name and time
    //update booking

    return(tableBookings);
}

void profileStatus(int profile) { //prints profile in a readable format
    printf("\n");
    printf("Name: %s\n",userCharArray[profile][0]);
    printf("Surname: %s\n",userCharArray[profile][1]);
    printf("bookingID: %s\n",userCharArray[profile][2]);
    printf("child guest count: %d\n",userIntArray[profile][0]);
    printf("adult guest count: %d\n",userIntArray[profile][1]);
    printf("length of stay: %d\n",userIntArray[profile][2]);
    printf("board type: %d\n",userIntArray[profile][3]);
    printf("newspaper: %d\n",userIntArray[profile][4]);
    printf("DoB: %d\n",userIntArray[profile][5]);
    printf("Room number: %d\n",userIntArray[profile][6]);
    printf("Meals booked: %d\n",userIntArray[profile][7]);
}

//main
int main() {
    //declaring variables and other shiz
    char choice = 'x';
    int roomsOccupied = 0;
    int tableBookings[3][7][2]; // 3 tables, 7 days, 2 times
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            userIntArray[i][j] = -1;
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 64; k++) {             // these for loops just make our arrays more predictable
                userCharArray[i][j][k] = 0;
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 1; j++) {
            userRoomArray[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++) {   //clears table bookings
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 2; k++) {
                tableBookings[i][j][k] = 0;
            }
        }
    }



    //dummy profile 0
    strcpy(userCharArray[0][0], "John"); // name
    strcpy(userCharArray[0][1], "Smith"); //surname
    strcpy(userCharArray[0][2], "JohnSmith9999"); //bookingID
    userIntArray[0][0] = 1; //child guests
    userIntArray[0][1] = 1; //adult guest
    userIntArray[0][2] = 4; //length of stay
    userIntArray[0][3] = 0; // full board
    userIntArray[0][4] = 1;// yes daily newspaper
    userIntArray[0][5] = 01012000; // 01/01/2000
    userIntArray[0][6] = 3; //room 3
    userIntArray[0][7] = 1; //zero meal orders at start



    while (1) {           // choice loop
        printf("\nYou have returned to the menu.\n");
        profileStatus(0); //prints profile in a readable format

        printf("\nChoose a function (i to check in, o to check out, or b to book a table):");
        scanf(" %c", &choice);
        if (choice == 'i') {          // check in
            //ed
            printf(">Checking in...\n");
            checkIn();
        }
        else if (choice == 'o') {   // check out
            //christian
            printf("\n>Checking out...");
            checkOut();
        }
        else if (choice == 'b') {   // booking a table
            //jonah
            printf("\n>Booking in...");
            bookTable(tableBookings);
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