#include "robot.h"
#include <vector>
#include <tuple>
//-----------------------------------------------------------------------------

enum class CommandId { MOVE, TURN, BEEP };
typedef double CommandParameter;
typedef std::tuple<CommandId, CommandParameter> Command; // command id, command parameter1 (if present); note: use tuple instead of pair to make it easily extensible

class RobotCommands {
  std::vector<Command> m_Commands;

public:

  inline void AddCommand(CommandId id, CommandParameter param1 = 0.0) {
    m_Commands.emplace_back(id, param1);
  }

  inline void Reset() {
    m_Commands.clear();
  }

  void SendTo(IRobot* r) {
    for(const auto& cmd : m_Commands)
      switch(std::get<0>(cmd)) {
        case CommandId::MOVE:
        r->Move(std::get<1>(cmd));
        break;

        case CommandId::TURN:
        r->Turn(std::get<1>(cmd));
        break;

        case CommandId::BEEP:
        r->Beep();
      }
  }
};
