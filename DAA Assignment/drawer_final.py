import matplotlib.pyplot as plt

# Open the file and read the points
with open('Points.txt', 'r') as file:
    lines = file.readlines()

# Create a new figure
# fig = plt.figure()

# Create a new plot
# ax = fig.add_subplot(111)

# Iterate over each line in the file
for line in lines:
    # Split the line into its four floats
    x1, y1, x2, y2 = map(float, line.strip().split())

    # Plot the line between the two points
    plt.plot([x1, x2], [y1, y2],color = 'b')

# Display the plot
plt.show()
