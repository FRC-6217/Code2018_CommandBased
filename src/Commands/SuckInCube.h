#ifndef SuckInCube_H
#define SuckInCube_H

#include "../CommandBase.h"

class SuckInCube : public CommandBase {
public:
	SuckInCube();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SuckInCube_H
