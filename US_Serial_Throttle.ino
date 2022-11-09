// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
float distance; // variable for the distance measurement
float sum = 0;
const int n_mess = 5;
float dist_array[5]={6.6,6.6,6.6,6.6,6.6};



void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed

}

int idx = 0;
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH,4600); // V = s/t;    s= 16
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  // cap dist if necessary

  if(distance>6.6) distance=6.6;
  if(distance<1.8) distance=6.6;
  
  
  // Displays the distance on the Serial Monitor
  

  dist_array[0]=dist_array[1];
  dist_array[1]=dist_array[2];
  dist_array[2]=dist_array[3];
  dist_array[3]=dist_array[4];
  dist_array[4]=distance;
  sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += dist_array[i];
  }
  
   

  
  float avg_dist = (1.0 *sum) / (5.0);
  int mapped_dist = map(avg_dist*100,180,660,0,100); // map distance from 0 to 100 or finally from 0.0 to 1.0
  Serial.println(1.0-(mapped_dist/100.0)); //convert from 0.0 to 1.0(no gas) to 1.0 (full gas) to 0.0 (no gas) 

}
