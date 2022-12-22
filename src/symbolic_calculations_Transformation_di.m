clear;

function eq = replace_pow_2(eq)
  eq = regexprep (eq, 'pow\((\w+), 2\)', '($1*$1)');
endfunction

pkg load symbolic;

syms J;
U_i_inv = sym('U_i_inv', [6 1]);
U_i_dot = sym('U_i_dot', [6 1]);
F = sym('F', [9 1]);
F_inv = sym('F_inv', [9 1]);
v = sym('v', [6 1]);

U_i_inv_M = [U_i_inv(1) U_i_inv(4)/2 U_i_inv(6)/2;
             U_i_inv(4)/2 U_i_inv(2) U_i_inv(5)/2;
             U_i_inv(6)/2 U_i_inv(5)/2 U_i_inv(3)];

U_i_dot_M = [U_i_dot(1) U_i_dot(4)/2 U_i_dot(6)/2;
             U_i_dot(4)/2 U_i_dot(2) U_i_dot(5)/2;
             U_i_dot(6)/2 U_i_dot(5)/2 U_i_dot(3)];
                  
F_M = [F(1) F(2) F(3);
       F(4) F(5) F(6);
       F(7) F(8) F(9);];

F_inv_M = [F_inv(1) F_inv(2) F_inv(3);
           F_inv(4) F_inv(5) F_inv(6);
           F_inv(7) F_inv(8) F_inv(9);];

I = sym([1 0 0; 0 1 0; 0 0 1]);

d_i = simplify(1/sym(2) * (F_M * U_i_inv_M * U_i_dot_M * F_inv_M + transpose(F_inv_M) * U_i_dot_M * U_i_inv_M * transpose(F_M)));

w = [ d_i(1,1);
      d_i(2,2);
      d_i(3,3);
      d_i(1,2)+d_i(2,1);
      d_i(2,3)+d_i(3,2);
      d_i(1,3)+d_i(3,1);];
      
q = [U_i_dot; U_i_inv; F; F_inv];

for i=1:6
  disp(["value(" num2str(i-1) ") = " replace_pow_2(ccode(simplify(w(i)))) ";"]);
  disp(" ");
endfor
           
disp(" ");

for i=1:6
 for j=1:30
  dw_dq(i,j) = diff(w(i), q(j,1));
   disp(["gradient(" num2str(i-1) "," num2str(j-1) ") = " replace_pow_2(ccode(simplify(dw_dq(i,j)))) ";"]);
 endfor
endfor

disp(" ");

v_dw_dq = simplify(transpose(v)*dw_dq);

for i=1:30
 for j=i:30
  v_d2w_dq2(i,j) = diff(v_dw_dq(i), q(j,1));
  if(i == j)
   disp(["hessian(" num2str(i-1) "," num2str(j-1) ") = " replace_pow_2(ccode(simplify(v_d2w_dq2(i,j)))) ";"]);
  else
   disp(["hessian(" num2str(i-1) "," num2str(j-1) ") = " "hessian(" num2str(j-1) "," num2str(i-1) ") = " replace_pow_2(ccode(simplify(v_d2w_dq2(i,j)))) ";"]);
  endif
 endfor
endfor
