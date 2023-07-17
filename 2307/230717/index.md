# 2023-07-17

## ML
* 군집화
    * `from sklearn.metrics import silhouette_samples`
        * `silhouette_samples(iris.data, iris_df["predict"])`
    * `from sklearn.manifold import TSNE`
        * `x_tsne = TSNE(random_state=1).fit_transform(digits.data)`
    * `from sklearn.cluster import KMeans`
        * `model = KMeans(n_clusters=3, n_init="auto", random_state=1)`
        * `inertia_list.append(model.inertia_)`
    * `from sklearn.cluster import AgglomerativeClustering`
        * `predict = AgglomerativeClustering(n_clusters=3).fit_predict(x)`
    * `from scipy.cluster.hierarchy import dendrogram, ward`
        * `linkage_array = ward(x)`
        * `dendrogram(linkage_array)`
        * `ax = plt.gca()`
        * `bounds = ax.get_xbound()`
    * `from sklearn.cluster import MeanShift`
        * `model = MeanShift()`
    * `from sklearn.cluster import DBSCAN`
        * `model = DBSCAN()`
    * `from sklearn.metrics import accuracy_score, normalized_mutual_info_score, adjusted_rand_score, silhouette_score`
        * `silhouette_score(iris.data, model.labels_)`
        * `silhouette_score(moons[["x01", "x02"]], moons[[predict]])`
        * `adjusted_rand_score(moons["target"], moons[predict])`
        * `normalized_mutual_info_score(moons["target"], moons[predict])`
* 데이터 전처리(인코더)
    * `from sklearn.preprocessing import LabelEncoder`
        * `LabelEncoder().fit_transform(tips["time"])`
    * `from sklearn.preprocessing import OneHotEncoder`
        * `OneHotEncoder().fit_transform(tips[["day"]])`
* 데이터 생성
    * `from sklearn.datasets import make_blobs`
        * `make_blobs(random_state=0, n_samples=10)`
    * `from sklearn.datasets import make_moons`
        * `x, y = make_moons(n_samples=300, noise=0.05, random_state=1)`
* NN(Neural Network)
    * `from sklearn.neural_network import MLPClassifier`
        * `model = MLPClassifier(hidden_layer_sizes=(4, 80, 80, 40))`
* 파이프라인
    * `from sklearn.pipeline import Pipeline`
        * `pipe01 = Pipeline([("scaler", MinMaxScaler()), ("svc", SVC())])`
        * `pipe02 = make_pipeline(MinMaxScaler(), SVC())`
* 모델 save/load
    * `import joblib`
        * `joblib.dump(model, "iris_random_forest.pkl")`
        * `model = joblib.load("iris_random_forest.pkl")`
* 분류
    * Oversampling(오버샘플링)
        * 적은 레이블을 가진 데이터 세트를 많은 레이블을 가진 데이터 세트 수준으로 증식
    * Undersampling(언더샘플링)
        * 많은 레이블을 가진 데이터 세트를 적은 레이블을 가진 데이터 세트 수준으로 감소
    * SMOTE(Synthetic Minority Over-sampling Technique)
        * `%conda install -c conda-forge imbalanced-learn`
    * 주의사항
        * LightGBM에서 레이블 값이 극도로 불균형한 분포를 이루는 경우 예측 성능을 위해 boost_from_average=False로 설정하여야한다.