/*
 * Copyright (C) 2022 by Fraunhofer IKTS, Dresden, Germany - All Rights Reserved
 *
 * Created on 21.12.2022 by Sebastian Stark
 *
 * This file is part of DEModel
 */

#include "tests.h"
#include <string>
#include <vector>

#include <demodel/demodel.h>

using namespace std;
using namespace CMF;

/**
 * Test for TransformationEte
 */

class ExampleFunction : public ScalarFunction<double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd>
{

public:

	ExampleFunction(const VariableSet w, const VariableSet p)
	:
	ScalarFunction(w, p)
	{
	}

	bool
	compute(double&				value,
			Eigen::VectorXd&	gradient,
			Eigen::MatrixXd&	hessian,
			const bool			update_value,
			const bool			update_gradient,
			const bool			update_hessian)
	override
	final
	{

		Eigen::MatrixXd K(6,6);
		for(unsigned int m = 0; m < 6; ++m)
			for(unsigned int n = 0; n < 6; ++n)
				K(m,n) = 1.0 + 6.0 * m + n;

		Eigen::VectorXd g(6);
		for(unsigned int m = 0; m < 6; ++m)
			g(m) = 1.0 + m;

		if(update_value)
			value = get_arguments().transpose() * K * get_arguments() + g.dot(get_arguments()) + 7.0;
		if(update_gradient)
			gradient = (K + K.transpose()) * get_arguments() + g;
		if(update_hessian)
			hessian = K + K.transpose();

		return false;
	}
};


int main(int argc, char *argv[])
{

	// initialize logging
	initlog(argc, argv, "transformation_di_00");


	ExampleFunction example_constitutive_function({"d_i_11", "d_i_22", "d_i_33", "2*d_i_12", "2*d_i_23", "2*d_i_31"},{});
	Eigen::VectorXd arguments(30), v(6);
	arguments << 0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5, 11.5, 0.73624, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3, 1.4, 0.14109, 0.58873, 0.33273, 0.16916, 0.78525, 0.39318, 0.79193, 0.63440;
	v << 1.0, 1.0, 1.0, 1.0, 1.0, 1.0;

	DEModel::Transformationdi test_transformation({"d_i_11", "d_i_22", "d_i_33", "2*d_i_12", "2*d_i_23", "2*d_i_31"}, {"U_i_dot_11", "U_i_dot_22", "U_i_dot_33", "2*U_i_dot_12", "2*U_i_dot_23", "2*U_i_dot_31", "Ui_inv_11", "Ui_inv_22", "Ui_inv_33", "2*Ui_inv_12", "2*Ui_inv_23", "2*Ui_inv_31", "F_11", "F_21", "F_31", "F_12", "F_22", "F_23", "F_31", "F_32", "F_33", "F_inv_11", "F_inv_21", "F_inv_31", "F_inv_12", "F_inv_22", "F_inv_23", "F_inv_31", "F_inv_32", "F_inv_33"});
	test_transformation.set_v(v);
	test_transformation.set_arguments(arguments);
	test_transformation.numeric_test_derivatives(1e-8, demodel_log);

	TransformedScalarFunction<double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd> transformed_constitutive_function(example_constitutive_function, test_transformation);
	transformed_constitutive_function.set_arguments(arguments);
	transformed_constitutive_function.numeric_test_derivatives(1e-8, demodel_log);

	// stop logging
	return stoplog(argc, argv);
}
