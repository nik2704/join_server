# join_server

## Описание
`join_server` — это асинхронный TCP-сервер на C++ с использованием Boost.Asio.
Он выполняет операции пересечения (`INTERSECTION`) и симметрической разницы (`SYMMETRIC_DIFFERENCE`).

## Компиляция и запуск

### 1. Установка зависимостей
Перед компиляцией убедитесь, что у вас установлен Boost (версии 1.67 или выше).

**Для Ubuntu:**
```sh
sudo apt update
sudo apt install libboost-all-dev
```


### 2. Компиляция
```sh
mkdir build && cd build
cmake ..
make
```

### 3. Запуск сервера
```sh
./join_server <port>
```
Где `<port>` — номер TCP-порта, который будет слушать сервер.

## Использование

### Подключение к серверу
Используйте `telnet` или `netcat`, чтобы отправлять команды серверу:
```sh
telnet localhost 9000
```
или
```sh
echo -e "INSERT A 0 lean\n" | nc localhost 9000
```

### Доступные команды

#### Вставка элементов в таблицы
```sh
INSERT A <id> <name>
INSERT B <id> <name>
```
Пример:
```sh
INSERT A 0 lean
INSERT B 3 proposal
```
Ответ:
```
OK
```
или в случае ошибки:
```
ERR duplicate 0
```

#### Очистка таблиц
```sh
TRUNCATE A
TRUNCATE B
```

#### Получение пересечения таблиц
```sh
INTERSECTION
```
Ответ:
```
3,violation,proposal
4,quality,example
5,precision,lake
OK
```

#### Получение симметрической разницы
```sh
SYMMETRIC_DIFFERENCE
```
Ответ:
```
0,lean,
1,sweater,
2,frank,
6,,flour
7,,wonder
8,,selection
OK
```
