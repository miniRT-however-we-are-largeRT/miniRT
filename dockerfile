############### 실행 방법 #################
# # 호스트에서 X 서버 접근 권한 허용 (최초 1회)
# xhost +local:docker

# # 컨테이너 실행
# docker run -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix minirt

# Ubuntu 22.04 이미지를 베이스로 사용 (glibc 2.34 이상 포함)
FROM ubuntu:22.04

# 비대화형 모드 설정
ENV DEBIAN_FRONTEND=noninteractive

# 빌드 도구 및 X11 관련 라이브러리 설치
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    make \
    libx11-dev \
    libxext-dev \
    xorg-dev \
 && rm -rf /var/lib/apt/lists/*

# 작업 디렉토리 설정
WORKDIR /app

# 프로젝트 파일 전체 복사
COPY . .

# Makefile에 정의된 빌드 명령 실행 (예: 'make all')
RUN make all

# 컨테이너 실행 시 X11 소켓 공유를 통해 miniRT 실행
CMD ["./miniRT", "scenes/scene5.rt"]
