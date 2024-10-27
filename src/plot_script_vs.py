import matplotlib.pyplot as plt
import numpy as np

data1 = np.loadtxt("output/mobby_ranks.txt", dtype={'names': ('rank', 'freq', 'word'), 'formats': ('i4', 'i4', 'U10')})
plt.loglog(data1['rank'], data1['freq'], marker='o', linestyle='None', label="Moby Dick")

data2 = np.loadtxt("output/quijote_ranks.txt", dtype={'names': ('rank', 'freq', 'word'), 'formats': ('i4', 'i4', 'U10')})
plt.loglog(data2['rank'], data2['freq'], marker='x', linestyle='None', label="Don Quixote")

plt.xlabel("Rank (log scale)")
plt.ylabel("Frequency (log scale)")
plt.title("Word Frequency Distribution on Log-Log Scale")
plt.legend()

plt.savefig("img/combined_plot.png")