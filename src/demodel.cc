/*
 * Copyright (C) 2022 by Fraunhofer IKTS, Dresden, Germany - All Rights Reserved
 *
 * Created on 21.12.2022 by Sebastian Stark
 *
 * This file is part of the DEModel library
 *
 */

#include <demodel/demodel.h>
#include <iostream>

using namespace std;
using namespace Eigen;
using namespace CMF;

namespace DEModel
{

//////////////////////
// Transformationdi //
//////////////////////

Transformationdi::Transformationdi(	const VariableSet value_set,
									const VariableSet argument_set)
:
VariableTransformFunction<Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd>(value_set,argument_set)
{
	assert(( "Incorrect number of variables w (must be 6)!", (value_set.size() == 6) ));
	assert(( "Incorrect number of variables q (must be 30)!", (argument_set.size() == 30) ));
}

bool
Transformationdi::compute(	VectorXd&	value,
							MatrixXd&	gradient,
							MatrixXd&	hessian,
							const bool	update_value,
							const bool	update_gradient,
							const bool	update_hessian)
{

	const double U_i_dot11 = get_arguments()[0];
	const double U_i_dot21 = get_arguments()[1];
	const double U_i_dot31 = get_arguments()[2];
	const double U_i_dot41 = get_arguments()[3];
	const double U_i_dot51 = get_arguments()[4];
	const double U_i_dot61 = get_arguments()[5];

	const double U_i_inv11 = get_arguments()[6];
	const double U_i_inv21 = get_arguments()[7];
	const double U_i_inv31 = get_arguments()[8];
	const double U_i_inv41 = get_arguments()[9];
	const double U_i_inv51 = get_arguments()[10];
	const double U_i_inv61 = get_arguments()[11];

	const double F11 = get_arguments()[12];
	const double F21 = get_arguments()[13];
	const double F31 = get_arguments()[14];
	const double F41 = get_arguments()[15];
	const double F51 = get_arguments()[16];
	const double F61 = get_arguments()[17];
	const double F71 = get_arguments()[18];
	const double F81 = get_arguments()[19];
	const double F91 = get_arguments()[20];

	const double F_inv11 = get_arguments()[21];
	const double F_inv21 = get_arguments()[22];
	const double F_inv31 = get_arguments()[23];
	const double F_inv41 = get_arguments()[24];
	const double F_inv51 = get_arguments()[25];
	const double F_inv61 = get_arguments()[26];
	const double F_inv71 = get_arguments()[27];
	const double F_inv81 = get_arguments()[28];
	const double F_inv91 = get_arguments()[29];

	if(update_value)
	{
		value.resize(6);

		value(0) = F11*F_inv11*U_i_dot11*U_i_inv11 + (1.0/4.0)*F11*F_inv11*U_i_dot41*U_i_inv41 + (1.0/4.0)*F11*F_inv11*U_i_dot61*U_i_inv61 + (1.0/2.0)*F11*F_inv41*U_i_dot21*U_i_inv41 + (1.0/2.0)*F11*F_inv41*U_i_dot41*U_i_inv11 + (1.0/4.0)*F11*F_inv41*U_i_dot51*U_i_inv61 + (1.0/2.0)*F11*F_inv71*U_i_dot31*U_i_inv61 + (1.0/4.0)*F11*F_inv71*U_i_dot51*U_i_inv41 + (1.0/2.0)*F11*F_inv71*U_i_dot61*U_i_inv11 + (1.0/2.0)*F21*F_inv11*U_i_dot11*U_i_inv41 + (1.0/2.0)*F21*F_inv11*U_i_dot41*U_i_inv21 + (1.0/4.0)*F21*F_inv11*U_i_dot61*U_i_inv51 + F21*F_inv41*U_i_dot21*U_i_inv21 + (1.0/4.0)*F21*F_inv41*U_i_dot41*U_i_inv41 + (1.0/4.0)*F21*F_inv41*U_i_dot51*U_i_inv51 + (1.0/2.0)*F21*F_inv71*U_i_dot31*U_i_inv51 + (1.0/2.0)*F21*F_inv71*U_i_dot51*U_i_inv21 + (1.0/4.0)*F21*F_inv71*U_i_dot61*U_i_inv41 + (1.0/2.0)*F31*F_inv11*U_i_dot11*U_i_inv61 + (1.0/4.0)*F31*F_inv11*U_i_dot41*U_i_inv51 + (1.0/2.0)*F31*F_inv11*U_i_dot61*U_i_inv31 + (1.0/2.0)*F31*F_inv41*U_i_dot21*U_i_inv51 + (1.0/4.0)*F31*F_inv41*U_i_dot41*U_i_inv61 + (1.0/2.0)*F31*F_inv41*U_i_dot51*U_i_inv31 + F31*F_inv71*U_i_dot31*U_i_inv31 + (1.0/4.0)*F31*F_inv71*U_i_dot51*U_i_inv51 + (1.0/4.0)*F31*F_inv71*U_i_dot61*U_i_inv61;
		value(1) = F41*F_inv21*U_i_dot11*U_i_inv11 + (1.0/4.0)*F41*F_inv21*U_i_dot41*U_i_inv41 + (1.0/4.0)*F41*F_inv21*U_i_dot61*U_i_inv61 + (1.0/2.0)*F41*F_inv51*U_i_dot21*U_i_inv41 + (1.0/2.0)*F41*F_inv51*U_i_dot41*U_i_inv11 + (1.0/4.0)*F41*F_inv51*U_i_dot51*U_i_inv61 + (1.0/2.0)*F41*F_inv81*U_i_dot31*U_i_inv61 + (1.0/4.0)*F41*F_inv81*U_i_dot51*U_i_inv41 + (1.0/2.0)*F41*F_inv81*U_i_dot61*U_i_inv11 + (1.0/2.0)*F51*F_inv21*U_i_dot11*U_i_inv41 + (1.0/2.0)*F51*F_inv21*U_i_dot41*U_i_inv21 + (1.0/4.0)*F51*F_inv21*U_i_dot61*U_i_inv51 + F51*F_inv51*U_i_dot21*U_i_inv21 + (1.0/4.0)*F51*F_inv51*U_i_dot41*U_i_inv41 + (1.0/4.0)*F51*F_inv51*U_i_dot51*U_i_inv51 + (1.0/2.0)*F51*F_inv81*U_i_dot31*U_i_inv51 + (1.0/2.0)*F51*F_inv81*U_i_dot51*U_i_inv21 + (1.0/4.0)*F51*F_inv81*U_i_dot61*U_i_inv41 + (1.0/2.0)*F61*F_inv21*U_i_dot11*U_i_inv61 + (1.0/4.0)*F61*F_inv21*U_i_dot41*U_i_inv51 + (1.0/2.0)*F61*F_inv21*U_i_dot61*U_i_inv31 + (1.0/2.0)*F61*F_inv51*U_i_dot21*U_i_inv51 + (1.0/4.0)*F61*F_inv51*U_i_dot41*U_i_inv61 + (1.0/2.0)*F61*F_inv51*U_i_dot51*U_i_inv31 + F61*F_inv81*U_i_dot31*U_i_inv31 + (1.0/4.0)*F61*F_inv81*U_i_dot51*U_i_inv51 + (1.0/4.0)*F61*F_inv81*U_i_dot61*U_i_inv61;
		value(2) = F71*F_inv31*U_i_dot11*U_i_inv11 + (1.0/4.0)*F71*F_inv31*U_i_dot41*U_i_inv41 + (1.0/4.0)*F71*F_inv31*U_i_dot61*U_i_inv61 + (1.0/2.0)*F71*F_inv61*U_i_dot21*U_i_inv41 + (1.0/2.0)*F71*F_inv61*U_i_dot41*U_i_inv11 + (1.0/4.0)*F71*F_inv61*U_i_dot51*U_i_inv61 + (1.0/2.0)*F71*F_inv91*U_i_dot31*U_i_inv61 + (1.0/4.0)*F71*F_inv91*U_i_dot51*U_i_inv41 + (1.0/2.0)*F71*F_inv91*U_i_dot61*U_i_inv11 + (1.0/2.0)*F81*F_inv31*U_i_dot11*U_i_inv41 + (1.0/2.0)*F81*F_inv31*U_i_dot41*U_i_inv21 + (1.0/4.0)*F81*F_inv31*U_i_dot61*U_i_inv51 + F81*F_inv61*U_i_dot21*U_i_inv21 + (1.0/4.0)*F81*F_inv61*U_i_dot41*U_i_inv41 + (1.0/4.0)*F81*F_inv61*U_i_dot51*U_i_inv51 + (1.0/2.0)*F81*F_inv91*U_i_dot31*U_i_inv51 + (1.0/2.0)*F81*F_inv91*U_i_dot51*U_i_inv21 + (1.0/4.0)*F81*F_inv91*U_i_dot61*U_i_inv41 + (1.0/2.0)*F91*F_inv31*U_i_dot11*U_i_inv61 + (1.0/4.0)*F91*F_inv31*U_i_dot41*U_i_inv51 + (1.0/2.0)*F91*F_inv31*U_i_dot61*U_i_inv31 + (1.0/2.0)*F91*F_inv61*U_i_dot21*U_i_inv51 + (1.0/4.0)*F91*F_inv61*U_i_dot41*U_i_inv61 + (1.0/2.0)*F91*F_inv61*U_i_dot51*U_i_inv31 + F91*F_inv91*U_i_dot31*U_i_inv31 + (1.0/4.0)*F91*F_inv91*U_i_dot51*U_i_inv51 + (1.0/4.0)*F91*F_inv91*U_i_dot61*U_i_inv61;
		value(3) = F11*F_inv21*U_i_dot11*U_i_inv11 + (1.0/4.0)*F11*F_inv21*U_i_dot41*U_i_inv41 + (1.0/4.0)*F11*F_inv21*U_i_dot61*U_i_inv61 + (1.0/2.0)*F11*F_inv51*U_i_dot21*U_i_inv41 + (1.0/2.0)*F11*F_inv51*U_i_dot41*U_i_inv11 + (1.0/4.0)*F11*F_inv51*U_i_dot51*U_i_inv61 + (1.0/2.0)*F11*F_inv81*U_i_dot31*U_i_inv61 + (1.0/4.0)*F11*F_inv81*U_i_dot51*U_i_inv41 + (1.0/2.0)*F11*F_inv81*U_i_dot61*U_i_inv11 + (1.0/2.0)*F21*F_inv21*U_i_dot11*U_i_inv41 + (1.0/2.0)*F21*F_inv21*U_i_dot41*U_i_inv21 + (1.0/4.0)*F21*F_inv21*U_i_dot61*U_i_inv51 + F21*F_inv51*U_i_dot21*U_i_inv21 + (1.0/4.0)*F21*F_inv51*U_i_dot41*U_i_inv41 + (1.0/4.0)*F21*F_inv51*U_i_dot51*U_i_inv51 + (1.0/2.0)*F21*F_inv81*U_i_dot31*U_i_inv51 + (1.0/2.0)*F21*F_inv81*U_i_dot51*U_i_inv21 + (1.0/4.0)*F21*F_inv81*U_i_dot61*U_i_inv41 + (1.0/2.0)*F31*F_inv21*U_i_dot11*U_i_inv61 + (1.0/4.0)*F31*F_inv21*U_i_dot41*U_i_inv51 + (1.0/2.0)*F31*F_inv21*U_i_dot61*U_i_inv31 + (1.0/2.0)*F31*F_inv51*U_i_dot21*U_i_inv51 + (1.0/4.0)*F31*F_inv51*U_i_dot41*U_i_inv61 + (1.0/2.0)*F31*F_inv51*U_i_dot51*U_i_inv31 + F31*F_inv81*U_i_dot31*U_i_inv31 + (1.0/4.0)*F31*F_inv81*U_i_dot51*U_i_inv51 + (1.0/4.0)*F31*F_inv81*U_i_dot61*U_i_inv61 + F41*F_inv11*U_i_dot11*U_i_inv11 + (1.0/4.0)*F41*F_inv11*U_i_dot41*U_i_inv41 + (1.0/4.0)*F41*F_inv11*U_i_dot61*U_i_inv61 + (1.0/2.0)*F41*F_inv41*U_i_dot21*U_i_inv41 + (1.0/2.0)*F41*F_inv41*U_i_dot41*U_i_inv11 + (1.0/4.0)*F41*F_inv41*U_i_dot51*U_i_inv61 + (1.0/2.0)*F41*F_inv71*U_i_dot31*U_i_inv61 + (1.0/4.0)*F41*F_inv71*U_i_dot51*U_i_inv41 + (1.0/2.0)*F41*F_inv71*U_i_dot61*U_i_inv11 + (1.0/2.0)*F51*F_inv11*U_i_dot11*U_i_inv41 + (1.0/2.0)*F51*F_inv11*U_i_dot41*U_i_inv21 + (1.0/4.0)*F51*F_inv11*U_i_dot61*U_i_inv51 + F51*F_inv41*U_i_dot21*U_i_inv21 + (1.0/4.0)*F51*F_inv41*U_i_dot41*U_i_inv41 + (1.0/4.0)*F51*F_inv41*U_i_dot51*U_i_inv51 + (1.0/2.0)*F51*F_inv71*U_i_dot31*U_i_inv51 + (1.0/2.0)*F51*F_inv71*U_i_dot51*U_i_inv21 + (1.0/4.0)*F51*F_inv71*U_i_dot61*U_i_inv41 + (1.0/2.0)*F61*F_inv11*U_i_dot11*U_i_inv61 + (1.0/4.0)*F61*F_inv11*U_i_dot41*U_i_inv51 + (1.0/2.0)*F61*F_inv11*U_i_dot61*U_i_inv31 + (1.0/2.0)*F61*F_inv41*U_i_dot21*U_i_inv51 + (1.0/4.0)*F61*F_inv41*U_i_dot41*U_i_inv61 + (1.0/2.0)*F61*F_inv41*U_i_dot51*U_i_inv31 + F61*F_inv71*U_i_dot31*U_i_inv31 + (1.0/4.0)*F61*F_inv71*U_i_dot51*U_i_inv51 + (1.0/4.0)*F61*F_inv71*U_i_dot61*U_i_inv61;
		value(4) = F41*F_inv31*U_i_dot11*U_i_inv11 + (1.0/4.0)*F41*F_inv31*U_i_dot41*U_i_inv41 + (1.0/4.0)*F41*F_inv31*U_i_dot61*U_i_inv61 + (1.0/2.0)*F41*F_inv61*U_i_dot21*U_i_inv41 + (1.0/2.0)*F41*F_inv61*U_i_dot41*U_i_inv11 + (1.0/4.0)*F41*F_inv61*U_i_dot51*U_i_inv61 + (1.0/2.0)*F41*F_inv91*U_i_dot31*U_i_inv61 + (1.0/4.0)*F41*F_inv91*U_i_dot51*U_i_inv41 + (1.0/2.0)*F41*F_inv91*U_i_dot61*U_i_inv11 + (1.0/2.0)*F51*F_inv31*U_i_dot11*U_i_inv41 + (1.0/2.0)*F51*F_inv31*U_i_dot41*U_i_inv21 + (1.0/4.0)*F51*F_inv31*U_i_dot61*U_i_inv51 + F51*F_inv61*U_i_dot21*U_i_inv21 + (1.0/4.0)*F51*F_inv61*U_i_dot41*U_i_inv41 + (1.0/4.0)*F51*F_inv61*U_i_dot51*U_i_inv51 + (1.0/2.0)*F51*F_inv91*U_i_dot31*U_i_inv51 + (1.0/2.0)*F51*F_inv91*U_i_dot51*U_i_inv21 + (1.0/4.0)*F51*F_inv91*U_i_dot61*U_i_inv41 + (1.0/2.0)*F61*F_inv31*U_i_dot11*U_i_inv61 + (1.0/4.0)*F61*F_inv31*U_i_dot41*U_i_inv51 + (1.0/2.0)*F61*F_inv31*U_i_dot61*U_i_inv31 + (1.0/2.0)*F61*F_inv61*U_i_dot21*U_i_inv51 + (1.0/4.0)*F61*F_inv61*U_i_dot41*U_i_inv61 + (1.0/2.0)*F61*F_inv61*U_i_dot51*U_i_inv31 + F61*F_inv91*U_i_dot31*U_i_inv31 + (1.0/4.0)*F61*F_inv91*U_i_dot51*U_i_inv51 + (1.0/4.0)*F61*F_inv91*U_i_dot61*U_i_inv61 + F71*F_inv21*U_i_dot11*U_i_inv11 + (1.0/4.0)*F71*F_inv21*U_i_dot41*U_i_inv41 + (1.0/4.0)*F71*F_inv21*U_i_dot61*U_i_inv61 + (1.0/2.0)*F71*F_inv51*U_i_dot21*U_i_inv41 + (1.0/2.0)*F71*F_inv51*U_i_dot41*U_i_inv11 + (1.0/4.0)*F71*F_inv51*U_i_dot51*U_i_inv61 + (1.0/2.0)*F71*F_inv81*U_i_dot31*U_i_inv61 + (1.0/4.0)*F71*F_inv81*U_i_dot51*U_i_inv41 + (1.0/2.0)*F71*F_inv81*U_i_dot61*U_i_inv11 + (1.0/2.0)*F81*F_inv21*U_i_dot11*U_i_inv41 + (1.0/2.0)*F81*F_inv21*U_i_dot41*U_i_inv21 + (1.0/4.0)*F81*F_inv21*U_i_dot61*U_i_inv51 + F81*F_inv51*U_i_dot21*U_i_inv21 + (1.0/4.0)*F81*F_inv51*U_i_dot41*U_i_inv41 + (1.0/4.0)*F81*F_inv51*U_i_dot51*U_i_inv51 + (1.0/2.0)*F81*F_inv81*U_i_dot31*U_i_inv51 + (1.0/2.0)*F81*F_inv81*U_i_dot51*U_i_inv21 + (1.0/4.0)*F81*F_inv81*U_i_dot61*U_i_inv41 + (1.0/2.0)*F91*F_inv21*U_i_dot11*U_i_inv61 + (1.0/4.0)*F91*F_inv21*U_i_dot41*U_i_inv51 + (1.0/2.0)*F91*F_inv21*U_i_dot61*U_i_inv31 + (1.0/2.0)*F91*F_inv51*U_i_dot21*U_i_inv51 + (1.0/4.0)*F91*F_inv51*U_i_dot41*U_i_inv61 + (1.0/2.0)*F91*F_inv51*U_i_dot51*U_i_inv31 + F91*F_inv81*U_i_dot31*U_i_inv31 + (1.0/4.0)*F91*F_inv81*U_i_dot51*U_i_inv51 + (1.0/4.0)*F91*F_inv81*U_i_dot61*U_i_inv61;
		value(5) = F11*F_inv31*U_i_dot11*U_i_inv11 + (1.0/4.0)*F11*F_inv31*U_i_dot41*U_i_inv41 + (1.0/4.0)*F11*F_inv31*U_i_dot61*U_i_inv61 + (1.0/2.0)*F11*F_inv61*U_i_dot21*U_i_inv41 + (1.0/2.0)*F11*F_inv61*U_i_dot41*U_i_inv11 + (1.0/4.0)*F11*F_inv61*U_i_dot51*U_i_inv61 + (1.0/2.0)*F11*F_inv91*U_i_dot31*U_i_inv61 + (1.0/4.0)*F11*F_inv91*U_i_dot51*U_i_inv41 + (1.0/2.0)*F11*F_inv91*U_i_dot61*U_i_inv11 + (1.0/2.0)*F21*F_inv31*U_i_dot11*U_i_inv41 + (1.0/2.0)*F21*F_inv31*U_i_dot41*U_i_inv21 + (1.0/4.0)*F21*F_inv31*U_i_dot61*U_i_inv51 + F21*F_inv61*U_i_dot21*U_i_inv21 + (1.0/4.0)*F21*F_inv61*U_i_dot41*U_i_inv41 + (1.0/4.0)*F21*F_inv61*U_i_dot51*U_i_inv51 + (1.0/2.0)*F21*F_inv91*U_i_dot31*U_i_inv51 + (1.0/2.0)*F21*F_inv91*U_i_dot51*U_i_inv21 + (1.0/4.0)*F21*F_inv91*U_i_dot61*U_i_inv41 + (1.0/2.0)*F31*F_inv31*U_i_dot11*U_i_inv61 + (1.0/4.0)*F31*F_inv31*U_i_dot41*U_i_inv51 + (1.0/2.0)*F31*F_inv31*U_i_dot61*U_i_inv31 + (1.0/2.0)*F31*F_inv61*U_i_dot21*U_i_inv51 + (1.0/4.0)*F31*F_inv61*U_i_dot41*U_i_inv61 + (1.0/2.0)*F31*F_inv61*U_i_dot51*U_i_inv31 + F31*F_inv91*U_i_dot31*U_i_inv31 + (1.0/4.0)*F31*F_inv91*U_i_dot51*U_i_inv51 + (1.0/4.0)*F31*F_inv91*U_i_dot61*U_i_inv61 + F71*F_inv11*U_i_dot11*U_i_inv11 + (1.0/4.0)*F71*F_inv11*U_i_dot41*U_i_inv41 + (1.0/4.0)*F71*F_inv11*U_i_dot61*U_i_inv61 + (1.0/2.0)*F71*F_inv41*U_i_dot21*U_i_inv41 + (1.0/2.0)*F71*F_inv41*U_i_dot41*U_i_inv11 + (1.0/4.0)*F71*F_inv41*U_i_dot51*U_i_inv61 + (1.0/2.0)*F71*F_inv71*U_i_dot31*U_i_inv61 + (1.0/4.0)*F71*F_inv71*U_i_dot51*U_i_inv41 + (1.0/2.0)*F71*F_inv71*U_i_dot61*U_i_inv11 + (1.0/2.0)*F81*F_inv11*U_i_dot11*U_i_inv41 + (1.0/2.0)*F81*F_inv11*U_i_dot41*U_i_inv21 + (1.0/4.0)*F81*F_inv11*U_i_dot61*U_i_inv51 + F81*F_inv41*U_i_dot21*U_i_inv21 + (1.0/4.0)*F81*F_inv41*U_i_dot41*U_i_inv41 + (1.0/4.0)*F81*F_inv41*U_i_dot51*U_i_inv51 + (1.0/2.0)*F81*F_inv71*U_i_dot31*U_i_inv51 + (1.0/2.0)*F81*F_inv71*U_i_dot51*U_i_inv21 + (1.0/4.0)*F81*F_inv71*U_i_dot61*U_i_inv41 + (1.0/2.0)*F91*F_inv11*U_i_dot11*U_i_inv61 + (1.0/4.0)*F91*F_inv11*U_i_dot41*U_i_inv51 + (1.0/2.0)*F91*F_inv11*U_i_dot61*U_i_inv31 + (1.0/2.0)*F91*F_inv41*U_i_dot21*U_i_inv51 + (1.0/4.0)*F91*F_inv41*U_i_dot41*U_i_inv61 + (1.0/2.0)*F91*F_inv41*U_i_dot51*U_i_inv31 + F91*F_inv71*U_i_dot31*U_i_inv31 + (1.0/4.0)*F91*F_inv71*U_i_dot51*U_i_inv51 + (1.0/4.0)*F91*F_inv71*U_i_dot61*U_i_inv61;	}

	if(update_gradient)
	{
		gradient.resize(value_set.size(), argument_set.size());

		gradient(0,0) = (1.0/2.0)*F_inv11*(2*F11*U_i_inv11 + F21*U_i_inv41 + F31*U_i_inv61);
		gradient(0,1) = (1.0/2.0)*F_inv41*(F11*U_i_inv41 + 2*F21*U_i_inv21 + F31*U_i_inv51);
		gradient(0,2) = (1.0/2.0)*F_inv71*(F11*U_i_inv61 + F21*U_i_inv51 + 2*F31*U_i_inv31);
		gradient(0,3) = (1.0/4.0)*F11*F_inv11*U_i_inv41 + (1.0/2.0)*F11*F_inv41*U_i_inv11 + (1.0/2.0)*F21*F_inv11*U_i_inv21 + (1.0/4.0)*F21*F_inv41*U_i_inv41 + (1.0/4.0)*F31*F_inv11*U_i_inv51 + (1.0/4.0)*F31*F_inv41*U_i_inv61;
		gradient(0,4) = (1.0/4.0)*F11*F_inv41*U_i_inv61 + (1.0/4.0)*F11*F_inv71*U_i_inv41 + (1.0/4.0)*F21*F_inv41*U_i_inv51 + (1.0/2.0)*F21*F_inv71*U_i_inv21 + (1.0/2.0)*F31*F_inv41*U_i_inv31 + (1.0/4.0)*F31*F_inv71*U_i_inv51;
		gradient(0,5) = (1.0/4.0)*F11*F_inv11*U_i_inv61 + (1.0/2.0)*F11*F_inv71*U_i_inv11 + (1.0/4.0)*F21*F_inv11*U_i_inv51 + (1.0/4.0)*F21*F_inv71*U_i_inv41 + (1.0/2.0)*F31*F_inv11*U_i_inv31 + (1.0/4.0)*F31*F_inv71*U_i_inv61;
		gradient(0,6) = (1.0/2.0)*F11*(2*F_inv11*U_i_dot11 + F_inv41*U_i_dot41 + F_inv71*U_i_dot61);
		gradient(0,7) = (1.0/2.0)*F21*(F_inv11*U_i_dot41 + 2*F_inv41*U_i_dot21 + F_inv71*U_i_dot51);
		gradient(0,8) = (1.0/2.0)*F31*(F_inv11*U_i_dot61 + F_inv41*U_i_dot51 + 2*F_inv71*U_i_dot31);
		gradient(0,9) = (1.0/4.0)*F11*F_inv11*U_i_dot41 + (1.0/2.0)*F11*F_inv41*U_i_dot21 + (1.0/4.0)*F11*F_inv71*U_i_dot51 + (1.0/2.0)*F21*F_inv11*U_i_dot11 + (1.0/4.0)*F21*F_inv41*U_i_dot41 + (1.0/4.0)*F21*F_inv71*U_i_dot61;
		gradient(0,10) = (1.0/4.0)*F21*F_inv11*U_i_dot61 + (1.0/4.0)*F21*F_inv41*U_i_dot51 + (1.0/2.0)*F21*F_inv71*U_i_dot31 + (1.0/4.0)*F31*F_inv11*U_i_dot41 + (1.0/2.0)*F31*F_inv41*U_i_dot21 + (1.0/4.0)*F31*F_inv71*U_i_dot51;
		gradient(0,11) = (1.0/4.0)*F11*F_inv11*U_i_dot61 + (1.0/4.0)*F11*F_inv41*U_i_dot51 + (1.0/2.0)*F11*F_inv71*U_i_dot31 + (1.0/2.0)*F31*F_inv11*U_i_dot11 + (1.0/4.0)*F31*F_inv41*U_i_dot41 + (1.0/4.0)*F31*F_inv71*U_i_dot61;
		gradient(0,12) = F_inv11*U_i_dot11*U_i_inv11 + (1.0/4.0)*F_inv11*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv11*U_i_dot61*U_i_inv61 + (1.0/2.0)*F_inv41*U_i_dot21*U_i_inv41 + (1.0/2.0)*F_inv41*U_i_dot41*U_i_inv11 + (1.0/4.0)*F_inv41*U_i_dot51*U_i_inv61 + (1.0/2.0)*F_inv71*U_i_dot31*U_i_inv61 + (1.0/4.0)*F_inv71*U_i_dot51*U_i_inv41 + (1.0/2.0)*F_inv71*U_i_dot61*U_i_inv11;
		gradient(0,13) = (1.0/2.0)*F_inv11*U_i_dot11*U_i_inv41 + (1.0/2.0)*F_inv11*U_i_dot41*U_i_inv21 + (1.0/4.0)*F_inv11*U_i_dot61*U_i_inv51 + F_inv41*U_i_dot21*U_i_inv21 + (1.0/4.0)*F_inv41*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv41*U_i_dot51*U_i_inv51 + (1.0/2.0)*F_inv71*U_i_dot31*U_i_inv51 + (1.0/2.0)*F_inv71*U_i_dot51*U_i_inv21 + (1.0/4.0)*F_inv71*U_i_dot61*U_i_inv41;
		gradient(0,14) = (1.0/2.0)*F_inv11*U_i_dot11*U_i_inv61 + (1.0/4.0)*F_inv11*U_i_dot41*U_i_inv51 + (1.0/2.0)*F_inv11*U_i_dot61*U_i_inv31 + (1.0/2.0)*F_inv41*U_i_dot21*U_i_inv51 + (1.0/4.0)*F_inv41*U_i_dot41*U_i_inv61 + (1.0/2.0)*F_inv41*U_i_dot51*U_i_inv31 + F_inv71*U_i_dot31*U_i_inv31 + (1.0/4.0)*F_inv71*U_i_dot51*U_i_inv51 + (1.0/4.0)*F_inv71*U_i_dot61*U_i_inv61;
		gradient(0,15) = 0;
		gradient(0,16) = 0;
		gradient(0,17) = 0;
		gradient(0,18) = 0;
		gradient(0,19) = 0;
		gradient(0,20) = 0;
		gradient(0,21) = F11*U_i_dot11*U_i_inv11 + (1.0/4.0)*F11*U_i_dot41*U_i_inv41 + (1.0/4.0)*F11*U_i_dot61*U_i_inv61 + (1.0/2.0)*F21*U_i_dot11*U_i_inv41 + (1.0/2.0)*F21*U_i_dot41*U_i_inv21 + (1.0/4.0)*F21*U_i_dot61*U_i_inv51 + (1.0/2.0)*F31*U_i_dot11*U_i_inv61 + (1.0/4.0)*F31*U_i_dot41*U_i_inv51 + (1.0/2.0)*F31*U_i_dot61*U_i_inv31;
		gradient(0,22) = 0;
		gradient(0,23) = 0;
		gradient(0,24) = (1.0/2.0)*F11*U_i_dot21*U_i_inv41 + (1.0/2.0)*F11*U_i_dot41*U_i_inv11 + (1.0/4.0)*F11*U_i_dot51*U_i_inv61 + F21*U_i_dot21*U_i_inv21 + (1.0/4.0)*F21*U_i_dot41*U_i_inv41 + (1.0/4.0)*F21*U_i_dot51*U_i_inv51 + (1.0/2.0)*F31*U_i_dot21*U_i_inv51 + (1.0/4.0)*F31*U_i_dot41*U_i_inv61 + (1.0/2.0)*F31*U_i_dot51*U_i_inv31;
		gradient(0,25) = 0;
		gradient(0,26) = 0;
		gradient(0,27) = (1.0/2.0)*F11*U_i_dot31*U_i_inv61 + (1.0/4.0)*F11*U_i_dot51*U_i_inv41 + (1.0/2.0)*F11*U_i_dot61*U_i_inv11 + (1.0/2.0)*F21*U_i_dot31*U_i_inv51 + (1.0/2.0)*F21*U_i_dot51*U_i_inv21 + (1.0/4.0)*F21*U_i_dot61*U_i_inv41 + F31*U_i_dot31*U_i_inv31 + (1.0/4.0)*F31*U_i_dot51*U_i_inv51 + (1.0/4.0)*F31*U_i_dot61*U_i_inv61;
		gradient(0,28) = 0;
		gradient(0,29) = 0;
		gradient(1,0) = (1.0/2.0)*F_inv21*(2*F41*U_i_inv11 + F51*U_i_inv41 + F61*U_i_inv61);
		gradient(1,1) = (1.0/2.0)*F_inv51*(F41*U_i_inv41 + 2*F51*U_i_inv21 + F61*U_i_inv51);
		gradient(1,2) = (1.0/2.0)*F_inv81*(F41*U_i_inv61 + F51*U_i_inv51 + 2*F61*U_i_inv31);
		gradient(1,3) = (1.0/4.0)*F41*F_inv21*U_i_inv41 + (1.0/2.0)*F41*F_inv51*U_i_inv11 + (1.0/2.0)*F51*F_inv21*U_i_inv21 + (1.0/4.0)*F51*F_inv51*U_i_inv41 + (1.0/4.0)*F61*F_inv21*U_i_inv51 + (1.0/4.0)*F61*F_inv51*U_i_inv61;
		gradient(1,4) = (1.0/4.0)*F41*F_inv51*U_i_inv61 + (1.0/4.0)*F41*F_inv81*U_i_inv41 + (1.0/4.0)*F51*F_inv51*U_i_inv51 + (1.0/2.0)*F51*F_inv81*U_i_inv21 + (1.0/2.0)*F61*F_inv51*U_i_inv31 + (1.0/4.0)*F61*F_inv81*U_i_inv51;
		gradient(1,5) = (1.0/4.0)*F41*F_inv21*U_i_inv61 + (1.0/2.0)*F41*F_inv81*U_i_inv11 + (1.0/4.0)*F51*F_inv21*U_i_inv51 + (1.0/4.0)*F51*F_inv81*U_i_inv41 + (1.0/2.0)*F61*F_inv21*U_i_inv31 + (1.0/4.0)*F61*F_inv81*U_i_inv61;
		gradient(1,6) = (1.0/2.0)*F41*(2*F_inv21*U_i_dot11 + F_inv51*U_i_dot41 + F_inv81*U_i_dot61);
		gradient(1,7) = (1.0/2.0)*F51*(F_inv21*U_i_dot41 + 2*F_inv51*U_i_dot21 + F_inv81*U_i_dot51);
		gradient(1,8) = (1.0/2.0)*F61*(F_inv21*U_i_dot61 + F_inv51*U_i_dot51 + 2*F_inv81*U_i_dot31);
		gradient(1,9) = (1.0/4.0)*F41*F_inv21*U_i_dot41 + (1.0/2.0)*F41*F_inv51*U_i_dot21 + (1.0/4.0)*F41*F_inv81*U_i_dot51 + (1.0/2.0)*F51*F_inv21*U_i_dot11 + (1.0/4.0)*F51*F_inv51*U_i_dot41 + (1.0/4.0)*F51*F_inv81*U_i_dot61;
		gradient(1,10) = (1.0/4.0)*F51*F_inv21*U_i_dot61 + (1.0/4.0)*F51*F_inv51*U_i_dot51 + (1.0/2.0)*F51*F_inv81*U_i_dot31 + (1.0/4.0)*F61*F_inv21*U_i_dot41 + (1.0/2.0)*F61*F_inv51*U_i_dot21 + (1.0/4.0)*F61*F_inv81*U_i_dot51;
		gradient(1,11) = (1.0/4.0)*F41*F_inv21*U_i_dot61 + (1.0/4.0)*F41*F_inv51*U_i_dot51 + (1.0/2.0)*F41*F_inv81*U_i_dot31 + (1.0/2.0)*F61*F_inv21*U_i_dot11 + (1.0/4.0)*F61*F_inv51*U_i_dot41 + (1.0/4.0)*F61*F_inv81*U_i_dot61;
		gradient(1,12) = 0;
		gradient(1,13) = 0;
		gradient(1,14) = 0;
		gradient(1,15) = F_inv21*U_i_dot11*U_i_inv11 + (1.0/4.0)*F_inv21*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv21*U_i_dot61*U_i_inv61 + (1.0/2.0)*F_inv51*U_i_dot21*U_i_inv41 + (1.0/2.0)*F_inv51*U_i_dot41*U_i_inv11 + (1.0/4.0)*F_inv51*U_i_dot51*U_i_inv61 + (1.0/2.0)*F_inv81*U_i_dot31*U_i_inv61 + (1.0/4.0)*F_inv81*U_i_dot51*U_i_inv41 + (1.0/2.0)*F_inv81*U_i_dot61*U_i_inv11;
		gradient(1,16) = (1.0/2.0)*F_inv21*U_i_dot11*U_i_inv41 + (1.0/2.0)*F_inv21*U_i_dot41*U_i_inv21 + (1.0/4.0)*F_inv21*U_i_dot61*U_i_inv51 + F_inv51*U_i_dot21*U_i_inv21 + (1.0/4.0)*F_inv51*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv51*U_i_dot51*U_i_inv51 + (1.0/2.0)*F_inv81*U_i_dot31*U_i_inv51 + (1.0/2.0)*F_inv81*U_i_dot51*U_i_inv21 + (1.0/4.0)*F_inv81*U_i_dot61*U_i_inv41;
		gradient(1,17) = (1.0/2.0)*F_inv21*U_i_dot11*U_i_inv61 + (1.0/4.0)*F_inv21*U_i_dot41*U_i_inv51 + (1.0/2.0)*F_inv21*U_i_dot61*U_i_inv31 + (1.0/2.0)*F_inv51*U_i_dot21*U_i_inv51 + (1.0/4.0)*F_inv51*U_i_dot41*U_i_inv61 + (1.0/2.0)*F_inv51*U_i_dot51*U_i_inv31 + F_inv81*U_i_dot31*U_i_inv31 + (1.0/4.0)*F_inv81*U_i_dot51*U_i_inv51 + (1.0/4.0)*F_inv81*U_i_dot61*U_i_inv61;
		gradient(1,18) = 0;
		gradient(1,19) = 0;
		gradient(1,20) = 0;
		gradient(1,21) = 0;
		gradient(1,22) = F41*U_i_dot11*U_i_inv11 + (1.0/4.0)*F41*U_i_dot41*U_i_inv41 + (1.0/4.0)*F41*U_i_dot61*U_i_inv61 + (1.0/2.0)*F51*U_i_dot11*U_i_inv41 + (1.0/2.0)*F51*U_i_dot41*U_i_inv21 + (1.0/4.0)*F51*U_i_dot61*U_i_inv51 + (1.0/2.0)*F61*U_i_dot11*U_i_inv61 + (1.0/4.0)*F61*U_i_dot41*U_i_inv51 + (1.0/2.0)*F61*U_i_dot61*U_i_inv31;
		gradient(1,23) = 0;
		gradient(1,24) = 0;
		gradient(1,25) = (1.0/2.0)*F41*U_i_dot21*U_i_inv41 + (1.0/2.0)*F41*U_i_dot41*U_i_inv11 + (1.0/4.0)*F41*U_i_dot51*U_i_inv61 + F51*U_i_dot21*U_i_inv21 + (1.0/4.0)*F51*U_i_dot41*U_i_inv41 + (1.0/4.0)*F51*U_i_dot51*U_i_inv51 + (1.0/2.0)*F61*U_i_dot21*U_i_inv51 + (1.0/4.0)*F61*U_i_dot41*U_i_inv61 + (1.0/2.0)*F61*U_i_dot51*U_i_inv31;
		gradient(1,26) = 0;
		gradient(1,27) = 0;
		gradient(1,28) = (1.0/2.0)*F41*U_i_dot31*U_i_inv61 + (1.0/4.0)*F41*U_i_dot51*U_i_inv41 + (1.0/2.0)*F41*U_i_dot61*U_i_inv11 + (1.0/2.0)*F51*U_i_dot31*U_i_inv51 + (1.0/2.0)*F51*U_i_dot51*U_i_inv21 + (1.0/4.0)*F51*U_i_dot61*U_i_inv41 + F61*U_i_dot31*U_i_inv31 + (1.0/4.0)*F61*U_i_dot51*U_i_inv51 + (1.0/4.0)*F61*U_i_dot61*U_i_inv61;
		gradient(1,29) = 0;
		gradient(2,0) = (1.0/2.0)*F_inv31*(2*F71*U_i_inv11 + F81*U_i_inv41 + F91*U_i_inv61);
		gradient(2,1) = (1.0/2.0)*F_inv61*(F71*U_i_inv41 + 2*F81*U_i_inv21 + F91*U_i_inv51);
		gradient(2,2) = (1.0/2.0)*F_inv91*(F71*U_i_inv61 + F81*U_i_inv51 + 2*F91*U_i_inv31);
		gradient(2,3) = (1.0/4.0)*F71*F_inv31*U_i_inv41 + (1.0/2.0)*F71*F_inv61*U_i_inv11 + (1.0/2.0)*F81*F_inv31*U_i_inv21 + (1.0/4.0)*F81*F_inv61*U_i_inv41 + (1.0/4.0)*F91*F_inv31*U_i_inv51 + (1.0/4.0)*F91*F_inv61*U_i_inv61;
		gradient(2,4) = (1.0/4.0)*F71*F_inv61*U_i_inv61 + (1.0/4.0)*F71*F_inv91*U_i_inv41 + (1.0/4.0)*F81*F_inv61*U_i_inv51 + (1.0/2.0)*F81*F_inv91*U_i_inv21 + (1.0/2.0)*F91*F_inv61*U_i_inv31 + (1.0/4.0)*F91*F_inv91*U_i_inv51;
		gradient(2,5) = (1.0/4.0)*F71*F_inv31*U_i_inv61 + (1.0/2.0)*F71*F_inv91*U_i_inv11 + (1.0/4.0)*F81*F_inv31*U_i_inv51 + (1.0/4.0)*F81*F_inv91*U_i_inv41 + (1.0/2.0)*F91*F_inv31*U_i_inv31 + (1.0/4.0)*F91*F_inv91*U_i_inv61;
		gradient(2,6) = (1.0/2.0)*F71*(2*F_inv31*U_i_dot11 + F_inv61*U_i_dot41 + F_inv91*U_i_dot61);
		gradient(2,7) = (1.0/2.0)*F81*(F_inv31*U_i_dot41 + 2*F_inv61*U_i_dot21 + F_inv91*U_i_dot51);
		gradient(2,8) = (1.0/2.0)*F91*(F_inv31*U_i_dot61 + F_inv61*U_i_dot51 + 2*F_inv91*U_i_dot31);
		gradient(2,9) = (1.0/4.0)*F71*F_inv31*U_i_dot41 + (1.0/2.0)*F71*F_inv61*U_i_dot21 + (1.0/4.0)*F71*F_inv91*U_i_dot51 + (1.0/2.0)*F81*F_inv31*U_i_dot11 + (1.0/4.0)*F81*F_inv61*U_i_dot41 + (1.0/4.0)*F81*F_inv91*U_i_dot61;
		gradient(2,10) = (1.0/4.0)*F81*F_inv31*U_i_dot61 + (1.0/4.0)*F81*F_inv61*U_i_dot51 + (1.0/2.0)*F81*F_inv91*U_i_dot31 + (1.0/4.0)*F91*F_inv31*U_i_dot41 + (1.0/2.0)*F91*F_inv61*U_i_dot21 + (1.0/4.0)*F91*F_inv91*U_i_dot51;
		gradient(2,11) = (1.0/4.0)*F71*F_inv31*U_i_dot61 + (1.0/4.0)*F71*F_inv61*U_i_dot51 + (1.0/2.0)*F71*F_inv91*U_i_dot31 + (1.0/2.0)*F91*F_inv31*U_i_dot11 + (1.0/4.0)*F91*F_inv61*U_i_dot41 + (1.0/4.0)*F91*F_inv91*U_i_dot61;
		gradient(2,12) = 0;
		gradient(2,13) = 0;
		gradient(2,14) = 0;
		gradient(2,15) = 0;
		gradient(2,16) = 0;
		gradient(2,17) = 0;
		gradient(2,18) = F_inv31*U_i_dot11*U_i_inv11 + (1.0/4.0)*F_inv31*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv31*U_i_dot61*U_i_inv61 + (1.0/2.0)*F_inv61*U_i_dot21*U_i_inv41 + (1.0/2.0)*F_inv61*U_i_dot41*U_i_inv11 + (1.0/4.0)*F_inv61*U_i_dot51*U_i_inv61 + (1.0/2.0)*F_inv91*U_i_dot31*U_i_inv61 + (1.0/4.0)*F_inv91*U_i_dot51*U_i_inv41 + (1.0/2.0)*F_inv91*U_i_dot61*U_i_inv11;
		gradient(2,19) = (1.0/2.0)*F_inv31*U_i_dot11*U_i_inv41 + (1.0/2.0)*F_inv31*U_i_dot41*U_i_inv21 + (1.0/4.0)*F_inv31*U_i_dot61*U_i_inv51 + F_inv61*U_i_dot21*U_i_inv21 + (1.0/4.0)*F_inv61*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv61*U_i_dot51*U_i_inv51 + (1.0/2.0)*F_inv91*U_i_dot31*U_i_inv51 + (1.0/2.0)*F_inv91*U_i_dot51*U_i_inv21 + (1.0/4.0)*F_inv91*U_i_dot61*U_i_inv41;
		gradient(2,20) = (1.0/2.0)*F_inv31*U_i_dot11*U_i_inv61 + (1.0/4.0)*F_inv31*U_i_dot41*U_i_inv51 + (1.0/2.0)*F_inv31*U_i_dot61*U_i_inv31 + (1.0/2.0)*F_inv61*U_i_dot21*U_i_inv51 + (1.0/4.0)*F_inv61*U_i_dot41*U_i_inv61 + (1.0/2.0)*F_inv61*U_i_dot51*U_i_inv31 + F_inv91*U_i_dot31*U_i_inv31 + (1.0/4.0)*F_inv91*U_i_dot51*U_i_inv51 + (1.0/4.0)*F_inv91*U_i_dot61*U_i_inv61;
		gradient(2,21) = 0;
		gradient(2,22) = 0;
		gradient(2,23) = F71*U_i_dot11*U_i_inv11 + (1.0/4.0)*F71*U_i_dot41*U_i_inv41 + (1.0/4.0)*F71*U_i_dot61*U_i_inv61 + (1.0/2.0)*F81*U_i_dot11*U_i_inv41 + (1.0/2.0)*F81*U_i_dot41*U_i_inv21 + (1.0/4.0)*F81*U_i_dot61*U_i_inv51 + (1.0/2.0)*F91*U_i_dot11*U_i_inv61 + (1.0/4.0)*F91*U_i_dot41*U_i_inv51 + (1.0/2.0)*F91*U_i_dot61*U_i_inv31;
		gradient(2,24) = 0;
		gradient(2,25) = 0;
		gradient(2,26) = (1.0/2.0)*F71*U_i_dot21*U_i_inv41 + (1.0/2.0)*F71*U_i_dot41*U_i_inv11 + (1.0/4.0)*F71*U_i_dot51*U_i_inv61 + F81*U_i_dot21*U_i_inv21 + (1.0/4.0)*F81*U_i_dot41*U_i_inv41 + (1.0/4.0)*F81*U_i_dot51*U_i_inv51 + (1.0/2.0)*F91*U_i_dot21*U_i_inv51 + (1.0/4.0)*F91*U_i_dot41*U_i_inv61 + (1.0/2.0)*F91*U_i_dot51*U_i_inv31;
		gradient(2,27) = 0;
		gradient(2,28) = 0;
		gradient(2,29) = (1.0/2.0)*F71*U_i_dot31*U_i_inv61 + (1.0/4.0)*F71*U_i_dot51*U_i_inv41 + (1.0/2.0)*F71*U_i_dot61*U_i_inv11 + (1.0/2.0)*F81*U_i_dot31*U_i_inv51 + (1.0/2.0)*F81*U_i_dot51*U_i_inv21 + (1.0/4.0)*F81*U_i_dot61*U_i_inv41 + F91*U_i_dot31*U_i_inv31 + (1.0/4.0)*F91*U_i_dot51*U_i_inv51 + (1.0/4.0)*F91*U_i_dot61*U_i_inv61;
		gradient(3,0) = F11*F_inv21*U_i_inv11 + (1.0/2.0)*F21*F_inv21*U_i_inv41 + (1.0/2.0)*F31*F_inv21*U_i_inv61 + F41*F_inv11*U_i_inv11 + (1.0/2.0)*F51*F_inv11*U_i_inv41 + (1.0/2.0)*F61*F_inv11*U_i_inv61;
		gradient(3,1) = (1.0/2.0)*F11*F_inv51*U_i_inv41 + F21*F_inv51*U_i_inv21 + (1.0/2.0)*F31*F_inv51*U_i_inv51 + (1.0/2.0)*F41*F_inv41*U_i_inv41 + F51*F_inv41*U_i_inv21 + (1.0/2.0)*F61*F_inv41*U_i_inv51;
		gradient(3,2) = (1.0/2.0)*F11*F_inv81*U_i_inv61 + (1.0/2.0)*F21*F_inv81*U_i_inv51 + F31*F_inv81*U_i_inv31 + (1.0/2.0)*F41*F_inv71*U_i_inv61 + (1.0/2.0)*F51*F_inv71*U_i_inv51 + F61*F_inv71*U_i_inv31;
		gradient(3,3) = (1.0/4.0)*F11*F_inv21*U_i_inv41 + (1.0/2.0)*F11*F_inv51*U_i_inv11 + (1.0/2.0)*F21*F_inv21*U_i_inv21 + (1.0/4.0)*F21*F_inv51*U_i_inv41 + (1.0/4.0)*F31*F_inv21*U_i_inv51 + (1.0/4.0)*F31*F_inv51*U_i_inv61 + (1.0/4.0)*F41*F_inv11*U_i_inv41 + (1.0/2.0)*F41*F_inv41*U_i_inv11 + (1.0/2.0)*F51*F_inv11*U_i_inv21 + (1.0/4.0)*F51*F_inv41*U_i_inv41 + (1.0/4.0)*F61*F_inv11*U_i_inv51 + (1.0/4.0)*F61*F_inv41*U_i_inv61;
		gradient(3,4) = (1.0/4.0)*F11*F_inv51*U_i_inv61 + (1.0/4.0)*F11*F_inv81*U_i_inv41 + (1.0/4.0)*F21*F_inv51*U_i_inv51 + (1.0/2.0)*F21*F_inv81*U_i_inv21 + (1.0/2.0)*F31*F_inv51*U_i_inv31 + (1.0/4.0)*F31*F_inv81*U_i_inv51 + (1.0/4.0)*F41*F_inv41*U_i_inv61 + (1.0/4.0)*F41*F_inv71*U_i_inv41 + (1.0/4.0)*F51*F_inv41*U_i_inv51 + (1.0/2.0)*F51*F_inv71*U_i_inv21 + (1.0/2.0)*F61*F_inv41*U_i_inv31 + (1.0/4.0)*F61*F_inv71*U_i_inv51;
		gradient(3,5) = (1.0/4.0)*F11*F_inv21*U_i_inv61 + (1.0/2.0)*F11*F_inv81*U_i_inv11 + (1.0/4.0)*F21*F_inv21*U_i_inv51 + (1.0/4.0)*F21*F_inv81*U_i_inv41 + (1.0/2.0)*F31*F_inv21*U_i_inv31 + (1.0/4.0)*F31*F_inv81*U_i_inv61 + (1.0/4.0)*F41*F_inv11*U_i_inv61 + (1.0/2.0)*F41*F_inv71*U_i_inv11 + (1.0/4.0)*F51*F_inv11*U_i_inv51 + (1.0/4.0)*F51*F_inv71*U_i_inv41 + (1.0/2.0)*F61*F_inv11*U_i_inv31 + (1.0/4.0)*F61*F_inv71*U_i_inv61;
		gradient(3,6) = F11*F_inv21*U_i_dot11 + (1.0/2.0)*F11*F_inv51*U_i_dot41 + (1.0/2.0)*F11*F_inv81*U_i_dot61 + F41*F_inv11*U_i_dot11 + (1.0/2.0)*F41*F_inv41*U_i_dot41 + (1.0/2.0)*F41*F_inv71*U_i_dot61;
		gradient(3,7) = (1.0/2.0)*F21*F_inv21*U_i_dot41 + F21*F_inv51*U_i_dot21 + (1.0/2.0)*F21*F_inv81*U_i_dot51 + (1.0/2.0)*F51*F_inv11*U_i_dot41 + F51*F_inv41*U_i_dot21 + (1.0/2.0)*F51*F_inv71*U_i_dot51;
		gradient(3,8) = (1.0/2.0)*F31*F_inv21*U_i_dot61 + (1.0/2.0)*F31*F_inv51*U_i_dot51 + F31*F_inv81*U_i_dot31 + (1.0/2.0)*F61*F_inv11*U_i_dot61 + (1.0/2.0)*F61*F_inv41*U_i_dot51 + F61*F_inv71*U_i_dot31;
		gradient(3,9) = (1.0/4.0)*F11*F_inv21*U_i_dot41 + (1.0/2.0)*F11*F_inv51*U_i_dot21 + (1.0/4.0)*F11*F_inv81*U_i_dot51 + (1.0/2.0)*F21*F_inv21*U_i_dot11 + (1.0/4.0)*F21*F_inv51*U_i_dot41 + (1.0/4.0)*F21*F_inv81*U_i_dot61 + (1.0/4.0)*F41*F_inv11*U_i_dot41 + (1.0/2.0)*F41*F_inv41*U_i_dot21 + (1.0/4.0)*F41*F_inv71*U_i_dot51 + (1.0/2.0)*F51*F_inv11*U_i_dot11 + (1.0/4.0)*F51*F_inv41*U_i_dot41 + (1.0/4.0)*F51*F_inv71*U_i_dot61;
		gradient(3,10) = (1.0/4.0)*F21*F_inv21*U_i_dot61 + (1.0/4.0)*F21*F_inv51*U_i_dot51 + (1.0/2.0)*F21*F_inv81*U_i_dot31 + (1.0/4.0)*F31*F_inv21*U_i_dot41 + (1.0/2.0)*F31*F_inv51*U_i_dot21 + (1.0/4.0)*F31*F_inv81*U_i_dot51 + (1.0/4.0)*F51*F_inv11*U_i_dot61 + (1.0/4.0)*F51*F_inv41*U_i_dot51 + (1.0/2.0)*F51*F_inv71*U_i_dot31 + (1.0/4.0)*F61*F_inv11*U_i_dot41 + (1.0/2.0)*F61*F_inv41*U_i_dot21 + (1.0/4.0)*F61*F_inv71*U_i_dot51;
		gradient(3,11) = (1.0/4.0)*F11*F_inv21*U_i_dot61 + (1.0/4.0)*F11*F_inv51*U_i_dot51 + (1.0/2.0)*F11*F_inv81*U_i_dot31 + (1.0/2.0)*F31*F_inv21*U_i_dot11 + (1.0/4.0)*F31*F_inv51*U_i_dot41 + (1.0/4.0)*F31*F_inv81*U_i_dot61 + (1.0/4.0)*F41*F_inv11*U_i_dot61 + (1.0/4.0)*F41*F_inv41*U_i_dot51 + (1.0/2.0)*F41*F_inv71*U_i_dot31 + (1.0/2.0)*F61*F_inv11*U_i_dot11 + (1.0/4.0)*F61*F_inv41*U_i_dot41 + (1.0/4.0)*F61*F_inv71*U_i_dot61;
		gradient(3,12) = F_inv21*U_i_dot11*U_i_inv11 + (1.0/4.0)*F_inv21*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv21*U_i_dot61*U_i_inv61 + (1.0/2.0)*F_inv51*U_i_dot21*U_i_inv41 + (1.0/2.0)*F_inv51*U_i_dot41*U_i_inv11 + (1.0/4.0)*F_inv51*U_i_dot51*U_i_inv61 + (1.0/2.0)*F_inv81*U_i_dot31*U_i_inv61 + (1.0/4.0)*F_inv81*U_i_dot51*U_i_inv41 + (1.0/2.0)*F_inv81*U_i_dot61*U_i_inv11;
		gradient(3,13) = (1.0/2.0)*F_inv21*U_i_dot11*U_i_inv41 + (1.0/2.0)*F_inv21*U_i_dot41*U_i_inv21 + (1.0/4.0)*F_inv21*U_i_dot61*U_i_inv51 + F_inv51*U_i_dot21*U_i_inv21 + (1.0/4.0)*F_inv51*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv51*U_i_dot51*U_i_inv51 + (1.0/2.0)*F_inv81*U_i_dot31*U_i_inv51 + (1.0/2.0)*F_inv81*U_i_dot51*U_i_inv21 + (1.0/4.0)*F_inv81*U_i_dot61*U_i_inv41;
		gradient(3,14) = (1.0/2.0)*F_inv21*U_i_dot11*U_i_inv61 + (1.0/4.0)*F_inv21*U_i_dot41*U_i_inv51 + (1.0/2.0)*F_inv21*U_i_dot61*U_i_inv31 + (1.0/2.0)*F_inv51*U_i_dot21*U_i_inv51 + (1.0/4.0)*F_inv51*U_i_dot41*U_i_inv61 + (1.0/2.0)*F_inv51*U_i_dot51*U_i_inv31 + F_inv81*U_i_dot31*U_i_inv31 + (1.0/4.0)*F_inv81*U_i_dot51*U_i_inv51 + (1.0/4.0)*F_inv81*U_i_dot61*U_i_inv61;
		gradient(3,15) = F_inv11*U_i_dot11*U_i_inv11 + (1.0/4.0)*F_inv11*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv11*U_i_dot61*U_i_inv61 + (1.0/2.0)*F_inv41*U_i_dot21*U_i_inv41 + (1.0/2.0)*F_inv41*U_i_dot41*U_i_inv11 + (1.0/4.0)*F_inv41*U_i_dot51*U_i_inv61 + (1.0/2.0)*F_inv71*U_i_dot31*U_i_inv61 + (1.0/4.0)*F_inv71*U_i_dot51*U_i_inv41 + (1.0/2.0)*F_inv71*U_i_dot61*U_i_inv11;
		gradient(3,16) = (1.0/2.0)*F_inv11*U_i_dot11*U_i_inv41 + (1.0/2.0)*F_inv11*U_i_dot41*U_i_inv21 + (1.0/4.0)*F_inv11*U_i_dot61*U_i_inv51 + F_inv41*U_i_dot21*U_i_inv21 + (1.0/4.0)*F_inv41*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv41*U_i_dot51*U_i_inv51 + (1.0/2.0)*F_inv71*U_i_dot31*U_i_inv51 + (1.0/2.0)*F_inv71*U_i_dot51*U_i_inv21 + (1.0/4.0)*F_inv71*U_i_dot61*U_i_inv41;
		gradient(3,17) = (1.0/2.0)*F_inv11*U_i_dot11*U_i_inv61 + (1.0/4.0)*F_inv11*U_i_dot41*U_i_inv51 + (1.0/2.0)*F_inv11*U_i_dot61*U_i_inv31 + (1.0/2.0)*F_inv41*U_i_dot21*U_i_inv51 + (1.0/4.0)*F_inv41*U_i_dot41*U_i_inv61 + (1.0/2.0)*F_inv41*U_i_dot51*U_i_inv31 + F_inv71*U_i_dot31*U_i_inv31 + (1.0/4.0)*F_inv71*U_i_dot51*U_i_inv51 + (1.0/4.0)*F_inv71*U_i_dot61*U_i_inv61;
		gradient(3,18) = 0;
		gradient(3,19) = 0;
		gradient(3,20) = 0;
		gradient(3,21) = F41*U_i_dot11*U_i_inv11 + (1.0/4.0)*F41*U_i_dot41*U_i_inv41 + (1.0/4.0)*F41*U_i_dot61*U_i_inv61 + (1.0/2.0)*F51*U_i_dot11*U_i_inv41 + (1.0/2.0)*F51*U_i_dot41*U_i_inv21 + (1.0/4.0)*F51*U_i_dot61*U_i_inv51 + (1.0/2.0)*F61*U_i_dot11*U_i_inv61 + (1.0/4.0)*F61*U_i_dot41*U_i_inv51 + (1.0/2.0)*F61*U_i_dot61*U_i_inv31;
		gradient(3,22) = F11*U_i_dot11*U_i_inv11 + (1.0/4.0)*F11*U_i_dot41*U_i_inv41 + (1.0/4.0)*F11*U_i_dot61*U_i_inv61 + (1.0/2.0)*F21*U_i_dot11*U_i_inv41 + (1.0/2.0)*F21*U_i_dot41*U_i_inv21 + (1.0/4.0)*F21*U_i_dot61*U_i_inv51 + (1.0/2.0)*F31*U_i_dot11*U_i_inv61 + (1.0/4.0)*F31*U_i_dot41*U_i_inv51 + (1.0/2.0)*F31*U_i_dot61*U_i_inv31;
		gradient(3,23) = 0;
		gradient(3,24) = (1.0/2.0)*F41*U_i_dot21*U_i_inv41 + (1.0/2.0)*F41*U_i_dot41*U_i_inv11 + (1.0/4.0)*F41*U_i_dot51*U_i_inv61 + F51*U_i_dot21*U_i_inv21 + (1.0/4.0)*F51*U_i_dot41*U_i_inv41 + (1.0/4.0)*F51*U_i_dot51*U_i_inv51 + (1.0/2.0)*F61*U_i_dot21*U_i_inv51 + (1.0/4.0)*F61*U_i_dot41*U_i_inv61 + (1.0/2.0)*F61*U_i_dot51*U_i_inv31;
		gradient(3,25) = (1.0/2.0)*F11*U_i_dot21*U_i_inv41 + (1.0/2.0)*F11*U_i_dot41*U_i_inv11 + (1.0/4.0)*F11*U_i_dot51*U_i_inv61 + F21*U_i_dot21*U_i_inv21 + (1.0/4.0)*F21*U_i_dot41*U_i_inv41 + (1.0/4.0)*F21*U_i_dot51*U_i_inv51 + (1.0/2.0)*F31*U_i_dot21*U_i_inv51 + (1.0/4.0)*F31*U_i_dot41*U_i_inv61 + (1.0/2.0)*F31*U_i_dot51*U_i_inv31;
		gradient(3,26) = 0;
		gradient(3,27) = (1.0/2.0)*F41*U_i_dot31*U_i_inv61 + (1.0/4.0)*F41*U_i_dot51*U_i_inv41 + (1.0/2.0)*F41*U_i_dot61*U_i_inv11 + (1.0/2.0)*F51*U_i_dot31*U_i_inv51 + (1.0/2.0)*F51*U_i_dot51*U_i_inv21 + (1.0/4.0)*F51*U_i_dot61*U_i_inv41 + F61*U_i_dot31*U_i_inv31 + (1.0/4.0)*F61*U_i_dot51*U_i_inv51 + (1.0/4.0)*F61*U_i_dot61*U_i_inv61;
		gradient(3,28) = (1.0/2.0)*F11*U_i_dot31*U_i_inv61 + (1.0/4.0)*F11*U_i_dot51*U_i_inv41 + (1.0/2.0)*F11*U_i_dot61*U_i_inv11 + (1.0/2.0)*F21*U_i_dot31*U_i_inv51 + (1.0/2.0)*F21*U_i_dot51*U_i_inv21 + (1.0/4.0)*F21*U_i_dot61*U_i_inv41 + F31*U_i_dot31*U_i_inv31 + (1.0/4.0)*F31*U_i_dot51*U_i_inv51 + (1.0/4.0)*F31*U_i_dot61*U_i_inv61;
		gradient(3,29) = 0;
		gradient(4,0) = F41*F_inv31*U_i_inv11 + (1.0/2.0)*F51*F_inv31*U_i_inv41 + (1.0/2.0)*F61*F_inv31*U_i_inv61 + F71*F_inv21*U_i_inv11 + (1.0/2.0)*F81*F_inv21*U_i_inv41 + (1.0/2.0)*F91*F_inv21*U_i_inv61;
		gradient(4,1) = (1.0/2.0)*F41*F_inv61*U_i_inv41 + F51*F_inv61*U_i_inv21 + (1.0/2.0)*F61*F_inv61*U_i_inv51 + (1.0/2.0)*F71*F_inv51*U_i_inv41 + F81*F_inv51*U_i_inv21 + (1.0/2.0)*F91*F_inv51*U_i_inv51;
		gradient(4,2) = (1.0/2.0)*F41*F_inv91*U_i_inv61 + (1.0/2.0)*F51*F_inv91*U_i_inv51 + F61*F_inv91*U_i_inv31 + (1.0/2.0)*F71*F_inv81*U_i_inv61 + (1.0/2.0)*F81*F_inv81*U_i_inv51 + F91*F_inv81*U_i_inv31;
		gradient(4,3) = (1.0/4.0)*F41*F_inv31*U_i_inv41 + (1.0/2.0)*F41*F_inv61*U_i_inv11 + (1.0/2.0)*F51*F_inv31*U_i_inv21 + (1.0/4.0)*F51*F_inv61*U_i_inv41 + (1.0/4.0)*F61*F_inv31*U_i_inv51 + (1.0/4.0)*F61*F_inv61*U_i_inv61 + (1.0/4.0)*F71*F_inv21*U_i_inv41 + (1.0/2.0)*F71*F_inv51*U_i_inv11 + (1.0/2.0)*F81*F_inv21*U_i_inv21 + (1.0/4.0)*F81*F_inv51*U_i_inv41 + (1.0/4.0)*F91*F_inv21*U_i_inv51 + (1.0/4.0)*F91*F_inv51*U_i_inv61;
		gradient(4,4) = (1.0/4.0)*F41*F_inv61*U_i_inv61 + (1.0/4.0)*F41*F_inv91*U_i_inv41 + (1.0/4.0)*F51*F_inv61*U_i_inv51 + (1.0/2.0)*F51*F_inv91*U_i_inv21 + (1.0/2.0)*F61*F_inv61*U_i_inv31 + (1.0/4.0)*F61*F_inv91*U_i_inv51 + (1.0/4.0)*F71*F_inv51*U_i_inv61 + (1.0/4.0)*F71*F_inv81*U_i_inv41 + (1.0/4.0)*F81*F_inv51*U_i_inv51 + (1.0/2.0)*F81*F_inv81*U_i_inv21 + (1.0/2.0)*F91*F_inv51*U_i_inv31 + (1.0/4.0)*F91*F_inv81*U_i_inv51;
		gradient(4,5) = (1.0/4.0)*F41*F_inv31*U_i_inv61 + (1.0/2.0)*F41*F_inv91*U_i_inv11 + (1.0/4.0)*F51*F_inv31*U_i_inv51 + (1.0/4.0)*F51*F_inv91*U_i_inv41 + (1.0/2.0)*F61*F_inv31*U_i_inv31 + (1.0/4.0)*F61*F_inv91*U_i_inv61 + (1.0/4.0)*F71*F_inv21*U_i_inv61 + (1.0/2.0)*F71*F_inv81*U_i_inv11 + (1.0/4.0)*F81*F_inv21*U_i_inv51 + (1.0/4.0)*F81*F_inv81*U_i_inv41 + (1.0/2.0)*F91*F_inv21*U_i_inv31 + (1.0/4.0)*F91*F_inv81*U_i_inv61;
		gradient(4,6) = F41*F_inv31*U_i_dot11 + (1.0/2.0)*F41*F_inv61*U_i_dot41 + (1.0/2.0)*F41*F_inv91*U_i_dot61 + F71*F_inv21*U_i_dot11 + (1.0/2.0)*F71*F_inv51*U_i_dot41 + (1.0/2.0)*F71*F_inv81*U_i_dot61;
		gradient(4,7) = (1.0/2.0)*F51*F_inv31*U_i_dot41 + F51*F_inv61*U_i_dot21 + (1.0/2.0)*F51*F_inv91*U_i_dot51 + (1.0/2.0)*F81*F_inv21*U_i_dot41 + F81*F_inv51*U_i_dot21 + (1.0/2.0)*F81*F_inv81*U_i_dot51;
		gradient(4,8) = (1.0/2.0)*F61*F_inv31*U_i_dot61 + (1.0/2.0)*F61*F_inv61*U_i_dot51 + F61*F_inv91*U_i_dot31 + (1.0/2.0)*F91*F_inv21*U_i_dot61 + (1.0/2.0)*F91*F_inv51*U_i_dot51 + F91*F_inv81*U_i_dot31;
		gradient(4,9) = (1.0/4.0)*F41*F_inv31*U_i_dot41 + (1.0/2.0)*F41*F_inv61*U_i_dot21 + (1.0/4.0)*F41*F_inv91*U_i_dot51 + (1.0/2.0)*F51*F_inv31*U_i_dot11 + (1.0/4.0)*F51*F_inv61*U_i_dot41 + (1.0/4.0)*F51*F_inv91*U_i_dot61 + (1.0/4.0)*F71*F_inv21*U_i_dot41 + (1.0/2.0)*F71*F_inv51*U_i_dot21 + (1.0/4.0)*F71*F_inv81*U_i_dot51 + (1.0/2.0)*F81*F_inv21*U_i_dot11 + (1.0/4.0)*F81*F_inv51*U_i_dot41 + (1.0/4.0)*F81*F_inv81*U_i_dot61;
		gradient(4,10) = (1.0/4.0)*F51*F_inv31*U_i_dot61 + (1.0/4.0)*F51*F_inv61*U_i_dot51 + (1.0/2.0)*F51*F_inv91*U_i_dot31 + (1.0/4.0)*F61*F_inv31*U_i_dot41 + (1.0/2.0)*F61*F_inv61*U_i_dot21 + (1.0/4.0)*F61*F_inv91*U_i_dot51 + (1.0/4.0)*F81*F_inv21*U_i_dot61 + (1.0/4.0)*F81*F_inv51*U_i_dot51 + (1.0/2.0)*F81*F_inv81*U_i_dot31 + (1.0/4.0)*F91*F_inv21*U_i_dot41 + (1.0/2.0)*F91*F_inv51*U_i_dot21 + (1.0/4.0)*F91*F_inv81*U_i_dot51;
		gradient(4,11) = (1.0/4.0)*F41*F_inv31*U_i_dot61 + (1.0/4.0)*F41*F_inv61*U_i_dot51 + (1.0/2.0)*F41*F_inv91*U_i_dot31 + (1.0/2.0)*F61*F_inv31*U_i_dot11 + (1.0/4.0)*F61*F_inv61*U_i_dot41 + (1.0/4.0)*F61*F_inv91*U_i_dot61 + (1.0/4.0)*F71*F_inv21*U_i_dot61 + (1.0/4.0)*F71*F_inv51*U_i_dot51 + (1.0/2.0)*F71*F_inv81*U_i_dot31 + (1.0/2.0)*F91*F_inv21*U_i_dot11 + (1.0/4.0)*F91*F_inv51*U_i_dot41 + (1.0/4.0)*F91*F_inv81*U_i_dot61;
		gradient(4,12) = 0;
		gradient(4,13) = 0;
		gradient(4,14) = 0;
		gradient(4,15) = F_inv31*U_i_dot11*U_i_inv11 + (1.0/4.0)*F_inv31*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv31*U_i_dot61*U_i_inv61 + (1.0/2.0)*F_inv61*U_i_dot21*U_i_inv41 + (1.0/2.0)*F_inv61*U_i_dot41*U_i_inv11 + (1.0/4.0)*F_inv61*U_i_dot51*U_i_inv61 + (1.0/2.0)*F_inv91*U_i_dot31*U_i_inv61 + (1.0/4.0)*F_inv91*U_i_dot51*U_i_inv41 + (1.0/2.0)*F_inv91*U_i_dot61*U_i_inv11;
		gradient(4,16) = (1.0/2.0)*F_inv31*U_i_dot11*U_i_inv41 + (1.0/2.0)*F_inv31*U_i_dot41*U_i_inv21 + (1.0/4.0)*F_inv31*U_i_dot61*U_i_inv51 + F_inv61*U_i_dot21*U_i_inv21 + (1.0/4.0)*F_inv61*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv61*U_i_dot51*U_i_inv51 + (1.0/2.0)*F_inv91*U_i_dot31*U_i_inv51 + (1.0/2.0)*F_inv91*U_i_dot51*U_i_inv21 + (1.0/4.0)*F_inv91*U_i_dot61*U_i_inv41;
		gradient(4,17) = (1.0/2.0)*F_inv31*U_i_dot11*U_i_inv61 + (1.0/4.0)*F_inv31*U_i_dot41*U_i_inv51 + (1.0/2.0)*F_inv31*U_i_dot61*U_i_inv31 + (1.0/2.0)*F_inv61*U_i_dot21*U_i_inv51 + (1.0/4.0)*F_inv61*U_i_dot41*U_i_inv61 + (1.0/2.0)*F_inv61*U_i_dot51*U_i_inv31 + F_inv91*U_i_dot31*U_i_inv31 + (1.0/4.0)*F_inv91*U_i_dot51*U_i_inv51 + (1.0/4.0)*F_inv91*U_i_dot61*U_i_inv61;
		gradient(4,18) = F_inv21*U_i_dot11*U_i_inv11 + (1.0/4.0)*F_inv21*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv21*U_i_dot61*U_i_inv61 + (1.0/2.0)*F_inv51*U_i_dot21*U_i_inv41 + (1.0/2.0)*F_inv51*U_i_dot41*U_i_inv11 + (1.0/4.0)*F_inv51*U_i_dot51*U_i_inv61 + (1.0/2.0)*F_inv81*U_i_dot31*U_i_inv61 + (1.0/4.0)*F_inv81*U_i_dot51*U_i_inv41 + (1.0/2.0)*F_inv81*U_i_dot61*U_i_inv11;
		gradient(4,19) = (1.0/2.0)*F_inv21*U_i_dot11*U_i_inv41 + (1.0/2.0)*F_inv21*U_i_dot41*U_i_inv21 + (1.0/4.0)*F_inv21*U_i_dot61*U_i_inv51 + F_inv51*U_i_dot21*U_i_inv21 + (1.0/4.0)*F_inv51*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv51*U_i_dot51*U_i_inv51 + (1.0/2.0)*F_inv81*U_i_dot31*U_i_inv51 + (1.0/2.0)*F_inv81*U_i_dot51*U_i_inv21 + (1.0/4.0)*F_inv81*U_i_dot61*U_i_inv41;
		gradient(4,20) = (1.0/2.0)*F_inv21*U_i_dot11*U_i_inv61 + (1.0/4.0)*F_inv21*U_i_dot41*U_i_inv51 + (1.0/2.0)*F_inv21*U_i_dot61*U_i_inv31 + (1.0/2.0)*F_inv51*U_i_dot21*U_i_inv51 + (1.0/4.0)*F_inv51*U_i_dot41*U_i_inv61 + (1.0/2.0)*F_inv51*U_i_dot51*U_i_inv31 + F_inv81*U_i_dot31*U_i_inv31 + (1.0/4.0)*F_inv81*U_i_dot51*U_i_inv51 + (1.0/4.0)*F_inv81*U_i_dot61*U_i_inv61;
		gradient(4,21) = 0;
		gradient(4,22) = F71*U_i_dot11*U_i_inv11 + (1.0/4.0)*F71*U_i_dot41*U_i_inv41 + (1.0/4.0)*F71*U_i_dot61*U_i_inv61 + (1.0/2.0)*F81*U_i_dot11*U_i_inv41 + (1.0/2.0)*F81*U_i_dot41*U_i_inv21 + (1.0/4.0)*F81*U_i_dot61*U_i_inv51 + (1.0/2.0)*F91*U_i_dot11*U_i_inv61 + (1.0/4.0)*F91*U_i_dot41*U_i_inv51 + (1.0/2.0)*F91*U_i_dot61*U_i_inv31;
		gradient(4,23) = F41*U_i_dot11*U_i_inv11 + (1.0/4.0)*F41*U_i_dot41*U_i_inv41 + (1.0/4.0)*F41*U_i_dot61*U_i_inv61 + (1.0/2.0)*F51*U_i_dot11*U_i_inv41 + (1.0/2.0)*F51*U_i_dot41*U_i_inv21 + (1.0/4.0)*F51*U_i_dot61*U_i_inv51 + (1.0/2.0)*F61*U_i_dot11*U_i_inv61 + (1.0/4.0)*F61*U_i_dot41*U_i_inv51 + (1.0/2.0)*F61*U_i_dot61*U_i_inv31;
		gradient(4,24) = 0;
		gradient(4,25) = (1.0/2.0)*F71*U_i_dot21*U_i_inv41 + (1.0/2.0)*F71*U_i_dot41*U_i_inv11 + (1.0/4.0)*F71*U_i_dot51*U_i_inv61 + F81*U_i_dot21*U_i_inv21 + (1.0/4.0)*F81*U_i_dot41*U_i_inv41 + (1.0/4.0)*F81*U_i_dot51*U_i_inv51 + (1.0/2.0)*F91*U_i_dot21*U_i_inv51 + (1.0/4.0)*F91*U_i_dot41*U_i_inv61 + (1.0/2.0)*F91*U_i_dot51*U_i_inv31;
		gradient(4,26) = (1.0/2.0)*F41*U_i_dot21*U_i_inv41 + (1.0/2.0)*F41*U_i_dot41*U_i_inv11 + (1.0/4.0)*F41*U_i_dot51*U_i_inv61 + F51*U_i_dot21*U_i_inv21 + (1.0/4.0)*F51*U_i_dot41*U_i_inv41 + (1.0/4.0)*F51*U_i_dot51*U_i_inv51 + (1.0/2.0)*F61*U_i_dot21*U_i_inv51 + (1.0/4.0)*F61*U_i_dot41*U_i_inv61 + (1.0/2.0)*F61*U_i_dot51*U_i_inv31;
		gradient(4,27) = 0;
		gradient(4,28) = (1.0/2.0)*F71*U_i_dot31*U_i_inv61 + (1.0/4.0)*F71*U_i_dot51*U_i_inv41 + (1.0/2.0)*F71*U_i_dot61*U_i_inv11 + (1.0/2.0)*F81*U_i_dot31*U_i_inv51 + (1.0/2.0)*F81*U_i_dot51*U_i_inv21 + (1.0/4.0)*F81*U_i_dot61*U_i_inv41 + F91*U_i_dot31*U_i_inv31 + (1.0/4.0)*F91*U_i_dot51*U_i_inv51 + (1.0/4.0)*F91*U_i_dot61*U_i_inv61;
		gradient(4,29) = (1.0/2.0)*F41*U_i_dot31*U_i_inv61 + (1.0/4.0)*F41*U_i_dot51*U_i_inv41 + (1.0/2.0)*F41*U_i_dot61*U_i_inv11 + (1.0/2.0)*F51*U_i_dot31*U_i_inv51 + (1.0/2.0)*F51*U_i_dot51*U_i_inv21 + (1.0/4.0)*F51*U_i_dot61*U_i_inv41 + F61*U_i_dot31*U_i_inv31 + (1.0/4.0)*F61*U_i_dot51*U_i_inv51 + (1.0/4.0)*F61*U_i_dot61*U_i_inv61;
		gradient(5,0) = F11*F_inv31*U_i_inv11 + (1.0/2.0)*F21*F_inv31*U_i_inv41 + (1.0/2.0)*F31*F_inv31*U_i_inv61 + F71*F_inv11*U_i_inv11 + (1.0/2.0)*F81*F_inv11*U_i_inv41 + (1.0/2.0)*F91*F_inv11*U_i_inv61;
		gradient(5,1) = (1.0/2.0)*F11*F_inv61*U_i_inv41 + F21*F_inv61*U_i_inv21 + (1.0/2.0)*F31*F_inv61*U_i_inv51 + (1.0/2.0)*F71*F_inv41*U_i_inv41 + F81*F_inv41*U_i_inv21 + (1.0/2.0)*F91*F_inv41*U_i_inv51;
		gradient(5,2) = (1.0/2.0)*F11*F_inv91*U_i_inv61 + (1.0/2.0)*F21*F_inv91*U_i_inv51 + F31*F_inv91*U_i_inv31 + (1.0/2.0)*F71*F_inv71*U_i_inv61 + (1.0/2.0)*F81*F_inv71*U_i_inv51 + F91*F_inv71*U_i_inv31;
		gradient(5,3) = (1.0/4.0)*F11*F_inv31*U_i_inv41 + (1.0/2.0)*F11*F_inv61*U_i_inv11 + (1.0/2.0)*F21*F_inv31*U_i_inv21 + (1.0/4.0)*F21*F_inv61*U_i_inv41 + (1.0/4.0)*F31*F_inv31*U_i_inv51 + (1.0/4.0)*F31*F_inv61*U_i_inv61 + (1.0/4.0)*F71*F_inv11*U_i_inv41 + (1.0/2.0)*F71*F_inv41*U_i_inv11 + (1.0/2.0)*F81*F_inv11*U_i_inv21 + (1.0/4.0)*F81*F_inv41*U_i_inv41 + (1.0/4.0)*F91*F_inv11*U_i_inv51 + (1.0/4.0)*F91*F_inv41*U_i_inv61;
		gradient(5,4) = (1.0/4.0)*F11*F_inv61*U_i_inv61 + (1.0/4.0)*F11*F_inv91*U_i_inv41 + (1.0/4.0)*F21*F_inv61*U_i_inv51 + (1.0/2.0)*F21*F_inv91*U_i_inv21 + (1.0/2.0)*F31*F_inv61*U_i_inv31 + (1.0/4.0)*F31*F_inv91*U_i_inv51 + (1.0/4.0)*F71*F_inv41*U_i_inv61 + (1.0/4.0)*F71*F_inv71*U_i_inv41 + (1.0/4.0)*F81*F_inv41*U_i_inv51 + (1.0/2.0)*F81*F_inv71*U_i_inv21 + (1.0/2.0)*F91*F_inv41*U_i_inv31 + (1.0/4.0)*F91*F_inv71*U_i_inv51;
		gradient(5,5) = (1.0/4.0)*F11*F_inv31*U_i_inv61 + (1.0/2.0)*F11*F_inv91*U_i_inv11 + (1.0/4.0)*F21*F_inv31*U_i_inv51 + (1.0/4.0)*F21*F_inv91*U_i_inv41 + (1.0/2.0)*F31*F_inv31*U_i_inv31 + (1.0/4.0)*F31*F_inv91*U_i_inv61 + (1.0/4.0)*F71*F_inv11*U_i_inv61 + (1.0/2.0)*F71*F_inv71*U_i_inv11 + (1.0/4.0)*F81*F_inv11*U_i_inv51 + (1.0/4.0)*F81*F_inv71*U_i_inv41 + (1.0/2.0)*F91*F_inv11*U_i_inv31 + (1.0/4.0)*F91*F_inv71*U_i_inv61;
		gradient(5,6) = F11*F_inv31*U_i_dot11 + (1.0/2.0)*F11*F_inv61*U_i_dot41 + (1.0/2.0)*F11*F_inv91*U_i_dot61 + F71*F_inv11*U_i_dot11 + (1.0/2.0)*F71*F_inv41*U_i_dot41 + (1.0/2.0)*F71*F_inv71*U_i_dot61;
		gradient(5,7) = (1.0/2.0)*F21*F_inv31*U_i_dot41 + F21*F_inv61*U_i_dot21 + (1.0/2.0)*F21*F_inv91*U_i_dot51 + (1.0/2.0)*F81*F_inv11*U_i_dot41 + F81*F_inv41*U_i_dot21 + (1.0/2.0)*F81*F_inv71*U_i_dot51;
		gradient(5,8) = (1.0/2.0)*F31*F_inv31*U_i_dot61 + (1.0/2.0)*F31*F_inv61*U_i_dot51 + F31*F_inv91*U_i_dot31 + (1.0/2.0)*F91*F_inv11*U_i_dot61 + (1.0/2.0)*F91*F_inv41*U_i_dot51 + F91*F_inv71*U_i_dot31;
		gradient(5,9) = (1.0/4.0)*F11*F_inv31*U_i_dot41 + (1.0/2.0)*F11*F_inv61*U_i_dot21 + (1.0/4.0)*F11*F_inv91*U_i_dot51 + (1.0/2.0)*F21*F_inv31*U_i_dot11 + (1.0/4.0)*F21*F_inv61*U_i_dot41 + (1.0/4.0)*F21*F_inv91*U_i_dot61 + (1.0/4.0)*F71*F_inv11*U_i_dot41 + (1.0/2.0)*F71*F_inv41*U_i_dot21 + (1.0/4.0)*F71*F_inv71*U_i_dot51 + (1.0/2.0)*F81*F_inv11*U_i_dot11 + (1.0/4.0)*F81*F_inv41*U_i_dot41 + (1.0/4.0)*F81*F_inv71*U_i_dot61;
		gradient(5,10) = (1.0/4.0)*F21*F_inv31*U_i_dot61 + (1.0/4.0)*F21*F_inv61*U_i_dot51 + (1.0/2.0)*F21*F_inv91*U_i_dot31 + (1.0/4.0)*F31*F_inv31*U_i_dot41 + (1.0/2.0)*F31*F_inv61*U_i_dot21 + (1.0/4.0)*F31*F_inv91*U_i_dot51 + (1.0/4.0)*F81*F_inv11*U_i_dot61 + (1.0/4.0)*F81*F_inv41*U_i_dot51 + (1.0/2.0)*F81*F_inv71*U_i_dot31 + (1.0/4.0)*F91*F_inv11*U_i_dot41 + (1.0/2.0)*F91*F_inv41*U_i_dot21 + (1.0/4.0)*F91*F_inv71*U_i_dot51;
		gradient(5,11) = (1.0/4.0)*F11*F_inv31*U_i_dot61 + (1.0/4.0)*F11*F_inv61*U_i_dot51 + (1.0/2.0)*F11*F_inv91*U_i_dot31 + (1.0/2.0)*F31*F_inv31*U_i_dot11 + (1.0/4.0)*F31*F_inv61*U_i_dot41 + (1.0/4.0)*F31*F_inv91*U_i_dot61 + (1.0/4.0)*F71*F_inv11*U_i_dot61 + (1.0/4.0)*F71*F_inv41*U_i_dot51 + (1.0/2.0)*F71*F_inv71*U_i_dot31 + (1.0/2.0)*F91*F_inv11*U_i_dot11 + (1.0/4.0)*F91*F_inv41*U_i_dot41 + (1.0/4.0)*F91*F_inv71*U_i_dot61;
		gradient(5,12) = F_inv31*U_i_dot11*U_i_inv11 + (1.0/4.0)*F_inv31*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv31*U_i_dot61*U_i_inv61 + (1.0/2.0)*F_inv61*U_i_dot21*U_i_inv41 + (1.0/2.0)*F_inv61*U_i_dot41*U_i_inv11 + (1.0/4.0)*F_inv61*U_i_dot51*U_i_inv61 + (1.0/2.0)*F_inv91*U_i_dot31*U_i_inv61 + (1.0/4.0)*F_inv91*U_i_dot51*U_i_inv41 + (1.0/2.0)*F_inv91*U_i_dot61*U_i_inv11;
		gradient(5,13) = (1.0/2.0)*F_inv31*U_i_dot11*U_i_inv41 + (1.0/2.0)*F_inv31*U_i_dot41*U_i_inv21 + (1.0/4.0)*F_inv31*U_i_dot61*U_i_inv51 + F_inv61*U_i_dot21*U_i_inv21 + (1.0/4.0)*F_inv61*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv61*U_i_dot51*U_i_inv51 + (1.0/2.0)*F_inv91*U_i_dot31*U_i_inv51 + (1.0/2.0)*F_inv91*U_i_dot51*U_i_inv21 + (1.0/4.0)*F_inv91*U_i_dot61*U_i_inv41;
		gradient(5,14) = (1.0/2.0)*F_inv31*U_i_dot11*U_i_inv61 + (1.0/4.0)*F_inv31*U_i_dot41*U_i_inv51 + (1.0/2.0)*F_inv31*U_i_dot61*U_i_inv31 + (1.0/2.0)*F_inv61*U_i_dot21*U_i_inv51 + (1.0/4.0)*F_inv61*U_i_dot41*U_i_inv61 + (1.0/2.0)*F_inv61*U_i_dot51*U_i_inv31 + F_inv91*U_i_dot31*U_i_inv31 + (1.0/4.0)*F_inv91*U_i_dot51*U_i_inv51 + (1.0/4.0)*F_inv91*U_i_dot61*U_i_inv61;
		gradient(5,15) = 0;
		gradient(5,16) = 0;
		gradient(5,17) = 0;
		gradient(5,18) = F_inv11*U_i_dot11*U_i_inv11 + (1.0/4.0)*F_inv11*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv11*U_i_dot61*U_i_inv61 + (1.0/2.0)*F_inv41*U_i_dot21*U_i_inv41 + (1.0/2.0)*F_inv41*U_i_dot41*U_i_inv11 + (1.0/4.0)*F_inv41*U_i_dot51*U_i_inv61 + (1.0/2.0)*F_inv71*U_i_dot31*U_i_inv61 + (1.0/4.0)*F_inv71*U_i_dot51*U_i_inv41 + (1.0/2.0)*F_inv71*U_i_dot61*U_i_inv11;
		gradient(5,19) = (1.0/2.0)*F_inv11*U_i_dot11*U_i_inv41 + (1.0/2.0)*F_inv11*U_i_dot41*U_i_inv21 + (1.0/4.0)*F_inv11*U_i_dot61*U_i_inv51 + F_inv41*U_i_dot21*U_i_inv21 + (1.0/4.0)*F_inv41*U_i_dot41*U_i_inv41 + (1.0/4.0)*F_inv41*U_i_dot51*U_i_inv51 + (1.0/2.0)*F_inv71*U_i_dot31*U_i_inv51 + (1.0/2.0)*F_inv71*U_i_dot51*U_i_inv21 + (1.0/4.0)*F_inv71*U_i_dot61*U_i_inv41;
		gradient(5,20) = (1.0/2.0)*F_inv11*U_i_dot11*U_i_inv61 + (1.0/4.0)*F_inv11*U_i_dot41*U_i_inv51 + (1.0/2.0)*F_inv11*U_i_dot61*U_i_inv31 + (1.0/2.0)*F_inv41*U_i_dot21*U_i_inv51 + (1.0/4.0)*F_inv41*U_i_dot41*U_i_inv61 + (1.0/2.0)*F_inv41*U_i_dot51*U_i_inv31 + F_inv71*U_i_dot31*U_i_inv31 + (1.0/4.0)*F_inv71*U_i_dot51*U_i_inv51 + (1.0/4.0)*F_inv71*U_i_dot61*U_i_inv61;
		gradient(5,21) = F71*U_i_dot11*U_i_inv11 + (1.0/4.0)*F71*U_i_dot41*U_i_inv41 + (1.0/4.0)*F71*U_i_dot61*U_i_inv61 + (1.0/2.0)*F81*U_i_dot11*U_i_inv41 + (1.0/2.0)*F81*U_i_dot41*U_i_inv21 + (1.0/4.0)*F81*U_i_dot61*U_i_inv51 + (1.0/2.0)*F91*U_i_dot11*U_i_inv61 + (1.0/4.0)*F91*U_i_dot41*U_i_inv51 + (1.0/2.0)*F91*U_i_dot61*U_i_inv31;
		gradient(5,22) = 0;
		gradient(5,23) = F11*U_i_dot11*U_i_inv11 + (1.0/4.0)*F11*U_i_dot41*U_i_inv41 + (1.0/4.0)*F11*U_i_dot61*U_i_inv61 + (1.0/2.0)*F21*U_i_dot11*U_i_inv41 + (1.0/2.0)*F21*U_i_dot41*U_i_inv21 + (1.0/4.0)*F21*U_i_dot61*U_i_inv51 + (1.0/2.0)*F31*U_i_dot11*U_i_inv61 + (1.0/4.0)*F31*U_i_dot41*U_i_inv51 + (1.0/2.0)*F31*U_i_dot61*U_i_inv31;
		gradient(5,24) = (1.0/2.0)*F71*U_i_dot21*U_i_inv41 + (1.0/2.0)*F71*U_i_dot41*U_i_inv11 + (1.0/4.0)*F71*U_i_dot51*U_i_inv61 + F81*U_i_dot21*U_i_inv21 + (1.0/4.0)*F81*U_i_dot41*U_i_inv41 + (1.0/4.0)*F81*U_i_dot51*U_i_inv51 + (1.0/2.0)*F91*U_i_dot21*U_i_inv51 + (1.0/4.0)*F91*U_i_dot41*U_i_inv61 + (1.0/2.0)*F91*U_i_dot51*U_i_inv31;
		gradient(5,25) = 0;
		gradient(5,26) = (1.0/2.0)*F11*U_i_dot21*U_i_inv41 + (1.0/2.0)*F11*U_i_dot41*U_i_inv11 + (1.0/4.0)*F11*U_i_dot51*U_i_inv61 + F21*U_i_dot21*U_i_inv21 + (1.0/4.0)*F21*U_i_dot41*U_i_inv41 + (1.0/4.0)*F21*U_i_dot51*U_i_inv51 + (1.0/2.0)*F31*U_i_dot21*U_i_inv51 + (1.0/4.0)*F31*U_i_dot41*U_i_inv61 + (1.0/2.0)*F31*U_i_dot51*U_i_inv31;
		gradient(5,27) = (1.0/2.0)*F71*U_i_dot31*U_i_inv61 + (1.0/4.0)*F71*U_i_dot51*U_i_inv41 + (1.0/2.0)*F71*U_i_dot61*U_i_inv11 + (1.0/2.0)*F81*U_i_dot31*U_i_inv51 + (1.0/2.0)*F81*U_i_dot51*U_i_inv21 + (1.0/4.0)*F81*U_i_dot61*U_i_inv41 + F91*U_i_dot31*U_i_inv31 + (1.0/4.0)*F91*U_i_dot51*U_i_inv51 + (1.0/4.0)*F91*U_i_dot61*U_i_inv61;
		gradient(5,28) = 0;
		gradient(5,29) = (1.0/2.0)*F11*U_i_dot31*U_i_inv61 + (1.0/4.0)*F11*U_i_dot51*U_i_inv41 + (1.0/2.0)*F11*U_i_dot61*U_i_inv11 + (1.0/2.0)*F21*U_i_dot31*U_i_inv51 + (1.0/2.0)*F21*U_i_dot51*U_i_inv21 + (1.0/4.0)*F21*U_i_dot61*U_i_inv41 + F31*U_i_dot31*U_i_inv31 + (1.0/4.0)*F31*U_i_dot51*U_i_inv51 + (1.0/4.0)*F31*U_i_dot61*U_i_inv61;
	}

	if(update_hessian)
	{
		const double v11 = get_v()[0];
		const double v21 = get_v()[1];
		const double v31 = get_v()[2];
		const double v41 = get_v()[3];
		const double v51 = get_v()[4];
		const double v61 = get_v()[5];

		hessian.resize(argument_set.size(), argument_set.size());

		hessian(0,0) = 0;
		hessian(0,1) = hessian(1,0) = 0;
		hessian(0,2) = hessian(2,0) = 0;
		hessian(0,3) = hessian(3,0) = 0;
		hessian(0,4) = hessian(4,0) = 0;
		hessian(0,5) = hessian(5,0) = 0;
		hessian(0,6) = hessian(6,0) = F11*F_inv11*v11 + F11*F_inv21*v41 + F11*F_inv31*v61 + F41*F_inv11*v41 + F41*F_inv21*v21 + F41*F_inv31*v51 +F71*F_inv11*v61 + F71*F_inv21*v51 + F71*F_inv31*v31;
		hessian(0,7) = hessian(7,0) = 0;
		hessian(0,8) = hessian(8,0) = 0;
		hessian(0,9) = hessian(9,0) = (1.0/2.0)*F21*F_inv11*v11 + (1.0/2.0)*F21*F_inv21*v41 + (1.0/2.0)*F21*F_inv31*v61 + (1.0/2.0)*F51*F_inv11*v41 + (1.0/2.0)*F51*F_inv21*v21 + (1.0/2.0)*F51*F_inv31*v51 + (1.0/2.0)*F81*F_inv11*v61 + (1.0/2.0)*F81*F_inv21*v51 + (1.0/2.0)*F81*F_inv31*v31;
		hessian(0,10) = hessian(10,0) = 0;
		hessian(0,11) = hessian(11,0) = (1.0/2.0)*F31*F_inv11*v11 + (1.0/2.0)*F31*F_inv21*v41 + (1.0/2.0)*F31*F_inv31*v61 + (1.0/2.0)*F61*F_inv11*v41 + (1.0/2.0)*F61*F_inv21*v21 + (1.0/2.0)*F61*F_inv31*v51 + (1.0/2.0)*F91*F_inv11*v61 + (1.0/2.0)*F91*F_inv21*v51 + (1.0/2.0)*F91*F_inv31*v31;
		hessian(0,12) = hessian(12,0) = U_i_inv11*(F_inv11*v11 + F_inv21*v41 + F_inv31*v61);
		hessian(0,13) = hessian(13,0) = (1.0/2.0)*U_i_inv41*(F_inv11*v11 + F_inv21*v41 + F_inv31*v61);
		hessian(0,14) = hessian(14,0) = (1.0/2.0)*U_i_inv61*(F_inv11*v11 + F_inv21*v41 + F_inv31*v61);
		hessian(0,15) = hessian(15,0) = U_i_inv11*(F_inv11*v41 + F_inv21*v21 + F_inv31*v51);
		hessian(0,16) = hessian(16,0) = (1.0/2.0)*U_i_inv41*(F_inv11*v41 + F_inv21*v21 + F_inv31*v51);
		hessian(0,17) = hessian(17,0) = (1.0/2.0)*U_i_inv61*(F_inv11*v41 + F_inv21*v21 + F_inv31*v51);
		hessian(0,18) = hessian(18,0) = U_i_inv11*(F_inv11*v61 + F_inv21*v51 + F_inv31*v31);
		hessian(0,19) = hessian(19,0) = (1.0/2.0)*U_i_inv41*(F_inv11*v61 + F_inv21*v51 + F_inv31*v31);
		hessian(0,20) = hessian(20,0) = (1.0/2.0)*U_i_inv61*(F_inv11*v61 + F_inv21*v51 + F_inv31*v31);
		hessian(0,21) = hessian(21,0) = F11*U_i_inv11*v11 + (1.0/2.0)*F21*U_i_inv41*v11 + (1.0/2.0)*F31*U_i_inv61*v11 + F41*U_i_inv11*v41 + (1.0/2.0)*F51*U_i_inv41*v41 + (1.0/2.0)*F61*U_i_inv61*v41 + F71*U_i_inv11*v61 + (1.0/2.0)*F81*U_i_inv41*v61 + (1.0/2.0)*F91*U_i_inv61*v61;
		hessian(0,22) = hessian(22,0) = F11*U_i_inv11*v41 + (1.0/2.0)*F21*U_i_inv41*v41 + (1.0/2.0)*F31*U_i_inv61*v41 + F41*U_i_inv11*v21 + (1.0/2.0)*F51*U_i_inv41*v21 + (1.0/2.0)*F61*U_i_inv61*v21 + F71*U_i_inv11*v51 + (1.0/2.0)*F81*U_i_inv41*v51 + (1.0/2.0)*F91*U_i_inv61*v51;
		hessian(0,23) = hessian(23,0) = F11*U_i_inv11*v61 + (1.0/2.0)*F21*U_i_inv41*v61 + (1.0/2.0)*F31*U_i_inv61*v61 + F41*U_i_inv11*v51 + (1.0/2.0)*F51*U_i_inv41*v51 + (1.0/2.0)*F61*U_i_inv61*v51 + F71*U_i_inv11*v31 + (1.0/2.0)*F81*U_i_inv41*v31 + (1.0/2.0)*F91*U_i_inv61*v31;
		hessian(0,24) = hessian(24,0) = 0;
		hessian(0,25) = hessian(25,0) = 0;
		hessian(0,26) = hessian(26,0) = 0;
		hessian(0,27) = hessian(27,0) = 0;
		hessian(0,28) = hessian(28,0) = 0;
		hessian(0,29) = hessian(29,0) = 0;
		hessian(1,1) = 0;
		hessian(1,2) = hessian(2,1) = 0;
		hessian(1,3) = hessian(3,1) = 0;
		hessian(1,4) = hessian(4,1) = 0;
		hessian(1,5) = hessian(5,1) = 0;
		hessian(1,6) = hessian(6,1) = 0;
		hessian(1,7) = hessian(7,1) = F21*F_inv41*v11 + F21*F_inv51*v41 + F21*F_inv61*v61 + F51*F_inv41*v41 + F51*F_inv51*v21 + F51*F_inv61*v51 +F81*F_inv41*v61 + F81*F_inv51*v51 + F81*F_inv61*v31;
		hessian(1,8) = hessian(8,1) = 0;
		hessian(1,9) = hessian(9,1) = (1.0/2.0)*F11*F_inv41*v11 + (1.0/2.0)*F11*F_inv51*v41 + (1.0/2.0)*F11*F_inv61*v61 + (1.0/2.0)*F41*F_inv41*v41 + (1.0/2.0)*F41*F_inv51*v21 + (1.0/2.0)*F41*F_inv61*v51 + (1.0/2.0)*F71*F_inv41*v61 + (1.0/2.0)*F71*F_inv51*v51 + (1.0/2.0)*F71*F_inv61*v31;
		hessian(1,10) = hessian(10,1) = (1.0/2.0)*F31*F_inv41*v11 + (1.0/2.0)*F31*F_inv51*v41 + (1.0/2.0)*F31*F_inv61*v61 + (1.0/2.0)*F61*F_inv41*v41 + (1.0/2.0)*F61*F_inv51*v21 + (1.0/2.0)*F61*F_inv61*v51 + (1.0/2.0)*F91*F_inv41*v61 + (1.0/2.0)*F91*F_inv51*v51 + (1.0/2.0)*F91*F_inv61*v31;
		hessian(1,11) = hessian(11,1) = 0;
		hessian(1,12) = hessian(12,1) = (1.0/2.0)*U_i_inv41*(F_inv41*v11 + F_inv51*v41 + F_inv61*v61);
		hessian(1,13) = hessian(13,1) = U_i_inv21*(F_inv41*v11 + F_inv51*v41 + F_inv61*v61);
		hessian(1,14) = hessian(14,1) = (1.0/2.0)*U_i_inv51*(F_inv41*v11 + F_inv51*v41 + F_inv61*v61);
		hessian(1,15) = hessian(15,1) = (1.0/2.0)*U_i_inv41*(F_inv41*v41 + F_inv51*v21 + F_inv61*v51);
		hessian(1,16) = hessian(16,1) = U_i_inv21*(F_inv41*v41 + F_inv51*v21 + F_inv61*v51);
		hessian(1,17) = hessian(17,1) = (1.0/2.0)*U_i_inv51*(F_inv41*v41 + F_inv51*v21 + F_inv61*v51);
		hessian(1,18) = hessian(18,1) = (1.0/2.0)*U_i_inv41*(F_inv41*v61 + F_inv51*v51 + F_inv61*v31);
		hessian(1,19) = hessian(19,1) = U_i_inv21*(F_inv41*v61 + F_inv51*v51 + F_inv61*v31);
		hessian(1,20) = hessian(20,1) = (1.0/2.0)*U_i_inv51*(F_inv41*v61 + F_inv51*v51 + F_inv61*v31);
		hessian(1,21) = hessian(21,1) = 0;
		hessian(1,22) = hessian(22,1) = 0;
		hessian(1,23) = hessian(23,1) = 0;
		hessian(1,24) = hessian(24,1) = (1.0/2.0)*F11*U_i_inv41*v11 + F21*U_i_inv21*v11 + (1.0/2.0)*F31*U_i_inv51*v11 + (1.0/2.0)*F41*U_i_inv41*v41 + F51*U_i_inv21*v41 + (1.0/2.0)*F61*U_i_inv51*v41 + (1.0/2.0)*F71*U_i_inv41*v61 + F81*U_i_inv21*v61 + (1.0/2.0)*F91*U_i_inv51*v61;
		hessian(1,25) = hessian(25,1) = (1.0/2.0)*F11*U_i_inv41*v41 + F21*U_i_inv21*v41 + (1.0/2.0)*F31*U_i_inv51*v41 + (1.0/2.0)*F41*U_i_inv41*v21 + F51*U_i_inv21*v21 + (1.0/2.0)*F61*U_i_inv51*v21 + (1.0/2.0)*F71*U_i_inv41*v51 + F81*U_i_inv21*v51 + (1.0/2.0)*F91*U_i_inv51*v51;
		hessian(1,26) = hessian(26,1) = (1.0/2.0)*F11*U_i_inv41*v61 + F21*U_i_inv21*v61 + (1.0/2.0)*F31*U_i_inv51*v61 + (1.0/2.0)*F41*U_i_inv41*v51 + F51*U_i_inv21*v51 + (1.0/2.0)*F61*U_i_inv51*v51 + (1.0/2.0)*F71*U_i_inv41*v31 + F81*U_i_inv21*v31 + (1.0/2.0)*F91*U_i_inv51*v31;
		hessian(1,27) = hessian(27,1) = 0;
		hessian(1,28) = hessian(28,1) = 0;
		hessian(1,29) = hessian(29,1) = 0;
		hessian(2,2) = 0;
		hessian(2,3) = hessian(3,2) = 0;
		hessian(2,4) = hessian(4,2) = 0;
		hessian(2,5) = hessian(5,2) = 0;
		hessian(2,6) = hessian(6,2) = 0;
		hessian(2,7) = hessian(7,2) = 0;
		hessian(2,8) = hessian(8,2) = F31*F_inv71*v11 + F31*F_inv81*v41 + F31*F_inv91*v61 + F61*F_inv71*v41 + F61*F_inv81*v21 + F61*F_inv91*v51 +F91*F_inv71*v61 + F91*F_inv81*v51 + F91*F_inv91*v31;
		hessian(2,9) = hessian(9,2) = 0;
		hessian(2,10) = hessian(10,2) = (1.0/2.0)*F21*F_inv71*v11 + (1.0/2.0)*F21*F_inv81*v41 + (1.0/2.0)*F21*F_inv91*v61 + (1.0/2.0)*F51*F_inv71*v41 + (1.0/2.0)*F51*F_inv81*v21 + (1.0/2.0)*F51*F_inv91*v51 + (1.0/2.0)*F81*F_inv71*v61 + (1.0/2.0)*F81*F_inv81*v51 + (1.0/2.0)*F81*F_inv91*v31;
		hessian(2,11) = hessian(11,2) = (1.0/2.0)*F11*F_inv71*v11 + (1.0/2.0)*F11*F_inv81*v41 + (1.0/2.0)*F11*F_inv91*v61 + (1.0/2.0)*F41*F_inv71*v41 + (1.0/2.0)*F41*F_inv81*v21 + (1.0/2.0)*F41*F_inv91*v51 + (1.0/2.0)*F71*F_inv71*v61 + (1.0/2.0)*F71*F_inv81*v51 + (1.0/2.0)*F71*F_inv91*v31;
		hessian(2,12) = hessian(12,2) = (1.0/2.0)*U_i_inv61*(F_inv71*v11 + F_inv81*v41 + F_inv91*v61);
		hessian(2,13) = hessian(13,2) = (1.0/2.0)*U_i_inv51*(F_inv71*v11 + F_inv81*v41 + F_inv91*v61);
		hessian(2,14) = hessian(14,2) = U_i_inv31*(F_inv71*v11 + F_inv81*v41 + F_inv91*v61);
		hessian(2,15) = hessian(15,2) = (1.0/2.0)*U_i_inv61*(F_inv71*v41 + F_inv81*v21 + F_inv91*v51);
		hessian(2,16) = hessian(16,2) = (1.0/2.0)*U_i_inv51*(F_inv71*v41 + F_inv81*v21 + F_inv91*v51);
		hessian(2,17) = hessian(17,2) = U_i_inv31*(F_inv71*v41 + F_inv81*v21 + F_inv91*v51);
		hessian(2,18) = hessian(18,2) = (1.0/2.0)*U_i_inv61*(F_inv71*v61 + F_inv81*v51 + F_inv91*v31);
		hessian(2,19) = hessian(19,2) = (1.0/2.0)*U_i_inv51*(F_inv71*v61 + F_inv81*v51 + F_inv91*v31);
		hessian(2,20) = hessian(20,2) = U_i_inv31*(F_inv71*v61 + F_inv81*v51 + F_inv91*v31);
		hessian(2,21) = hessian(21,2) = 0;
		hessian(2,22) = hessian(22,2) = 0;
		hessian(2,23) = hessian(23,2) = 0;
		hessian(2,24) = hessian(24,2) = 0;
		hessian(2,25) = hessian(25,2) = 0;
		hessian(2,26) = hessian(26,2) = 0;
		hessian(2,27) = hessian(27,2) = (1.0/2.0)*F11*U_i_inv61*v11 + (1.0/2.0)*F21*U_i_inv51*v11 + F31*U_i_inv31*v11 + (1.0/2.0)*F41*U_i_inv61*v41 + (1.0/2.0)*F51*U_i_inv51*v41 + F61*U_i_inv31*v41 + (1.0/2.0)*F71*U_i_inv61*v61 + (1.0/2.0)*F81*U_i_inv51*v61 + F91*U_i_inv31*v61;
		hessian(2,28) = hessian(28,2) = (1.0/2.0)*F11*U_i_inv61*v41 + (1.0/2.0)*F21*U_i_inv51*v41 + F31*U_i_inv31*v41 + (1.0/2.0)*F41*U_i_inv61*v21 + (1.0/2.0)*F51*U_i_inv51*v21 + F61*U_i_inv31*v21 + (1.0/2.0)*F71*U_i_inv61*v51 + (1.0/2.0)*F81*U_i_inv51*v51 + F91*U_i_inv31*v51;
		hessian(2,29) = hessian(29,2) = (1.0/2.0)*F11*U_i_inv61*v61 + (1.0/2.0)*F21*U_i_inv51*v61 + F31*U_i_inv31*v61 + (1.0/2.0)*F41*U_i_inv61*v51 + (1.0/2.0)*F51*U_i_inv51*v51 + F61*U_i_inv31*v51 + (1.0/2.0)*F71*U_i_inv61*v31 + (1.0/2.0)*F81*U_i_inv51*v31 + F91*U_i_inv31*v31;
		hessian(3,3) = 0;
		hessian(3,4) = hessian(4,3) = 0;
		hessian(3,5) = hessian(5,3) = 0;
		hessian(3,6) = hessian(6,3) = (1.0/2.0)*F11*F_inv41*v11 + (1.0/2.0)*F11*F_inv51*v41 + (1.0/2.0)*F11*F_inv61*v61 + (1.0/2.0)*F41*F_inv41*v41 + (1.0/2.0)*F41*F_inv51*v21 + (1.0/2.0)*F41*F_inv61*v51 + (1.0/2.0)*F71*F_inv41*v61 + (1.0/2.0)*F71*F_inv51*v51 + (1.0/2.0)*F71*F_inv61*v31;
		hessian(3,7) = hessian(7,3) = (1.0/2.0)*F21*F_inv11*v11 + (1.0/2.0)*F21*F_inv21*v41 + (1.0/2.0)*F21*F_inv31*v61 + (1.0/2.0)*F51*F_inv11*v41 + (1.0/2.0)*F51*F_inv21*v21 + (1.0/2.0)*F51*F_inv31*v51 + (1.0/2.0)*F81*F_inv11*v61 + (1.0/2.0)*F81*F_inv21*v51 + (1.0/2.0)*F81*F_inv31*v31;
		hessian(3,8) = hessian(8,3) = 0;
		hessian(3,9) = hessian(9,3) = (1.0/4.0)*F11*F_inv11*v11 + (1.0/4.0)*F11*F_inv21*v41 + (1.0/4.0)*F11*F_inv31*v61 + (1.0/4.0)*F21*F_inv41*v11 + (1.0/4.0)*F21*F_inv51*v41 + (1.0/4.0)*F21*F_inv61*v61 + (1.0/4.0)*F41*F_inv11*v41 + (1.0/4.0)*F41*F_inv21*v21 + (1.0/4.0)*F41*F_inv31*v51 + (1.0/4.0)*F51*F_inv41*v41 + (1.0/4.0)*F51*F_inv51*v21 + (1.0/4.0)*F51*F_inv61*v51 + (1.0/4.0)*F71*F_inv11*v61 + (1.0/4.0)*F71*F_inv21*v51 + (1.0/4.0)*F71*F_inv31*v31 + (1.0/4.0)*F81*F_inv41*v61 + (1.0/4.0)*F81*F_inv51*v51 + (1.0/4.0)*F81*F_inv61*v31;
		hessian(3,10) = hessian(10,3) = (1.0/4.0)*F31*F_inv11*v11 + (1.0/4.0)*F31*F_inv21*v41 + (1.0/4.0)*F31*F_inv31*v61 + (1.0/4.0)*F61*F_inv11*v41 + (1.0/4.0)*F61*F_inv21*v21 + (1.0/4.0)*F61*F_inv31*v51 + (1.0/4.0)*F91*F_inv11*v61 + (1.0/4.0)*F91*F_inv21*v51 + (1.0/4.0)*F91*F_inv31*v31;
		hessian(3,11) = hessian(11,3) = (1.0/4.0)*F31*F_inv41*v11 + (1.0/4.0)*F31*F_inv51*v41 + (1.0/4.0)*F31*F_inv61*v61 + (1.0/4.0)*F61*F_inv41*v41 + (1.0/4.0)*F61*F_inv51*v21 + (1.0/4.0)*F61*F_inv61*v51 + (1.0/4.0)*F91*F_inv41*v61 + (1.0/4.0)*F91*F_inv51*v51 + (1.0/4.0)*F91*F_inv61*v31;
		hessian(3,12) = hessian(12,3) = (1.0/4.0)*F_inv11*U_i_inv41*v11 + (1.0/4.0)*F_inv21*U_i_inv41*v41 + (1.0/4.0)*F_inv31*U_i_inv41*v61 + (1.0/2.0)*F_inv41*U_i_inv11*v11 + (1.0/2.0)*F_inv51*U_i_inv11*v41 + (1.0/2.0)*F_inv61*U_i_inv11*v61;
		hessian(3,13) = hessian(13,3) = (1.0/2.0)*F_inv11*U_i_inv21*v11 + (1.0/2.0)*F_inv21*U_i_inv21*v41 + (1.0/2.0)*F_inv31*U_i_inv21*v61 + (1.0/4.0)*F_inv41*U_i_inv41*v11 + (1.0/4.0)*F_inv51*U_i_inv41*v41 + (1.0/4.0)*F_inv61*U_i_inv41*v61;
		hessian(3,14) = hessian(14,3) = (1.0/4.0)*F_inv11*U_i_inv51*v11 + (1.0/4.0)*F_inv21*U_i_inv51*v41 + (1.0/4.0)*F_inv31*U_i_inv51*v61 + (1.0/4.0)*F_inv41*U_i_inv61*v11 + (1.0/4.0)*F_inv51*U_i_inv61*v41 + (1.0/4.0)*F_inv61*U_i_inv61*v61;
		hessian(3,15) = hessian(15,3) = (1.0/4.0)*F_inv11*U_i_inv41*v41 + (1.0/4.0)*F_inv21*U_i_inv41*v21 + (1.0/4.0)*F_inv31*U_i_inv41*v51 + (1.0/2.0)*F_inv41*U_i_inv11*v41 + (1.0/2.0)*F_inv51*U_i_inv11*v21 + (1.0/2.0)*F_inv61*U_i_inv11*v51;
		hessian(3,16) = hessian(16,3) = (1.0/2.0)*F_inv11*U_i_inv21*v41 + (1.0/2.0)*F_inv21*U_i_inv21*v21 + (1.0/2.0)*F_inv31*U_i_inv21*v51 + (1.0/4.0)*F_inv41*U_i_inv41*v41 + (1.0/4.0)*F_inv51*U_i_inv41*v21 + (1.0/4.0)*F_inv61*U_i_inv41*v51;
		hessian(3,17) = hessian(17,3) = (1.0/4.0)*F_inv11*U_i_inv51*v41 + (1.0/4.0)*F_inv21*U_i_inv51*v21 + (1.0/4.0)*F_inv31*U_i_inv51*v51 + (1.0/4.0)*F_inv41*U_i_inv61*v41 + (1.0/4.0)*F_inv51*U_i_inv61*v21 + (1.0/4.0)*F_inv61*U_i_inv61*v51;
		hessian(3,18) = hessian(18,3) = (1.0/4.0)*F_inv11*U_i_inv41*v61 + (1.0/4.0)*F_inv21*U_i_inv41*v51 + (1.0/4.0)*F_inv31*U_i_inv41*v31 + (1.0/2.0)*F_inv41*U_i_inv11*v61 + (1.0/2.0)*F_inv51*U_i_inv11*v51 + (1.0/2.0)*F_inv61*U_i_inv11*v31;
		hessian(3,19) = hessian(19,3) = (1.0/2.0)*F_inv11*U_i_inv21*v61 + (1.0/2.0)*F_inv21*U_i_inv21*v51 + (1.0/2.0)*F_inv31*U_i_inv21*v31 + (1.0/4.0)*F_inv41*U_i_inv41*v61 + (1.0/4.0)*F_inv51*U_i_inv41*v51 + (1.0/4.0)*F_inv61*U_i_inv41*v31;
		hessian(3,20) = hessian(20,3) = (1.0/4.0)*F_inv11*U_i_inv51*v61 + (1.0/4.0)*F_inv21*U_i_inv51*v51 + (1.0/4.0)*F_inv31*U_i_inv51*v31 + (1.0/4.0)*F_inv41*U_i_inv61*v61 + (1.0/4.0)*F_inv51*U_i_inv61*v51 + (1.0/4.0)*F_inv61*U_i_inv61*v31;
		hessian(3,21) = hessian(21,3) = (1.0/4.0)*F11*U_i_inv41*v11 + (1.0/2.0)*F21*U_i_inv21*v11 + (1.0/4.0)*F31*U_i_inv51*v11 + (1.0/4.0)*F41*U_i_inv41*v41 + (1.0/2.0)*F51*U_i_inv21*v41 + (1.0/4.0)*F61*U_i_inv51*v41 + (1.0/4.0)*F71*U_i_inv41*v61 + (1.0/2.0)*F81*U_i_inv21*v61 + (1.0/4.0)*F91*U_i_inv51*v61;
		hessian(3,22) = hessian(22,3) = (1.0/4.0)*F11*U_i_inv41*v41 + (1.0/2.0)*F21*U_i_inv21*v41 + (1.0/4.0)*F31*U_i_inv51*v41 + (1.0/4.0)*F41*U_i_inv41*v21 + (1.0/2.0)*F51*U_i_inv21*v21 + (1.0/4.0)*F61*U_i_inv51*v21 + (1.0/4.0)*F71*U_i_inv41*v51 + (1.0/2.0)*F81*U_i_inv21*v51 + (1.0/4.0)*F91*U_i_inv51*v51;
		hessian(3,23) = hessian(23,3) = (1.0/4.0)*F11*U_i_inv41*v61 + (1.0/2.0)*F21*U_i_inv21*v61 + (1.0/4.0)*F31*U_i_inv51*v61 + (1.0/4.0)*F41*U_i_inv41*v51 + (1.0/2.0)*F51*U_i_inv21*v51 + (1.0/4.0)*F61*U_i_inv51*v51 + (1.0/4.0)*F71*U_i_inv41*v31 + (1.0/2.0)*F81*U_i_inv21*v31 + (1.0/4.0)*F91*U_i_inv51*v31;
		hessian(3,24) = hessian(24,3) = (1.0/2.0)*F11*U_i_inv11*v11 + (1.0/4.0)*F21*U_i_inv41*v11 + (1.0/4.0)*F31*U_i_inv61*v11 + (1.0/2.0)*F41*U_i_inv11*v41 + (1.0/4.0)*F51*U_i_inv41*v41 + (1.0/4.0)*F61*U_i_inv61*v41 + (1.0/2.0)*F71*U_i_inv11*v61 + (1.0/4.0)*F81*U_i_inv41*v61 + (1.0/4.0)*F91*U_i_inv61*v61;
		hessian(3,25) = hessian(25,3) = (1.0/2.0)*F11*U_i_inv11*v41 + (1.0/4.0)*F21*U_i_inv41*v41 + (1.0/4.0)*F31*U_i_inv61*v41 + (1.0/2.0)*F41*U_i_inv11*v21 + (1.0/4.0)*F51*U_i_inv41*v21 + (1.0/4.0)*F61*U_i_inv61*v21 + (1.0/2.0)*F71*U_i_inv11*v51 + (1.0/4.0)*F81*U_i_inv41*v51 + (1.0/4.0)*F91*U_i_inv61*v51;
		hessian(3,26) = hessian(26,3) = (1.0/2.0)*F11*U_i_inv11*v61 + (1.0/4.0)*F21*U_i_inv41*v61 + (1.0/4.0)*F31*U_i_inv61*v61 + (1.0/2.0)*F41*U_i_inv11*v51 + (1.0/4.0)*F51*U_i_inv41*v51 + (1.0/4.0)*F61*U_i_inv61*v51 + (1.0/2.0)*F71*U_i_inv11*v31 + (1.0/4.0)*F81*U_i_inv41*v31 + (1.0/4.0)*F91*U_i_inv61*v31;
		hessian(3,27) = hessian(27,3) = 0;
		hessian(3,28) = hessian(28,3) = 0;
		hessian(3,29) = hessian(29,3) = 0;
		hessian(4,4) = 0;
		hessian(4,5) = hessian(5,4) = 0;
		hessian(4,6) = hessian(6,4) = 0;
		hessian(4,7) = hessian(7,4) = (1.0/2.0)*F21*F_inv71*v11 + (1.0/2.0)*F21*F_inv81*v41 + (1.0/2.0)*F21*F_inv91*v61 + (1.0/2.0)*F51*F_inv71*v41 + (1.0/2.0)*F51*F_inv81*v21 + (1.0/2.0)*F51*F_inv91*v51 + (1.0/2.0)*F81*F_inv71*v61 + (1.0/2.0)*F81*F_inv81*v51 + (1.0/2.0)*F81*F_inv91*v31;
		hessian(4,8) = hessian(8,4) = (1.0/2.0)*F31*F_inv41*v11 + (1.0/2.0)*F31*F_inv51*v41 + (1.0/2.0)*F31*F_inv61*v61 + (1.0/2.0)*F61*F_inv41*v41 + (1.0/2.0)*F61*F_inv51*v21 + (1.0/2.0)*F61*F_inv61*v51 + (1.0/2.0)*F91*F_inv41*v61 + (1.0/2.0)*F91*F_inv51*v51 + (1.0/2.0)*F91*F_inv61*v31;
		hessian(4,9) = hessian(9,4) = (1.0/4.0)*F11*F_inv71*v11 + (1.0/4.0)*F11*F_inv81*v41 + (1.0/4.0)*F11*F_inv91*v61 + (1.0/4.0)*F41*F_inv71*v41 + (1.0/4.0)*F41*F_inv81*v21 + (1.0/4.0)*F41*F_inv91*v51 + (1.0/4.0)*F71*F_inv71*v61 + (1.0/4.0)*F71*F_inv81*v51 + (1.0/4.0)*F71*F_inv91*v31;
		hessian(4,10) = hessian(10,4) = (1.0/4.0)*F21*F_inv41*v11 + (1.0/4.0)*F21*F_inv51*v41 + (1.0/4.0)*F21*F_inv61*v61 + (1.0/4.0)*F31*F_inv71*v11 + (1.0/4.0)*F31*F_inv81*v41 + (1.0/4.0)*F31*F_inv91*v61 + (1.0/4.0)*F51*F_inv41*v41 + (1.0/4.0)*F51*F_inv51*v21 + (1.0/4.0)*F51*F_inv61*v51 + (1.0/4.0)*F61*F_inv71*v41 + (1.0/4.0)*F61*F_inv81*v21 + (1.0/4.0)*F61*F_inv91*v51 + (1.0/4.0)*F81*F_inv41*v61 + (1.0/4.0)*F81*F_inv51*v51 + (1.0/4.0)*F81*F_inv61*v31 + (1.0/4.0)*F91*F_inv71*v61 + (1.0/4.0)*F91*F_inv81*v51 + (1.0/4.0)*F91*F_inv91*v31;
		hessian(4,11) = hessian(11,4) = (1.0/4.0)*F11*F_inv41*v11 + (1.0/4.0)*F11*F_inv51*v41 + (1.0/4.0)*F11*F_inv61*v61 + (1.0/4.0)*F41*F_inv41*v41 + (1.0/4.0)*F41*F_inv51*v21 + (1.0/4.0)*F41*F_inv61*v51 + (1.0/4.0)*F71*F_inv41*v61 + (1.0/4.0)*F71*F_inv51*v51 + (1.0/4.0)*F71*F_inv61*v31;
		hessian(4,12) = hessian(12,4) = (1.0/4.0)*F_inv41*U_i_inv61*v11 + (1.0/4.0)*F_inv51*U_i_inv61*v41 + (1.0/4.0)*F_inv61*U_i_inv61*v61 + (1.0/4.0)*F_inv71*U_i_inv41*v11 + (1.0/4.0)*F_inv81*U_i_inv41*v41 + (1.0/4.0)*F_inv91*U_i_inv41*v61;
		hessian(4,13) = hessian(13,4) = (1.0/4.0)*F_inv41*U_i_inv51*v11 + (1.0/4.0)*F_inv51*U_i_inv51*v41 + (1.0/4.0)*F_inv61*U_i_inv51*v61 + (1.0/2.0)*F_inv71*U_i_inv21*v11 + (1.0/2.0)*F_inv81*U_i_inv21*v41 + (1.0/2.0)*F_inv91*U_i_inv21*v61;
		hessian(4,14) = hessian(14,4) = (1.0/2.0)*F_inv41*U_i_inv31*v11 + (1.0/2.0)*F_inv51*U_i_inv31*v41 + (1.0/2.0)*F_inv61*U_i_inv31*v61 + (1.0/4.0)*F_inv71*U_i_inv51*v11 + (1.0/4.0)*F_inv81*U_i_inv51*v41 + (1.0/4.0)*F_inv91*U_i_inv51*v61;
		hessian(4,15) = hessian(15,4) = (1.0/4.0)*F_inv41*U_i_inv61*v41 + (1.0/4.0)*F_inv51*U_i_inv61*v21 + (1.0/4.0)*F_inv61*U_i_inv61*v51 + (1.0/4.0)*F_inv71*U_i_inv41*v41 + (1.0/4.0)*F_inv81*U_i_inv41*v21 + (1.0/4.0)*F_inv91*U_i_inv41*v51;
		hessian(4,16) = hessian(16,4) = (1.0/4.0)*F_inv41*U_i_inv51*v41 + (1.0/4.0)*F_inv51*U_i_inv51*v21 + (1.0/4.0)*F_inv61*U_i_inv51*v51 + (1.0/2.0)*F_inv71*U_i_inv21*v41 + (1.0/2.0)*F_inv81*U_i_inv21*v21 + (1.0/2.0)*F_inv91*U_i_inv21*v51;
		hessian(4,17) = hessian(17,4) = (1.0/2.0)*F_inv41*U_i_inv31*v41 + (1.0/2.0)*F_inv51*U_i_inv31*v21 + (1.0/2.0)*F_inv61*U_i_inv31*v51 + (1.0/4.0)*F_inv71*U_i_inv51*v41 + (1.0/4.0)*F_inv81*U_i_inv51*v21 + (1.0/4.0)*F_inv91*U_i_inv51*v51;
		hessian(4,18) = hessian(18,4) = (1.0/4.0)*F_inv41*U_i_inv61*v61 + (1.0/4.0)*F_inv51*U_i_inv61*v51 + (1.0/4.0)*F_inv61*U_i_inv61*v31 + (1.0/4.0)*F_inv71*U_i_inv41*v61 + (1.0/4.0)*F_inv81*U_i_inv41*v51 + (1.0/4.0)*F_inv91*U_i_inv41*v31;
		hessian(4,19) = hessian(19,4) = (1.0/4.0)*F_inv41*U_i_inv51*v61 + (1.0/4.0)*F_inv51*U_i_inv51*v51 + (1.0/4.0)*F_inv61*U_i_inv51*v31 + (1.0/2.0)*F_inv71*U_i_inv21*v61 + (1.0/2.0)*F_inv81*U_i_inv21*v51 + (1.0/2.0)*F_inv91*U_i_inv21*v31;
		hessian(4,20) = hessian(20,4) = (1.0/2.0)*F_inv41*U_i_inv31*v61 + (1.0/2.0)*F_inv51*U_i_inv31*v51 + (1.0/2.0)*F_inv61*U_i_inv31*v31 + (1.0/4.0)*F_inv71*U_i_inv51*v61 + (1.0/4.0)*F_inv81*U_i_inv51*v51 + (1.0/4.0)*F_inv91*U_i_inv51*v31;
		hessian(4,21) = hessian(21,4) = 0;
		hessian(4,22) = hessian(22,4) = 0;
		hessian(4,23) = hessian(23,4) = 0;
		hessian(4,24) = hessian(24,4) = (1.0/4.0)*F11*U_i_inv61*v11 + (1.0/4.0)*F21*U_i_inv51*v11 + (1.0/2.0)*F31*U_i_inv31*v11 + (1.0/4.0)*F41*U_i_inv61*v41 + (1.0/4.0)*F51*U_i_inv51*v41 + (1.0/2.0)*F61*U_i_inv31*v41 + (1.0/4.0)*F71*U_i_inv61*v61 + (1.0/4.0)*F81*U_i_inv51*v61 + (1.0/2.0)*F91*U_i_inv31*v61;
		hessian(4,25) = hessian(25,4) = (1.0/4.0)*F11*U_i_inv61*v41 + (1.0/4.0)*F21*U_i_inv51*v41 + (1.0/2.0)*F31*U_i_inv31*v41 + (1.0/4.0)*F41*U_i_inv61*v21 + (1.0/4.0)*F51*U_i_inv51*v21 + (1.0/2.0)*F61*U_i_inv31*v21 + (1.0/4.0)*F71*U_i_inv61*v51 + (1.0/4.0)*F81*U_i_inv51*v51 + (1.0/2.0)*F91*U_i_inv31*v51;
		hessian(4,26) = hessian(26,4) = (1.0/4.0)*F11*U_i_inv61*v61 + (1.0/4.0)*F21*U_i_inv51*v61 + (1.0/2.0)*F31*U_i_inv31*v61 + (1.0/4.0)*F41*U_i_inv61*v51 + (1.0/4.0)*F51*U_i_inv51*v51 + (1.0/2.0)*F61*U_i_inv31*v51 + (1.0/4.0)*F71*U_i_inv61*v31 + (1.0/4.0)*F81*U_i_inv51*v31 + (1.0/2.0)*F91*U_i_inv31*v31;
		hessian(4,27) = hessian(27,4) = (1.0/4.0)*F11*U_i_inv41*v11 + (1.0/2.0)*F21*U_i_inv21*v11 + (1.0/4.0)*F31*U_i_inv51*v11 + (1.0/4.0)*F41*U_i_inv41*v41 + (1.0/2.0)*F51*U_i_inv21*v41 + (1.0/4.0)*F61*U_i_inv51*v41 + (1.0/4.0)*F71*U_i_inv41*v61 + (1.0/2.0)*F81*U_i_inv21*v61 + (1.0/4.0)*F91*U_i_inv51*v61;
		hessian(4,28) = hessian(28,4) = (1.0/4.0)*F11*U_i_inv41*v41 + (1.0/2.0)*F21*U_i_inv21*v41 + (1.0/4.0)*F31*U_i_inv51*v41 + (1.0/4.0)*F41*U_i_inv41*v21 + (1.0/2.0)*F51*U_i_inv21*v21 + (1.0/4.0)*F61*U_i_inv51*v21 + (1.0/4.0)*F71*U_i_inv41*v51 + (1.0/2.0)*F81*U_i_inv21*v51 + (1.0/4.0)*F91*U_i_inv51*v51;
		hessian(4,29) = hessian(29,4) = (1.0/4.0)*F11*U_i_inv41*v61 + (1.0/2.0)*F21*U_i_inv21*v61 + (1.0/4.0)*F31*U_i_inv51*v61 + (1.0/4.0)*F41*U_i_inv41*v51 + (1.0/2.0)*F51*U_i_inv21*v51 + (1.0/4.0)*F61*U_i_inv51*v51 + (1.0/4.0)*F71*U_i_inv41*v31 + (1.0/2.0)*F81*U_i_inv21*v31 + (1.0/4.0)*F91*U_i_inv51*v31;
		hessian(5,5) = 0;
		hessian(5,6) = hessian(6,5) = (1.0/2.0)*F11*F_inv71*v11 + (1.0/2.0)*F11*F_inv81*v41 + (1.0/2.0)*F11*F_inv91*v61 + (1.0/2.0)*F41*F_inv71*v41 + (1.0/2.0)*F41*F_inv81*v21 + (1.0/2.0)*F41*F_inv91*v51 + (1.0/2.0)*F71*F_inv71*v61 + (1.0/2.0)*F71*F_inv81*v51 + (1.0/2.0)*F71*F_inv91*v31;
		hessian(5,7) = hessian(7,5) = 0;
		hessian(5,8) = hessian(8,5) = (1.0/2.0)*F31*F_inv11*v11 + (1.0/2.0)*F31*F_inv21*v41 + (1.0/2.0)*F31*F_inv31*v61 + (1.0/2.0)*F61*F_inv11*v41 + (1.0/2.0)*F61*F_inv21*v21 + (1.0/2.0)*F61*F_inv31*v51 + (1.0/2.0)*F91*F_inv11*v61 + (1.0/2.0)*F91*F_inv21*v51 + (1.0/2.0)*F91*F_inv31*v31;
		hessian(5,9) = hessian(9,5) = (1.0/4.0)*F21*F_inv71*v11 + (1.0/4.0)*F21*F_inv81*v41 + (1.0/4.0)*F21*F_inv91*v61 + (1.0/4.0)*F51*F_inv71*v41 + (1.0/4.0)*F51*F_inv81*v21 + (1.0/4.0)*F51*F_inv91*v51 + (1.0/4.0)*F81*F_inv71*v61 + (1.0/4.0)*F81*F_inv81*v51 + (1.0/4.0)*F81*F_inv91*v31;
		hessian(5,10) = hessian(10,5) = (1.0/4.0)*F21*F_inv11*v11 + (1.0/4.0)*F21*F_inv21*v41 + (1.0/4.0)*F21*F_inv31*v61 + (1.0/4.0)*F51*F_inv11*v41 + (1.0/4.0)*F51*F_inv21*v21 + (1.0/4.0)*F51*F_inv31*v51 + (1.0/4.0)*F81*F_inv11*v61 + (1.0/4.0)*F81*F_inv21*v51 + (1.0/4.0)*F81*F_inv31*v31;
		hessian(5,11) = hessian(11,5) = (1.0/4.0)*F11*F_inv11*v11 + (1.0/4.0)*F11*F_inv21*v41 + (1.0/4.0)*F11*F_inv31*v61 + (1.0/4.0)*F31*F_inv71*v11 + (1.0/4.0)*F31*F_inv81*v41 + (1.0/4.0)*F31*F_inv91*v61 + (1.0/4.0)*F41*F_inv11*v41 + (1.0/4.0)*F41*F_inv21*v21 + (1.0/4.0)*F41*F_inv31*v51 + (1.0/4.0)*F61*F_inv71*v41 + (1.0/4.0)*F61*F_inv81*v21 + (1.0/4.0)*F61*F_inv91*v51 + (1.0/4.0)*F71*F_inv11*v61 + (1.0/4.0)*F71*F_inv21*v51 + (1.0/4.0)*F71*F_inv31*v31 + (1.0/4.0)*F91*F_inv71*v61 + (1.0/4.0)*F91*F_inv81*v51 + (1.0/4.0)*F91*F_inv91*v31;
		hessian(5,12) = hessian(12,5) = (1.0/4.0)*F_inv11*U_i_inv61*v11 + (1.0/4.0)*F_inv21*U_i_inv61*v41 + (1.0/4.0)*F_inv31*U_i_inv61*v61 + (1.0/2.0)*F_inv71*U_i_inv11*v11 + (1.0/2.0)*F_inv81*U_i_inv11*v41 + (1.0/2.0)*F_inv91*U_i_inv11*v61;
		hessian(5,13) = hessian(13,5) = (1.0/4.0)*F_inv11*U_i_inv51*v11 + (1.0/4.0)*F_inv21*U_i_inv51*v41 + (1.0/4.0)*F_inv31*U_i_inv51*v61 + (1.0/4.0)*F_inv71*U_i_inv41*v11 + (1.0/4.0)*F_inv81*U_i_inv41*v41 + (1.0/4.0)*F_inv91*U_i_inv41*v61;
		hessian(5,14) = hessian(14,5) = (1.0/2.0)*F_inv11*U_i_inv31*v11 + (1.0/2.0)*F_inv21*U_i_inv31*v41 + (1.0/2.0)*F_inv31*U_i_inv31*v61 + (1.0/4.0)*F_inv71*U_i_inv61*v11 + (1.0/4.0)*F_inv81*U_i_inv61*v41 + (1.0/4.0)*F_inv91*U_i_inv61*v61;
		hessian(5,15) = hessian(15,5) = (1.0/4.0)*F_inv11*U_i_inv61*v41 + (1.0/4.0)*F_inv21*U_i_inv61*v21 + (1.0/4.0)*F_inv31*U_i_inv61*v51 + (1.0/2.0)*F_inv71*U_i_inv11*v41 + (1.0/2.0)*F_inv81*U_i_inv11*v21 + (1.0/2.0)*F_inv91*U_i_inv11*v51;
		hessian(5,16) = hessian(16,5) = (1.0/4.0)*F_inv11*U_i_inv51*v41 + (1.0/4.0)*F_inv21*U_i_inv51*v21 + (1.0/4.0)*F_inv31*U_i_inv51*v51 + (1.0/4.0)*F_inv71*U_i_inv41*v41 + (1.0/4.0)*F_inv81*U_i_inv41*v21 + (1.0/4.0)*F_inv91*U_i_inv41*v51;
		hessian(5,17) = hessian(17,5) = (1.0/2.0)*F_inv11*U_i_inv31*v41 + (1.0/2.0)*F_inv21*U_i_inv31*v21 + (1.0/2.0)*F_inv31*U_i_inv31*v51 + (1.0/4.0)*F_inv71*U_i_inv61*v41 + (1.0/4.0)*F_inv81*U_i_inv61*v21 + (1.0/4.0)*F_inv91*U_i_inv61*v51;
		hessian(5,18) = hessian(18,5) = (1.0/4.0)*F_inv11*U_i_inv61*v61 + (1.0/4.0)*F_inv21*U_i_inv61*v51 + (1.0/4.0)*F_inv31*U_i_inv61*v31 + (1.0/2.0)*F_inv71*U_i_inv11*v61 + (1.0/2.0)*F_inv81*U_i_inv11*v51 + (1.0/2.0)*F_inv91*U_i_inv11*v31;
		hessian(5,19) = hessian(19,5) = (1.0/4.0)*F_inv11*U_i_inv51*v61 + (1.0/4.0)*F_inv21*U_i_inv51*v51 + (1.0/4.0)*F_inv31*U_i_inv51*v31 + (1.0/4.0)*F_inv71*U_i_inv41*v61 + (1.0/4.0)*F_inv81*U_i_inv41*v51 + (1.0/4.0)*F_inv91*U_i_inv41*v31;
		hessian(5,20) = hessian(20,5) = (1.0/2.0)*F_inv11*U_i_inv31*v61 + (1.0/2.0)*F_inv21*U_i_inv31*v51 + (1.0/2.0)*F_inv31*U_i_inv31*v31 + (1.0/4.0)*F_inv71*U_i_inv61*v61 + (1.0/4.0)*F_inv81*U_i_inv61*v51 + (1.0/4.0)*F_inv91*U_i_inv61*v31;
		hessian(5,21) = hessian(21,5) = (1.0/4.0)*F11*U_i_inv61*v11 + (1.0/4.0)*F21*U_i_inv51*v11 + (1.0/2.0)*F31*U_i_inv31*v11 + (1.0/4.0)*F41*U_i_inv61*v41 + (1.0/4.0)*F51*U_i_inv51*v41 + (1.0/2.0)*F61*U_i_inv31*v41 + (1.0/4.0)*F71*U_i_inv61*v61 + (1.0/4.0)*F81*U_i_inv51*v61 + (1.0/2.0)*F91*U_i_inv31*v61;
		hessian(5,22) = hessian(22,5) = (1.0/4.0)*F11*U_i_inv61*v41 + (1.0/4.0)*F21*U_i_inv51*v41 + (1.0/2.0)*F31*U_i_inv31*v41 + (1.0/4.0)*F41*U_i_inv61*v21 + (1.0/4.0)*F51*U_i_inv51*v21 + (1.0/2.0)*F61*U_i_inv31*v21 + (1.0/4.0)*F71*U_i_inv61*v51 + (1.0/4.0)*F81*U_i_inv51*v51 + (1.0/2.0)*F91*U_i_inv31*v51;
		hessian(5,23) = hessian(23,5) = (1.0/4.0)*F11*U_i_inv61*v61 + (1.0/4.0)*F21*U_i_inv51*v61 + (1.0/2.0)*F31*U_i_inv31*v61 + (1.0/4.0)*F41*U_i_inv61*v51 + (1.0/4.0)*F51*U_i_inv51*v51 + (1.0/2.0)*F61*U_i_inv31*v51 + (1.0/4.0)*F71*U_i_inv61*v31 + (1.0/4.0)*F81*U_i_inv51*v31 + (1.0/2.0)*F91*U_i_inv31*v31;
		hessian(5,24) = hessian(24,5) = 0;
		hessian(5,25) = hessian(25,5) = 0;
		hessian(5,26) = hessian(26,5) = 0;
		hessian(5,27) = hessian(27,5) = (1.0/2.0)*F11*U_i_inv11*v11 + (1.0/4.0)*F21*U_i_inv41*v11 + (1.0/4.0)*F31*U_i_inv61*v11 + (1.0/2.0)*F41*U_i_inv11*v41 + (1.0/4.0)*F51*U_i_inv41*v41 + (1.0/4.0)*F61*U_i_inv61*v41 + (1.0/2.0)*F71*U_i_inv11*v61 + (1.0/4.0)*F81*U_i_inv41*v61 + (1.0/4.0)*F91*U_i_inv61*v61;
		hessian(5,28) = hessian(28,5) = (1.0/2.0)*F11*U_i_inv11*v41 + (1.0/4.0)*F21*U_i_inv41*v41 + (1.0/4.0)*F31*U_i_inv61*v41 + (1.0/2.0)*F41*U_i_inv11*v21 + (1.0/4.0)*F51*U_i_inv41*v21 + (1.0/4.0)*F61*U_i_inv61*v21 + (1.0/2.0)*F71*U_i_inv11*v51 + (1.0/4.0)*F81*U_i_inv41*v51 + (1.0/4.0)*F91*U_i_inv61*v51;
		hessian(5,29) = hessian(29,5) = (1.0/2.0)*F11*U_i_inv11*v61 + (1.0/4.0)*F21*U_i_inv41*v61 + (1.0/4.0)*F31*U_i_inv61*v61 + (1.0/2.0)*F41*U_i_inv11*v51 + (1.0/4.0)*F51*U_i_inv41*v51 + (1.0/4.0)*F61*U_i_inv61*v51 + (1.0/2.0)*F71*U_i_inv11*v31 + (1.0/4.0)*F81*U_i_inv41*v31 + (1.0/4.0)*F91*U_i_inv61*v31;
		hessian(6,6) = 0;
		hessian(6,7) = hessian(7,6) = 0;
		hessian(6,8) = hessian(8,6) = 0;
		hessian(6,9) = hessian(9,6) = 0;
		hessian(6,10) = hessian(10,6) = 0;
		hessian(6,11) = hessian(11,6) = 0;
		hessian(6,12) = hessian(12,6) = F_inv11*U_i_dot11*v11 + F_inv21*U_i_dot11*v41 + F_inv31*U_i_dot11*v61 + (1.0/2.0)*F_inv41*U_i_dot41*v11 +(1.0/2.0)*F_inv51*U_i_dot41*v41 + (1.0/2.0)*F_inv61*U_i_dot41*v61 + (1.0/2.0)*F_inv71*U_i_dot61*v11 + (1.0/2.0)*F_inv81*U_i_dot61*v41 + (1.0/2.0)*F_inv91*U_i_dot61*v61;
		hessian(6,13) = hessian(13,6) = 0;
		hessian(6,14) = hessian(14,6) = 0;
		hessian(6,15) = hessian(15,6) = F_inv11*U_i_dot11*v41 + F_inv21*U_i_dot11*v21 + F_inv31*U_i_dot11*v51 + (1.0/2.0)*F_inv41*U_i_dot41*v41 +(1.0/2.0)*F_inv51*U_i_dot41*v21 + (1.0/2.0)*F_inv61*U_i_dot41*v51 + (1.0/2.0)*F_inv71*U_i_dot61*v41 + (1.0/2.0)*F_inv81*U_i_dot61*v21 + (1.0/2.0)*F_inv91*U_i_dot61*v51;
		hessian(6,16) = hessian(16,6) = 0;
		hessian(6,17) = hessian(17,6) = 0;
		hessian(6,18) = hessian(18,6) = F_inv11*U_i_dot11*v61 + F_inv21*U_i_dot11*v51 + F_inv31*U_i_dot11*v31 + (1.0/2.0)*F_inv41*U_i_dot41*v61 +(1.0/2.0)*F_inv51*U_i_dot41*v51 + (1.0/2.0)*F_inv61*U_i_dot41*v31 + (1.0/2.0)*F_inv71*U_i_dot61*v61 + (1.0/2.0)*F_inv81*U_i_dot61*v51 + (1.0/2.0)*F_inv91*U_i_dot61*v31;
		hessian(6,19) = hessian(19,6) = 0;
		hessian(6,20) = hessian(20,6) = 0;
		hessian(6,21) = hessian(21,6) = U_i_dot11*(F11*v11 + F41*v41 + F71*v61);
		hessian(6,22) = hessian(22,6) = U_i_dot11*(F11*v41 + F41*v21 + F71*v51);
		hessian(6,23) = hessian(23,6) = U_i_dot11*(F11*v61 + F41*v51 + F71*v31);
		hessian(6,24) = hessian(24,6) = (1.0/2.0)*U_i_dot41*(F11*v11 + F41*v41 + F71*v61);
		hessian(6,25) = hessian(25,6) = (1.0/2.0)*U_i_dot41*(F11*v41 + F41*v21 + F71*v51);
		hessian(6,26) = hessian(26,6) = (1.0/2.0)*U_i_dot41*(F11*v61 + F41*v51 + F71*v31);
		hessian(6,27) = hessian(27,6) = (1.0/2.0)*U_i_dot61*(F11*v11 + F41*v41 + F71*v61);
		hessian(6,28) = hessian(28,6) = (1.0/2.0)*U_i_dot61*(F11*v41 + F41*v21 + F71*v51);
		hessian(6,29) = hessian(29,6) = (1.0/2.0)*U_i_dot61*(F11*v61 + F41*v51 + F71*v31);
		hessian(7,7) = 0;
		hessian(7,8) = hessian(8,7) = 0;
		hessian(7,9) = hessian(9,7) = 0;
		hessian(7,10) = hessian(10,7) = 0;
		hessian(7,11) = hessian(11,7) = 0;
		hessian(7,12) = hessian(12,7) = 0;
		hessian(7,13) = hessian(13,7) = (1.0/2.0)*F_inv11*U_i_dot41*v11 + (1.0/2.0)*F_inv21*U_i_dot41*v41 + (1.0/2.0)*F_inv31*U_i_dot41*v61 + F_inv41*U_i_dot21*v11 + F_inv51*U_i_dot21*v41 + F_inv61*U_i_dot21*v61 + (1.0/2.0)*F_inv71*U_i_dot51*v11 + (1.0/2.0)*F_inv81*U_i_dot51*v41 + (1.0/2.0)*F_inv91*U_i_dot51*v61;
		hessian(7,14) = hessian(14,7) = 0;
		hessian(7,15) = hessian(15,7) = 0;
		hessian(7,16) = hessian(16,7) = (1.0/2.0)*F_inv11*U_i_dot41*v41 + (1.0/2.0)*F_inv21*U_i_dot41*v21 + (1.0/2.0)*F_inv31*U_i_dot41*v51 + F_inv41*U_i_dot21*v41 + F_inv51*U_i_dot21*v21 + F_inv61*U_i_dot21*v51 + (1.0/2.0)*F_inv71*U_i_dot51*v41 + (1.0/2.0)*F_inv81*U_i_dot51*v21 + (1.0/2.0)*F_inv91*U_i_dot51*v51;
		hessian(7,17) = hessian(17,7) = 0;
		hessian(7,18) = hessian(18,7) = 0;
		hessian(7,19) = hessian(19,7) = (1.0/2.0)*F_inv11*U_i_dot41*v61 + (1.0/2.0)*F_inv21*U_i_dot41*v51 + (1.0/2.0)*F_inv31*U_i_dot41*v31 + F_inv41*U_i_dot21*v61 + F_inv51*U_i_dot21*v51 + F_inv61*U_i_dot21*v31 + (1.0/2.0)*F_inv71*U_i_dot51*v61 + (1.0/2.0)*F_inv81*U_i_dot51*v51 + (1.0/2.0)*F_inv91*U_i_dot51*v31;
		hessian(7,20) = hessian(20,7) = 0;
		hessian(7,21) = hessian(21,7) = (1.0/2.0)*U_i_dot41*(F21*v11 + F51*v41 + F81*v61);
		hessian(7,22) = hessian(22,7) = (1.0/2.0)*U_i_dot41*(F21*v41 + F51*v21 + F81*v51);
		hessian(7,23) = hessian(23,7) = (1.0/2.0)*U_i_dot41*(F21*v61 + F51*v51 + F81*v31);
		hessian(7,24) = hessian(24,7) = U_i_dot21*(F21*v11 + F51*v41 + F81*v61);
		hessian(7,25) = hessian(25,7) = U_i_dot21*(F21*v41 + F51*v21 + F81*v51);
		hessian(7,26) = hessian(26,7) = U_i_dot21*(F21*v61 + F51*v51 + F81*v31);
		hessian(7,27) = hessian(27,7) = (1.0/2.0)*U_i_dot51*(F21*v11 + F51*v41 + F81*v61);
		hessian(7,28) = hessian(28,7) = (1.0/2.0)*U_i_dot51*(F21*v41 + F51*v21 + F81*v51);
		hessian(7,29) = hessian(29,7) = (1.0/2.0)*U_i_dot51*(F21*v61 + F51*v51 + F81*v31);
		hessian(8,8) = 0;
		hessian(8,9) = hessian(9,8) = 0;
		hessian(8,10) = hessian(10,8) = 0;
		hessian(8,11) = hessian(11,8) = 0;
		hessian(8,12) = hessian(12,8) = 0;
		hessian(8,13) = hessian(13,8) = 0;
		hessian(8,14) = hessian(14,8) = (1.0/2.0)*F_inv11*U_i_dot61*v11 + (1.0/2.0)*F_inv21*U_i_dot61*v41 + (1.0/2.0)*F_inv31*U_i_dot61*v61 + (1.0/2.0)*F_inv41*U_i_dot51*v11 + (1.0/2.0)*F_inv51*U_i_dot51*v41 + (1.0/2.0)*F_inv61*U_i_dot51*v61 + F_inv71*U_i_dot31*v11 + F_inv81*U_i_dot31*v41 + F_inv91*U_i_dot31*v61;
		hessian(8,15) = hessian(15,8) = 0;
		hessian(8,16) = hessian(16,8) = 0;
		hessian(8,17) = hessian(17,8) = (1.0/2.0)*F_inv11*U_i_dot61*v41 + (1.0/2.0)*F_inv21*U_i_dot61*v21 + (1.0/2.0)*F_inv31*U_i_dot61*v51 + (1.0/2.0)*F_inv41*U_i_dot51*v41 + (1.0/2.0)*F_inv51*U_i_dot51*v21 + (1.0/2.0)*F_inv61*U_i_dot51*v51 + F_inv71*U_i_dot31*v41 + F_inv81*U_i_dot31*v21 + F_inv91*U_i_dot31*v51;
		hessian(8,18) = hessian(18,8) = 0;
		hessian(8,19) = hessian(19,8) = 0;
		hessian(8,20) = hessian(20,8) = (1.0/2.0)*F_inv11*U_i_dot61*v61 + (1.0/2.0)*F_inv21*U_i_dot61*v51 + (1.0/2.0)*F_inv31*U_i_dot61*v31 + (1.0/2.0)*F_inv41*U_i_dot51*v61 + (1.0/2.0)*F_inv51*U_i_dot51*v51 + (1.0/2.0)*F_inv61*U_i_dot51*v31 + F_inv71*U_i_dot31*v61 + F_inv81*U_i_dot31*v51 + F_inv91*U_i_dot31*v31;
		hessian(8,21) = hessian(21,8) = (1.0/2.0)*U_i_dot61*(F31*v11 + F61*v41 + F91*v61);
		hessian(8,22) = hessian(22,8) = (1.0/2.0)*U_i_dot61*(F31*v41 + F61*v21 + F91*v51);
		hessian(8,23) = hessian(23,8) = (1.0/2.0)*U_i_dot61*(F31*v61 + F61*v51 + F91*v31);
		hessian(8,24) = hessian(24,8) = (1.0/2.0)*U_i_dot51*(F31*v11 + F61*v41 + F91*v61);
		hessian(8,25) = hessian(25,8) = (1.0/2.0)*U_i_dot51*(F31*v41 + F61*v21 + F91*v51);
		hessian(8,26) = hessian(26,8) = (1.0/2.0)*U_i_dot51*(F31*v61 + F61*v51 + F91*v31);
		hessian(8,27) = hessian(27,8) = U_i_dot31*(F31*v11 + F61*v41 + F91*v61);
		hessian(8,28) = hessian(28,8) = U_i_dot31*(F31*v41 + F61*v21 + F91*v51);
		hessian(8,29) = hessian(29,8) = U_i_dot31*(F31*v61 + F61*v51 + F91*v31);
		hessian(9,9) = 0;
		hessian(9,10) = hessian(10,9) = 0;
		hessian(9,11) = hessian(11,9) = 0;
		hessian(9,12) = hessian(12,9) = (1.0/4.0)*F_inv11*U_i_dot41*v11 + (1.0/4.0)*F_inv21*U_i_dot41*v41 + (1.0/4.0)*F_inv31*U_i_dot41*v61 + (1.0/2.0)*F_inv41*U_i_dot21*v11 + (1.0/2.0)*F_inv51*U_i_dot21*v41 + (1.0/2.0)*F_inv61*U_i_dot21*v61 + (1.0/4.0)*F_inv71*U_i_dot51*v11 + (1.0/4.0)*F_inv81*U_i_dot51*v41 + (1.0/4.0)*F_inv91*U_i_dot51*v61;
		hessian(9,13) = hessian(13,9) = (1.0/2.0)*F_inv11*U_i_dot11*v11 + (1.0/2.0)*F_inv21*U_i_dot11*v41 + (1.0/2.0)*F_inv31*U_i_dot11*v61 + (1.0/4.0)*F_inv41*U_i_dot41*v11 + (1.0/4.0)*F_inv51*U_i_dot41*v41 + (1.0/4.0)*F_inv61*U_i_dot41*v61 + (1.0/4.0)*F_inv71*U_i_dot61*v11 + (1.0/4.0)*F_inv81*U_i_dot61*v41 + (1.0/4.0)*F_inv91*U_i_dot61*v61;
		hessian(9,14) = hessian(14,9) = 0;
		hessian(9,15) = hessian(15,9) = (1.0/4.0)*F_inv11*U_i_dot41*v41 + (1.0/4.0)*F_inv21*U_i_dot41*v21 + (1.0/4.0)*F_inv31*U_i_dot41*v51 + (1.0/2.0)*F_inv41*U_i_dot21*v41 + (1.0/2.0)*F_inv51*U_i_dot21*v21 + (1.0/2.0)*F_inv61*U_i_dot21*v51 + (1.0/4.0)*F_inv71*U_i_dot51*v41 + (1.0/4.0)*F_inv81*U_i_dot51*v21 + (1.0/4.0)*F_inv91*U_i_dot51*v51;
		hessian(9,16) = hessian(16,9) = (1.0/2.0)*F_inv11*U_i_dot11*v41 + (1.0/2.0)*F_inv21*U_i_dot11*v21 + (1.0/2.0)*F_inv31*U_i_dot11*v51 + (1.0/4.0)*F_inv41*U_i_dot41*v41 + (1.0/4.0)*F_inv51*U_i_dot41*v21 + (1.0/4.0)*F_inv61*U_i_dot41*v51 + (1.0/4.0)*F_inv71*U_i_dot61*v41 + (1.0/4.0)*F_inv81*U_i_dot61*v21 + (1.0/4.0)*F_inv91*U_i_dot61*v51;
		hessian(9,17) = hessian(17,9) = 0;
		hessian(9,18) = hessian(18,9) = (1.0/4.0)*F_inv11*U_i_dot41*v61 + (1.0/4.0)*F_inv21*U_i_dot41*v51 + (1.0/4.0)*F_inv31*U_i_dot41*v31 + (1.0/2.0)*F_inv41*U_i_dot21*v61 + (1.0/2.0)*F_inv51*U_i_dot21*v51 + (1.0/2.0)*F_inv61*U_i_dot21*v31 + (1.0/4.0)*F_inv71*U_i_dot51*v61 + (1.0/4.0)*F_inv81*U_i_dot51*v51 + (1.0/4.0)*F_inv91*U_i_dot51*v31;
		hessian(9,19) = hessian(19,9) = (1.0/2.0)*F_inv11*U_i_dot11*v61 + (1.0/2.0)*F_inv21*U_i_dot11*v51 + (1.0/2.0)*F_inv31*U_i_dot11*v31 + (1.0/4.0)*F_inv41*U_i_dot41*v61 + (1.0/4.0)*F_inv51*U_i_dot41*v51 + (1.0/4.0)*F_inv61*U_i_dot41*v31 + (1.0/4.0)*F_inv71*U_i_dot61*v61 + (1.0/4.0)*F_inv81*U_i_dot61*v51 + (1.0/4.0)*F_inv91*U_i_dot61*v31;
		hessian(9,20) = hessian(20,9) = 0;
		hessian(9,21) = hessian(21,9) = (1.0/4.0)*F11*U_i_dot41*v11 + (1.0/2.0)*F21*U_i_dot11*v11 + (1.0/4.0)*F41*U_i_dot41*v41 + (1.0/2.0)*F51*U_i_dot11*v41 + (1.0/4.0)*F71*U_i_dot41*v61 + (1.0/2.0)*F81*U_i_dot11*v61;
		hessian(9,22) = hessian(22,9) = (1.0/4.0)*F11*U_i_dot41*v41 + (1.0/2.0)*F21*U_i_dot11*v41 + (1.0/4.0)*F41*U_i_dot41*v21 + (1.0/2.0)*F51*U_i_dot11*v21 + (1.0/4.0)*F71*U_i_dot41*v51 + (1.0/2.0)*F81*U_i_dot11*v51;
		hessian(9,23) = hessian(23,9) = (1.0/4.0)*F11*U_i_dot41*v61 + (1.0/2.0)*F21*U_i_dot11*v61 + (1.0/4.0)*F41*U_i_dot41*v51 + (1.0/2.0)*F51*U_i_dot11*v51 + (1.0/4.0)*F71*U_i_dot41*v31 + (1.0/2.0)*F81*U_i_dot11*v31;
		hessian(9,24) = hessian(24,9) = (1.0/2.0)*F11*U_i_dot21*v11 + (1.0/4.0)*F21*U_i_dot41*v11 + (1.0/2.0)*F41*U_i_dot21*v41 + (1.0/4.0)*F51*U_i_dot41*v41 + (1.0/2.0)*F71*U_i_dot21*v61 + (1.0/4.0)*F81*U_i_dot41*v61;
		hessian(9,25) = hessian(25,9) = (1.0/2.0)*F11*U_i_dot21*v41 + (1.0/4.0)*F21*U_i_dot41*v41 + (1.0/2.0)*F41*U_i_dot21*v21 + (1.0/4.0)*F51*U_i_dot41*v21 + (1.0/2.0)*F71*U_i_dot21*v51 + (1.0/4.0)*F81*U_i_dot41*v51;
		hessian(9,26) = hessian(26,9) = (1.0/2.0)*F11*U_i_dot21*v61 + (1.0/4.0)*F21*U_i_dot41*v61 + (1.0/2.0)*F41*U_i_dot21*v51 + (1.0/4.0)*F51*U_i_dot41*v51 + (1.0/2.0)*F71*U_i_dot21*v31 + (1.0/4.0)*F81*U_i_dot41*v31;
		hessian(9,27) = hessian(27,9) = (1.0/4.0)*F11*U_i_dot51*v11 + (1.0/4.0)*F21*U_i_dot61*v11 + (1.0/4.0)*F41*U_i_dot51*v41 + (1.0/4.0)*F51*U_i_dot61*v41 + (1.0/4.0)*F71*U_i_dot51*v61 + (1.0/4.0)*F81*U_i_dot61*v61;
		hessian(9,28) = hessian(28,9) = (1.0/4.0)*F11*U_i_dot51*v41 + (1.0/4.0)*F21*U_i_dot61*v41 + (1.0/4.0)*F41*U_i_dot51*v21 + (1.0/4.0)*F51*U_i_dot61*v21 + (1.0/4.0)*F71*U_i_dot51*v51 + (1.0/4.0)*F81*U_i_dot61*v51;
		hessian(9,29) = hessian(29,9) = (1.0/4.0)*F11*U_i_dot51*v61 + (1.0/4.0)*F21*U_i_dot61*v61 + (1.0/4.0)*F41*U_i_dot51*v51 + (1.0/4.0)*F51*U_i_dot61*v51 + (1.0/4.0)*F71*U_i_dot51*v31 + (1.0/4.0)*F81*U_i_dot61*v31;
		hessian(10,10) = 0;
		hessian(10,11) = hessian(11,10) = 0;
		hessian(10,12) = hessian(12,10) = 0;
		hessian(10,13) = hessian(13,10) = (1.0/4.0)*F_inv11*U_i_dot61*v11 + (1.0/4.0)*F_inv21*U_i_dot61*v41 + (1.0/4.0)*F_inv31*U_i_dot61*v61 + (1.0/4.0)*F_inv41*U_i_dot51*v11 + (1.0/4.0)*F_inv51*U_i_dot51*v41 + (1.0/4.0)*F_inv61*U_i_dot51*v61 + (1.0/2.0)*F_inv71*U_i_dot31*v11 + (1.0/2.0)*F_inv81*U_i_dot31*v41 + (1.0/2.0)*F_inv91*U_i_dot31*v61;
		hessian(10,14) = hessian(14,10) = (1.0/4.0)*F_inv11*U_i_dot41*v11 + (1.0/4.0)*F_inv21*U_i_dot41*v41 + (1.0/4.0)*F_inv31*U_i_dot41*v61 + (1.0/2.0)*F_inv41*U_i_dot21*v11 + (1.0/2.0)*F_inv51*U_i_dot21*v41 + (1.0/2.0)*F_inv61*U_i_dot21*v61 + (1.0/4.0)*F_inv71*U_i_dot51*v11 + (1.0/4.0)*F_inv81*U_i_dot51*v41 + (1.0/4.0)*F_inv91*U_i_dot51*v61;
		hessian(10,15) = hessian(15,10) = 0;
		hessian(10,16) = hessian(16,10) = (1.0/4.0)*F_inv11*U_i_dot61*v41 + (1.0/4.0)*F_inv21*U_i_dot61*v21 + (1.0/4.0)*F_inv31*U_i_dot61*v51 + (1.0/4.0)*F_inv41*U_i_dot51*v41 + (1.0/4.0)*F_inv51*U_i_dot51*v21 + (1.0/4.0)*F_inv61*U_i_dot51*v51 + (1.0/2.0)*F_inv71*U_i_dot31*v41 + (1.0/2.0)*F_inv81*U_i_dot31*v21 + (1.0/2.0)*F_inv91*U_i_dot31*v51;
		hessian(10,17) = hessian(17,10) = (1.0/4.0)*F_inv11*U_i_dot41*v41 + (1.0/4.0)*F_inv21*U_i_dot41*v21 + (1.0/4.0)*F_inv31*U_i_dot41*v51 + (1.0/2.0)*F_inv41*U_i_dot21*v41 + (1.0/2.0)*F_inv51*U_i_dot21*v21 + (1.0/2.0)*F_inv61*U_i_dot21*v51 + (1.0/4.0)*F_inv71*U_i_dot51*v41 + (1.0/4.0)*F_inv81*U_i_dot51*v21 + (1.0/4.0)*F_inv91*U_i_dot51*v51;
		hessian(10,18) = hessian(18,10) = 0;
		hessian(10,19) = hessian(19,10) = (1.0/4.0)*F_inv11*U_i_dot61*v61 + (1.0/4.0)*F_inv21*U_i_dot61*v51 + (1.0/4.0)*F_inv31*U_i_dot61*v31 + (1.0/4.0)*F_inv41*U_i_dot51*v61 + (1.0/4.0)*F_inv51*U_i_dot51*v51 + (1.0/4.0)*F_inv61*U_i_dot51*v31 + (1.0/2.0)*F_inv71*U_i_dot31*v61 + (1.0/2.0)*F_inv81*U_i_dot31*v51 + (1.0/2.0)*F_inv91*U_i_dot31*v31;
		hessian(10,20) = hessian(20,10) = (1.0/4.0)*F_inv11*U_i_dot41*v61 + (1.0/4.0)*F_inv21*U_i_dot41*v51 + (1.0/4.0)*F_inv31*U_i_dot41*v31 + (1.0/2.0)*F_inv41*U_i_dot21*v61 + (1.0/2.0)*F_inv51*U_i_dot21*v51 + (1.0/2.0)*F_inv61*U_i_dot21*v31 + (1.0/4.0)*F_inv71*U_i_dot51*v61 + (1.0/4.0)*F_inv81*U_i_dot51*v51 + (1.0/4.0)*F_inv91*U_i_dot51*v31;
		hessian(10,21) = hessian(21,10) = (1.0/4.0)*F21*U_i_dot61*v11 + (1.0/4.0)*F31*U_i_dot41*v11 + (1.0/4.0)*F51*U_i_dot61*v41 + (1.0/4.0)*F61*U_i_dot41*v41 + (1.0/4.0)*F81*U_i_dot61*v61 + (1.0/4.0)*F91*U_i_dot41*v61;
		hessian(10,22) = hessian(22,10) = (1.0/4.0)*F21*U_i_dot61*v41 + (1.0/4.0)*F31*U_i_dot41*v41 + (1.0/4.0)*F51*U_i_dot61*v21 + (1.0/4.0)*F61*U_i_dot41*v21 + (1.0/4.0)*F81*U_i_dot61*v51 + (1.0/4.0)*F91*U_i_dot41*v51;
		hessian(10,23) = hessian(23,10) = (1.0/4.0)*F21*U_i_dot61*v61 + (1.0/4.0)*F31*U_i_dot41*v61 + (1.0/4.0)*F51*U_i_dot61*v51 + (1.0/4.0)*F61*U_i_dot41*v51 + (1.0/4.0)*F81*U_i_dot61*v31 + (1.0/4.0)*F91*U_i_dot41*v31;
		hessian(10,24) = hessian(24,10) = (1.0/4.0)*F21*U_i_dot51*v11 + (1.0/2.0)*F31*U_i_dot21*v11 + (1.0/4.0)*F51*U_i_dot51*v41 + (1.0/2.0)*F61*U_i_dot21*v41 + (1.0/4.0)*F81*U_i_dot51*v61 + (1.0/2.0)*F91*U_i_dot21*v61;
		hessian(10,25) = hessian(25,10) = (1.0/4.0)*F21*U_i_dot51*v41 + (1.0/2.0)*F31*U_i_dot21*v41 + (1.0/4.0)*F51*U_i_dot51*v21 + (1.0/2.0)*F61*U_i_dot21*v21 + (1.0/4.0)*F81*U_i_dot51*v51 + (1.0/2.0)*F91*U_i_dot21*v51;
		hessian(10,26) = hessian(26,10) = (1.0/4.0)*F21*U_i_dot51*v61 + (1.0/2.0)*F31*U_i_dot21*v61 + (1.0/4.0)*F51*U_i_dot51*v51 + (1.0/2.0)*F61*U_i_dot21*v51 + (1.0/4.0)*F81*U_i_dot51*v31 + (1.0/2.0)*F91*U_i_dot21*v31;
		hessian(10,27) = hessian(27,10) = (1.0/2.0)*F21*U_i_dot31*v11 + (1.0/4.0)*F31*U_i_dot51*v11 + (1.0/2.0)*F51*U_i_dot31*v41 + (1.0/4.0)*F61*U_i_dot51*v41 + (1.0/2.0)*F81*U_i_dot31*v61 + (1.0/4.0)*F91*U_i_dot51*v61;
		hessian(10,28) = hessian(28,10) = (1.0/2.0)*F21*U_i_dot31*v41 + (1.0/4.0)*F31*U_i_dot51*v41 + (1.0/2.0)*F51*U_i_dot31*v21 + (1.0/4.0)*F61*U_i_dot51*v21 + (1.0/2.0)*F81*U_i_dot31*v51 + (1.0/4.0)*F91*U_i_dot51*v51;
		hessian(10,29) = hessian(29,10) = (1.0/2.0)*F21*U_i_dot31*v61 + (1.0/4.0)*F31*U_i_dot51*v61 + (1.0/2.0)*F51*U_i_dot31*v51 + (1.0/4.0)*F61*U_i_dot51*v51 + (1.0/2.0)*F81*U_i_dot31*v31 + (1.0/4.0)*F91*U_i_dot51*v31;
		hessian(11,11) = 0;
		hessian(11,12) = hessian(12,11) = (1.0/4.0)*F_inv11*U_i_dot61*v11 + (1.0/4.0)*F_inv21*U_i_dot61*v41 + (1.0/4.0)*F_inv31*U_i_dot61*v61 + (1.0/4.0)*F_inv41*U_i_dot51*v11 + (1.0/4.0)*F_inv51*U_i_dot51*v41 + (1.0/4.0)*F_inv61*U_i_dot51*v61 + (1.0/2.0)*F_inv71*U_i_dot31*v11 + (1.0/2.0)*F_inv81*U_i_dot31*v41 + (1.0/2.0)*F_inv91*U_i_dot31*v61;
		hessian(11,13) = hessian(13,11) = 0;
		hessian(11,14) = hessian(14,11) = (1.0/2.0)*F_inv11*U_i_dot11*v11 + (1.0/2.0)*F_inv21*U_i_dot11*v41 + (1.0/2.0)*F_inv31*U_i_dot11*v61 + (1.0/4.0)*F_inv41*U_i_dot41*v11 + (1.0/4.0)*F_inv51*U_i_dot41*v41 + (1.0/4.0)*F_inv61*U_i_dot41*v61 + (1.0/4.0)*F_inv71*U_i_dot61*v11 + (1.0/4.0)*F_inv81*U_i_dot61*v41 + (1.0/4.0)*F_inv91*U_i_dot61*v61;
		hessian(11,15) = hessian(15,11) = (1.0/4.0)*F_inv11*U_i_dot61*v41 + (1.0/4.0)*F_inv21*U_i_dot61*v21 + (1.0/4.0)*F_inv31*U_i_dot61*v51 + (1.0/4.0)*F_inv41*U_i_dot51*v41 + (1.0/4.0)*F_inv51*U_i_dot51*v21 + (1.0/4.0)*F_inv61*U_i_dot51*v51 + (1.0/2.0)*F_inv71*U_i_dot31*v41 + (1.0/2.0)*F_inv81*U_i_dot31*v21 + (1.0/2.0)*F_inv91*U_i_dot31*v51;
		hessian(11,16) = hessian(16,11) = 0;
		hessian(11,17) = hessian(17,11) = (1.0/2.0)*F_inv11*U_i_dot11*v41 + (1.0/2.0)*F_inv21*U_i_dot11*v21 + (1.0/2.0)*F_inv31*U_i_dot11*v51 + (1.0/4.0)*F_inv41*U_i_dot41*v41 + (1.0/4.0)*F_inv51*U_i_dot41*v21 + (1.0/4.0)*F_inv61*U_i_dot41*v51 + (1.0/4.0)*F_inv71*U_i_dot61*v41 + (1.0/4.0)*F_inv81*U_i_dot61*v21 + (1.0/4.0)*F_inv91*U_i_dot61*v51;
		hessian(11,18) = hessian(18,11) = (1.0/4.0)*F_inv11*U_i_dot61*v61 + (1.0/4.0)*F_inv21*U_i_dot61*v51 + (1.0/4.0)*F_inv31*U_i_dot61*v31 + (1.0/4.0)*F_inv41*U_i_dot51*v61 + (1.0/4.0)*F_inv51*U_i_dot51*v51 + (1.0/4.0)*F_inv61*U_i_dot51*v31 + (1.0/2.0)*F_inv71*U_i_dot31*v61 + (1.0/2.0)*F_inv81*U_i_dot31*v51 + (1.0/2.0)*F_inv91*U_i_dot31*v31;
		hessian(11,19) = hessian(19,11) = 0;
		hessian(11,20) = hessian(20,11) = (1.0/2.0)*F_inv11*U_i_dot11*v61 + (1.0/2.0)*F_inv21*U_i_dot11*v51 + (1.0/2.0)*F_inv31*U_i_dot11*v31 + (1.0/4.0)*F_inv41*U_i_dot41*v61 + (1.0/4.0)*F_inv51*U_i_dot41*v51 + (1.0/4.0)*F_inv61*U_i_dot41*v31 + (1.0/4.0)*F_inv71*U_i_dot61*v61 + (1.0/4.0)*F_inv81*U_i_dot61*v51 + (1.0/4.0)*F_inv91*U_i_dot61*v31;
		hessian(11,21) = hessian(21,11) = (1.0/4.0)*F11*U_i_dot61*v11 + (1.0/2.0)*F31*U_i_dot11*v11 + (1.0/4.0)*F41*U_i_dot61*v41 + (1.0/2.0)*F61*U_i_dot11*v41 + (1.0/4.0)*F71*U_i_dot61*v61 + (1.0/2.0)*F91*U_i_dot11*v61;
		hessian(11,22) = hessian(22,11) = (1.0/4.0)*F11*U_i_dot61*v41 + (1.0/2.0)*F31*U_i_dot11*v41 + (1.0/4.0)*F41*U_i_dot61*v21 + (1.0/2.0)*F61*U_i_dot11*v21 + (1.0/4.0)*F71*U_i_dot61*v51 + (1.0/2.0)*F91*U_i_dot11*v51;
		hessian(11,23) = hessian(23,11) = (1.0/4.0)*F11*U_i_dot61*v61 + (1.0/2.0)*F31*U_i_dot11*v61 + (1.0/4.0)*F41*U_i_dot61*v51 + (1.0/2.0)*F61*U_i_dot11*v51 + (1.0/4.0)*F71*U_i_dot61*v31 + (1.0/2.0)*F91*U_i_dot11*v31;
		hessian(11,24) = hessian(24,11) = (1.0/4.0)*F11*U_i_dot51*v11 + (1.0/4.0)*F31*U_i_dot41*v11 + (1.0/4.0)*F41*U_i_dot51*v41 + (1.0/4.0)*F61*U_i_dot41*v41 + (1.0/4.0)*F71*U_i_dot51*v61 + (1.0/4.0)*F91*U_i_dot41*v61;
		hessian(11,25) = hessian(25,11) = (1.0/4.0)*F11*U_i_dot51*v41 + (1.0/4.0)*F31*U_i_dot41*v41 + (1.0/4.0)*F41*U_i_dot51*v21 + (1.0/4.0)*F61*U_i_dot41*v21 + (1.0/4.0)*F71*U_i_dot51*v51 + (1.0/4.0)*F91*U_i_dot41*v51;
		hessian(11,26) = hessian(26,11) = (1.0/4.0)*F11*U_i_dot51*v61 + (1.0/4.0)*F31*U_i_dot41*v61 + (1.0/4.0)*F41*U_i_dot51*v51 + (1.0/4.0)*F61*U_i_dot41*v51 + (1.0/4.0)*F71*U_i_dot51*v31 + (1.0/4.0)*F91*U_i_dot41*v31;
		hessian(11,27) = hessian(27,11) = (1.0/2.0)*F11*U_i_dot31*v11 + (1.0/4.0)*F31*U_i_dot61*v11 + (1.0/2.0)*F41*U_i_dot31*v41 + (1.0/4.0)*F61*U_i_dot61*v41 + (1.0/2.0)*F71*U_i_dot31*v61 + (1.0/4.0)*F91*U_i_dot61*v61;
		hessian(11,28) = hessian(28,11) = (1.0/2.0)*F11*U_i_dot31*v41 + (1.0/4.0)*F31*U_i_dot61*v41 + (1.0/2.0)*F41*U_i_dot31*v21 + (1.0/4.0)*F61*U_i_dot61*v21 + (1.0/2.0)*F71*U_i_dot31*v51 + (1.0/4.0)*F91*U_i_dot61*v51;
		hessian(11,29) = hessian(29,11) = (1.0/2.0)*F11*U_i_dot31*v61 + (1.0/4.0)*F31*U_i_dot61*v61 + (1.0/2.0)*F41*U_i_dot31*v51 + (1.0/4.0)*F61*U_i_dot61*v51 + (1.0/2.0)*F71*U_i_dot31*v31 + (1.0/4.0)*F91*U_i_dot61*v31;
		hessian(12,12) = 0;
		hessian(12,13) = hessian(13,12) = 0;
		hessian(12,14) = hessian(14,12) = 0;
		hessian(12,15) = hessian(15,12) = 0;
		hessian(12,16) = hessian(16,12) = 0;
		hessian(12,17) = hessian(17,12) = 0;
		hessian(12,18) = hessian(18,12) = 0;
		hessian(12,19) = hessian(19,12) = 0;
		hessian(12,20) = hessian(20,12) = 0;
		hessian(12,21) = hessian(21,12) = (1.0/4.0)*v11*(4*U_i_dot11*U_i_inv11 + U_i_dot41*U_i_inv41 + U_i_dot61*U_i_inv61);
		hessian(12,22) = hessian(22,12) = (1.0/4.0)*v41*(4*U_i_dot11*U_i_inv11 + U_i_dot41*U_i_inv41 + U_i_dot61*U_i_inv61);
		hessian(12,23) = hessian(23,12) = (1.0/4.0)*v61*(4*U_i_dot11*U_i_inv11 + U_i_dot41*U_i_inv41 + U_i_dot61*U_i_inv61);
		hessian(12,24) = hessian(24,12) = (1.0/4.0)*v11*(2*U_i_dot21*U_i_inv41 + 2*U_i_dot41*U_i_inv11 + U_i_dot51*U_i_inv61);
		hessian(12,25) = hessian(25,12) = (1.0/4.0)*v41*(2*U_i_dot21*U_i_inv41 + 2*U_i_dot41*U_i_inv11 + U_i_dot51*U_i_inv61);
		hessian(12,26) = hessian(26,12) = (1.0/4.0)*v61*(2*U_i_dot21*U_i_inv41 + 2*U_i_dot41*U_i_inv11 + U_i_dot51*U_i_inv61);
		hessian(12,27) = hessian(27,12) = (1.0/4.0)*v11*(2*U_i_dot31*U_i_inv61 + U_i_dot51*U_i_inv41 + 2*U_i_dot61*U_i_inv11);
		hessian(12,28) = hessian(28,12) = (1.0/4.0)*v41*(2*U_i_dot31*U_i_inv61 + U_i_dot51*U_i_inv41 + 2*U_i_dot61*U_i_inv11);
		hessian(12,29) = hessian(29,12) = (1.0/4.0)*v61*(2*U_i_dot31*U_i_inv61 + U_i_dot51*U_i_inv41 + 2*U_i_dot61*U_i_inv11);
		hessian(13,13) = 0;
		hessian(13,14) = hessian(14,13) = 0;
		hessian(13,15) = hessian(15,13) = 0;
		hessian(13,16) = hessian(16,13) = 0;
		hessian(13,17) = hessian(17,13) = 0;
		hessian(13,18) = hessian(18,13) = 0;
		hessian(13,19) = hessian(19,13) = 0;
		hessian(13,20) = hessian(20,13) = 0;
		hessian(13,21) = hessian(21,13) = (1.0/4.0)*v11*(2*U_i_dot11*U_i_inv41 + 2*U_i_dot41*U_i_inv21 + U_i_dot61*U_i_inv51);
		hessian(13,22) = hessian(22,13) = (1.0/4.0)*v41*(2*U_i_dot11*U_i_inv41 + 2*U_i_dot41*U_i_inv21 + U_i_dot61*U_i_inv51);
		hessian(13,23) = hessian(23,13) = (1.0/4.0)*v61*(2*U_i_dot11*U_i_inv41 + 2*U_i_dot41*U_i_inv21 + U_i_dot61*U_i_inv51);
		hessian(13,24) = hessian(24,13) = (1.0/4.0)*v11*(4*U_i_dot21*U_i_inv21 + U_i_dot41*U_i_inv41 + U_i_dot51*U_i_inv51);
		hessian(13,25) = hessian(25,13) = (1.0/4.0)*v41*(4*U_i_dot21*U_i_inv21 + U_i_dot41*U_i_inv41 + U_i_dot51*U_i_inv51);
		hessian(13,26) = hessian(26,13) = (1.0/4.0)*v61*(4*U_i_dot21*U_i_inv21 + U_i_dot41*U_i_inv41 + U_i_dot51*U_i_inv51);
		hessian(13,27) = hessian(27,13) = (1.0/4.0)*v11*(2*U_i_dot31*U_i_inv51 + 2*U_i_dot51*U_i_inv21 + U_i_dot61*U_i_inv41);
		hessian(13,28) = hessian(28,13) = (1.0/4.0)*v41*(2*U_i_dot31*U_i_inv51 + 2*U_i_dot51*U_i_inv21 + U_i_dot61*U_i_inv41);
		hessian(13,29) = hessian(29,13) = (1.0/4.0)*v61*(2*U_i_dot31*U_i_inv51 + 2*U_i_dot51*U_i_inv21 + U_i_dot61*U_i_inv41);
		hessian(14,14) = 0;
		hessian(14,15) = hessian(15,14) = 0;
		hessian(14,16) = hessian(16,14) = 0;
		hessian(14,17) = hessian(17,14) = 0;
		hessian(14,18) = hessian(18,14) = 0;
		hessian(14,19) = hessian(19,14) = 0;
		hessian(14,20) = hessian(20,14) = 0;
		hessian(14,21) = hessian(21,14) = (1.0/4.0)*v11*(2*U_i_dot11*U_i_inv61 + U_i_dot41*U_i_inv51 + 2*U_i_dot61*U_i_inv31);
		hessian(14,22) = hessian(22,14) = (1.0/4.0)*v41*(2*U_i_dot11*U_i_inv61 + U_i_dot41*U_i_inv51 + 2*U_i_dot61*U_i_inv31);
		hessian(14,23) = hessian(23,14) = (1.0/4.0)*v61*(2*U_i_dot11*U_i_inv61 + U_i_dot41*U_i_inv51 + 2*U_i_dot61*U_i_inv31);
		hessian(14,24) = hessian(24,14) = (1.0/4.0)*v11*(2*U_i_dot21*U_i_inv51 + U_i_dot41*U_i_inv61 + 2*U_i_dot51*U_i_inv31);
		hessian(14,25) = hessian(25,14) = (1.0/4.0)*v41*(2*U_i_dot21*U_i_inv51 + U_i_dot41*U_i_inv61 + 2*U_i_dot51*U_i_inv31);
		hessian(14,26) = hessian(26,14) = (1.0/4.0)*v61*(2*U_i_dot21*U_i_inv51 + U_i_dot41*U_i_inv61 + 2*U_i_dot51*U_i_inv31);
		hessian(14,27) = hessian(27,14) = (1.0/4.0)*v11*(4*U_i_dot31*U_i_inv31 + U_i_dot51*U_i_inv51 + U_i_dot61*U_i_inv61);
		hessian(14,28) = hessian(28,14) = (1.0/4.0)*v41*(4*U_i_dot31*U_i_inv31 + U_i_dot51*U_i_inv51 + U_i_dot61*U_i_inv61);
		hessian(14,29) = hessian(29,14) = (1.0/4.0)*v61*(4*U_i_dot31*U_i_inv31 + U_i_dot51*U_i_inv51 + U_i_dot61*U_i_inv61);
		hessian(15,15) = 0;
		hessian(15,16) = hessian(16,15) = 0;
		hessian(15,17) = hessian(17,15) = 0;
		hessian(15,18) = hessian(18,15) = 0;
		hessian(15,19) = hessian(19,15) = 0;
		hessian(15,20) = hessian(20,15) = 0;
		hessian(15,21) = hessian(21,15) = (1.0/4.0)*v41*(4*U_i_dot11*U_i_inv11 + U_i_dot41*U_i_inv41 + U_i_dot61*U_i_inv61);
		hessian(15,22) = hessian(22,15) = (1.0/4.0)*v21*(4*U_i_dot11*U_i_inv11 + U_i_dot41*U_i_inv41 + U_i_dot61*U_i_inv61);
		hessian(15,23) = hessian(23,15) = (1.0/4.0)*v51*(4*U_i_dot11*U_i_inv11 + U_i_dot41*U_i_inv41 + U_i_dot61*U_i_inv61);
		hessian(15,24) = hessian(24,15) = (1.0/4.0)*v41*(2*U_i_dot21*U_i_inv41 + 2*U_i_dot41*U_i_inv11 + U_i_dot51*U_i_inv61);
		hessian(15,25) = hessian(25,15) = (1.0/4.0)*v21*(2*U_i_dot21*U_i_inv41 + 2*U_i_dot41*U_i_inv11 + U_i_dot51*U_i_inv61);
		hessian(15,26) = hessian(26,15) = (1.0/4.0)*v51*(2*U_i_dot21*U_i_inv41 + 2*U_i_dot41*U_i_inv11 + U_i_dot51*U_i_inv61);
		hessian(15,27) = hessian(27,15) = (1.0/4.0)*v41*(2*U_i_dot31*U_i_inv61 + U_i_dot51*U_i_inv41 + 2*U_i_dot61*U_i_inv11);
		hessian(15,28) = hessian(28,15) = (1.0/4.0)*v21*(2*U_i_dot31*U_i_inv61 + U_i_dot51*U_i_inv41 + 2*U_i_dot61*U_i_inv11);
		hessian(15,29) = hessian(29,15) = (1.0/4.0)*v51*(2*U_i_dot31*U_i_inv61 + U_i_dot51*U_i_inv41 + 2*U_i_dot61*U_i_inv11);
		hessian(16,16) = 0;
		hessian(16,17) = hessian(17,16) = 0;
		hessian(16,18) = hessian(18,16) = 0;
		hessian(16,19) = hessian(19,16) = 0;
		hessian(16,20) = hessian(20,16) = 0;
		hessian(16,21) = hessian(21,16) = (1.0/4.0)*v41*(2*U_i_dot11*U_i_inv41 + 2*U_i_dot41*U_i_inv21 + U_i_dot61*U_i_inv51);
		hessian(16,22) = hessian(22,16) = (1.0/4.0)*v21*(2*U_i_dot11*U_i_inv41 + 2*U_i_dot41*U_i_inv21 + U_i_dot61*U_i_inv51);
		hessian(16,23) = hessian(23,16) = (1.0/4.0)*v51*(2*U_i_dot11*U_i_inv41 + 2*U_i_dot41*U_i_inv21 + U_i_dot61*U_i_inv51);
		hessian(16,24) = hessian(24,16) = (1.0/4.0)*v41*(4*U_i_dot21*U_i_inv21 + U_i_dot41*U_i_inv41 + U_i_dot51*U_i_inv51);
		hessian(16,25) = hessian(25,16) = (1.0/4.0)*v21*(4*U_i_dot21*U_i_inv21 + U_i_dot41*U_i_inv41 + U_i_dot51*U_i_inv51);
		hessian(16,26) = hessian(26,16) = (1.0/4.0)*v51*(4*U_i_dot21*U_i_inv21 + U_i_dot41*U_i_inv41 + U_i_dot51*U_i_inv51);
		hessian(16,27) = hessian(27,16) = (1.0/4.0)*v41*(2*U_i_dot31*U_i_inv51 + 2*U_i_dot51*U_i_inv21 + U_i_dot61*U_i_inv41);
		hessian(16,28) = hessian(28,16) = (1.0/4.0)*v21*(2*U_i_dot31*U_i_inv51 + 2*U_i_dot51*U_i_inv21 + U_i_dot61*U_i_inv41);
		hessian(16,29) = hessian(29,16) = (1.0/4.0)*v51*(2*U_i_dot31*U_i_inv51 + 2*U_i_dot51*U_i_inv21 + U_i_dot61*U_i_inv41);
		hessian(17,17) = 0;
		hessian(17,18) = hessian(18,17) = 0;
		hessian(17,19) = hessian(19,17) = 0;
		hessian(17,20) = hessian(20,17) = 0;
		hessian(17,21) = hessian(21,17) = (1.0/4.0)*v41*(2*U_i_dot11*U_i_inv61 + U_i_dot41*U_i_inv51 + 2*U_i_dot61*U_i_inv31);
		hessian(17,22) = hessian(22,17) = (1.0/4.0)*v21*(2*U_i_dot11*U_i_inv61 + U_i_dot41*U_i_inv51 + 2*U_i_dot61*U_i_inv31);
		hessian(17,23) = hessian(23,17) = (1.0/4.0)*v51*(2*U_i_dot11*U_i_inv61 + U_i_dot41*U_i_inv51 + 2*U_i_dot61*U_i_inv31);
		hessian(17,24) = hessian(24,17) = (1.0/4.0)*v41*(2*U_i_dot21*U_i_inv51 + U_i_dot41*U_i_inv61 + 2*U_i_dot51*U_i_inv31);
		hessian(17,25) = hessian(25,17) = (1.0/4.0)*v21*(2*U_i_dot21*U_i_inv51 + U_i_dot41*U_i_inv61 + 2*U_i_dot51*U_i_inv31);
		hessian(17,26) = hessian(26,17) = (1.0/4.0)*v51*(2*U_i_dot21*U_i_inv51 + U_i_dot41*U_i_inv61 + 2*U_i_dot51*U_i_inv31);
		hessian(17,27) = hessian(27,17) = (1.0/4.0)*v41*(4*U_i_dot31*U_i_inv31 + U_i_dot51*U_i_inv51 + U_i_dot61*U_i_inv61);
		hessian(17,28) = hessian(28,17) = (1.0/4.0)*v21*(4*U_i_dot31*U_i_inv31 + U_i_dot51*U_i_inv51 + U_i_dot61*U_i_inv61);
		hessian(17,29) = hessian(29,17) = (1.0/4.0)*v51*(4*U_i_dot31*U_i_inv31 + U_i_dot51*U_i_inv51 + U_i_dot61*U_i_inv61);
		hessian(18,18) = 0;
		hessian(18,19) = hessian(19,18) = 0;
		hessian(18,20) = hessian(20,18) = 0;
		hessian(18,21) = hessian(21,18) = (1.0/4.0)*v61*(4*U_i_dot11*U_i_inv11 + U_i_dot41*U_i_inv41 + U_i_dot61*U_i_inv61);
		hessian(18,22) = hessian(22,18) = (1.0/4.0)*v51*(4*U_i_dot11*U_i_inv11 + U_i_dot41*U_i_inv41 + U_i_dot61*U_i_inv61);
		hessian(18,23) = hessian(23,18) = (1.0/4.0)*v31*(4*U_i_dot11*U_i_inv11 + U_i_dot41*U_i_inv41 + U_i_dot61*U_i_inv61);
		hessian(18,24) = hessian(24,18) = (1.0/4.0)*v61*(2*U_i_dot21*U_i_inv41 + 2*U_i_dot41*U_i_inv11 + U_i_dot51*U_i_inv61);
		hessian(18,25) = hessian(25,18) = (1.0/4.0)*v51*(2*U_i_dot21*U_i_inv41 + 2*U_i_dot41*U_i_inv11 + U_i_dot51*U_i_inv61);
		hessian(18,26) = hessian(26,18) = (1.0/4.0)*v31*(2*U_i_dot21*U_i_inv41 + 2*U_i_dot41*U_i_inv11 + U_i_dot51*U_i_inv61);
		hessian(18,27) = hessian(27,18) = (1.0/4.0)*v61*(2*U_i_dot31*U_i_inv61 + U_i_dot51*U_i_inv41 + 2*U_i_dot61*U_i_inv11);
		hessian(18,28) = hessian(28,18) = (1.0/4.0)*v51*(2*U_i_dot31*U_i_inv61 + U_i_dot51*U_i_inv41 + 2*U_i_dot61*U_i_inv11);
		hessian(18,29) = hessian(29,18) = (1.0/4.0)*v31*(2*U_i_dot31*U_i_inv61 + U_i_dot51*U_i_inv41 + 2*U_i_dot61*U_i_inv11);
		hessian(19,19) = 0;
		hessian(19,20) = hessian(20,19) = 0;
		hessian(19,21) = hessian(21,19) = (1.0/4.0)*v61*(2*U_i_dot11*U_i_inv41 + 2*U_i_dot41*U_i_inv21 + U_i_dot61*U_i_inv51);
		hessian(19,22) = hessian(22,19) = (1.0/4.0)*v51*(2*U_i_dot11*U_i_inv41 + 2*U_i_dot41*U_i_inv21 + U_i_dot61*U_i_inv51);
		hessian(19,23) = hessian(23,19) = (1.0/4.0)*v31*(2*U_i_dot11*U_i_inv41 + 2*U_i_dot41*U_i_inv21 + U_i_dot61*U_i_inv51);
		hessian(19,24) = hessian(24,19) = (1.0/4.0)*v61*(4*U_i_dot21*U_i_inv21 + U_i_dot41*U_i_inv41 + U_i_dot51*U_i_inv51);
		hessian(19,25) = hessian(25,19) = (1.0/4.0)*v51*(4*U_i_dot21*U_i_inv21 + U_i_dot41*U_i_inv41 + U_i_dot51*U_i_inv51);
		hessian(19,26) = hessian(26,19) = (1.0/4.0)*v31*(4*U_i_dot21*U_i_inv21 + U_i_dot41*U_i_inv41 + U_i_dot51*U_i_inv51);
		hessian(19,27) = hessian(27,19) = (1.0/4.0)*v61*(2*U_i_dot31*U_i_inv51 + 2*U_i_dot51*U_i_inv21 + U_i_dot61*U_i_inv41);
		hessian(19,28) = hessian(28,19) = (1.0/4.0)*v51*(2*U_i_dot31*U_i_inv51 + 2*U_i_dot51*U_i_inv21 + U_i_dot61*U_i_inv41);
		hessian(19,29) = hessian(29,19) = (1.0/4.0)*v31*(2*U_i_dot31*U_i_inv51 + 2*U_i_dot51*U_i_inv21 + U_i_dot61*U_i_inv41);
		hessian(20,20) = 0;
		hessian(20,21) = hessian(21,20) = (1.0/4.0)*v61*(2*U_i_dot11*U_i_inv61 + U_i_dot41*U_i_inv51 + 2*U_i_dot61*U_i_inv31);
		hessian(20,22) = hessian(22,20) = (1.0/4.0)*v51*(2*U_i_dot11*U_i_inv61 + U_i_dot41*U_i_inv51 + 2*U_i_dot61*U_i_inv31);
		hessian(20,23) = hessian(23,20) = (1.0/4.0)*v31*(2*U_i_dot11*U_i_inv61 + U_i_dot41*U_i_inv51 + 2*U_i_dot61*U_i_inv31);
		hessian(20,24) = hessian(24,20) = (1.0/4.0)*v61*(2*U_i_dot21*U_i_inv51 + U_i_dot41*U_i_inv61 + 2*U_i_dot51*U_i_inv31);
		hessian(20,25) = hessian(25,20) = (1.0/4.0)*v51*(2*U_i_dot21*U_i_inv51 + U_i_dot41*U_i_inv61 + 2*U_i_dot51*U_i_inv31);
		hessian(20,26) = hessian(26,20) = (1.0/4.0)*v31*(2*U_i_dot21*U_i_inv51 + U_i_dot41*U_i_inv61 + 2*U_i_dot51*U_i_inv31);
		hessian(20,27) = hessian(27,20) = (1.0/4.0)*v61*(4*U_i_dot31*U_i_inv31 + U_i_dot51*U_i_inv51 + U_i_dot61*U_i_inv61);
		hessian(20,28) = hessian(28,20) = (1.0/4.0)*v51*(4*U_i_dot31*U_i_inv31 + U_i_dot51*U_i_inv51 + U_i_dot61*U_i_inv61);
		hessian(20,29) = hessian(29,20) = (1.0/4.0)*v31*(4*U_i_dot31*U_i_inv31 + U_i_dot51*U_i_inv51 + U_i_dot61*U_i_inv61);
		hessian(21,21) = 0;
		hessian(21,22) = hessian(22,21) = 0;
		hessian(21,23) = hessian(23,21) = 0;
		hessian(21,24) = hessian(24,21) = 0;
		hessian(21,25) = hessian(25,21) = 0;
		hessian(21,26) = hessian(26,21) = 0;
		hessian(21,27) = hessian(27,21) = 0;
		hessian(21,28) = hessian(28,21) = 0;
		hessian(21,29) = hessian(29,21) = 0;
		hessian(22,22) = 0;
		hessian(22,23) = hessian(23,22) = 0;
		hessian(22,24) = hessian(24,22) = 0;
		hessian(22,25) = hessian(25,22) = 0;
		hessian(22,26) = hessian(26,22) = 0;
		hessian(22,27) = hessian(27,22) = 0;
		hessian(22,28) = hessian(28,22) = 0;
		hessian(22,29) = hessian(29,22) = 0;
		hessian(23,23) = 0;
		hessian(23,24) = hessian(24,23) = 0;
		hessian(23,25) = hessian(25,23) = 0;
		hessian(23,26) = hessian(26,23) = 0;
		hessian(23,27) = hessian(27,23) = 0;
		hessian(23,28) = hessian(28,23) = 0;
		hessian(23,29) = hessian(29,23) = 0;
		hessian(24,24) = 0;
		hessian(24,25) = hessian(25,24) = 0;
		hessian(24,26) = hessian(26,24) = 0;
		hessian(24,27) = hessian(27,24) = 0;
		hessian(24,28) = hessian(28,24) = 0;
		hessian(24,29) = hessian(29,24) = 0;
		hessian(25,25) = 0;
		hessian(25,26) = hessian(26,25) = 0;
		hessian(25,27) = hessian(27,25) = 0;
		hessian(25,28) = hessian(28,25) = 0;
		hessian(25,29) = hessian(29,25) = 0;
		hessian(26,26) = 0;
		hessian(26,27) = hessian(27,26) = 0;
		hessian(26,28) = hessian(28,26) = 0;
		hessian(26,29) = hessian(29,26) = 0;
		hessian(27,27) = 0;
		hessian(27,28) = hessian(28,27) = 0;
		hessian(27,29) = hessian(29,27) = 0;
		hessian(28,28) = 0;
		hessian(28,29) = hessian(29,28) = 0;
		hessian(29,29) = 0;
	}

	return false;
}

/////////////
// PsiMech //
/////////////

PsiMech::PsiMech(	const VariableSet	argument_set,
					const VariableSet	parameter_set,
					const double		mu_e,
					const double		mu_i)
:
ScalarFunction<double, VectorXd, MatrixXd, VectorXd, VectorXd>(argument_set, parameter_set),
mu_e(mu_e),
mu_i(mu_i)
{
}

bool
PsiMech::compute(double&		value,
				VectorXd&	gradient,
				MatrixXd&	hessian,
				const bool	update_value,
				const bool	update_gradient,
				const bool	update_hessian)
{
	const double F11 = get_arguments()[0];
	const double F21 = get_arguments()[1];
	const double F31 = get_arguments()[2];
	const double F41 = get_arguments()[3];
	const double F51 = get_arguments()[4];
	const double F61 = get_arguments()[5];
	const double F71 = get_arguments()[6];
	const double F81 = get_arguments()[7];
	const double F91 = get_arguments()[8];

	const double Ui_inv11 = get_arguments()[9];
	const double Ui_inv21 = get_arguments()[10];
	const double Ui_inv31 = get_arguments()[11];
	const double Ui_inv41 = get_arguments()[12];
	const double Ui_inv51 = get_arguments()[13];
	const double Ui_inv61 = get_arguments()[14];

	if(update_value)
	{
		value = (1.0/2.0)*mu_e*((F11*F11) + (F21*F21) + (F31*F31) + (F41*F41) + (F51*F51) + (F61*F61) + (F71*F71) + (F81*F81) + (F91*F91)) + (1.0/8.0)*mu_i*(2*Ui_inv11*(F11*(2*F11*Ui_inv11 + F21*Ui_inv41 + F31*Ui_inv61) + F41*(2*F41*Ui_inv11 + F51*Ui_inv41 + F61*Ui_inv61) + F71*(2*F71*Ui_inv11 + F81*Ui_inv41 + F91*Ui_inv61)) + 2*Ui_inv21*(F21*(F11*Ui_inv41 + 2*F21*Ui_inv21 + F31*Ui_inv51) + F51*(F41*Ui_inv41 + 2*F51*Ui_inv21 + F61*Ui_inv51) + F81*(F71*Ui_inv41 + 2*F81*Ui_inv21 + F91*Ui_inv51)) + 2*Ui_inv31*(F31*(F11*Ui_inv61 + F21*Ui_inv51 + 2*F31*Ui_inv31) + F61*(F41*Ui_inv61 + F51*Ui_inv51 + 2*F61*Ui_inv31) + F91*(F71*Ui_inv61 + F81*Ui_inv51 + 2*F91*Ui_inv31)) + Ui_inv41*(F11*(F11*Ui_inv41 + 2*F21*Ui_inv21 + F31*Ui_inv51) + F41*(F41*Ui_inv41 + 2*F51*Ui_inv21 + F61*Ui_inv51) + F71*(F71*Ui_inv41 + 2*F81*Ui_inv21 + F91*Ui_inv51)) + Ui_inv41*(F21*(2*F11*Ui_inv11 + F21*Ui_inv41 + F31*Ui_inv61) + F51*(2*F41*Ui_inv11 + F51*Ui_inv41 + F61*Ui_inv61) + F81*(2*F71*Ui_inv11 + F81*Ui_inv41 + F91*Ui_inv61)) + Ui_inv51*(F21*(F11*Ui_inv61 + F21*Ui_inv51 + 2*F31*Ui_inv31) + F51*(F41*Ui_inv61 + F51*Ui_inv51 + 2*F61*Ui_inv31) + F81*(F71*Ui_inv61 + F81*Ui_inv51 + 2*F91*Ui_inv31)) + Ui_inv51*(F31*(F11*Ui_inv41 + 2*F21*Ui_inv21 + F31*Ui_inv51) + F61*(F41*Ui_inv41 + 2*F51*Ui_inv21 + F61*Ui_inv51) + F91*(F71*Ui_inv41 + 2*F81*Ui_inv21 + F91*Ui_inv51)) + Ui_inv61*(F11*(F11*Ui_inv61 + F21*Ui_inv51 + 2*F31*Ui_inv31) + F41*(F41*Ui_inv61 + F51*Ui_inv51 + 2*F61*Ui_inv31) + F71*(F71*Ui_inv61 + F81*Ui_inv51 + 2*F91*Ui_inv31)) + Ui_inv61*(F31*(2*F11*Ui_inv11 + F21*Ui_inv41 + F31*Ui_inv61) + F61*(2*F41*Ui_inv11 + F51*Ui_inv41 + F61*Ui_inv61) + F91*(2*F71*Ui_inv11 + F81*Ui_inv41 + F91*Ui_inv61)));
	}

	if(update_gradient)
	{
		gradient.resize(15);
		gradient(0) = F11*(Ui_inv11*Ui_inv11)*mu_i + (1.0/4.0)*F11*(Ui_inv41*Ui_inv41)*mu_i + (1.0/4.0)*F11*(Ui_inv61*Ui_inv61)*mu_i + F11*mu_e +(1.0/2.0)*F21*Ui_inv11*Ui_inv41*mu_i + (1.0/2.0)*F21*Ui_inv21*Ui_inv41*mu_i + (1.0/4.0)*F21*Ui_inv51*Ui_inv61*mu_i + (1.0/2.0)*F31*Ui_inv11*Ui_inv61*mu_i + (1.0/2.0)*F31*Ui_inv31*Ui_inv61*mu_i + (1.0/4.0)*F31*Ui_inv41*Ui_inv51*mu_i;
		gradient(1) = (1.0/2.0)*F11*Ui_inv11*Ui_inv41*mu_i + (1.0/2.0)*F11*Ui_inv21*Ui_inv41*mu_i + (1.0/4.0)*F11*Ui_inv51*Ui_inv61*mu_i + F21*(Ui_inv21*Ui_inv21)*mu_i + (1.0/4.0)*F21*(Ui_inv41*Ui_inv41)*mu_i + (1.0/4.0)*F21*(Ui_inv51*Ui_inv51)*mu_i + F21*mu_e + (1.0/2.0)*F31*Ui_inv21*Ui_inv51*mu_i + (1.0/2.0)*F31*Ui_inv31*Ui_inv51*mu_i + (1.0/4.0)*F31*Ui_inv41*Ui_inv61*mu_i;
		gradient(2) = (1.0/2.0)*F11*Ui_inv11*Ui_inv61*mu_i + (1.0/2.0)*F11*Ui_inv31*Ui_inv61*mu_i + (1.0/4.0)*F11*Ui_inv41*Ui_inv51*mu_i + (1.0/2.0)*F21*Ui_inv21*Ui_inv51*mu_i + (1.0/2.0)*F21*Ui_inv31*Ui_inv51*mu_i + (1.0/4.0)*F21*Ui_inv41*Ui_inv61*mu_i + F31*(Ui_inv31*Ui_inv31)*mu_i + (1.0/4.0)*F31*(Ui_inv51*Ui_inv51)*mu_i + (1.0/4.0)*F31*(Ui_inv61*Ui_inv61)*mu_i + F31*mu_e;
		gradient(3) = F41*(Ui_inv11*Ui_inv11)*mu_i + (1.0/4.0)*F41*(Ui_inv41*Ui_inv41)*mu_i + (1.0/4.0)*F41*(Ui_inv61*Ui_inv61)*mu_i + F41*mu_e +(1.0/2.0)*F51*Ui_inv11*Ui_inv41*mu_i + (1.0/2.0)*F51*Ui_inv21*Ui_inv41*mu_i + (1.0/4.0)*F51*Ui_inv51*Ui_inv61*mu_i + (1.0/2.0)*F61*Ui_inv11*Ui_inv61*mu_i + (1.0/2.0)*F61*Ui_inv31*Ui_inv61*mu_i + (1.0/4.0)*F61*Ui_inv41*Ui_inv51*mu_i;
		gradient(4) = (1.0/2.0)*F41*Ui_inv11*Ui_inv41*mu_i + (1.0/2.0)*F41*Ui_inv21*Ui_inv41*mu_i + (1.0/4.0)*F41*Ui_inv51*Ui_inv61*mu_i + F51*(Ui_inv21*Ui_inv21)*mu_i + (1.0/4.0)*F51*(Ui_inv41*Ui_inv41)*mu_i + (1.0/4.0)*F51*(Ui_inv51*Ui_inv51)*mu_i + F51*mu_e + (1.0/2.0)*F61*Ui_inv21*Ui_inv51*mu_i + (1.0/2.0)*F61*Ui_inv31*Ui_inv51*mu_i + (1.0/4.0)*F61*Ui_inv41*Ui_inv61*mu_i;
		gradient(5) = (1.0/2.0)*F41*Ui_inv11*Ui_inv61*mu_i + (1.0/2.0)*F41*Ui_inv31*Ui_inv61*mu_i + (1.0/4.0)*F41*Ui_inv41*Ui_inv51*mu_i + (1.0/2.0)*F51*Ui_inv21*Ui_inv51*mu_i + (1.0/2.0)*F51*Ui_inv31*Ui_inv51*mu_i + (1.0/4.0)*F51*Ui_inv41*Ui_inv61*mu_i + F61*(Ui_inv31*Ui_inv31)*mu_i + (1.0/4.0)*F61*(Ui_inv51*Ui_inv51)*mu_i + (1.0/4.0)*F61*(Ui_inv61*Ui_inv61)*mu_i + F61*mu_e;
		gradient(6) = F71*(Ui_inv11*Ui_inv11)*mu_i + (1.0/4.0)*F71*(Ui_inv41*Ui_inv41)*mu_i + (1.0/4.0)*F71*(Ui_inv61*Ui_inv61)*mu_i + F71*mu_e +(1.0/2.0)*F81*Ui_inv11*Ui_inv41*mu_i + (1.0/2.0)*F81*Ui_inv21*Ui_inv41*mu_i + (1.0/4.0)*F81*Ui_inv51*Ui_inv61*mu_i + (1.0/2.0)*F91*Ui_inv11*Ui_inv61*mu_i + (1.0/2.0)*F91*Ui_inv31*Ui_inv61*mu_i + (1.0/4.0)*F91*Ui_inv41*Ui_inv51*mu_i;
		gradient(7) = (1.0/2.0)*F71*Ui_inv11*Ui_inv41*mu_i + (1.0/2.0)*F71*Ui_inv21*Ui_inv41*mu_i + (1.0/4.0)*F71*Ui_inv51*Ui_inv61*mu_i + F81*(Ui_inv21*Ui_inv21)*mu_i + (1.0/4.0)*F81*(Ui_inv41*Ui_inv41)*mu_i + (1.0/4.0)*F81*(Ui_inv51*Ui_inv51)*mu_i + F81*mu_e + (1.0/2.0)*F91*Ui_inv21*Ui_inv51*mu_i + (1.0/2.0)*F91*Ui_inv31*Ui_inv51*mu_i + (1.0/4.0)*F91*Ui_inv41*Ui_inv61*mu_i;
		gradient(8) = (1.0/2.0)*F71*Ui_inv11*Ui_inv61*mu_i + (1.0/2.0)*F71*Ui_inv31*Ui_inv61*mu_i + (1.0/4.0)*F71*Ui_inv41*Ui_inv51*mu_i + (1.0/2.0)*F81*Ui_inv21*Ui_inv51*mu_i + (1.0/2.0)*F81*Ui_inv31*Ui_inv51*mu_i + (1.0/4.0)*F81*Ui_inv41*Ui_inv61*mu_i + F91*(Ui_inv31*Ui_inv31)*mu_i + (1.0/4.0)*F91*(Ui_inv51*Ui_inv51)*mu_i + (1.0/4.0)*F91*(Ui_inv61*Ui_inv61)*mu_i + F91*mu_e;
		gradient(9) = (1.0/2.0)*mu_i*(2*(F11*F11)*Ui_inv11 + F11*F21*Ui_inv41 + F11*F31*Ui_inv61 + 2*(F41*F41)*Ui_inv11 + F41*F51*Ui_inv41 + F41*F61*Ui_inv61 + 2*(F71*F71)*Ui_inv11 + F71*F81*Ui_inv41 + F71*F91*Ui_inv61);
		gradient(10) = (1.0/2.0)*mu_i*(F11*F21*Ui_inv41 + 2*(F21*F21)*Ui_inv21 + F21*F31*Ui_inv51 + F41*F51*Ui_inv41 + 2*(F51*F51)*Ui_inv21 + F51*F61*Ui_inv51 + F71*F81*Ui_inv41 + 2*(F81*F81)*Ui_inv21 + F81*F91*Ui_inv51);
		gradient(11) = (1.0/2.0)*mu_i*(F11*F31*Ui_inv61 + F21*F31*Ui_inv51 + 2*(F31*F31)*Ui_inv31 + F41*F61*Ui_inv61 + F51*F61*Ui_inv51 + 2*(F61*F61)*Ui_inv31 + F71*F91*Ui_inv61 + F81*F91*Ui_inv51 + 2*(F91*F91)*Ui_inv31);
		gradient(12) = (1.0/4.0)*mu_i*((F11*F11)*Ui_inv41 + 2*F11*F21*Ui_inv11 + 2*F11*F21*Ui_inv21 + F11*F31*Ui_inv51 + (F21*F21)*Ui_inv41 + F21*F31*Ui_inv61 + (F41*F41)*Ui_inv41 + 2*F41*F51*Ui_inv11 + 2*F41*F51*Ui_inv21 + F41*F61*Ui_inv51 + (F51*F51)*Ui_inv41 + F51*F61*Ui_inv61 + (F71*F71)*Ui_inv41 + 2*F71*F81*Ui_inv11 + 2*F71*F81*Ui_inv21 + F71*F91*Ui_inv51 + (F81*F81)*Ui_inv41 + F81*F91*Ui_inv61);
		gradient(13) = (1.0/4.0)*mu_i*(F11*F21*Ui_inv61 + F11*F31*Ui_inv41 + (F21*F21)*Ui_inv51 + 2*F21*F31*Ui_inv21 + 2*F21*F31*Ui_inv31 + (F31*F31)*Ui_inv51 + F41*F51*Ui_inv61 + F41*F61*Ui_inv41 + (F51*F51)*Ui_inv51 + 2*F51*F61*Ui_inv21 + 2*F51*F61*Ui_inv31 + (F61*F61)*Ui_inv51 + F71*F81*Ui_inv61 + F71*F91*Ui_inv41 + (F81*F81)*Ui_inv51 + 2*F81*F91*Ui_inv21 + 2*F81*F91*Ui_inv31 + (F91*F91)*Ui_inv51);
		gradient(14) = (1.0/4.0)*mu_i*((F11*F11)*Ui_inv61 + F11*F21*Ui_inv51 + 2*F11*F31*Ui_inv11 + 2*F11*F31*Ui_inv31 + F21*F31*Ui_inv41 + (F31*F31)*Ui_inv61 + (F41*F41)*Ui_inv61 + F41*F51*Ui_inv51 + 2*F41*F61*Ui_inv11 + 2*F41*F61*Ui_inv31 + F51*F61*Ui_inv41 + (F61*F61)*Ui_inv61 + (F71*F71)*Ui_inv61 + F71*F81*Ui_inv51 + 2*F71*F91*Ui_inv11 + 2*F71*F91*Ui_inv31 + F81*F91*Ui_inv41 + (F91*F91)*Ui_inv61);
	}

	if(update_hessian)
	{
		hessian.resize(15,15);
		hessian(0,0) = mu_e + (1.0/4.0)*mu_i*(4*(Ui_inv11*Ui_inv11) + (Ui_inv41*Ui_inv41) + (Ui_inv61*Ui_inv61));
		hessian(0,1) = hessian(1,0) = (1.0/4.0)*mu_i*(2*Ui_inv11*Ui_inv41 + 2*Ui_inv21*Ui_inv41 + Ui_inv51*Ui_inv61);
		hessian(0,2) = hessian(2,0) = (1.0/4.0)*mu_i*(2*Ui_inv11*Ui_inv61 + 2*Ui_inv31*Ui_inv61 + Ui_inv41*Ui_inv51);
		hessian(0,3) = hessian(3,0) = 0;
		hessian(0,4) = hessian(4,0) = 0;
		hessian(0,5) = hessian(5,0) = 0;
		hessian(0,6) = hessian(6,0) = 0;
		hessian(0,7) = hessian(7,0) = 0;
		hessian(0,8) = hessian(8,0) = 0;
		hessian(0,9) = hessian(9,0) = (1.0/2.0)*mu_i*(4*F11*Ui_inv11 + F21*Ui_inv41 + F31*Ui_inv61);
		hessian(0,10) = hessian(10,0) = (1.0/2.0)*F21*Ui_inv41*mu_i;
		hessian(0,11) = hessian(11,0) = (1.0/2.0)*F31*Ui_inv61*mu_i;
		hessian(0,12) = hessian(12,0) = (1.0/4.0)*mu_i*(2*F11*Ui_inv41 + 2*F21*Ui_inv11 + 2*F21*Ui_inv21 + F31*Ui_inv51);
		hessian(0,13) = hessian(13,0) = (1.0/4.0)*mu_i*(F21*Ui_inv61 + F31*Ui_inv41);
		hessian(0,14) = hessian(14,0) = (1.0/4.0)*mu_i*(2*F11*Ui_inv61 + F21*Ui_inv51 + 2*F31*Ui_inv11 + 2*F31*Ui_inv31);
		hessian(1,0) = hessian(0,1) = (1.0/4.0)*mu_i*(2*Ui_inv11*Ui_inv41 + 2*Ui_inv21*Ui_inv41 + Ui_inv51*Ui_inv61);
		hessian(1,1) = mu_e + (1.0/4.0)*mu_i*(4*(Ui_inv21*Ui_inv21) + (Ui_inv41*Ui_inv41) + (Ui_inv51*Ui_inv51));
		hessian(1,2) = hessian(2,1) = (1.0/4.0)*mu_i*(2*Ui_inv21*Ui_inv51 + 2*Ui_inv31*Ui_inv51 + Ui_inv41*Ui_inv61);
		hessian(1,3) = hessian(3,1) = 0;
		hessian(1,4) = hessian(4,1) = 0;
		hessian(1,5) = hessian(5,1) = 0;
		hessian(1,6) = hessian(6,1) = 0;
		hessian(1,7) = hessian(7,1) = 0;
		hessian(1,8) = hessian(8,1) = 0;
		hessian(1,9) = hessian(9,1) = (1.0/2.0)*F11*Ui_inv41*mu_i;
		hessian(1,10) = hessian(10,1) = (1.0/2.0)*mu_i*(F11*Ui_inv41 + 4*F21*Ui_inv21 + F31*Ui_inv51);
		hessian(1,11) = hessian(11,1) = (1.0/2.0)*F31*Ui_inv51*mu_i;
		hessian(1,12) = hessian(12,1) = (1.0/4.0)*mu_i*(2*F11*Ui_inv11 + 2*F11*Ui_inv21 + 2*F21*Ui_inv41 + F31*Ui_inv61);
		hessian(1,13) = hessian(13,1) = (1.0/4.0)*mu_i*(F11*Ui_inv61 + 2*F21*Ui_inv51 + 2*F31*Ui_inv21 + 2*F31*Ui_inv31);
		hessian(1,14) = hessian(14,1) = (1.0/4.0)*mu_i*(F11*Ui_inv51 + F31*Ui_inv41);
		hessian(2,0) = hessian(0,2) = (1.0/4.0)*mu_i*(2*Ui_inv11*Ui_inv61 + 2*Ui_inv31*Ui_inv61 + Ui_inv41*Ui_inv51);
		hessian(2,1) = hessian(1,2) = (1.0/4.0)*mu_i*(2*Ui_inv21*Ui_inv51 + 2*Ui_inv31*Ui_inv51 + Ui_inv41*Ui_inv61);
		hessian(2,2) = mu_e + (1.0/4.0)*mu_i*(4*(Ui_inv31*Ui_inv31) + (Ui_inv51*Ui_inv51) + (Ui_inv61*Ui_inv61));
		hessian(2,3) = hessian(3,2) = 0;
		hessian(2,4) = hessian(4,2) = 0;
		hessian(2,5) = hessian(5,2) = 0;
		hessian(2,6) = hessian(6,2) = 0;
		hessian(2,7) = hessian(7,2) = 0;
		hessian(2,8) = hessian(8,2) = 0;
		hessian(2,9) = hessian(9,2) = (1.0/2.0)*F11*Ui_inv61*mu_i;
		hessian(2,10) = hessian(10,2) = (1.0/2.0)*F21*Ui_inv51*mu_i;
		hessian(2,11) = hessian(11,2) = (1.0/2.0)*mu_i*(F11*Ui_inv61 + F21*Ui_inv51 + 4*F31*Ui_inv31);
		hessian(2,12) = hessian(12,2) = (1.0/4.0)*mu_i*(F11*Ui_inv51 + F21*Ui_inv61);
		hessian(2,13) = hessian(13,2) = (1.0/4.0)*mu_i*(F11*Ui_inv41 + 2*F21*Ui_inv21 + 2*F21*Ui_inv31 + 2*F31*Ui_inv51);
		hessian(2,14) = hessian(14,2) = (1.0/4.0)*mu_i*(2*F11*Ui_inv11 + 2*F11*Ui_inv31 + F21*Ui_inv41 + 2*F31*Ui_inv61);
		hessian(3,0) = hessian(0,3) = 0;
		hessian(3,1) = hessian(1,3) = 0;
		hessian(3,2) = hessian(2,3) = 0;
		hessian(3,3) = mu_e + (1.0/4.0)*mu_i*(4*(Ui_inv11*Ui_inv11) + (Ui_inv41*Ui_inv41) + (Ui_inv61*Ui_inv61));
		hessian(3,4) = hessian(4,3) = (1.0/4.0)*mu_i*(2*Ui_inv11*Ui_inv41 + 2*Ui_inv21*Ui_inv41 + Ui_inv51*Ui_inv61);
		hessian(3,5) = hessian(5,3) = (1.0/4.0)*mu_i*(2*Ui_inv11*Ui_inv61 + 2*Ui_inv31*Ui_inv61 + Ui_inv41*Ui_inv51);
		hessian(3,6) = hessian(6,3) = 0;
		hessian(3,7) = hessian(7,3) = 0;
		hessian(3,8) = hessian(8,3) = 0;
		hessian(3,9) = hessian(9,3) = (1.0/2.0)*mu_i*(4*F41*Ui_inv11 + F51*Ui_inv41 + F61*Ui_inv61);
		hessian(3,10) = hessian(10,3) = (1.0/2.0)*F51*Ui_inv41*mu_i;
		hessian(3,11) = hessian(11,3) = (1.0/2.0)*F61*Ui_inv61*mu_i;
		hessian(3,12) = hessian(12,3) = (1.0/4.0)*mu_i*(2*F41*Ui_inv41 + 2*F51*Ui_inv11 + 2*F51*Ui_inv21 + F61*Ui_inv51);
		hessian(3,13) = hessian(13,3) = (1.0/4.0)*mu_i*(F51*Ui_inv61 + F61*Ui_inv41);
		hessian(3,14) = hessian(14,3) = (1.0/4.0)*mu_i*(2*F41*Ui_inv61 + F51*Ui_inv51 + 2*F61*Ui_inv11 + 2*F61*Ui_inv31);
		hessian(4,0) = hessian(0,4) = 0;
		hessian(4,1) = hessian(1,4) = 0;
		hessian(4,2) = hessian(2,4) = 0;
		hessian(4,3) = hessian(3,4) = (1.0/4.0)*mu_i*(2*Ui_inv11*Ui_inv41 + 2*Ui_inv21*Ui_inv41 + Ui_inv51*Ui_inv61);
		hessian(4,4) = mu_e + (1.0/4.0)*mu_i*(4*(Ui_inv21*Ui_inv21) + (Ui_inv41*Ui_inv41) + (Ui_inv51*Ui_inv51));
		hessian(4,5) = hessian(5,4) = (1.0/4.0)*mu_i*(2*Ui_inv21*Ui_inv51 + 2*Ui_inv31*Ui_inv51 + Ui_inv41*Ui_inv61);
		hessian(4,6) = hessian(6,4) = 0;
		hessian(4,7) = hessian(7,4) = 0;
		hessian(4,8) = hessian(8,4) = 0;
		hessian(4,9) = hessian(9,4) = (1.0/2.0)*F41*Ui_inv41*mu_i;
		hessian(4,10) = hessian(10,4) = (1.0/2.0)*mu_i*(F41*Ui_inv41 + 4*F51*Ui_inv21 + F61*Ui_inv51);
		hessian(4,11) = hessian(11,4) = (1.0/2.0)*F61*Ui_inv51*mu_i;
		hessian(4,12) = hessian(12,4) = (1.0/4.0)*mu_i*(2*F41*Ui_inv11 + 2*F41*Ui_inv21 + 2*F51*Ui_inv41 + F61*Ui_inv61);
		hessian(4,13) = hessian(13,4) = (1.0/4.0)*mu_i*(F41*Ui_inv61 + 2*F51*Ui_inv51 + 2*F61*Ui_inv21 + 2*F61*Ui_inv31);
		hessian(4,14) = hessian(14,4) = (1.0/4.0)*mu_i*(F41*Ui_inv51 + F61*Ui_inv41);
		hessian(5,0) = hessian(0,5) = 0;
		hessian(5,1) = hessian(1,5) = 0;
		hessian(5,2) = hessian(2,5) = 0;
		hessian(5,3) = hessian(3,5) = (1.0/4.0)*mu_i*(2*Ui_inv11*Ui_inv61 + 2*Ui_inv31*Ui_inv61 + Ui_inv41*Ui_inv51);
		hessian(5,4) = hessian(4,5) = (1.0/4.0)*mu_i*(2*Ui_inv21*Ui_inv51 + 2*Ui_inv31*Ui_inv51 + Ui_inv41*Ui_inv61);
		hessian(5,5) = mu_e + (1.0/4.0)*mu_i*(4*(Ui_inv31*Ui_inv31) + (Ui_inv51*Ui_inv51) + (Ui_inv61*Ui_inv61));
		hessian(5,6) = hessian(6,5) = 0;
		hessian(5,7) = hessian(7,5) = 0;
		hessian(5,8) = hessian(8,5) = 0;
		hessian(5,9) = hessian(9,5) = (1.0/2.0)*F41*Ui_inv61*mu_i;
		hessian(5,10) = hessian(10,5) = (1.0/2.0)*F51*Ui_inv51*mu_i;
		hessian(5,11) = hessian(11,5) = (1.0/2.0)*mu_i*(F41*Ui_inv61 + F51*Ui_inv51 + 4*F61*Ui_inv31);
		hessian(5,12) = hessian(12,5) = (1.0/4.0)*mu_i*(F41*Ui_inv51 + F51*Ui_inv61);
		hessian(5,13) = hessian(13,5) = (1.0/4.0)*mu_i*(F41*Ui_inv41 + 2*F51*Ui_inv21 + 2*F51*Ui_inv31 + 2*F61*Ui_inv51);
		hessian(5,14) = hessian(14,5) = (1.0/4.0)*mu_i*(2*F41*Ui_inv11 + 2*F41*Ui_inv31 + F51*Ui_inv41 + 2*F61*Ui_inv61);
		hessian(6,0) = hessian(0,6) = 0;
		hessian(6,1) = hessian(1,6) = 0;
		hessian(6,2) = hessian(2,6) = 0;
		hessian(6,3) = hessian(3,6) = 0;
		hessian(6,4) = hessian(4,6) = 0;
		hessian(6,5) = hessian(5,6) = 0;
		hessian(6,6) = mu_e + (1.0/4.0)*mu_i*(4*(Ui_inv11*Ui_inv11) + (Ui_inv41*Ui_inv41) + (Ui_inv61*Ui_inv61));
		hessian(6,7) = hessian(7,6) = (1.0/4.0)*mu_i*(2*Ui_inv11*Ui_inv41 + 2*Ui_inv21*Ui_inv41 + Ui_inv51*Ui_inv61);
		hessian(6,8) = hessian(8,6) = (1.0/4.0)*mu_i*(2*Ui_inv11*Ui_inv61 + 2*Ui_inv31*Ui_inv61 + Ui_inv41*Ui_inv51);
		hessian(6,9) = hessian(9,6) = (1.0/2.0)*mu_i*(4*F71*Ui_inv11 + F81*Ui_inv41 + F91*Ui_inv61);
		hessian(6,10) = hessian(10,6) = (1.0/2.0)*F81*Ui_inv41*mu_i;
		hessian(6,11) = hessian(11,6) = (1.0/2.0)*F91*Ui_inv61*mu_i;
		hessian(6,12) = hessian(12,6) = (1.0/4.0)*mu_i*(2*F71*Ui_inv41 + 2*F81*Ui_inv11 + 2*F81*Ui_inv21 + F91*Ui_inv51);
		hessian(6,13) = hessian(13,6) = (1.0/4.0)*mu_i*(F81*Ui_inv61 + F91*Ui_inv41);
		hessian(6,14) = hessian(14,6) = (1.0/4.0)*mu_i*(2*F71*Ui_inv61 + F81*Ui_inv51 + 2*F91*Ui_inv11 + 2*F91*Ui_inv31);
		hessian(7,0) = hessian(0,7) = 0;
		hessian(7,1) = hessian(1,7) = 0;
		hessian(7,2) = hessian(2,7) = 0;
		hessian(7,3) = hessian(3,7) = 0;
		hessian(7,4) = hessian(4,7) = 0;
		hessian(7,5) = hessian(5,7) = 0;
		hessian(7,6) = hessian(6,7) = (1.0/4.0)*mu_i*(2*Ui_inv11*Ui_inv41 + 2*Ui_inv21*Ui_inv41 + Ui_inv51*Ui_inv61);
		hessian(7,7) = mu_e + (1.0/4.0)*mu_i*(4*(Ui_inv21*Ui_inv21) + (Ui_inv41*Ui_inv41) + (Ui_inv51*Ui_inv51));
		hessian(7,8) = hessian(8,7) = (1.0/4.0)*mu_i*(2*Ui_inv21*Ui_inv51 + 2*Ui_inv31*Ui_inv51 + Ui_inv41*Ui_inv61);
		hessian(7,9) = hessian(9,7) = (1.0/2.0)*F71*Ui_inv41*mu_i;
		hessian(7,10) = hessian(10,7) = (1.0/2.0)*mu_i*(F71*Ui_inv41 + 4*F81*Ui_inv21 + F91*Ui_inv51);
		hessian(7,11) = hessian(11,7) = (1.0/2.0)*F91*Ui_inv51*mu_i;
		hessian(7,12) = hessian(12,7) = (1.0/4.0)*mu_i*(2*F71*Ui_inv11 + 2*F71*Ui_inv21 + 2*F81*Ui_inv41 + F91*Ui_inv61);
		hessian(7,13) = hessian(13,7) = (1.0/4.0)*mu_i*(F71*Ui_inv61 + 2*F81*Ui_inv51 + 2*F91*Ui_inv21 + 2*F91*Ui_inv31);
		hessian(7,14) = hessian(14,7) = (1.0/4.0)*mu_i*(F71*Ui_inv51 + F91*Ui_inv41);
		hessian(8,0) = hessian(0,8) = 0;
		hessian(8,1) = hessian(1,8) = 0;
		hessian(8,2) = hessian(2,8) = 0;
		hessian(8,3) = hessian(3,8) = 0;
		hessian(8,4) = hessian(4,8) = 0;
		hessian(8,5) = hessian(5,8) = 0;
		hessian(8,6) = hessian(6,8) = (1.0/4.0)*mu_i*(2*Ui_inv11*Ui_inv61 + 2*Ui_inv31*Ui_inv61 + Ui_inv41*Ui_inv51);
		hessian(8,7) = hessian(7,8) = (1.0/4.0)*mu_i*(2*Ui_inv21*Ui_inv51 + 2*Ui_inv31*Ui_inv51 + Ui_inv41*Ui_inv61);
		hessian(8,8) = mu_e + (1.0/4.0)*mu_i*(4*(Ui_inv31*Ui_inv31) + (Ui_inv51*Ui_inv51) + (Ui_inv61*Ui_inv61));
		hessian(8,9) = hessian(9,8) = (1.0/2.0)*F71*Ui_inv61*mu_i;
		hessian(8,10) = hessian(10,8) = (1.0/2.0)*F81*Ui_inv51*mu_i;
		hessian(8,11) = hessian(11,8) = (1.0/2.0)*mu_i*(F71*Ui_inv61 + F81*Ui_inv51 + 4*F91*Ui_inv31);
		hessian(8,12) = hessian(12,8) = (1.0/4.0)*mu_i*(F71*Ui_inv51 + F81*Ui_inv61);
		hessian(8,13) = hessian(13,8) = (1.0/4.0)*mu_i*(F71*Ui_inv41 + 2*F81*Ui_inv21 + 2*F81*Ui_inv31 + 2*F91*Ui_inv51);
		hessian(8,14) = hessian(14,8) = (1.0/4.0)*mu_i*(2*F71*Ui_inv11 + 2*F71*Ui_inv31 + F81*Ui_inv41 + 2*F91*Ui_inv61);
		hessian(9,0) = hessian(0,9) = (1.0/2.0)*mu_i*(4*F11*Ui_inv11 + F21*Ui_inv41 + F31*Ui_inv61);
		hessian(9,1) = hessian(1,9) = (1.0/2.0)*F11*Ui_inv41*mu_i;
		hessian(9,2) = hessian(2,9) = (1.0/2.0)*F11*Ui_inv61*mu_i;
		hessian(9,3) = hessian(3,9) = (1.0/2.0)*mu_i*(4*F41*Ui_inv11 + F51*Ui_inv41 + F61*Ui_inv61);
		hessian(9,4) = hessian(4,9) = (1.0/2.0)*F41*Ui_inv41*mu_i;
		hessian(9,5) = hessian(5,9) = (1.0/2.0)*F41*Ui_inv61*mu_i;
		hessian(9,6) = hessian(6,9) = (1.0/2.0)*mu_i*(4*F71*Ui_inv11 + F81*Ui_inv41 + F91*Ui_inv61);
		hessian(9,7) = hessian(7,9) = (1.0/2.0)*F71*Ui_inv41*mu_i;
		hessian(9,8) = hessian(8,9) = (1.0/2.0)*F71*Ui_inv61*mu_i;
		hessian(9,9) = mu_i*((F11*F11) + (F41*F41) + (F71*F71));
		hessian(9,10) = hessian(10,9) = 0;
		hessian(9,11) = hessian(11,9) = 0;
		hessian(9,12) = hessian(12,9) = (1.0/2.0)*mu_i*(F11*F21 + F41*F51 + F71*F81);
		hessian(9,13) = hessian(13,9) = 0;
		hessian(9,14) = hessian(14,9) = (1.0/2.0)*mu_i*(F11*F31 + F41*F61 + F71*F91);
		hessian(10,0) = hessian(0,10) = (1.0/2.0)*F21*Ui_inv41*mu_i;
		hessian(10,1) = hessian(1,10) = (1.0/2.0)*mu_i*(F11*Ui_inv41 + 4*F21*Ui_inv21 + F31*Ui_inv51);
		hessian(10,2) = hessian(2,10) = (1.0/2.0)*F21*Ui_inv51*mu_i;
		hessian(10,3) = hessian(3,10) = (1.0/2.0)*F51*Ui_inv41*mu_i;
		hessian(10,4) = hessian(4,10) = (1.0/2.0)*mu_i*(F41*Ui_inv41 + 4*F51*Ui_inv21 + F61*Ui_inv51);
		hessian(10,5) = hessian(5,10) = (1.0/2.0)*F51*Ui_inv51*mu_i;
		hessian(10,6) = hessian(6,10) = (1.0/2.0)*F81*Ui_inv41*mu_i;
		hessian(10,7) = hessian(7,10) = (1.0/2.0)*mu_i*(F71*Ui_inv41 + 4*F81*Ui_inv21 + F91*Ui_inv51);
		hessian(10,8) = hessian(8,10) = (1.0/2.0)*F81*Ui_inv51*mu_i;
		hessian(10,9) = hessian(9,10) = 0;
		hessian(10,10) = mu_i*((F21*F21) + (F51*F51) + (F81*F81));
		hessian(10,11) = hessian(11,10) = 0;
		hessian(10,12) = hessian(12,10) = (1.0/2.0)*mu_i*(F11*F21 + F41*F51 + F71*F81);
		hessian(10,13) = hessian(13,10) = (1.0/2.0)*mu_i*(F21*F31 + F51*F61 + F81*F91);
		hessian(10,14) = hessian(14,10) = 0;
		hessian(11,0) = hessian(0,11) = (1.0/2.0)*F31*Ui_inv61*mu_i;
		hessian(11,1) = hessian(1,11) = (1.0/2.0)*F31*Ui_inv51*mu_i;
		hessian(11,2) = hessian(2,11) = (1.0/2.0)*mu_i*(F11*Ui_inv61 + F21*Ui_inv51 + 4*F31*Ui_inv31);
		hessian(11,3) = hessian(3,11) = (1.0/2.0)*F61*Ui_inv61*mu_i;
		hessian(11,4) = hessian(4,11) = (1.0/2.0)*F61*Ui_inv51*mu_i;
		hessian(11,5) = hessian(5,11) = (1.0/2.0)*mu_i*(F41*Ui_inv61 + F51*Ui_inv51 + 4*F61*Ui_inv31);
		hessian(11,6) = hessian(6,11) = (1.0/2.0)*F91*Ui_inv61*mu_i;
		hessian(11,7) = hessian(7,11) = (1.0/2.0)*F91*Ui_inv51*mu_i;
		hessian(11,8) = hessian(8,11) = (1.0/2.0)*mu_i*(F71*Ui_inv61 + F81*Ui_inv51 + 4*F91*Ui_inv31);
		hessian(11,9) = hessian(9,11) = 0;
		hessian(11,10) = hessian(10,11) = 0;
		hessian(11,11) = mu_i*((F31*F31) + (F61*F61) + (F91*F91));
		hessian(11,12) = hessian(12,11) = 0;
		hessian(11,13) = hessian(13,11) = (1.0/2.0)*mu_i*(F21*F31 + F51*F61 + F81*F91);
		hessian(11,14) = hessian(14,11) = (1.0/2.0)*mu_i*(F11*F31 + F41*F61 + F71*F91);
		hessian(12,0) = hessian(0,12) = (1.0/4.0)*mu_i*(2*F11*Ui_inv41 + 2*F21*Ui_inv11 + 2*F21*Ui_inv21 + F31*Ui_inv51);
		hessian(12,1) = hessian(1,12) = (1.0/4.0)*mu_i*(2*F11*Ui_inv11 + 2*F11*Ui_inv21 + 2*F21*Ui_inv41 + F31*Ui_inv61);
		hessian(12,2) = hessian(2,12) = (1.0/4.0)*mu_i*(F11*Ui_inv51 + F21*Ui_inv61);
		hessian(12,3) = hessian(3,12) = (1.0/4.0)*mu_i*(2*F41*Ui_inv41 + 2*F51*Ui_inv11 + 2*F51*Ui_inv21 + F61*Ui_inv51);
		hessian(12,4) = hessian(4,12) = (1.0/4.0)*mu_i*(2*F41*Ui_inv11 + 2*F41*Ui_inv21 + 2*F51*Ui_inv41 + F61*Ui_inv61);
		hessian(12,5) = hessian(5,12) = (1.0/4.0)*mu_i*(F41*Ui_inv51 + F51*Ui_inv61);
		hessian(12,6) = hessian(6,12) = (1.0/4.0)*mu_i*(2*F71*Ui_inv41 + 2*F81*Ui_inv11 + 2*F81*Ui_inv21 + F91*Ui_inv51);
		hessian(12,7) = hessian(7,12) = (1.0/4.0)*mu_i*(2*F71*Ui_inv11 + 2*F71*Ui_inv21 + 2*F81*Ui_inv41 + F91*Ui_inv61);
		hessian(12,8) = hessian(8,12) = (1.0/4.0)*mu_i*(F71*Ui_inv51 + F81*Ui_inv61);
		hessian(12,9) = hessian(9,12) = (1.0/2.0)*mu_i*(F11*F21 + F41*F51 + F71*F81);
		hessian(12,10) = hessian(10,12) = (1.0/2.0)*mu_i*(F11*F21 + F41*F51 + F71*F81);
		hessian(12,11) = hessian(11,12) = 0;
		hessian(12,12) = (1.0/4.0)*mu_i*((F11*F11) + (F21*F21) + (F41*F41) + (F51*F51) + (F71*F71) + (F81*F81));
		hessian(12,13) = hessian(13,12) = (1.0/4.0)*mu_i*(F11*F31 + F41*F61 + F71*F91);
		hessian(12,14) = hessian(14,12) = (1.0/4.0)*mu_i*(F21*F31 + F51*F61 + F81*F91);
		hessian(13,0) = hessian(0,13) = (1.0/4.0)*mu_i*(F21*Ui_inv61 + F31*Ui_inv41);
		hessian(13,1) = hessian(1,13) = (1.0/4.0)*mu_i*(F11*Ui_inv61 + 2*F21*Ui_inv51 + 2*F31*Ui_inv21 + 2*F31*Ui_inv31);
		hessian(13,2) = hessian(2,13) = (1.0/4.0)*mu_i*(F11*Ui_inv41 + 2*F21*Ui_inv21 + 2*F21*Ui_inv31 + 2*F31*Ui_inv51);
		hessian(13,3) = hessian(3,13) = (1.0/4.0)*mu_i*(F51*Ui_inv61 + F61*Ui_inv41);
		hessian(13,4) = hessian(4,13) = (1.0/4.0)*mu_i*(F41*Ui_inv61 + 2*F51*Ui_inv51 + 2*F61*Ui_inv21 + 2*F61*Ui_inv31);
		hessian(13,5) = hessian(5,13) = (1.0/4.0)*mu_i*(F41*Ui_inv41 + 2*F51*Ui_inv21 + 2*F51*Ui_inv31 + 2*F61*Ui_inv51);
		hessian(13,6) = hessian(6,13) = (1.0/4.0)*mu_i*(F81*Ui_inv61 + F91*Ui_inv41);
		hessian(13,7) = hessian(7,13) = (1.0/4.0)*mu_i*(F71*Ui_inv61 + 2*F81*Ui_inv51 + 2*F91*Ui_inv21 + 2*F91*Ui_inv31);
		hessian(13,8) = hessian(8,13) = (1.0/4.0)*mu_i*(F71*Ui_inv41 + 2*F81*Ui_inv21 + 2*F81*Ui_inv31 + 2*F91*Ui_inv51);
		hessian(13,9) = hessian(9,13) = 0;
		hessian(13,10) = hessian(10,13) = (1.0/2.0)*mu_i*(F21*F31 + F51*F61 + F81*F91);
		hessian(13,11) = hessian(11,13) = (1.0/2.0)*mu_i*(F21*F31 + F51*F61 + F81*F91);
		hessian(13,12) = hessian(12,13) = (1.0/4.0)*mu_i*(F11*F31 + F41*F61 + F71*F91);
		hessian(13,13) = (1.0/4.0)*mu_i*((F21*F21) + (F31*F31) + (F51*F51) + (F61*F61) + (F81*F81) + (F91*F91));
		hessian(13,14) = hessian(14,13) = (1.0/4.0)*mu_i*(F11*F21 + F41*F51 + F71*F81);
		hessian(14,0) = hessian(0,14) = (1.0/4.0)*mu_i*(2*F11*Ui_inv61 + F21*Ui_inv51 + 2*F31*Ui_inv11 + 2*F31*Ui_inv31);
		hessian(14,1) = hessian(1,14) = (1.0/4.0)*mu_i*(F11*Ui_inv51 + F31*Ui_inv41);
		hessian(14,2) = hessian(2,14) = (1.0/4.0)*mu_i*(2*F11*Ui_inv11 + 2*F11*Ui_inv31 + F21*Ui_inv41 + 2*F31*Ui_inv61);
		hessian(14,3) = hessian(3,14) = (1.0/4.0)*mu_i*(2*F41*Ui_inv61 + F51*Ui_inv51 + 2*F61*Ui_inv11 + 2*F61*Ui_inv31);
		hessian(14,4) = hessian(4,14) = (1.0/4.0)*mu_i*(F41*Ui_inv51 + F61*Ui_inv41);
		hessian(14,5) = hessian(5,14) = (1.0/4.0)*mu_i*(2*F41*Ui_inv11 + 2*F41*Ui_inv31 + F51*Ui_inv41 + 2*F61*Ui_inv61);
		hessian(14,6) = hessian(6,14) = (1.0/4.0)*mu_i*(2*F71*Ui_inv61 + F81*Ui_inv51 + 2*F91*Ui_inv11 + 2*F91*Ui_inv31);
		hessian(14,7) = hessian(7,14) = (1.0/4.0)*mu_i*(F71*Ui_inv51 + F91*Ui_inv41);
		hessian(14,8) = hessian(8,14) = (1.0/4.0)*mu_i*(2*F71*Ui_inv11 + 2*F71*Ui_inv31 + F81*Ui_inv41 + 2*F91*Ui_inv61);
		hessian(14,9) = hessian(9,14) = (1.0/2.0)*mu_i*(F11*F31 + F41*F61 + F71*F91);
		hessian(14,10) = hessian(10,14) = 0;
		hessian(14,11) = hessian(11,14) = (1.0/2.0)*mu_i*(F11*F31 + F41*F61 + F71*F91);
		hessian(14,12) = hessian(12,14) = (1.0/4.0)*mu_i*(F21*F31 + F51*F61 + F81*F91);
		hessian(14,13) = hessian(13,14) = (1.0/4.0)*mu_i*(F11*F21 + F41*F51 + F71*F81);
		hessian(14,14) = (1.0/4.0)*mu_i*((F11*F11) + (F31*F31) + (F41*F41) + (F61*F61) + (F71*F71) + (F91*F91));
	}

	return false;
}

/////////////
// PsiElec //
/////////////

PsiElec::PsiElec(	const VariableSet	argument_set,
					const VariableSet	parameter_set,
					const double		epsilon)
:
ScalarFunction<double, VectorXd, MatrixXd, VectorXd, VectorXd>(argument_set, parameter_set),
epsilon(epsilon)
{
}

bool
PsiElec::compute(	double&		value,
					VectorXd&	gradient,
					MatrixXd&	hessian,
					const bool	update_value,
					const bool	update_gradient,
					const bool	update_hessian)
{
	const double E11 = get_arguments()[0];
	const double E21 = get_arguments()[1];
	const double E31 = get_arguments()[2];
	const double F_inv11 = get_arguments()[3];
	const double F_inv21 = get_arguments()[4];
	const double F_inv31 = get_arguments()[5];
	const double F_inv41 = get_arguments()[6];
	const double F_inv51 = get_arguments()[7];
	const double F_inv61 = get_arguments()[8];
	const double F_inv71 = get_arguments()[9];
	const double F_inv81 = get_arguments()[10];
	const double F_inv91 = get_arguments()[11];

	if(update_value)
	{
		value = -1.0/2.0*(E11*(F_inv11*(E11*F_inv11 + E21*F_inv41 + E31*F_inv71) + F_inv21*(E11*F_inv21 + E21*F_inv51 + E31*F_inv81) + F_inv31*(E11*F_inv31 + E21*F_inv61 + E31*F_inv91)) + E21*(F_inv41*(E11*F_inv11 + E21*F_inv41 + E31*F_inv71) + F_inv51*(E11*F_inv21 + E21*F_inv51 + E31*F_inv81) + F_inv61*(E11*F_inv31 + E21*F_inv61 + E31*F_inv91)) + E31*(F_inv71*(E11*F_inv11 + E21*F_inv41 + E31*F_inv71) + F_inv81*(E11*F_inv21 + E21*F_inv51 + E31*F_inv81) + F_inv91*(E11*F_inv31 + E21*F_inv61 + E31*F_inv91)))/epsilon;
	}

	if(update_gradient)
	{
		gradient.resize(12);
		gradient(0) = -(E11*(F_inv11*F_inv11) + E11*(F_inv21*F_inv21) + E11*(F_inv31*F_inv31) + E21*F_inv11*F_inv41 + E21*F_inv21*F_inv51 + E21*F_inv31*F_inv61 + E31*F_inv11*F_inv71 + E31*F_inv21*F_inv81 + E31*F_inv31*F_inv91)/epsilon;
		gradient(1) = -(E11*F_inv11*F_inv41 + E11*F_inv21*F_inv51 + E11*F_inv31*F_inv61 + E21*(F_inv41*F_inv41) + E21*(F_inv51*F_inv51) + E21*(F_inv61*F_inv61) + E31*F_inv41*F_inv71 + E31*F_inv51*F_inv81 + E31*F_inv61*F_inv91)/epsilon;
		gradient(2) = -(E11*F_inv11*F_inv71 + E11*F_inv21*F_inv81 + E11*F_inv31*F_inv91 + E21*F_inv41*F_inv71 + E21*F_inv51*F_inv81 + E21*F_inv61*F_inv91 + E31*(F_inv71*F_inv71) + E31*(F_inv81*F_inv81) + E31*(F_inv91*F_inv91))/epsilon;
		gradient(3) = -E11*(E11*F_inv11 + E21*F_inv41 + E31*F_inv71)/epsilon;
		gradient(4) = -E11*(E11*F_inv21 + E21*F_inv51 + E31*F_inv81)/epsilon;
		gradient(5) = -E11*(E11*F_inv31 + E21*F_inv61 + E31*F_inv91)/epsilon;
		gradient(6) = -E21*(E11*F_inv11 + E21*F_inv41 + E31*F_inv71)/epsilon;
		gradient(7) = -E21*(E11*F_inv21 + E21*F_inv51 + E31*F_inv81)/epsilon;
		gradient(8) = -E21*(E11*F_inv31 + E21*F_inv61 + E31*F_inv91)/epsilon;
		gradient(9) = -E31*(E11*F_inv11 + E21*F_inv41 + E31*F_inv71)/epsilon;
		gradient(10) = -E31*(E11*F_inv21 + E21*F_inv51 + E31*F_inv81)/epsilon;
		gradient(11) = -E31*(E11*F_inv31 + E21*F_inv61 + E31*F_inv91)/epsilon;
	}

	if(update_hessian)
	{
		hessian.resize(12,12);
		hessian(0,0) = -((F_inv11*F_inv11) + (F_inv21*F_inv21) + (F_inv31*F_inv31))/epsilon;
		hessian(0,1) = hessian(1,0) = -(F_inv11*F_inv41 + F_inv21*F_inv51 + F_inv31*F_inv61)/epsilon;
		hessian(0,2) = hessian(2,0) = -(F_inv11*F_inv71 + F_inv21*F_inv81 + F_inv31*F_inv91)/epsilon;
		hessian(0,3) = hessian(3,0) = -(2*E11*F_inv11 + E21*F_inv41 + E31*F_inv71)/epsilon;
		hessian(0,4) = hessian(4,0) = -(2*E11*F_inv21 + E21*F_inv51 + E31*F_inv81)/epsilon;
		hessian(0,5) = hessian(5,0) = -(2*E11*F_inv31 + E21*F_inv61 + E31*F_inv91)/epsilon;
		hessian(0,6) = hessian(6,0) = -E21*F_inv11/epsilon;
		hessian(0,7) = hessian(7,0) = -E21*F_inv21/epsilon;
		hessian(0,8) = hessian(8,0) = -E21*F_inv31/epsilon;
		hessian(0,9) = hessian(9,0) = -E31*F_inv11/epsilon;
		hessian(0,10) = hessian(10,0) = -E31*F_inv21/epsilon;
		hessian(0,11) = hessian(11,0) = -E31*F_inv31/epsilon;
		hessian(1,1) = -((F_inv41*F_inv41) + (F_inv51*F_inv51) + (F_inv61*F_inv61))/epsilon;
		hessian(1,2) = hessian(2,1) = -(F_inv41*F_inv71 + F_inv51*F_inv81 + F_inv61*F_inv91)/epsilon;
		hessian(1,3) = hessian(3,1) = -E11*F_inv41/epsilon;
		hessian(1,4) = hessian(4,1) = -E11*F_inv51/epsilon;
		hessian(1,5) = hessian(5,1) = -E11*F_inv61/epsilon;
		hessian(1,6) = hessian(6,1) = -(E11*F_inv11 + 2*E21*F_inv41 + E31*F_inv71)/epsilon;
		hessian(1,7) = hessian(7,1) = -(E11*F_inv21 + 2*E21*F_inv51 + E31*F_inv81)/epsilon;
		hessian(1,8) = hessian(8,1) = -(E11*F_inv31 + 2*E21*F_inv61 + E31*F_inv91)/epsilon;
		hessian(1,9) = hessian(9,1) = -E31*F_inv41/epsilon;
		hessian(1,10) = hessian(10,1) = -E31*F_inv51/epsilon;
		hessian(1,11) = hessian(11,1) = -E31*F_inv61/epsilon;
		hessian(2,2) = -((F_inv71*F_inv71) + (F_inv81*F_inv81) + (F_inv91*F_inv91))/epsilon;
		hessian(2,3) = hessian(3,2) = -E11*F_inv71/epsilon;
		hessian(2,4) = hessian(4,2) = -E11*F_inv81/epsilon;
		hessian(2,5) = hessian(5,2) = -E11*F_inv91/epsilon;
		hessian(2,6) = hessian(6,2) = -E21*F_inv71/epsilon;
		hessian(2,7) = hessian(7,2) = -E21*F_inv81/epsilon;
		hessian(2,8) = hessian(8,2) = -E21*F_inv91/epsilon;
		hessian(2,9) = hessian(9,2) = -(E11*F_inv11 + E21*F_inv41 + 2*E31*F_inv71)/epsilon;
		hessian(2,10) = hessian(10,2) = -(E11*F_inv21 + E21*F_inv51 + 2*E31*F_inv81)/epsilon;
		hessian(2,11) = hessian(11,2) = -(E11*F_inv31 + E21*F_inv61 + 2*E31*F_inv91)/epsilon;
		hessian(3,3) = -(E11*E11)/epsilon;
		hessian(3,4) = hessian(4,3) = 0;
		hessian(3,5) = hessian(5,3) = 0;
		hessian(3,6) = hessian(6,3) = -E11*E21/epsilon;
		hessian(3,7) = hessian(7,3) = 0;
		hessian(3,8) = hessian(8,3) = 0;
		hessian(3,9) = hessian(9,3) = -E11*E31/epsilon;
		hessian(3,10) = hessian(10,3) = 0;
		hessian(3,11) = hessian(11,3) = 0;
		hessian(4,4) = -(E11*E11)/epsilon;
		hessian(4,5) = hessian(5,4) = 0;
		hessian(4,6) = hessian(6,4) = 0;
		hessian(4,7) = hessian(7,4) = -E11*E21/epsilon;
		hessian(4,8) = hessian(8,4) = 0;
		hessian(4,9) = hessian(9,4) = 0;
		hessian(4,10) = hessian(10,4) = -E11*E31/epsilon;
		hessian(4,11) = hessian(11,4) = 0;
		hessian(5,5) = -(E11*E11)/epsilon;
		hessian(5,6) = hessian(6,5) = 0;
		hessian(5,7) = hessian(7,5) = 0;
		hessian(5,8) = hessian(8,5) = -E11*E21/epsilon;
		hessian(5,9) = hessian(9,5) = 0;
		hessian(5,10) = hessian(10,5) = 0;
		hessian(5,11) = hessian(11,5) = -E11*E31/epsilon;
		hessian(6,6) = -(E21*E21)/epsilon;
		hessian(6,7) = hessian(7,6) = 0;
		hessian(6,8) = hessian(8,6) = 0;
		hessian(6,9) = hessian(9,6) = -E21*E31/epsilon;
		hessian(6,10) = hessian(10,6) = 0;
		hessian(6,11) = hessian(11,6) = 0;
		hessian(7,7) = -(E21*E21)/epsilon;
		hessian(7,8) = hessian(8,7) = 0;
		hessian(7,9) = hessian(9,7) = 0;
		hessian(7,10) = hessian(10,7) = -E21*E31/epsilon;
		hessian(7,11) = hessian(11,7) = 0;
		hessian(8,8) = -(E21*E21)/epsilon;
		hessian(8,9) = hessian(9,8) = 0;
		hessian(8,10) = hessian(10,8) = 0;
		hessian(8,11) = hessian(11,8) = -E21*E31/epsilon;
		hessian(9,9) = -(E31*E31)/epsilon;
		hessian(9,10) = hessian(10,9) = 0;
		hessian(9,11) = hessian(11,9) = 0;
		hessian(10,10) = -(E31*E31)/epsilon;
		hessian(10,11) = hessian(11,10) = 0;
		hessian(11,11) = -(E31*E31)/epsilon;
	}

	return false;
}

/////////////
// PsiSurf //
/////////////

PsiSurf::PsiSurf(	const VariableSet	argument_set,
					const VariableSet	parameter_set,
					const double		lambda_S,
					const double		mu_S)
:
ScalarFunction<double, VectorXd, MatrixXd, VectorXd, VectorXd>(argument_set, parameter_set),
lambda_S(lambda_S),
mu_S(mu_S)
{
}

bool
PsiSurf::compute(	double&		value,
					VectorXd&	gradient,
					MatrixXd&	hessian,
					const bool	update_value,
					const bool	update_gradient,
					const bool	update_hessian)
{
	const double n11 = get_parameters()[0];
	const double n21 = get_parameters()[1];
	const double n31 = get_parameters()[2];

	const double a11 = 1.0 - n11*n11;
	const double a21 = 1.0 - n21*n21;
	const double a31 = 1.0 - n31*n31;
	const double a41 = -n11 * n21;
	const double a51 = -n21 * n31;
	const double a61 = -n31 * n11;

	const double grad_u11 = get_arguments()[0];
	const double grad_u21 = get_arguments()[1];
	const double grad_u31 = get_arguments()[2];
	const double grad_u41 = get_arguments()[3];
	const double grad_u51 = get_arguments()[4];
	const double grad_u61 = get_arguments()[5];
	const double grad_u71 = get_arguments()[6];
	const double grad_u81 = get_arguments()[7];
	const double grad_u91 = get_arguments()[8];

	if(update_value)
	{
		value = (1.0/8.0)*lambda_S*((((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2)*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 +grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2)) - 1.0/4.0*mu_S*(2*((a11 + grad_u11)*(a11 + grad_u11)) + 2*((a21 + grad_u51)*(a21 + grad_u51)) + 2*((a31 + grad_u91)*(a31 + grad_u91)) + 2*((a41 + grad_u21)*(a41 + grad_u21)) + 2*((a41 + grad_u41)*(a41 + grad_u41)) + 2*((a51 + grad_u61)*(a51 + grad_u61)) + 2*((a51 + grad_u81)*(a51 + grad_u81)) + 2*((a61 + grad_u31)*(a61 + grad_u31)) + 2*((a61 + grad_u71)*(a61 + grad_u71)) - 2*(((a11 + grad_u11)*(a41 + grad_u21) + (a21 + grad_u51)*(a41 + grad_u41) + (a51 + grad_u81)*(a61 + grad_u71))*((a11 + grad_u11)*(a41 + grad_u21) + (a21 + grad_u51)*(a41 + grad_u41) + (a51 + grad_u81)*(a61 + grad_u71))) - 2*(((a11 + grad_u11)*(a61 + grad_u31) + (a31 + grad_u91)*(a61 + grad_u71) + (a41 + grad_u41)*(a51 + grad_u61))*((a11 + grad_u11)*(a61 + grad_u31) + (a31 + grad_u91)*(a61 + grad_u71) + (a41 + grad_u41)*(a51 + grad_u61))) - 2*(((a21 + grad_u51)*(a51 + grad_u61) + (a31 + grad_u91)*(a51 + grad_u81) + (a41 + grad_u21)*(a61 + grad_u31))*((a21 + grad_u51)*(a51 + grad_u61) + (a31 + grad_u91)*(a51 + grad_u81) + (a41 + grad_u21)*(a61 + grad_u31))) - ((((a11 + grad_u11)*(a11 + grad_u11)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a61 + grad_u71)*(a61 + grad_u71)))*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a61 + grad_u71)*(a61 + grad_u71)))) - ((((a21 + grad_u51)*(a21 + grad_u51)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a51 + grad_u81)*(a51 + grad_u81)))*(((a21 + grad_u51)*(a21 + grad_u51)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a51 + grad_u81)*(a51 + grad_u81)))) - ((((a31 + grad_u91)*(a31 + grad_u91)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a61 + grad_u31)*(a61 + grad_u31)))*(((a31 + grad_u91)*(a31 + grad_u91)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a61 + grad_u31)*(a61 + grad_u31)))) - 2);
	}

	if(update_gradient)
	{
		gradient.resize(9);
		gradient(0) = (1.0/2.0)*lambda_S*(a11 + grad_u11)*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(-a11 - grad_u11 + (a11 + grad_u11)*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a61 + grad_u71)*(a61 + grad_u71))) + (a41 + grad_u21)*((a11 + grad_u11)*(a41 + grad_u21) + (a21 + grad_u51)*(a41 + grad_u41) + (a51 + grad_u81)*(a61 + grad_u71)) + (a61 + grad_u31)*((a11 + grad_u11)*(a61 + grad_u31) + (a31 + grad_u91)*(a61 + grad_u71) + (a41 + grad_u41)*(a51 + grad_u61)));
		gradient(1) = (1.0/2.0)*lambda_S*(a41 + grad_u21)*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(-a41 - grad_u21 + (a11 + grad_u11)*((a11 + grad_u11)*(a41 + grad_u21) + (a21 + grad_u51)*(a41 + grad_u41) + (a51 + grad_u81)*(a61 + grad_u71)) + (a41 + grad_u21)*(((a21 + grad_u51)*(a21 + grad_u51)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a51 + grad_u81)*(a51 + grad_u81))) + (a61 + grad_u31)*((a21 + grad_u51)*(a51 + grad_u61) + (a31 + grad_u91)*(a51 + grad_u81) + (a41 + grad_u21)*(a61 + grad_u31)));
		gradient(2) = (1.0/2.0)*lambda_S*(a61 + grad_u31)*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(-a61 - grad_u31 + (a11 + grad_u11)*((a11 + grad_u11)*(a61 + grad_u31) + (a31 + grad_u91)*(a61 + grad_u71) + (a41 + grad_u41)*(a51 + grad_u61)) + (a41 + grad_u21)*((a21 + grad_u51)*(a51 + grad_u61) + (a31 + grad_u91)*(a51 + grad_u81) + (a41 + grad_u21)*(a61 + grad_u31)) + (a61 + grad_u31)*(((a31 + grad_u91)*(a31 + grad_u91)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a61 + grad_u31)*(a61 + grad_u31))));
		gradient(3) = (1.0/2.0)*lambda_S*(a41 + grad_u41)*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(-a41 - grad_u41 + (a21 + grad_u51)*((a11 + grad_u11)*(a41 + grad_u21) + (a21 + grad_u51)*(a41 + grad_u41) + (a51 + grad_u81)*(a61 + grad_u71)) + (a41 + grad_u41)*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a61 + grad_u71)*(a61 + grad_u71))) + (a51 + grad_u61)*((a11 + grad_u11)*(a61 + grad_u31) + (a31 + grad_u91)*(a61 + grad_u71) + (a41 + grad_u41)*(a51 + grad_u61)));
		gradient(4) = (1.0/2.0)*lambda_S*(a21 + grad_u51)*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(-a21 - grad_u51 + (a21 + grad_u51)*(((a21 + grad_u51)*(a21 + grad_u51)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a51 + grad_u81)*(a51 + grad_u81))) + (a41 + grad_u41)*((a11 + grad_u11)*(a41 + grad_u21) + (a21 + grad_u51)*(a41 + grad_u41) + (a51 + grad_u81)*(a61 + grad_u71)) + (a51 + grad_u61)*((a21 + grad_u51)*(a51 + grad_u61) + (a31 + grad_u91)*(a51 + grad_u81) + (a41 + grad_u21)*(a61 + grad_u31)));
		gradient(5) = (1.0/2.0)*lambda_S*(a51 + grad_u61)*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(-a51 - grad_u61 + (a21 + grad_u51)*((a21 + grad_u51)*(a51 + grad_u61) + (a31 + grad_u91)*(a51 + grad_u81) + (a41 + grad_u21)*(a61 + grad_u31)) + (a41 + grad_u41)*((a11 + grad_u11)*(a61 + grad_u31) + (a31 + grad_u91)*(a61 + grad_u71) + (a41 + grad_u41)*(a51 + grad_u61)) + (a51 + grad_u61)*(((a31 + grad_u91)*(a31 + grad_u91)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a61 + grad_u31)*(a61 + grad_u31))));
		gradient(6) = (1.0/2.0)*lambda_S*(a61 + grad_u71)*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(-a61 - grad_u71 + (a31 + grad_u91)*((a11 + grad_u11)*(a61 + grad_u31) + (a31 + grad_u91)*(a61 + grad_u71) + (a41 + grad_u41)*(a51 + grad_u61)) + (a51 + grad_u81)*((a11 + grad_u11)*(a41 + grad_u21) + (a21 + grad_u51)*(a41 + grad_u41) + (a51 + grad_u81)*(a61 + grad_u71)) + (a61 + grad_u71)*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a61 + grad_u71)*(a61 + grad_u71))));
		gradient(7) = (1.0/2.0)*lambda_S*(a51 + grad_u81)*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(-a51 - grad_u81 + (a31 + grad_u91)*((a21 + grad_u51)*(a51 + grad_u61) + (a31 + grad_u91)*(a51 + grad_u81) + (a41 + grad_u21)*(a61 + grad_u31)) + (a51 + grad_u81)*(((a21 + grad_u51)*(a21 + grad_u51)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a51 + grad_u81)*(a51 + grad_u81))) + (a61 + grad_u71)*((a11 + grad_u11)*(a41 + grad_u21) + (a21 + grad_u51)*(a41 + grad_u41) + (a51 + grad_u81)*(a61 + grad_u71)));
		gradient(8) = (1.0/2.0)*lambda_S*(a31 + grad_u91)*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(-a31 - grad_u91 + (a31 + grad_u91)*(((a31 + grad_u91)*(a31 + grad_u91)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a61 + grad_u31)*(a61 + grad_u31))) + (a51 + grad_u81)*((a21 + grad_u51)*(a51 + grad_u61) + (a31 + grad_u91)*(a51 + grad_u81) + (a41 + grad_u21)*(a61 + grad_u31)) + (a61 + grad_u71)*((a11 + grad_u11)*(a61 + grad_u31) + (a31 + grad_u91)*(a61 + grad_u71) + (a41 + grad_u41)*(a51 + grad_u61)));
	}

	if(update_hessian)
	{
		hessian.resize(9,9);
		hessian(0,0) = lambda_S*((a11 + grad_u11)*(a11 + grad_u11)) + (1.0/2.0)*lambda_S*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(3*((a11 + grad_u11)*(a11 + grad_u11)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 1);
		hessian(0,1) = hessian(1,0) = lambda_S*(a11 + grad_u11)*(a41 + grad_u21) + mu_S*(2*(a11 + grad_u11)*(a41 + grad_u21) + (a21 + grad_u51)*(a41 + grad_u41) + (a51 + grad_u81)*(a61 + grad_u71));
		hessian(0,2) = hessian(2,0) = lambda_S*(a11 + grad_u11)*(a61 + grad_u31) + mu_S*(2*(a11 + grad_u11)*(a61 + grad_u31) + (a31 + grad_u91)*(a61 + grad_u71) + (a41 + grad_u41)*(a51 + grad_u61));
		hessian(0,3) = hessian(3,0) = lambda_S*(a11 + grad_u11)*(a41 + grad_u41) + mu_S*(2*(a11 + grad_u11)*(a41 + grad_u41) + (a21 + grad_u51)*(a41 + grad_u21) + (a51 + grad_u61)*(a61 + grad_u31));
		hessian(0,4) = hessian(4,0) = lambda_S*(a11 + grad_u11)*(a21 + grad_u51) + mu_S*(a41 + grad_u21)*(a41 + grad_u41);
		hessian(0,5) = hessian(5,0) = lambda_S*(a11 + grad_u11)*(a51 + grad_u61) + mu_S*(a41 + grad_u41)*(a61 + grad_u31);
		hessian(0,6) = hessian(6,0) = lambda_S*(a11 + grad_u11)*(a61 + grad_u71) + mu_S*(2*(a11 + grad_u11)*(a61 + grad_u71) + (a31 + grad_u91)*(a61 + grad_u31) + (a41 + grad_u21)*(a51 + grad_u81));
		hessian(0,7) = hessian(7,0) = lambda_S*(a11 + grad_u11)*(a51 + grad_u81) + mu_S*(a41 + grad_u21)*(a61 + grad_u71);
		hessian(0,8) = hessian(8,0) = lambda_S*(a11 + grad_u11)*(a31 + grad_u91) + mu_S*(a61 + grad_u31)*(a61 + grad_u71);
		hessian(1,1) = lambda_S*((a41 + grad_u21)*(a41 + grad_u21)) + (1.0/2.0)*lambda_S*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + 3*((a41 + grad_u21)*(a41 + grad_u21)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) - 1);
		hessian(1,2) = hessian(2,1) = lambda_S*(a41 + grad_u21)*(a61 + grad_u31) + mu_S*((a21 + grad_u51)*(a51 + grad_u61) + (a31 + grad_u91)*(a51 + grad_u81) + 2*(a41 + grad_u21)*(a61 + grad_u31));
		hessian(1,3) = hessian(3,1) = lambda_S*(a41 + grad_u21)*(a41 + grad_u41) + mu_S*(a11 + grad_u11)*(a21 + grad_u51);
		hessian(1,4) = hessian(4,1) = lambda_S*(a21 + grad_u51)*(a41 + grad_u21) + mu_S*((a11 + grad_u11)*(a41 + grad_u41) + 2*(a21 + grad_u51)*(a41 + grad_u21) + (a51 + grad_u61)*(a61 + grad_u31));
		hessian(1,5) = hessian(5,1) = lambda_S*(a41 + grad_u21)*(a51 + grad_u61) + mu_S*(a21 + grad_u51)*(a61 + grad_u31);
		hessian(1,6) = hessian(6,1) = lambda_S*(a41 + grad_u21)*(a61 + grad_u71) + mu_S*(a11 + grad_u11)*(a51 + grad_u81);
		hessian(1,7) = hessian(7,1) = lambda_S*(a41 + grad_u21)*(a51 + grad_u81) + mu_S*((a11 + grad_u11)*(a61 + grad_u71) + (a31 + grad_u91)*(a61 + grad_u31) + 2*(a41 + grad_u21)*(a51 + grad_u81));
		hessian(1,8) = hessian(8,1) = lambda_S*(a31 + grad_u91)*(a41 + grad_u21) + mu_S*(a51 + grad_u81)*(a61 + grad_u31);
		hessian(2,2) = lambda_S*((a61 + grad_u31)*(a61 + grad_u31)) + (1.0/2.0)*lambda_S*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a51 + grad_u61)*(a51 + grad_u61)) + 3*((a61 + grad_u31)*(a61 + grad_u31)) - 1);
		hessian(2,3) = hessian(3,2) = lambda_S*(a41 + grad_u41)*(a61 + grad_u31) + mu_S*(a11 + grad_u11)*(a51 + grad_u61);
		hessian(2,4) = hessian(4,2) = lambda_S*(a21 + grad_u51)*(a61 + grad_u31) + mu_S*(a41 + grad_u21)*(a51 + grad_u61);
		hessian(2,5) = hessian(5,2) = lambda_S*(a51 + grad_u61)*(a61 + grad_u31) + mu_S*((a11 + grad_u11)*(a41 + grad_u41) + (a21 + grad_u51)*(a41 + grad_u21) + 2*(a51 + grad_u61)*(a61 + grad_u31));
		hessian(2,6) = hessian(6,2) = lambda_S*(a61 + grad_u31)*(a61 + grad_u71) + mu_S*(a11 + grad_u11)*(a31 + grad_u91);
		hessian(2,7) = hessian(7,2) = lambda_S*(a51 + grad_u81)*(a61 + grad_u31) + mu_S*(a31 + grad_u91)*(a41 + grad_u21);
		hessian(2,8) = hessian(8,2) = lambda_S*(a31 + grad_u91)*(a61 + grad_u31) + mu_S*((a11 + grad_u11)*(a61 + grad_u71) + 2*(a31 + grad_u91)*(a61 + grad_u31) + (a41 + grad_u21)*(a51 + grad_u81));
		hessian(3,3) = lambda_S*((a41 + grad_u41)*(a41 + grad_u41)) + (1.0/2.0)*lambda_S*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + 3*((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 1);
		hessian(3,4) = hessian(4,3) = lambda_S*(a21 + grad_u51)*(a41 + grad_u41) + mu_S*((a11 + grad_u11)*(a41 + grad_u21) + 2*(a21 + grad_u51)*(a41 + grad_u41) + (a51 + grad_u81)*(a61 + grad_u71));
		hessian(3,5) = hessian(5,3) = lambda_S*(a41 + grad_u41)*(a51 + grad_u61) + mu_S*((a11 + grad_u11)*(a61 + grad_u31) + (a31 + grad_u91)*(a61 + grad_u71) + 2*(a41 + grad_u41)*(a51 + grad_u61));
		hessian(3,6) = hessian(6,3) = lambda_S*(a41 + grad_u41)*(a61 + grad_u71) + mu_S*((a21 + grad_u51)*(a51 + grad_u81) + (a31 + grad_u91)*(a51 + grad_u61) + 2*(a41 + grad_u41)*(a61 + grad_u71));
		hessian(3,7) = hessian(7,3) = lambda_S*(a41 + grad_u41)*(a51 + grad_u81) + mu_S*(a21 + grad_u51)*(a61 + grad_u71);
		hessian(3,8) = hessian(8,3) = lambda_S*(a31 + grad_u91)*(a41 + grad_u41) + mu_S*(a51 + grad_u61)*(a61 + grad_u71);
		hessian(4,4) = lambda_S*((a21 + grad_u51)*(a21 + grad_u51)) + (1.0/2.0)*lambda_S*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(3*((a21 + grad_u51)*(a21 + grad_u51)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) - 1);
		hessian(4,5) = hessian(5,4) = lambda_S*(a21 + grad_u51)*(a51 + grad_u61) + mu_S*(2*(a21 + grad_u51)*(a51 + grad_u61) + (a31 + grad_u91)*(a51 + grad_u81) + (a41 + grad_u21)*(a61 + grad_u31));
		hessian(4,6) = hessian(6,4) = lambda_S*(a21 + grad_u51)*(a61 + grad_u71) + mu_S*(a41 + grad_u41)*(a51 + grad_u81);
		hessian(4,7) = hessian(7,4) = lambda_S*(a21 + grad_u51)*(a51 + grad_u81) + mu_S*(2*(a21 + grad_u51)*(a51 + grad_u81) + (a31 + grad_u91)*(a51 + grad_u61) + (a41 + grad_u41)*(a61 + grad_u71));
		hessian(4,8) = hessian(8,4) = lambda_S*(a21 + grad_u51)*(a31 + grad_u91) + mu_S*(a51 + grad_u61)*(a51 + grad_u81);
		hessian(5,5) = lambda_S*((a51 + grad_u61)*(a51 + grad_u61)) + (1.0/2.0)*lambda_S*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u41)*(a41 + grad_u41)) + 3*((a51 + grad_u61)*(a51 + grad_u61)) + ((a61 + grad_u31)*(a61 + grad_u31)) - 1);
		hessian(5,6) = hessian(6,5) = lambda_S*(a51 + grad_u61)*(a61 + grad_u71) + mu_S*(a31 + grad_u91)*(a41 + grad_u41);
		hessian(5,7) = hessian(7,5) = lambda_S*(a51 + grad_u61)*(a51 + grad_u81) + mu_S*(a21 + grad_u51)*(a31 + grad_u91);
		hessian(5,8) = hessian(8,5) = lambda_S*(a31 + grad_u91)*(a51 + grad_u61) + mu_S*((a21 + grad_u51)*(a51 + grad_u81) + 2*(a31 + grad_u91)*(a51 + grad_u61) + (a41 + grad_u41)*(a61 + grad_u71));
		hessian(6,6) = lambda_S*((a61 + grad_u71)*(a61 + grad_u71)) + (1.0/2.0)*lambda_S*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u81)*(a51 + grad_u81)) + 3*((a61 + grad_u71)*(a61 + grad_u71)) - 1);
		hessian(6,7) = hessian(7,6) = lambda_S*(a51 + grad_u81)*(a61 + grad_u71) + mu_S*((a11 + grad_u11)*(a41 + grad_u21) + (a21 + grad_u51)*(a41 + grad_u41) + 2*(a51 + grad_u81)*(a61 + grad_u71));
		hessian(6,8) = hessian(8,6) = lambda_S*(a31 + grad_u91)*(a61 + grad_u71) + mu_S*((a11 + grad_u11)*(a61 + grad_u31) + 2*(a31 + grad_u91)*(a61 + grad_u71) + (a41 + grad_u41)*(a51 + grad_u61));
		hessian(7,7) = lambda_S*((a51 + grad_u81)*(a51 + grad_u81)) + (1.0/2.0)*lambda_S*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + 3*((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 1);
		hessian(7,8) = hessian(8,7) = lambda_S*(a31 + grad_u91)*(a51 + grad_u81) + mu_S*((a21 + grad_u51)*(a51 + grad_u61) + 2*(a31 + grad_u91)*(a51 + grad_u81) + (a41 + grad_u21)*(a61 + grad_u31));
		hessian(8,8) = lambda_S*((a31 + grad_u91)*(a31 + grad_u91)) + (1.0/2.0)*lambda_S*(((a11 + grad_u11)*(a11 + grad_u11)) + ((a21 + grad_u51)*(a21 + grad_u51)) + ((a31 + grad_u91)*(a31 + grad_u91)) + ((a41 + grad_u21)*(a41 + grad_u21)) + ((a41 + grad_u41)*(a41 + grad_u41)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 2) + mu_S*(3*((a31 + grad_u91)*(a31 + grad_u91)) + ((a51 + grad_u61)*(a51 + grad_u61)) + ((a51 + grad_u81)*(a51 + grad_u81)) + ((a61 + grad_u31)*(a61 + grad_u31)) + ((a61 + grad_u71)*(a61 + grad_u71)) - 1);
	}

	return false;
}

//////////////
// DeltaEta //
//////////////

DeltaEta::DeltaEta(	const VariableSet	argument_set,
					const VariableSet	parameter_set,
					const double		eta)
:
ScalarFunction<double, VectorXd, MatrixXd, VectorXd, VectorXd>(argument_set, parameter_set),
eta(eta)
{
}

bool
DeltaEta::compute(	double&		value,
					VectorXd&	gradient,
					MatrixXd&	hessian,
					const bool	update_value,
					const bool	update_gradient,
					const bool	update_hessian)
{
	const double di11 = get_arguments()[0];
	const double di21 = get_arguments()[1];
	const double di31 = get_arguments()[2];
	const double di41 = get_arguments()[3];
	const double di51 = get_arguments()[4];
	const double di61 = get_arguments()[5];

	if(update_value)
	{
		value = (1.0/2.0)*eta*(2*((di11)*(di11)) + 2*((di21)*(di21)) + 2*((di31)*(di31)) + ((di41)*(di41)) + ((di51)*(di51)) + ((di61)*(di61)));
	}


	if(update_gradient)
	{
		gradient.resize(6);
		gradient(0) = 2*di11*eta;
		gradient(1) = 2*di21*eta;
		gradient(2) = 2*di31*eta;
		gradient(3) = di41*eta;
		gradient(4) = di51*eta;
		gradient(5) = di61*eta;
	}

	if(update_hessian)
	{
		hessian.resize(6,6);
		hessian(0,0) = 2*eta;
		hessian(0,1) = hessian(1,0) = 0;
		hessian(0,2) = hessian(2,0) = 0;
		hessian(0,3) = hessian(3,0) = 0;
		hessian(0,4) = hessian(4,0) = 0;
		hessian(0,5) = hessian(5,0) = 0;
		hessian(1,1) = 2*eta;
		hessian(1,2) = hessian(2,1) = 0;
		hessian(1,3) = hessian(3,1) = 0;
		hessian(1,4) = hessian(4,1) = 0;
		hessian(1,5) = hessian(5,1) = 0;
		hessian(2,2) = 2*eta;
		hessian(2,3) = hessian(3,2) = 0;
		hessian(2,4) = hessian(4,2) = 0;
		hessian(2,5) = hessian(5,2) = 0;
		hessian(3,3) = eta;
		hessian(3,4) = hessian(4,3) = 0;
		hessian(3,5) = hessian(5,3) = 0;
		hessian(4,4) = eta;
		hessian(4,5) = hessian(5,4) = 0;
		hessian(5,5) = eta;
	}

	return false;
}



}
