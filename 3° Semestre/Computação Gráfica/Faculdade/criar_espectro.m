function imagem_espectro = criar_espectro(width, height)

imagem_espectro = zeros(height, width, 3);

for y = 1:height
    for x =1:width
        r = x / width;
        g = 1;
        b = 1;
        rgb = hsv2rgb([r, g, b]);
        imagem_espectro(y, x, :) = rgb * 255;
    end
end

imagem_espectro = uint8(imagem_espectro);
end