#pragma once

#include "State.h"

class IdleState : public State {
 public:
  void enter() override;
  void update() override;
  void exit() override;

 private:
  bool handleBothButtonsHeld();
  void runMotionPipeline(float dt, unsigned long now);
  void handleSleepTransition(unsigned long now);

  unsigned long lastUpdateMs_ = 0;
  unsigned long lastActivityMs_ = 0;
  bool noMotion_ = false;
};
