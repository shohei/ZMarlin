#if defined(__MK64FX512__) || defined(__MK66FX1M0__)


#include "HAL_Servo_Teensy.h"
#include "../../../MarlinConfig.h"


int8_t libServo::attach(int pin) {
	if (this->servoIndex >= MAX_SERVOS) return -1;
	return Servo::attach(pin);
}

int8_t libServo::attach(int pin, int min, int max) {
	return Servo::attach(pin, min, max);
}

void libServo::move(int value) {
  if (this->attach(0) >= 0) {
    this->write(value);
    delay(SERVO_DELAY);
    #if ENABLED(DEACTIVATE_SERVOS_AFTER_MOVE)
      this->detach();
    #endif
  }
}


#endif
