import matplotlib.pyplot as plt


with open('inp.txt', 'r') as f:
    n = int(f.readline().strip())
    coord = [tuple(map(float, line.strip().split())) for line in f.readlines()]



coord.append(coord[0]) 

xs, ys = zip(*coord) 

plt.figure()
plt.plot(xs,ys) 
plt.show() 
