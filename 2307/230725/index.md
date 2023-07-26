# 2023-07-25

# RNN
* `from sklearn.decomposition import LatentDirichletAllocation`
    * `lda = LatentDirichletAllocation(n_components=10, learning_method="batch", max_iter=25, random_state=0, n_jobs=-1)`
    * `topics = lda.fit_transform(x)`
* `from keras.utils import pad_sequences`
    * `x_train_pad = pad_sequences(x_train, maxlen=500)`
* `from keras.layers import Embedding, SimpleRNN, Dense`
    * `model.add(Embedding(10000, 10))`
    * `model.add(SimpleRNN(10, return_sequences=True))`
* `from keras.callbacks import EarlyStopping`
    * `early_stopping = EarlyStopping(patience=3)`
    * `result = model.fit(x_train_pad, y_train, batch_size=100, epochs=100, callbacks=[early_stopping], validation_split=0.2)`
* `from keras.layers import LSTM`
    * `model.add(LSTM(10, dropout=0.3, return_sequences=True))`
* `from keras.layers import GRU`
    * `model.add(GRU(10, dropout=0.3, return_sequences=True))`

# Tensor1
* `node01 = tf.constant(10, dtype=tf.float32)`
* `sess = tf.Session()`
* `sess.run(node)`
* `sess.run([node01, node03])`
* `node04 = tf.placeholder(dtype=tf.float32)`
* `sess.run(node06, feed_dict={node04: [1, 2, 3], node05: [4, 5, 6]})`
* flow
    * `w = tf.Variable(tf.random_normal([1]), name="weight")`
    * `b = tf.Variable(tf.random_normal([1]), name="bias")`
    * `loss = tf.reduce_mean(tf.square(h - y))`
    * `optimizer = tf.train.GradientDescentOptimizer(learning_rate)`
    * `train = optimizer.minimize(loss)`
    * `sess = tf.Session()`
    * `sess.run(tf.global_variables_initializer())`
    * `_, loss_val, w_val, b_val = sess.run([train, loss, w, b], feed_dict={x: [1, 2, 3, 4], y: [3, 5, 7, 9]})`
    * `sess.run(h, feed_dict={x:[10, 11, 12, 13]})`
* loss
    * `loss = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits_v2(logits=logits, labels=y_node))`
    * `loss = tf.reduce_mean(tf.nn.sigmoid_cross_entropy_with_logits(logits=logits, labels=y_node))`
* `x_node = tf.placeholder(shape=[None, 4], dtype=tf.float32)`
* `w = tf.Variable(tf.random_normal([4, 3]), name="weight")`
* `logits = tf.matmul(x_node, w) + b`
* `h = tf.nn.softmax(logits)`

<br/>

# PyTorch

* base
    * `x = torch.tensor([[1, 2], [3, 4]])`
    * `y = torch.tensor(np.array([[5, 6], [7, 8]]))`
    * `x2 = torch.from_numpy(np.array(x))`
    * `x[0][0]`
    * `x.size()`
    * `x_reshape02 = x.view(-1)`
    * `one = torch.ones(1)`
* cnn
    * `train = CIFAR10(root="data", train=True, download=True, transform=ToTensor())`
    * `trainset = DataLoader(train, batch_size=batch_size, shuffle=True)`
    * `class CNN(Module):`
        * `def __init__(self):`
        * `def forward(self, x):`
    * `loss_function = CrossEntropyLoss()`
    * `optimizer = Adam(model.parameters(), lr=learning_rate)`
    * training
        * `optimizer.zero_grad()`
        * `h = model(x_train)`
        * `loss = loss_function(h, y_train)`
        * `loss.backward()`
        * `optimizer.step()`
    * `test_iter = iter(testset)`
    * `x_test, y_test = next(test_iter)`
    * `predict = model(x_test)`
    * `plt.imshow(img.T)`