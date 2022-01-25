#define VERMELHO 13
#define LARANJA 12
#define AMARELO 11
#define VERDE 10
#define LDR A0

int rtn = 0; 
  
void setup()
{
  Serial.begin(9600);
  pinMode(VERMELHO, OUTPUT);
  pinMode(LARANJA, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(LDR, INPUT);
}


void loop()
{
  // todos os leds comecam desligados
  if(rtn == 0){ // so vai entrar na primeira passada
    digitalWrite(VERMELHO, LOW);
    digitalWrite(LARANJA, LOW);
    digitalWrite(AMARELO, LOW);
    digitalWrite(VERDE, LOW);
  }
  
  rtn = analogRead(LDR);
  Serial.println(rtn); // so para debugar
  delay(1000);
  
  // os valores condicionais sao para o caso de um resistor de
  // 2Kohms antes do LDR
  
  if(rtn >= 207 && rtn <= 409){ // turva
    // ligando verde
  	digitalWrite(VERDE, HIGH);
    
    // desligando todas as outras
    digitalWrite(LARANJA, LOW);
    digitalWrite(AMARELO, LOW);
    digitalWrite(VERMELHO, LOW);
    
  } else if(rtn > 409 && rtn <= 610){ // semi-turva
    // ligando amarelo
  	digitalWrite(AMARELO, HIGH);
    
    // desligando todas as outras
    digitalWrite(VERMELHO, LOW);
    digitalWrite(LARANJA, LOW);
    digitalWrite(VERDE, LOW);
      
  } else if(rtn > 610 && rtn <= 811){ // semi-limpa
    // ligando laranja
  	digitalWrite(LARANJA, HIGH);
    
    // desligando todas as outras
    digitalWrite(VERMELHO, LOW);
    digitalWrite(AMARELO, LOW);
    digitalWrite(VERDE, LOW);
    
      
  } else if(rtn > 811 && rtn <= 1012){ // limpa
    // ligando vermelho
  	digitalWrite(VERMELHO, HIGH);
    
    // desligando todas as outras
    digitalWrite(VERDE, LOW);
    digitalWrite(LARANJA, LOW);
    digitalWrite(AMARELO, LOW);
    
  }
}