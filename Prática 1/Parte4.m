image = imread('mapaexemplo.bmp');
grayimage = rgb2gray(image);
bwimage = grayimage < 0.5;
grid = robotics.BinaryOccupancyGrid(bwimage,50);
show(grid)