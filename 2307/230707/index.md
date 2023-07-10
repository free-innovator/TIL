# 2023-07-07

## ML
* LinearRegression
    * `model = LinearRegression()`
* `x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random_state=1)`
* `model.fit(x_train, y_train)`
* `predict = model.predict(x_test)`
* `boston.isnull().sum()`
* `boston.isna().sum()`
* `corr = boston.corr()`
* `sns.heatmap(corr.values, annot=True, fmt=".2f", xticklabels=boston.columns, yticklabels=boston.columns)`
* `mean_squared_error(y_test, predict)`
* `model.score(x_test, y_test)`
