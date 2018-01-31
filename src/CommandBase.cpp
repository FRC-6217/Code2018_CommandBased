#include "CommandBase.h"
#include <Commands/Scheduler.h>
#include "Subsystems/DriveTrain.h"

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {
}
DriveTrain* CommandBase::driveTrain = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init(){
	driveTrain = new DriveTrain();
	oi = new OI();
}
