# 2023-06-10

## 자료구조
* 스택
  * 선입후출
  * python. list
* 큐
  * 선입선출
  * python. from collections import deque
    * append, popleft
  * Java. `Queue<Integer> q = new LinkedList<>();`
    * offer, poll
* 우선순위 큐
  * 우선순위가 높은 데이터부터 처리하고 싶을 때
* heap
  * min heap과 max heap이 있음
  * 완전 이진트리
  * python. min heap, import heapq
    * heappush, heappop
  * C++, `priority_queue<int> h;`
    * push, pop
* Tree
  * root node
    * 부모가 없는 최상위 노드
  * leaf node
    * 자식이 없는 노드
  * size
    * 모든 노드의 개수
  * depth
    * 루트 노드부터의 거리
  * height
    * max depth
  * degree
    * 각 노드의 자식 방향 간선 개수
* 이진탐색 트리
  * 왼쪽 자식 노드 < 부모 노드 < 오른쪽 자식 노드
* 트리 순회
  * 전위 순회
    * 자신, 왼쪽, 오른쪽
  * 중위 순회
    * 왼쪽, 자신, 오른쪽
  * 후위 순회
    * 왼쪽, 오른쪽, 자신
* 바이너리 인덱스 트리(펜윅 트리)
  * 바이너리 인덱스로 만든 트리. 난이도가 조금 있다.
  * 구간 합을 풀 때 빠른 속도로 풀 수 있다.
  * (i & -i) 비트 연산 값을 이용한다.

```python
import os
import io
speed_input = io.BytesIO(os.read(0, os.fstat(0).st_size))


class Solver:
    def __init__(self):
        self.n, self.m, self.k = map(int, speed_input.readline().split())
        others = speed_input.readlines()
        self.arr = [0] + [*map(int, others[:self.n])]
        self.request = [[int(i) for i in x.split()] for x in others[self.n:]]
        self.fenwick = [0] * (self.n + 1)

        for i, x in enumerate(self.arr[1:], 1):
            self.update(i, x)

    def update(self, i, x):
        while i <= self.n:
            self.fenwick[i] += x
            i += i & -i

    def prefix_sum(self, i):
        result = 0
        while i > 0:
            result += self.fenwick[i]
            i -= i & -i
        return result

    def interval_sum(self, b, c):
        return self.prefix_sum(c) - self.prefix_sum(b - 1)

    def solve(self):
        ans = []
        for a, b, c in self.request:
            if a == 1:
                self.update(b, c - self.arr[b])
                self.arr[b] = c
            if a == 2:
                ans.append(str(self.interval_sum(b, c)))
        print("\n".join(ans))


if __name__ == '__main__':
    Solver().solve()
```

* 정렬
  * 데이터를 특정 기준에 따라 순서대로 나열하는 것.
  * 선택 정렬
    * 모든 요소를 검사하여 하나씩 선택하여 정렬. O(N**2)
  * 삽입 정렬
    * 요소를 하나씩 전진하면서 왼쪽 부분의 어느 곳에 삽입하면 되는지 판단하여 정렬. O(N**2)
  * 퀵 정렬
    * 일반적인 상황에서 가장 많이 사용하는 대표적인 정렬
    * 정렬된 값을 정렬하려고 하면 최악의 경우가 된다. 평균 O(N*log(N))
  * 계수 정렬
    * 숫자를 count하고 차례대로 출력
    * 메모리를 많이 사용할 수록 빨라진다.
* 그래프 탐색
  * DFS
    * 스택 사용
    * 깊이 우선 탐색
  * BFS
    * 큐 사용
    * 너비 우선 탐색
  * 다익스트라 최단 경로 알고리즘
    * 현실 세계 길 찾기에서 유용 (음의 간선이 없을 때 가능)
    * 특정 노드에서 출발하여 다른 모든 노드로 가는 최단 경로를 계산
    * 그리드 알고리즘 유형에 속함
    * 음의 간선 순환이 생기면 최단 경로의 값이 음의 무한의 값이 된다.
  * 플로이드 워셜 알고리즘
    * 모든 노드에서 다른 모든 노드까지 최단 경로를 모두 계산
    * 다이나믹 프로그래밍 유형에 속함
    * O(N**3)
  * 벨만 포드 알고리즘
    * 음수 간선이 포함된 경우
* 유니온 파인드(서로소 집합) 자료구조
  * 서로소 부분 집합들로 나누어진 원소들의 데이터를 처리하기 위한 자료구조
  * 합집합(Union)
    * 인덱스가 더 작은 노드를 부모노드로 가리키는 것이 관행이다.
  * 찾기(Find)
  * 합쳐서 Union Find 자료구조
* 신장 트리
  * 그래프에서 모든 노드를 포함하면서 사이클이 존재하지 않는 부분 그래프(트리)
* 최소 신장 트리
  * 최소한의 비용으로 구성되는 신장 트리를 찾아야 할 때
* 크루스칼 알고리즘
  * 대표적인 최소 신장 트리 알고리즘
  * 그리디 알고리즘으로 분류
* 최소 공통 조상 알고리즘
  * 부모 노드로 거슬러 올라가면서 부모 노드의 깊이가 같을 때 서로의 노드가 동일한 지 검사

  