import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import brentq

# Define the two functions
def f1(n):
    return 5 * n**2 + 10 * np.log2(n)

def f2(n):
    return 6 * n**2

# Find crossover point: f1(n) = f2(n) => 10*log2(n) = n^2
# i.e., f1(n) - f2(n) = 0
def diff(n):
    return f1(n) - f2(n)

# Search for crossover in range [1.1, 100]
# diff(n) = 10*log2(n) - n^2; positive for small n (log grows), negative eventually
crossover_n = brentq(diff, 1.1, 100)
crossover_y = f2(crossover_n)

print(f"Crossover point: n = {crossover_n:.4f}, f(n) = {crossover_y:.4f}")

# Plot
n = np.linspace(1.01, 20, 1000)

plt.figure(figsize=(9, 6))
plt.plot(n, f1(n), label=r'$5n^2 + 10\log_2 n$', linewidth=2)
plt.plot(n, f2(n), label=r'$6n^2$', linewidth=2)

plt.axvline(crossover_n, color='gray', linestyle='--', linewidth=1)
plt.plot(crossover_n, crossover_y, 'ro', markersize=8,
         label=f'Crossover at n ≈ {crossover_n:.4f}')

plt.annotate(f'n ≈ {crossover_n:.4f}\nf(n) ≈ {crossover_y:.1f}',
             xy=(crossover_n, crossover_y),
             xytext=(crossover_n + 1.5, crossover_y - 50),
             arrowprops=dict(arrowstyle='->', color='black'),
             fontsize=10)

plt.xlabel('n', fontsize=13)
plt.ylabel('f(n)', fontsize=13)
plt.title('Crossover: $5n^2 + 10\\log_2 n$ vs $6n^2$', fontsize=14)
plt.legend(fontsize=12)
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.savefig('crossover.png', dpi=150)
plt.show()
print("Plot saved to crossover.png")
