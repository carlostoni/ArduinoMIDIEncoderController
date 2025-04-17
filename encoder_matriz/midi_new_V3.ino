#include <Control_Surface.h>

// Interface MIDI USB
USBMIDI_Interface midi;

// Configurações dos Encoders
struct EncoderConfig {
  uint8_t pinA;
  uint8_t pinB;
  uint8_t ccNumber;
  int8_t initialValue;
};

constexpr EncoderConfig encoders[] = {
  {1, 2, 21, 90},
  {20, 21, 22, 90},
  {4, 3, 23, 90},
  {18, 19, 24, 90},
};

// Número de encoders
constexpr uint8_t numEncoders = sizeof(encoders) / sizeof(encoders[0]);

// Estado anterior do pino A de cada encoder
bool prevA[numEncoders];
// Valor de controle de cada encoder
int8_t controlValue[numEncoders];

// Configurações da Matriz de Botões
constexpr uint8_t numRows = 5;
constexpr uint8_t numCols = 4;

const AddressMatrix<numRows, numCols> addresses = {{
  {1, 2, 3, 4},
  {5, 6, 7, 8},
  {9, 10, 11, 12},
  {13, 14, 15, 16},
  {17, 18, 19, 20},
}};

NoteButtonMatrix<numRows, numCols> buttonmatrix = {
  {5, 6, 7, 8, 9},      // row pins
  {15, 14, 16, 10},     // column pins
  addresses,
  CHANNEL_1,
};

// Função para ler encoders de forma estável
void handleEncoder(uint8_t index) {
  bool currentA = digitalRead(encoders[index].pinA);
  bool currentB = digitalRead(encoders[index].pinB);

  if (prevA[index] && !currentA) {  // Detecta borda de descida do pino A
    if (currentB) {
      // Sentido horário: incrementa o valor de controle
      controlValue[index] = min(controlValue[index] + 5, 127);
    } else {
      // Sentido anti-horário: decrementa o valor de controle
      controlValue[index] = max(controlValue[index] - 5, 0);
    }
    midi.sendCC(encoders[index].ccNumber, controlValue[index]);  // Envia a mensagem CC
  }

  prevA[index] = currentA;
}

void setup() {
  Control_Surface.begin();

  // Inicializa as configurações dos encoders
  for (uint8_t i = 0; i < numEncoders; i++) {
    pinMode(encoders[i].pinA, INPUT_PULLUP);
    pinMode(encoders[i].pinB, INPUT_PULLUP);
    prevA[i] = digitalRead(encoders[i].pinA); // Inicializa o estado anterior de A
    controlValue[i] = encoders[i].initialValue; // Inicializa o valor de controle
  }
}

void loop() {
  Control_Surface.loop();

  // Lê o estado de cada encoder a cada iteração do loop
  for (uint8_t i = 0; i < numEncoders; i++) {
    handleEncoder(i);
  }
}
