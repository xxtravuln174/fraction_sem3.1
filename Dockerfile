FROM gcc:12.2.0

# Устанавливаем cmake и doxygen
RUN apt-get update && apt-get install -y cmake doxygen \
    && rm -rf /var/lib/apt/lists/*

# Копируем проект
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp

# Конфигурация и сборка
RUN cmake -S . -B build \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=/usr/src/myapp/build/bin \
 && cmake --build build -- -j$(nproc)

# Запуск тестов по умолчанию
CMD ["/usr/src/myapp/build/bin/tests"]

# Запуск контейнера docker run --rm fraction-app
# Запуск самого приложения docker run --rm fraction-app /usr/src/myapp/build/bin/fraction_app
