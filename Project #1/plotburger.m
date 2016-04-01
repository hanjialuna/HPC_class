function [N, x, u] = plotburger( fname )
% [N, x, u] = plotburger( fname )
%
% Reads the output of your burger program and returns the data in 
% Matlab format.  Also plots the data for viewing.
%
% Input:
% fname = filename of your data file
%
% Output:
% N = number of grid points
% x = x location of the grid points (length N)
% u = 5xN array containing the u values of the data at the
%     specified time points.

fid = fopen(fname, 'r');
N = fread(fid, 1, 'int');
x = fread(fid, N, 'double');
u = fread(fid, [N,5], 'double');

plot([x,x,x,x,x],u);
legend('t=0.0','t=0.5','t=1.0','t=1.5','t=2.0');

end

