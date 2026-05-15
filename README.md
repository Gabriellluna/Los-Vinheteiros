# 🍷 Los Vinheteiros - Adega Inteligente

## 📝 Descrição do Projeto
Este projeto foi desenvolvido como parte da avaliação da disciplina de Eletrônica do curso de Engenharia de Software da **FIAP**.

O **Los Vinheteiros** é um sistema de monitoramento ambiental focado na preservação de vinhos finos em adegas. O projeto utiliza sensores para capturar variações de luminosidade, temperatura e umidade, processando esses dados via Arduino para garantir que a maturação da bebida ocorra em condições ideais, evitando a oxidação e o ressecamento de rolhas.

---

## 💻 Estratégia de Desenvolvimento (Simulação vs. Real)
Devido às limitações técnicas do simulador **Tinkercad**, que não possui o sensor digital DHT11 em seu catálogo, adotamos uma estratégia de **Hardware Mocking** na pasta `/src` para validar a lógica de software:

* **Ambiente de Simulação (Tinkercad):** * Utilizamos o sensor **TMP36** (Analógico) para leitura de Temperatura.
    * Utilizamos um **Potenciômetro** (Analógico) para simular a variação da Umidade.
* **Ambiente Real:** * Utilizamos o sensor **DHT11** (Digital) para capturar temperatura e umidade de forma integrada e precisa.

---

## ⚙️ Regras de Preservação (Business Rules)

### 💡 1. Luminosidade (Proteção UV)
A exposição excessiva à luz pode comprometer a estrutura química do vinho. O sistema monitora a incidência:
* **Abaixo de 300 (Escuro):** Condição ideal. LED Verde aceso.
* **Entre 300 e 699 (Meia Luz):** Alerta de atenção. LED Amarelo aceso.
* **Acima de 700 (Muito Claro):** Risco crítico de oxidação. **Buzzer** e LED Vermelho acionados.

### 🌡️ 2. Temperatura (Estabilidade Térmica)
Vinhos de guarda exigem estabilidade absoluta, idealmente entre 10°C e 15°C:
* **10°C a 15°C:** Temperatura ideal. LCD exibe: "Temperatura OK".
* **Fora da faixa:** Indica "Temp. Alta" ou "Temp. Baixa" no LCD, aciona LED Amarelo e **Buzzer**.

### 💧 3. Umidade (Preservação da Rolha)
A umidade controlada evita o ressecamento da rolha ou a proliferação de fungos:
* **50% a 70%:** Umidade ideal. LCD exibe: "Umidade OK".
* **Fora da faixa:** Indica "Umid. Alta" ou "Umid. Baixa" no LCD, aciona LED Vermelho e **Buzzer**.

---

## 🛠️ Hardware e Materiais

* **1x Placa Arduino Uno R3**
* **1x Display LCD 16x2 com Módulo I2C**
* **1x Sensor de Temperatura e Umidade (DHT11 - Físico / TMP36 - Simulação)**
* **1x Potenciômetro** (Apenas para simulação de umidade no Tinkercad)
* **1x Sensor de Luminosidade (LDR)**
* **3x LEDs** (Verde, Amarelo e Vermelho)
* **1x Buzzer**
* **Resistores** (10kΩ para LDR e 220Ω para LEDs)
* **Protoboard e Jumpers**

---

## 🔌 Esquema de Ligação — Pinagem

| Componente | Pino no Arduino | Função |
|---|---|---|
| LDR | A0 | Leitura de Luminosidade |
| Sensor Temp (TMP3) | A1 | Leitura de Temperatura (Simulação) |
| Potenciômetro | A2 | Simulação de Umidade |
| DHT11 | D2 | Leitura Digital Temp/Umid (Físico) |
| Buzzer | D7 | Alerta Sonoro |
| LED Verde | D8 | Status: Ideal |
| LED Amarelo | D9 | Status: Atenção |
| LED Vermelho | D10 | Status: Crítico |
| LCD (SDA) | SDA | Comunicação I2C |
| LCD (SCL) | SCL | Comunicação I2C |

---

## 🚀 Como Reproduzir o Projeto

1.  **Hardware:** Monte o circuito seguindo a tabela de pinagem. Se estiver no Tinkercad, utilize o TMP36 e o Potenciômetro.
2.  **Software:** * Instale as bibliotecas `LiquidCrystal_I2C` e `DHT sensor library` na Arduino IDE.
    * Carregue o código correspondente ao seu ambiente (Pasta `/src`).
3.  **Monitoramento:** Abra o Monitor Serial (9600 baud) para acompanhar as leituras brutas ou observe o Display LCD para os estados do sistema.

---

## ✅ Soluções Adotadas e Dificuldades
* **Média Móvel:** O código implementa uma média de 5 leituras para o sensor LDR, evitando disparos falsos por variações bruscas de luz.
* **I2C Integration:** O uso do módulo I2C reduziu a complexidade de fios no projeto, facilitando a manutenção e organização na protoboard.
* **Mocking:** Superação da ausência do DHT11 no Tinkercad através de entradas analógicas mapeadas via software.

---

## 🔗 Links de Acesso
* **Simulação Tinkercad:** [Clique Aqui](https://www.tinkercad.com/things/3He1tPOllec-sensor-de-luminosidadetemperaturaumidade/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fall)
* **Repositório GitHub:** [Los-Vinheteiros](https://github.com/Gabriellluna/Los-Vinheteiros)
* * **Vídeo no Youtube:** [Vídeo](https://youtu.be/Kw74fmqsVcA)

---

## 👨‍💻 Equipe - Los Vinheteiros
* **Bruno Guilherme Gonçalves de Oliveira** - RM: 573697
* **Gabriel Cardoso de Sá Finzetto** - RM: 571846
* **Gabriel Luna Maia** - RM: 570982
* **João Lucas Magordo Rodrigues** - RM: 572419
* **Murilo Vieira dos Reis** - RM: 573764

---
*Projeto acadêmico - FIAP (2026).*
