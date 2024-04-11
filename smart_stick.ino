const int trigger = 2;  //Trigger pin of 1st Sesnor 
 
const int echo = 4;  //Echo pin of 1st Sesnor 
 
const int Buzz = 12;  //Echo pin of 1st Sesnor 
 
const int Light = A0;  //Echo pin of 1st Sesnor 
 
long time_taken; 
 
int dist; 
int br = 0; 
int dm = 0; 
 
int Intens; 
 
 
 
void setup() { 
 
  Serial.begin(9600); 
 
  pinMode(Buzz, OUTPUT); 
  pinMode(Light, OUTPUT); 
   
 
  pinMode(trigger, OUTPUT); 
 
  pinMode(echo, INPUT); 
} 
 
/*###Function to calculate distance###*/ 
 
void calculate_distance(int trigger, int echo) 
 
{ 
 
  digitalWrite(trigger, LOW); 
 
  delayMicroseconds(2); 
 
  digitalWrite(trigger, HIGH); 
 
  delayMicroseconds(10);
digitalWrite(trigger, LOW); 
 
  time_taken = pulseIn(echo, HIGH); 
 
  dist = time_taken * 0.034 / 2; 
 
  if (dist > 300) 
 
    dist = 300; 
} 
 
void loop() {  //infinite loopy 
 
  Intens = analogRead(Light); 
  calculate_distance(trigger, echo); 
   
  //Check if Remote is pressed 
 
  //If very dark 
 
  if (Intens < 400 && br<=1) 
 
  { 
    delay(400); 
    br++; 
    dm=0; 
    Serial.print(Intens); 
    Serial.println("Bright Light"); 
 
    digitalWrite(Buzz, HIGH); 
    delay(200); 
    digitalWrite(Buzz, LOW); 
    delay(200); 
    digitalWrite(Buzz, HIGH); 
    delay(200); 
 
    digitalWrite(Buzz, LOW); 
    delay(200); 
 
    delay(500); 
  } 
 
  //If very bright 
 
  if (Intens > 800 && dm<=1) 
 
  { 
    delay(400); 
    br=0; 
    dm++; 
 
    Serial.print(Intens); 
    Serial.println("Low Light");
 digitalWrite(Buzz, HIGH); 
    delay(500); 
    digitalWrite(Buzz, LOW); 
    delay(500); 
    digitalWrite(Buzz, HIGH); 
    delay(500); 
 
    digitalWrite(Buzz, LOW); 
    delay(500); 
  } 
 
  if (dist < 50) 
 
  { 
 
    Serial.print(dist); 
    Serial.println("Object Alert"); 
 
 
    digitalWrite(Buzz, HIGH); 
 
    for (int i = dist; i > 0; i--) 
 
      delay(10); 
 
    digitalWrite(Buzz, LOW); 
 
    for (int i = dist; i > 0; i--) 
 
      delay(10); 
  } 
   
 
} 
 
//Serial.print("dist="); 
 
//Serial.println(dist); 
 
//Serial.print("Similar_count=");
