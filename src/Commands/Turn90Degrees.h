/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#ifndef Turn90Degrees_H
#define Turn90Degrees_H

#include "../CommandBase.h"

class Turn90Degrees : public CommandBase {
public:
	Turn90Degrees();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif  // Turn90Degrees_H


