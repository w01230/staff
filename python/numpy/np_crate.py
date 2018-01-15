# -*- coding: utf-8 -*-

import numpy as np

x = np.array([1, 2, 3])
print(x)
print(x.shape)

x = np.array([[1, 2], [3, 4], [5, 6]])
print(x)
print(x.shape)

x = np.zeros(6)
print(x)

x = np.zeros((2, 3))
print(x)

x = np.empty((3, 3))
print(x)
