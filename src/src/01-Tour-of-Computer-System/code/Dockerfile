FROM gcc:4.9

COPY *.c /home/src/

COPY *.h /home/src/

WORKDIR /home/src/

RUN gcc -o app main.c

CMD ["./app"]