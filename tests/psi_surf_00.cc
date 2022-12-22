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
 * Test for PsiSurf
 */

int main(int argc, char *argv[])
{

	// initialize logging
	initlog(argc, argv, "psi_surf_00");

	const double lambda_S = 1.2;
	const double mu_S = 1.6;

	DEModel::PsiSurf psi_surf({"u_1,1", "u_1,2", "u_1,3", "u_2,1", "u_2,2", "u_2,3", "u_3,1", "u_3,2", "u_3,3"}, {"n_1", "n_2", "n_3"}, lambda_S, mu_S);

	Eigen::VectorXd arguments(9), parameters(3);
	arguments << 0.14109, 0.58873, 0.33273, 0.16916, 0.78525, 0.39318, 0.79193, 0.63440, 0.552314;
	parameters << 0.33835, 0.74636, 0.57312;

	psi_surf.set_arguments(arguments);
	psi_surf.set_parameters(parameters);
	psi_surf.numeric_test_derivatives(1e-8, demodel_log);

	// stop logging
	return stoplog(argc, argv);
}
