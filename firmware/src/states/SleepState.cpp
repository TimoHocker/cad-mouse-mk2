#include "states/SleepState.h"

#include <Arduino.h>

#include "Config.h"
#include "Controllers.h"
#include "StateMachine.h"

void SleepState::enter() {
  ledController.off();
}

void SleepState::update() {
  inputController.update();

  if (inputController.takeBothButtonsHeld()) {
    stateMachine.changeState(&StateMachine::calibratingState);
    return;
  }
}

void SleepState::exit() {}
