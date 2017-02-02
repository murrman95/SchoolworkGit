#include <stdio.h>
#include <stdlib.h>

void findClosestFlight(int desiredTime, int *departureTime, int *arrivalTIme);
int hoursIn(int totalMinutes,int *hours);

int main(){
  int userHour;
  int userMinute;
  int userTime;
  printf("Instert a time you wish to find a close flight with: \n");
  if(scanf("%d:%d", &userHour, &userMinute) != 2){
    printf("Invalid input\n");
  }
  
  userTime = (60*userHour) + userMinute;
  int userDepart = 0;
  int userArrive = 0;
  
  findClosestFlight(userTime, &userDepart, &userArrive);
  int dHours;
  int dMinutes;
  int aHours;
  int aMinutes;
  
  dMinutes = hoursIn(userDepart, &dHours);
  aMinutes = hoursIn(userArrive, &aHours);
  if(dMinutes >= 10){
    printf("The departure time of the closest flight is: %d:%d\n", dHours
                                                                , dMinutes);
  }
  else{
    printf("The departure time of the closest flight is: %d:0%d\n", dHours
                                                                , dMinutes);
  }
  if(aMinutes >= 10){
    printf("The arrival time of the closest flight is: %d:%d\n", aHours
                                                                , aMinutes);
  }
  else{
    printf("The arrival time of the closest flight is: %d:0%d\n", aHours
                                                                , aMinutes);    
  }
  return 0;
}

void findClosestFlight(int desiredTime,int *departureTime, int *arrivalTime){
  int *d = departureTime;
  int *a = arrivalTime;
  
  int closest = 24*60+1; //larger than the amount of minutes there are in a day
  FILE *f = fopen("flights.dat","r");
  int counter = 0; //Just to keep track of reading departure times or arrivals
  
  int dhours;
  int dminutes;
  int ahours;
  int aminutes;
    
  while((fscanf(f,"%d:%d", &dhours, &dminutes) == 2) 
      && (fscanf(f,"%d:%d", &ahours, &aminutes) == 2)){
    int dtime = (dhours*60) + dminutes;
    int atime = (ahours*60) + aminutes;
  
    int compare = desiredTime - dtime;
    if(compare < 0){
      if((compare * -1) < closest){
        closest = (compare*-1);
        *d = dtime;
        *a = atime;
      }
    }
    else{
      if(compare < closest){
        closest = compare;
        *d = dtime;
        *a = atime;
      }
    }
  }
}


int hoursIn(int totalMinutes,int *hours){
  int acc = totalMinutes;
  int tHours = 0;
  while(acc >= 60){
    acc -= 60;
    tHours ++;
  }
  *hours = tHours;
  return acc;
}