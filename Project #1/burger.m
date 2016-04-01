function [u, x] = burger(N, dt, T)
% u = burger(N, dt, T)
%
% This function solves the PDE
%
%    u  + [f(u)]  = nu u      u(-1,t) = u(1,t) = 0, u(x,0) = -sin(pi*x)
%     t         x       xx
%
% on the interval -1 <= x <= 1 and for time 0 <= t <= T
% where nu = 1/100/pi.
% 
% N = number of grid points in the interval
% dt = time step size
% T = terminal time
%
% returns
% u = u(x,T)
% x = grid point locations

figure(1)
x = linspace(-1,1,N);
dx = x(2)-x(1);
u = -sin(pi*x);
uhat = zeros(size(u));
plot(x,u,'b-');
drawnow
nsteps = round(T/dt);
nu = 1/100/pi;
for step=1:nsteps
    if mod(step,2) == 0
        uhat(2:N-1) = u(2:N-1) + dt/dx*(f(u(3:N))+nu*(u(3:N)-u(2:N-1))/dx ...
                                        -f(u(2:N-1))-nu*(u(2:N-1)-u(1:N-2))/dx);
        u(2:N-1) = 0.5*(uhat(2:N-1)+u(2:N-1)+dt/dx*(f(u(2:N-1))+nu*(u(3:N)-u(2:N-1))/dx ...
                                        -f(u(1:N-2))-nu*(u(2:N-1)-u(1:N-2))/dx));
    else
        uhat(2:N-1) = u(2:N-1) + dt/dx*(f(u(2:N-1))+nu*(u(3:N)-u(2:N-1))/dx ...
                                        -f(u(1:N-2))-nu*(u(2:N-1)-u(1:N-2))/dx);
        u(2:N-1) = 0.5*(uhat(2:N-1)+u(2:N-1)+dt/dx*(f(u(3:N))+nu*(u(3:N)-u(2:N-1))/dx ...
                                        -f(u(2:N-1))-nu*(u(2:N-1)-u(1:N-2))/dx));
    end
    if mod(step,100) == 0
        plot(x,u,'b-');
        axis([-1,1,-1,1]);
        drawnow
    end
end

end

function fu = f(u)
fu = -u.^2/2;
end

