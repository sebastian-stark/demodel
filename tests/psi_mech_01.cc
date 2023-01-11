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
 * Test for PsiMech
 */

int main(int argc, char *argv[])
{

	// initialize logging
	initlog(argc, argv, "psi_mech_01");

	const double mu_i = 1.2;
	const double mu_e = 1.5;

	DEModel::PsiMech psi_mech({"F_11", "F_12", "F_13", "F_21", "F_22", "F_23", "F_31", "F_32", "F_33", "Ui_inv_11", "Ui_inv_22", "Ui_inv_33", "2*Ui_inv_12", "2*Ui_inv_23", "2*Ui_inv_31", "J"}, {"x_1", "x_2", "x_3"}, mu_e, mu_i);

	TransformationIdentity transformation_identity_F = CMF::TransformationIdentity({"F_11", "F_12", "F_13", "F_21", "F_22", "F_23", "F_31", "F_32", "F_33"}, {"F_11", "F_12", "F_13", "F_21", "F_22", "F_23", "F_31", "F_32", "F_33"});
	TransformationInverseSymmetricRank2Tensor transformation_Ui_inv_Ui = CMF::TransformationInverseSymmetricRank2Tensor({"Ui_inv_11", "Ui_inv_22", "Ui_inv_33", "2*Ui_inv_12", "2*Ui_inv_23", "2*Ui_inv_31"}, {"Ui_11", "Ui_22", "Ui_33", "2*Ui_12", "2*Ui_23", "2*Ui_31"});
	TransformationDeterminantMatrix transformation_J_F = CMF::TransformationDeterminantMatrix({"J"}, {"F_11", "F_12", "F_13", "F_21", "F_22", "F_23", "F_31", "F_32", "F_33"});

	CombinedVariableTransformFunction<Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd> transform_Ui_inv_Ui = CMF::CombinedVariableTransformFunction<Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd>({&transformation_identity_F, &transformation_Ui_inv_Ui, &transformation_J_F});
	TransformedScalarFunction<double, Eigen::VectorXd, Eigen::MatrixXd> psi_mech_transformed(psi_mech, transform_Ui_inv_Ui);

	Eigen::VectorXd arguments(15), parameters(3);
	arguments << 7.919001680476220e-01, 4.354021247897929e-01, 7.258518419606522e-02, 2.536529913731666e-01, 9.357484950847669e-01, 1.187560501774511e-01, 4.061255583546320e-01, 2.959545035959460e-01, 8.658406739391875e-01, 2.18069, 2.38926, 1.26704, -1.79623, -0.28343, 0.51123;

	psi_mech_transformed.set_arguments(arguments);
	psi_mech_transformed.numeric_test_derivatives(1e-8, demodel_log);

	// stop logging
	return stoplog(argc, argv);
}
