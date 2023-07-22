# 2023-07-19

## ML
* 회귀
    * 다항 회귀는 선형 회귀이다.
    * 선형/비선형을 나누는 기준은 회귀 계수(w)를 따른다.
* 데이터 클렌징(Data Cleansing)

## DL
* `from tensorflow.keras.layers import Flatten, Dense, Dropout`
* `from tensorflow.keras.utils import to_categorical`
* `from tensorflow.keras.callbacks import EarlyStopping`
* `from tensorflow.keras.optimizers import SGD, Adagrad, RMSprop, Adam`
* `from tensorflow.keras.callbacks import ModelCheckpoint`
    * `ModelCheckpoint(filepath=save_dir + "/" + save_time + "_{epoch}_{val_loss:.4f}.h5", moniter="val_loss", save_best_only=True, save_weights_only=True)`
    * `model.build(input_shape=x_train_scale.shape)`
    * `model.load_weights(path)`
    * `model.save("dl12.h5")`
    * `model.save("dl12.keras")`
    * `model01 = load_model("dl12.h5")`
    * `model02 = load_model("dl12.keras")`
* `result.history`