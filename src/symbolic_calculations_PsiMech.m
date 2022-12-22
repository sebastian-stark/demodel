clear;

function eq = replace_pow_2(eq)
  eq = regexprep (eq, 'pow\((\w+), 2\)', '($1*$1)');
endfunction

##function eq = replace_not_supported_strings(eq, str)
##  eq = regexprep (eq, '// Not supported in C:\n', '');
##endfunction

pkg load symbolic;

syms mu_e mu_i;
F = sym('F', [9 1]);
U_i_inv = sym('Ui_inv', [6 1]);
q = [F; U_i_inv];

F_M = [F(1) F(2) F(3);
       F(4) F(5) F(6);
       F(7) F(8) F(9);];

U_i_inv_M = [U_i_inv(1) U_i_inv(4)/2 U_i_inv(6)/2;
             U_i_inv(4)/2 U_i_inv(2) U_i_inv(5)/2;
             U_i_inv(6)/2 U_i_inv(5)/2 U_i_inv(3)];
             
Psi = simplify(mu_e/sym(2) * trace(transpose(F_M)*F_M) + mu_i/sym(2) * trace(U_i_inv_M*transpose(F_M)*F_M*U_i_inv_M) );
disp(["value = " replace_expr(ccode(simplify(Psi))) ";"]);

disp(" ");

for i=1:15
  dPsi_dq(i) = diff(Psi, q(i,1));
  disp(["gradient(" num2str(i-1) ") = " replace_expr(ccode(simplify(dPsi_dq(i)))) ";"]);
endfor

disp(" ");

for i=1:15
 for j=1:15
  if(i == j)
   disp(["hessian(" num2str(i-1) "," num2str(j-1) ") = " replace_pow_2(ccode(simplify(diff(dPsi_dq(i), q(j,1))))) ";"]);
  else
   disp(["hessian(" num2str(i-1) "," num2str(j-1) ") = " "hessian(" num2str(j-1) "," num2str(i-1) ") = " replace_pow_2(ccode(simplify(diff(dPsi_dq(i), q(j,1))))) ";"]);
  endif
 endfor
endfor
