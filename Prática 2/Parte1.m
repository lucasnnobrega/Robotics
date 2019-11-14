fprintf("Parte 1 da prática 2\n")

%function [xf, yf]=gertrajPRM(res)


%% Mapa normal para OcupancyGrid
image = imread('mapaexemploCorreto.bmp');
grayimage = rgb2gray(image);
bwimage = grayimage < 0.5;
grid = robotics.BinaryOccupancyGrid(bwimage, 50);
show(grid)


%% Infla o OcuppancyGrid map
robotRadius = 0.1;
mapInflated = copy(grid);
inflate(mapInflated,robotRadius);
show(mapInflated)

%% Mapa
prm = robotics.PRM;
prm.Map = mapInflated;

%% Local de Partida do Robô
startLocation = [1 0.5];

%% Local de Chegada do Robô
fprintf("Invalid location: endLocation = [8 6]");
endLocation = [8 6]

%% Colocar o restante dos parâmetros para incluir os pontos inicial e final nos nós

prm.NumNodes = 200;
prm.ConnectionDistance = 15;
show(prm)

%% Procura Caminho
path = findpath(prm, startLocation, endLocation);
path

%% Achando o número mínimo de nós que encontre um caminho.
while isempty(path)
    % Se nenhum caminho for encontrado, aumente o número de nós
    prm.NumNodes = prm.NumNodes + 10;
    % Use a função |update| para recriar o mapa de rotas PRM com
    % o atributo modificado
    update(prm);
    % Procure por um caminho com o PRM atualizado
    path = findpath(prm, startLocation, endLocation);
end
% mostre o caminho final
path

%%
show(prm)

%% Mostra o numero de Nós
prm.NumNodes



