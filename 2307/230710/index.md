# 2023-07-10

## ML
* `from sklearn.preprocessing import PolynomialFeatures`
    * `poly = PolynomialFeatures(degree=10)`
    * `poly.fit(x)`
    * `x_poly = poly.transform(x)`
    * `x_poly = poly.fit_transform(x)`
    * `poly.get_feature_names_out()`
* `from sklearn.linear_model import Ridge`
    * 선형회귀의 비용함수에 가중치의 제곱합을 최소화 하는 제약 조건 추가 (L2 규제)
    * `model = Ridge(alpha=0.5)`
* `from sklearn.linear_model import Lasso`
    * 선형회귀의 비용함수에 가중치들의 절대값의 합을 최소화하는 제약조건 추가 (L1 규제)
    * `model = Lasso(alpha=1)`
* `from sklearn.linear_model import ElasticNet`
    * Ridge + Lasso
    * `model = ElasticNet(alpha=1, l1_ratio=0.5)`
* `model.coef_`
* `model.intercept_`
