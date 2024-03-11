
#include <Servo.h> 
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;

const int PUL = 10;
const int s1 = 8;
const int s2 = 9;
bool run = false;
int xung = 150;

void setup() { 

  Serial.begin(9600);
  // servo: 7,2,...->6: tu tren xuong duoi
  myservo1.attach(7);
  myservo2.attach(2);
  myservo3.attach(3);
  myservo4.attach(4);
  myservo5.attach(5);
  myservo6.attach(6); 
  // home 
  myservo1.write(30); // 30: mở; 90: đóng
  myservo2.write(100); // ngang: 100; doc theo chieu bang tai: 0
  myservo3.write(60); // 0: thẳng ra; 60: gap lai
  myservo4.write(30); // 30: gap lai; 100: thang ra
  myservo5.write(80); // 70: dung; 30: nga toi;
  myservo6.write(70);  // 70: ngang; 80: qua trái; 60: qua phai(huong ve mach)
  // PUL TB6600
  pinMode(PUL, OUTPUT);
} 


void loop() {
  if (Serial.available()){
    String inputSerial = Serial.readString();
    inputSerial.trim();
    Serial.print("Input: "); Serial.println(inputSerial);
    if (inputSerial.equals("c")){
      gap_vat();
      delay(30);
      di_chuyen_tha_vat(); 
      Serial.println("here");
    }  else {
      Serial.println("Không so sánh được");
    }
  }
  
}
void gap_vat(){
  myservo5.write(70);
  delay(500);
  for (int i = 30; i<90; i=i+10){myservo1.write(i);delay(100); };
  delay(500);
  myservo5.write(80);
}
void di_chuyen_tha_vat(){
  for (int i = 70 ; i<160; i++){myservo6.write(i);delay(200); };
  delay(500);
  for (int i = 80; i>30; i=i-10){myservo1.write(i);delay(100); };
  delay(500);
  for (int i = 160 ; i>70; i--){myservo6.write(i);delay(200); };
}
