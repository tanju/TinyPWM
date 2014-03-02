A library for a PWM on PIN PB1 (Pin 6) of an ATTiny uC

E.g. ATTiny45
```
    +----V----+
PB5 | 1     8 | Vcc
PB3 | 2     7 | PB2
PB4 | 3     6 | PB1
GND | 4     5 | PB0
    +---------+
```
## Usage

Initialize this lib in your setup, e.g. for an 38kHz PWM use
```
TinyPWM pwm;

void setup(){ 
 pwm.begin( 38000 ); // Initializes 38kHz PWM and disables output
}
```

And use enable() or disable() / enable( false ) to enable or
disable the PWM output on pin 6/PB1. Right after begin(...) the output
pin is low.

Code found on http://forum.arduino.cc/index.php?topic=139729.0 by dc42
and assembled to an arduino library
