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

	DEModel::PsiMech psi_mech({"F_11", "F_12", "F_13", "F_21", "F_22", "F_23", "F_31", "F_32", "F_33", "Ui_inv_11", "Ui_inv_22", "Ui_inv_33", "2*Ui_inv_12", "2*Ui_inv_23", "2*Ui_inv_31", "J"}, {"x_1", "x_2", "x_3"}, mu_e, mu_i);

	Eigen::VectorXd arguments(16), parameters(3);
	arguments << 7.919001680476220e-01, 4.354021247897929e-01, 7.258518419606522e-02, 2.536529913731666e-01, 9.357484950847669e-01, 1.187560501774511e-01, 4.061255583546320e-01, 2.959545035959460e-01, 8.658406739391875e-01, 0.552314, 0.495467, 0.808784, 0.404693, 0.029189, -0.177586, 5.170116338434780e-01;

	psi_mech.set_arguments(arguments);
	psi_mech.numeric_test_derivatives(1e-8, demodel_log);

	// stop logging
	return stoplog(argc, argv);
}
