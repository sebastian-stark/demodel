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
#include <cmf/variable_transform_function.h>
#include <cmf/derivative_transform_lib.h>

namespace DEModel
{

/**
 * This class describes a transformation of variables according to \f$ d^\mathrm{i}_{kl} = \dfrac{1}{2}\left( F_{ki} {U^\mathrm{i}}^{-1}_{ij} \dot{U}^\mathrm{i}_{jm} F^{-1}_{ml} + F_{li} {U^\mathrm{i}}^{-1}_{ij} \dot{U}^\mathrm{i}_{jm} F^{-1}_{mk} \right) \f$,
 * where \f$\dot{U}^\mathrm{i}_{kl}\f$ and \f${U^\mathrm{i}}^{-1}_{kl}\f$ are symmetric, while \f$F_{kl}\f$ and \f$F^{-1}_{kl}\f$ are unsymmetric.
 *
 * Given a function \f$f(d^\mathrm{i}_{kl})\f$, the result is a function \f$g(\dot{U}^\mathrm{i}_{mn}, U^{-1}_{mn}, F_{mn}, F^{-1}_{mn})=f[d^\mathrm{i}_{kl}(\dot{U}^\mathrm{i}_{mn}, U^{-1}_{mn}, F_{mn}, F^{-1}_{mn})]\f$.
 *
 * The variables are stored as \f$ w_\alpha = \begin{pmatrix} d^\mathrm{i}_{11} \\ d^\mathrm{i}_{22} \\ d^\mathrm{i}_{33} \\ 2 d^\mathrm{i}_{12} \\ 2 d^\mathrm{i}_{23} \\ 2 d^\mathrm{i}_{31} \end{pmatrix} \f$
 * and \f$ q_\zeta = \begin{pmatrix} \dot{U}^\mathrm{i}_{11} \\ \dot{U}^\mathrm{i}_{22} \\ \dot{U}^\mathrm{i}_{33} \\ 2 \dot{U}^\mathrm{i}_{12} \\ 2 \dot{U}^\mathrm{i}_{23} \\ 2 \dot{U}^\mathrm{i}_{31} \\ {{U}^\mathrm{i}}^{-1}_{11} \\ {{U}^\mathrm{i}}^{-1}_{22} \\ {{U}^\mathrm{i}}^{-1}_{33} \\ 2 {{U}^\mathrm{i}}^{-1}_{12} \\ 2 {{U}^\mathrm{i}}^{-1}_{23} \\ 2 {{U}^\mathrm{i}}^{-1}_{31} \\ F_{11} \\ F_{12} \\ F_{13} \\ F_{21} \\ F_{22} \\ F_{23} \\ F_{31} \\ F_{32} \\ F_{33} \\ F^{-1}_{11} \\ F^{-1}_{12} \\ F^{-1}_{13} \\ F^{-1}_{21} \\ F^{-1}_{22} \\ F^{-1}_{23} \\ F^{-1}_{31} \\ F^{-1}_{32} \\ F^{-1}_{33} \end{pmatrix} \f$.
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

/**
 * Implementation of the elastic free energy function \f$\rho_0 \Psi^\mathrm{mech} = \dfrac{\mu^\mathrm{e}}{2} F_{ij} F_{ij} + \dfrac{\mu^\mathrm{i}}{2} {U^\mathrm{i}}^{-1}_{ik} F_{lk} F_{lm} {U^\mathrm{i}}^{-1}_{mi} \f$,
 * where \f${U^\mathrm{i}}^{-1}_{kl}\f$ is symmetric, while \f$F_{kl}\f$ is unsymmetric, and \f$\mu^\mathrm{e}>0\f$ and \f$\mu^\mathrm{i}>0\f$ are material parameters.
 *
 * Order of arguments:<br>	[0]	 \f$F_{11}\f$<br>
 * 							[1]	 \f$F_{12}\f$<br>
 * 							[2]	 \f$F_{13}\f$<br>
 * 							[3]	 \f$F_{21}\f$<br>
 * 							[4]	 \f$F_{22}\f$<br>
 * 							[5]	 \f$F_{23}\f$<br>
 * 							[6]	 \f$F_{31}\f$<br>
 * 							[7]	 \f$F_{32}\f$<br>
 * 							[8]	 \f$F_{33}\f$<br>
 * 							[9]  \f${{U}^\mathrm{i}}^{-1}_{11}\f$<br>
 * 							[10] \f${{U}^\mathrm{i}}^{-1}_{22}\f$<br>
 * 							[11] \f${{U}^\mathrm{i}}^{-1}_{33}\f$<br>
 * 							[12] \f$2 {{U}^\mathrm{i}}^{-1}_{12}\f$<br>
 * 							[13] \f$2 {{U}^\mathrm{i}}^{-1}_{23}\f$<br>
 * 							[14] \f$2 {{U}^\mathrm{i}}^{-1}_{31}\f$
 *
 * Order of parameters:<br>	[0]	 \f$x_1\f$<br>
 * 							[1]	 \f$x_2\f$<br>
 * 							[2]	 \f$x_3\f$<br>
 */
class PsiMech : public CMF::ScalarFunction<double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd>
{

private:

	/**
	 * Material parameter
	 */
	const double
	mu_e;

	/**
	 * Material parameter
	 */
	const double
	mu_i;

public:

	/**
	 * Constructor.
	 *
	 * @param[in]	argument_set	The names of the arguments
	 *
	 * @param[in]	parameter_set	The names of the parameters
	 *
	 * @param[in]	mu_e			The material parameter \f$\mu^\mathrm{e}\f$
	 *
	 * @param[in]	mu_i			The material parameter \f$\mu^\mathrm{i}\f$
	 *
	 */
	PsiMech(const CMF::VariableSet	argument_set,
			const CMF::VariableSet	parameter_set,
			const double			mu_e,
			const double			mu_i);

	/**
	 * See CMF::Function::compute()
	 */
	bool
	compute(double&				value,
			Eigen::VectorXd&	gradient,
			Eigen::MatrixXd&	hessian,
			const bool			update_value,
			const bool			update_gradient,
			const bool			update_hessian)
	override
	final;
};

/**
 * Implementation of the electrostatic free energy function \f$\rho_0 \Psi^\mathrm{elec} = -\dfrac{1}{2\epsilon} E_i F^{-1}_{ik} F^{-1}_{jk} E_j \f$,
 * where \f$F_{kl}\f$ is unsymmetric, and \f$\epsilon>0\f$ is a material parameter.
 *
 * Order of arguments:<br>	[0]	 \f$E_{1}\f$<br>
 * 							[1]	 \f$E_{2}\f$<br>
 * 							[2]	 \f$E_{3}\f$<br>
 * 							[3]	 \f$F^{-1}_{11}\f$<br>
 * 							[4]	 \f$F^{-1}_{12}\f$<br>
 * 							[5]	 \f$F^{-1}_{13}\f$<br>
 * 							[6]	 \f$F^{-1}_{21}\f$<br>
 * 							[7]	 \f$F^{-1}_{22}\f$<br>
 * 							[8]	 \f$F^{-1}_{23}\f$<br>
 * 							[9]	 \f$F^{-1}_{31}\f$<br>
 * 							[10] \f$F^{-1}_{32}\f$<br>
 * 							[11] \f$F^{-1}_{33}\f$
 *
 * Order of parameters:<br>	[0]	 \f$x_1\f$<br>
 * 							[1]	 \f$x_2\f$<br>
 * 							[2]	 \f$x_3\f$<br>
 */
class PsiElec : public CMF::ScalarFunction<double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd>
{

private:

	/**
	 * Material parameter
	 */
	const double
	epsilon;

public:

	/**
	 * Constructor.
	 *
	 * @param[in]	argument_set	The names of the arguments
	 *
	 * @param[in]	parameter_set	The names of the parameters
	 *
	 * @param[in]	epsilon			The material parameter \f$\epsilon\f$
	 *
	 */
	PsiElec(const CMF::VariableSet	argument_set,
			const CMF::VariableSet	parameter_set,
			const double			epsilon);

	/**
	 * See CMF::Function::compute()
	 */
	bool
	compute(double&				value,
			Eigen::VectorXd&	gradient,
			Eigen::MatrixXd&	hessian,
			const bool			update_value,
			const bool			update_gradient,
			const bool			update_hessian)
	override
	final;
};

/**
 * Implementation of the elastic surface free energy function \f$\rho_0 \Psi^\mathrm{surf} = \dfrac{1}{8} \lambda^\mathrm{S} ( C^\mathrm{S}_{kk} - 2)^2 + \dfrac{1}{4} \mu^\mathrm{S} ( C^\mathrm{S}_{ki}C^\mathrm{S}_{ik} - 2 C^\mathrm{S}_{kk} + 2) \f$,
 * where \f$C^\mathrm{S}_{kl} = F^\mathrm{S}_{ik} F^\mathrm{S}_{il}\f$, and \f$F^\mathrm{S}_{kl} = u^\mathrm{S}_{k,l} + \delta_{kl}- n_k n_l\f$. In the latter formula, \f$u^\mathrm{S}_{k,l}\f$ is the surface gradient of the vector field \f$u^\mathrm{S}_k\f$, which is defined on a surface.
 * Furthermore, \f$n_k\f$ is the outward normal vector on the surface.
 *
 * Order of arguments:<br>	[0] \f$u^\mathrm{S}_{1,1}\f$<br>
 * 							[1] \f$u^\mathrm{S}_{1,2}\f$<br>
 * 							[2] \f$u^\mathrm{S}_{1,3}\f$<br>
 * 							[3] \f$u^\mathrm{S}_{2,1}\f$<br>
 * 							[4] \f$u^\mathrm{S}_{2,2}\f$<br>
 * 							[5] \f$u^\mathrm{S}_{2,3}\f$<br>
 * 							[6] \f$u^\mathrm{S}_{3,1}\f$<br>
 * 							[7] \f$u^\mathrm{S}_{3,2}\f$<br>
 * 							[8] \f$u^\mathrm{S}_{3,3}\f$
 *
 * Order of parameters:<br>	[0]	\f$x_1\f$<br>
 * 							[1]	\f$x_2\f$<br>
 * 							[2]	\f$x_3\f$<br>
 * 							[3] \f$n_{1}\f$<br>
 * 							[4] \f$n_{2}\f$<br>
 * 							[5] \f$n_{3}\f$<br>
 */
class PsiSurf : public CMF::ScalarFunction<double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd>
{

private:

	/**
	 * Material parameter
	 */
	const double
	lambda_S;

	/**
	 * Material parameter
	 */
	const double
	mu_S;

public:

	/**
	 * Constructor.
	 *
	 * @param[in]	argument_set	The names of the arguments
	 *
	 * @param[in]	parameter_set	The names of the parameters
	 *
	 * @param[in]	lambda_S		The material parameter \f$\lambda^\mathrm{S}\f$
	 *
	 * @param[in]	mu_S			The material parameter \f$\mu^\mathrm{S}\f$
	 *
	 */
	PsiSurf(const CMF::VariableSet	argument_set,
			const CMF::VariableSet	parameter_set,
			const double			lambda_S,
			const double			mu_S);

	/**
	 * See CMF::Function::compute()
	 */
	bool
	compute(double&				value,
			Eigen::VectorXd&	gradient,
			Eigen::MatrixXd&	hessian,
			const bool			update_value,
			const bool			update_gradient,
			const bool			update_hessian)
	override
	final;
};

/**
 * Implementation of the dissipation function \f$\rho_0 \Delta^\eta = \eta d_{ij}d_{ij}\f$,
 * where \f$\eta>0\f$ is a material parameter and \f$d_{ij}\f$ is symmetric.
 *
 * Order of arguments:<br>	[0]	 \f$d^\mathrm{i}_{11}\f$<br>
 * 							[1]	 \f$d^\mathrm{i}_{22}\f$<br>
 * 							[2]	 \f$d^\mathrm{i}_{33}\f$<br>
 * 							[3]	 \f$2 d^\mathrm{i}_{12}\f$<br>
 * 							[4]	 \f$2 d^\mathrm{i}_{23}\f$<br>
 * 							[5]	 \f$2 d^\mathrm{i}_{31}\f$<br>
 *
 * Order of parameters:<br>	[0] Time \f$t\f$<br>
 * 							[1]	\f$x_1\f$<br>
 * 							[2]	\f$x_2\f$<br>
 * 							[3]	\f$x_3\f$<br>
 */
class DeltaEta : public CMF::ScalarFunction<double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd>
{

private:

	/**
	 * Material parameter
	 */
	const double
	eta;

public:

	/**
	 * Constructor.
	 *
	 * @param[in]	argument_set	The names of the arguments
	 *
	 * @param[in]	parameter_set	The names of the parameters
	 *
	 * @param[in]	eta				Material parameter \f$\eta\f$
	 *
	 */
	DeltaEta(	const CMF::VariableSet	argument_set,
				const CMF::VariableSet	parameter_set,
				const double			eta);

	/**
	 * See CMF::Function::compute()
	 */
	bool
	compute(double&				value,
			Eigen::VectorXd&	gradient,
			Eigen::MatrixXd&	hessian,
			const bool			update_value,
			const bool			update_gradient,
			const bool			update_hessian)
	override
	final;
};

}

#endif /* INCLUDE_DEMODEL_DEMODEL_H_ */
