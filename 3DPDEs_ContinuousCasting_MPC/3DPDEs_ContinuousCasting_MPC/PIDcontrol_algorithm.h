#ifndef PIDcontrol_algorithm_H
#define PIDcontrol_algorithm_H
#include <Temperature.h>
class PIDcontrol_algorithm
{
    public:
		float *kp;
		float *ki;
		int n_dim;
		PIDcontrol_algorithm(float[], float[]);
		void updateh(float*, float*, float*);
		void outputdata(Temperature &, float*)
};
#endif
