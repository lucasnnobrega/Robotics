function r = amostra(b)
r = 0;

    for i = 1 : 12
        r = r + (-b + (b - (-b)) .* rand(1,1));
    end

end