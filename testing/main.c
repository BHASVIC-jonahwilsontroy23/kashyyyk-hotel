#include <stdio.h>
#include <string.h>

//function area
void checkIn(int userIntArray[5], int userCharArray[2][64]) {
    //check for profile availability

    printf("\n-=CHAR Board=-\n");
    for (int i = 0; i < 2; i++) {
        printf("\n");
        printf("\n");
        for (int j = 0; j < 64; j++) {
            printf("%d, ", userCharArray[i][j]);
        }
    }
    printf("\n-=INT Board=-\n");
    for (int i = 0; i < 5; i++) {
        printf("%d, ", userIntArray[i]);
    }


    //remove profile data and exit immediately if exited.
}
//main
int main() {
    //declaring variables and other shiz
    char choice = 'x';

    while (1) {
        int userCharArray[6][2][64];
        int userIntArray[6][5];

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 5; j++) {
                userIntArray[i][j] = 999;
            }
        }

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 64; k++) {
                    userCharArray[i][j][k] =  k;
                }
            }
        }
        printf("prof 0\n");
        userCharArray[0][2][0] = 1001;
        checkIn(userIntArray,userCharArray);


        printf("\nChoose a function (i to check in, o to check out, or b to book a table): ");
        scanf("%c", &choice);

        if (choice == 'i') {          // check in
            //ed
            printf("\n>Checking in...");
            checkIn(userIntArray[1],userCharArray[1]);

        } else {                   //invalid input
            printf("\n>Invalid Input. Try again.");
        }
        //this is the end of while loop
    }
    return 0;
}
#


//make array global by using "passing by reference"
//pass in desired profile.