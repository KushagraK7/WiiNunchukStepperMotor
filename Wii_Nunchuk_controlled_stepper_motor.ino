#include<AccelStepper.h>
#include<Wire.h>
#include<Nunchuk.h>

AccelStepper stepper(AccelStepper::FULL4WIRE, 6, 7, 8, 9);

int x, pos = 0, c;

void setup() {
  // put your setup code here, to run once:

  Wire.begin();

  Serial.begin(9600);

  nunchuk_init();

  stepper.setMaxSpeed(2000);

  stepper.setAcceleration(100);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  nunchuk_read();

  x = nunchuk_joystickX();

  c = nunchuk_buttonC();

  x-=5;

  if(x >= -131 && x <= 0) pos = map(x, -131, 0, -180, 0);

  if(x <= 122 && x >= 0) pos = map(x, 0, 122, 0, 180);

  Serial.println(pos);

  if(c == 1) stepper.moveTo(0);

  else stepper.moveTo(pos);

  stepper.run();

}
