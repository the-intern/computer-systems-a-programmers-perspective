FROM gcc:4.9

COPY src/*.c /home/src/app/

COPY src/*.h /home/src/app/

WORKDIR /home/src/app/

RUN echo 'alias lc="clear;ls -la"' >> ~/.bashrc

# RUN gcc -o app main.c

# CMD ["./app"]