#include "CommandBase.h"
#include <Commands/Scheduler.h>

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {
}
DriveTrain* CommandBase::driveTrain = NULL;
Lift* CommandBase::lift = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init(){
	driveTrain = new DriveTrain();
	lift = new Lift();
	oi = new OI();
}
