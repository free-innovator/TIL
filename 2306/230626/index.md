# 2023-06-26

## SQL
* 정합성을 확보해야한다.
* 결측치
    * 수집하지 못한 데이터
* Query
    * IS NULL
    * BETWEEN
    * NOT IN
    * IN
    * LIKE
    * CASE WHEN WHEN END
    * SELECT
    * INSERT INTO
    * DELETE
    * GROUP BY
    * ORDER BY
    * WHERE
    * FROM
    * UPDATE SET
    * CREATE PROCEDURE BEGIN END;
    * DELIMITER `<구분자>`, DELIMITER ;
    * CREATE VIEW DB.view_name AS
        * 액세스 제한을 위해 주로 사용됨
        * 실제 테이블에 링크된 상태
        * 조회만 가능
    * MECE(Mutually Exclusive Collectively Exhaustive)
        * 서로 중복 없이 누락된 것 없이.
        * 각 항목이 상호 배타적이면서 모였을 때 완전하게 합쳐지는 것.
* function
    * AVG()
    * COUNT()
    * SUM()
    * RANK() OVER(PARTITION BY column ORDER BY column)
    * DENSE_RANK() OVER(PARTITION BY column ORDER BY column)
    * ROW_NUMBER() OVER(PARTITION BY column ORDER BY column)
