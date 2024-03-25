%% Importação e Exibição de Imagem

% Carregar uma Imagem
I = imread('arara.jpg');

% Exibir a imagem
imshow(I)

%% Importação, Visualizar e Salvar Vídeos

% Criar um objeto VideoReader
inputVideo = VideoReader('matlab.mp4')

% Cria um video de saída
outputVideo = VideoWriter('video-saida.mp4', 'MPEG-4')
outputVideo.FrameRate = inputVideo.FrameRate
open(outputVideo);

while hasFrame(inputVideo)
    
    frame = readFrame(inputVideo);

    imshow(frame)
    
    %... Realizar processamento da imagem

    writeVideo(outputVideo, frame);
    
end

close(outputVideo);

%% Imagens Digitais
I = imread('arara.jpg');
imtool(I) 
% OU
imageViewer(I)



