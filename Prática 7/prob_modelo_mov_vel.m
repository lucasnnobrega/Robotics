function probabilidade = prob_modelo_mov_vel(ps, u, ps_ant, alfa, t)

delta_t = 2;

xl = ps(1);
yl = ps(2);
thetal = ps(3);

v = u(1);
w = u(2);

x = ps_ant(1);
y = ps_ant(2);
theta = ps_ant(3);

alfa1 = alfa(1);
alfa2 = alfa(2);
alfa3 = alfa(3);
alfa4 = alfa(4);
alfa5 = alfa(5);
alfa6 = alfa(6);

mi = 1/2 * ((x - xl)*cos(theta) + (y - yl)*sin(theta))/((y - yl)*cos(theta) - (x - xl)*sin(theta));
xc = ((x + xl)/2) + mi * (y - yl);
yc = ((y + yl)/2) + mi * (x - xl);
rc = sqrt((x - xc)*(x - xc) + (y - yc)*(y - yc));
delta_theta = atan2(yl - yc, xl - xc) - atan2(y - yc, x - xc);

vc = (delta_theta/delta_t)*rc;
wc = delta_theta/delta_t;
gamma = ((thetal - theta)/delta_t) - wc;

probabilidade = prob((v - vc), alfa1*abs(v) + alfa2*abs(w)) * prob((w - wc), alfa3*abs(v) + alfa4*abs(w)) * prob (gamma, alfa5*abs(v) + alfa6*abs(w));

figure(1)
plot(x, y, 'og');
hold on;
plot(xl, yl, 'ok');
plot([x xl], [y yl]);
axis([0 7 0.5 9])

for i = 1 : 200
    modelo_mov_vel(x, y, theta, v, w) % O alfa e delta_t não são passados pois já estão definidos dentro da função
end

end