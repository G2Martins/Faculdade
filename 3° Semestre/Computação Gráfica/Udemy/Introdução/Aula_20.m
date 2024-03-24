%% Handle Function
%{

sintaxe

nome_da_função = @(entradas) saida;

%}

area_circulo_2 = @(r) pi * r^2;

area = area_circulo_2(2)

calc_hipotenusa = @(c1, c2) sqrt(c1^2 + c2^2)
hipot = calc_hipotenusa(3,4)