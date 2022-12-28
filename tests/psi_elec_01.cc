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
	initlog(argc, argv, "psi_elec_01");

	const double epsilon = 1.2;

	DEModel::PsiElec psi_elec({"E_1", "E_2", "E_3", "F_inv_11", "F_inv_12", "F_inv_13", "F_inv_21", "F_inv_22", "F_inv_23", "F_inv_31", "F_inv_32", "F_inv_33"}, {}, epsilon);

	TransformationIdentity transformation_identity_E = TransformationIdentity({"E_1", "E_2", "E_3"}, {"E_1", "E_2", "E_3"});
	TransformationInverseRank2Tensor transformation_F_inv_F = TransformationInverseRank2Tensor({"F_inv_11", "F_inv_12", "F_inv_13", "F_inv_21", "F_inv_22", "F_inv_23", "F_inv_31", "F_inv_32", "F_inv_33"}, {"F_11", "F_12", "F_13", "F_21", "F_22", "F_23", "F_31", "F_32", "F_33"});
	CombinedVariableTransformFunction<Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd> transform_F_inv_F = CombinedVariableTransformFunction<Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd>({&transformation_identity_E, &transformation_F_inv_F});
	TransformedScalarFunction<double, Eigen::VectorXd, Eigen::MatrixXd> psi_elec_transformed(psi_elec, transform_F_inv_F);

	Eigen::VectorXd arguments(12), parameters(0);
	arguments << 0.404693, 0.029189, -0.177586, -10.904941, 6.751108, 1.763490, -12.897515, 10.981974, -0.047985, 30.450311, -22.294147, -0.662882;

	psi_elec_transformed.set_arguments(arguments);
	psi_elec_transformed.numeric_test_derivatives(1e-8, demodel_log);

	// stop logging
	return stoplog(argc, argv);
}
