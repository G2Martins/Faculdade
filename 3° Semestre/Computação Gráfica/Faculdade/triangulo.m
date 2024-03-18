function y = triangulo(v1,v2, v3, M, N)

    %Montando matriz de zeros originale transformando em double:
    y = zeros(M,N);
    y = double(y)/255;

    for j = 1 : 3

       if j==1 %Primeira reta
        v0 = v1; vf = v2;
       end

       if j==2 %Segunda reta
        v0 = v2; vf = v3;
       end

       if j == 3 %Terceira reta
        v0 = v3; vf = v1;
       end


       %Calculando o valor de da diferença entre as coordenadas x e y
       delta_i = vf(1) - v0(1);
       delta_j = vf(2) - v0(2);

       %Escolhendo a maior entre as duas diferenças
        %A função abs é utilizada para não deixar o valor ser negativo
       N = max(abs(delta_i), abs(delta_j));

        %Laço para pintar pixel a pixel de branco entre os pontos
        for i = 1 : N+1
          t = (i-1)/N; %Calculando os tempos

          P = ((1-t).*v0) + (t.*vf); %Calculando qual quais pixels deverão ser preenchidos de branco
          P_int = round(P); %Arrendondando coordenadas do pixel para não gerar problema
          y(P_int(1), P_int(2)) = 1; % Transformando pixels escolhidos em branco
         end

        j = j+1; %Incrementando para desenhar todas as 3 retas
    end