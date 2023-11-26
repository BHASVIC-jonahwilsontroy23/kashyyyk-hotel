//notes section:
//ben will try to break out code, so make sure to add validation checks!
//need to have the profile data stored on the computer itself.
//checkout will use temp variables and update global on finish, while the others can use global variables in the func
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

////TODO: Different approach to room number below needs to be consistent with arrays above

////TODO: Discuss use of RoomNumber vs Profile.
//*/

#define maxStringVariables 3
#define maxIntegerVariables 8
#define maxRoomVariables 1
char userCharArray[6][maxStringVariables][64];
int userIntArray[6][maxIntegerVariables];
int userRoomArray[6][maxRoomVariables];
int roomDetailsIntArray[7][maxRoomVariables];
int boardRatesIntArray[3];
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
// Date of birth-> [5]
//Room number -> [6]
//meals orders -> [7]

//userRoomArray[room][in use]
//1 - in use
//0 - not in use

//Init
void initVars(){

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


}

void initTableBookingsVar() {
    int tableBookings[3][7][2]; // 3 tables, 7 days, 2 times
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            userIntArray[i][j] = -1;
        }
    }
    for (int i = 0; i < 3; i++) {   //clears table bookings
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 2; k++) {
                tableBookings[i][j][k] = 0;
            }
        }
    }
}

//Utility Functions
//Utility Functions
void testBooking(){

    //Children
    userIntArray[1][0] = 5;
    //printf("how many adults are in your booking?");
    userIntArray[1][1] = 2;
    //printf("how long are you staying for?");
    userIntArray[1][2] = 2;
    //printf("what type of booking do you have?\n (FB=0 HB=1 BB=2)");
    userIntArray[1][3] = 1;
    //printf("would you like a daily newspaper? yes=1 no=0");
    userIntArray[1][4]=1;
    //printf("what is your DOB? please write in format: ddmmyyyy");
    userIntArray[1][5]=19112023;

    userIntArray[1][6] = 1;

    //printf("What is your first name");

    strcpy(userCharArray[1][0] , "ed");
    //printf("What is your last name");
    strcpy(userCharArray[1][1] , "Bell");

    //printf("Enter your preferred booking reference (first, last and a random single digit number)");
    strcpy(userCharArray[1][2],"test1");

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
}

void setRoomAndBoardPrices(){
    //room number maps to index
    roomDetailsIntArray[0][0] = 0;  //Not used
    roomDetailsIntArray[1][0] = 1;
    roomDetailsIntArray[2][0] = 2;
    roomDetailsIntArray[3][0] = 3;
    roomDetailsIntArray[4][0] = 4;
    roomDetailsIntArray[5][0] = 5;
    roomDetailsIntArray[6][0] = 6;

    //room price
    roomDetailsIntArray[1][1] = 100;
    roomDetailsIntArray[2][1] = 100;
    roomDetailsIntArray[3][1] = 85;
    roomDetailsIntArray[4][1] = 75;
    roomDetailsIntArray[5][1] = 75;
    roomDetailsIntArray[6][1] = 50;

    //board rates
    boardRatesIntArray[0]=20;
    boardRatesIntArray[1]=15;
    boardRatesIntArray[2]=5;

}

int bookingIDRetriever() {
    char enteredBookingID[68];
    int profile = 12;
    int done = 0;
    fflush(stdin);
    do {
        printf("\nEnter bookingID (or 'exit' to exit):\n");
        scanf("%s", enteredBookingID);
        printf("\n>Inputted = %s.", enteredBookingID);
        for (int i = 0; i<6; i++) {
            if (!strcmp(enteredBookingID, userCharArray[i][2])) {
                profile = i;
                printf("\n>Match found with profile %d.\n", i);
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

int getProfileForBookingID() {
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

int isRoomAvailable(int roomNumber){
    if (userIntArray[roomNumber][6])
        return 0;
    else return 1;
}

char* getBoardTypeFullName (int intBoardType)
{
    char* boardTypeLocal;

    if (intBoardType == 0 ) boardTypeLocal = "Full Board";
    else if (intBoardType == 1 ) boardTypeLocal = "Half Board";
    else if (intBoardType == 2 ) boardTypeLocal = "Bed and Breakfast";
    else boardTypeLocal = "Unknown";

    return boardTypeLocal;
}

//DATE SPLIT
/*void splitString(const char *input, char *output[]) {

    int temp = 0;

    if (strlen(input) != 6) {
        printf("Input string must have exactly 6 characters.\n");
        return;
    }

    // Copy two characters at a time into the output array
    for (int i = 0, j = 0; i < 6; i += 2, j++) {
        strncpy(output[j], input + i, 2);



    }
}
char dobSplit[4][3]; // Array to store four 2-character strings

*/
//Dupe of Show room details
void profileStatus(int profile) { //prints profile in a readable format
    printf("\n");
    printf("Name: %s\n", userCharArray[profile][0]);
    printf("Surname: %s\n", userCharArray[profile][1]);
    printf("bookingID: %s\n", userCharArray[profile][2]);
    printf("child guest count: %d\n", userIntArray[profile][0]);
    printf("adult guest count: %d\n", userIntArray[profile][1]);
    printf("length of stay: %d\n", userIntArray[profile][2]);
    printf("board type: %d\n", userIntArray[profile][3]);
    printf("newspaper: %d\n", userIntArray[profile][4]);
    printf("DoB: %d\n", userIntArray[profile][5]);
    printf("Room number: %d\n", userIntArray[profile][6]);
    printf("Meals booked: %d\n", userIntArray[profile][7]);
}

//BOOKING
void showAvailableRoomDetails(){
    //TODO: Consider use of Dates for room bookings
    char varRoomDetails[2000] = "x";
    char buffer[4]="x";

    for (int roomNum  = 1; roomNum < 7; roomNum++) {

        if (isRoomAvailable(roomNum)) {

            strcat(varRoomDetails, "\n Room Rate for Room ");
            sprintf(buffer, "%d", roomNum);
            strcat(varRoomDetails, buffer);


            strcat(varRoomDetails, "is: ");
            sprintf(buffer, "%d", roomDetailsIntArray[roomNum][1]);
            strcat(varRoomDetails, buffer);

        }
        else {
            strcat(varRoomDetails, "\n This room isn't available, Room");
            sprintf(buffer, "%d", roomNum);
            strcat(varRoomDetails, buffer);
        }
    }

    strcat(varRoomDetails, "\n Full Board rate is: ");
    sprintf(buffer, "%d", boardRatesIntArray[0]);
    strcat(varRoomDetails, buffer);

    strcat(varRoomDetails, "\n Half Board Rate is: ");
    sprintf(buffer, "%d", boardRatesIntArray[1]);
    strcat(varRoomDetails, buffer);
    strcat(varRoomDetails, "\n B&B rate is: ");
    sprintf(buffer, "%d", boardRatesIntArray[2]);
    strcat(varRoomDetails, buffer);

    printf(varRoomDetails);

}

void makeBooking(int roomNumber) {

    fflush(stdin);
    printf("how many children are included in your booking?");
    scanf("%d", &userIntArray[roomNumber][0]);
    printf("how many adults are in your booking?");
    scanf("%d",&userIntArray[roomNumber][1]);
    printf("how long are you staying for?");
    scanf("%d", &userIntArray[roomNumber][2]);
    printf("what type of booking do you have?\n (FB=0 HB=1 BB=2)");
    scanf("%d",&userIntArray[roomNumber][3]);
    printf("would you like a daily newspaper? yes=1 no=0");
    scanf("%d",&userIntArray[roomNumber][4]);
    printf("what is your DOB? please write in format: ddmmyyyy");
    scanf("%d",&userIntArray[roomNumber][5]);

    userIntArray[roomNumber][6] = roomNumber;

    printf("What is your first name");
    scanf("%s",&userCharArray[roomNumber][0]);
    printf("What is your last name");
    scanf("%s",&userCharArray[roomNumber][1]);

    printf("Enter your preferred booking reference (first, last and a random single digit number)");
    scanf("%s",&userCharArray[roomNumber][2]);

    //int r = rand() %10

}

void showRoomDetails(int roomNum){
    printf("\nYou are staying in room %d\n", roomNum);
    printf("\n%d Adults are included",userIntArray[roomNum][1]);
    printf("\n%d Children are included",userIntArray[roomNum][0]);
    printf("\nYou are staying for %d days",userIntArray[roomNum][2]);
    printf("\nYou have board type %s ",getBoardTypeFullName(userIntArray[roomNum][3]));
    printf("\nDid you want a newspaper? %d yes=1 no=0",userIntArray[roomNum][4]);
    //TODO convert date format
    printf("\nYour date of birth is, %d", userIntArray[roomNum][5]);
    printf("\nYour name is %s %s", userCharArray[roomNum][0],userCharArray[roomNum][1]);


}

//BOOK TABLE
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
    int desiredTime = -1; //if still -1, make them try again.
    int desiredDay = -1;
    int desiredTable = -1;
    char endDecision = 'r';

    //user inputs and their validations
        printf("\n      Table Booking\n");
    do {
        int c;
        if (endDecision == 'r') {
            printf(">Booking new table...\n");
        }
        do {
            printf("Pick a Time:\n[0] 7pm\n[1] 9pm\n");
            while ((c = getchar()) != '\n' && c != EOF);
            scanf("%d", &desiredTime);
        } while (desiredTime != 0 && desiredTime != 1);
        do {
            printf("\nPick a Day:\n[0] Monday\n[1] Tuesday\n[2] Wednesday\n[3] Thursday\n[4] Friday\n[5] Saturday\n[6] Sunday\n");
            while ((c = getchar()) != '\n' && c != EOF);
            scanf("%d", &desiredDay);
        } while (desiredDay > 6 || desiredDay < 0);
        do {
            printf("\nPick a Table:\n[0] Endor\n[1] Naboo\n[2] Tatooine\n");
            while ((c = getchar()) != '\n' && c != EOF);
            scanf("%d", &desiredTable);
        } while (desiredTable > 2 || desiredTable < 0);

        if (tableBookings[desiredTable][desiredDay][desiredTime] <=
            (userIntArray[profile][0] + userIntArray[profile][1])) {
            printf("\n%d seat(s) there is/are available.\n[y] Book this slot\n", 4 - tableBookings[desiredTable][desiredDay][desiredTime]);
        } else {
            printf("\nThere are not enough seats available there.\n");
        }
        printf("[t] try another slot\n[e] Exit\n");
        scanf(" %c", &endDecision); //maybe add ampersand!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        if (endDecision == 'y' && (4-tableBookings[desiredTable][desiredDay][desiredTime]) >= (userIntArray[profile][0] + userIntArray[profile][1])) {
            tableBookings[desiredTable][desiredDay][desiredTime] += (userIntArray[profile][0] + userIntArray[profile][1]);
            userIntArray[profile][7]++; //increments meals booked variable
            //in case of yes ask for another booking of table
        } else if (endDecision == 'y') {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                .~~~~~~~~~~~~~~~~.                         \n                          ^77GGGB@@@@@@@@@@@@@@@@BGGG77~                   \n                       ^JB@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BJ^                \n                     :J@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Y:              \n                     5@@@@@@&&&&&&&@@@@@@@@@@@@&&&&&&&@@@@@@P              \n                     5@@BJ?!.......!P@@@@@@@@P!.......!?JB@@P              \n                     Y@#.      !P5. 7@@@@@@@@J  5P7      .B@P              \n                     .7#BY?7:::^!:.Y&@#!:7&@@&5.:~~:::!?JB#?.              \n                      .7@@@@G#PYY5#@@#.   ^&@@@&5YYP&G&@@@?.               \n                      !@@GPJ Y55G&&&&#PPPPP#&&&&@G555:^?G@@?               \n                .!JJJ^:Y@&#GJ5:~P55!!PP~?PPP~7PY:J?:JB###@5^:JJY!.         \n              .Y#@@@@#J~7P#@@@GPG55^~BG:?BBB:7G5~Y#@@@@&P! !B@@B&#!        \n             .J&J^^^Y555PBGY!Y55P&&GPPPGPPPPPPG&&P55Y~^::7G&#Y~ !Y!:       \n            .!P^        :7JY#YY7:..~~:::::::~^...:::^JYP&#Y~      :!Y!     \n          !77~      5!     ~@7!5#~.?PPPPPPPP&5^~P&#PP7!!~   .!7:    ~77~.  \n        :JY^        #J  :::7@!~P#^7^:7PPPPP5#GY5Y&Y         ?&.       .^P! \n       !57          ##57!!!7?P~!5Y Y&#####G  .!@7BY    :~^YPB&.         .PP\n       75~.       .!5! .    .@Y~?@:5@@@@@@@G:7PJ!#Y 777J5~!:!#.          PG\n         ^77~:    ^@^       .JJ7?&:5@@@@@@@@^J#!5Y!!#:       ~B^        :55\n           .^!7~~:^@^         GP!&.JBBBBBBBB^Y#7@?7Y.        .@~     :~7!: \n              .^~!J&~..:::....BG?@?7777777777G&J@Y^..::::::..^@J!!!7::^    \n                   :~PG!7!?JJ7??7?^.         ~?7?JJJ7777777?5PJ~:::        \n                    YJ^  :5&5.                   P@G       7Y~             \n                    &?   G@G            ~!.      P@B.       !&             \n                  .YJ^ .Y&G!            5#!Y:    G@@#:      :?Y:           \n                  ^@:  :@@?           .~Y?.@~    :5@@:       .@~           \n                  :#~::^5P7.::::::::~77~. :#!::::.J@@Y~::::::~#^           \n                    ~!!!~?YYYYY?!!!!~.     .~!!!!JY555?!!!!!!~             \n                  :!!!!! JB&@@@Y                 P@@@@J.   ^!!7:.          \n                !P&@@@@@##G5JB#BY              .PB###PP5Y##@@@@&#BJ.       \n                Y#BBBBBBBBBG7.7JJ?.           :?JJJ7.5BB#BBBBBBBBG7.\n\n\n\n                              we're gonna have a bad time...\n\n\n                              ready?");
            scanf("%d", &desiredTime);
        }
    } while (endDecision == 'r' || endDecision == 'y');

    return (tableBookings[3][7][2]); //todo jonah fix...(int tableBookings ) //(was return 1; just now)
}

//CHECKOUT
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








    // if any guests are 16 and under 50% discount on board rate for them

    boardCost=(userIntArray[profile][1]*boardCost)+(userIntArray[profile][0]*0.5*boardCost);
    //show users booking id and main guests name
    printf("\nBooking id is %s", userCharArray[profile][2]);
    printf("\nYour room was %d",profile);
    printf("\nMain guest name is %s %s",userCharArray[profile][0],userCharArray[profile][1]);
    //each of the subtotals amounts frm amove where it is tleast >0

    totalCost=newsPaperCost+roomCost+boardCost;


    if (newsPaperCost >0)
    {
        printf("\nNewspaper cost =%d",newsPaperCost);
    }

    if (roomCost >0)
    {
        printf("\nRoom cost =%d",roomCost);
    }

    if (boardCost >0)
    {
        printf("\nBoard cost =%d",boardCost);
    }

    printf("\nTotal cost =%d",totalCost);

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

//MAIN
//MAIN
int main() {//declaring variables and other shiz
    int roomNum;
    char choice = 'x';
    int tableBookings[3][7][2]; // 3 tables, 7 days, 2 times
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            userIntArray[i][j] = -1;
        }
    }
    for (int i = 0; i < 3; i++) {   //clears table bookings
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 2; k++) {
                tableBookings[i][j][k] = 0;
            }
        }
    }

// Set up Room prices.
    setRoomAndBoardPrices();
    initVars();
    testBooking();
    while (1) {           // choice loop
        int viewprofiledetailschoice = 2;
        printf("DEBUG: would you like to display a profile's details?\n[0] prof 0\n[1] prof 1\n[2,3,4,5] others (not filled in)\n[7] no.\n");
        scanf("%d",&viewprofiledetailschoice);
        if (viewprofiledetailschoice < 6) {
            profileStatus(viewprofiledetailschoice);
        }

        printf("\nslot 000 = %d, slot 001 = %d\n", tableBookings[0][0][0],tableBookings[0][0][1]);
        setbuf(stdout, 0); //Needed to display message in debug on windows
        printf("\nChoose a function:\n[b] Book room\n[i] Check profile info\n[o] Check out\n[t] Book a table\n");
        scanf(" %c", &choice);
        if (choice == 'b') {          // book room i think
            //ed
            printf(">These are our available rooms, pick one...\n");
            showAvailableRoomDetails();
            printf("\n>Pick a room\n");
            scanf(" %d", &roomNum);

            //TODO Check room selection is valid (Less than 7 and available)
            makeBooking(roomNum);
            printf("\n Thank you for you Booking");
        }
        else if (choice == 'i') {//check prof info
            roomNum = 12;
            roomNum = getProfileForBookingID();  //Profile vs RoomNumber
            if (roomNum < 7) {
                printf(">welcome to the hotel these are your booking details\n");
                showRoomDetails(roomNum);
                // profileStatus(0); //replaced with showroomdetails - prints profile in a readable format
            }else printf("apologies, we cannot find your booking, to try again press c again");
        } else if (choice == 'o') {   // check out
            //christian
            printf("\n>Checking out...");
            checkOut();
        } else if (choice == 't') {   // booking a table
            //jonah

            printf("\n>Booking Table...");
            bookTable(tableBookings);
        } else {                   //invalid input
            printf("\n>Invalid Input. Try again.");
        }
        //this is the end of while loop
        printf("\n\n\n\n\n\n\n\n\nYou have returned to the menu.\n\n\n\n\n\n\n");

    }
    return 0;

}