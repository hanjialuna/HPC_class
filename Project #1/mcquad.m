function q = mcquad(N)
% q = mcquad(N)
%
% This function computes an approximation of the integral
%
%    +infinity 
%   /
%   |  -x
%   | e   cos(x) dx
%   /
%    0
%
% using Monte Carlo integration with importance sampling where
% an exponential distribution is used.
%
% N = number of sample points
% 
% q = approximation of the integral
%

y = rand(N,1);
x = -log(y);
q = mean(f(x));

end

function z = f(x)
z = cos(x);
end
