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
	initlog(argc, argv, "delta_eta_01");

	const double eta = 1.2;

	DEModel::DeltaEta delta_eta({"di_11", "di_22", "di_33", "2*di_12", "2*di_23", "2*di_31"}, {"t", "x_1", "x_2", "x_3"}, eta);

	DEModel::Transformationdi transformationdi = DEModel::Transformationdi({"di_11", "di_22", "di_33", "2*di_12", "2*di_23", "2*di_31"}, {"Ui_dot_11", "Ui_dot_22", "Ui_dot_33", "2*Ui_dot_12", "2*Ui_dot_23", "2*Ui_dot_31", "Ui_inv_11", "Ui_inv_22", "Ui_inv_33", "2*Ui_inv_12", "2*Ui_inv_23", "2*Ui_inv_31", "F_11", "F_12", "F_13", "F_21", "F_22", "F_23", "F_31", "F_32", "F_33", "F_inv_11", "F_inv_12", "F_inv_13", "F_inv_21", "F_inv_22", "F_inv_23", "F_inv_31", "F_inv_32", "F_inv_33"});
	TransformationIdentity transformation_identity_Ui_dot = CMF::TransformationIdentity({"Ui_dot_11", "Ui_dot_22", "Ui_dot_33", "2*Ui_dot_12", "2*Ui_dot_23", "2*Ui_dot_31"}, {"Ui_dot_11", "Ui_dot_22", "Ui_dot_33", "2*Ui_dot_12", "2*Ui_dot_23", "2*Ui_dot_31"});
	TransformationInverseSymmetricRank2Tensor transformation_Ui_inv_Ui = CMF::TransformationInverseSymmetricRank2Tensor({"Ui_inv_11", "Ui_inv_22", "Ui_inv_33", "2*Ui_inv_12", "2*Ui_inv_23", "2*Ui_inv_31"}, {"Ui_11", "Ui_22", "Ui_33", "2*Ui_12", "2*Ui_23", "2*Ui_31"});
	TransformationIdentity transformation_identity_F = CMF::TransformationIdentity({"F_11", "F_12", "F_13", "F_21", "F_22", "F_23", "F_31", "F_32", "F_33"}, {"F_11", "F_12", "F_13", "F_21", "F_22", "F_23", "F_31", "F_32", "F_33"});
	TransformationInverseRank2Tensor transformation_F_inv_F = TransformationInverseRank2Tensor({"F_inv_11", "F_inv_12", "F_inv_13", "F_inv_21", "F_inv_22", "F_inv_23", "F_inv_31", "F_inv_32", "F_inv_33"}, {"F_11", "F_12", "F_13", "F_21", "F_22", "F_23", "F_31", "F_32", "F_33"});
	CombinedVariableTransformFunction<Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd> combined_transform = CombinedVariableTransformFunction<Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd>({&transformation_identity_Ui_dot, &transformation_Ui_inv_Ui, &transformation_identity_F, &transformation_F_inv_F});

	TransformedScalarFunction<double, Eigen::VectorXd, Eigen::MatrixXd> delta_eta_transformed_1(delta_eta, transformationdi);
	TransformedScalarFunction<double, Eigen::VectorXd, Eigen::MatrixXd> delta_eta_transformed(delta_eta_transformed_1, combined_transform);

	Eigen::VectorXd arguments(21), parameters(4);
	arguments << 2.18069, 2.38926, 1.26704, -1.79623, -0.28343, 0.51123, 0.266529, 0.291755, 0.401604, 0.054264, -0.185090, -0.135517, 0.14109, 0.58873, 0.33273, 0.16916, 0.78525, 0.39318, 0.79193, 0.63440, 0.552314;

	delta_eta_transformed.set_arguments(arguments);
	delta_eta_transformed.numeric_test_derivatives(1e-8, demodel_log);

	// stop logging
	return stoplog(argc, argv);
}
