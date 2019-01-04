#include <PIDcontrol_algorithm.h>
#include <Temperature.h>
#include <iostream>
#include <fstream>
#include <Mesh.h>
PIDcontrol_algorithm::PIDcontrol_algorithm(float m_kp[], float m_ki[])
{
	int n_dim = sizeof(m_kp) / sizeof(float);
	float* kp = new float[n_dim];
	float* ki = new float[n_dim];
	for (int i = 0; i < n_dim; i++)
	{
		kp[i] = m_kp[i];
		ki[i] = m_ki[i];
	}
}

void PIDcontrol_algorithm::updateh(float*h_init, float*measuredtemperature, float*taimmeantemperature)
{
	for (int i = 0; i < n_dim; i++)
		h_init[i] += kp[i] * (measuredtemperature[i] - taimmeantemperature[i]);
}

void PIDcontrol_algorithm::outputdata(Temperature & SteelTemperature, float* h_init)
{
	ofstream outputfile;
	outputfile.open("C:\\T_Result_3DGPU_PID.csv", ios::app);
	for (int i = 0; i < SteelTemperature.mesh->ny; i++)
		outputfile << SteelTemperature.T_Surface[i] << ",";
	outputfile << endl;
	outputfile.close();
		
}