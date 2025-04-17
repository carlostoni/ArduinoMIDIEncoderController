#include <Control_Surface.h>

// Interface MIDI USB
USBMIDI_Interface midi;

// Pinos dos encoders
constexpr uint8_t pinA[] = {1, 20, 4, 18};
constexpr uint8_t pinB[] = {2, 21, 3, 19};
constexpr uint8_t ccNumber[] = {21, 22, 23, 24};

// Estado e volume de cada encoder
bool prevA[4];
int8_t volume[4] = {90, 90, 90, 90};

// Matriz de botões
const AddressMatrix<5, 4> addresses = {{
  {1, 2, 3, 4},
  {5, 6, 7, 8},
  {9, 10, 11, 12},
  {13, 14, 15, 16},
  {17, 18, 19, 20},
}};

NoteButtonMatrix<5, 4> buttonmatrix = {
  {5, 6, 7, 8, 9},         // row pins
  {15, 14, 16, 10},        // column pins
  addresses,
  CHANNEL_1,
};

// Função para ler encoders de forma estável
void handleEncoder(uint8_t index) {
  bool currentA = digitalRead(pinA[index]);
  bool currentB = digitalRead(pinB[index]);

  if (prevA[index] && !currentA) {  // Detecta borda de descida
    if (currentB) {
      // Sentido horário
      volume[index] = min(volume[index] + 5, 127);
    } else {
      // Sentido anti-horário
      volume[index] = max(volume[index] - 5, 0);
    }
    midi.sendCC(ccNumber[index], volume[index]);  // Envia CC
  }

  prevA[index] = currentA;
}

void setup() {
  Control_Surface.begin();

  // Configura os pinos dos encoders
  for (uint8_t i = 0; i < 4; i++) {
    pinMode(pinA[i], INPUT_PULLUP);
    pinMode(pinB[i], INPUT_PULLUP);
    prevA[i] = digitalRead(pinA[i]);
  }
}

void loop() {
  Control_Surface.loop();

  for (uint8_t i = 0; i < 4; i++) {
    handleEncoder(i);
  }
}
