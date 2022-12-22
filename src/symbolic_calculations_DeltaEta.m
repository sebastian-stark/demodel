clear;

function eq = replace_pow_2(eq)
  while(length(strfind (eq, 'pow'))>0)
    eq = regexprep (eq, 'pow\(((?:[^)(]|\((?:[^)(]|\((?:[^)(]|\([^)(]*\))*\))*\))*), 2\)', '(($1)*($1))');
  endwhile
endfunction

pkg load symbolic;

syms eta;
di = sym('di', [6 1]);
q = [di];

di_M = [di(1) di(4)/2 di(6)/2;
         di(4)/2 di(2) di(5)/2
         di(6)/2 di(5)/2 di(3)];
              
Delta = eta * trace(di_M * di_M);
disp(["value = " replace_pow_2(ccode(simplify(Delta))) ";"]);

disp(" ");

for i=1:6
  dDelta_dq(i) = diff(Delta, q(i,1));
  disp(["gradient(" num2str(i-1) ") = " replace_pow_2(ccode(simplify(dDelta_dq(i)))) ";"]);
endfor

disp(" ");

for i=1:6
 for j=i:6
  if(i == j)
   disp(["hessian(" num2str(i-1) "," num2str(j-1) ") = " replace_pow_2(ccode(simplify(diff(dDelta_dq(i), q(j,1))))) ";"]);
  else
   disp(["hessian(" num2str(i-1) "," num2str(j-1) ") = " "hessian(" num2str(j-1) "," num2str(i-1) ") = " replace_pow_2(ccode(simplify(diff(dDelta_dq(i), q(j,1))))) ";"]);
  endif
 endfor
endfor