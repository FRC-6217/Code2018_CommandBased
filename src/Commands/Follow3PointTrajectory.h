#ifndef Follow3PointTrajectory_H
#define Follow3PointTrajectory_H

#include <Path_Finder.cpp>
#include "../CommandBase.h"

class Follow3PointTrajectory : public CommandBase {
private:
	Pathfinder* pf;
	double _X1, _Y1, _exitAngle1, _X2, _Y2, _exitAngle2, _X3, _Y3, _exitAngle3;
	double lPower;
	double rPower;
	double _returnValue[2];
public:
	Follow3PointTrajectory(double X1, double Y1, double exitAngle1,
			 	 	 	   double X2, double Y2, double exitAngle2,
						   double X3, double Y3, double exitAngle3);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Follow3PointTrajectory_H
