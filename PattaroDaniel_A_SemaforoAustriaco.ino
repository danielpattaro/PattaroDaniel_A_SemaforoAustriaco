
int r1=8;
int g1= 9;
int v1= 10;
int r2=3;
int g2= 4;
int v2= 5;
int temporv = 0;
int tempog = 0;
int lampeggi=0;
int t=0;

void semaforo ()
{
  digitalWrite(r1, HIGH);
  digitalWrite(v2, HIGH);
  delay(temporv-(t*lampeggi));
  digitalWrite(g1, HIGH);
  digitalWrite(g2, HIGH);
  delay(tempog-(t*lampeggi));
  int a = lampeggi;
  while (a>=0)
  {
  digitalWrite(v2, LOW);
  delay(t);
  digitalWrite(v2, HIGH);
  delay(t);
  a--;
  }
  a = lampeggi;
  digitalWrite(v2, LOW);
  //delay(a);
  digitalWrite(r1, LOW);
  digitalWrite(g1, LOW);
  digitalWrite(g2, LOW);
  digitalWrite(v1, HIGH);
  digitalWrite(r2, HIGH);
  delay(temporv-(t*lampeggi));
  digitalWrite(g2, HIGH);
  digitalWrite(g1, HIGH);
  delay(tempog-(t*lampeggi));
  while (a>=0)
  {
  digitalWrite(v1, LOW);
  delay(t);
  digitalWrite(v1, HIGH);
  delay(t);
  a--;
  }
  a = lampeggi;
  
  digitalWrite(v1, LOW);
  digitalWrite(g2, LOW);
  digitalWrite(g1, LOW);
  digitalWrite(r2, LOW);
}


void setup() {
  // put your setup code here, to run once:

  pinMode (r1, OUTPUT);
  pinMode (g1, OUTPUT);
  pinMode (v1, OUTPUT);
  pinMode (r2, OUTPUT);
  pinMode (g2, OUTPUT);
  pinMode (v2, OUTPUT);  

 Serial.begin(9600);
 Serial.println("Seriale attiva");

  
  while (t<=0 || lampeggi<=0 || temporv<=0 || tempog<=0 )
  { 
    Serial.println("Durata rosso/verde: ");
    while(Serial.available()==0){};
    temporv=Serial.readString().toInt();

    Serial.println("Durata giallo: ");
    while(Serial.available()==0){};
    tempog=Serial.readString().toInt();

    do
   { Serial.println("Numero lampeggi: ");
    while(Serial.available()==0){};
    lampeggi=Serial.readString().toInt();

    Serial.println("Durata lampeggi");
    while(Serial.available()==0){};
    t=Serial.readString().toInt();
   }
   while (lampeggi*t > tempog);
  

  }
  
 
}

void loop() {
  

  semaforo();


}
