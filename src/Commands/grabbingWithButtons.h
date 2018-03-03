#ifndef grabbingWithButtons_H
#define grabbingWithButtons_H

#include "../CommandBase.h"

class grabbingWithButtons : public CommandBase {
private:
	int currentDirection = GRABBER_STOP;
	int currentSpeed = .0;
public:
	grabbingWithButtons();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif  // grabbingWithButtons_H
