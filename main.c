#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CITIES 30
#define SIZE 50
void removeNewline(char *str);
void addCity(char city[][SIZE], int *citycount);
void cityManagement(char city[][SIZE], int *citycount);



int main() {
    char cities[CITIES][SIZE];
int citycount = 0;

 int choice;
     while (choice !=10) {

        printf("\n---- Logistics Management System ----\n");
        printf("1. City Management\n");
        printf("2. Distance Management\n");
        printf("3. Vehicle Management\n");
        printf("4. Delivery Request Handling\n");
        printf("5. Cost, Time, and Fuel Calculations\n");
        printf("6. Delivery Records\n");
        printf("7. Finding The Least-Cost Route (Least-Distance)\n");
        printf("8. Performance Reports\n");
        printf("9. File Handling\n");
        printf("10. Exit\n");
        printf("Choose option: ");
     scanf("%d",&choice);



        switch (choice) {
            case 1:
                cityManagement(cities, &citycount);
                break;
                case 2:
                printf("not added yet");
                break;
                case 3:
                printf("not added yet");
                break;
                case 4:
                printf("not added yet");
                break;
                case 5:
                printf("not added yet");
                break;
                case 6:
                printf("not added yet");
                break;
                case 7:
                printf("not added yet");
                break;
                case 8:
                printf("not added yet");
                break;
                case 9:
                printf("not added yet");
                break;
                case 10:
                printf("you exit the program\n");
                break;
                default:
            printf("Invalid choice.\n");




        }
    }
}



void removeNewline(char *str) {
    int len = strlen(str);
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';
}

// to add a new city
void addCity(char city[][SIZE], int *citycount) {
    if (*citycount >= CITIES) {
        printf("City limit reached!\n");
        return;
    }

    printf("Enter city name: ");
    fgets(city[*citycount], SIZE, stdin);
    removeNewline(city[*citycount]);

    (*citycount)++;
    printf("City added successfully!\n");
}




void cityManagement(char city[][SIZE], int *citycount) {
    int choice_city;
    while (1) {
        printf("\n--- City Management ---\n");
        printf("1) Add City\n");
        printf("2) Rename City\n");
        printf("3) Remove City\n");
        printf("4) Display Cities\n");
        printf("0) Back to Main Menu\n");
        printf("Enter option: ");
        scanf("%d", &choice_city);
        getchar();

        switch (choice_city) {
            case 1:
                addCity(city, citycount);
                break;
            case 2:
                printf("not added yet");
                break;
            case 3:
                printf("not added yet");
                break;
            case 4:
                printf("not added yet");
                break;
            case 0:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

