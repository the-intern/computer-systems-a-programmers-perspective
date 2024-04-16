FROM gcc:13.2

COPY src/*.c /home/csapp/src/

COPY src/*.h /home/csapp/src/

COPY src/*.sh /home/csapp/src/

WORKDIR /home/csapp/src/

# RUN echo "deb https://deb.debian.org/debian/ stable main" > /etc/apt/sources.list

# RUN apt-get update && apt-get upgrade -y &&  apt-get vim

RUN echo 'alias lc="clear;ls -la"' >> ~/.bashrc

RUN echo 'alias whoa="clear;ls"' >> ~/.bashrc

# RUN gcc -o app main.c

# CMD ["./app"]