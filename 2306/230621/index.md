# 2023-06-21

## 통계적 가설검정

### 2표본 문제에 관한 가설검정

#### 대응비교 t 검정
* 정규분포 and 대응표본
* `stats.ttest_1samp(...)`
* `stats.ttest_rel(...)`

#### 독립비교 t 검정
* 정규분포 and 독립표본
* 웰치의 방법을 사용
* `stats.ttest_ind(..., equal_val=False)`

#### 윌콕슨의 부호순위검정 (Wilcoxon signed-rank test)
* 비정규분포 and 대응표본
* `중앙값의 차이`에 대한 검정
* `stats.wilcoxon(...)`

#### 만 위트니의 U검정 (Mann-Whitney rank test)
* 비정규분포 and 독립표본
* 윌콕슨의 순위합검정이라고도 한다.
* 양측 검정을 수행한다.
* `stats.mannwhitneyu(..., alternative='two-sided')`

#### 카이제곱검정
* 독립성 검정 (test for independence)
    * 'X와 Y가 독립이다.' 라는 귀무가설과 'X와 Y가 독립이 아니다.' 라는 대립가설에 의해 수행되는 검정
    * 카이제곱분포가 사용되기에 카이제곱검정(chi-square test)이라고도 부른다.
    * 검정통계량 Y는 자유도가 1인 카이제곱분포를 근사적으로 따른다고 알려져 있다.
* 기대도수(expected frequency)
    * 기대하는 값
* 관측도수(observed frequency)
    * 실제로 관측된 데이터
* `chi2, p, dof, ef = stats.chi2_contingency(..., correction=False)`


<br/>
<br/>

## DB

* 용어
    * 트랜젝션
        * 최소한의 작업 단위
* SQL
    * DCL(Data Control Langauge)
        * 데이터 제어 언어
        * COMMIT
        * ROLLBACK
        * GRANT
        * REVOKE
    * TLC(Transaction Control Language)
        * COMMIT
        * ROLLBACK
    * CARTESIAN PRODUCT
        * 데카르트 곱

<br/>
<br/>

## django

* WAS (Web Application Server)
    * 동적
* Web Server
    * static file
* wsgi
    * web server gateway interface
* asgi
    * asynchronous server gateway interface
    * was의 동기/비동기 지원
* project
    * 전체영역
* app
    *  app.domain.xxx
* MVT
    * Model, View, Template
    * Model
        * ORM
    * View
        * Business Logic
    * Template
        * presentation
* SSR
    * Server side rendering

