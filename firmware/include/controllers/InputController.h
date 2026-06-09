#pragma once

#include <Arduino.h>
#include <AceButton.h>

class InputController {
 public:
  InputController();
  void begin();
  void update();

  uint16_t buttonBits() const;
  bool takeBothButtonsHeld();
  bool takeActivity();

 private:
  static void handleButtonEvent(ace_button::AceButton* button, uint8_t eventType,
                                uint8_t buttonState);
  void onButtonEvent(ace_button::AceButton* button, uint8_t eventType);
  bool areBothPressed() const;

  ace_button::AceButton leftBtn_;
  ace_button::AceButton rightBtn_;

  bool bothButtonsHeld_ = false;
  bool hadActivity_ = false;
  unsigned long bothHeldStartMs_ = 0;
  bool bothHoldingStarted = false;
  bool leftPressed_ = false;
  bool rightPressed_ = false;

  static InputController* instance_;
};
