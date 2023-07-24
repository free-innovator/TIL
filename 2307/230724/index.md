# 2023-07-24

## CNN
* `from keras.applications.vgg16 import VGG16`
    * `for layer in vgg16.layers[:-4]: layer.trainable = False`
    * `model.add(vgg16)`
* `from keras.layers import BatchNormalization, Activation`
    * `model.add(BatchNormalization())`
    * `model.add(Activation("relu"))`
* `from keras.preprocessing.image import ImageDataGenerator`

<br/>

## NLP
* preprocessing
    * `" ".join(shakespeare)`
    * `token_str.lower()`
    * `token_str.replace("\n", "")`
    * `re.sub("[^a-z]", " ", token_str)`
    * `tokens.split(" ")`
    * `list(filter(None, tokens))`
    * `token_df = pd.DataFrame.from_dict(dict(tokens_cnt), orient="index", columns=["freq"])`
    * `token_df.sort_values(by="freq", ascending=False, inplace=True)`
    * `ax = token_df.head(20).plot(kind="barh")`
* `from sklearn.feature_extraction.text import CountVectorizer`
    * `cv = CountVectorizer(stop_words="english")`
    * `dict(zip(cv.get_feature_names_out(), cnt.toarray().sum(axis=0)))`
    * `cv.fit(corpus)`
    * `bow = cv.transform(corpus)`
    * `cv.vocabulary_`
    * `cv = CountVectorizer(ngram_range=(2, 2))`
* `from keras.preprocessing.text import text_to_word_sequence`
    * `text_to_word_sequence(" ".join(shakespeare))`
* `from nltk.tokenize import word_tokenize`
    * `word_tokenize(txt)`
* `from nltk.corpus import stopwords`
    * `list(stopwords.words("english"))`
* `from nltk.tag import pos_tag`
    * `token_df["pos"] = list(map(lambda x: x[1], pos_tag(token_df["token"])))`
* `from nltk.stem import WordNetLemmatizer`
    * `lemmatizer = WordNetLemmatizer()`
    * `token_df["lemma"] = list(map(lambda x: lemmatizer.lemmatize(x), token_df["token"]))`
* `from nltk.stem.porter import PorterStemmer`
    * `stemmer = PorterStemmer()`
    * `token_df["stem"] = list(map(lambda x: stemmer.stem(x), token_df["token"])`
* `from sklearn.metrics.pairwise import cosine_similarity`
    * `cosine_similarity(bow[0], bow[1])`
* `from sklearn.feature_extraction.text import TfidfVectorizer`
    * `tfv = TfidfVectorizer(stop_words=stopwords.words("english"))`
    * `tf_idf = tfv.transform(corpus)`
    * `tf_idf.toarray()`

|   |POS	|English |Korean    |
|---|-------|--------|----------|
|0	|FW     |Foreign word	|외래어|
|1	|IN     |Preposition or subordinating conjunction	|전치사 종속접속사|
|2	|JJ     |Adjective	|형용사|
|3	|JJR    |Adjective : comparative	|형용사 : 비교급|
|4	|JJS    |Adjective : superlative	|형용사 : 최상급|
|5	|NN     |Noun : singular or mass	|명사 : 단수형|
|6	|NNS    |Noun : plural	|명사 : 복수형|
|7	|NP     |Proper noun : singular	|고유명사 : 단수형|
|8	|NPS    |Proper noun : plural	|고유명사 : 복수형|
|9	|PP     |Personal pronoun	|인칭 대명사|
|10	|PP$    |Possessive pronoun	|소유 대명사|
|11	|RB     |Adverb	|부사|
|12	|RBR    |Adverb : comparative	|부사 : 비교급|
|13	|RBS    |Adverb : superlative	|부사 : 최상급|
|14	|VB     |Verb : base form	|동사 : 원형|
|15	|VBD    |Verb : past tense	|동사 : 과거형|
|16	|VBG    |Verb : gerund or present participle	|동사 : 현재분사|
|17	|VBN    |Verb : past participle	|동사 : 과거분사|
|18	|VBZ    |Verb : 3rd person singular present	|동사 : 3인칭 현재 단수|
