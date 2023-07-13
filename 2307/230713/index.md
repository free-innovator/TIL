# 2023-07-13

## ML

* `from sklearn.naive_bayes import GaussianNB`
    * `GaussianNB()`
* `from sklearn.neighbors import KNeighborsClassifier, KNeighborsRegressor`
    * `KNeighborsClassifier(n_neighbors=16)`
    * 가장 인접한 요소들을 찾아서 수가 제일 많은 레이블을 선택한다.
* `from sklearn.tree import DecisionTreeClassifier, DecisionTreeRegressor`
    * `model = DecisionTreeClassifier(max_depth=4)`
    * `model.feature_importances_`
    * 구분을 쉽게 할 수 있는 조건을 우선 비교하여 결정한다.
* `from sklearn.tree import plot_tree`
    * `plot_tree(model, class_names=["mal", "ben"], feature_names=list(cancer.feature_names), impurity=False, filled=True, fontsize=10)`