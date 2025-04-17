# ArduinoMIDIEncoderController V1
This is a code for a MIDI controller made with Arduino that utilizes encoders to control volume and other MIDI functions. The code makes use of the Control Surface library to simplify MIDI communication.

The controller features encoders for adjusting volume. Additionally, there's a button matrix configured to send MIDI notes corresponding to the pressed buttons.

The code monitors the states of the encoders and detects the rotation direction to increase or decrease the volume, limiting it between the minimum and maximum values supported by the MIDI protocol (0-127). When there's a volume change, a MIDI control message is sent.

The additional encoders are also monitored for rotation detection, and similar actions are executed for these encoders.

The code is set to loop continuously, monitoring the states of the encoders and buttons and sending corresponding MIDI messages as needed.

This code can be used as a foundation for creating a custom MIDI controller using Arduino and encoders for volume control and other MIDI functions
Arduino IDE 2.1.0

MIDI Mixer
### Library:
 -  Control_Surface.h

### Materials:
 -  1x arduino pro micro
 -  4x encoder ec11
 -  16x Push button 2 pin
 -  8x Resistor 10k

# ArduinoMIDIEncoderController V2
Here are the improvements you can apply to your code:

### 1. **Organize and Simplify the Encoder Code**
   Instead of handling each encoder separately, you can create a data structure that stores the state of all encoders and use a single loop to process them generically. This eliminates code repetition and makes maintenance easier. Additionally, you can centralize the volume adjustment logic in a single function.

### 2. **Refactor Button Matrix Code**
   You can simplify the button matrix control by using a loop to read all the buttons. This helps modularize the code and makes it easier to expand the number of buttons or change the button matrix.

### 3. **Optimize Volume Control**
   Instead of repeating the volume control logic for each encoder, you can create a function that adjusts the volume flexibly. The logic could include visual or auditory feedback, indicating when the volume reaches the maximum or minimum. This helps make the code clearer and easier to modify in the future.

### 4. **Use Definitions and Constants**
   Instead of using fixed numbers like `127` or `0` directly in the code, it's a good practice to define constants with descriptive names. This improves the readability of the code and makes future adjustments easier. For example, by defining `MAX_VOLUME` and `MIN_VOLUME`, you make the code more intuitive and easier to understand.

These improvements make the code more modular, organized, and flexible, as well as easier to maintain and expand in the future.


<p>
 <img src="https://img.shields.io/badge/Arduino_IDE-00979D?style=for-the-badge&logo=arduino&logoColor=white" />
</p>

## Wiring Diagram
![Untitled Sketch 2_bb](https://github.com/carlostoni/ArduinoMIDIEncoderController/assets/80012970/971fbe5a-fd81-4997-93f9-2a67fd259edc)

## Assembled Project
![midi](https://github.com/carlostoni/ArduinoMIDIEncoderController/assets/80012970/8bffcd88-4fce-4e25-b3d2-687adfa83afe)


