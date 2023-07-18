# 2023-07-18

## ML
* SMOTE
    * 정밀도가 낮아지고, 재현율이 높아진다.
* Stacking
    * 각 모델들의 Predict 값을 쌓아서(Stacking) 모델로 학습하는 방법.

## DL

* Perceptron
    * 선형 결합을 activation function에 통과시켜 아웃풋을 내는 데 사용하는 인경 신경망 모델
    * 편향 값으로 모델의 유연성을 높여준다.
    * 단측은 선형 분리 가능 문제만 해결할 수 있지만, MLP는 비선형 문제도 해결할 수 있다.
* Activation function
    * Softmax
        * 총합이 1이고 치역이 [0, 1)인 함수
        * 확률을 얻을 때 사용한다.
    * linear
        * 그대로 출력
        * 치역이 실수 전체인 연속형일 때 사용한다.
* `from tensorflow.keras import Sequential`
    * `model.fit(x, y, epochs=1000)`
    * `model.get_weights()`
* `from tensorflow.keras.layers import Dense`
    * `model.add(Dense(32, activation="relu", input_shape=(x.columns.size, )))`
* `from tensorflow.keras.optimizers import SGD`
* `from tensorflow.keras.losses import mse`
    * `model.compile(optimizer=SGD(), loss=mse, metrics=["acc"])`