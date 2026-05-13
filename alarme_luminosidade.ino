#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);


const int pinoLDR = A0;   
const int pinoTemp = A1;  
const int pinoUmid = A2;  


const int ledVerde = 8;
const int ledAmarelo = 9;
const int ledVermelho = 10;
const int pinoBuzzer = 7;

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  float somaLuz = 0, somaTemp = 0, somaUmid = 0;

  for (int i = 0; i < 5; i++) {
    somaLuz += analogRead(pinoLDR);

    int leituraTemp = analogRead(pinoTemp);
    float tensao = leituraTemp * 5.0 / 1024.0;
    somaTemp += (tensao - 0.5) * 100.0;

    somaUmid += map(analogRead(pinoUmid), 0, 1023, 0, 100);

    delay(50);
  }

  int luz = somaLuz / 5;
  float temp = somaTemp / 5.0;
  int umid = somaUmid / 5;

  bool estadoVerde = false;
  bool estadoAmarelo = false;
  bool estadoVermelho = false;
  bool estadoBuzzer = false;

  String msgLuz1 = "", msgLuz2 = "";
  String msgTemp1 = "", msgTemp2 = "";
  String msgUmid1 = "", msgUmid2 = "";

  if (luz < 300) { 
    estadoVerde = true; 
    msgLuz1 = "Ambiente Escuro";
  } 
  else if (luz >= 300 && luz < 700) { 
    estadoAmarelo = true; 
    msgLuz1 = "Ambiente a";
    msgLuz2 = "meia luz";
  } 
  else { 
    estadoVermelho = true; 
    estadoBuzzer = true;   
    msgLuz1 = "Ambiente muito";
    msgLuz2 = "claro";
  }

  if (temp >= 10 && temp <= 15) { 
    msgTemp1 = "Temperatura OK";
    msgTemp2 = String(temp, 1) + " C";
  } 
  else {
    estadoAmarelo = true; 
    estadoBuzzer = true;  
    
    if (temp > 15) {      
      msgTemp1 = "Temp. Alta";
    } else {              
      msgTemp1 = "Temp. Baixa";
    }
    msgTemp2 = String(temp, 1) + " C";
  }

  if (umid >= 50 && umid <= 70) { 
    msgUmid1 = "Umidade OK";
    msgUmid2 = String(umid) + " %";
  } 
  else {
    estadoVermelho = true; 
    estadoBuzzer = true;   
    
    if (umid > 70) {       
      msgUmid1 = "Umidade. Alta";
    } else {               
      msgUmid1 = "Umidade. Baixa";
    }
    msgUmid2 = String(umid) + " %";
  }

  digitalWrite(ledVerde, estadoVerde);
  digitalWrite(ledAmarelo, estadoAmarelo);
  digitalWrite(ledVermelho, estadoVermelho);

  if (estadoBuzzer) {
    tone(pinoBuzzer, 1000);
  } else {
    noTone(pinoBuzzer);
  }

  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(msgLuz1);
  lcd.setCursor(0, 1);
  lcd.print(msgLuz2);
  delay(1600);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(msgTemp1);
  lcd.setCursor(0, 1);
  lcd.print(msgTemp2);
  delay(1600);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(msgUmid1);
  lcd.setCursor(0, 1);
  lcd.print(msgUmid2);
  delay(1550); 
}
