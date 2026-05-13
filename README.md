# Los Vinheteiros

# Sistema de Monitoramento Ambiental com Arduino

## 📝 Descrição do Projeto

Este projeto implementa um sistema de monitoramento ambiental utilizando Arduino, sensores analógicos, LEDs, buzzer e display LCD.

O sistema tem como objetivo monitorar as condições do ambiente por meio da leitura de luminosidade, temperatura e umidade. A partir dessas informações, o projeto classifica o ambiente em diferentes estados, indicando visualmente e sonoramente quando alguma condição está fora do ideal.

A leitura dos dados é exibida em uma tela LCD, permitindo que o usuário acompanhe em tempo real os valores captados pelos sensores e o estado atual do ambiente.

## Comportamento do Sistema

### Luminosidade

O sistema realiza a leitura da intensidade de luz no ambiente por meio de um sensor LDR.

- Luz baixa: ambiente considerado escuro.
- Luz média: ambiente em condição intermediária.
- Luz alta: ambiente muito claro, podendo acionar alerta.

A indicação é feita por meio dos LEDs, permitindo visualizar rapidamente a condição da luminosidade.

### Temperatura

A temperatura é monitorada por um sensor analógico.  
Quando a temperatura está dentro da faixa definida como ideal, o sistema permanece em condição normal.

Caso a temperatura esteja muito alta ou muito baixa, o sistema identifica a situação como alerta e pode acionar o buzzer.

### Umidade

A umidade é simulada por meio de um potenciômetro, permitindo testar diferentes valores durante a execução do projeto.

Quando a umidade está dentro da faixa adequada, o sistema indica condição normal.  
Caso esteja acima ou abaixo do limite ideal, o sistema entra em estado de alerta.

### Alertas

O projeto utiliza LEDs e buzzer para indicar as condições do ambiente:

- LED Verde: condição normal.
- LED Amarelo: condição de atenção.
- LED Vermelho: condição crítica ou fora do ideal.
- Buzzer: alerta sonoro em situações problemáticas.

---

## 🛠️ Dependências e Materiais

### Hardware

- 1x Placa Arduino Uno
- 1x Cabo USB
- 1x Protoboard
- 1x Sensor LDR
- 1x Resistor de 10kΩ para o LDR
- 1x Sensor de temperatura
- 1x Potenciômetro para simulação de umidade
- 1x Display LCD 16x2
- 3x LEDs:
  - 1 Verde
  - 1 Amarelo
  - 1 Vermelho
- 3x Resistores de 220Ω ou 330Ω para os LEDs
- 1x Buzzer
- Fios jumper diversos

### Software

- Arduino IDE
- Ou simulador Tinkercad
- Bibliotecas necessárias para funcionamento do display LCD

---

## 🔌 Esquema de Ligação — Pinagem

| Componente | Pino no Arduino | Função |
|---|---:|---|
| LDR | A0 | Leitura da luminosidade |
| Sensor de Temperatura | A1 | Leitura da temperatura |
| Potenciômetro | A2 | Simulação da umidade |
| LED Verde | D8 | Indicação de condição normal |
| LED Amarelo | D9 | Indicação de atenção |
| LED Vermelho | D10 | Indicação de problema |
| Buzzer | D7 | Alerta sonoro |
| Display LCD | SDA/SCL | Exibição das informações |

---

## 🚀 Como Reproduzir o Projeto

### Passo 1: Montagem do Hardware

Monte o circuito na protoboard seguindo a tabela de pinagem apresentada.

O sensor LDR deve ser utilizado para captar a intensidade de luz do ambiente.  
O sensor de temperatura deve ser conectado para realizar a leitura térmica.  
O potenciômetro será utilizado para simular diferentes níveis de umidade.  
Os LEDs serão responsáveis por indicar visualmente o estado do sistema.  
O buzzer será utilizado para emitir alertas sonoros.  
O display LCD exibirá os valores e mensagens referentes ao funcionamento do projeto.

### Passo 2: Execução do Projeto

Após montar o circuito e enviar o projeto para o Arduino ou iniciar a simulação no Tinkercad, o sistema começa a realizar as leituras dos sensores automaticamente.

Durante a execução, o display LCD mostra as informações do ambiente, enquanto os LEDs indicam o estado atual do sistema.

Quando alguma variável apresenta valor fora da faixa ideal, o sistema aciona o LED correspondente e, em situações críticas, também ativa o buzzer.

### Passo 3: Testes do Sistema

Para testar o funcionamento do projeto, é possível variar as condições dos sensores:

- Alterar a luminosidade sobre o LDR.
- Modificar a leitura de umidade pelo potenciômetro.
- Simular variações de temperatura.
- Observar as mudanças exibidas no display LCD.
- Verificar o acionamento dos LEDs e do buzzer.

---

## ⚠️ Possíveis Dificuldades

- Calibrar corretamente os sensores de acordo com o ambiente.
- Compreender a variação dos valores analógicos lidos pelo Arduino.
- Ajustar os limites de luminosidade, temperatura e umidade.
- Configurar corretamente o display LCD.
- Evitar leituras instáveis dos sensores.
- Garantir que os LEDs indiquem corretamente cada estado do sistema.
- Fazer com que o buzzer seja acionado apenas em situações de alerta.

---

## ✅ Soluções Adotadas

- Utilização de sensores para monitoramento das condições ambientais.
- Uso de LEDs para facilitar a identificação visual dos estados.
- Implementação de alerta sonoro com buzzer.
- Exibição das informações em tempo real no display LCD.
- Separação das condições do sistema em estados de normalidade, atenção e problema.
- Uso do potenciômetro para permitir a simulação prática da umidade.
- Organização do circuito para facilitar testes e ajustes.

---

## 📌 Conclusão

O projeto demonstra uma aplicação prática de automação e monitoramento utilizando Arduino.

Com a integração de sensores, LEDs, buzzer e display LCD, o sistema permite acompanhar as condições do ambiente de forma simples e eficiente. Além disso, o projeto contribui para o aprendizado de leitura de sensores analógicos, controle de atuadores e exibição de dados em tempo real.

A solução pode ser expandida futuramente para aplicações como monitoramento residencial, controle de ambientes, estufas automatizadas, salas inteligentes e sistemas de segurança ambiental.

---

## 🔗 Links de Acesso

Simulação do Projeto: inserir link do vídeo ou demonstração  
Repositório do Projeto: inserir link do GitHub  
Projeto no Tinkercad: inserir link do Tinkercad  

---

## Integrantes

Bruno Guilherme Gonçalves de Oliveira - 573697  
Gabriel Cardoso de Sá Finzetto - 571846  
Gabriel Luna Maia - 570982  
João Lucas Magordo Rodrigues - 572419  
Murilo Vieira dos Reis - 573764
