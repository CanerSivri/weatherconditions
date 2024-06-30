#include <stdio.h>
#include <stdlib.h>

float calculateCelcius(float fahrenheit){
    return (fahrenheit - 32) * 5 / 9;
}

void printCelcius(float fahrenheit){
    printf("The temperature in Celcius is %f\n", calculateCelcius(fahrenheit));
}

int main(){
    int hot=0 , cold=0;
    float averageTemp=0;
    float sum=0;
    int days=10;
    float temp[days];
    FILE *fptr;
    fptr = fopen("weather.txt", "w");
    if(fptr == NULL){
        printf("Error!");
        exit(1);
    }
    for(int i=0; i<days; i++){
        printf("Enter the Fahrenheit temperature for day %d: ", i+1);
        scanf("%f", &temp[i]);
        sum += temp[i];
        fprintf(fptr, "%f\n", temp[i]);
    }
    fclose(fptr);
    averageTemp = sum / days;
    fptr = fopen("weather.txt", "r");
    while(fscanf(fptr, "%f", &temp[days]) && days<10){
        if(temp[days] > averageTemp){
            printf("Day %d had a temperature higher than the average\n", days+1);
            hot++;
        }
        else{
            printf("Day %d had a temperature lower than the average\n", days+1);
            cold++;
        }
    }
    fclose(fptr);
    printf("The average temperature is %f\n", averageTemp);
    printCelcius(averageTemp);
    printf("There were %d days with temperatures higher than the average\n", hot);
    printf("There were %d days with temperatures lower than the average\n", cold);
    system("pause");
    return 0;
}