# make_data.py
"""
Create data.txt containing 100 million characters in which
  • 'A' appears 95 % of the time
  • 'B'–'E' share the remaining 5 %
Change N to taste ( ≥ 10 million is enough to show a PGO win).
"""
import random, itertools, sys

N = 10000000          # characters to write      (≈100 MB)
rng = random.Random(42)  # deterministic seed

letters  = "ABCDE"
weights  = [95, 2, 1, 1, 1]        # very skewed toward 'A'
choices  = rng.choices             # local alias for speed

with open("data.txt", "w") as f:
    get_chunk = lambda: "".join(choices(letters, weights, k=1_000_000))
    for _ in range(N // 1_000_000):
        f.write(get_chunk())
        f.flush()  # Ensure data is written to disk
print("data.txt written")