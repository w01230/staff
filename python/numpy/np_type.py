# -*- coding: utf-8 -*-

import numpy as np

x = np.array([1, 2, 3, 5], dtype=np.int64)
print(x)
print(x.dtype)

x = np.array([1, 2, 3], dtype=np.float64)
print(x)
print(x.dtype)

y = x.astype(np.int32)
print(y)
print(y.dtype)

z = y.astype(np.float64)
print(z)
print(z.dtype)

x = np.array(['1', '2', '3'], dtype=np.string_)
y = x.astype(np.int32)
print(x)
print(y)

x = np.array([1., 2.6, 3.], dtype=np.float32)
y = np.arange(3, dtype=np.int32)
print(y)
print(y.astype(x.dtype))
