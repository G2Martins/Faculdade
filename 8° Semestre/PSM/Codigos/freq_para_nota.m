function nome = freq_para_nota(f)
% FREQ_PARA_NOTA  Converte uma frequencia (Hz) no nome da nota musical.
%   Referencia: La4 = 440 Hz (numero MIDI 69).
notas = {'Do','Do#','Re','Re#','Mi','Fa','Fa#','Sol','Sol#','La','La#','Si'};
if f <= 0
    nome = '---';
    return;
end
n_midi = round(12*log2(f/440)) + 69;
idx    = mod(n_midi, 12) + 1;
oitava = floor(n_midi/12) - 1;
nome   = sprintf('%s%d (%.1f Hz)', notas{idx}, oitava, f);
end
