# 2023-06-13

## 알고리즘

* 위상 정렬
    * 진입 차수(Indegree)
        * 특정한 노드로 들어오는 간선의 개수
    * 진출 차수(Outdegree)
        * 특정한 노드에서 나가는 간선의 개수
    * 알고리즘
        1. 진입 차수가 0인 모든 노드를 큐에 넣고
        2. 원소를 꺼내 나가는 간선을 그래프에서 제거
        3. 새로 진입 차수가 0인 노드를 큐에 넣는다.
        4. 반복한다.
    * DAG(사이클이 없는 방향 그래프)이어야 한다.
* 파이썬 유용한 표준 라이브러리
    * 내장 함수 (built-in)
        * sum
            * 합계
        * min
            * 최솟값
        * max
            * 최댓값
        * eval
            * 평가 (문자열을 그대로 실행)
        * sorted
            * 정렬
            * key=`<function>` 으로 비교할 키를 선택할 수 있다.
            * reverse=True 이면 역순이다.
    * itertools
        * permutations
            * 순열
            * from itertools from permutations
            * `permutations(<iterable>, <int>)`
            * ('A', 'B') ('A', 'C') ('B', 'A') ('B', 'C') ('C', 'A') ('C', 'B')
        * combinations
            * 조합
            * from itertools from combinations
            * `combinations(<iterable>, <int>)`
            * ('A', 'B') ('A', 'C') ('B', 'C')
        * product
            * 중복 순열
            * `product(<iterable>, repeat=<int>)`
            * ('A', 'A') ('A', 'B') ('A', 'C') ('B', 'A') ('B', 'B') ('B', 'C') ('C', 'A') ('C', 'B') ('C', 'C')
        * combinations_with_replacement
            * 중복 조합
            * `combinations_with_replacement(<iterable>, <int>)`
            * ('A', 'A') ('A', 'B') ('A', 'C') ('B', 'B') ('B', 'C') ('C', 'C')
        ```python
        from itertools import product, permutations, combinations, combinations_with_replacement

        res = ['A', 'B', 'C']
        num = 2

        print(*product(res, repeat=num))
        print(*permutations(res, num))
        print("==========")
        print(*combinations(res, 2))
        print(*combinations_with_replacement(res, 2))
        ```
    * heapq
        * 힙
    * bisect
        * 이진 탐색
    * collections
        * deque
        * `Counter(<iterable>)`
            * dict 형태로 바꿀 수 있다.
            * `return_value['element_name'] == count`
    * math
        * 팩토리얼, 제곱근, 삼각함수 관련 등.
        * gcd(a, b)
            * 최대공약수
* 소수 판별
    * 에라토스테네스의 체
        * 2부터 n까지 숫자를 나열
        * i를 하나씩 늘리면서 소수인 경우 i의 배수를 체에서 제거.
        * 메모리 측면에서 비효율적일 수 있다.
* 이진 탐색
    * 정렬된 데이터에서 사용 가능
    * `from bisect import bisect_left, bisect_right`
        * 왼쪽 우선 or 오른쪽 우선
        * `bisect_left(<iterable>, <value>)`
    * 파라메트릭 서치 (Parametric Search)
        * 최적화 문제를 결정 문제(예, 아니오)로 바꾸어 해결하는 기법
* 다이나믹 프로그래밍 (DP)
    * 계산된 결과를 메모리에 저장해 같은 계산을 다시 하지 않도록 하는 기법.
    * 탑다운과 보텀업(하향식, 상향식) 방식이 있다.
    * 다음의 조건을 만족할 때 사용할 수 있다.
        * 최적 부분 구조 (Optimal Substructure)
            * 작은 문제의 답을 모아 큰 문제를 해결할 수 있을 때
        * 중복되는 부분 문제 (Overlapping Subproblem)
            * 동일한 작은 문제를 반복적으로 해결해야 할 때