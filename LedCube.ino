/*
 * Program: 4x4x4 LED Cube
 * Date: 07-August-2015 
 * 
 * xy-plane:
 * x = vertical
 * y = horizontal
 * Top view (positions):        Pin allocation:
 *   | 0 1 2 3                    | 0       1       2       3
 * --|--------                  --|-------------------------------
 *  0| o o o o                   0| 0       1       2       3
 *  1| o o o o                   1| 4       5       6       7
 *  2| o o o o                   2| 8       9       10      11
 *  3| o o o o                   3| 12      13      14(A0)  15(A1)
 * 
 * z-axis:
 * Side view (layers):          Pin allocation:
 * -----------                  ---------------
 *  3| o o o o                   3| 19(A5)
 *  2| o o o o                   2| 18(A4)
 *  1| o o o o                   1| 17(A3)
 *  0| o o o o                   0| 16(A2)
 *  
 */

// Declaring array to store LED positions correspond to pin number
byte xy[4][4];
// Declaring array to store LED layers correspond to pin number
byte z[4];
// Indices used in for loop
int i,j;

void setup() {
  // Allocating the pin number to array xy
  byte pin = 0;   // Starting from pin 0
  
  // Store from pin 0 to 15
  for(i=0;i<4;i++) {
    for(j=0;j<4;j++) {
      xy[i][j] = pin++;   // Store and increment to next pin number
      pinMode(xy[i][j],OUTPUT);   // Also set the pin as output
    }
  }
  
  // Allocate layers to array z
  // Continue to store pin starting from 16
  for(i=0;i<4;i++) {
    z[i] = pin++;
    pinMode(z[i],OUTPUT);
  }
  cubeClear();    // Clear the cube

}

void loop() {
  // First line, blink and moving upward
  for(i=0;i<=3;i++) {
    ledOFF(xy[0][0],z[0]);
    delay(500);
    ledON(xy[0][0],z[0]);
    delay(500);
  }
  delay(1000);
  for(i=1;i<4;i++) {
    ledON(xy[0][0],z[i]);
    delay(50);
  }
  for(i=0;i<=2;i++) {
    digitalWrite(z[i],HIGH);
    delay(50);
  }
  delay(200);

  // Second line, moving downward
  ledON(xy[0][1],z[3]);
  delay(100);
  digitalWrite(xy[0][0],LOW);
  delay(250);
  for(i=2;i>=0;i--) {
    ledON(xy[0][1],z[i]);
    delay(50);
  }
  for(i=3;i>=1;i--) {
    digitalWrite(z[i],HIGH);
    delay(50);
  }
  delay(200);

  // Third line, moving horizontal
  ledON(xy[1][1],z[0]);
  delay(100);
  digitalWrite(xy[0][1],LOW);
  delay(250);
  ledON(xy[2][1],z[0]);
  delay(100);
  digitalWrite(xy[1][1],LOW);
  delay(250);
  ledON(xy[3][1],z[0]);
  delay(100);
  digitalWrite(xy[2][1],LOW);
  delay(250);

  // Fourth line, moving upward line by line
  for(i=0;i<4;i++) {
    ledON(xy[3][1],z[i]);
    delay(100);
  }
  cubeClear();
  delay(100);
  for(i=0;i<4;i++) {
    ledON(xy[2][1],z[i]);
    delay(100);
  }
  cubeClear();
  delay(100);
  for(i=0;i<4;i++) {
    ledON(xy[1][1],z[i]);
    delay(100);
  }
  cubeClear();
  delay(100);
  for(i=0;i<4;i++) {
    ledON(xy[0][1],z[i]);
    delay(100);
  }
  delay(1000);

  // Plane, create a vertical plane
  cubeClear();
  delay(500);
  for(i=0;i<4;i++) {
    digitalWrite(xy[i][1],HIGH);
  }
  for(i=0;i<=4;i++) {
    digitalWrite(z[i],LOW);
    delay(50);
  }
  delay(1000);

  // Layer0, light up LED one by one
  cubeClear();
  delay(500);
  for(i=0;i<4;i++) {
    for(j=0;j<4;j++) {
      ledON(xy[i][j],z[0]);
      delay(100);
    }
  }
  delay(1000);

  // Layer 1, light up LED in a spiral shape
  cubeClear();
  delay(500);
  for(i=0;i<4;i++) {
    ledON(xy[0][i],z[1]);
    delay(50);
  }
  for(i=1;i<4;i++) {
    ledON(xy[i][3],z[1]);
    delay(50);
  }
  for(int i=2;i>=0;i--) {
    ledON(xy[3][i],z[1]);
    delay(50);
  }
  ledON(xy[2][0],z[1]);
  delay(50);
  for(i=0;i<=2;i++) {
    ledON(xy[1][i],z[1]);
    delay(50);
  }
  ledON(xy[2][2],z[1]);
  delay(50);
  ledON(xy[2][1],z[1]);
  delay(1000);

  // Layer2, light up LED as a claw shape
  cubeClear();
  delay(500);
  ledON(xy[0][3],z[2]);
  delay(100);
  ledON(xy[0][1],z[2]);
  ledON(xy[1][2],z[2]);
  ledON(xy[2][3],z[2]);
  delay(100);
  ledON(xy[1][0],z[2]);
  ledON(xy[2][1],z[2]);
  ledON(xy[3][2],z[2]);
  delay(100);
  ledON(xy[3][0],z[2]);
  delay(1000);

  // Layer3, light up all LED layer by layer
  cubeClear();
  delay(500);
  for(byte k=0;k<3;k++) {  
    for(i=0;i<4;i++) {
      for(j=0;j<4;j++) {
        ledON(xy[i][j],z[3]);
      }
    }
    delay(100);
    for(i=2;i>=0;i--) {
    digitalWrite(z[i],LOW);
    delay(100);
    }
    for(i=3;i>=0;i--) {
    digitalWrite(z[i],HIGH);
    delay(100);
    }
    for(i=0;i<=3;i++) {
    digitalWrite(z[i],LOW);
    delay(100);
    }
    for(i=0;i<=3;i++) {
    digitalWrite(z[i],HIGH);
    delay(100);
    }
  }

  // Light up all LED and stay forever
  cubeClear();
  delay(500);
  cubeON();
  while(1);
  
}

// Clear all led
void cubeClear() {
  for(byte i=0;i<4;i++) {
    for(byte j=0;j<4;j++) {
      digitalWrite(xy[i][j],LOW);   // Set all LED position pin to LOW
    }
    digitalWrite(z[i],HIGH);    // Set all LED layer pin to HIGH
  }
}

// On all led
void cubeON() {
  for(byte i=0;i<4;i++) {
    for(byte j=0;j<4;j++) {
      digitalWrite(xy[i][j],HIGH);    // Set all LED position pin to HIGH
    }
    digitalWrite(z[i],LOW);   // Set all LED layer pin to LOW
  }
}

// On one desired led
void ledON(byte xy, byte z) {
  digitalWrite(xy,HIGH);    // Set the desired LED position pin to HIGH
  digitalWrite(z,LOW);    // Set the desired LED layer pin to LOW
}

// Off one desired led
void ledOFF(byte xy, byte z) {
  digitalWrite(xy,LOW);   // Set the desired LED position pin to LOW
  digitalWrite(z,HIGH);   // Set the desired LED layer pin to HIGH
}

