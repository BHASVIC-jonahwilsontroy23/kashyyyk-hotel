#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define maxStringVariables 3
#define maxIntegerVariables 6
char userCharArray[6][maxStringVariables][64];
int userIntArray[6][maxIntegerVariables];

int bookingIDRetriever() {
    char enteredBookingID[68];
    int profile = 12;
    int done = 0;
    fflush(stdin);
    do {
        printf("Enter bookingID (or 'exit' to exit): ");
        scanf("%s", enteredBookingID);
        printf("Input = %s\n", enteredBookingID);
        for (int i = 0; i < 6; i++) {
            if (!strcmp(enteredBookingID, userCharArray[i][2])) {
                profile = i;
                printf(">Match found with profile %d.", i);
                done = 1;
            }
        }

    if (!strcmp(enteredBookingID, "exit")) {
        profile = 11;
        done = 1;
        printf("exited within function\n");
    }
    if (!done) {
        printf("Try again.\n");
    }
    } while (!done);
    return profile;
}

int main() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            userIntArray[i][j] = 9999;
        }

    }
    for (int i = 0; i < 6; i++) {
            for (int k =0; k <64; k++) {
            userCharArray[i][2][k] = "z";
            }
    }
    strcpy(userCharArray[2][2], "Smith9999");

    int profile = bookingIDRetriever();
    if (profile > 10) {
        printf("exiting... from prof = 11");
        return 0;
    }
    printf("didnt exit!");

    return 0;
}