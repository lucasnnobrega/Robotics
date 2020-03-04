function prob = prob(a,b)
    termoUm = (1/(sqrt(2*pi*b^2)));
    termoDois = exp((-1/2 * (a^2/b^2)));
    prob = termoUm*termoDois;
end