
import numpy as np
import matplotlib.pyplot as plt

# Since there is an issue saving as EPS, let's try saving the graph as a PNG file instead.

# Recreate the extended scale graph for saving
fig, ax = plt.subplots(figsize=(10, 6))

ax.plot(n_large_scale, log_n_large_scale, label='O(log n)', lw=2)
ax.plot(n_large_scale, n_large_scale_linear, label='O(n)', lw=2)
ax.plot(n_large_scale, n_log_n_large_scale, label='O(n log n)', lw=2)
ax.plot(n_large_scale, n_squared_large_scale, label='O(n^2)', lw=2)
ax.plot(n_large_scale, n_cubed_large_scale, label='O(n^3)', lw=2)
ax.plot(n_large_scale[:150], two_power_n_large_scale[:150], label='O(2^n)', lw=2)  # Limit range to keep it readable

ax.set_title('Computational Complexity Classes (Extended Scale)')
ax.set_xlabel('n (size of input)')
ax.set_ylabel('Number of operations (time)')
ax.set_yscale('log')  # Keep a logarithmic scale for the y-axis

ax.legend()
ax.grid(True, which="both", ls="--")

ax.set_xlim(0, 100)  # Limit x-axis to 100 for readability

# Define the PNG file path
png_file_path = '/mnt/data/complexity_graph.png'

# Save the figure as a PNG
fig.savefig(png_file_path, format='png')

# Close the plt object to clear the figure
plt.close(fig)

# Return the path if successful
png_file_path
plt.show()
