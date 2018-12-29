#include <Ultrasonic.h>

//Ponte H
int IN1 = 2;
int IN2 = 4;
int IN3 = 6;
int IN4 = 7;
int velocidadeA = 3;
int velocidadeB = 5;

//Ultrasonic
#define TRIGGER_PIN  13
#define ECHO_PIN     12
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

//Bluetooth
int val = 0;
 
void setup() {  
  Serial.begin(9600);
  
  //Define os pinos para a ponte H como saida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(velocidadeA,OUTPUT);
  pinMode(velocidadeB,OUTPUT);
}  
    
void loop()  {     
  val=Serial.read();
  //Sensor de distancia, freia com obstaculo a frente
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  // Valores do bluetooth
  if (val=='f') {
    andaParaFrente(); 
  }
  if (val=='a') {
    andaParaTras(); 
  }
  if (val=='e') {
    viraParaEsquerda(); 
  }
  if (val=='d') {
    viraParaDireita(); 
  }
  if (val=='q' || cmMsec < 10) {  
    freia();
  }
}

//Funções para a movimentação do robô

void andaParaFrente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(velocidadeA,255);
  analogWrite(velocidadeB,255);
}

void andaParaTras() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void viraParaEsquerda() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void viraParaDireita() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void freia() {
  if (val=='a') {
    andaParaTras(); 
  } else {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH); 
  }
}
