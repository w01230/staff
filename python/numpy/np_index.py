# -*- coding: utf-8 -*-

import numpy as np

x = np.array([3, 2, 1, 0])
y = np.array([True, False, True, False])

print(x[y])
print(x[y == False])
print(x[x < 3])

