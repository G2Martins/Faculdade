function area = area_circulo(diametro)
    % Calcula o raio
    raio = calcula_raio(diametro);

    % Calcula a area
    area = pi * raio^2;
end

function r = calcula_raio(d)
    r = d/2;
end