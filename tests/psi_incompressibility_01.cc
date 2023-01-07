/*
 * Copyright (C) 2022 by Fraunhofer IKTS, Dresden, Germany - All Rights Reserved
 *
 * Created on 28.12.2022 by Sebastian Stark
 *
 * This file is part of the DEModel library
 */

#include "tests.h"
#include <string>
#include <vector>

#include <demodel/demodel.h>
#include <cmf/variable_transform_function.h>
#include <cmf/derivative_transform_lib.h>

using namespace std;
using namespace CMF;

/**
 * Test for PsiElec
 */

int main(int argc, char *argv[])
{

	// initialize logging
	initlog(argc, argv, "psi_incompressibility_01");

	const double epsilon = 1.2;

	DEModel::PsiIncompressibility psi_inc({"p", "J"}, {"x_1", "x_2", "x_3"});

	TransformationIdentity transformation_identity_p = TransformationIdentity({"p"}, {"p"});
	TransformationDeterminantSymmetricMatrix transformation_J_Ui = TransformationDeterminantSymmetricMatrix({"J"}, {"Ui_inv_11", "Ui_inv_22", "Ui_inv_33", "2*Ui_inv_12", "2*Ui_inv_23", "2*Ui_inv_31"});
	CombinedVariableTransformFunction<Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd> combined_transform_2 = CombinedVariableTransformFunction<Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd>({&transformation_identity_p, &transformation_J_Ui});
	TransformedScalarFunction<double, Eigen::VectorXd, Eigen::MatrixXd> psi_inc_transformed(psi_inc, combined_transform_2);

	Eigen::VectorXd arguments(7), parameters(3);
	arguments << -1.2, 2.18069, 2.38926, 1.26704, -1.79623, -0.28343, 0.51123;

	psi_inc_transformed.set_arguments(arguments);
	psi_inc_transformed.numeric_test_derivatives(1e-8, demodel_log);

	// stop logging
	return stoplog(argc, argv);
}
