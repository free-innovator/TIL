# 2023-06-28

## crawling
* `import requests`
    * `requests.get(url)`
* `import json`
    * `json.dumps(result_dict, ensure_ascii=False)`
* `import urllib.request`
    * `urllib.request.urlopen(url)`
* `from bs4 import BeautifulSoup`
    * `BeautifulSoup(resp, "html.parser")`
    * `soup.find("div", class_="component_section")`
    * `item.find("span", class_="title").string`
    * `item.select(".title")[0].text`
    * `item.select("a>span>span.text")[0].text`
* `from selenium import webdriver`
    * `webdriver.chrome.service.Service(executable_path="...")`
    * `driver = webdriver.Chrome(service=service)`
    * `driver.get(url)`
    * `driver.execute_script("scrollBy(0, 1000);")`
    * `driver.close()`
    * `driver.quit()`
