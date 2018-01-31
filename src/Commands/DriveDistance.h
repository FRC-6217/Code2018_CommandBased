#ifndef DriveDistance_H
#define DriveDistance_H

#include "../CommandBase.h"

class DriveDistance : public CommandBase {
public:
	DriveDistance();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif  // DriveDistance_H
