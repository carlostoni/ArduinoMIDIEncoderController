# ArduinoMIDIEncoderController
This is a code for a MIDI controller made with Arduino that utilizes encoders to control volume and other MIDI functions. The code makes use of the Control Surface library to simplify MIDI communication.

The controller features encoders for adjusting volume and three additional encoders for additional functions. Additionally, there's a button matrix configured to send MIDI notes corresponding to the pressed buttons.

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


<p>
 <img src="https://img.shields.io/badge/Arduino_IDE-00979D?style=for-the-badge&logo=arduino&logoColor=white" />
</p>

## Wiring Diagram
![Untitled Sketch 2_bb](https://github.com/carlostoni/ArduinoMIDIEncoderController/assets/80012970/971fbe5a-fd81-4997-93f9-2a67fd259edc)

## Assembled Project
![midi](https://github.com/carlostoni/ArduinoMIDIEncoderController/assets/80012970/8bffcd88-4fce-4e25-b3d2-687adfa83afe)


