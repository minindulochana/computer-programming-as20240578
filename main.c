#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CITIES 30
#define SIZE 50
#define vehicle 3
#define maxdelivery 50
void removeNewline(char *str);
void addCity(char city[][SIZE], int *citycount);
void displayCities(char city[][SIZE], int citycount);
void renameCity(char city[][SIZE], int citycount);
void removeCity(char city[][SIZE], int *citycount);
void cityManagement(char city[][SIZE], int *citycount);
int distance(int dist[][CITIES], int cityCount, int a, int b, int km);
void inputDistance(int dist[][CITIES], char cities[][SIZE], int cityCount);
void displayDistanceTable(int dist[][CITIES], char cities[][SIZE], int cityCount);
void displayVehicleTypes();
void handleDeliveryRequest(int dist[][CITIES], char cities[][SIZE], int cityCount,
                           int capacity[]);
void calculateDeliveryCost(int dist[][CITIES], char cities[][SIZE], int cityCount,
                           int capacity[], int ratePerKm[], int avgSpeed[],
                           int fuelEff[], float fuelPrice);
void storeDeliveryRecord(int dist[][CITIES], char cities[][SIZE], int citycount,
                         int deliveryStart[], int deliveryEnd[],
                         float deliveryWeight[], int deliveryVehicle[],
                         int *deliveryCount,
                         int capacity[]);
void findLeastCostRoute(int dist[][CITIES], char cities[][SIZE], int citycount,
                        int capacity[], int ratePerKm[], int avgSpeed[],
                        int fuelEff[], float fuelPrice);

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
    float fuelprice=310.0;
    int deliveryStart[maxdelivery ];
    int deliveryEnd[maxdelivery ];
    float deliveryWeight[maxdelivery ];
    int deliveryVehicle[maxdelivery ];
    int deliveryCount = 0;




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
            displayVehicleTypes();
            break;
        case 4:
            handleDeliveryRequest(dist, cities, citycount, capacity);
            break;
        case 5:

            calculateDeliveryCost(dist, cities, citycount,
                                  capacity, ratePerKm, avgSpeed,
                                  fuelEff, fuelprice);


            break;
        case 6:
            storeDeliveryRecord(dist, cities, citycount,
                                deliveryStart, deliveryEnd,
                                deliveryWeight, deliveryVehicle,
                                &deliveryCount,
                                capacity);
            break;
        case 7:
            findLeastCostRoute(dist, cities, citycount,
                               capacity, ratePerKm, avgSpeed,
                               fuelEff, fuelprice);
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


    printf("Enter second city index: ");
    scanf("%d", &b);


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
void displayVehicleTypes()
{
    printf("\n--- Vehicle Types ---\n");
    printf("1) Van   | Capacity: 1000 kg | Rate: 30 LKR/km | Speed: 60 km/h | Fuel: 12 km/l\n");
    printf("2) Truck | Capacity: 5000 kg | Rate: 40 LKR/km | Speed: 50 km/h | Fuel: 6 km/l\n");
    printf("3) Lorry | Capacity: 10000 kg | Rate: 80 LKR/km | Speed: 45 km/h | Fuel: 4 km/l\n");
}

void handleDeliveryRequest(int dist[][CITIES], char cities[][SIZE], int cityCount,
                           int capacity[])
{

    if (cityCount < 2)
    {
        printf("Need at least 2 cities to request delivery!\n");
        return;
    }

    int start, end, type;
    float weight;

    displayCities(cities, cityCount);
    displayVehicleTypes();

    printf("Enter source city index: ");
    scanf("%d", &start);

    printf("Enter destination city index: ");
    scanf("%d", &end);

    if (start == end)
    {
        printf("it cannot be same ");
        return;
    }

    if (start< 0 ||start >= cityCount || end< 0 || end >= cityCount)
    {
        printf("invalid\n");
        return;
    }

    printf("Enter weight (kg): ");
    scanf("%f", &weight);

    printf("\nSelect Vehicle Type:\n");


    printf("Enter vehicle type: ");
    scanf("%d", &type);
    type--;


    if (type < 0 || type > vehicle)
    {
        printf("enter a valid number\n");
        return;
    }

    if (weight > capacity[type])
    {
        printf("Over vehicle capacity Max: %d kg\n", capacity[type]);
        return;
    }

    if (dist[start][end] <= 0)
    {
        printf(" Distance not set between these cities\n");
        return;
    }

    printf("\nDelivery Request Accepted\n");
    printf("Source: %s\n", cities[start]);
    printf("Destination: %s\n", cities[end]);
    printf("Weight: %.2f kg\n", weight);
    printf("Vehicle: %d\n\n", type+1);
}


void calculateDeliveryCost(int dist[][CITIES], char cities[][SIZE], int cityCount,
                           int capacity[], int ratePerKm[], int avgSpeed[],
                           int fuelEff[], float fuelPrice)
{

    if (cityCount < 2)
    {
        printf("Add two or more than two\n");
        return;
    }

    int start, end, type;
    float weight;

    displayCities(cities, cityCount);


    printf("Enter begining city index: ");
    scanf("%d", &start);

    printf("Enter End city index: ");
    scanf("%d", &end);

    if (start== end )
    {
        printf(" it cannot be same\n");
        return;
    }
    if (start< 0 || end >= cityCount || end < 0 || end>= cityCount)
    {
        printf("Invalid city\n");
        return;
    }

    if (dist[start][end] <= 0)
    {
        printf(" enter the distance first\n");
        return;
    }

    printf("Enter weight (kg): ");
    scanf("%f", &weight);
    printf("\nVehicle Types:\n");
    displayVehicleTypes();
    printf("Enter vehicle type: ");
    scanf("%d", &type);
    type--;


    if (type < 0 || type > vehicle)
    {
        printf(" Invalid vehicle type\n");
        return;
    }

    if (weight > capacity[type])
    {
        printf(" Weight exceeds capacity (%d kg)!\n", capacity[type]);
        return;
    }

    float D = dist[start][end];
    float W = weight;
    float R = ratePerKm[type];
    float S = avgSpeed[type];
    float E = fuelEff[type];

    float Cost = D * R * (1 + W / 10000.0f);
    float Time = D / S;
    float FuelUsed = D / E;
    float FuelCost = FuelUsed * fuelPrice;
    float TotalCost = Cost + FuelCost;
    float Profit = Cost * 0.25f;
    float CustomerCharge = TotalCost + Profit;

    printf("\nDelivery Cost Summary\n");
    printf("Start: %s\n", cities[start]);
    printf("End: %s\n", cities[end]);
    printf("Distance: %.2f km\n", D);
    printf("Weight: %.2f kg\n", W);
    printf("Base Delivery Cost: %.2f LKR\n", Cost);
    printf("Fuel Used: %.2f L\n", FuelUsed);
    printf("Fuel Cost: %.2f LKR\n", FuelCost);
    printf("Operational Cost: %.2f LKR\n", TotalCost);
    printf("Profit (25%%): %.2f LKR\n", Profit);
    printf(" Final Customer Charge: %.2f LKR\n", CustomerCharge);
}



void storeDeliveryRecord(int dist[][CITIES], char cities[][SIZE], int citycount,
                         int deliveryStart[], int deliveryEnd[],
                         float deliveryWeight[], int deliveryVehicle[],
                         int *deliveryCount,
                         int capacity[])
{

    if (*deliveryCount >= maxdelivery)
    {
        printf("Record limit reached\n");
        return;
    }

    if (citycount < 2)
    {
        printf(" enter two or more than two cities\n");
        return;
    }

    int start, end, type;
    float weight;

    displayCities(cities, citycount);

    printf("Enter start city index: ");
    scanf("%d", &start);


    printf("Enter End city index: ");
    scanf("%d", &end);


    if (start == end)
    {
        printf(" Start and End cannot be same\n");
        return;
    }

    if (start < 0 || start >= citycount || end < 0 || end>= citycount)
    {
        printf(" Invalid city index\n");
        return;
    }

    if (dist[start][end] <= 0)
    {
        printf(" set the distance first\n");
        return;
    }

    printf("Enter weight (kg): ");
    scanf("%f", &weight);

    displayVehicleTypes();
    printf("\nSelect Vehicle Type:\n");



    printf("Enter vehicle type: ");
    scanf("%d", &type);
    type--;



    if (type < 0 || type >= vehicle)
    {
        printf(" Invalid vehicle type\n");
        return;
    }

    if (weight > capacity[type])
    {
        printf(" Weight exceeds capacity (%d kg)\n", capacity[type]);
        return;
    }

    deliveryStart[*deliveryCount]  = start;
    deliveryEnd[*deliveryCount]    = end;
    deliveryWeight[*deliveryCount] = weight;
    deliveryVehicle[*deliveryCount] = type;

    (*deliveryCount)++;

    printf(" Delivery Recorded \n");
    printf("Record No: %d\n\n", *deliveryCount);
}

void findLeastCostRoute(int dist[][CITIES], char cities[][SIZE], int citycount,
                        int capacity[], int ratePerKm[], int avgSpeed[],
                        int fuelEff[], float fuelPrice)
{

    if (citycount < 2)
    {
        printf("enter two or more than two cities\n");
        return;
    }

    int start, end, type;
    float weight;

    displayCities(cities, citycount);

    printf("Enter START city index: ");
    scanf("%d", &start);
    printf("Enter END city index: ");
    scanf("%d", &end);

    if (start == end)
    {
        printf("Start and End cannot be same\n");
        return;
    }
    if (dist[start][end] <= 0)
    {
        printf("No direct route\n");
    }

    printf("Enter Weight (kg): ");
    scanf("%f", &weight);
    displayVehicleTypes();
    printf("Select Vehicle:  ");
    scanf("%d", &type);
    type--;

    if (weight > capacity[type])
    {
        printf(" Over capacity (%d kg)\n", capacity[type]);
        return;
    }

    float bestDist = 9999;
    int bestPath[4], pathCount = 0;


    for (int i = 0; i < citycount; i++)
    {
        for (int j = 0; j < citycount; j++)
        {
            if (i == start || j == start|| i == j) continue;
            if (i == end || j == end) continue;
            if (dist[start][i] > 0 && dist[i][j] > 0 && dist[j][end] > 0)
            {
                float d = dist[start][i] + dist[i][j] + dist[j][end];
                if (d < bestDist)
                {
                    bestDist = d;
                    bestPath[0] = start;
                    bestPath[1] = i;
                    bestPath[2] = j;
                    bestPath[3] = end;
                    pathCount = 4;
                }
            }
        }
    }

    //if its haven't intermediate path use direct path
    if (bestDist == 99999 && dist[start][end] > 0)
    {
        bestDist = dist[start][end];
        bestPath[0] = start;
        bestPath[1] = end;
        pathCount = 2;
    }

    if (bestDist == 99999)
    {
        printf(" No route found!\n");
        return;
    }

    float D = bestDist;
    float W = weight;
    float R = ratePerKm[type];
    float S = avgSpeed[type];
    float E = fuelEff[type];

    float Cost = D * R * (1 + W / 10000.0f);
    float Fuel = D / E;
    float FuelCost = Fuel * fuelPrice;
    float TotalCost = Cost + FuelCost;
    float Profit = Cost * 0.25;
    float CustomerCharge = TotalCost + Profit;
    float Time = D / S;


    printf("DELIVERY COST ESTIMATION\n");
    printf("------------------------------------------------------\n");
    printf("From: %s\n", cities[start]);
    printf("To: %s\n", cities[end]);
    printf("Minimum Distance: %.2f km\n", D);
    printf("Vehicle: %d\n", type + 1);
    printf("Weight: %.2f kg\n", W);
    printf("------------------------------------------------------\n");
    printf("Base Cost: %.2f LKR\n", Cost);
    printf("Fuel Used: %.2f L\n", Fuel);
    printf("Fuel Cost: %.2f LKR\n", FuelCost);
    printf("Operational Cost: %.2f LKR\n", TotalCost);
    printf("Profit: %.2f LKR\n", Profit);
    printf("Customer Charge: %.2f LKR\n", CustomerCharge);
    printf("Estimated Time: %.2f hours\n", Time);
    printf("======================================================\n");

    printf("\nBest Route: ");
    for (int k = 0; k < pathCount; k++)
    {
        printf("%s", cities[bestPath[k]]);
        if (k < pathCount - 1) printf(" - ");
    }
    printf("\n\n");
}



