# 2023-07-04

## numpy

* `import numpy as np`
    * `numpy`
        * `np.__version__`
        * `np.array([1, 2, 3, 4, 5])`
        * `np.arange(0, 11, 2)`
        * `np.arange(100, dtype=float)`
        * `np.zeros(5)`
        * `np.ones(10)`
        * `np.empty(5)`
        * `np.linspace(0, 10, num=5)`
        * `np.eye(3)`
        * `np.full((2, 3), 1)`
    * `numpy.random`
        * `np.random.random((2, 3))`
        * `np.random.seed(1)`
        * `np.random.randint(0, 10, (2, 3))`
        * `np.random.randn(2, 3)`
    * `numpy.ndarray`
        * `arr.shape`
        * `arr.ndim`
        * `arr.size`
        * `arr.reshape(2, -1)`
        * `arr.dtype`
        * `arr.copy()`
        * `arr.sort(axis=0)`        
    * calculation
        * `arr.sum(axis=0)`
        * `np.max(a, axis=0)`
        * `np.min(a, axis=0)`
        * `np.mean(a, axis=0)`
        * `np.median(a, axis=0)`
        * `np.std(a, axis=0)`
        * `np.sqrt(a)`
        * `np.exp(a)`
        * `np.sin(a)`
        * `np.cos(a)`
        * `np.tan(a)`
        * `np.matmul(b, c)`
        * `np.dot(b, c)`
    * indexing
        * `e[:, 5:]`
        * `e[(0, 1, 2, 4), (0, 1, 2, -1)]`
        * `e[e%2 == 0]`
```python
class Fancy:
    def __init__(self):
        print("init")

    def __getitem__(self, x):
        print(x)
        print(type(x[0]))

Fancy()[:, 5:]
```
```Text
init
(slice(None, None, None), slice(5, None, None))
<class 'slice'>
```
