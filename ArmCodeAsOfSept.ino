//www.elegoo.com
//2016.12.12

/************************
Exercise the motor using
the L293D chip
************************/

#define ENABLE 3
#define DIRA 5
#define DIRB 4
#define OPEN A14
#define HANDCLOSE 24
#define HANDOPEN 29

//Wrist Setting
#define enaW 7 //enaWble or motor
#define dirW 2 //determines the address
#define pulW 6 //execute a step



int interval = 3000; //interval between as
bool pulseW = LOW; //pulseW status
bool pulseE = LOW;
#define Wup 30
#define Wdn 23

const int BENCHMARK = 500;
 
void setup() {
  //---set pin direction
  Serial.begin(9600);

  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(OPEN, INPUT);


  pinMode(enaW, OUTPUT);
  pinMode(dirW, OUTPUT);
  pinMode(pulW, OUTPUT);
  pinMode(Wup, INPUT);
  pinMode(Wdn, INPUT);
  //digitalWrite(enaW, LOW); //enaWble em low inverted
  //digitalWrite(dirW, HIGH); // low CW / high CCW
  //digitalWrite(pulW, HIGH); //deciding edge
}

void loop() {
  analogWrite(ENABLE, 255); // Any value between 0 and 255
  int yolo = analogRead(OPEN);

  Serial.println(yolo);

  digitalWrite(DIRA, HIGH);

  digitalWrite(DIRB, LOW);

  if (yolo > BENCHMARK) {
    digitalWrite(DIRA, HIGH);

    digitalWrite(DIRB, LOW);
  } else {
    digitalWrite(DIRB, HIGH);

    digitalWrite(DIRA, LOW);
  }





  digitalWrite(pulW, pulseW); //attribute the new status to the portal
  delayMicroseconds(interval);


  if(digitalRead(Wup) == HIGH){
    //digitalWrite(enaW, LOW);
    digitalWrite(dirW, HIGH);
    //interval = 3000;
    pulseW = !pulseW;
  }
  else if(digitalRead(Wdn) == HIGH){
    //digitalWrite(enaW, LOW);
    digitalWrite(dirW, LOW);
    //interval = 3000;
    pulseW = !pulseW;
  }


}