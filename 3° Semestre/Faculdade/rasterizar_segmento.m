function rasterizar_segmento(v1, v2, M, N)

    X = zeros(M, N);

    delta_x = v2(1) - v1(1);
    delta_y = v2(2) - v1(2);

    steps = max(abs(delta_x), abs(delta_y));

    for k = 0:steps
        tk = k / steps;
        x = (1 - tk) * v1(1) + tk * v2(1);
        y = (1 - tk) * v1(2) + tk * v2(2);
        X(round(x), round(y)) = 1; 
    end

    imshow(X);
end