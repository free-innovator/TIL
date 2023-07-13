# 2023-07-11

## ML
* `iris.target`
* `iris.data`
* `iris.feature_names`
* `iris.target_names`
* `from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score`
* `from sklearn.metrics import ConfusionMatrixDisplay, confusion_matrix, precision_score, recall_score, f1_score, accuracy_score, classification_report, precision_recall_curve, roc_curve, roc_auc_score`
* metrics (평가지표)
    * MAE
    * MSE
    * RMSE
    * R Squared
    * Confusion matrix
        * TP
            * 정확하게(T) Positive(P)로 예측
        * FP
            * 잘못해서(F) Positive(P)로 예측
        * TN
            * 정확하게(T) Negative(N)로 예측
        * FN
            * 잘못해서(F) Negative(N)로 예측
        * accuracy(정확도) as score
            * 정확히 예측한 비율
            * 데이터 수가 균형있게 있을 때 더 좋은 평가지표이다.
        * f1_score
            * Precision과 Recall의 조화평균
            * 데이터 수가 불균형한 데이터에서 score보다 더 좋은 평가지표로 사용할 수 있다.
        * Precision(정밀도)
            * 제대로 예측한 비율
            * 크면 대체로 제 1종 오류를 줄일 수 있다.
        * Recall(재현율)
            * 표본을 찾아낸(재현한) 비율
            * 크면 대체로 제 2종 오류를 줄일 수 있다.
        * TPR
            * 실제 Positive 샘플 중에서 정확하게(T) Positive(P)로 예측한 비율(R)
        * FPR
            * 실제 Negative 샘플 중에서 잘못하여(F) Positive(P)로 예측한 비율(R)
