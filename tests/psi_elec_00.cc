/*
 * Copyright (C) 2022 by Fraunhofer IKTS, Dresden, Germany - All Rights Reserved
 *
 * Created on 22.12.2022 by Sebastian Stark
 *
 * This file is part of the DEModel library
 */

#include "tests.h"
#include <string>
#include <vector>

#include <demodel/demodel.h>

using namespace std;
using namespace CMF;

/**
 * Test for PsiElec
 */

int main(int argc, char *argv[])
{

	// initialize logging
	initlog(argc, argv, "psi_elec_00");

	const double epsilon = 1.2;

	DEModel::PsiElec psi_elec({"E_1", "E_2", "E_3", "F_inv_11", "F_inv_21", "F_inv_31", "F_inv_12", "F_inv_22", "F_inv_23", "F_inv_31", "F_inv_32", "F_inv_33"}, {"x_1", "x_2", "x_3"}, epsilon);

	Eigen::VectorXd arguments(12), parameters(3);
	arguments << 0.404693, 0.029189, -0.177586, 0.14109, 0.58873, 0.33273, 0.16916, 0.78525, 0.39318, 0.79193, 0.63440, 0.552314;

	psi_elec.set_arguments(arguments);
	psi_elec.numeric_test_derivatives(1e-8, demodel_log);

	// stop logging
	return stoplog(argc, argv);
}
