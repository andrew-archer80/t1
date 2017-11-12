#include "robot_commands.h"
#include <iostream>
//-----------------------------------------------------------------------------


class DummyRobot : public IRobot {
public:
  void Move(double distance) override {};
  void Turn(double angle) override {};
  void Beep() override {};
};



int main() {
  RobotCommands rcs;
  // commands entered by an operator
  rcs.AddCommand(CommandId::BEEP);
  rcs.AddCommand(CommandId::BEEP);
  rcs.AddCommand(CommandId::MOVE, 125.4878);
  rcs.AddCommand(CommandId::TURN, -0.15784);

  DummyRobot r1, r2;
  rcs.SendTo(&r1); // send commands to robot r1
  rcs.SendTo(&r2); // send commands to robot r2

  return 0;
}
