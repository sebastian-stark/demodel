<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile doxygen_version="1.9.1" doxygen_gitid="ef9b20ac7f8a8621fcfc299f8bd0b80422390f4b">
  <compound kind="file">
    <name>mainpage.dox</name>
    <path>C:/Users/seb45399/code/cmf/doc/</path>
    <filename>mainpage_8dox.html</filename>
  </compound>
  <compound kind="file">
    <name>config.h</name>
    <path>C:/Users/seb45399/code/cmf/include/cmf/</path>
    <filename>config_8h.html</filename>
  </compound>
  <compound kind="file">
    <name>derivative_transform_lib.h</name>
    <path>C:/Users/seb45399/code/cmf/include/cmf/</path>
    <filename>derivative__transform__lib_8h.html</filename>
    <class kind="class">CMF::TransformationInverseSymmetricRank2Tensor</class>
    <class kind="class">CMF::TransformationDeterminantSymmetricMatrix</class>
    <class kind="class">CMF::TransformationIdentity</class>
    <namespace>CMF</namespace>
  </compound>
  <compound kind="file">
    <name>function.h</name>
    <path>C:/Users/seb45399/code/cmf/include/cmf/</path>
    <filename>function_8h.html</filename>
    <class kind="class">CMF::Function</class>
    <namespace>CMF</namespace>
  </compound>
  <compound kind="file">
    <name>scalar_function.h</name>
    <path>C:/Users/seb45399/code/cmf/include/cmf/</path>
    <filename>scalar__function_8h.html</filename>
    <class kind="class">CMF::ScalarFunction</class>
    <class kind="class">CMF::ScalarFunction&lt; double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</class>
    <class kind="class">CMF::TransformedScalarFunctionBase</class>
    <class kind="class">CMF::TransformedScalarFunction</class>
    <class kind="class">CMF::TransformedScalarFunction&lt; double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</class>
    <namespace>CMF</namespace>
  </compound>
  <compound kind="file">
    <name>variable_set.h</name>
    <path>C:/Users/seb45399/code/cmf/include/cmf/</path>
    <filename>variable__set_8h.html</filename>
    <class kind="class">CMF::VariableSet</class>
    <namespace>CMF</namespace>
  </compound>
  <compound kind="file">
    <name>variable_transform_function.h</name>
    <path>C:/Users/seb45399/code/cmf/include/cmf/</path>
    <filename>variable__transform__function_8h.html</filename>
    <class kind="class">CMF::VariableTransformFunctionBase</class>
    <class kind="class">CMF::VariableTransformFunction</class>
    <class kind="class">CMF::VariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</class>
    <class kind="class">CMF::CombinedVariableTransformFunctionBase</class>
    <class kind="class">CMF::CombinedVariableTransformFunction</class>
    <class kind="class">CMF::CombinedVariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</class>
    <namespace>CMF</namespace>
  </compound>
  <compound kind="file">
    <name>vector_function.h</name>
    <path>C:/Users/seb45399/code/cmf/include/cmf/</path>
    <filename>vector__function_8h.html</filename>
    <class kind="class">CMF::VectorFunction</class>
    <namespace>CMF</namespace>
  </compound>
  <compound kind="class">
    <name>CMF::CombinedVariableTransformFunction</name>
    <filename>class_c_m_f_1_1_combined_variable_transform_function.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <base>CombinedVariableTransformFunctionBase&lt; ValueType, GradientType, HessianType, GradientType, GradientType &gt;</base>
  </compound>
  <compound kind="class">
    <name>CMF::CombinedVariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</name>
    <filename>class_c_m_f_1_1_combined_variable_transform_function_3_01_eigen_1_1_vector_xd_00_01_eigen_1_1_maf41d66ed174fe8db6a909d8e7e927b15.html</filename>
    <base>CombinedVariableTransformFunctionBase&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</base>
    <member kind="function">
      <type></type>
      <name>CombinedVariableTransformFunction</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_3_01_eigen_1_1_vector_xd_00_01_eigen_1_1_maf41d66ed174fe8db6a909d8e7e927b15.html</anchorfile>
      <anchor>a3cd2116964223423a12034c2899d5d85</anchor>
      <arglist>(const std::vector&lt; VariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt; * &gt; variable_transforms)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_3_01_eigen_1_1_vector_xd_00_01_eigen_1_1_maf41d66ed174fe8db6a909d8e7e927b15.html</anchorfile>
      <anchor>a2356081bb4c4a6ecd57daecf8ef0151b</anchor>
      <arglist>(Eigen::VectorXd &amp;value, Eigen::MatrixXd &amp;gradient, Eigen::MatrixXd &amp;hessian, const bool update_value, const bool update_gradient, const bool update_hessian) override final</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CMF::CombinedVariableTransformFunctionBase</name>
    <filename>class_c_m_f_1_1_combined_variable_transform_function_base.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <base>VariableTransformFunction&lt; ValueType, GradientType, HessianType, GradientType, GradientType &gt;</base>
    <member kind="function">
      <type></type>
      <name>CombinedVariableTransformFunctionBase</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>abb31405d7e2f58c4df8c3a10ee736cd2</anchor>
      <arglist>(const std::vector&lt; VariableTransformFunction&lt; ValueType, GradientType, HessianType, ArgumentType, ParameterType &gt; * &gt; variable_transforms)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const std::vector&lt; VariableTransformFunction&lt; ValueType, GradientType, HessianType, ArgumentType, ParameterType &gt; * &gt;</type>
      <name>variable_transforms</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>aa88925c8d12776f7b99e4d50c0d079ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const std::vector&lt; std::vector&lt; unsigned int &gt; &gt;</type>
      <name>value_map</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>ab756201935d98ac3061d9f6486d9f682</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const std::vector&lt; std::vector&lt; unsigned int &gt; &gt;</type>
      <name>argument_map</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a5090e07dfc0915d6086ebb874a97f7af</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>post_set_arguments</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a9f3bedc7a1f4798f486748fb86e05c3a</anchor>
      <arglist>() override final</arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>post_set_v</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a85961917d1c0d922b0f63ce3d4efc3b5</anchor>
      <arglist>() override final</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static VariableSet</type>
      <name>get_value_set_init</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a577c39afb245fccc5142c7443170a0d0</anchor>
      <arglist>(const std::vector&lt; VariableTransformFunction&lt; ValueType, GradientType, HessianType, ArgumentType, ParameterType &gt; * &gt; &amp;variable_transforms)</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static VariableSet</type>
      <name>get_argument_set_init</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a20e059128adc1f360234a8ee985e6244</anchor>
      <arglist>(const std::vector&lt; VariableTransformFunction&lt; ValueType, GradientType, HessianType, ArgumentType, ParameterType &gt; * &gt; &amp;variable_transforms)</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static std::vector&lt; std::vector&lt; unsigned int &gt; &gt;</type>
      <name>get_value_map</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>ac9e62a2e08aa648d5519fa754dfc069d</anchor>
      <arglist>(const std::vector&lt; VariableTransformFunction&lt; ValueType, GradientType, HessianType, ArgumentType, ParameterType &gt; * &gt; &amp;variable_transforms)</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static std::vector&lt; std::vector&lt; unsigned int &gt; &gt;</type>
      <name>get_argument_map</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a915fc13f62ebfd218ef5f3d57667edb6</anchor>
      <arglist>(const std::vector&lt; VariableTransformFunction&lt; ValueType, GradientType, HessianType, ArgumentType, ParameterType &gt; * &gt; &amp;variable_transforms)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CombinedVariableTransformFunctionBase&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</name>
    <filename>class_c_m_f_1_1_combined_variable_transform_function_base.html</filename>
    <base>CMF::VariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</base>
    <member kind="function">
      <type></type>
      <name>CombinedVariableTransformFunctionBase</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>abb31405d7e2f58c4df8c3a10ee736cd2</anchor>
      <arglist>(const std::vector&lt; VariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt; * &gt; variable_transforms)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const std::vector&lt; VariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt; * &gt;</type>
      <name>variable_transforms</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>aa88925c8d12776f7b99e4d50c0d079ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const std::vector&lt; std::vector&lt; unsigned int &gt; &gt;</type>
      <name>value_map</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>ab756201935d98ac3061d9f6486d9f682</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const std::vector&lt; std::vector&lt; unsigned int &gt; &gt;</type>
      <name>argument_map</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a5090e07dfc0915d6086ebb874a97f7af</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>post_set_arguments</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a9f3bedc7a1f4798f486748fb86e05c3a</anchor>
      <arglist>() override final</arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>post_set_v</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a85961917d1c0d922b0f63ce3d4efc3b5</anchor>
      <arglist>() override final</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static VariableSet</type>
      <name>get_value_set_init</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a577c39afb245fccc5142c7443170a0d0</anchor>
      <arglist>(const std::vector&lt; VariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt; * &gt; &amp;variable_transforms)</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static VariableSet</type>
      <name>get_argument_set_init</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a20e059128adc1f360234a8ee985e6244</anchor>
      <arglist>(const std::vector&lt; VariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt; * &gt; &amp;variable_transforms)</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static std::vector&lt; std::vector&lt; unsigned int &gt; &gt;</type>
      <name>get_value_map</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>ac9e62a2e08aa648d5519fa754dfc069d</anchor>
      <arglist>(const std::vector&lt; VariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt; * &gt; &amp;variable_transforms)</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static std::vector&lt; std::vector&lt; unsigned int &gt; &gt;</type>
      <name>get_argument_map</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a915fc13f62ebfd218ef5f3d57667edb6</anchor>
      <arglist>(const std::vector&lt; VariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt; * &gt; &amp;variable_transforms)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CombinedVariableTransformFunctionBase&lt; ValueType, GradientType, HessianType, GradientType, GradientType &gt;</name>
    <filename>class_c_m_f_1_1_combined_variable_transform_function_base.html</filename>
    <base>VariableTransformFunction&lt; ValueType, GradientType, HessianType, GradientType, GradientType &gt;</base>
    <member kind="function">
      <type></type>
      <name>CombinedVariableTransformFunctionBase</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>abb31405d7e2f58c4df8c3a10ee736cd2</anchor>
      <arglist>(const std::vector&lt; VariableTransformFunction&lt; ValueType, GradientType, HessianType, GradientType, GradientType &gt; * &gt; variable_transforms)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const std::vector&lt; VariableTransformFunction&lt; ValueType, GradientType, HessianType, GradientType, GradientType &gt; * &gt;</type>
      <name>variable_transforms</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>aa88925c8d12776f7b99e4d50c0d079ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const std::vector&lt; std::vector&lt; unsigned int &gt; &gt;</type>
      <name>value_map</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>ab756201935d98ac3061d9f6486d9f682</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const std::vector&lt; std::vector&lt; unsigned int &gt; &gt;</type>
      <name>argument_map</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a5090e07dfc0915d6086ebb874a97f7af</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>post_set_arguments</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a9f3bedc7a1f4798f486748fb86e05c3a</anchor>
      <arglist>() override final</arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>post_set_v</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a85961917d1c0d922b0f63ce3d4efc3b5</anchor>
      <arglist>() override final</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static VariableSet</type>
      <name>get_value_set_init</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a577c39afb245fccc5142c7443170a0d0</anchor>
      <arglist>(const std::vector&lt; VariableTransformFunction&lt; ValueType, GradientType, HessianType, GradientType, GradientType &gt; * &gt; &amp;variable_transforms)</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static VariableSet</type>
      <name>get_argument_set_init</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a20e059128adc1f360234a8ee985e6244</anchor>
      <arglist>(const std::vector&lt; VariableTransformFunction&lt; ValueType, GradientType, HessianType, GradientType, GradientType &gt; * &gt; &amp;variable_transforms)</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static std::vector&lt; std::vector&lt; unsigned int &gt; &gt;</type>
      <name>get_value_map</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>ac9e62a2e08aa648d5519fa754dfc069d</anchor>
      <arglist>(const std::vector&lt; VariableTransformFunction&lt; ValueType, GradientType, HessianType, GradientType, GradientType &gt; * &gt; &amp;variable_transforms)</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static std::vector&lt; std::vector&lt; unsigned int &gt; &gt;</type>
      <name>get_argument_map</name>
      <anchorfile>class_c_m_f_1_1_combined_variable_transform_function_base.html</anchorfile>
      <anchor>a915fc13f62ebfd218ef5f3d57667edb6</anchor>
      <arglist>(const std::vector&lt; VariableTransformFunction&lt; ValueType, GradientType, HessianType, GradientType, GradientType &gt; * &gt; &amp;variable_transforms)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CMF::Function</name>
    <filename>class_c_m_f_1_1_function.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>Function</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a4019d0b060bea59d5b24360c3283ca9b</anchor>
      <arglist>(const VariableSet argument_set, const VariableSet parameter_set)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>set_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>abd98c028d32ed2784e3d71e940a84dc1</anchor>
      <arglist>(const ArgumentType &amp;arguments)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>set_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a62637a97e68f3712ff432233b47477fd</anchor>
      <arglist>(const ParameterType &amp;parameters)</arglist>
    </member>
    <member kind="function">
      <type>const ArgumentType &amp;</type>
      <name>get_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>aab01888d90c1c0b7e22935acf8b5c3dc</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const ParameterType &amp;</type>
      <name>get_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a0cc0cf2b4c7545c78076834714702105</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const VariableSet &amp;</type>
      <name>get_argument_set</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a2984e50ec4a1de34c310fd9cdb4653cf</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const VariableSet &amp;</type>
      <name>get_parameter_set</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a75f8b475a84ccf3ae76089c0cf7dc704</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>get_N_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>aea474b9d64a093206789d2f1b78732d1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>get_N_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a3b9ec78bbe76caa2b41d424050242426</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>compute</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>affd176606b14cbeede5f3cf164716dff</anchor>
      <arglist>(ValueType &amp;value, GradientType &amp;gradient, HessianType &amp;hessian, const bool update_value=true, const bool update_gradient=true, const bool update_hessian=true)=0</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_value</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a05e8201870164fc63c14201cfc630171</anchor>
      <arglist>(ValueType &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_gradient</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a45a837ef26365b07aad28eaff534aec2</anchor>
      <arglist>(GradientType &amp;gradient)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_hessian</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a7aafb8301aeb32f91b7c0f5c14776198</anchor>
      <arglist>(HessianType &amp;hessian)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_value_gradient</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ad0f33cfce5b5aeb5e2f66ba19fea0939</anchor>
      <arglist>(ValueType &amp;value, GradientType &amp;gradient)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_value_hessian</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a3082e181c6160819fd8f2a3915980b07</anchor>
      <arglist>(ValueType &amp;value, HessianType &amp;hessian)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_gradient_hessian</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a30f837362b5f9dfb7e9daab962135cef</anchor>
      <arglist>(GradientType &amp;gradient, HessianType &amp;hessian)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_value_gradient_hessian</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ae2bdf7e66f37320d66bb0b6962a3616c</anchor>
      <arglist>(ValueType &amp;value, GradientType &amp;gradient, HessianType &amp;hessian)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_check_domain</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>af8d6d05b7f35f15243fa9a6f3c34a146</anchor>
      <arglist>(const bool check_domain)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>is_in_domain</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ad1694962f86f11d6ac57dab9db2c71a4</anchor>
      <arglist>(const ArgumentType &amp;arguments) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Function</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>aafc2c4e2dc33dcead6666b68107d02a1</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>post_set_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>aac1c809e04e3b171be97fb2760a62c11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>post_set_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ac3faa1103501d3caabea0a3a48808a66</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const VariableSet</type>
      <name>argument_set</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a7810b5054666cabf38b32fbbe941f0c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const VariableSet</type>
      <name>parameter_set</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>acdbf1c4858302a02c4b3e4e7a1372fa6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const unsigned int</type>
      <name>N_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a0fce7368fcc6673d4db7e7d9d16124e7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const unsigned int</type>
      <name>N_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ab1afd4944ce21b157d6117ecabf6cf57</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>check_domain</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a408758263057f977068606042eef7664</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ArgumentType</type>
      <name>arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ae9b681025ed2daa8a3a7b17b1c353ee1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ParameterType</type>
      <name>parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>af2a61c22d18e67c5dc4b5cd1d893bf8d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Function&lt; double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</name>
    <filename>class_c_m_f_1_1_function.html</filename>
    <member kind="function">
      <type></type>
      <name>Function</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a4019d0b060bea59d5b24360c3283ca9b</anchor>
      <arglist>(const VariableSet argument_set, const VariableSet parameter_set)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>set_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>abd98c028d32ed2784e3d71e940a84dc1</anchor>
      <arglist>(const Eigen::VectorXd &amp;arguments)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>set_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a62637a97e68f3712ff432233b47477fd</anchor>
      <arglist>(const Eigen::VectorXd &amp;parameters)</arglist>
    </member>
    <member kind="function">
      <type>const Eigen::VectorXd &amp;</type>
      <name>get_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>aab01888d90c1c0b7e22935acf8b5c3dc</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const Eigen::VectorXd &amp;</type>
      <name>get_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a0cc0cf2b4c7545c78076834714702105</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const VariableSet &amp;</type>
      <name>get_argument_set</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a2984e50ec4a1de34c310fd9cdb4653cf</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const VariableSet &amp;</type>
      <name>get_parameter_set</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a75f8b475a84ccf3ae76089c0cf7dc704</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>get_N_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>aea474b9d64a093206789d2f1b78732d1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>get_N_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a3b9ec78bbe76caa2b41d424050242426</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>compute</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>affd176606b14cbeede5f3cf164716dff</anchor>
      <arglist>(double &amp;value, Eigen::VectorXd &amp;gradient, Eigen::MatrixXd &amp;hessian, const bool update_value=true, const bool update_gradient=true, const bool update_hessian=true)=0</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_value</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a05e8201870164fc63c14201cfc630171</anchor>
      <arglist>(double &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_gradient</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a45a837ef26365b07aad28eaff534aec2</anchor>
      <arglist>(Eigen::VectorXd &amp;gradient)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_hessian</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a7aafb8301aeb32f91b7c0f5c14776198</anchor>
      <arglist>(Eigen::MatrixXd &amp;hessian)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_value_gradient</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ad0f33cfce5b5aeb5e2f66ba19fea0939</anchor>
      <arglist>(double &amp;value, Eigen::VectorXd &amp;gradient)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_value_hessian</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a3082e181c6160819fd8f2a3915980b07</anchor>
      <arglist>(double &amp;value, Eigen::MatrixXd &amp;hessian)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_gradient_hessian</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a30f837362b5f9dfb7e9daab962135cef</anchor>
      <arglist>(Eigen::VectorXd &amp;gradient, Eigen::MatrixXd &amp;hessian)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_value_gradient_hessian</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ae2bdf7e66f37320d66bb0b6962a3616c</anchor>
      <arglist>(double &amp;value, Eigen::VectorXd &amp;gradient, Eigen::MatrixXd &amp;hessian)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_check_domain</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>af8d6d05b7f35f15243fa9a6f3c34a146</anchor>
      <arglist>(const bool check_domain)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>is_in_domain</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ad1694962f86f11d6ac57dab9db2c71a4</anchor>
      <arglist>(const Eigen::VectorXd &amp;arguments) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Function</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>aafc2c4e2dc33dcead6666b68107d02a1</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>post_set_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>aac1c809e04e3b171be97fb2760a62c11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>post_set_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ac3faa1103501d3caabea0a3a48808a66</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const VariableSet</type>
      <name>argument_set</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a7810b5054666cabf38b32fbbe941f0c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const VariableSet</type>
      <name>parameter_set</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>acdbf1c4858302a02c4b3e4e7a1372fa6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const unsigned int</type>
      <name>N_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a0fce7368fcc6673d4db7e7d9d16124e7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const unsigned int</type>
      <name>N_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ab1afd4944ce21b157d6117ecabf6cf57</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>check_domain</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a408758263057f977068606042eef7664</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ae9b681025ed2daa8a3a7b17b1c353ee1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>af2a61c22d18e67c5dc4b5cd1d893bf8d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Function&lt; ValueType, GradientType, HessianType, ArgumentType, ArgumentType &gt;</name>
    <filename>class_c_m_f_1_1_function.html</filename>
    <member kind="function">
      <type></type>
      <name>Function</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a4019d0b060bea59d5b24360c3283ca9b</anchor>
      <arglist>(const VariableSet argument_set, const VariableSet parameter_set)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>set_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>abd98c028d32ed2784e3d71e940a84dc1</anchor>
      <arglist>(const ArgumentType &amp;arguments)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>set_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a62637a97e68f3712ff432233b47477fd</anchor>
      <arglist>(const ArgumentType &amp;parameters)</arglist>
    </member>
    <member kind="function">
      <type>const ArgumentType &amp;</type>
      <name>get_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>aab01888d90c1c0b7e22935acf8b5c3dc</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const ArgumentType &amp;</type>
      <name>get_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a0cc0cf2b4c7545c78076834714702105</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const VariableSet &amp;</type>
      <name>get_argument_set</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a2984e50ec4a1de34c310fd9cdb4653cf</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const VariableSet &amp;</type>
      <name>get_parameter_set</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a75f8b475a84ccf3ae76089c0cf7dc704</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>get_N_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>aea474b9d64a093206789d2f1b78732d1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>get_N_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a3b9ec78bbe76caa2b41d424050242426</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>compute</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>affd176606b14cbeede5f3cf164716dff</anchor>
      <arglist>(ValueType &amp;value, GradientType &amp;gradient, HessianType &amp;hessian, const bool update_value=true, const bool update_gradient=true, const bool update_hessian=true)=0</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_value</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a05e8201870164fc63c14201cfc630171</anchor>
      <arglist>(ValueType &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_gradient</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a45a837ef26365b07aad28eaff534aec2</anchor>
      <arglist>(GradientType &amp;gradient)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_hessian</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a7aafb8301aeb32f91b7c0f5c14776198</anchor>
      <arglist>(HessianType &amp;hessian)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_value_gradient</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ad0f33cfce5b5aeb5e2f66ba19fea0939</anchor>
      <arglist>(ValueType &amp;value, GradientType &amp;gradient)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_value_hessian</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a3082e181c6160819fd8f2a3915980b07</anchor>
      <arglist>(ValueType &amp;value, HessianType &amp;hessian)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_gradient_hessian</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a30f837362b5f9dfb7e9daab962135cef</anchor>
      <arglist>(GradientType &amp;gradient, HessianType &amp;hessian)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_value_gradient_hessian</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ae2bdf7e66f37320d66bb0b6962a3616c</anchor>
      <arglist>(ValueType &amp;value, GradientType &amp;gradient, HessianType &amp;hessian)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_check_domain</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>af8d6d05b7f35f15243fa9a6f3c34a146</anchor>
      <arglist>(const bool check_domain)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>is_in_domain</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ad1694962f86f11d6ac57dab9db2c71a4</anchor>
      <arglist>(const ArgumentType &amp;arguments) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Function</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>aafc2c4e2dc33dcead6666b68107d02a1</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>post_set_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>aac1c809e04e3b171be97fb2760a62c11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>post_set_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ac3faa1103501d3caabea0a3a48808a66</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const VariableSet</type>
      <name>argument_set</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a7810b5054666cabf38b32fbbe941f0c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const VariableSet</type>
      <name>parameter_set</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>acdbf1c4858302a02c4b3e4e7a1372fa6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const unsigned int</type>
      <name>N_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a0fce7368fcc6673d4db7e7d9d16124e7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const unsigned int</type>
      <name>N_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ab1afd4944ce21b157d6117ecabf6cf57</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>check_domain</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a408758263057f977068606042eef7664</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ArgumentType</type>
      <name>arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ae9b681025ed2daa8a3a7b17b1c353ee1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ArgumentType</type>
      <name>parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>af2a61c22d18e67c5dc4b5cd1d893bf8d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Function&lt; ValueType, GradientType, HessianType, GradientType, GradientType &gt;</name>
    <filename>class_c_m_f_1_1_function.html</filename>
    <member kind="function">
      <type></type>
      <name>Function</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a4019d0b060bea59d5b24360c3283ca9b</anchor>
      <arglist>(const VariableSet argument_set, const VariableSet parameter_set)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>set_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>abd98c028d32ed2784e3d71e940a84dc1</anchor>
      <arglist>(const GradientType &amp;arguments)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>set_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a62637a97e68f3712ff432233b47477fd</anchor>
      <arglist>(const GradientType &amp;parameters)</arglist>
    </member>
    <member kind="function">
      <type>const GradientType &amp;</type>
      <name>get_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>aab01888d90c1c0b7e22935acf8b5c3dc</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const GradientType &amp;</type>
      <name>get_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a0cc0cf2b4c7545c78076834714702105</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const VariableSet &amp;</type>
      <name>get_argument_set</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a2984e50ec4a1de34c310fd9cdb4653cf</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const VariableSet &amp;</type>
      <name>get_parameter_set</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a75f8b475a84ccf3ae76089c0cf7dc704</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>get_N_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>aea474b9d64a093206789d2f1b78732d1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>get_N_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a3b9ec78bbe76caa2b41d424050242426</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>compute</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>affd176606b14cbeede5f3cf164716dff</anchor>
      <arglist>(ValueType &amp;value, GradientType &amp;gradient, HessianType &amp;hessian, const bool update_value=true, const bool update_gradient=true, const bool update_hessian=true)=0</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_value</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a05e8201870164fc63c14201cfc630171</anchor>
      <arglist>(ValueType &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_gradient</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a45a837ef26365b07aad28eaff534aec2</anchor>
      <arglist>(GradientType &amp;gradient)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_hessian</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a7aafb8301aeb32f91b7c0f5c14776198</anchor>
      <arglist>(HessianType &amp;hessian)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_value_gradient</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ad0f33cfce5b5aeb5e2f66ba19fea0939</anchor>
      <arglist>(ValueType &amp;value, GradientType &amp;gradient)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_value_hessian</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a3082e181c6160819fd8f2a3915980b07</anchor>
      <arglist>(ValueType &amp;value, HessianType &amp;hessian)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_gradient_hessian</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a30f837362b5f9dfb7e9daab962135cef</anchor>
      <arglist>(GradientType &amp;gradient, HessianType &amp;hessian)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute_value_gradient_hessian</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ae2bdf7e66f37320d66bb0b6962a3616c</anchor>
      <arglist>(ValueType &amp;value, GradientType &amp;gradient, HessianType &amp;hessian)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_check_domain</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>af8d6d05b7f35f15243fa9a6f3c34a146</anchor>
      <arglist>(const bool check_domain)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>is_in_domain</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ad1694962f86f11d6ac57dab9db2c71a4</anchor>
      <arglist>(const GradientType &amp;arguments) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Function</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>aafc2c4e2dc33dcead6666b68107d02a1</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>post_set_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>aac1c809e04e3b171be97fb2760a62c11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>post_set_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ac3faa1103501d3caabea0a3a48808a66</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const VariableSet</type>
      <name>argument_set</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a7810b5054666cabf38b32fbbe941f0c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const VariableSet</type>
      <name>parameter_set</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>acdbf1c4858302a02c4b3e4e7a1372fa6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const unsigned int</type>
      <name>N_arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a0fce7368fcc6673d4db7e7d9d16124e7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const unsigned int</type>
      <name>N_parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ab1afd4944ce21b157d6117ecabf6cf57</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>check_domain</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>a408758263057f977068606042eef7664</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>GradientType</type>
      <name>arguments</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>ae9b681025ed2daa8a3a7b17b1c353ee1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>GradientType</type>
      <name>parameters</name>
      <anchorfile>class_c_m_f_1_1_function.html</anchorfile>
      <anchor>af2a61c22d18e67c5dc4b5cd1d893bf8d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CMF::ScalarFunction</name>
    <filename>class_c_m_f_1_1_scalar_function.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <base>Function&lt; ValueType, GradientType, HessianType, GradientType, GradientType &gt;</base>
    <member kind="function">
      <type></type>
      <name>ScalarFunction</name>
      <anchorfile>class_c_m_f_1_1_scalar_function.html</anchorfile>
      <anchor>a8bb8d65602d7c8a18125ad6230f3a974</anchor>
      <arglist>(const VariableSet argument_set, const VariableSet parameter_set)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CMF::ScalarFunction&lt; double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</name>
    <filename>class_c_m_f_1_1_scalar_function_3_01double_00_01_eigen_1_1_vector_xd_00_01_eigen_1_1_matrix_xd_0e82303c680459f2bf2d322b91d244852.html</filename>
    <base>Function&lt; double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</base>
    <member kind="function">
      <type></type>
      <name>ScalarFunction</name>
      <anchorfile>class_c_m_f_1_1_scalar_function_3_01double_00_01_eigen_1_1_vector_xd_00_01_eigen_1_1_matrix_xd_0e82303c680459f2bf2d322b91d244852.html</anchorfile>
      <anchor>a970e17b0ca5908cdac20463b76d15bd0</anchor>
      <arglist>(const VariableSet argument_set, const VariableSet parameter_set)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>numeric_test_derivatives</name>
      <anchorfile>class_c_m_f_1_1_scalar_function_3_01double_00_01_eigen_1_1_vector_xd_00_01_eigen_1_1_matrix_xd_0e82303c680459f2bf2d322b91d244852.html</anchorfile>
      <anchor>acce05150919a9d77549677791bd37f7f</anchor>
      <arglist>(const double eps, std::ostream &amp;output, const double relative_threshold_identical=1e-3, const double absolute_threshold_zero_direct=1e-8, const double absolute_threshold_zero_num=1e-7)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ScalarFunction&lt; ValueTypeFunction, GradientTypeFunction, HessianTypeFunction, GradientTypeFunction, GradientTypeFunction &gt;</name>
    <filename>class_c_m_f_1_1_scalar_function.html</filename>
    <base>CMF::Function</base>
    <member kind="function">
      <type></type>
      <name>ScalarFunction</name>
      <anchorfile>class_c_m_f_1_1_scalar_function.html</anchorfile>
      <anchor>a8bb8d65602d7c8a18125ad6230f3a974</anchor>
      <arglist>(const VariableSet argument_set, const VariableSet parameter_set)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CMF::TransformationDeterminantSymmetricMatrix</name>
    <filename>class_c_m_f_1_1_transformation_determinant_symmetric_matrix.html</filename>
    <base>CMF::VariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</base>
    <member kind="function">
      <type></type>
      <name>TransformationDeterminantSymmetricMatrix</name>
      <anchorfile>class_c_m_f_1_1_transformation_determinant_symmetric_matrix.html</anchorfile>
      <anchor>a06933b325ee0dad768d892e0de26d706</anchor>
      <arglist>(const VariableSet value_set, const VariableSet argument_set)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute</name>
      <anchorfile>class_c_m_f_1_1_transformation_determinant_symmetric_matrix.html</anchorfile>
      <anchor>a97d53233646b86547d0d3c1abe3d2696</anchor>
      <arglist>(Eigen::VectorXd &amp;value, Eigen::MatrixXd &amp;gradient, Eigen::MatrixXd &amp;hessian, const bool update_value, const bool update_gradient, const bool update_hessian) override final</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CMF::TransformationIdentity</name>
    <filename>class_c_m_f_1_1_transformation_identity.html</filename>
    <base>CMF::VariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</base>
    <member kind="function">
      <type></type>
      <name>TransformationIdentity</name>
      <anchorfile>class_c_m_f_1_1_transformation_identity.html</anchorfile>
      <anchor>a26755829f8e0a60711b7bc0084d53aad</anchor>
      <arglist>(const VariableSet value_set, const VariableSet argument_set)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute</name>
      <anchorfile>class_c_m_f_1_1_transformation_identity.html</anchorfile>
      <anchor>a23071a60cc939ac8f4f278bac62a00f7</anchor>
      <arglist>(Eigen::VectorXd &amp;value, Eigen::MatrixXd &amp;gradient, Eigen::MatrixXd &amp;hessian, const bool update_value, const bool update_gradient, const bool update_hessian) override final</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CMF::TransformationInverseSymmetricRank2Tensor</name>
    <filename>class_c_m_f_1_1_transformation_inverse_symmetric_rank2_tensor.html</filename>
    <base>CMF::VariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</base>
    <member kind="function">
      <type></type>
      <name>TransformationInverseSymmetricRank2Tensor</name>
      <anchorfile>class_c_m_f_1_1_transformation_inverse_symmetric_rank2_tensor.html</anchorfile>
      <anchor>a232dbc9c6fc4e160f24c69029b2e080e</anchor>
      <arglist>(const VariableSet value_set, const VariableSet argument_set)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute</name>
      <anchorfile>class_c_m_f_1_1_transformation_inverse_symmetric_rank2_tensor.html</anchorfile>
      <anchor>a3698bc0426e43f3d0f8c5b9e2509b7bb</anchor>
      <arglist>(Eigen::VectorXd &amp;value, Eigen::MatrixXd &amp;gradient, Eigen::MatrixXd &amp;hessian, const bool update_value, const bool update_gradient, const bool update_hessian) override final</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CMF::TransformedScalarFunction</name>
    <filename>class_c_m_f_1_1_transformed_scalar_function.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <base>TransformedScalarFunctionBase&lt; ValueTypeFunction, GradientTypeFunction, HessianTypeFunction, GradientTypeFunction, GradientTypeFunction, GradientTypeFunction, HessianTypeFunction, HessianTypeFunction, GradientTypeFunction, GradientTypeFunction &gt;</base>
    <member kind="function" protection="private" virtualness="pure">
      <type>virtual</type>
      <name>~TransformedScalarFunction</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function.html</anchorfile>
      <anchor>a204debeeddcfe5083f140b051bb3c45b</anchor>
      <arglist>()=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CMF::TransformedScalarFunction&lt; double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</name>
    <filename>class_c_m_f_1_1_transformed_scalar_function_3_01double_00_01_eigen_1_1_vector_xd_00_01_eigen_1_166d8a906364a509586fd6a62037070c4.html</filename>
    <base>TransformedScalarFunctionBase&lt; double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</base>
    <member kind="function">
      <type></type>
      <name>TransformedScalarFunction</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_3_01double_00_01_eigen_1_1_vector_xd_00_01_eigen_1_166d8a906364a509586fd6a62037070c4.html</anchorfile>
      <anchor>a0b0bad2b1bfc516aeebe6452ba458a86</anchor>
      <arglist>(ScalarFunction&lt; double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt; &amp;f, VariableTransformFunctionBase&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt; &amp;t)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>convert_gradient_hessian</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_3_01double_00_01_eigen_1_1_vector_xd_00_01_eigen_1_166d8a906364a509586fd6a62037070c4.html</anchorfile>
      <anchor>a72b1eb908517dd7b9b5b5b28aaef6d03</anchor>
      <arglist>(const Eigen::VectorXd &amp;df_dw, const Eigen::MatrixXd &amp;d2f_dw2, const Eigen::MatrixXd &amp;dw_dq, const Eigen::MatrixXd &amp;df_dw_d2w_dq2, Eigen::VectorXd &amp;dg_dq, Eigen::MatrixXd &amp;d2g_dq2) const override final</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>convert_gradient</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_3_01double_00_01_eigen_1_1_vector_xd_00_01_eigen_1_166d8a906364a509586fd6a62037070c4.html</anchorfile>
      <anchor>a8fe1ca0374d63fe9976fc669ce1a6e59</anchor>
      <arglist>(const Eigen::VectorXd &amp;df_dw, const Eigen::MatrixXd &amp;dw_dq, Eigen::VectorXd &amp;dg_dq) const override final</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>convert_hessian</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_3_01double_00_01_eigen_1_1_vector_xd_00_01_eigen_1_166d8a906364a509586fd6a62037070c4.html</anchorfile>
      <anchor>ae6131f3237dc65009a6ae4ebe11691e0</anchor>
      <arglist>(const Eigen::MatrixXd &amp;d2f_dw2, const Eigen::MatrixXd &amp;dw_dq, const Eigen::MatrixXd &amp;df_dw_d2w_dq2, Eigen::MatrixXd &amp;d2g_dq2) const override final</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CMF::TransformedScalarFunctionBase</name>
    <filename>class_c_m_f_1_1_transformed_scalar_function_base.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <base>ScalarFunction&lt; ValueTypeFunction, GradientTypeFunction, HessianTypeFunction, GradientTypeFunction, GradientTypeFunction &gt;</base>
    <member kind="function">
      <type></type>
      <name>TransformedScalarFunctionBase</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a033c8b7648b07d5ad7898b871cef7030</anchor>
      <arglist>(ScalarFunction&lt; ValueTypeFunction, GradientTypeFunction, HessianTypeFunction, ArgumentTypeFunction, ParameterTypeFunction &gt; &amp;f, VariableTransformFunctionBase&lt; ValueTypeTransformation, GradientTypeTransformation, HessianTypeTransformation, ArgumentTypeTransformation, ParameterTypeTransformation &gt; &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>aab61ec7bc765bf8e17a8a50faa01aacf</anchor>
      <arglist>(ValueTypeFunction &amp;value, GradientTypeFunction &amp;gradient, HessianTypeFunction &amp;hessian, const bool update_value, const bool update_gradient, const bool update_hessian) override final</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>convert_gradient_hessian</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a799046d52924a9052313dc5eb8ac40a5</anchor>
      <arglist>(const GradientTypeFunction &amp;df_dw, const HessianTypeFunction &amp;d2f_dw2, const GradientTypeTransformation &amp;dw_dq, const HessianTypeTransformation &amp;df_dw_d2w_dq2, GradientTypeFunction &amp;dg_dq, HessianTypeFunction &amp;d2g_dq2) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>convert_gradient</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>af64d59280294c2868798335337c2fe16</anchor>
      <arglist>(const GradientTypeFunction &amp;df_dw, const GradientTypeTransformation &amp;dw_dq, GradientTypeFunction &amp;dg_dq) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>convert_hessian</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a6e8746baed278a9891af1e4c513a848f</anchor>
      <arglist>(const HessianTypeFunction &amp;d2f_dw2, const GradientTypeTransformation &amp;dw_dq, const HessianTypeTransformation &amp;df_dw_d2w_dq2, HessianTypeFunction &amp;d2g_dq2) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>is_in_domain</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>ade176b8d5f5f59f920f7f3d0f20914da</anchor>
      <arglist>(const ArgumentTypeFunction &amp;arguments) const override final</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual</type>
      <name>~TransformedScalarFunctionBase</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>af3ad2157ac689fe6e232f09191830713</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ScalarFunction&lt; ValueTypeFunction, GradientTypeFunction, HessianTypeFunction, ArgumentTypeFunction, ParameterTypeFunction &gt; &amp;</type>
      <name>f</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a2c1d30fa99b88a4ad9e0172bc81a6c4d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>VariableTransformFunctionBase&lt; ValueTypeTransformation, GradientTypeTransformation, HessianTypeTransformation, ArgumentTypeTransformation, ParameterTypeTransformation &gt; &amp;</type>
      <name>t</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a5a189bf75f7192f58fec9d3d9a8da531</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>post_set_arguments</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a2de3717fcf154324fb70e47cf419ad1a</anchor>
      <arglist>() override final</arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>post_set_parameters</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>ab426f6daed5e79c837324a5fa4fe57ed</anchor>
      <arglist>() override final</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TransformedScalarFunctionBase&lt; double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</name>
    <filename>class_c_m_f_1_1_transformed_scalar_function_base.html</filename>
    <base>CMF::ScalarFunction&lt; double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</base>
    <member kind="function">
      <type></type>
      <name>TransformedScalarFunctionBase</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a033c8b7648b07d5ad7898b871cef7030</anchor>
      <arglist>(ScalarFunction&lt; double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt; &amp;f, VariableTransformFunctionBase&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt; &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>aab61ec7bc765bf8e17a8a50faa01aacf</anchor>
      <arglist>(double &amp;value, Eigen::VectorXd &amp;gradient, Eigen::MatrixXd &amp;hessian, const bool update_value, const bool update_gradient, const bool update_hessian) override final</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>convert_gradient_hessian</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a799046d52924a9052313dc5eb8ac40a5</anchor>
      <arglist>(const Eigen::VectorXd &amp;df_dw, const Eigen::MatrixXd &amp;d2f_dw2, const Eigen::MatrixXd &amp;dw_dq, const Eigen::MatrixXd &amp;df_dw_d2w_dq2, Eigen::VectorXd &amp;dg_dq, Eigen::MatrixXd &amp;d2g_dq2) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>convert_gradient</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>af64d59280294c2868798335337c2fe16</anchor>
      <arglist>(const Eigen::VectorXd &amp;df_dw, const Eigen::MatrixXd &amp;dw_dq, Eigen::VectorXd &amp;dg_dq) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>convert_hessian</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a6e8746baed278a9891af1e4c513a848f</anchor>
      <arglist>(const Eigen::MatrixXd &amp;d2f_dw2, const Eigen::MatrixXd &amp;dw_dq, const Eigen::MatrixXd &amp;df_dw_d2w_dq2, Eigen::MatrixXd &amp;d2g_dq2) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>is_in_domain</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>ade176b8d5f5f59f920f7f3d0f20914da</anchor>
      <arglist>(const Eigen::VectorXd &amp;arguments) const override final</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual</type>
      <name>~TransformedScalarFunctionBase</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>af3ad2157ac689fe6e232f09191830713</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ScalarFunction&lt; double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt; &amp;</type>
      <name>f</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a2c1d30fa99b88a4ad9e0172bc81a6c4d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>VariableTransformFunctionBase&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt; &amp;</type>
      <name>t</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a5a189bf75f7192f58fec9d3d9a8da531</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>post_set_arguments</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a2de3717fcf154324fb70e47cf419ad1a</anchor>
      <arglist>() override final</arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>post_set_parameters</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>ab426f6daed5e79c837324a5fa4fe57ed</anchor>
      <arglist>() override final</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TransformedScalarFunctionBase&lt; ValueTypeFunction, GradientTypeFunction, HessianTypeFunction, GradientTypeFunction, GradientTypeFunction, GradientTypeFunction, HessianTypeFunction, HessianTypeFunction, GradientTypeFunction, GradientTypeFunction &gt;</name>
    <filename>class_c_m_f_1_1_transformed_scalar_function_base.html</filename>
    <base>ScalarFunction&lt; ValueTypeFunction, GradientTypeFunction, HessianTypeFunction, GradientTypeFunction, GradientTypeFunction &gt;</base>
    <member kind="function">
      <type></type>
      <name>TransformedScalarFunctionBase</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a033c8b7648b07d5ad7898b871cef7030</anchor>
      <arglist>(ScalarFunction&lt; ValueTypeFunction, GradientTypeFunction, HessianTypeFunction, GradientTypeFunction, GradientTypeFunction &gt; &amp;f, VariableTransformFunctionBase&lt; GradientTypeFunction, HessianTypeFunction, HessianTypeFunction, GradientTypeFunction, GradientTypeFunction &gt; &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>compute</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>aab61ec7bc765bf8e17a8a50faa01aacf</anchor>
      <arglist>(ValueTypeFunction &amp;value, GradientTypeFunction &amp;gradient, HessianTypeFunction &amp;hessian, const bool update_value, const bool update_gradient, const bool update_hessian) override final</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>convert_gradient_hessian</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a799046d52924a9052313dc5eb8ac40a5</anchor>
      <arglist>(const GradientTypeFunction &amp;df_dw, const HessianTypeFunction &amp;d2f_dw2, const HessianTypeFunction &amp;dw_dq, const HessianTypeFunction &amp;df_dw_d2w_dq2, GradientTypeFunction &amp;dg_dq, HessianTypeFunction &amp;d2g_dq2) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>convert_gradient</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>af64d59280294c2868798335337c2fe16</anchor>
      <arglist>(const GradientTypeFunction &amp;df_dw, const HessianTypeFunction &amp;dw_dq, GradientTypeFunction &amp;dg_dq) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>convert_hessian</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a6e8746baed278a9891af1e4c513a848f</anchor>
      <arglist>(const HessianTypeFunction &amp;d2f_dw2, const HessianTypeFunction &amp;dw_dq, const HessianTypeFunction &amp;df_dw_d2w_dq2, HessianTypeFunction &amp;d2g_dq2) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>is_in_domain</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>ade176b8d5f5f59f920f7f3d0f20914da</anchor>
      <arglist>(const GradientTypeFunction &amp;arguments) const override final</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual</type>
      <name>~TransformedScalarFunctionBase</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>af3ad2157ac689fe6e232f09191830713</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ScalarFunction&lt; ValueTypeFunction, GradientTypeFunction, HessianTypeFunction, GradientTypeFunction, GradientTypeFunction &gt; &amp;</type>
      <name>f</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a2c1d30fa99b88a4ad9e0172bc81a6c4d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>VariableTransformFunctionBase&lt; GradientTypeFunction, HessianTypeFunction, HessianTypeFunction, GradientTypeFunction, GradientTypeFunction &gt; &amp;</type>
      <name>t</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a5a189bf75f7192f58fec9d3d9a8da531</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>post_set_arguments</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>a2de3717fcf154324fb70e47cf419ad1a</anchor>
      <arglist>() override final</arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>post_set_parameters</name>
      <anchorfile>class_c_m_f_1_1_transformed_scalar_function_base.html</anchorfile>
      <anchor>ab426f6daed5e79c837324a5fa4fe57ed</anchor>
      <arglist>() override final</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CMF::VariableSet</name>
    <filename>class_c_m_f_1_1_variable_set.html</filename>
    <member kind="function">
      <type></type>
      <name>VariableSet</name>
      <anchorfile>class_c_m_f_1_1_variable_set.html</anchorfile>
      <anchor>afa1fd73e687c83ca952e97f7ce11d79a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VariableSet</name>
      <anchorfile>class_c_m_f_1_1_variable_set.html</anchorfile>
      <anchor>a16a4388291308ed9a8556d9ae85f9707</anchor>
      <arglist>(const std::initializer_list&lt; std::string &gt; &amp;variables)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>push_back</name>
      <anchorfile>class_c_m_f_1_1_variable_set.html</anchorfile>
      <anchor>a55cd2c4f267e9755e11c8a0882d399fa</anchor>
      <arglist>(std::string name)</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; unsigned int &gt;</type>
      <name>get_correspondence</name>
      <anchorfile>class_c_m_f_1_1_variable_set.html</anchorfile>
      <anchor>a20760bcfb1da44ef29b856faa8ae409a</anchor>
      <arglist>(const VariableSet &amp;other_variable_set) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>operator[]</name>
      <anchorfile>class_c_m_f_1_1_variable_set.html</anchorfile>
      <anchor>ab2a1252cbfe0e410cc5ee70362dbf734</anchor>
      <arglist>(unsigned int index) const</arglist>
    </member>
    <member kind="function">
      <type>std::string::size_type</type>
      <name>size</name>
      <anchorfile>class_c_m_f_1_1_variable_set.html</anchorfile>
      <anchor>ad2e30460ee1e17be3b14e989b01de585</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; std::string &gt;::const_iterator</type>
      <name>begin</name>
      <anchorfile>class_c_m_f_1_1_variable_set.html</anchorfile>
      <anchor>a509d44297de286307a7740e95e5b26a1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; std::string &gt;::const_iterator</type>
      <name>end</name>
      <anchorfile>class_c_m_f_1_1_variable_set.html</anchorfile>
      <anchor>aba719a996356d1a0c41065cab19063af</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; std::string &gt;</type>
      <name>get_variables</name>
      <anchorfile>class_c_m_f_1_1_variable_set.html</anchorfile>
      <anchor>ad1557554f935a996dfff05f3b5166c12</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; std::string &gt;</type>
      <name>variables</name>
      <anchorfile>class_c_m_f_1_1_variable_set.html</anchorfile>
      <anchor>aedcd5111c4ac3df7880c5fb760f2fd62</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CMF::VariableTransformFunction</name>
    <filename>class_c_m_f_1_1_variable_transform_function.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <base>VariableTransformFunctionBase&lt; ValueType, GradientType, HessianType, ValueType, ValueType &gt;</base>
  </compound>
  <compound kind="class">
    <name>CMF::VariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</name>
    <filename>class_c_m_f_1_1_variable_transform_function_3_01_eigen_1_1_vector_xd_00_01_eigen_1_1_matrix_xd_09c44dd2dd12039f232b7d0c4f02bcaca.html</filename>
    <base>VariableTransformFunctionBase&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</base>
    <member kind="function">
      <type></type>
      <name>VariableTransformFunction</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_3_01_eigen_1_1_vector_xd_00_01_eigen_1_1_matrix_xd_09c44dd2dd12039f232b7d0c4f02bcaca.html</anchorfile>
      <anchor>ac74a3bbe5634fcdd6748332f18c026ae</anchor>
      <arglist>(const VariableSet value_set, const VariableSet argument_set)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>numeric_test_derivatives</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_3_01_eigen_1_1_vector_xd_00_01_eigen_1_1_matrix_xd_09c44dd2dd12039f232b7d0c4f02bcaca.html</anchorfile>
      <anchor>a509cf8ed87fa45427af3db0dc9096e76</anchor>
      <arglist>(const double eps, std::ostream &amp;output, const double relative_threshold_identical=1e-3, const double absolute_threshold_zero_direct=1e-8, const double absolute_threshold_zero_num=1e-7)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>VariableTransformFunction&lt; ValueType, GradientType, HessianType, GradientType, GradientType &gt;</name>
    <filename>class_c_m_f_1_1_variable_transform_function.html</filename>
    <base>CMF::VariableTransformFunctionBase</base>
  </compound>
  <compound kind="class">
    <name>CMF::VariableTransformFunctionBase</name>
    <filename>class_c_m_f_1_1_variable_transform_function_base.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <base>VectorFunction&lt; ValueType, GradientType, HessianType, ValueType, ValueType &gt;</base>
    <member kind="function">
      <type></type>
      <name>VariableTransformFunctionBase</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>ae743e0633b72679cb7b35a66ff2dbe90</anchor>
      <arglist>(const VariableSet value_set, const VariableSet argument_set)</arglist>
    </member>
    <member kind="function">
      <type>const VariableSet &amp;</type>
      <name>get_value_set</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a2938639ff4e127dcec027e617666f3c7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>get_N_values</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a135ab0bfc2678886622d437770ee50c4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>set_v</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>aad64d0a6fd3938d4397a7b7e7ca2b894</anchor>
      <arglist>(const ValueType &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>const ValueType &amp;</type>
      <name>get_v</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a1853f194c8af288edcd2a3c0ae1c64dd</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>post_set_v</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a8029e9e508f6c659d344ae99b30b2f36</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const VariableSet</type>
      <name>value_set</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a0a0fc8a12b720ad0dec3420435015b91</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const unsigned int</type>
      <name>N_values</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a6b29fcf78595a714faf4955609229439</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ValueType</type>
      <name>v</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a971898c0fd46da42e531328469475612</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>VariableTransformFunctionBase&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</name>
    <filename>class_c_m_f_1_1_variable_transform_function_base.html</filename>
    <base>CMF::VectorFunction</base>
    <member kind="function">
      <type></type>
      <name>VariableTransformFunctionBase</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>ae743e0633b72679cb7b35a66ff2dbe90</anchor>
      <arglist>(const VariableSet value_set, const VariableSet argument_set)</arglist>
    </member>
    <member kind="function">
      <type>const VariableSet &amp;</type>
      <name>get_value_set</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a2938639ff4e127dcec027e617666f3c7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>get_N_values</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a135ab0bfc2678886622d437770ee50c4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>set_v</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>aad64d0a6fd3938d4397a7b7e7ca2b894</anchor>
      <arglist>(const Eigen::VectorXd &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>const Eigen::VectorXd &amp;</type>
      <name>get_v</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a1853f194c8af288edcd2a3c0ae1c64dd</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>post_set_v</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a8029e9e508f6c659d344ae99b30b2f36</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const VariableSet</type>
      <name>value_set</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a0a0fc8a12b720ad0dec3420435015b91</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const unsigned int</type>
      <name>N_values</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a6b29fcf78595a714faf4955609229439</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Eigen::VectorXd</type>
      <name>v</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a971898c0fd46da42e531328469475612</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>VariableTransformFunctionBase&lt; GradientTypeFunction, HessianTypeFunction, HessianTypeFunction, GradientTypeFunction, GradientTypeFunction &gt;</name>
    <filename>class_c_m_f_1_1_variable_transform_function_base.html</filename>
    <base>CMF::VectorFunction</base>
    <member kind="function">
      <type></type>
      <name>VariableTransformFunctionBase</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>ae743e0633b72679cb7b35a66ff2dbe90</anchor>
      <arglist>(const VariableSet value_set, const VariableSet argument_set)</arglist>
    </member>
    <member kind="function">
      <type>const VariableSet &amp;</type>
      <name>get_value_set</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a2938639ff4e127dcec027e617666f3c7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>get_N_values</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a135ab0bfc2678886622d437770ee50c4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>set_v</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>aad64d0a6fd3938d4397a7b7e7ca2b894</anchor>
      <arglist>(const GradientTypeFunction &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>const GradientTypeFunction &amp;</type>
      <name>get_v</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a1853f194c8af288edcd2a3c0ae1c64dd</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>post_set_v</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a8029e9e508f6c659d344ae99b30b2f36</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const VariableSet</type>
      <name>value_set</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a0a0fc8a12b720ad0dec3420435015b91</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const unsigned int</type>
      <name>N_values</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a6b29fcf78595a714faf4955609229439</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>GradientTypeFunction</type>
      <name>v</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a971898c0fd46da42e531328469475612</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>VariableTransformFunctionBase&lt; ValueType, GradientType, HessianType, ValueType, ValueType &gt;</name>
    <filename>class_c_m_f_1_1_variable_transform_function_base.html</filename>
    <base>VectorFunction&lt; ValueType, GradientType, HessianType, ValueType, ValueType &gt;</base>
    <member kind="function">
      <type></type>
      <name>VariableTransformFunctionBase</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>ae743e0633b72679cb7b35a66ff2dbe90</anchor>
      <arglist>(const VariableSet value_set, const VariableSet argument_set)</arglist>
    </member>
    <member kind="function">
      <type>const VariableSet &amp;</type>
      <name>get_value_set</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a2938639ff4e127dcec027e617666f3c7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>get_N_values</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a135ab0bfc2678886622d437770ee50c4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>set_v</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>aad64d0a6fd3938d4397a7b7e7ca2b894</anchor>
      <arglist>(const ValueType &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>const ValueType &amp;</type>
      <name>get_v</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a1853f194c8af288edcd2a3c0ae1c64dd</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>post_set_v</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a8029e9e508f6c659d344ae99b30b2f36</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const VariableSet</type>
      <name>value_set</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a0a0fc8a12b720ad0dec3420435015b91</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const unsigned int</type>
      <name>N_values</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a6b29fcf78595a714faf4955609229439</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ValueType</type>
      <name>v</name>
      <anchorfile>class_c_m_f_1_1_variable_transform_function_base.html</anchorfile>
      <anchor>a971898c0fd46da42e531328469475612</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CMF::VectorFunction</name>
    <filename>class_c_m_f_1_1_vector_function.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <base>Function&lt; ValueType, GradientType, HessianType, ArgumentType, ArgumentType &gt;</base>
    <member kind="function">
      <type></type>
      <name>VectorFunction</name>
      <anchorfile>class_c_m_f_1_1_vector_function.html</anchorfile>
      <anchor>a56fea5e170ca0b769aa3a8e14d2afe38</anchor>
      <arglist>(const VariableSet argument_set, const VariableSet parameter_set)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>VectorFunction&lt; ValueType, GradientType, HessianType, ValueType, ValueType &gt;</name>
    <filename>class_c_m_f_1_1_vector_function.html</filename>
    <base>CMF::Function</base>
    <member kind="function">
      <type></type>
      <name>VectorFunction</name>
      <anchorfile>class_c_m_f_1_1_vector_function.html</anchorfile>
      <anchor>a56fea5e170ca0b769aa3a8e14d2afe38</anchor>
      <arglist>(const VariableSet argument_set, const VariableSet parameter_set)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>CMF</name>
    <filename>namespace_c_m_f.html</filename>
    <class kind="class">CMF::TransformationInverseSymmetricRank2Tensor</class>
    <class kind="class">CMF::TransformationDeterminantSymmetricMatrix</class>
    <class kind="class">CMF::TransformationIdentity</class>
    <class kind="class">CMF::Function</class>
    <class kind="class">CMF::ScalarFunction</class>
    <class kind="class">CMF::ScalarFunction&lt; double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</class>
    <class kind="class">CMF::TransformedScalarFunctionBase</class>
    <class kind="class">CMF::TransformedScalarFunction</class>
    <class kind="class">CMF::TransformedScalarFunction&lt; double, Eigen::VectorXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</class>
    <class kind="class">CMF::VariableSet</class>
    <class kind="class">CMF::VariableTransformFunctionBase</class>
    <class kind="class">CMF::VariableTransformFunction</class>
    <class kind="class">CMF::VariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</class>
    <class kind="class">CMF::CombinedVariableTransformFunctionBase</class>
    <class kind="class">CMF::CombinedVariableTransformFunction</class>
    <class kind="class">CMF::CombinedVariableTransformFunction&lt; Eigen::VectorXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd &gt;</class>
    <class kind="class">CMF::VectorFunction</class>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title>CMF (Constitutive Modeling Framework) Documentation</title>
    <filename>index.html</filename>
  </compound>
</tagfile>
