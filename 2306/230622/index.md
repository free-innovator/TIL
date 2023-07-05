# 2023-06-22

## 회귀분석 (regression analysis)
인과관계가 의심되는 복수의 변수를 사용하여 어느 변수로부터 다른 변수의 값을 예측하는 기법

* 설명변수(explanatory variable) as 독립변수(independent variable)
    * 원인이 되는 변수
* 반응변수(response variable) as 종속변수(dependent variable)
    * 결과가 되는 변수

### 단순회귀모형 
* 단순회귀모형(simple regression model)
    * 설명변수와 반응변수가 1개인 모델
    * 회귀직선을 그리는 것이 목표 중 하나이다.
* 오차항
    * 예측할 수 없는 부분
* 설명변수가 확률변수는 아니다.
* 오차항은 서로 독립이고 $N(0, α^2)$을 따른다.
* 회귀직선(regression line)
* 회귀계수(regression coefficient)
* ols(Ordinary Least Squares) as 최소제곱법
    * `statmodels.formula.api.ols(<formula>, <dataframe>).fit().summary()`
    * `<formula> := '<반응변수> ~ <설명변수>'`
    * 잔차제곱합을 최소화하는 회귀계수를 구하는 방법
    * `numpy.linalg.lstsq(<설명변수>, <반응변수>)[0]`
* 예측값(predicted value)
* 잔차(residual)
* 잔차제곱합(residual sum of squares, RSS)

### 중회귀모형
* 중회귀모형(multiple regression model)
    * 설명변수가 2개 이상인 모형
    * `<formula> := '<반응변수> ~ <설명변수> + <설명변수>'`

<br/>

## django

* ORM (Object Relation Mapping)
* **javascript 영역에서 생략이 가능한 변수는 window가 아닌 self이다.**