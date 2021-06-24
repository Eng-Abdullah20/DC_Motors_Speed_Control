
void setup() {
int  motorSpeed1 = 0;
int  motorSpeed2 = 0;

  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  int xAxis = analogRead(A0); // Read Joystick's X-axis movement
  int yAxis = analogRead(A1); // Read Joystick's Y-axis movement
  // Y-axis used for vertical control (forward and backward)
  if (yAxis <= 50) {
    // move Motor 1 backwards
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // move Motor 2 backwards
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    // Convert the declining Y-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed
    motorSpeedA = map(yAxis, 50, 0, 0, 255);
    motorSpeedB = map(yAxis, 50, 0, 0, 255);
  }
  else if( 50<yAxis < 470 )  {
    // move Motor 1 backwards
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // move Motor 2 backwards
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    // Convert the declining Y-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed
    motorSpeedA = map(yAxis, 50, 470, 0, 150);
    motorSpeedB = map(yAxis, 50, 470, 0, 150);
    
  else if (yAxis >= 950) {
    // move Motor 1 forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // move Motor 2 forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    // Convert the increasing Y-axis readings for going forward from 550 to 1023 into 0 to 255 value for the PWM signal for increasing the motor speed
    motorSpeedA = map(yAxis, 950, 1023, 0, 255);
    motorSpeedB = map(yAxis, 950, 1023, 0, 255);
  }
    else if (550 < yAxis < 950) {
    // move Motor 1 forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // move Motor 2 forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    // Convert the increasing Y-axis readings for going forward from 550 to 1023 into 0 to 255 value for the PWM signal for increasing the motor speed
    motorSpeedA = map(yAxis, 550, 950, 0, 150);
    motorSpeedB = map(yAxis, 1020, 1023, 0, 150);
  // If joystick stays in middle the motors are not moving
  else {
    motorSpeedA = 0;
    motorSpeedB = 0;
  }
  // X-axis used for horizontal control (robot rotation)
   if (xAxis < 470) {
     // Convert the declining X-axis readings from 470 to 0 into increasing 0 to 255 value
    int xMapped = map(xAxis, 470, 0, 0, 255);
    // Move to left - decrease left motor speed, increase right motor speed
    motorSpeed1 = motorSpeed1 - xMapped;
    motorSpeed2 = motorSpeed2 + xMapped;
    // Confine the range from 0 to 255
    if (motorSpeedA < 0) {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255) {
      motorSpeedB = 255;
    }
  }
  if (xAxis > 550) {
    // Convert the increasing X-axis readings from 550 to 1023 into 0 to 255 value
    int xMapped = map(xAxis, 550, 1023, 0, 255);
    // Move right - decrease right motor speed, increase left motor speed
    motorSpeed1 = motorSpeed1 + xMapped;
    motorSpeed2 = motorSpeed2 - xMapped;
    // Confine the range from 0 to 255
    if (motorSpeed1 > 255) {
      motorSpeed1 = 255;
    }
    if (motorSpeedB < 0) {
      motorSpeedB = 0;
    }

  analogWrite(en1, motorSpeed1); // Send output signal to motor 1
  analogWrite(en2, motorSpeed2); // Send output signal to motor 2
}
  }
