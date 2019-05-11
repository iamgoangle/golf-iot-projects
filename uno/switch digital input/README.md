# Control Digital Input from Switch

![LED Blink](https://raw.githubusercontent.com/iamgoangle/golf-iot-projects/master/uno/switch%20digital%20input/digital_switch.jpg)

Switch = `Pull Up` and `Pull Down` state.

State = `0` and `1`

Pinmode = `input`

#### Code

```c++
int sw = 8;

void setup()
{
  Serial.begin(9600); // watch serial monitor
  pinMode(sw, INPUT);
}

void loop()
{
  int val = digitalRead(sw);
  Serial.println(val);
  delay(600);
}
```

## Arduino Internal Pull Up mode

Arduino support `INPUT_PULLUP` so that means we can remove register to a board.

![LED Blink](https://raw.githubusercontent.com/iamgoangle/golf-iot-projects/master/uno/switch%20digital%20input/input_pull_up.jpg)

```c++
void setup()
{
  Serial.begin(9600); // watch serial monitor
  pinMode(sw, INPUT_PULLUP);
}
```
