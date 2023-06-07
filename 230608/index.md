# 2023-06-08

## 파이썬 통계분석

### 1차원 이산형 확률변수
#### **정의**

* 이산형 확률변수
  * 취할 수 있는 값이 이산적인 확률변수
  * 정수로 생각해도 무방
* 확률질량함수(probability mass fuinction, PMF) as 확률함수
  * 예를 들어 pmf = [1/21, 2/21, 3/21, 4/21, 5/21, 6/21]이라 할 때, pmf[x]를 확률질량함수라고 한다.
* 확률분포(probability distribution)
  * 확률변수가 취할 수 있는 값과 그 확률의 구체적인 대응
  * 확률변수의 확률분포가 결정되는 그 확률변수의 움직임이 정해진다.
  * 확률변수가 취할 수 있는 값의 집합과 확률변수의 세트.
  * X = [x_set, f]
* 확률의 성질
  * f(x) >= 0
  * sum([f(x) for x in x_set]) == 1
* 누적분포함수(cumulative distribution function, CDF) as 분포함수
  * F(x) == sum([f(k) for k in x_set if k <= x])
* 확률변수의 변환
  *  확률변수 X에 2를 곱하고 3을 더한 2X + 3도 확률변수이다.
#### **지표**
* 기댓값(expected value)
  * 확률변수의 평균
  * 확률변수가 취할 수 있는 값과 그 확률의 곱의 총합으로 정의
  * μ : 기대값의 값 자체를 나타낼 때.
  * E(X) : 기댓값의 연산이라는 의미가 강할 때
  * E(X) == sum([f(x)*x for x in x_set])
  * E(g(X)) == sum(f(g(x))*g(x) for x in x_set)
* 기댓값의 선형성
  * E(aX + b) = aE(X) + b
* 분산
  * σ**2 or V(X)로 표기
  * V(X) == sum((x-mean)<sup>2</sup> * f(x) for x in x_set)
  * 여기서 mean은 기댓값 E(X)이다.
  * V(g(x)) == sum((g(x) - E(x))<sup>2</sup> * f(g(x)) for x in x_set)
* 분산 공식
  * V(aX + b) = a<sup>2</sup>V(X)

<br/>

### 2차원 이산형 확률변수
#### **정의**
* 결합확률분포(joint probability distribution) as 결합분포
  * 주사위 두 개를 던졌을 때 한 눈은 X, 한 눈을 Y라고 하자. 이 때 확률변수 (X, Y)의 움직임을 동시에 고려한 분포를 결합확률분포 or 결합분포라 한다.
* 결합확률함수(joint probability function)
  * f<sub>XY</sub>(x, y)
* 확률의 성질
  * f<sub>XY</sub>(x, y) >= 0
  * sum(f(x, y) for x in x_set for y in y_set) == 1

---
await next_study(132)