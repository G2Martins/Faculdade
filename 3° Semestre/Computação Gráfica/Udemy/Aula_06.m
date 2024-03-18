%% O que é uma String?
% Na programaçaõ de computadores, uma cadeia de caracteres ou string é uma
% sequência de caracteres, geralmente utilizada para representar palavras,
% frases ou textos de um programa


%% Criando uma String?
str1 = 'Olá, mundo!'
str2 = "Olá, mundo!"


%% Acessar uma String?
str1(1:3) % Percorre a string do 1° caracteres até o 3° com aspas simples
str2(1:3) % Apresentará um erro pelo fato das aspas duplas


%% Combinando uma String (join)
vet1 = ["banana", "uva", "maracuja"] % Exibe cada palavra separada
vet2 = ['banana', 'uva', 'maracuja'] % Exibe todas juntas

var3 = join(vet1) % Junta em uma variável as 3 palavras separadas
                  % "banana uva maracuja"


%% Acrescentar Strings (plus)
str3 = "Uva"
str4 = "Roxa"

str5 = str3 + str4 % Junta as strings -> "UvaRoxa"
str6 = str3 + " " + str4 % Junta as strings -> "Uva Roxa"

%% Anexar ao final (append)
str7 = "Uva"
str8 = "Roxa"

str9 = append(str7, str8) % Adiciona ao final -> "UvaRoxa"
str10 = append(str7," ", str8) % Adiciona ao final -> "Uva Roxa"


%% Converter numero em String (2 Funções)
var_num = 1234
str11 = string(var_num) % Exibe -> "1234" ou str11+5 -> "12345"
str12 = num2str(var_num)


%% Converter string em número (2 Funções)
str = "5678"
var = double(str) % Exibe -> 5678 ou var+10 -> 5688
var2 = str2num(str)


%% Editar
% Apagar algo da string
str1 = "Bom dia!"
str2 = erase(str1, "dia!") % Remove "dia!"

% Apagar algo da string entre dois caracteres
str1 = "123456789"
str2 = eraseBetween(str1, "3", "8") % Apaga entre o 3 e o 8

% Manipulações (caixa baixa, caixa alta, invertida)
str = "O FLAMENGO é o melhor do MUNDOOO"

str_min = lower(str) % Exibe -> "O flamengo é o melhor do mundooo"

str_mai = upper(str) % Exibe -> "O FLAMENGO É O MELHOR DO MUNDOOO"

str_rev = reverse(str)


%% Comparando Strings
str1 = "Bom dia!"
str2 = "Bom dia!"

% Comparando a string (case sensitive)
strcmp(str1, str2) % Exibe -> 1 (true)

% Comparando a string (case insensitive
strcmpi(str1, str2)
