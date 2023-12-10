#include <stdio.h>
#include <stdlib.h>

#define MAX_SENSORS 5
#define SAFE_DISTANCE 50 // 50 cm

// Struct to represent the Ultrasonic Sensor data
typedef struct {
 int sensorId;
 int distance;
} SensorData;

// Function to process sensor data and make decision
void processSensorData(SensorData *data) {
   if (data->distance < SAFE_DISTANCE) {
     printf("Sensor %d: Warning! Vehicle is too close to obstacles.\n", data->sensorId);
   } else {
     printf("Sensor %d: Vehicle is safe. Distance: %d cm\n", data->sensorId, data->distance);
   }
}

int main() {
 SensorData sensorData[MAX_SENSORS];
 int numSensors, i;

 printf("Enter the number of sensors: ");
 scanf("%d", &numSensors);

 if (numSensors > MAX_SENSORS) {
    printf("Error: Maximum number of sensors is %d.\n", MAX_SENSORS);
    return -1;
 }

for (i = 0; i < numSensors; i++) {
    printf("Enter sensor ID %d: ", i + 1);
    scanf("%d", &sensorData[i].sensorId);

    printf("Enter distance for sensor ID %d: ", sensorData[i].sensorId);
    scanf("%d", &sensorData[i].distance);
}

 printf("\nProcessed Data:\n");
 for (i = 0; i < numSensors; i++) {
    processSensorData(&sensorData[i]);
 }

  return 0;
}