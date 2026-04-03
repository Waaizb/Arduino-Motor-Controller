# Arduino Motor Controller (Cutter & Feeder)

This repository contains Arduino code to proportionally control the speeds of two separate DC motors—a main cutter and a feeder gearmotor—using a single potentiometer. 

## How It Works
The script reads an analog value from a potentiometer and scales it to set proportional PWM (Pulse Width Modulation) speeds for both motors. 
* The **Cutter Motor** scales up to maximum speed (255) for high-speed chopping.
* The **Feeder Motor** has its maximum speed capped (150) to ensure it feeds material slower than the cutter chops, preventing jams.

## Hardware Requirements
* 1x Arduino (Uno, Nano, etc.)
* 1x Motor Driver (e.g., L298N)
* 1x DC Motor (Cutter)
* 1x DC Gearmotor (Feeder - Yellow TT Motor)
* 1x Potentiometer

##  Pin Mapping & Wiring
Here is how the hardware should be connected to the Arduino:

**Inputs:**
* `A0` - Potentiometer Signal

**Outputs (Motor Driver):**
* `Pin 9` - Cutter Speed / Enable (PWM)
* `Pin 8` - Cutter Direction (Input 1)
* `Pin 10` - Feeder Speed / Enable (PWM)
* `Pin 11` - Feeder Direction (Input 3)

*Note: Both motors are hardcoded to spin in the forward direction. Direction pins are set to `HIGH` in the setup phase.*
