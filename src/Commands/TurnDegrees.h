/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#ifndef TurnDegrees_H
#define TurnDegrees_H

#include "../CommandBase.h"

class TurnDegrees : public CommandBase {
private:
	float _turnDegrees;
public:
	TurnDegrees(float turnDegrees);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif  // Turn90Degrees_H


