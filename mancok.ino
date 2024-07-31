#include <ESP32Servo.h>

const int RPWM = 25; // Pin A0 untuk LDR
const int LPWM = 26; // Pin GPIO13 untuk Servo
const int RLen = 27; // Pin GPIO32 untuk LED
const int SERVOpin = 15;
Servo myServo;

void setup() {
  Serial.begin(115200);
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
  pinMode(RLen, OUTPUT); // Servo pada posisi awal
  myServo.attach(SERVOpin); // Menghubungkan servo ke pin
}
void loop (){
  CONVEYOR();
  SERVO();
}

void CONVEYOR() {
  digitalWrite(RPWM, HIGH);
   digitalWrite(LPWM, LOW);
    digitalWrite(RLen, 255);  
}
void SERVO() {
  // Gerakkan servo dari 0 hingga 180 derajat
  for (int angle = 60; angle <= 90; angle++) {
    myServo.write(angle); // Setel posisi servo
    delay(15); // Tunggu servo untuk mencapai posisi
  }

  delay(5); // Jeda 1 detik

  // Gerakkan servo dari 180 hingga 0 derajat
  for (int angle = 90; angle >= 60; angle--) {
    myServo.write(angle); // Setel posisi servo
    delay(15); // Tunggu servo untuk mencapai posisi
  }

  delay(5); // Jeda 1 detik
}
  
