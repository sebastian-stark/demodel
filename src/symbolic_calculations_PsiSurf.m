clear;

function eq = replace_pow_2(eq)
%eq = regexprep (eq, 'pow\((a\d1 \+ grad_u\d1), 2\)', '($1*$1)');
eq = regexprep (eq, 'pow\(((?:[^)(]|\((?:[^)(]|\((?:[^)(]|\([^)(]*\))*\))*\))*), 2\)', '(($1)*($1))');
eq = regexprep (eq, 'pow\(((?:[^)(]|\((?:[^)(]|\((?:[^)(]|\([^)(]*\))*\))*\))*), 2\)', '(($1)*($1))');


##  eq = regexprep (eq, 'pow\((n\d1), 2\)', '($1*$1)');
##  eq = regexprep (eq, '  pow\((grad_u\d1 - \(n\d1\*n\d1\) + 1), 2\)', '($1*$1)');
##  grad_u11 - (n11*n11) + 1, 2
##  
##  eq = regexprep (eq, 'pow\((.+), 2\)', '($1*$1)');

endfunction

pkg load symbolic;

syms mu_S lambda_S;
grad_u = sym('grad_u', [9 1]);
n = sym('n', [3 1]);
a = sym('a', [6 1]);
q = [grad_u];
grad_u_M = [grad_u(1) grad_u(2) grad_u(3);
            grad_u(4) grad_u(5) grad_u(6);
            grad_u(7) grad_u(8) grad_u(9)];
            
a = [a(1) a(4) a(6);
     a(4) a(2) a(5);
     a(6) a(5) a(3)];

F_S = grad_u_M + a;
C_S = transpose(F_S)*F_S;
tr_C_S = trace(C_S);
tr_C_S_2 = trace(C_S*C_S);
    
Psi = (1/sym(8)*lambda_S*(tr_C_S-2)*(tr_C_S-2) + 1/sym(4)*mu_S*(tr_C_S_2-2*tr_C_S + 2));
disp(["value = " replace_pow_2(ccode(simplify(Psi))) ";"]);

disp(" ");

for i=1:9
  dPsi_dq(i) = diff(Psi, q(i,1));
  disp(["gradient(" num2str(i-1) ") = " replace_pow_2(ccode(simplify(dPsi_dq(i)))) ";"]);
endfor

disp(" ");

for i=1:9
 for j=i:9
  if(i == j)
   disp(["hessian(" num2str(i-1) "," num2str(j-1) ") = " replace_pow_2(ccode(simplify(diff(dPsi_dq(i), q(j,1))))) ";"]);
  else
   disp(["hessian(" num2str(i-1) "," num2str(j-1) ") = " "hessian(" num2str(j-1) "," num2str(i-1) ") = " replace_pow_2(ccode(simplify(diff(dPsi_dq(i), q(j,1))))) ";"]);
  endif
 endfor
endfor