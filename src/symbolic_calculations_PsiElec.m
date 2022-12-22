clear;

function eq = replace_pow_2(eq)
  eq = regexprep (eq, 'pow\((\w+), 2\)', '($1*$1)');
endfunction

##function eq = replace_not_supported_strings(eq, str)
##  eq = regexprep (eq, '// Not supported in C:\n', '');
##endfunction

pkg load symbolic;

syms epsilon;
E = sym('E', [3 1]);
F_inv = sym('F_inv', [9 1]);
q = [E; F_inv];

F_inv_M = [F_inv(1) F_inv(2) F_inv(3);
           F_inv(4) F_inv(5) F_inv(6);
           F_inv(7) F_inv(8) F_inv(9);];
    
Psi = -simplify(1/sym(2)/epsilon * transpose(E) * F_inv_M * transpose(F_inv_M) * E );
disp(["value = " replace_expr(ccode(simplify(Psi))) ";"]);

disp(" ");

for i=1:12
  dPsi_dq(i) = diff(Psi, q(i,1));
  disp(["gradient(" num2str(i-1) ") = " replace_expr(ccode(simplify(dPsi_dq(i)))) ";"]);
endfor

disp(" ");

for i=1:12
 for j=i:12
  if(i == j)
   disp(["hessian(" num2str(i-1) "," num2str(j-1) ") = " replace_pow_2(ccode(simplify(diff(dPsi_dq(i), q(j,1))))) ";"]);
  else
   disp(["hessian(" num2str(i-1) "," num2str(j-1) ") = " "hessian(" num2str(j-1) "," num2str(i-1) ") = " replace_pow_2(ccode(simplify(diff(dPsi_dq(i), q(j,1))))) ";"]);
  endif
 endfor
endfor