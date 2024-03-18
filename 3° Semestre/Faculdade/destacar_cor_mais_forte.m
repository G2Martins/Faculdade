function nova_imagem = destacar_cor_mais_forte(imagem)
    [linhas, colunas, canais] = size(imagem);
    nova_imagem = zeros(linhas, colunas, canais); 

    for i = 1:linhas
        for j = 1:colunas
            pixel = imagem(i,j,:);
            [valor_mais_forte, indice] = max(pixel);
            novo_pixel = zeros(1,1,canais);

            novo_pixel(indice) = valor_mais_forte;
            nova_imagem(i,j,:) = novo_pixel;
        end
    end
end