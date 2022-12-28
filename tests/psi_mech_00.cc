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
 * Test for PsiMech
 */

int main(int argc, char *argv[])
{

	// initialize logging
	initlog(argc, argv, "psi_mech_00");

	const double mu_i = 1.2;
	const double mu_e = 1.5;

	DEModel::PsiMech psi_mech({"F_11", "F_21", "F_31", "F_12", "F_22", "F_23", "F_31", "F_32", "F_33", "Ui_inv_11", "Ui_inv_22", "Ui_inv_33", "2*Ui_inv_12", "2*Ui_inv_23", "2*Ui_inv_31"}, {}, mu_e, mu_i);

	Eigen::VectorXd arguments(15), parameters(0);
	arguments << 0.14109, 0.58873, 0.33273, 0.16916, 0.78525, 0.39318, 0.79193, 0.63440, 0.552314, 0.552314, 0.495467, 0.808784, 0.404693, 0.029189, -0.177586;

	psi_mech.set_arguments(arguments);
	psi_mech.numeric_test_derivatives(1e-8, demodel_log);

	// stop logging
	return stoplog(argc, argv);
}
