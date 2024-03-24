%% Função Seno

% Seno (radiano)
sin(0.5*pi) % Seno de 90° é 1
sin(1.87)

% Seno (graus)
sind(0) % Já vai direto e Exibe -> 0
sin(45)
sind(90) % Já vai direto e Exibe -> 1

% Seno (multiplos de pi)
sinp(0.5) % Seno de 90° e Exibe -> 1

% Inversa do Seno (radianos)
asin(1) % recebe o valor do seno e retorna o angulo em radianos

% Inversa do Seno (graus)
sind(1) % Retorna o valor do Angulo e Exibe 90°

%% Função Cosseno

% Cosseno (radiano)
cos(pi) % Cosseno de 180 -> -1
cos(1/3*pi) % Cosseno de 60° -> 0.500

% Cosseno (graus)
cosd(45)
cosd(60)
cosd(90)
cosd(180)

% Cosseno (multiplos de pi)
cospi(1) % 180° -> -1
cospi(1/3) % 60° -> 0.500

% Inversa do Cosseno (radianos)
acos(0.5) % Cosseno de 60° em radianos
acos(1) % Cosseno de 0° em radianos
acos(-1) % Cosseno de 180° em radianos

% Inversa do Cosseno (graus)
acosd(0.5) % Qual o angulo em graus que o cosseno é 0.5 -> 60°
acosd(1) % Qual o angulo em graus que o cosseno é 1 -> 0°
acosd(-1) % Qual o angulo em graus que o cosseno é 1- -> 180°

%% Função Tangente

% Tangente (radiano)
tan(pi/4) % Valor da tangente de 45° 

% Tangente (graus)
tand(45) % Valor da tangente de 45°

% Inversa da Tangente (radianos)
atan(1) % 45° || pi/4

% Inversa da Tangente (graus)
atand(1) % Exibe -> 45°

% Inversa FOUR-QUADRANT da tangente (radianos)
%          (y,x)
var = atan2(1,-1) % retorna em radianos
rad2deg(var) % Retorna o Ângulo -> 135°

% Inversa FOUR-QUADRANT da tangente (graus)
atan2d(1,-1) % Retorna o Ângulo -> 135°
atan2d(-1,-1) % Retorna o Ângulo -> -135°

% x > 0, y > 0 -------- Ângulo entre 0° e 90°
% x < 0, y > 0 -------- Ângulo entre 90° e 180°
% x < 0, y < 0 -------- Ângulo entre 180° e 270°
% x > 0, y < 0 -------- Ângulo entre 270° e 360°

%% Hipotenusa Fórmula -> c² = a² + b²
%    (Cat 1(a), Cat 2(b)

hypot(3,4) % Exibe -> 5






