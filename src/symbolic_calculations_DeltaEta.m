clear;

function eq = replace_expr(eq)
  eq = regexprep (eq, '\/\/ .+\n', '');
  eq = regexprep (eq, 'Derivative\((\w+)\(\w+\), \((\w+), (\w+)\)\)', 'd$3$1_d$2$3');
  eq = regexprep (eq, 'Derivative\((\w+)\(\w+\), (\w+)\)', 'd$1_d$2');
  eq = regexprep (eq, '\(Ji\)', '');

  eq = regexprep (eq, 'Ji_muv', 'Ji_muv_');
  eq = regexprep (eq, 'Ji_lambdav', 'Ji_lambdav_');

  eq = regexprep (eq, '__', '_');

  eq = regexprep (eq, 'dJi_muv_dJi', 'dJi_muv');
  eq = regexprep (eq, 'dJi_lambdav_dJi', 'dJi_lambdav');

  eq = regexprep (eq, 'd2Ji_muv_dJi2', 'd2Ji_muv');
  eq = regexprep (eq, 'd2Ji_lambdav_dJi2', 'd2Ji_lambdav');
  
 
  eq = regexprep (eq, 'pow\((\w+), 2\)', '($1*$1)');
endfunction

##function eq = replace_not_supported_strings(eq, str)
##  eq = regexprep (eq, '// Not supported in C:\n', '');
##endfunction

pkg load symbolic;

syms Ji;
di = sym('di', [6 1]);
syms Ji_muv(Ji);
syms Ji_lambdav(Ji);

C=[2*Ji_muv+Ji_lambdav Ji_lambdav Ji_lambdav 0 0 0;
   Ji_lambdav 2*Ji_muv+Ji_lambdav Ji_lambdav 0 0 0;
   Ji_lambdav Ji_lambdav 2*Ji_muv+Ji_lambdav 0 0 0;
   0 0 0 Ji_muv 0 0;
   0 0 0 0 Ji_muv 0;
   0 0 0 0 0 Ji_muv];
              
Delta = simplify(sym(1)/sym(2) * transpose(di) * C * di);
disp(["value = " replace_expr(ccode(simplify(Delta))) ";"]);

disp(" ");

for i=1:6
  dDelta_ddi(i) = diff(Delta, di(i,1));
  disp(["gradient(" num2str(i-1) ") = " replace_expr(ccode(simplify(dDelta_ddi(i)))) ";"]);
endfor
dDelta_dJi = diff(Delta, Ji);
disp(["gradient(6) = " replace_expr(ccode(simplify(dDelta_dJi))) ";"]);

disp(" ");

for i=1:6
 for j=1:6
  d2Delta_ddi2(i,j) = diff(dDelta_ddi(i), di(j,1));
  disp(["hessian(" num2str(i-1) "," num2str(j-1) ") = " replace_expr(ccode(simplify(d2Delta_ddi2(i,j)))) ";"]);
 endfor
endfor
for i=1:6
  d2Delta_ddidJi(i) = diff(dDelta_ddi(i), Ji);
  disp(["hessian(" num2str(i-1) "," num2str(6) ") = hessian(" num2str(6) "," num2str(i-1) ") = " replace_expr(ccode(simplify(d2Delta_ddidJi(i)))) ";"]);
endfor
d2Delta_dJi2 = diff(dDelta_dJi, Ji);
disp(["hessian(6,6) = " replace_expr(ccode(simplify(d2Delta_dJi2))) ";"]);
