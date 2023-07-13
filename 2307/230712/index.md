# 2023-07-12

## ML

* `from sklearn.preprocessing import MinMaxScaler, StandardScaler`
    * MinMaxScaler
        * 정규화
    * StandardScaler
        * 표준화
* `from sklearn.svm import LinearSVC, SVC`
    * `SVC(kernel="rbf", random_state=0, C=3, gamma=10)`
* `from sklearn.model_selection import cross_val_score, cross_validate`
    * `cross_val_score(model, x, y, cv=10)`
    * `cross_validate(model, x, y, return_train_score=True)`
* `from sklearn.model_selection import KFold, StratifiedKFold`
    * `KFold(n_splits=3)`
    * `StratifiedKFold(n_splits=3)`
* `from sklearn.model_selection import GridSearchCV`
    * `GridSearchCV(model, {"kernel": kernel_list, "C": C_list})`