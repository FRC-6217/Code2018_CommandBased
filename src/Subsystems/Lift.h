#ifndef Lift_H
#define Lift_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "..\RobotMap.h"

class Lift : public frc::Subsystem {
private:
	Spark* _acmeScrew1;
	Spark* _acmeScrew2;

public:
	Lift();
	void InitDefaultCommand();
	void Lift1Operate(int direction);
	void Lift2Operate(int direction);
};

#endif  // Lift_H
