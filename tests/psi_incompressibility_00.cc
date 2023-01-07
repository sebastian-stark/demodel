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
 * Test for PsiIncompressibility
 */

int main(int argc, char *argv[])
{

	// initialize logging
	initlog(argc, argv, "psi_incompressibility_00");

	DEModel::PsiIncompressibility psi_inc({"p", "J"}, {"x_1", "x_2", "x_3"});

	Eigen::VectorXd arguments(2), parameters(3);
	arguments << -0.3, 1.2;

	psi_inc.set_arguments(arguments);
	psi_inc.numeric_test_derivatives(1e-8, demodel_log);

	// stop logging
	return stoplog(argc, argv);
}
