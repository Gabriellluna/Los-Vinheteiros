#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
#include <DHT.h>               

LiquidCrystal_I2C lcd(0x27, 16, 2); 

#define DHTPIN 2       
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE); 

const int pinoLDR = A0;   
const int ledVerde = 8;     
const int ledAmarelo = 9;   
const int ledVermelho = 10; 
const int pinoBuzzer = 7;   

void setup() { 
  lcd.init();      
  lcd.backlight(); 
  
  pinMode(ledVerde, OUTPUT); 
  pinMode(ledAmarelo, OUTPUT); 
  pinMode(ledVermelho, OUTPUT); 
  pinMode(pinoBuzzer, OUTPUT); 
  
  Serial.begin(9600); // Inicializa a comunicação serial
  dht.begin(); 
  
  Serial.println("Sistema Iniciado. Lendo sensores...");
}

void loop() { 
  
  float somaLuz = 0; 
  for (int i = 0; i < 5; i++) { 
    somaLuz += analogRead(pinoLDR); 
    delay(50); 
  } 
  int luz = somaLuz / 5; 

  float temp = dht.readTemperature(); 
  float umid = dht.readHumidity();    

  if (isnan(temp) || isnan(umid)) {
    Serial.println("Falha ao ler o sensor DHT!");
  } else {
    
    Serial.print("Luminosidade: ");
    Serial.print(luz);
    Serial.print(" | Temperatura: ");
    Serial.print(temp, 1);
    Serial.print(" C | Umidade: ");
    Serial.print(umid, 0);
    Serial.println(" %");
  }

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
    msgUmid2 = String(umid, 0) + " %"; 
  } 
  else { 
    estadoVermelho = true; 
    estadoBuzzer = true;   
    
    if (umid > 70) {        
      msgUmid1 = "Umidade Alta"; 
    } else {                       
      msgUmid1 = "Umidade Baixa"; 
    }
    msgUmid2 = String(umid, 0) + " %"; 
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