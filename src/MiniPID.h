#ifndef MINIPID_H
#define MINIPID_H

#include "HardwareSerial.h"

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

class MiniPID{
public:
	MiniPID(double, double, double);
	MiniPID(double, double, double, double);
	void setP(double);
	void setI(double);
	void setD(double);
	void setF(double);
	void setPID(double, double, double);
	void setPID(double, double, double, double);
	void setMaxIOutput(double);
	void setOutputLimits(double);
	void setOutputLimits(double,double);
	void setDirection(bool);
	void setSetpoint(double);
	void reset();
	void setOutputRampRate(double);
	void setSetpointRange(double);
	void setOutputFilter(double);
	void setPositionDiff(double);
	double getOutput();
	double getOutput(double);
	double getOutput(double, double);
	void setSynchronize(bool);
	bool getSynchronize(); 

	double getP();
	double getI();
	double getD();
	double getF();
	double getRampRate();

	double getPoutput();
	double getIoutput();
	double getDoutput();
	double getFoutput();
	double getPOSoutput();
	double getPOSoutputFiltered();

	double getError();
	double getErrorSum();
	double getActual();
	double getSetpoint();

	double getMaxIOutput();

	double getSyncDisabledForErrorSmallerThen();
	void setSyncDisabledForErrorSmallerThen(double val);

	double getMinOutput();
	double getMaxOutput();
	double getMaxError();



private:
	double clamp(double, double, double);
	bool bounded(double, double, double);
	void checkSigns();
	void init();
	double P;
	double I;
	double D;
	double F;

	volatile double output;
	double Poutput;
	double Ioutput;
	double Doutput;
	double Foutput;
	double POSOutput;
	double lastPOSOutputFiltered;
	double POSOutputFiltered;

	volatile bool sychronize;

	double maxIOutput;
	double maxError;
	double errorSum;

	volatile double error;
	volatile double syncDisabledForErrorSmallerThen;
	volatile double actual;

	double positionDiff;

	double maxOutput; 
	double minOutput;

	double setpoint;

	double lastActual;

	bool firstRun;
	bool reversed;

	double outputRampRate;
	double lastOutput;

	double outputFilter;

	double setpointRange;
};
#endif
