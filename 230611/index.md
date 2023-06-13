# 2023-06-11

## 자료구조

* 최소 공통 조상 알고리즘
  * 부모 노드로 거슬러 올라가면서 부모 노드의 깊이가 같을 때 서로의 노드가 동일한 지 검사
  * 희소 배열을 사용하여 성능 향상.
  * 제일 상단에 있는 부모부터 검사하여 거슬러 올라가는 방식을 사용.
    * 정순으로 올라가면 부모를 지나칠 수 있지만, 역순으로 내려오면 지나치는 일이 없다.
    * 지나치면 다시 돌아와야하는데, 그렇게 되면 알고리즘이 복잡해진다.
    * 최소 공통 조상보다 깊이가 얕은 모든 부모가 공통 조상이기 때문에 가능하다.

```python
import os
import io
import math
speed_input = io.BytesIO(os.read(0, os.fstat(0).st_size))
LOG = math.ceil(math.log2(100000))


def main():
    n = int(speed_input.readline())
    parent = [[0] * LOG for _ in range(n+1)]
    depth = [0] * (n+1)
    check = [False] * (n+1)
    graph = [[] for _ in range(n+1)]

    for _ in range(n-1):
        a, b = map(int, speed_input.readline().split())
        graph[a].append(b)
        graph[b].append(a)

    # calculate depth
    cur_depth = 1
    stack = [1]
    while stack:
        next_stack = []
        for x in stack:
            check[x] = True
            depth[x] = cur_depth
            for y in graph[x]:
                if check[y]:
                    continue
                parent[y][0] = x
                next_stack.append(y)
        cur_depth += 1
        stack = next_stack

    for i in range(1, LOG):
        for j in range(1, n+1):
            parent[j][i] = parent[parent[j][i-1]][i-1]

    # solve
    ans = []
    m = int(speed_input.readline())
    for _ in range(m):
        a, b = map(int, speed_input.readline().split())

        if depth[a] > depth[b]:
            a, b = b, a
        for i in reversed(range(LOG)):
            if depth[b] - depth[a] >= (1 << i):
                b = parent[b][i]

        if a == b:
            ans.append(str(a))
            continue

        for i in reversed(range(LOG)):
            if parent[a][i] != parent[b][i]:
                a = parent[a][i]
                b = parent[b][i]

        ans.append(str(parent[a][0]))

    print("\n".join(ans))


if __name__ == '__main__':
    main()
```
