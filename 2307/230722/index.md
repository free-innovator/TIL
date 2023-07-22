# 2023-07-22

## tensorflow GPU
이하 내용 중 제외해도 되는 부분이 있을 수 있습니다..

Cuda를 세 번이나 설치했는데, 하나는 Windows용, 하나는 ipykernel, 하나는 Debian 용이다. 시간이 오래 걸려 하나씩 제외해보지 못했고, 따로 Docker 이미지로 나와있을 수도 있으니 있으면 도커를 쓰는 방법이 빠를수도 있을 것 같습니다.

tensorflow에서 알려주는 GPU 관련 문서를 확인하고 설치하면 유용합니다.

* Windows 11 - WSL2 Debian
    1. WSL2 + Debian을 설치한다. (여러 설정이 필요할 수 있다.)
    1. sudo apt(apt-get)을 이용해 wget을 설치한다.
    1. wget으로 이하를 설치한다.
        * conda
        * cuda
    1. conda 가상환경을 만들고 이하를 conda install -c conda-forge로 설치한다.
        * python (버전은 tensorflow에 맞춰서)
        * cuda (최신버전 or tensorRT를 사용하려면 그에 맞춰서)
    1. 해당 가상환경에서 python3 -m pip로 이하를 설치한다. 
        * cudnn (cuda 버전에 맞게)
        * tensorflow (최신버전)
    1. cuda, cudnn를 위한 환경변수 설정을 한다.
    1. 드라이버 등을 최신 상태로 업데이트한다.
    1. git, code가 동작하게 설정한다.
        * code에서 .ipynb를 사용하려 하면 자동으로 확장프로그램과 패키지를 설치해준다.
        * github에 push를 하기 위해서 ssh를 설정해야하는데, openssl 버전 이슈가 나는 경우, conda remove --force openssl로 제거하면 본래 환경의 openssl으로 실행되어서 오류가 없어질 수 있다.
    1. 기타 필요한 패키지는 해당 환경에서 python3 -m pip로 설치한다.
