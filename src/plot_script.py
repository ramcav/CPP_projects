import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt("output/mobby_ranks.txt", dtype={'names': ('rank', 'freq', 'word'), 'formats': ('i4', 'i4', 'U10')})
plt.loglog(data['rank'], data['freq'], marker='o', linestyle='None')
plt.xlabel("Rank (log scale)")
plt.ylabel("Frequency (log scale)")
plt.title("Word Frequency Distribution on Log-Log Scale")
plt.savefig("img/python_plot.png")
plt.show()