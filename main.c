#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CITIES 30
#define SIZE 50
#define vehicle 3
void removeNewline(char *str);
void addCity(char city[][SIZE], int *citycount);
void displayCities(char city[][SIZE], int citycount);
void renameCity(char city[][SIZE], int citycount);
void removeCity(char city[][SIZE], int *citycount);
void cityManagement(char city[][SIZE], int *citycount);
int distance(int dist[][CITIES], int cityCount, int a, int b, int km);
void inputDistance(int dist[][CITIES], char cities[][SIZE], int cityCount);
void displayDistanceTable(int dist[][CITIES], char cities[][SIZE], int cityCount);
void showVehicleTypes();



int main()
{
    char cities[CITIES][SIZE];
    int citycount = 0;
    int dist[CITIES][CITIES]= {0}; // its equal to zero because asaign garbage values
    char vehicleType[vehicle][SIZE] = { "Van", "Truck", "Lorry" };
    int capacity[vehicle] = { 1000, 5000, 10000 };
    int ratePerKm[vehicle] = { 30, 40, 80 };
    int avgSpeed[vehicle] = { 60, 50, 45 };
    int fuelEff[vehicle] = { 12, 6, 4 };



    int choice;
    while (choice !=10)
    {

        printf("\n---- Logistics Management System ----\n");
        printf("1. City Management\n");
        printf("2. Distance Management\n");
        printf("3. Display vehcles\n");
        printf("4. Delivery Request Handling\n");
        printf("5. Cost, Time, and Fuel Calculations\n");
        printf("6. Delivery Records\n");
        printf("7. Finding The Least-Cost Route (Least-Distance)\n");
        printf("8. Performance Reports\n");
        printf("9. File Handling\n");
        printf("10. Exit\n");
        printf("Choose option: ");
        scanf("%d",&choice);



        switch (choice)
        {
        case 1:
            cityManagement(cities, &citycount);
            break;
        case 2:
            displayDistanceTable( dist, cities,citycount);
            break;
        case 3:
             showVehicleTypes();
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



void removeNewline(char *str)
{
    int len = strlen(str);
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';
}

// to add a new city
void addCity(char city[][SIZE], int *citycount)
{
    if (*citycount >= CITIES)
    {
        printf("City limit reached!\n");
        return;
    }

    printf("Enter city name: ");
    fgets(city[*citycount], SIZE, stdin);
    removeNewline(city[*citycount]);

    (*citycount)++;
    printf("City added successfully!\n");
}

// to Display all cities
void displayCities(char city[][SIZE], int citycount)
{
    if (citycount == 0)
    {
        printf("No cities added yet.\n");
        return;
    }

    printf("\nCities List:\n");
    for (int i = 0; i < citycount; i++)
    {
        printf("[%d] %s\n", i, city[i]);
    }
}

// to Rename a city
void renameCity(char city[][SIZE], int citycount)
{
    if (citycount == 0)
    {
        printf("No cities available!\n");
        return;
    }

    displayCities(city, citycount);

    int index;
    printf("Enter city index to rename: ");
    scanf("%d", &index);
    getchar();

    if (index < 0 || index >= citycount)
    {
        printf("Invalid index!\n");
        return;
    }

    printf("Enter new name: ");
    fgets(city[index], SIZE, stdin);
    removeNewline(city[index]);

    printf("City renamed!\n");
}

// to Remove a city
void removeCity(char city[][SIZE], int *citycount)
{
    if (*citycount == 0)
    {
        printf("No cities to remove!\n");
        return;
    }

    displayCities(city, *citycount);

    int index;
    printf("Enter city index to remove: ");
    scanf("%d", &index);
    getchar();

    if (index < 0 || index >= *citycount)
    {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index; i < *citycount - 1; i++)
    {
        strcpy(city[i], city[i + 1]);
    }

    (*citycount)--;
    printf("City removed!\n");
}



void cityManagement(char city[][SIZE], int *citycount)
{
    int choice_city;
    while (1)
    {
        printf("\n--- City Management ---\n");
        printf("1) Add City\n");
        printf("2) Rename City\n");
        printf("3) Remove City\n");
        printf("4) Display Cities\n");
        printf("0) Back to Main Menu\n");
        printf("Enter option: ");
        scanf("%d", &choice_city);
        getchar();

        switch (choice_city)
        {
        case 1:
            addCity(city, citycount);
            break;
        case 2:
            renameCity(city, *citycount);
            break;
        case 3:
            removeCity(city,citycount);
            break;
        case 4:
            displayCities(city, *citycount);
            break;
        case 0:
            return;
        default:
            printf("Invalid choice!\n");
        }
    }
}
int distance(int dist[][CITIES], int cityCount, int a, int b, int km)
{
    if (a < 0 || a >= cityCount || b < 0 || b >= cityCount)
    {
        printf("Invalid\n");
        return 0;
    }
    if (a == b)
    {
        printf("Distance = 0.\n");
        return 0;
    }
    if (km < 0)
    {
        printf("Distance cannot be negative\n");
        return 0;
    }

    dist[a][b] = km;
    dist[b][a] = km;
    return 1;
}

void inputDistance(int dist[][CITIES], char cities[][SIZE], int cityCount)
{

    if (cityCount < 2)
    {
        printf("input two or more than two\n");
        return;
    }

    int a, b, km;

    displayCities(cities, cityCount);

    printf("Enter first city index: ");
    scanf("%d", &a);
    getchar();

    printf("Enter second city index: ");
    scanf("%d", &b);
    getchar();

    if (a == b)
    {
        printf("distance = 0\n");
        return;
    }

    printf("Enter distance in km: ");
    scanf("%d", &km);
    getchar();

    if (distance(dist, cityCount, a, b, km))
        printf(" Distance updated successfully!\n");
}


void displayDistanceTable(int dist[][CITIES], char cities[][SIZE], int cityCount)
{

    inputDistance(dist,cities,cityCount);
    if (cityCount == 0)
    {
        printf("No cities available!\n");
        return;
    }

    printf("\nDistance Table (km)\n     ");


    for (int j = 0; j < cityCount; j++)
        printf("%6d", j);

    printf("\n");

    for (int i = 0; i < cityCount; i++)
    {
        printf("%3d |", i);

        for (int j = 0; j < cityCount; j++)
            printf("%6d", dist[i][j]);

        printf("    %s\n", cities[i]);
    }
}
void showVehicleTypes() {
    printf("\n--- Vehicle Types ---\n");
    printf("0) Van   | Capacity: 1000 kg | Rate: 30 LKR/km | Speed: 60 km/h | Fuel: 12 km/l\n");
    printf("1) Truck | Capacity: 5000 kg | Rate: 40 LKR/km | Speed: 50 km/h | Fuel: 6 km/l\n");
    printf("2) Lorry | Capacity: 10000 kg | Rate: 80 LKR/km | Speed: 45 km/h | Fuel: 4 km/l\n");
}
