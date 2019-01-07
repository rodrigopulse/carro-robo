#include <Ultrasonic.h>

//Ponte H
int IN1a = 2;
int IN2a = 3;
int IN3a = 4;
int IN4a = 5;

int IN1b = 8;
int IN2b = 9;
int IN3b = 10;
int IN4b = 11;

//Ultrasonic
#define TRIGGER_PIN  13
#define ECHO_PIN     12
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

//Bluetooth
int val = 0;
 
void setup() {  
  Serial.begin(9600);
  
  //Define os pinos para a ponte H como saida
  pinMode(IN1a, OUTPUT);
  pinMode(IN2a, OUTPUT);
  pinMode(IN3a, OUTPUT);
  pinMode(IN4a, OUTPUT);
  pinMode(IN1b, OUTPUT);
  pinMode(IN2b, OUTPUT);
  pinMode(IN3b, OUTPUT);
  pinMode(IN4b, OUTPUT);
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
  digitalWrite(IN1a, HIGH);
  digitalWrite(IN2a, LOW);
  digitalWrite(IN3a, HIGH);
  digitalWrite(IN4a, LOW);
  digitalWrite(IN1b, HIGH);
  digitalWrite(IN2b, LOW);
  digitalWrite(IN3b, HIGH);
  digitalWrite(IN4b, LOW);
}

void andaParaTras() {
  digitalWrite(IN1a, LOW);
  digitalWrite(IN2a, HIGH);
  digitalWrite(IN3a, LOW);
  digitalWrite(IN4a, HIGH);
  digitalWrite(IN1b, LOW);
  digitalWrite(IN2b, HIGH);
  digitalWrite(IN3b, LOW);
  digitalWrite(IN4b, HIGH);
}

void viraParaEsquerda() {
  digitalWrite(IN1a, HIGH);
  digitalWrite(IN2a, LOW);
  digitalWrite(IN3a, LOW);
  digitalWrite(IN4a, HIGH);
  digitalWrite(IN1b, HIGH);
  digitalWrite(IN2b, LOW);
  digitalWrite(IN3b, LOW);
  digitalWrite(IN4b, HIGH);
}

void viraParaDireita() {
  digitalWrite(IN1a, LOW);
  digitalWrite(IN2a, HIGH);
  digitalWrite(IN3a, HIGH);
  digitalWrite(IN4a, LOW);
  digitalWrite(IN1b, LOW);
  digitalWrite(IN2b, HIGH);
  digitalWrite(IN3b, HIGH);
  digitalWrite(IN4b, LOW);
}

void freia() {
  digitalWrite(IN1a, HIGH);
  digitalWrite(IN2a, HIGH);
  digitalWrite(IN3a, HIGH);
  digitalWrite(IN4a, HIGH);
  digitalWrite(IN1b, HIGH);
  digitalWrite(IN2b, HIGH);
  digitalWrite(IN3b, HIGH);
  digitalWrite(IN4b, HIGH);
}
