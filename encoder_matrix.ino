#include <Control_Surface.h>


// Interface type to use
USBMIDI_Interface midi;

// Definindo os pinos dos encoders para controlar o volume
constexpr uint8_t pinA_Volume = 1; // Pino A do encoder para controlar o volume
constexpr uint8_t pinB_Volume = 2; // Pino B do encoder para controlar o volume

constexpr uint8_t pinA1 = 20; // Pino A do primeiro encoder
constexpr uint8_t pinB1 = 21; // Pino B do primeiro encoder
constexpr uint8_t pinA2 = 4; // Pino A do segundo encoder
constexpr uint8_t pinB2 = 3; // Pino B do segundo encoder
constexpr uint8_t pinA3 = 18; // Pino A do terceiro encoder
constexpr uint8_t pinB3 = 19; // Pino B do terceiro encoder

// Variáveis para armazenar o estado anterior dos pinos dos encoders de volume
bool prevA_Volume;
bool prevB_Volume;
bool prevA1;
bool prevB1;
bool prevA2;
bool prevB2;
bool prevA3;
bool prevB3;

// Variável para armazenar o volume
int8_t volume = 64; // Inicialmente 50%

// The note numbers corresponding to the buttons in the matrix
const AddressMatrix<5, 4> addresses = {{
  {1, 2, 3, 4},
  {5, 6, 7, 8},
  {9, 10, 11, 12},
  {13, 14, 15, 16},
  {17, 18, 19, 20},
}};
 
NoteButtonMatrix<5, 4> buttonmatrix = {
  {5, 6, 7, 8, 9},// row pins
  {15, 14, 16, 10},// column pins
  addresses,    // address matrix
  CHANNEL_1,    // channel and cable number
};

// Initialise control surface
void setup() {
  Control_Surface.begin();

  // Configurando os pinos dos encoders de volume como entrada
  pinMode(pinA_Volume, INPUT_PULLUP);
  pinMode(pinB_Volume, INPUT_PULLUP);
  pinMode(pinA1, INPUT_PULLUP);
  pinMode(pinB1, INPUT_PULLUP);
  pinMode(pinA2, INPUT_PULLUP);
  pinMode(pinB2, INPUT_PULLUP);
  pinMode(pinA3, INPUT_PULLUP);
  pinMode(pinB3, INPUT_PULLUP);

  // Inicializando o estado anterior dos pinos dos encoders de volume
  prevA_Volume = digitalRead(pinA_Volume);
  prevB_Volume = digitalRead(pinB_Volume);

  prevA1 = digitalRead(pinA1);
  prevB1 = digitalRead(pinB1);
}

// Start loop
void loop() {
  Control_Surface.loop();

  // Lendo os estados atuais dos pinos dos encoders de volume
  bool currentA_Volume = digitalRead(pinA_Volume);
  bool currentB_Volume = digitalRead(pinB_Volume);

  
  // Verificando a direção da rotação do encoder de volume
  if (currentA_Volume != prevA_Volume || currentB_Volume != prevB_Volume) {
    if (prevA_Volume && !currentA_Volume && currentB_Volume) {
      // Rotação no sentido horário
      if (volume < 127) { // Verifica se o volume está abaixo do máximo
        volume += 5; // Aumenta o volume em 5 unidades
        if (volume > 127) volume = 127; // Limita o volume ao máximo
        midi.sendControlChange(21, volume); // Envia mensagem MIDI de controle de volume
      }
    } else if (prevB_Volume && !currentB_Volume && currentA_Volume) {
      // Rotação no sentido anti-horário
      if (volume > 0) { // Verifica se o volume está acima do mínimo
        volume -= 5; // Diminui o volume em 5 unidades
        if (volume < 0) volume = 0; // Limita o volume ao mínimo
        midi.sendControlChange(21, volume); // Envia mensagem MIDI de controle de volume
      }
    }
    // Atualizando o estado anterior dos pinos dos encoders de volume
    prevA_Volume = currentA_Volume;
    prevB_Volume = currentB_Volume;
  }
  bool currentA1 = digitalRead(pinA1);
  bool currentB1 = digitalRead(pinB1);
  // Verifique a direção da rotação do primeiro encoder
  if (currentA1 != prevA1 || currentB1 != prevB1) {
    if (prevA1 && !currentA1 && currentB1) {
       if (volume < 127) { // Verifica se o volume está abaixo do máximo
        volume += 5; // Aumenta o volume em 5 unidades
        if (volume > 127) volume = 127; // Limita o volume ao máximo
        midi.sendControlChange(22, volume); // Envia mensagem MIDI de controle de volume
      }
    } else if (prevB1 && !currentB1 && currentA1) {
      // Rotação no sentido anti-horário
      if (volume > 0) { // Verifica se o volume está acima do mínimo
        volume -= 5; // Diminui o volume em 5 unidades
        if (volume < 0) volume = 0; // Limita o volume ao mínimo
        midi.sendControlChange(22, volume); // Envia mensagem MIDI de controle de volume
      }
    }
    prevA1 = currentA1;
    prevB1 = currentB1;
  }
  bool currentA2 = digitalRead(pinA2);
  bool currentB2 = digitalRead(pinB2);

  // Verifique a direção da rotação do segundo encoder
  if (currentA2 != prevA2 || currentB2 != prevB2) {
    if (prevA2 && !currentA2 && currentB2) {
     if (volume < 127) { // Verifica se o volume está abaixo do máximo
        volume += 5; // Aumenta o volume em 5 unidades
        if (volume > 127) volume = 127; // Limita o volume ao máximo
        midi.sendControlChange(23, volume); // Envia mensagem MIDI de controle de volume
      }
    } else if (prevB2 && !currentB2 && currentA2) {
      // Rotação no sentido anti-horário
      if (volume > 0) { // Verifica se o volume está acima do mínimo
        volume -= 5; // Diminui o volume em 5 unidades
        if (volume < 0) volume = 0; // Limita o volume ao mínimo
        midi.sendControlChange(23, volume); // Envia mensagem MIDI de controle de volume
      }
    }
    prevA2 = currentA2;
    prevB2 = currentB2;
  }
  bool currentA3 = digitalRead(pinA3);
  bool currentB3 = digitalRead(pinB3);
  
  // Verifique a direção da rotação do terceiro encoder
  if (currentA3 != prevA3 || currentB3 != prevB3) {
    if (prevA3 && !currentA3 && currentB3) {
      if (volume < 127) { // Verifica se o volume está abaixo do máximo
        volume += 5; // Aumenta o volume em 5 unidades
        if (volume > 127) volume = 127; // Limita o volume ao máximo
        midi.sendControlChange(24, volume); // Envia mensagem MIDI de controle de volume
      }
    } else if (prevB3 && !currentB3 && currentA3) {
      // Rotação no sentido anti-horário
      if (volume > 0) { // Verifica se o volume está acima do mínimo
        volume -= 5; // Diminui o volume em 5 unidades
        if (volume < 0) volume = 0; // Limita o volume ao mínimo
        midi.sendControlChange(24, volume); // Envia mensagem MIDI de controle de volume
      }
    }
    prevA3 = currentA3;
    prevB3 = currentB3;
  }
}
