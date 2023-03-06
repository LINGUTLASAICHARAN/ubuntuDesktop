import matplotlib.pyplot as plt

# Read edges from points.txt file
edges = []
with open('points.txt', 'r') as file:
    for line in file:
        edge = line.strip().split()
        edges.append(edge)

# Convert edges to x and y coordinates
x_coords = [float(edge[0]) for edge in edges]
y_coords = [float(edge[1]) for edge in edges]

# Draw edges using matplotlib
fig, ax = plt.subplots()
ax.plot(x_coords, y_coords)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_title('Edges from points.txt')
plt.show()