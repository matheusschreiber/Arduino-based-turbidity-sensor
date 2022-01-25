#define VERMELHO 12
#define LARANJA 11
#define AMARELO 10
#define VERDE 9
#define AZUL 8

#define LDR A0

int rtn = 0; 
  
void setup() {
  Serial.begin(9600);
  pinMode(VERMELHO, OUTPUT);
  pinMode(LARANJA, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);
  
  pinMode(LDR, INPUT);
  
  // todos os leds comecam desligados
  digitalWrite(VERMELHO, LOW);
  digitalWrite(LARANJA, LOW);
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  
}

int ledAceso = 0;
int ledsApagados[5] = { VERMELHO,LARANJA,AMARELO,VERDE,AZUL };

void loop() {    
  rtn = analogRead(LDR);
  Serial.println(rtn); // so para debugar
  
  for(int i;i<5;i++) digitalWrite(ledsApagados[i], LOW);
  
  // os valores condicionais sao para o caso de um resistor de
  // 2KOhms ligado ao LDR (vão precisar de ajustes quando for
  // finalizada a montagem presencial)
  
  if(rtn <= 300){ ledAceso = AZUL; } //limpíssima
  else if(rtn > 300 && rtn <= 350){ ledAceso = VERDE; } //limpa
  else if(rtn > 300 && rtn <= 400){ ledAceso = AMARELO; } //semi-limpa
  else if(rtn > 400 && rtn <= 600){ ledAceso = LARANJA; } //semi-turva
  else if(rtn > 600 && rtn <= 1012){ ledAceso = VERMELHO; } //turva

  digitalWrite(ledAceso, HIGH);
  
  delay(500);
}