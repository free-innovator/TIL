# 2023-07-21

## CNN
* `from tensorflow.keras.layers import Conv2D, MaxPool2D, Flatten, Dense`
    * `model.add(Conv2D(32, input_shape=(28, 28, 1), kernel_size=(5, 5), activation="relu"))`
    * `model.add(Conv2D(32, kernel_size=(5, 5), padding="same", input_shape=(100, 100, 3), activation="relu"))`
    * `model.add(MaxPool2D(pool_size=(2, 2)))`
    * `model.add(Dense(10, activation="softmax"))`
    * `model.compile(optimizer="adam", loss="sparse_categorical_crossentropy", metrics=["acc"])`
    * `model.add(Dense(1, activation="sigmoid"))`
    * `model.compile(optimizer="adam", loss="binary_crossentropy", metrics=["acc"])`
    * `predict_labels = np.argmax(predict, axis=1)`
* `import tensorflow_datasets as tfds`
    * `ds, info = tfds.load("cats_vs_dogs", split="train", with_info=True)`
    * `for idx, data in enumerate(tfds.as_numpy(ds)):`
* `from tensorflow.keras.layers import MaxPooling2D, Rescaling, RandomFlip, RandomRotation, RandomZoom`