class IRobot {
public:
  virtual void Move(double distance) = 0;
  virtual void Turn(double angle) = 0;
  virtual void Beep() = 0;
};


class Robot : public IRobot {
  // ...
public:
  void Move(double distance) override {};
  void Turn(double angle) override {};
  void Beep() override {};
};
