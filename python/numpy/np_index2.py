# -*- coding: utf-8 -*-

import numpy as np

x = np.array([3, 2, 1, 0])
print(x[[0, 1, 2]])
print(x[[-1, -2, -3]])

y = np.array([[1, 2], [3, 4], [5, 6]])
print(y[[0, 1]])
print(y[[0, 1], [0, 1]])
