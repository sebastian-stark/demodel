/*
 * Copyright (C) 2022 by Fraunhofer IKTS, Dresden, Germany - All Rights Reserved
 *
 * Created on 21.12.2022 by Sebastian Stark
 *
 * This file is part of the DEModel library
 *
 */

#ifndef INCLUDE_DEMODEL_DEMODEL_H_
#define INCLUDE_DEMODEL_DEMODEL_H_

#include <cmf/scalar_function.h>

namespace DEModel
{

/**
 * This class describes a transformation of variables according to \f$ d^\mathrm{i}_{kl} = \dfrac{1}{2}\left( F_{ki} {U^\mathrm{i}}^{-1}_{ij} \dot{U}^\mathrm{i}_{jm} F^{-1}_{ml} + F_{li} {U^\mathrm{i}}^{-1}_{ij} \dot{U}^\mathrm{i}_{jm} F^{-1}_{mk} \right) \f$,
 * where \f$\dot{U}^\mathrm{i}_{kl}\f$ and \f${U^\mathrm{i}}^{-1}_{kl}\f$ are symmetric, while \f$F_{kl}\f$ and \f$F^{-1}_{kl}\f$ are unsymmetric.
 *
 * Given a function \f$f(d^\mathrm{i}_{kl})\f$, the result is a function \f$g(\dot{U}^\mathrm{i}_{mn}, U^{-1}_{mn}, F_{mn}, F^{-1}_{mn})=f[d^\mathrm{i}_{kl}(\dot{U}^\mathrm{i}_{mn}, U^{-1}_{mn}, F_{mn}, F^{-1}_{mn})]\f$.
 *
 * The variables are stored as \f$ w_\alpha = \begin{pmatrix} d^\mathrm{i}_{11} \\ d^\mathrm{i}_{22} \\ d^\mathrm{i}_{33} \\ 2 d^\mathrm{i}_{12} \\ 2 d^\mathrm{i}_{23} \\ 2 d^\mathrm{i}_{31} \end{pmatrix} \f$
 * and \f$ q_\zeta = \begin{pmatrix} \dot{U}^\mathrm{i}_{11} \\ \dot{U}^\mathrm{i}_{22} \\ \dot{U}^\mathrm{i}_{33} \\ 2 \dot{U}^\mathrm{i}_{12} \\ 2 \dot{U}^\mathrm{i}_{23} \\ 2 \dot{U}^\mathrm{i}_{31} \\ U^{-1}_{11} \\ U^{-1}_{22} \\ U^{-1}_{33} \\ 2 U^{-1}_{12} \\ 2 U^{-1}_{23} \\ 2 U^{-1}_{31} \\ F_{11} \\ F_{12} \\ F_{13} \\ F_{21} \\ F_{22} \\ F_{23} \\ F_{31} \\ F_{32} \\ F_{33} \\ F^{-1}_{11} \\ F^{-1}_{12} \\ F^{-1}_{13} \\ F^{-1}_{21} \\ F^{-1}_{22} \\ F^{-1}_{23} \\ F^{-1}_{31} \\ F^{-1}_{32} \\ F^{-1}_{33} \end{pmatrix} \f$.
 *
 * See also the general documentation of VariableTransformFunction<double, Eigen::VectorXd, Eigen::MatrixXd> for further information.
 */
class Transformationdi : public CMF::VariableTransformFunction<Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd>
{
public:

	/**
	 * @param[in]	value_set		The variable set \f$w_\alpha\f$.
	 *
	 * @param[in]	argument_set	The variable set \f$q_\zeta\f$.
	 */
	Transformationdi(	const CMF::VariableSet value_set,
						const CMF::VariableSet argument_set);

	/**
	 * See CMF::Function::compute()
	 */
	bool
	compute(Eigen::VectorXd&	value,
			Eigen::MatrixXd&	gradient,
			Eigen::MatrixXd&	hessian,
			const bool			update_value,
			const bool			update_gradient,
			const bool			update_hessian)
	override
	final;

};

}

#endif /* INCLUDE_DEMODEL_DEMODEL_H_ */
