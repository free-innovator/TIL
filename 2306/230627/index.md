# 2023-06-27

## 확률과 통계
* 분포가 identify가 된다.
    * 완벽하게 정의할 수 있다.

<br/>

## SQL
* SUBSTR(str, i, count)
    * str의 i번째부터 count개 가져온다. (index는 1부터 시작)

<br/>

## django
* 뷰
    * `.LoginView.as_view(template_name="login.html")`
    * `.LogoutView.as_view()`
* 폼
    * `from django import forms`
    * {{ form.as_table }}
* 현지화
    * `LANGUAGE_CODE = "ko-kr"`
    * `TIME_ZONE = "Asia/Seoul"`
* 회원가입
    * username, password1, password2
    * check_password, make_password
    * `from django.contrib.auth.forms import UserCreationForm`
    * `from django.contrib.auth.models import User`
    * `LOGIN_REDIRECT_URL = "/result/"`
    * `LOGOUT_REDIRECT_URL = "/"`
    * `.LoginView.as_view(template_name="login.html")`
    * `.LogoutView.as_view()`
* 파일 업로드
    * enctype="multipart/form-data"
    * input type="file"
    * `MEDIA_URL = "/media/"`
    * `MEDIA_ROOT = BASE_DIR/"media"`
    * `request.FILES["upload_file"]`
    * `from django.core.files.base import ContentFile`
    * `from django.core.files.storage import default_storage`
    * `default_storage.save(upload_file.name, ContentFile(upload_file.read()))`
    * `HttpResponse(default_storage.open(filename).read(), content_type="application/force-download")`
