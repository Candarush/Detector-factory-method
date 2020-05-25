FROM gcc:latest

# Копирование директории
COPY . /usr/src/detector
WORKDIR /usr/src/detector

# Сборка
RUN make

#Запуск
CMD ["./exec"]