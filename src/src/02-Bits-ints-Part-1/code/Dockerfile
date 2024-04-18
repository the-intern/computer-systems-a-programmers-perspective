FROM gcc:13.2

COPY src/*.c /home/csapp/src/

COPY src/*.h /home/csapp/src/

COPY playground/*.c /home/csapp/playground/

COPY playground/*.h /home/csapp/playground/

COPY playground/*.sh /home/csapp/playground/

COPY src/*.sh /home/csapp/src/

WORKDIR /home/csapp/src/

# RUN echo "deb https://deb.debian.org/debian/ stable main" > /etc/apt/sources.list

RUN apt-get update && apt-get upgrade -y

RUN apt-get install vim -y && apt-get install gdb -y && apt-get install tree -y && apt-get install less -y

RUN echo 'alias lc="clear;ls -la"' >> ~/.bashrc

RUN echo 'alias ..="cd ..;clear;ls -la"' >> ~/.bashrc

# RUN gcc -o app main.c

# CMD ["./app"]