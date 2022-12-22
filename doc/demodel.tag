<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>mainpage.dox</name>
    <path>/home/sst/code/demodel/doc/</path>
    <filename>mainpage_8dox.html</filename>
  </compound>
  <compound kind="file">
    <name>demodel.h</name>
    <path>/home/sst/code/demodel/include/demodel/</path>
    <filename>demodel_8h.html</filename>
    <class kind="class">DEModel::Transformationdi</class>
    <class kind="class">DEModel::PsiMech</class>
    <namespace>DEModel</namespace>
  </compound>
  <compound kind="class">
    <name>DEModel::PsiMech</name>
    <filename>class_d_e_model_1_1_psi_mech.html</filename>
    <base>CMF::ScalarFunction&lt; double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</base>
    <member kind="function">
      <type></type>
      <name>PsiMech</name>
      <anchorfile>class_d_e_model_1_1_psi_mech.html</anchorfile>
      <anchor>afdf133b808e7694b77885b37c6aa42db</anchor>
      <arglist>(const CMF::VariableSet argument_set, const CMF::VariableSet parameter_set, const double mu_e, const double mu_i)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute</name>
      <anchorfile>class_d_e_model_1_1_psi_mech.html</anchorfile>
      <anchor>a3966a8d47b4157ecbabfc2a181fdaa6a</anchor>
      <arglist>(double &amp;value, Eigen::VectorXd &amp;gradient, Eigen::MatrixXd &amp;hessian, const bool update_value, const bool update_gradient, const bool update_hessian) override final</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const double</type>
      <name>mu_e</name>
      <anchorfile>class_d_e_model_1_1_psi_mech.html</anchorfile>
      <anchor>aac8778ae5fb4ae23e01479ee2985e51f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const double</type>
      <name>mu_i</name>
      <anchorfile>class_d_e_model_1_1_psi_mech.html</anchorfile>
      <anchor>a2d6d73f5d4a32dccf4442c20fd053da0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DEModel::Transformationdi</name>
    <filename>class_d_e_model_1_1_transformationdi.html</filename>
    <base>CMF::VariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</base>
    <member kind="function">
      <type></type>
      <name>Transformationdi</name>
      <anchorfile>class_d_e_model_1_1_transformationdi.html</anchorfile>
      <anchor>ae91ddc992aac84114e185cbda08611a6</anchor>
      <arglist>(const CMF::VariableSet value_set, const CMF::VariableSet argument_set)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute</name>
      <anchorfile>class_d_e_model_1_1_transformationdi.html</anchorfile>
      <anchor>a8524c981184775047ae91e8ec96e663f</anchor>
      <arglist>(Eigen::VectorXd &amp;value, Eigen::MatrixXd &amp;gradient, Eigen::MatrixXd &amp;hessian, const bool update_value, const bool update_gradient, const bool update_hessian) override final</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>DEModel</name>
    <filename>namespace_d_e_model.html</filename>
    <class kind="class">DEModel::PsiMech</class>
    <class kind="class">DEModel::Transformationdi</class>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title>SinterModel Documentation</title>
    <filename>index</filename>
  </compound>
</tagfile>
