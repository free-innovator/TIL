# 2023-06-30

## SQL

* Query
    * `PARTITION BY`
        * 테이블을 파티션으로 나눠 출력
    * `OVER`
        * 단일, 집계함수 혼용
    * `CREATE TEMPORARY TABLE`
        * 현재 세션에서만 유지되는 테이블 생성
    * `FLOOR`
        * 바닥 함수
    * `CASE WHEN THEN WHEN THEN...`
        * if elif elif 처럼 동작
    * `VARIANCE`
        * 분산
* 용어
    * NLP(Natural Language Processing)
        * 자연어처리
    * TF-IDF
        * 단어별로 가치 수준을 매김
    * BU
        * 구매자 수
    * aisle
        * 선반, 매대
    * UPT
        * Unit Per Transaction (주문 건 당 평균 구매 상품 수)
    * 10분위 분석
        * 전체를 10분위로 나누어 각 분위 수에 해당하는 집단의 성질을 나타내는 방법.
    * KPI
        * Key Performance Indicator
* 메모
    * 파이션으로 나눈 값을 조건으로 매기려면 서브쿼리로 돌려야한다.
    * HAVING과 WHERE의 차이
        * WHERE은 FROM 테이블에 조건을 건다.
        * HAVING은 그룹핑한 데이터에 조건을 건다.
