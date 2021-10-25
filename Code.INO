int verde_1= 13;
int verde_2=12;
int amarillo_1=11;
int amarillo_2=10;
int rojo_1=9;
int rojo_2=8;
long DURACION;
long DISTANCIA;

int TRIG = 7;
int ECHO=6;
void setup() {
 Serial.begin(9600);
 pinMode(verde_1, OUTPUT);
 pinMode(verde_2, OUTPUT);
 pinMode(amarillo_1,OUTPUT);
 pinMode(amarillo_2, OUTPUT);
 pinMode(rojo_1, OUTPUT);
 pinMode(rojo_2, OUTPUT);
 pinMode(TRIG, OUTPUT);
 pinMode(ECHO, INPUT);
 DURACION = pulseIn(ECHO, HIGH);
  Serial.begin(9600);
 
  

}

void loop() {
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG,LOW);
  DURACION = pulseIn(ECHO, HIGH);
  DISTANCIA = DURACION/58.2;
  Serial.println(DISTANCIA);
  if (DISTANCIA<=35 && DISTANCIA>15) {
     
    digitalWrite(verde_1, HIGH);
    digitalWrite(verde_2, LOW);
    digitalWrite(amarillo_2, LOW);
    digitalWrite(amarillo_1, LOW);
    digitalWrite(rojo_1, LOW);
    digitalWrite(rojo_2, LOW);
    tone(6, 500);
    delay(800);
   digitalWrite(verde_1, LOW);
   digitalWrite(verde_2, HIGH);
   tone(6,500);
   delay(800);
   DISTANCIA = DURACION/58.2;
  }
  else if (DISTANCIA<=15 && DISTANCIA >8) {
     DISTANCIA = DURACION/58.2;
    digitalWrite(amarillo_1, HIGH);
    digitalWrite(amarillo_2,LOW);
    digitalWrite(verde_1, LOW);
    digitalWrite(verde_2, LOW);
    digitalWrite(rojo_1, LOW);
    digitalWrite(rojo_2, LOW);
    tone(6, 400);
    delay(600);
   digitalWrite(amarillo_1, LOW);
   digitalWrite(amarillo_2, HIGH);
   tone(6,400);
   delay(600);
    DISTANCIA = DURACION/58.2;
  }
  else if(DISTANCIA<=8 && DISTANCIA >1) {
   
     digitalWrite(amarillo_1, LOW);
    digitalWrite(amarillo_2,LOW);
    digitalWrite(verde_1, LOW);
    digitalWrite(verde_2, LOW);
    digitalWrite(rojo_1, HIGH);
    digitalWrite(rojo_2, LOW);
    tone(6, 300);
    delay(300);
   digitalWrite(rojo_1, LOW);
   digitalWrite(rojo_2, HIGH);
   tone(6,300);
   delay(300);
    DISTANCIA = DURACION/58.2;
  }
  else {
    
    noTone(6);
    digitalWrite(verde_1, LOW);
    digitalWrite(verde_2, LOW);
    digitalWrite(amarillo_1, LOW);
    digitalWrite(amarillo_2, LOW);
    digitalWrite(rojo_1, LOW);
    digitalWrite(rojo_2, LOW);
  
    
  }
  
 
