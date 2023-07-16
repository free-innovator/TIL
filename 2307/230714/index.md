# 2023-07-14

## ML
* 앙상블 학습 (Ensembel Learning)
    * 여러 개의 분류기(Classifier)를 생성하고 그 예측을 결합함으로써 보다 정확한 최종 예측을 도출하는 기법
* 학습 유형
    * Voting
        * 서로 다른 분류 알고리즘을 가진 분류기를 결합
        * Hard Voting
            * 다수결
        * Soft Voting
            * class 확률 평균으로
    * Bagging
        * 같은 유형의 알고리즘 기반이지만 데이퍼 샘플링을 다르게 한다.
        * Bootstrapping(부트스트래핑) 분할방식
            * 여러 개의 데이터 세트를 중첩되게 분리하는 것
            * 통계학에서 여러 개의 작은 데이터 세트를 임의로 만들어 개별 평균의 분포도를 측정하는 등의 목적을 위한 샘플링 방식
        * 랜덤 포레스트 알고리즘
            * 기반 알고리즘은 결정트리이다.
    * Boosting
        * 예측이 틀린 데이터에 대해서 올바르게 예측할 수 있도록 다음 분류기에게는 가중치를 부스팅하는 방식
        * 그래디언트 부스트, XGBoost(eXtreme Gradient Boost), AdaBoost(Adaptive boosting)
        * XGBoost(eXtreme Gradient Boost)
            * GBM의 단점을 보완한 알고리즘(수행 시간 향상, 과적합 규제 추가 등)
        * LightGBM(Light Gradient Boost)
            * XGBoost에 비해 가볍고 대체로 성능이 좋으나, 적은 데이터 세트(1만 건 이하)에 적용하면 과적합이 발생하기 쉽다.
            * 리프 중심 트리 분할 방식이다. (최대 손실값을 가지는 리프 노드를 지속적으로 분할)
            * 카테고리형 feature 자동 변환과 최적 분할
* 베이지안 최적화
    * 목적 함수 식을 제대로 알 수 없는 블랙 박스 형태의 함수에서 최대 또는 최소 함수 반환 값을 만드는 최적 입력값을 가능한 적은 시도를 통해 빠르고 효과적으로 찾아주는 방식
    * 대체 모델 (Surrogate Model)
    * 획득 함수 (Acquisition Function)
    * 가우시안 프로세스(Gaussian Process)
    * 트리 파르젠 Estimator(TPE, Tree-structure Parzen Estimator)
    * HyperOpt, Bayesian Optimization, Optuna