function [u, x] = burger2(N, dt, T)
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
A = sparse(eye(N)*(1+nu*dt/dx^2)-diag(ones(N-1,1),1)*nu*dt/2/dx^2 ...
    -diag(ones(N-1,1),-1)*nu*dt/2/dx^2);
A(1,:) = 0;
A(1,1) = 1;
A(N,:) = 0;
A(N,N) = 1;
B = eye(N)*(1-nu*dt/dx^2)+diag(ones(N-1,1),1)*nu*dt/2/dx^2 ...
    +diag(ones(N-1,1),-1)*nu*dt/2/dx^2;
B(1,:)=0;
B(N,:)=0;
for step=1:nsteps
    if mod(step,2) == 0
        uhat(2:N-1) = u(2:N-1) + dt/dx*(f(u(3:N))-f(u(2:N-1)));
        u(2:N-1) = 0.5*(uhat(2:N-1)+u(2:N-1)+dt/dx*(f(u(2:N-1))-f(u(1:N-2))));
    else
        uhat(2:N-1) = u(2:N-1) + dt/dx*(f(u(2:N-1))-f(u(1:N-2)));
        u(2:N-1) = 0.5*(uhat(2:N-1)+u(2:N-1)+dt/dx*(f(u(3:N))-f(u(2:N-1))));
    end
    u = (A\B*u')';
    if mod(step,100) == 0
        plot(x,u,'b-');
        axis([-1,1,-1,1]);
        title(sprintf('Time = %f',step*dt));
        drawnow
    end
end

end

function fu = f(u)
fu = -u.^2/2;
end

