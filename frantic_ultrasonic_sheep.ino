int trig1 = 4;
int echo1 = 3; 
int trig2 = 9;
int echo2 = 8; 

int c = 0;

void setup()
{
  pinMode(trig1, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  float dur1, dur2;
  float dist1, dist2;
  float gate = 150;
  
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, LOW);
  delayMicroseconds(2); 
  
  
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);  
  dur1 = pulseIn(echo1, HIGH);  
  dist1 = 0.034*(dur1/2);
  
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);  
  dur2 = pulseIn(echo2, HIGH);  
  dist2 = 0.034*(dur2/2);
  
  if(dist1<gate)
  {
    c++;
    delay(700); 
  }
  
  if(dist2<gate)
  {
    if(c>0){
      c--;
      delay(700);
    }  	
  }
  
  Serial.print("\nThe number of sheep inside the field= ");
  Serial.println(c);
  delay(500);
}