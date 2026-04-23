# Los Vinheteiros
## Alarme de Monitoramento de Luminosidade com Arduino

## 📝 Descrição do Projeto
Este projeto implementa um sistema de monitoramento de luz ambiente utilizando um Arduino e um sensor LDR (Fotoresistor). O sistema capta a luminosidade e a classifica em três níveis ("OK", "Alerta" e "Problema"), acionando indicadores visuais (LEDs) e sonoros (Buzzer) quando a luz ultrapassa limites pré-estabelecidos. A lógica principal é voltada para detectar o **excesso de luz**.

### Comportamento do Sistema:
* **Luz Normal (OK):** LED Verde aceso.
* **Luz Elevada (Alerta):** LED Amarelo aceso.
* **Luz Crítica (Problema):** LED Vermelho aceso e acionamento de um Buzzer por 3 segundos (que volta a tocar se o problema persistir).

---

## 🛠️ Dependências e Materiais

**Hardware:**
* 1x Placa Arduino (Uno, Nano, Mega, etc.) e Cabo USB
* 1x Sensor LDR (Fotoresistor)
* 1x Resistor de 10kΩ (para o divisor de tensão do LDR)
* 3x LEDs (1 Verde, 1 Amarelo, 1 Vermelho)
* 3x Resistores de 220Ω ou 330Ω (para proteção dos LEDs)
* 1x Buzzer Ativo (Piezo)
* 1x Protoboard
* Fios Jumper diversos

**Software:**
* [Arduino IDE](https://www.arduino.cc/en/software) (para gravação na placa física)
* Ou simulador [Tinkercad](https://www.tinkercad.com/) (para testes e prototipagem virtual)

---

## 🔌 Esquema de Ligação (Pinagem)

| Componente | Pino no Arduino | Conexão Adicional na Protoboard |
| :--- | :--- | :--- |
| **LDR (Sensor)** | `A0` (Sinal) | Perna 1 conectada aos **5V**. Perna 2 conectada ao **A0** E a um resistor de 10kΩ que vai para o **GND**. |
| **LED Verde** | `D7` | Perna negativa (cátodo) vai para o **GND** através de um resistor de 220Ω. |
| **LED Amarelo**| `D6` | Perna negativa (cátodo) vai para o **GND** através de um resistor de 220Ω. |
| **LED Vermelho**| `D5` | Perna negativa (cátodo) vai para o **GND** através de um resistor de 220Ω. |
| **Buzzer** | `D4` | Pino positivo no Arduino. Pino negativo vai direto para o **GND**. |

---

## 🚀 Como Reproduzir o Projeto

### Passo 1: Montagem do Hardware
Monte o circuito na protoboard seguindo a tabela de pinagem acima. Tenha atenção especial à ligação do LDR: ele obrigatoriamente precisa do resistor de 10kΩ puxando para o GND para formar o **divisor de tensão**, caso contrário o Arduino não conseguirá ler as variações de luminosidade.

### Passo 2: Configuração do Código
1. Abra a Arduino IDE (ou a aba de código em "Texto" no Tinkercad).
2. Cole o código fonte `main.ino` ou `sketch.ino` correspondente a este projeto.
3. Conecte o Arduino na porta USB do computador.

### Passo 3: Calibração (Obrigatório)
A sensibilidade do LDR varia de acordo com a iluminação do cômodo onde o projeto está sendo executado. Para que o alarme funcione de forma precisa:
1. Faça o upload do código para o Arduino.
2. Abra o **Monitor Serial** (ícone de lupa no canto superior direito da IDE, configurado em 9600 baud).
3. Observe os números lidos. Teste o sensor cobrindo-o com a mão e depois apontando a lanterna do celular para ele.
4. No início do código, altere as variáveis de limite com base nos números que você observou no Monitor Serial:
   ```cpp
   int limiteAlerta = 500;   // Substitua pelo valor de luz de alerta do seu ambiente
   int limiteProblema = 800; // Substitua pelo valor de luz crítica do seu ambiente
5. Faça o upload do código novamente com os limites atualizados.
### Passo 4: Execução
O sistema agora rodará de forma autônoma. Tente simular uma variação de luz forte e observe a transição dos LEDs até o acionamento do alarme sonoro de 3 segundos.

## ⚠️ Possíveis dificuldades
* Calibrar corretamente os valores do LDR para diferentes ambientes.
* Entender a lógica de verificação de tempo do millis().
* Evitar o uso de delay() que interrompe a leitura dos sensores.
* Garantir que o buzzer respeite os tempos definidos sem repetições indesejadas.

## ✅ Soluções Adotadas
* Uso do Serial Monitor para monitorização em tempo real dos valores do LDR.
* Implementação de controle de tempo baseado em flags e estados com millis().
* Definição de estados lógicos (ligado/desligado) para o buzzer.
* Ajuste fino dos limites de luminosidade após testes práticos.

## 📌 Conclusão   
* O projeto demonstra uma aplicação prática de sensores e atuadores com Arduino, permitindo monitoramento em tempo real e resposta automática. A utilização de técnicas como o millis() eleva a qualidade do código, permitindo que o sistema seja expansível para soluções de automação residencial e controle ambiental mais complexos.

## Confira nosso projeto no seguinte repositório do Github: https://github.com/Gabriellluna/Los-Vinheteiros.git

## Integrantes
Bruno Guilherme Gonçalves de Oliveira - 573697  
Gabriel Cardoso de Sá Finzetto - 571846  
Gabriel Luna Maia - 570982  
João Lucas Magordo Rodrigues - 572419  
Murilo Vieira dos Reis - 573764  
