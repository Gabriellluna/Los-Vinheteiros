
const int pinoLDR = A0;
const int ledVerde = 7;
const int ledAmarelo = 6;
const int ledVermelho = 5;
const int buzzer = 4;

const int limiteAlerta = 300;
const int limiteProblema = 600;

unsigned long tempoInicioBuzzer = 0;
bool buzzerAtivo = false;
bool problemaAnterior = false;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  
  Serial.begin(9600);
}

void loop() {
  int luminosidade = analogRead(pinoLDR);
  
  bool problema = (luminosidade >= limiteProblema);
  bool alerta = (!problema && luminosidade >= limiteAlerta);
  bool ok = (!problema && !alerta);
  
  digitalWrite(ledVerde, ok ? HIGH : LOW);
  digitalWrite(ledAmarelo, alerta ? HIGH : LOW);
  digitalWrite(ledVermelho, problema ? HIGH : LOW);
  
  if (problema) {
    if (!buzzerAtivo) {
      tone(buzzer, 1000);
      tempoInicioBuzzer = millis();
      buzzerAtivo = true;
    } else {
      if (millis() - tempoInicioBuzzer >= 3000) {
        noTone(buzzer);
        buzzerAtivo = false;
        delay(500);
      }
    }
  } else {
    if (buzzerAtivo) {
      noTone(buzzer);
      buzzerAtivo = false;
    }
  }
  
  delay(500);
  
  Serial.print("Luminosidade: ");
  Serial.print(luminosidade);
  Serial.print(" | Estado: ");
  if (ok) Serial.println("OK (Verde)");
  else if (alerta) Serial.println("ALERTA (Amarelo)");
  else Serial.println("PROBLEMA (Vermelho)");
}