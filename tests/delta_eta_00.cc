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
 * Test for PsiElPaper2018
 */

int main(int argc, char *argv[])
{

	// initialize logging
	initlog(argc, argv, "delta_eta_00");

	const double eta = 1.2;

	DEModel::DeltaEta delta_eta({"di_11", "di_22", "di_33", "2*di_12", "2*di_23", "2*di_31"}, {"t", "x_1", "x_2", "x_3"}, eta);

	Eigen::VectorXd arguments(6), parameters(4);
	arguments << 0.552314, 0.495467, 0.808784, 0.404693, 0.029189, -0.177586;

	delta_eta.set_arguments(arguments);
	delta_eta.numeric_test_derivatives(1e-8, demodel_log);

	// stop logging
	return stoplog(argc, argv);
}
