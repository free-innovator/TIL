# 2023-06-07

## git, github 특강

<br/>

### MarkDown

마크다운에 대해 공부하였습니다.

하나의 사이트를 마크다운으로 옮겼는데, 해당 내용은 아래 markdown.md 파일에서 확인할 수 있습니다.

<br/>

### git 명령어

* git init
  * cwd에 .git 폴더를 생성하며 initalize.
* git status
  * git의 상태 출력.
* git add .
  * cwd와 그 하위 디렉토리 안의 변경 내용 전부 스테이징.
* git commit -m "message"
  * message 주석을 달고 commit 생성.
* git log
  * commit history 보기.
* git push
  * 연결된 외부 저장소에 git 내용 올리기.
* git pull
  * 연결된 외부 저장소에서 git 내용 내려받기. (fetch and merge)
* git remote -v
  * 원격 저장소 정보 보기.
* git remote add origin [url]
  * origin이라는 이름의 remote 저장소 추가.
* git push origin main
  * origin이라는 이름의 remote 저장소의 main 브런치에 push.
* git config --global init.defaultBranch main
  * 기본 브런치 이름을 main으로 변경
* git config --global user.name "`<username>`"
  * 글로벌 유저 이름 설정
* git config --global user.email "`<email>`"
  * 글로벌 유저 이메일 설정
* git branch --set-upstream-to=origin/`<branch>` main
  * 원격 저장소와 브런치 이름이 일치하지 않은 경우

<br/>

---

<br/>

## 파이썬 통계분석
### 모집단과 표본
* 모집단(population)
  * 추측하고 싶은 관측 대상 전체
* 표본(sample)
  * 추측에 사용하는 관측 대상의 일부분
* 표본추출(sampling)
  * 모집단에서 표본을 골라내는 일
* 표본 크기 or 샘플 사이즈
  * 골라낸 표본의 수
* 표본 통계량
  * 표본을 바탕으로 계산한 평균이나 분산, 상관계수 등
* 모수
  * 모집단의 평균이나 분산, 상관계수 등
* 추정량(estimator)
  * 표본평균으로 모평균을 추측할 때, 표본평균은 모평균의 추정량이라고 한다.
* 추정값(estimate)
  * 실제로 표본의 데이터를 이용하여 계산한 결과
* 무작위추출(random sampling)
  * 임의로 표본을 추출하는 방법
* 복원추출(sampling with replacement)
  * 여러 차례 동일한 표본을 선택하는 추출 방법
  * ```np.random.choice([1, 2, 3], 3)```
* 비복원추출(sampling without replacement)
  * 동일한 표본은 한 번만 선택하는 방법
  * ```np.random.choice([1, 2, 3], 3, replace=False)```


```python
# numpy random 시드 설정
np.random.seed(num)
```

<br/>

### 확률 모형
* 확률 모형(probability model)
  * 확률을 사용한 무작위추출 혹은 주사위를 모델링한 것
* 확률변수(random variable)
  * 취하는 값과 그 값이 나올 확률이 결정되어 있는 것
* 시행(trial)
  * 확률변수의 결과를 관측하는 것
* 실현값(realization)
  * 시행에 의해 관측되는 값
* 사건(event)
  * 눈이 1 or 홀수처럼 시행 결과로 나타날 수 있는 일
* 근원사건(elementary event)
  * '눈이 1'처럼 더 이상 세부적으로 분해할 수 없는 사건
* 상호배반(mutually exclusive)
  * 각 사건이 동시에 일어날 수 없을 때.
  * 확률을 더할 수 있다.
* 확률분포(probability distribution)
  * 확률변수가 어떻게 움직이는가

```python
# np.random.choice(:iterable, :int, p:iterable)
# 1이 나올 확률 33%, 2가 나올 확률 66% 3이 나올 확률 0%로 100회 시행.
np.random.choice([1, 2, 3], 100, p=[1/3, 2/3, 0])
```
* 히스토그램(histogram)
  * 표로 되어 있는 도수 분포를 정보 그림으로 나타낸 것이다.
  * [numpy.histogram](https://numpy.org/doc/stable/reference/generated/numpy.histogram.html)
```python
# Compute the histogram of a dataset.
# bins는 계급수(구간의 수)
hist, bin_edges = numpy.histogram(a, bins=10, range=None, density=None, weights=None)
```

* csv 파일 읽기
  * [pandas.read_csv](https://pandas.pydata.org/docs/reference/api/pandas.read_csv.html)
* ndarray로 형변환
  * [The N-dimensional array](https://numpy.org/doc/stable/reference/arrays.ndarray.html)
```python
# csv 형태로 저장된 파일을 읽는 함수
# pandas.read_csv(...)
# return: pandas.core.frame.DataFrame
#
# 사용하기 위해 형변환 필요. 
# ex: np.array(df['col_name'])
#
# df -> pandas.core.frame.DataFrame
# df['col_name'] -> pandas.core.series.Series
# np.array(...) -> numpy.ndarray
df = pandas.read_csv(path)
arr = numpy.array(df['col_name'])
```
* 산포도
  *  변량이 흩어져 있는 정도를 하나의 수로 나타낸 값이다.
* 분산
  * 어떤 대상의 흩어진 정도나 상태를 의미.
* 추정(estimation)
  * 모수를 추측하는 것
  * 점추정은 하나의 값으로 추정하는 것
  * 구간추정은 구간으로 추정하는 것
* 검정(test)
  * 모집단의 통계적 성질에 대해 가설을 세우고, 그 가설이 옳은지 여부를 판단하는 기법

