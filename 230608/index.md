# 2023-06-08

## git, github 특강

### 복습문제
1. git commit -m "`<message>`"
2. 변경 사항이 없음
3. 분산 버전 관리 시스템(DVCS)
4. DVCS를 사용할 때 이용하는 원격 저장소 중 하나

### 공부
github에서 자신의 username과 같은 이름의 저장소는 special 저장소 중 하나이며,<br/>이 저장소의 README.md의 내용은 프로필 페이지 상단에 게시됩니다.

* git config --global core.editor "code --wait"
  * vim 대신 code 에디터로 편집 가능하게 설정
* git log --oneline
  * 로그 당 한 줄로 출력
* git log --oneline --graph
  * 로그 당 한 줄로 출력하고 그래프로 표현
* git branch `<branch name>`
  * 새로운 브런치 분기
* git checkout `<branch name>`
  * 다른 브런치로 ckeckout
* git switch `<branch name>`
  * git 2.23 버전부터 추가된 브런치 변경 명령어
* git restore `<path>`
  * git 2.23 버전부터 추가된 복구 명령어

<br/>

* main(master)
  * 제품으로 출시될 수 있는 브랜치
* develop
  * 다음 출시 버전을 개발하는 브랜치
* feature
  * 기능을 개발하는 브랜치
* release
  * 이번 출시 버전을 준비하는 브랜치
* hotfix
  * 출시 버전에서 발생한 버그를 수정하는 브랜치

<br/>

---

<br/>

## 이산형 확률변수

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
  * σ<sup>2</sup> or V(X)로 표기
  * V(X) == sum((x-mean)<sup>2</sup> * f(x) for x in x_set)
  * 여기서 mean은 기댓값 E(X)이다.
  * V(g(x)) == sum((g(x) - E(x))<sup>2</sup> * f(g(x)) for x in x_set)
* 분산 공식
  * V(aX + b) = a<sup>2</sup>V(X)

<br/>

### 2차원 이산형 확률변수

#### **정의**
* 결합확률분포(joint probability distribution) as 결합분포
  * 주사위 두 개를 던졌을 때 한 눈은 X, 한 눈을 Y라고 하자. <br/>이 때 확률변수 (X, Y)의 움직임을 동시에 고려한 분포를 결합확률분포 or 결합분포라 한다.
* 결합확률함수(joint probability function)
  * f<sub>XY</sub>(x, y)
* 확률의 성질
  * f<sub>XY</sub>(x, y) >= 0
  * sum(f(x, y) for x in x_set for y in y_set) == 1
```python
# 1000*800 사이즈의 figure
fig = plt.figure(figsize=(10, 8))
# 1행x1열의 1번째 자리에 추가
ax = fig.add_subplot(111)
# minor=True이면 라벨이 없는 작은 눈금 표시.
ax.set_xticks(<arguments>, minor=True)
```
```python
# 모든 값이 참인 경우 True
numpy.all(<ndarray>)
```
* 주변확률분포(marginal probability distribution) as 주변분포
  * 결합확률함수에서 확률변수 Y의 영향을 제거하면 확률변수 X의 확률함수만 남는다고 생각할 수 있는데, <br/>이와 같이 얻은 함수를 X의 주변확률분포라고 한다.
  * sum(f(x, y) for y in y_set)

#### **지표**
* 기댓값
  * sum([x * f(x, y) for x in x_set for y in y_set])
* 기댓값의 선형성
  * E(aX + bY) = aE(X) + bE(Y)
* 분산 as V(X), V(Y)
  * sum([(x - mean)<sup>2</sup> * f(x, y) for x in x_set for y in y_set])
* 공분산 as Cov(X, Y)
  * sum([(x - x_mean)*(y - y_mean)*f(x,y) for x in x_set for y in y_set])
* 분산과 공분산 공식
  * V(aX + bY) = a<sup>2</sup>V(X) + b<sup>2</sup>V(Y) + 2abCov(X, Y)
* 상관계수
  * 공분산을 각각의 표준편차로 나누어 구한다.

<br/>

## 대표적인 이산형 확률분포
* 비모수적 기법
  * 모집단의 확률분포에 어떠한 가정도 하지 않고 추정하는 기법
* 모수적 기법
  * 모집단의 성질을 어느정도 가정하고 추측하는 기법
  * 모형으로서의 표현력은 부족하지만, 추정이 간단하고 분석이 쉬운 모형을 만들 수 있다.
### 베르누이 분포
---
await next_study(145)
 
