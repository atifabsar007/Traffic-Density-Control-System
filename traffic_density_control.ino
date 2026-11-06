// Advanced Arduino Project
// Episode 7: Traffic Density Control System

// Traffic Lights Road 1
int red1 = 8;
int yellow1 = 7;
int green1 = 6;

// Traffic Lights Road 2
int red2 = 3;
int yellow2 = 4;
int green2 = 5;

// Ultrasonic Sensors
const int trig1 = 10;
const int echo1 = 9;

const int trig2 = 12;
const int echo2 = 11;

void setup() {
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);

  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);

  // Configure ultrasonic sensor pins explicitly.
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  // Start from a safe all-red state.
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(green2, LOW);

  Serial.begin(9600);
}

// -------- LOOP --------
void loop() {

  int distance1 = calculateDistance(trig1, echo1);
  int distance2 = calculateDistance(trig2, echo2);

  Serial.print("Road1: "); Serial.print(distance1);
  Serial.print(" cm | Road2: "); Serial.println(distance2);

  // -------- PRIORITY LOGIC --------
  // A negative distance means that sensor timed out or returned no echo.
  if (distance1 < 0 && distance2 < 0) {
    // Do not grant green when neither lane has a trustworthy reading.
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    Serial.println("Sensor timeout on both roads; keeping both roads RED.");
    delay(250);
    return;
  }

  if (distance1 < 0) {
    controlTraffic(2); // Only Road 2 has a valid reading.
  } else if (distance2 < 0) {
    controlTraffic(1); // Only Road 1 has a valid reading.
  } else if (distance1 < distance2) {
    controlTraffic(1);
  } else {
    controlTraffic(2);
  }

  delay(500);
}

// -------- TRAFFIC CONTROL FUNCTION --------
void controlTraffic(int road) {

  // Yellow transition
  digitalWrite(yellow1, HIGH);
  digitalWrite(yellow2, HIGH);
  delay(500);

  digitalWrite(yellow1, LOW);
  digitalWrite(yellow2, LOW);

  if (road == 1) {
    // Road 1 Green
    digitalWrite(green1, HIGH);
    digitalWrite(red1, LOW);

    digitalWrite(green2, LOW);
    digitalWrite(red2, HIGH);

    delay(5000);
  }
  else {
    // Road 2 Green
    digitalWrite(green2, HIGH);
    digitalWrite(red2, LOW);

    digitalWrite(green1, LOW);
    digitalWrite(red1, HIGH);

    delay(5000);
  }

  // Reset to RED before next cycle
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(green1, LOW);
  digitalWrite(green2, LOW);
}

// -------- DISTANCE FUNCTION --------
int calculateDistance(int trig, int echo) {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Bound the echo wait so a disconnected sensor cannot block the controller.
  unsigned long duration = pulseIn(echo, HIGH, 30000UL);

  if (duration == 0) {
    return -1; // No echo received within the timeout.
  }

  int distance = static_cast<int>(duration * 0.034 / 2.0);
  return distance;  // in cm
}
