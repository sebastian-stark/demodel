clear;

function eq = replace_pow_2(eq)
  eq = regexprep (eq, 'pow\((\w+), 2\)', '($1*$1)');
endfunction

##function eq = replace_not_supported_strings(eq, str)
##  eq = regexprep (eq, '// Not supported in C:\n', '');
##endfunction

pkg load symbolic;

syms Ji;
E_te = sym('E_te', [6 1]);
syms Ji_mu(Ji);
syms Ji_lambda(Ji);
syms epsT(Ji);

eps_el = E_te - [epsT;epsT;epsT;0;0;0];

C=[2*Ji_mu+Ji_lambda Ji_lambda Ji_lambda 0 0 0;
   Ji_lambda 2*Ji_mu+Ji_lambda Ji_lambda 0 0 0;
   Ji_lambda Ji_lambda 2*Ji_mu+Ji_lambda 0 0 0;
   0 0 0 Ji_mu 0 0;
   0 0 0 0 Ji_mu 0;
   0 0 0 0 0 Ji_mu];
              
Psi = simplify(sym(1)/sym(2) * transpose(eps_el) * C * eps_el);
disp(["value = " replace_expr(ccode(simplify(Psi))) ";"]);

disp(" ");

for i=1:6
  dPsi_dE_te(i) = diff(Psi, E_te(i,1));
  disp(["gradient(" num2str(i-1) ") = " replace_expr(ccode(simplify(dPsi_dE_te(i)))) ";"]);
endfor
dPsi_dJi = diff(Psi, Ji);
disp(["gradient(6) = " replace_expr(ccode(simplify(dPsi_dJi))) ";"]);

disp(" ");

for i=1:6
 for j=1:6
  d2Psi_dE_te2(i,j) = diff(dPsi_dE_te(i), E_te(j,1));
  disp(["hessian(" num2str(i-1) "," num2str(j-1) ") = " replace_expr(ccode(simplify(d2Psi_dE_te2(i,j)))) ";"]);
 endfor
endfor
for i=1:6
  d2Psi_dEdJi(i) = diff(dPsi_dE_te(i), Ji);
  disp(["hessian(" num2str(i-1) "," num2str(6) ") = hessian(" num2str(6) "," num2str(i-1) ") = " replace_expr(ccode(simplify(d2Psi_dEdJi(i)))) ";"]);
endfor
d2Psi_Ji2 = diff(dPsi_dJi, Ji);
disp(["hessian(6,6) = " replace_expr(ccode(simplify(d2Psi_Ji2))) ";"]);
