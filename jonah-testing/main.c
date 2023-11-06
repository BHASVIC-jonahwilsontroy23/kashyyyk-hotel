#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//int main() {
//    while (1) {
//        printf("Hello, World!\n");
//        char mystr1[2][5] = {"hello"};
//        char mystr2[2][5] = {"", "bells"};
//        printf("Input1:\n");
//        scanf("%s", mystr1[0]);
//        printf("Input2:\n");
//        scanf("%s", mystr2[1]);
//
//        printf("1: %s\n2: %s\n", mystr1[0], mystr2[1]);
//        if (strcmp(mystr1[0], mystr2[1])) {
//            printf("scess\n");
//        }
//    }
//    return 0;
//}

//    char var1 = 69;
//    int var2 = 10;
//    printf("char: %c or %d. combined: %d", var1, var1, var1+var2);

#define maxStringVariables 3
#define maxIntegerVariables 6
char userCharArray[6][maxStringVariables][64];
int userIntArray[6][maxIntegerVariables];

int bookingIDRetriever() {
    char enteredBookingID[68];
    int profile;
    int done = 0;
    fflush(stdin);
    do {
        printf("Enter bookingID (or 'exit' to exit): ");
        scanf("%s", enteredBookingID);
        printf("Input = %s\n", enteredBookingID);
        for (int i = 0; i < 6; i++) {
            if (strcmp(enteredBookingID, userCharArray[i][2])) {
                profile = i;
                printf(">Match found with profile %d.", i);
                done = 1;
            } else {
                printf("Try again.\n");
            }
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
        for (int j = 0; j < 3; j++) {
            userCharArray[i][j] = 'z';
        }

    }
    strcpy(userCharArray[2][2], "Smith9999");

    int profile = bookingIDRetriever();
    if (profile == 10) {
        printf("exiting...");
        return 0;
    }
    printf("didnt exit!");

    return 0;
}