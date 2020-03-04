function [xl, yl, thetal] = modelo_mov_vel(x, y, theta, v, w)

delta_t = 2;

alfa1 = 0.02;
alfa2 = 0.002;
alfa3 = 0.02;
alfa4 = 0.2;
alfa5 = 0.2;
alfa6 = 0.2;

vc = v + amostra(alfa1*abs(v) + alfa2*abs(w));
wc = w + amostra(alfa3*abs(v) + alfa4*abs(w));
gamma = amostra(alfa5*abs(v) + alfa6*abs(w));

xl = x - (vc/wc)*sin(theta) + (vc/wc)*sin(theta + wc*delta_t);
yl = y + (vc/wc)*cos(theta) - (vc/wc)*cos(theta + wc*delta_t);
thetal = theta + wc*delta_t + gamma*delta_t;

plot(xl, yl, '.r');
hold on;

return

end