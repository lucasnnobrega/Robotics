function [v,w] = fcn(v1,v2)
    L = 2 * 0.17;
    v = (v1 + v2)/2;
    w = (v1 - v2)/L;
end