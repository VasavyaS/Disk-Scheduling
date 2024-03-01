//Vasavya Sri
#include <iostream>
#include<limits.h>
#include<stdlib.h>
#include <algorithm>
using namespace std;

#define arraySize 10 // number of requests
int initialPos = 50;
int requests[arraySize];//= {5, 28, 10, 7, 39, 20, 45, 67, 36, 35 };



int workLoadGenerator()
{
   //Generate and store 20 random integers in the array
    for (int i = 0; i < arraySize; ++i) {
       requests[i] = rand() % 100; // Generate a random number between 0 and 99
   }
 
 

    // Print the generated array
    cout << "Generated workload: ";
    for (int i = 0; i < arraySize; ++i) {
        cout << requests[i] << " ";
    }
 
    return 0;
}

int FCFS(int requests[10], int initialPos)
{
  int seekTime = 0;
  int currentPosition = initialPos;
  cout<<"\n Executing FCFS algorithm:";
    for (int i = 0; i < arraySize; i++) {
        seekTime += abs(requests[i] - currentPosition);
        cout<<"\n Reading Track :" << requests[i]<< "  Distance Moved : "<<abs(requests[i] - currentPosition);
        currentPosition = requests[i];
       
    }
  cout<< "\n Seek time : "<< seekTime;
    return seekTime;
}

int SSTF(int requests[10], int initialPos)
{
  int seekTime = 0;
  int currentPosition = initialPos;
  int requestSize = arraySize;
  int requestsCopy[10];
  for (int i = 0; i < arraySize; i++)
  {
    requestsCopy[i] = requests[i];
  }
  cout<<"\n Executing SSTF algorithm:";
  while(requestSize > 0)
    {
      int shortest = INT_MAX;
      int shortestIndex = -1;
      int distance =0;
     
      for (int i = 0; i < requestSize; i++)
      {
        distance = abs(requestsCopy[i]-currentPosition);
        if(distance < shortest)
        {
          shortest = distance;
          shortestIndex = i;
        }
       
      }
    cout<< "\n Reading Track :" << requestsCopy[shortestIndex] << "  Distance Moved :" << distance;
    seekTime += shortest;
    currentPosition = requestsCopy[shortestIndex];
   
    for (int i = shortestIndex; i < arraySize - 1; ++i) {
            requestsCopy[i] = requestsCopy[i + 1];
        }
       
    requestSize--;
    }
  cout<< "\n Seek time : "<< seekTime;
    return seekTime;
}

int LOOK(int requests[10], int initialPos)
{
    int seekTime = 0;
    int currentPos = initialPos;
    int direction; // 1 for moving up, 0 for moving down
    int size = arraySize;
    int saveIndex=-1;
    sort(requests, requests + size);
    cout << "\nEnter the direction (1 for moving up and 0 for moving down) :\n";
    cin >> direction;
    int requestsCopy[10];
    for (int i = 0; i < arraySize; i++)
    {
      requestsCopy[i] = requests[i];
    }
   
    while (size > 0) {
       
        if (direction == 1) {
            int nextPos = -1;
            for (int i = 0; i < size; i++) {
                if (requestsCopy[i] >= currentPos) {
                    nextPos = requestsCopy[i];
                    saveIndex = i;
                    break;
                }
            }
            if (nextPos == -1) {
           
                direction = 0;
                continue;
            }
            seekTime += abs(nextPos - currentPos);
            cout<< "\n Reading Track :" << nextPos << "  Distance Moved :" <<abs(nextPos - currentPos) ;
            currentPos = nextPos;
           
            for (int i = saveIndex; i < size - 1; i++) {
                requestsCopy[i] = requestsCopy[i + 1];
           }
            size--;
             
           
        }
        else {
            int nextPos = -1;
            for (int i = size-1; i >= 0; i--) {
                if (requestsCopy[i] <= currentPos) {
                    nextPos = requestsCopy[i];
                    saveIndex = i;
                    break;
                }
            }
            if (nextPos == -1) {
                direction = 1;
                continue;
            }
            seekTime += abs(nextPos - currentPos);
            cout<< "\n Reading Track :" << nextPos << "  Distance Moved :" <<abs(nextPos - currentPos) ;
            currentPos = nextPos;
            for (int i = saveIndex; i < size-1 ; i++) {
                requestsCopy[i] = requestsCopy[i + 1];
           }
            size--;
        }
       
    }
    cout << "\n LOOK : "<< seekTime << " ";
    return 0;
}

int main()
{
    
    workLoadGenerator();
    
    FCFS(requests, initialPos);
    
    SSTF(requests, initialPos);
    
    LOOK(requests, initialPos);
   
    return 0;
}
