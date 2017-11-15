#include "robot_commands.h"
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
//-----------------------------------------------------------------------------


class MockRobot : public IRobot {
public:
    MOCK_METHOD0(Beep, void());
    MOCK_METHOD1(Move, void(double distance));
    MOCK_METHOD1(Turn, void(double angle));
};



TEST(RobotCommands, CommandsAreSent) {
  RobotCommands rcs;
  double move_val = 125.4878, turn_val = -0.15784;
  rcs.AddCommand(CommandId::BEEP);
  rcs.AddCommand(CommandId::BEEP);
  rcs.AddCommand(CommandId::MOVE, move_val);
  rcs.AddCommand(CommandId::TURN, turn_val);
  rcs.AddCommand(CommandId::BEEP);

  // send commands to robot r1
  MockRobot r1;
  EXPECT_CALL(r1, Beep())
  .Times(3);
  EXPECT_CALL(r1, Move(move_val))
  .Times(1);
  EXPECT_CALL(r1, Turn(turn_val))
  .Times(1);
  rcs.SendTo(&r1);

  // send the same saved commands to robots r2 and r3
  MockRobot r2, r3;
  EXPECT_CALL(r2, Beep())
  .Times(3);
  EXPECT_CALL(r2, Move(move_val))
  .Times(1);
  EXPECT_CALL(r2, Turn(turn_val))
  .Times(1);
  EXPECT_CALL(r3, Beep())
  .Times(3);
  EXPECT_CALL(r3, Move(move_val))
  .Times(1);
  EXPECT_CALL(r3, Turn(turn_val))
  .Times(1);
  rcs.SendTo(&r2);
  rcs.SendTo(&r3);
}



int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
