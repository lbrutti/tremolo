# Tremolo
 
In this project, I made a tremolo modulation pedal with wave altering feature for a guitar using an Arduino and an optocoupler.
<br/><br/>
Required components:
| Component        | Quantity|    
| ------------- |-----:|
| Arduino Nano (Mini USB) | 1 |
| 10K Potentiometers | 3 |
| 250K Potentiometer | 1 |
| 1/4 InchMono Input Jack | 2 |
| PC817B Optocoupler | 1 |
| LED | 1 |
| PLA (If you want to print your case) | 1 |

The following is the wiring required from the Arduino Pins:
10 to LED;
11 to Optocupler;
A0 to 10K Potentiometer [peek bias (Sawtooth wave)];
A1 to 10K Potentiometer [waveform];
A2 to 10K Potentiometer [rate]
then one wire from the Jacks can be corrected directly to the matching connector on the other jack and the other can be connected through the Optocoupler and the 250K Potentiometer.