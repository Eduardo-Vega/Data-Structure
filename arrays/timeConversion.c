#include <stdio.h>
#include<stdlib.h>
#include<string.h>

/******************************************************************
 Description:
        Convert 12-hour AM/PM format to military 24-hour time.
********************************************************************/

void timeConversion(char militaryHour[], const char s[]){
    int h = 0;
    char hour[9] = {0};
    //plus 12 to original hour
    strncat(hour, s, 2); 
    h = atoi(hour) + 12;
    //saving 12-hour string without AM/PM
    strncpy(hour, s, 8); // "12:10:10"
    //saving original min and sec
    char *min = strstr(hour, ":"); //":10:00"
    //looking for AM or PM in 12-hour string
    char *p = strstr(s, "PM");
    // Checking if is afrternoon or morning
    if (p != NULL){ 
        //Checking if is not 12 PM
        if (!(h == 24)) {
            sprintf(militaryHour, "%d", h);
        }else{ strncpy(militaryHour, s, 2); } 
    }else{
        if (h == 24){ //Checking if is 12AM to set 00h
            strcpy(militaryHour, "00");
        }else{ strncpy(militaryHour, s, 2); } //if not 12AM, hh is the same
    }
    //concat :mm:ss to hh converted
    strcat(militaryHour, min);
}

void main(){
    //initializing strings
    char militaryHour[9] = {0};
    char s[11] = "12:10:00AM";
    timeConversion(militaryHour, s);
    //printing result
    printf("12-hour format: %s\n24-hour format: %s\n", s, militaryHour);
    getchar();
}

