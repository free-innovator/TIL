# 2023-07-03

## 시각화

### matplot
* `import matplotlib.pyplot as plt`
    * `plt`
        * `plt.show()`
        * `plt.xticks(list(range(0, 11)))`
        * `plt.xlim(0, 10)`
        * `fig, ax = plt.subplots(2, 2, figsize=(9, 9))`
        * `fig, ax = plt.subplots()`
        * `fig = plt.figure(figsize=(10, 5))`
    * `fig`
        * `fig.tight_layout()`
        * `ax = fig.subplots()`
        * `ax = fig.add_subplot(1, 2, 1)`
    * `ax`
        * `ax.plot`
            * `ax.plot([1, 2, 3, 4, 5])`
            * `ax.plot(x, y01, color="red", label="pow2")`
        * `ax.scatter`
            * `ax[0, 0].scatter(x, y01, color="red")`
        * `ax.hist`
            * `ax.hist(x, bins=10)`
        * `ax.boxplot`
            * `ax.boxplot(x)`
        * `ax.pie`
            * `ax.pie(count, labels=labels, autopct="%1.1f%%", startangle=90, counterclock=False)`
        * `ax.bar`
            * `ax01.bar(x, y, color='r')`
            * `ax02.barh(x, y, color='b')`
        * `ax[(0, 0)].set_title("y01")`
        * `ax.set_title("x**2")` 
        * `ax.legend()`

### seaborn
* `import seaborn as sns`
    * `sns.barplot(data=car_crashes, x="abbrev", y="total")`
    * `sns.lineplot(x="abbrev", y="speeding", data=car_crashes, linewidth=3, color="r", label="speeding")`
    * `sns.histplot(data=penguins, x="body_mass_g", hue="species", multiple="fill")`
    * `sns.boxplot(data=penguins, y="body_mass_g", x="species", hue="species")`
    * `sns.swarmplot(data=penguins, x="body_mass_g", y="species", color="black", alpha=0.5)`
    * `sns.scatterplot(data=penguins, x="bill_length_mm", y="bill_depth_mm", hue="species", style="sex", markers=markers)`
    * `sns.violinplot(data=penguins, x="body_mass_g", y="species", hue="sex", split=True)`
    * `sns.regplot(data=penguins, x="bill_length_mm", y="bill_depth_mm")`
    * `sns.ecdfplot(data=penguins, x="body_mass_g")`
    * `sns.pairplot(penguins, kind="reg", corner=True)`
    * `sns.displot(data=penguins, x="bill_length_mm", hue="sex", multiple="stack", col="species")`

### plotly
* `import plotly.express as px`
    * `df = px.data.election()`
    * `fig = px.bar(df, x="district", y=["Coderre", "Bergeron", "Joly"], barmode="group")`
    * `fig.show()`
    * `fig.write_html("montreal.html")`
    * `fig.write_json("montreal.json")`
    * `fig = px.pie(korea, values="count", names="medal")`
    * `fig.show()`

### folium
* `import folium`
    * `my_loc = folium.Map(location=loc, zoom_start=18)`
    * `folium.Marker(loc, popup=folium.Popup("<mark_name>", max_width=100)).add_to(my_loc)`
    * `my_loc.save("visual01.html")`

### wordcloud
* `from wordcloud import WordCloud`
    * `cloud = WordCloud(background_color="white", max_words=30, width=400, height=300, font_path="Goyang.ttf")`
    * `cloud = WordCloud(font_path="Goyang.ttf", max_font_size=40, mask=masking_img, background_color="white").fit_words(res)`
    * `visual = cloud.fit_words(res)`
    * `visual.to_image()`
    * `visual.to_file("cloud01.png")`
