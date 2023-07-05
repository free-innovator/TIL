# 2023-07-05

## numpy
* `np.nan`

## pandas
* `pandas`
    * `pd.set_option("display.max_columns", None)`
    * `pd.set_option("display.max_rows", None)`
    * `pd.DataFrame(random_num, index=["row1", "row2", "row3"], columns=["col1", "col2", "col3"])`
    * `pd.Series(data=[19, 2, 8, 22, 42, 32, 39])`
    * `pd.Series(num_list, index=["1000회", "1001회"])`
    * `pd.to_datetime(df_title["1st-edition"])`
    * `pd.read_csv(<file_path>)`
* `pandas.core.series.Series`
    * `.index`
    * `.values`
    * `.is_unique`
    * `.is_monotonic_increasing`    
    * `nums = pd.Series(random_num, dtype='float')`
    * `nums.head(n=3)`
    * `nums.tail(n=2)`
    * `nums.sum(skipna=False)`
    * `nums.count()`
    * `nums.cumsum()`
    * `nums.mean()`
    * `nums.median()`
    * `nums.std()`
    * `nums.max()`
    * `nums.min()`
    * `nums.describe()`
    * `.unique()`
    * `.sort_values()`
    * `.astype("str")`
    * `.reset_index(drop=True)`
    * `.plot.pie(y=category)`
* `pandas.core.frame.DataFrame`
    * `df_books.index`
    * `df_books.columns`
    * `df_books.shape`
    * `df_books.size`
    * `df_books.dtypes`
    * `df_books.count()`
    * `df_books.value_counts()`
    * `df_books.info()`
    * `df_books["title"]`
    * `df_books.title`
    * `df_books.sort_values(by=["price", "1st-edition"], ascending=[False, True])`
    * `df_books.sort_index(axis=1)`
    * `df_title.sum(numeric_only=True)`
    * `df_title.select_dtypes(exclude="object")`
    * `df_title[["writer", "price"]]`
    * `df_title.loc[["드래곤라자", "퇴마록"]]`
    * `df_title.iloc[2:4]`
    * `.groupby(<column name>)`
    * `.str.split(" ").str.get(0)`
    * `.apply(lambda x: weekday_list[x["요일"]], axis=1)`
    * `.reindex(weekday_list)`
    * `.dt`
        * `.dt.year`
        * `.dt.month`
        * `.dt.day`
        * `.dt.weekday`
        * `.dt.day_name()`
